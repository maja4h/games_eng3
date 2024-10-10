#pragma once
#include <SFML/Graphics.hpp>
//ship.h
//will contain class declarations, function declarations

class Ship : public sf::Sprite {
protected:
	sf::IntRect _sprite;
	//default constructor is hidden
	Ship();

public:
	//constructor that takes sprite
	explicit Ship(sf::IntRect ir);

	//pure virtual deconstructer - makes then an abstract class
	//and avoids undefined behaviour
	virtual ~Ship() = 0;
	//update, virtual so can be overrridden, but not pure virtual
	virtual void Update(const float& dt);
};