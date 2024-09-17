#include "../Renderer/Transform2D.hpp"
class Entity : public Transform2D{
    public:
        bool enabled; //Property; may call events and perform changes
        virtual void Start();
        virtual void Update();
};