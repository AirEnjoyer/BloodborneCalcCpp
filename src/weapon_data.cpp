#include "weapon.hpp"
#include <vector>

weapon::weapon(
  std::string i_name;

  // Scaling
  std::vector<float> i_scales; 

  // Scaling increase
  std::vector<float> i_scaleIncrease; 

  // Attack multipliers
  std::vector<float> i_regMults;
  std::vector<float> i_transformedMults;

  // Base damage stats & amount added per weapon level
  std::vector<int> i_base; 
  std::vector<int> i_inc; 

  // Amounted added at level 10 weapon
  std::vector<int> i_finals; 
  ) {
    name = i_name;
    scales = i_scales;
    scaleIncrease = i_scaleIncrease;
    regMults = i_regMults;
    transformedMults = i_transformedMults;
    base = i_base;
    inc = i_inc;
    finals = i_finals;
};

weapon::returnName(){
    return name;
}

weapon::returnScale(int index){
    return scales[index];
}

weapon::returnScaleIncrease(int index){
    return scalesIncrease[index];
}

weapon::returnRegMult(int index){
    return regMults[index];
}

weapon::returnTransformedMult(int index){
    return transformedMults[index];
}

weapon::returnBase(int index){
    return base[index];
}

weapon::returnInc(int index){
    return inc[index];
}

weapon::returnFinals(int index){
    return finals[index];
}



