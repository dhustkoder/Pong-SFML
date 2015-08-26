#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "ball.hpp"




constexpr float brickWidth  	= 8.f;
constexpr float brickHeight 	= 4.f;
constexpr float brickVelocity  	= 2.5f; 

struct Brick
{
	sf::Vector2f velocity;
	sf::RectangleShape shape;
	Brick(float x, float y)
	{
		shape.setOrigin(static_division(brickWidth,2.f), static_division(brickHeight,2.f));
		shape.setOutlineColor(sf::Color::Red);
		shape.setFillColor(sf::Color::White);
		shape.setPosition(x,y);
		shape.setSize ( { brickWidth*12, brickHeight*12 } ) ;		
	
	}
	void move()
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				velocity.y = brickVelocity;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				velocity.y = -brickVelocity;
		
		shape.move(velocity);
		velocity.y = 0;
	
	
	}





};





int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "sfml");
	window.setFramerateLimit(60);
	Ball ball;
	Brick brick (static_division(WIDTH,2.f), HEIGHT - 50 );
	while(window.isOpen())
	{
		window.clear(sf::Color::Black);
		sf::Event ev;

		if(window.pollEvent(ev))
		{
			if(ev.type == sf::Event::Closed)
				window.close();

			
		
		}
		brick.move();
		ball.move();
		window.draw(ball.shape);
		window.draw(brick.shape);
		window.display();

	}






}
