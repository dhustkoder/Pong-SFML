#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "pong.hpp"
#include "ball.hpp"

constexpr float brickWidth  	= 20.f;
constexpr float brickHeight 	= 80.f;
constexpr float brickVelocity  	= 2.5f; 

struct Paddle
{
	sf::Vector2f velocity;
	sf::RectangleShape shape;
	Paddle(float x, float y)
	{

		shape.setPosition(x, y);
		shape.setFillColor(sf::Color::Blue);
		shape.setSize( { brickWidth, brickHeight } );
		shape.setOrigin(static_division(brickWidth,2.f), static_division(brickHeight,2.f));
	
	}
	
	void move()
	{
	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bottom() < HEIGHT)
				velocity.y = brickVelocity;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && top() > 0)
				velocity.y = -brickVelocity;
		
		shape.move(velocity);
		velocity.y = 0;
	
	
	}

	float x() 	const 			{ return shape.getPosition().x; 					}
	float y() 	const			{ return shape.getPosition().y; 					} 
	float top() 	const 		{ return y() - static_division(brickHeight,2.f); 	}
	float bottom() 	const 		{ return y() + static_division(brickHeight,2.f); 	}
	float left() 	const 		{ return x() - static_division(brickWidth,2.f); 	}
	float right() 	const 		{ return x() + static_division(brickWidth,2.f); 	}

};


template <typename T, typename B>
bool collision(T &obj1, B &obj2)
{

	return (( obj1.left() <= obj2.right() && obj1.top() <= obj2.bottom() 
	   && obj1.left() >= obj2.left() && obj1.top() >= obj2.top()) 
		
			||
		 
			( obj2.left() <= obj1.right() && obj2.top() <= obj1.bottom() 
				&& obj2.left() >= obj1.left() && obj2.top() >=obj1.top())); 
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "sfml");
	window.setFramerateLimit(60);
	Ball ball;
	Paddle brick ( 20, static_division(HEIGHT,2.f) );
	
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