std::vector<weapon> weapons = {
   weapon( 
        "Hunter Axe", {0.45f, 0.15f, 0.0f, 0.33f}, {0.02f, 0.02f, 0.0f,  0.02f},
        {1.0f,         1.35f, 2.0f,  1.1f}, {1.05f, 1.37f, 2.8f,  1.25f, 1.2f},
        {98,           0,     0},     {8,    0,     0},     {17,    0,     0}
        ),
    weapon("Saw Cleaver", {0.4f, 0.2f, 0.0f, 0.33f}, {0.02f, 0.02f, 0.0f, 0.02f},
        {1.0f, 1.2f, 1.9f, 1.3f}, {0.97f, 1.25f, 1.7f, 0.0f, 1.3f}, 
        {90, 0, 0}, {9, 0, 0}, {9, 0, 0}),
    weapon("Saw Spear", {0.3f, 0.44f, 0.0f, 0.4f},  {0.02f, 0.02f, 0.0f, 0.02f},
        {1.0f,        1.2f, 1.9f,  1.3f}, {1.08f, 1.33f, 1.73f, 0.0f, 1.23f},
        {85,          0,    0},     {8,    0,     0},     {13,    0,    0}),
    weapon("Threaded Cane", {0.19f, 0.6f, 0.0f, 0.43f}, {0.01f, 0.03f, 0.0f, 0.02f},
            {1.0f, 1.35f, 1.9f, 1.2f}, {0.95f, 1.25f, 0.0f, 0.0f, 1.2f},
            {78, 0, 0}, {7, 0, 0}, {15, 0, 0}),
    weapon("Kirkhammer", {0.6f, 0.19f, 0.0f,  0.43f}, {0.04f, 0.01f, 0.0f,  0.03f},
            {0.71f,        1.0f, 1.2f,  1.05f}, {1.0f,  1.25f, 2.3f,  1.15f, 1.05f},
            {105,          0,    0},     {10,    0,     0},     {15,    0,     0}),
    weapon("Rifle Spear",{ 0.2f, 0.5f, 0.35f, 0.38f}, {0.01f, 0.02f, 0.03f, 0.02f},
            {0.95f, 1.35f, 1.95f, .08f}, {0.95f, 1.45f, 2.45f, 0.08f, 1.30f},
            {85, 0, 85}, {8, 0, 8}, {13, 0, 13}),
    weapon("Stake Driver", 0.4f, 0.35f, 0.0f, 0.41f, 0.02f, 0.02f, 0.00f, 0.02f,
     1.0f, 1.35f, 1.9f, 1.1f, 0.97f, 1.37f, 3.55f, 0.0f, 1.0f,
     85, 0, 0, 8, 0, 0, 13, 0, 0),
    weapon("Ludwig's Holy Blade", {0.5f, 0.4f, 0.0f, 0.49f}, {0.03f, 0.04f, 0.0f, 0.04f},
            {0.7f, 1.0f, 1.2f, 1.05f}, {1.0f, 1.25f, 2.2f, 1.15f, 1.26f},
            {100, 0, 0}, {10, 0, 0}, {10, 0, 0}),
    weapon("Blade of Mercy", {0.0f, 0.6f, 0.0f, 0.4f}, {0.0f, 0.05f, 0.0f, 0.03f},
            {1.0f, 1.25f, 2.0f, 1.2f}, {0.9f, 1.5f, 0.0f, 1.5f, 1.3f},
            {60, 30, 0}, {6, 3, 0}, {6, 3, 0}),
    weapon("Tonitrus", {0.45f, 0.15f, 0.0f, 0.33f}, {0.02f, 0.01f, 0.0f, 0.01f},
            {1.0f,       1.2f,  1.9f,  1.2f}, {0.0f,  0.0f,  0.0f,  0.0f, 0.0f},
            {80,         40,    0},     {8,    4,     0},     {8,     4,    0}),
    weapon("Chikage", {0.15f, 0.45f, 0.6f,  0.33f}, {0.1f, 0.2f,  0.5f,  0.015f},
            {1.0f,      1.27f, 1.85f, 1.42f}, {0.95f, 1.5f, 2.25f, 1.27f, 0.95f},
            {92,        0,     92},    {9,     0,     9},    {11,    0,     11}),
    weapon("Reiterpallasch", {0.1f, 0.6f, 0.2f, 0.38f}, {0.01f, 0.04f, 0.02f, 0.03f},
            {1.0f, 1.25f, 1.9f, 1.0f}, {0.75f, 1.0f, 0.0f, 0.0f, 1.1f},
            {75, 0, 75}, {7, 0, 7}, {12, 0, 12}),
    weapon("Logarius' Wheel", {0.6f, 0.0f, 0.0f, 0.33f}, {0.05f, 0.0f, 0.0f, 0.025f},
            {1.0f, 1.15f, 1.6f, 1.23f}, {1.02f, 1.47f, 0.0f, 0.0f, 0.4f},
            {100, 25, 0}, {10, 2, 0}, {10, 7, 0}),
    weapon("Burial Blade", {0.2f, 0.55f, 0.0f, 0.4f}, {0.01f, 0.02f, 0.0f, 0.03f},
            {1.0f, 1.22f, 1.7f, 1.6f}, {1.1f, 1.45f, 1.9f, 1.4f, 1.1f},
            {80, 30, 0}, {8, 3, 0}, {8, 3, 0}),
    weapon("Beast Claw", {0.4f,  0.25f, 0.0f, 0.35f}, {0.02f, 0.01f, 0.0f, 0.02f},
            {1.0f,         1.25f, 1.8f,  0.0f}, {0.9f,  1.35f, 1.9f,  1.2f, 1.25f},
            {75,           0,     0},     {7,    0,     0},     {12,    0,    0}),
    weapon("Beast Claw (Beast's Embrace)", {0.4f, 0.25f, 0.0f, 0.35f}, {0.02f, 0.01f, 0.0f, 0.02f},
            {1.0f, 1.2f, 1.4f, 1.8f}, {1.0f, 1.2f, 0.0f, 0.3f, 1.25f},
            {75, 0, 0}, {7, 0, 0}, {12, 0, 0}),
    weapon("Amygdalan Arm", {0.6f, 0.15f, 0.0f, 0.41f}, {0.03f, 0.01f, 0.0f, 0.02f},
            {1.0f, 1.3f, 1.8f, 1.15f}, {0.95f, 1.2f, 1.7f, 0.0f, 1.5f},
            {80, 40, 0}, {8, 4, 0}, {8, 4, 0}),
    weapon("Beasthunter Saif", {0.2f, 0.4f, 0.0f, 0.33f}, {0.01f, 0.03f, 0.0f, 0.02f},
            {1.10f, 1.45f, 1.8f, 1.15f}, {0.95f, 1.3f, 1.6f, 0.0f, 1.1f},
            {90, 0, 0}, {9, 0, 0}, {9, 0, 0}),
    weapon("Beast Cutter", {0.4f, 0.1f, 0.0f, 0.27f}, {0.02f, 0.02f, 0.0f, 0.02f},
            {1.0f, 1.2f, 1.9f, 1.4f}, {0.95f, 1.3f, 0.0f, 0.0f, 1.5f},
            {92, 0, 0}, {9, 0, 0}, {11, 0, 0}),
    weapon("Bloodletter", {0.6f, 0.0f, 0.7f, 0.33f}, {0.04f, 0.0f, 0.04f, 0.02f},
            {1.0f, 1.5f, 1.9f, 1.3f}, {1.05f, 1.5f, 2.0f, 2.0f, 1.2f},
            {90, 0, 90}, {9, 0, 9}, {9, 0, 9}),
    weapon("Boom Hammer", {0.6f, 0.15f, 0.0f, 0.41f}, {0.03f, 0.01f, 0.0f, 0.02f},
            {1.0f, 1.35f, 1.9f, 0.8f}, {1.0f, 1.3f, 1.8f, 0.0f, 0.8f},
            {90, 60, 0}, {9, 6, 0}, {9, 6, 0}),
    weapon("Church Pick", {0.2f, 0.5f, 0.0f, 0.38f}, {0.02f, 0.02f, 0.0f, 0.02f},
            {0.95f, 1.3f, 1.7f, 1.2f}, {1.05f, 1.4f, 1.9f, 0.5f, 1.35f},
            {88, 0, 0}, {8, 0, 0}, {16, 0, 0}),
    weapon("Holy Moonlight Sword", {0.5f, 0.4f, 0.0f, 0.6f}, {0.03f, 0.02f, 0.0f, 0.04f},
            {1.0f, 1.3f, 1.8f, 1.2f}, {1.0f, 1.2f, 1.4f, 1.5f, 1.3f},
            {90, 50, 0}, {9, 5, 0}, {9, 5, 0}),
    weapon("Kos Parasite (Milkweed Rune)", {0.0f, 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 0.06f},
            {2.0f, 2.35f, 3.7f, 2.2f}, {2.1f, 2.5f, 0.0f, 0.9f, 2.0f},
            {0, 30, 0}, {0, 3, 0}, {0, 3, 0}),
    weapon("Kos Parasite (Fists/Kos Parasite)", {0.0f, 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 0.06f},
            {1.0f, 1.25f, 1.45f, 1.2f}, {1.2f, 1.42f, 2.0f, 1.4f, 1.0f},
            {0, 30, 0}, {0, 3, 0}, {0, 3, 0}),
    weapon("Rakuyo", {0.0f,  0.6f, 0.0f, 0.33f}, {0.0f, 0.04f, 0.0f,  0.02f},
            {1.0f,     1.35f, 1.7f, 1.3f}, {1.0f,  0.9f, 0.0f,  1.95f, 1.5f},
            {82,       0,     0},    {8,    0,     0},    {10,    0,     0}),
    weapon("Simon's Bowblade", {0.6f, 0.6f, 0.6f, 0.33f}, {0.0f, 0.05f, 0.05f, 0.02f},
            {1.0f, 1.3f, 2.5f, 0.85f}, {0.85f, 1.05f, 1.4f, 0.7f, 1.35f},
            {80, 0, 80}, {8, 0, 8}, {8, 0, 8}),
    weapon("Whirligig Saw", {0.7f, 0.2f, 0.0f, 0.49f}, {0.04f, 0.01f, 0.0f, 0.3f},
            {0.75f, 1.05f, 1.3f, 1.15f}, {1.0f, 1.3f, 0.0f, 0.8f, 1.05f},
            {95, 0, 0}, {9, 0, 0}, {14, 0, 0}});
