#include <string>
class RenderObject2D{
    public:
        bool enabled; //Property; may call events and perform changes
        std::string imageName;
        FilterMode filteringMode; //Enum
        WrapMode wrapMode; //Enum
        RenderingLayer layer; //Flags
};