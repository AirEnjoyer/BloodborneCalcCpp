#include "weapon.h"
#include <iostream>

void calcDamage(const Weapon *w, int weaponLevel, int userStr, int userSkill,
                int userBloodtinge, int userArc, int bloodLevel);

int main() {

  int userChoice, weaponLevel;

  double strScale, strSat, skillScale, skillSat, bloodtingeScale, bloodtingeSat,
      arcScale, arcSat;

  double weaponStrScale, weaponSkillScale, weaponBloodtingeScale,
      weaponArcaneScale;

  int userStr, userSkill, userBloodtinge, userArc, bloodLevel;

  std::cout << "Choose a weapon by number" << std::endl;

  for (int i = 0; i < 25; i++) {
    std::cout << i + 1 << "." << weapons[i].name;
  };

  return 0;
}
