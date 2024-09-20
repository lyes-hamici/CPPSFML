#ifndef GAME_HEADER
#define GAME_HEADER
#include <string>
#include <map>
#include <functional>
#include "Level.hpp"
#include "Cannon.hpp"
class Game{
public:
    static std::string levelsPath;
    static std::map<std::string,Level> levels;
    Cannon cannon;
    void Start();
    void Update();
};

#endif