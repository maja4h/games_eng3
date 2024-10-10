#include "ship.h"
//ship.cpp

using namespace sf;
using namespace std;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship:: Update(const float &dt) {}

//define the ship deconstructor
//even tho its set to pure virtual, we still have to define it
Ship::~Ship() = default;
