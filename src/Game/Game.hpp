#ifndef GAME_H
#define GAME_H
#include <string>
#include <unordered_set>
#include <map>
#include <functional>
#include "Level.hpp"
class Game{
private:
    std::string levelsPath;
public:
    static std::map<std::string,Level> levels;
    void Start();
    void Update();
};

#endif