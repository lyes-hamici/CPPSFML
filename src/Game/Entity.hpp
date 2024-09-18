#ifndef ENTITY_HEADER
#define ENTITY_HEADER
#include "../Renderer/Transform2D.hpp"
class Entity : public Transform2D{
	public:
		virtual void Start();
		virtual void Update();
		virtual void SetEnabled(bool enabled);
		bool IsEnabled();
};
#endif