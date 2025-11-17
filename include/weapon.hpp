#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <vector>

class weapon {
    private:

  std::string name;

  // Scaling
  std::vector<float> scales; 

  // Scaling increase
  std::vector<float> scaleIncrease; 

  // Attack multipliers
  std::vector<float> regMults;
  std::vector<float> transformedMults;

  // Base damage stats & amount added per weapon level
  std::vector<int> base; 
  std::vector<int> inc; 

  // Amounted added at level 10 weapon
  std::vector<int> finals; 

    public:
  weapon(
  std::string i_name,

  // Scaling
  std::vector<float> i_scales,

  // Scaling increase
  std::vector<float> i_scaleIncrease,

  // Attack multipliers
  std::vector<float> i_regMults,
  std::vector<float> i_transformedMults,

  // Base damage stats & amount added per weapon level
  std::vector<int> i_base,
  std::vector<int> i_inc,

  // Amounted added at level 10 weapon
  std::vector<int> i_finals
  );

  std::string returnName();
  int returnScales(int index);
  int returnScaleIncrease(int index);
  int returnRegMult(int index);
  int returnTransformedMult(int index);
  int returnBase(int index);
  int returnInc(int index);
  int returnFinals(int index);
};

extern std::vector<weapon> weapons;

#endif
