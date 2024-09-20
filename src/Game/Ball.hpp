#ifndef BALL_HEADER
#define BALL_HEADER
#include "../Renderer/RenderObject2D.hpp"
#include "../Physics/CircleCollider2D.hpp"
#include "../Core/Vector2.hpp"
#include "Entity.hpp"
class Ball : public Entity, RenderObject2D, CircleCollider2D{
    public:
        Vector2 velocity;
        using Entity::Entity;
		void Start() override;
		void Update() override;
		void SetEnabled(bool enabled) override;
        //Override hit events
};
#endif