#include "weapon.hpp"
#include <cmath>
#include <iostream>
#include <string>

namespace scales
{
    enum indexes
    {
        strength,
        skill,
        bloodtinge,
        arcane
    };
}

namespace bases 
{
    enum indexes 
    {
        physical,
        arcane,
        blood
    };
}

namespace finals
{
    enum indexes
    {
        physical,
        arcane,
        blood
    };
}

namespace regMults
{
    enum indexes
    {
        r1,
        tapR2,
        chargeR2,
        regTransformAttack
    };
}

namespace transformedMults
{
    enum indexes
    {
        r1,
        tapR2,
        chargeR2,
        l2,
        transformedTransformAttack
    };
}

float getSat(int inputStat) {
  float sat;
  if (inputStat >= 5 && inputStat <= 10) {
    sat = (inputStat * 0.005) + .025;
  } else if (inputStat >= 11 && inputStat <= 25) {
    sat = ((inputStat - 10) * 0.03) + 0.050;
  } else if (inputStat >= 26 && inputStat <= 50) {
    sat = ((inputStat - 25) * 0.014) + .5;
  } else if (inputStat >= 51 && inputStat <= 58) {
    sat = ((inputStat - 50) * 0.003) + .85;
  } else if (inputStat == 58) {
    sat = 0.878;
  } else if (inputStat >= 59 && inputStat <= 99) {
    sat = ((inputStat - 58) * 0.003) + 0.878;
  }
  return sat;
}

void getVisceralDamage(int skill, int bloodLevel, float *initThrustDamage,
                       float *parryViscDamage, float *breakViscDamage) {
  float visceralSat = 0;

  if (skill >= 5 && skill <= 10) {
    visceralSat = (skill * 0.01) + .05;
  } else if (skill >= 11 && skill <= 50) {
    visceralSat = ((skill - 10) * 0.0175) + 0.1;
  } else if (skill >= 51 && skill <= 53) {
    visceralSat = ((skill - 50) * 0.004) + .8;
  } else if (skill == 54) {
    visceralSat = 0.8163;
  } else if (skill >= 55 && skill <= 62) {
    visceralSat = ((skill - 54) * 0.0041) + 0.8163;
  } else if (skill == 63) {
    visceralSat = 0.853;
  } else if (skill >= 64 && skill <= 69) {
    visceralSat = ((skill - 63) * 0.0041) + 0.853;
  } else if (skill == 70) {
    visceralSat = .8816;
  } else if (skill >= 71 && skill <= 74) {
    visceralSat = ((skill - 70) * 0.0041) + 0.8816;
  } else if (skill == 75) {
    visceralSat = 0.902;
  } else if (skill >= 76 && skill <= 79) {
    visceralSat = ((skill - 75) * 0.0041) + 0.9061;
  } else if (skill == 80) {
    visceralSat = .9224;
  } else if (skill >= 81 && skill <= 84) {
    visceralSat = ((skill - 80) * 0.0041) + 0.9924;
  } else if (skill == 85) {
    visceralSat = 0.9428;
  } else if (skill >= 86 && skill <= 89) {
    visceralSat = ((skill - 85) * 0.0041) + 0.9428;
  } else if (skill == 90) {
    visceralSat = 0.9633;
  } else if (skill == 91) {
    visceralSat = 0.9673;
  } else if (skill >= 92 && skill <= 99) {
    visceralSat = ((skill - 91) * 0.0041) + 0.9673;
  }

  float initThrust, parryVisc, breakVisc;

  if (bloodLevel >= 4 && bloodLevel <= 14) {
    initThrust = 0.5f;
    parryVisc = 2.5f;
    breakVisc = 3;
  } else if (bloodLevel >= 15 && bloodLevel <= 29) {
    initThrust = 0.55;
    parryVisc = 3.25;
    breakVisc = 3.75;
  } else if (bloodLevel >= 30 && bloodLevel <= 44) {
    initThrust = 0.6;
    parryVisc = 3.9;
    breakVisc = 4.4;
  } else if (bloodLevel >= 45 && bloodLevel <= 59) {
    initThrust = 0.65;
    parryVisc = 5.7;
    breakVisc = 6.2;
  } else if (bloodLevel >= 60 && bloodLevel <= 79) {
    initThrust = 0.7;
    parryVisc = 6.4;
    breakVisc = 6.9;
  } else if (bloodLevel >= 80 && bloodLevel <= 99) {
    initThrust = 0.75;
    parryVisc = 7.2;
    breakVisc = 7.7;
  } else if (bloodLevel >= 100 && bloodLevel <= 119) {
    initThrust = 0.8;
    parryVisc = 7.4;
    breakVisc = 7.9;
  } else if (bloodLevel >= 120 && bloodLevel <= 139) {
    initThrust = 0.85;
    parryVisc = 7.6;
    breakVisc = 8.1;
  } else if (bloodLevel >= 140 && bloodLevel <= 159) {
    initThrust = 0.9;
    parryVisc = 7.7;
    breakVisc = 8.2;
  } else if (bloodLevel >= 160 && bloodLevel <= 199) {
    initThrust = 0.95;
    parryVisc = 7.8;
    breakVisc = 8.3;
  } else if (bloodLevel > 199) {
    initThrust = 1;
    parryVisc = 7.9;
    breakVisc = 8.4;
  }
  *initThrustDamage = (130 + (130 * 1.3 * visceralSat)) * initThrust;
  *parryViscDamage = (130 + (130 * 1.3 * visceralSat)) * parryVisc;
  *breakViscDamage = (130 + (130 * 1.3 * visceralSat)) * breakVisc;
}

