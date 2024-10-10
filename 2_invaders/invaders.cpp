#include <SFML/Graphics.hpp>
#include <iostream>
//space invaders

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

//game window variables
const int gameWidth = 800;
const int gameHeight = 600;

void Load() {
	//getting spritesheet
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	//loading the spritesheet
	invader.setTexture(spritesheet);
	//cuts out the bit we want from the spritsheet (left,top) (width height)
	invader.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(32, 32)));

}

//in charge of game logic, eg window control
void Update(RenderWindow& window) {

	//reset clock, recalculate deltatim
	//static Clock clock;
	//float dt = clock.restart().asSeconds();

	// check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}
	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}

void Render(RenderWindow& window) {
	//drawing/rendering the invader sprte from the spritesheet
	window.draw(invader);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Invaders");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}


  return 0;
}