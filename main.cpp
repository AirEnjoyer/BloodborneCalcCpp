#include "weapon.h"
#include <cstdio>
#include <iostream>
#include <ostream>

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
    std::cout << i + 1 << "." << weapons[i].name << std::endl;
  };

  std::cin >> userChoice;

  userChoice--;

  std::cout << "Enter the weapon level: " << std::endl << std::flush;
  std::cin >> weaponLevel;

  std::cout << "Enter your strength: " << std::endl;
  std::cin >> userStr;

  std::cout << "Enter your skill: " << std::endl;
  std::cin >> userSkill;

  std::cout << "Enter your Bloodtinge: " << std::endl;
  std::cin >> userBloodtinge;

  std::cout << "Enter your Arcane: " << std::endl;
  std::cin >> userArc;

  std::cout << "Enter your blood level: " << std::endl;
  std::cin >> bloodLevel;

  calcDamage(&weapons[userChoice], weaponLevel, userStr, userSkill,
             userBloodtinge, userArc, bloodLevel);

  std::cout << "Press enter to exit" << std::endl << std::flush;

  std::cin.get();

  return 0;
}
