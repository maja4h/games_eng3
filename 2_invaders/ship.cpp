#include "ship.h"
#include "game.h"
#include <SFML/Graphics.hpp>
//ship.cpp

using namespace sf;
using namespace std;

sf::Texture spritesheet;

//declaring the ship and invader classes
Ship::Ship() {};
Invader::Invader() : Ship() {};

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(Vector2f(16.f, 16.f));;
	setPosition(pos);
}

void Invader::Update(const float& dt) {
	Ship::Update(dt);
}

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship:: Update(const float &dt) {}

//define the ship deconstructor
//even tho its set to pure virtual, we still have to define it
Ship::~Ship() = default;

