#include <SFML/Graphics.hpp>
//PONG game

using namespace sf;
using namespace std;

//Player keyboard controls
const Keyboard::Key controls[4] = {
    Keyboard::W, //PLayer up
    Keyboard::S, //Player down
    Keyboard::Up, //Player up
    Keyboard::Down, //Player down
};

//setting up variables for paddles and dimensions of the game
const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const int paddleSpeed = 400.f;
const float paddleOffsetWall = 10.f;
//adding ball velocity
Vector2f ballVelocity;
bool isPlayer1Serving = false;
const float initialVelocityX = 100.f;
const float initialVelocityY = 60.f;
//adding multiplayer
const float velocityMulti = 1.1f;

//setting up the shapes of the balls and paddles
CircleShape ball;
RectangleShape paddles[2];

//loading in assets for paddles and ball
void Load() {
    //set size and origin of paddles
    for (auto& p : paddles) {
        p.setSize(paddleSize);
        p.setOrigin(paddleSize / 2.f);
    }

    //set size and origin of ball
    ball.setRadius(ballRadius);
    ball.setOrigin(ball.getRadius(), ball.getRadius());

    //reset paddle position
    paddles[0].setPosition(Vector2f(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f));
    paddles[1].setPosition(Vector2f(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f));

    //reset ball position
    ball.setPosition(400, 300);

    //ball velocity, making it move
    ballVelocity = { (isPlayer1Serving ? initialVelocityX : -initialVelocityX), initialVelocityY };
}

void Reset() {

    //reset paddle position
    paddles[0].setPosition(Vector2f(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f));
    paddles[1].setPosition(Vector2f(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f));

    //reset ball position
    ball.setPosition(400, 300);

    //ball velocity, making it move
    ballVelocity = { (isPlayer1Serving ? initialVelocityX : -initialVelocityX), initialVelocityY };

}

//where game logic goes
void Update(RenderWindow& window) {

    //reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();

    // check and consume events
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }

    //ball moving function
    ball.move(ballVelocity * dt);

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    // handle paddle movement
    float direction = 0.0f;
    if (Keyboard::isKeyPressed(controls[0])) {
        direction--;
    }
    if (Keyboard::isKeyPressed(controls[1])) {
        direction++;
    }

    paddles[0].move(Vector2f(0.f, direction * paddleSpeed * dt));

    //check ball collision
    const float bx = ball.getPosition().x;
    const float by = ball.getPosition().y;
    if (by > gameHeight) {
        //bottom wall
        ballVelocity.x *= velocityMulti;
        ballVelocity.y *= -velocityMulti;
        ball.move(Vector2f(0.f, -10.f));
    }
    else if (by < 0) {
        //top wall
        ballVelocity.x *= velocityMulti;
        ballVelocity.y *= -velocityMulti;
        ball.move(Vector2f(0.f, 10.f));
    }
}

//render function
void Render(RenderWindow& window) {

    //draw everything
    window.draw(paddles[0]);
    window.draw(paddles[1]);
    window.draw(ball);
}

int main(){
    RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }

  return 0;
}