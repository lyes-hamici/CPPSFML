#ifndef RENDEROBJECTS2D_HEADER
#define RENDEROBJECTS2D_HEADER
#include "Renderer.hpp"
#include <string>
class RenderObject2D{
    public:
        static std::map<std::string,RenderObject2D> all;
        bool renderingEnabled; //Property; may call events and perform changes
        std::string imageName;
        FilterMode filteringMode; //Enum
        WrapMode wrapMode; //Enum
};
#endif