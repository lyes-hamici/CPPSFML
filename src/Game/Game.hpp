#ifndef GAME_H
#define GAME_H
#include <string>
#include <unordered_set>
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