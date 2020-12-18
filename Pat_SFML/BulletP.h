#pragma once
#include <SFML/Graphics.hpp>

class BulletP
{
public:
	BulletP(sf::Vector2f size);
	~BulletP();

	void Fire(float Bspeed);
	void Draw(sf::RenderWindow& window);
	void setPos(sf::Vector2f newPos);

	float getRight();
	float getLeft();
	float getTop();
	float getBottom();

private:
	sf::RectangleShape bulletPlayer;
	sf::Vector2f size;
};