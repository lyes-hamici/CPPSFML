#ifndef LEVEL_HEADER
#define LEVEL_HEADER
#include <string>
#include <vector>
#include "Brick.hpp"
class Level{
    public:
        std::string name;
        int layout[12][6];
        std::vector<Brick> bricks;
        bool LoadFromFile(std::string path);
        void Setup();
};
#endif