#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "hitboxComponent.h"
class Boss
{
public:
	Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position); // , sf::Vector2f size
	~Boss();

	void Update(float deltaTime, sf::Vector2f direction);
	void Draw(sf::RenderWindow& window);
	void posi(sf::Vector2f playerPosition);
	void OnCollision2(sf::Vector2f direction);
	void updateHP(int hit);
	bool checkIntersect(const sf::FloatRect& frect);
	void setPos(float x, float y);
	int getHP()
	{
		return this->hp;
	}

	sf::Vector2f GetPosition()
	{
		return hitboxBoss.getPosition();
	}
	Collider GetCollider2()
	{
		return Collider(hitboxBoss);
	}

private:
	Animation animation;
	sf::RectangleShape body;
	sf::RectangleShape hpBar;
	sf::RectangleShape hitboxBoss;

	unsigned int row;
	float speed;
	bool faceLeft;

	sf::Vector2f velocity;
	bool canJump;
	bool fire;
	float jumpHeight;

	int hp;
};