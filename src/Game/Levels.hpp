#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Brick.hpp"

class Levels {
public:
    int layout[6][12]; 
    std::vector<Brick> bricks;  

    static Levels LoadFromFile(const std::string& path);

    void Setup();

    void PrintLayout() const;
};

#endif
