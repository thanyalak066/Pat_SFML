#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include <iostream>
#include "Collider.h"
using namespace std;

class Bullet
{
public:
	Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos, sf::Vector2f size, float cool);
	~Bullet();
	void draw(sf::RenderWindow& window);
	void onCollision(sf::Vector2f direction);
	void setPosition(sf::Vector2f pos);
	void updateL(float deltaTime);
	void updateR(float deltaTime);
	void attackL(sf::Vector2f pos);
	void attackR(sf::Vector2f pos);
	float cooldown(float deltaTime, int check);
	bool checkIntersect(const sf::FloatRect& frect);
	bool ready();

	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	}
	Collider GetCollider()
	{
		return Collider(body);
	}

private:
	Animation animation;
	sf::RectangleShape body;
	sf::Vector2f velocity;

	float speed;
	float cooling;
	float cool;
	unsigned int row;

	bool rea = true;
};