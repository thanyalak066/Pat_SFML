#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "hitboxComponent.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight); // , sf::Vector2f size
	~Player();

	void Update(float deltaTime, sf::Vector2f direction);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	void pos(sf::Vector2f playerPosition);
	void stateChange(sf::RenderWindow& window);
	void stateChange1(sf::RenderWindow& window);
	void setPosition(float x, float y);
	float iframeTimer(float deltaTime, sf::Vector2f direction);
	void damaged(int dmg);
	void drawbar(sf::Vector2f barpos, sf::RenderWindow& window, sf::Vector2f pos);
	void HPre();
	float GetHp() { return hp; }

	sf::Vector2f GetPosition()
	{
		return hitbox.getPosition();
	}
	Collider GetCollider()
	{
		return Collider(hitbox);
	}

	bool checkIntersect(const sf::FloatRect& frect) {
		return hitbox.getGlobalBounds().intersects(frect);
	}

private:
	Animation animation;
	sf::RectangleShape hitbox;
	sf::RectangleShape body;

	unsigned int row;
	float speed;
	bool faceRight;

	float hp;
	float iframe;
	float invince;

	sf::Vector2f velocity;
	bool canJump;
	bool fire;
	float jumpHeight;

	sf::Texture playHP;
	sf::RectangleShape HPbar;
};
