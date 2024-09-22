#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Brick.hpp"

class Level {
public:

    std::string name;
    int layout[6][12]; 
    std::vector<Brick> bricks;
    bool empty;
    bool LoadFromFile(const std::string& path);
    void Start();
    void Update();
};

#endif
