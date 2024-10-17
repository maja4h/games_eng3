#pragma once
#include <SFML/Graphics.hpp>
//game.h

//global variables
constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;
constexpr uint16_t invaders_rows = 5;
constexpr uint16_t invaders_columns = 12;

//making the spritesheet global so that all parts can access it
extern sf::Texture spritesheet;
