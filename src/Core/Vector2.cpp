#define _USE_MATH_DEFINES //Needs to be before the cmath include
#include <string>
#include <stdexcept>
#include <cmath>
#include "Vector2.hpp"
//================================
// Constructors
//================================
Vector2::Vector2(){}
Vector2::Vector2(float value){
	this->x = value;
	this->y = value;
}
Vector2::Vector2(float x,float y){
	this->x = x;
	this->y = y;
}
Vector2::~Vector2(){}
float& Vector2::operator[](int index){
	if(index < 0 || index > 1){throw std::out_of_range("[Vector2] Index '"+std::to_string(index)+"' out of range (0-1).");}
	return index == 0 ? this->x : this->y;
}
//================================
// Operators
//================================
bool Vector2::operator==(Vector2 other){
	return this->x == other.x && this->y == other.y;
}
Vector2 Vector2::operator+(Vector2 other){
	return Vector2(this->x + other.x,this->y + other.y);
}
Vector2 Vector2::operator+(float value){
	return Vector2(this->x + value,this->y + value);
}
Vector2 Vector2::operator-(Vector2 other){
	return Vector2(this->x - other.x,this->y - other.y);
}
Vector2 Vector2::operator-(float value){
	return Vector2(this->x - value,this->y - value);
}
Vector2 Vector2::operator*(Vector2 other){
	return Vector2(this->x * other.x,this->y * other.y);
}
Vector2 Vector2::operator*(float scale){
	return Vector2(this->x * scale,this->y * scale);
}
Vector2 Vector2::operator/(Vector2 other){
	return Vector2(this->x / other.x,this->y / other.y);
}
Vector2 Vector2::operator/(float divider){
	return Vector2(this->x / divider,this->y / divider);
}
//================================
// Functions
//================================
void Vector2::Set(float value){
	this->x = value;
	this->y = value;
}
void Vector2::Set(float x,float y){
	this->x = x;
	this->y = y;
}
Vector2 Vector2::MoveTowards(Vector2 other,float amount){
	auto vector = Vector2();
	if(this->x < other.x){
		vector.x = std::min(this->x + amount,other.x);
	}
	else if(this->x > other.x){
		vector.x = std::max(this->x - amount,other.x);
	}
	if(this->y < other.y){
		vector.y = std::min(this->y + amount,other.y);
	}
	else if(this->y > other.y){
		vector.y = std::max(this->y - amount,other.y);
	}
	return vector;
}
float Vector2::Magnitude(){
	return std::sqrtf(this->x * this->x + this->y * this->y);
}
float Vector2::SquaredMagnitude(){
	return this->x * this->x + this->y * this->y;
}
Vector2 Vector2::Normalize(){
	auto threshold = 0.00001f;
	auto magnitude = this->Magnitude();
	return magnitude > threshold ? *this / magnitude : Vector2();
}
float Vector2::DotProduct(Vector2 other){
	return this->x * other.x + this->y * other.y;
}
float Vector2::Angle(Vector2 from,Vector2 to){
	auto denominator = std::sqrtf(from.SquaredMagnitude() * to.SquaredMagnitude());
	auto threshold = 0.000000000001;
	if(denominator < threshold){return 0;}
	auto dotProduct = from.DotProduct(to) / denominator;
	return std::acos(dotProduct) * (180 / M_PI);
}
float Vector2::SignedAngle(Vector2 from,Vector2 to){
	auto unsignedAngle = Vector2::Angle(from,to);
	auto sign = from.x * to.y - from.y * to.x;
	sign = sign >= 0 ? 1 : -1;
	return unsignedAngle * sign;
}
Vector2 Vector2::Remap(Vector2 fromA,Vector2 toA,Vector2 fromB,Vector2 toB){
	return fromB + (toB - fromB) * ((*this - fromA) / (toA - fromA));
}
Vector2 Vector2::FromAngle(float angle){
	angle *= M_PI / 180;
	return Vector2(std::sin(angle),std::cos(angle));
}