void calcDamage(weapon *w, int weaponLevel, int userStr, int userSkill,
                int userBloodtinge, int userArc, int bloodLevel) {
  int effectiveLevel = 0;

  if (weaponLevel <= 0) {
    effectiveLevel = 1;
  } else if (weaponLevel >= 10) {
    effectiveLevel = 9;
  } else {
    effectiveLevel = weaponLevel;
  }

  float strSat = getSat(userStr);
  float skillSat = getSat(userSkill);
  float bloodtingeSat = getSat(userBloodtinge);
  float arcSat = getSat(userArc);

  float weaponStrScale = w->returnScales(scales::strength)+ (w->returnScaleIncrease(scales::strength) * effectiveLevel);
  float weaponSkillScale =
      w->returnScales(scales::skill) + (w->returnScaleIncrease(scales::skill) * effectiveLevel);
  float weaponBloodtingeScale =
      w->returnScales(scales::bloodtinge) + (w->returnScaleIncrease(scales::bloodtinge) * effectiveLevel);
  float weaponArcScale =
      w->returnScales(scales::bloodtinge)+ (w->returnScaleIncrease(scales::arcane) * effectiveLevel);

  float basePhys = w->returnBase(bases::physical)+ (w->returnInc(bases::physical) * (effectiveLevel - 1));
  float baseArc = w->returnBase(bases::arcane)+ (w->returnInc(bases::arcane) * (effectiveLevel - 1));
  float baseBlood = w->returnBase(bases::blood)+ (w->returnInc(bases::blood) * (effectiveLevel - 1));

  if (weaponLevel == 10) {
    if (basePhys > 0)
      basePhys += w->returnFinals(finals::physical);
    if (baseBlood > 0) {
      baseBlood += w->returnFinals(finals::blood);
      if (baseArc > 0) {
        baseArc += w->returnFinals(finals::arcane);
      }
    }
  }

  float physDamage = (basePhys + (weaponStrScale * strSat +
                                  basePhys * weaponSkillScale * skillSat));

  float bloodDamage = (baseBlood + (weaponBloodtingeScale * bloodtingeSat));

  float arcDamage = (baseArc + (weaponArcScale * arcSat));

  if (w->returnName() == "Holy Moonlight Sword") {
    float holyGSwordR1Arc = 0.50;
    float holyGSwordR2Arc = 0.65f;
    float holyGSwordChargedR2Arc = 0.9f;
    float holyGSwordTransformArc = 1.0f;
    float transformedHolyGSwordR1Arc = 0.7f;
    float transformedHolyGSwordR2Arc = 2.0f;
    float transformedHolyGSwordChargedR2Arc = 2.8f;
    float holyGSwordL2 = 1.5f;
    float transformedHolyGSwordTransformArc = 1.3f;

    std::cout << "R1: " << physDamage * w->returnRegMult(regMults::r1) + arcDamage * holyGSwordR1Arc
              << std::endl
              << "R2: " << physDamage * w->returnRegMult(regMults::tapR2) + arcDamage * holyGSwordR2Arc
              << std::endl
              << "Charged R2 "
              << physDamage * w->returnRegMult(regMults::chargeR2) + arcDamage * holyGSwordChargedR2Arc
              << std::endl
              << "Transform Attack: "
              << physDamage * w->returnRegMult(regMults::regTransformAttack) +
                     arcDamage * holyGSwordTransformArc
              << std::endl
              << "Transformed R1:"
              << physDamage * w->returnTransformedMult(transformedMults::r1)+
                     arcDamage * transformedHolyGSwordR1Arc
              << std::endl
              << "Transformed R2: "
              << physDamage * w->returnTransformedMult(transformedMults::tapR2)+
                     arcDamage * transformedHolyGSwordR2Arc
              << "Transformed Charged R2: "
              << physDamage * w->returnTransformedMult(transformedMults::chargeR2) +
                     arcDamage * transformedHolyGSwordR1Arc
              << std::endl
              << "L2: " << physDamage * w->returnTransformedMult(transformedMults::l2) + arcDamage * holyGSwordL2
              << std::endl
              << "Transformed transform attack: "
              << physDamage * w->returnTransformedMult(transformedMults::transformedTransformAttack)+
                     arcDamage * transformedHolyGSwordTransformArc
              << std::endl;
  } else {
    std::cout << "R1: "
              << (w->returnRegMult(regMults::r1) * physDamage) + (w->returnRegMult(regMults::r1)* arcDamage) +
                     (w->returnRegMult(regMults::r1) * bloodDamage)
              << std::endl;
    std::cout << "R2: "
              << (w->returnRegMult(regMults::tapR2) * physDamage) + (w->returnRegMult(regMults::tapR2) * arcDamage) +
                     (w->returnRegMult(regMults::tapR2) * bloodDamage)
              << std::endl;
    std::cout << "Charged R2: "
              << (w->returnRegMult(regMults::chargeR2) * physDamage) + (w->returnRegMult(regMults::chargeR2) * arcDamage) +
                     (w->returnRegMult(regMults::chargeR2) * bloodDamage)
              << std::endl;
    std::cout << "Transform Attack: "
              << (w->returnRegMult(regMults::regTransformAttack) * physDamage) +
                     (w->returnRegMult(regMults::regTransformAttack) * arcDamage) +
                     (w->returnRegMult(regMults::regTransformAttack) * bloodDamage)
              << std::endl;
    std::cout << "Transformed R1: "
              << (w->returnTransformedMult(transformedMults::r1) * physDamage) +
                     (w->returnTransformedMult(transformedMults::r1) * arcDamage) +
                     (w->returnTransformedMult(transformedMults::r1) * bloodDamage)
              << std::endl;
    std::cout << "Transformed Tap R2: "
              << (w->returnTransformedMult(transformedMults::tapR2) * physDamage) +
                     (w->returnTransformedMult(transformedMults::tapR2) * arcDamage) +
                     (w->returnTransformedMult(transformedMults::tapR2) * bloodDamage)
              << std::endl;
    std::cout << "Transformed Charged R2: "
              << (w->returnName() == "Whirligig Saw"
                      ? ((w->returnTransformedMult(transformedMults::chargeR2) * 1.8) +
                         pow((w->returnTransformedMult(transformedMults::chargeR2) * 0.3), 3)) *
                            physDamage
                      : (w->returnTransformedMult(transformedMults::chargeR2) * physDamage) +
                            (w->returnTransformedMult(transformedMults::chargeR2) * arcDamage) +
                            (w->returnTransformedMult(transformedMults::chargeR2) * bloodDamage))
              << std::endl;
    std::cout << "L2: "
              << (w->returnTransformedMult(transformedMults::l2) * physDamage) + (w->returnTransformedMult(transformedMults::l2) * arcDamage) +
                     (w->returnTransformedMult(transformedMults::l2) * bloodDamage)
              << std::endl;
    std::cout << "Transformed Transform Attack: "
              << (w->returnTransformedMult(transformedMults::transformedTransformAttack) * physDamage) +
                     (w->returnTransformedMult(transformedMults::transformedTransformAttack) * arcDamage) +
                     (w->returnTransformedMult(transformedMults::transformedTransformAttack) * bloodDamage)
              << std::endl
              << std::flush;
    std::string dummyInput;
    std::getline(std::cin, dummyInput);
  }
}
