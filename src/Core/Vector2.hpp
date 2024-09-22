#ifndef VECTOR2_HEADER
#define VECTOR2_HEADER
class Vector2{
	public:
		float x;
		float y;
        Vector2();
        Vector2(float value);
        Vector2(float x,float y);
        ~Vector2();
		float& operator[](int index);
		bool operator==(Vector2 other);
		Vector2 operator+(Vector2 other);
		Vector2 operator+(float value);
		Vector2 operator-(Vector2 other);
		Vector2 operator-(float value);
		Vector2 operator*(Vector2 other);
		Vector2 operator*(float scale);
		Vector2 operator/(Vector2 other);
		Vector2 operator/(float divider);
		static float Angle(Vector2 from,Vector2 to);
		static float SignedAngle(Vector2 from,Vector2 to);
		static Vector2 FromAngle(float angle);
        void Set(float x,float y);
        void Set(float value);
		void Clear();
		Vector2 MoveTowards(Vector2 other,float amount);
		float Magnitude();
		float SquaredMagnitude();
		Vector2 Normalize();
		float DotProduct(Vector2 other);
		Vector2 Remap(Vector2 fromA,Vector2 toA,Vector2 fromB,Vector2 toB);
		bool Within(Vector2 minimum,Vector2 maximum);
		Vector2 Clamp(Vector2 minimum,Vector2 maximum);
		float DistanceFrom(Vector2 other);
		Vector2 Absolute();
		Vector2 Swap();
};
#endif