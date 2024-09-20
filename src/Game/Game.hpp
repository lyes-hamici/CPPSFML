#ifndef GAME_HEADER
#define GAME_HEADER
#include <string>
#include <map>
#include <functional>
#include "Level.hpp"



class Game{
public:
    int current_level;
    static std::string levelsPath;
    static std::vector<Level> levels;
    void Start();
    void Update();
};

#endif