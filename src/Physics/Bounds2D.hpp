#include "../Core/Vector2.hpp"
//Should become a template for use in both 2D and 3D projects
struct Bounds2D{
    public:
        Vector2 minimums;
        Vector2 maximums;
};