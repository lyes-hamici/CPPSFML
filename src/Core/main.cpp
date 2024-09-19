#include <iostream>
#include "../Game/Levels.hpp"
#include <windows.h>

int main() {

    Levels level = Levels::LoadFromFile("../Build/Levels/level1.txt");


    level.PrintLayout(); 

  
    level.Setup();

  
    for (const Brick& brick : level.bricks) {
        std::cout << "Brick with " << brick.hp << " HP at position ("
                  << brick.x << ", " << brick.y << ")\n";
    }
    system("pause");
    return 0;
}
