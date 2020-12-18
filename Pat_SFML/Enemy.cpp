#include "Enemy.h"
#include "Animation.h"
#include <iostream>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	hp = 5;

	row = 0;
	faceLeft = true;
	fire = false;
	canJump = true;

	body.setTexture(texture);
	body.setPosition(position);
	body.setSize(sf::Vector2f(115.f, 100.0f));
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	//hp bar enemy
	hpBar.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y - 40));
	hpBar.setOrigin(hpBar.getSize() / 2.0f);

	hitboxEnemy.setSize(sf::Vector2f(50.0f, 85.0f));
	hitboxEnemy.setOrigin(hitboxEnemy.getSize() / 2.f);
	hitboxEnemy.setFillColor(sf::Color::Transparent);
	hitboxEnemy.setOutlineThickness(1.f);
	hitboxEnemy.setOutlineColor(sf::Color::Green);
	hitboxEnemy.setPosition(body.getPosition());
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, sf::Vector2f direction, int check)
{
	hpBar.setPosition(sf::Vector2f(body.getPosition().x - 40, body.getPosition().y - 40));

	if (check == 1)
	{
		velocity.x = -200.0f;
	}
	if (check == 0)
	{
		velocity.x = 200.0f;
	}
	if (check == 2)
	{
		velocity.x = 0.0f;
	}
	if (direction.y >= 0)
	{
		velocity.y += 981.0f * deltaTime;

	}
	if (direction.y == -1)
	{
		velocity.y = 0;
	}


	if (velocity.x == 0.0f && velocity.y == 0.0f && fire == false)
	{
		row = 0;
	}
	if (velocity.x == 0.0f && velocity.y == 0.0f && fire == true)
	{
		row = 1;
	}
	if (velocity.y < 0.0f && fire == true)
	{
		row = 1;
	}
	if (velocity.y < 0.0f && fire == false)
	{
		row = 2;
	}

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	if (velocity.x != 0.0f && fire == true)
	{
		velocity.x = 0.0f;
		row = 1;
	}
	fire = false;
	if (velocity.x != 0.0f && fire == false)
	{
		row = 2;
		if (velocity.x > 0.0f)
			faceLeft = false;
		else
			faceLeft = true;
	}
	row = 0;
	hpBar.setSize(sf::Vector2f(hp * 14, 5.0f));
	hpBar.setFillColor(sf::Color::Red);
	animation.updateEnemy(row, deltaTime, faceLeft);
	body.setTextureRect(animation.uvRect);
	hitboxEnemy.move(velocity * deltaTime);
	body.setPosition(hitboxEnemy.getPosition());
	hpBar.setPosition(sf::Vector2f(body.getPosition().x - 35, body.getPosition().y - 40));
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitboxEnemy);
	window.draw(hpBar);
}

void Enemy::OnCollision1(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		//collision on the bottom.
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//collision on the top.
		velocity.y = 0.0f;
	}
}

void Enemy::updateHP(int hit)
{
	if (hp > 0)
	{
		hp -= hit;
	}
	//bot died
	/*if (hp <= 0)
	{
		body.setPosition(sf::Vector2f(31000.0f, 500.0f));
	}*/
}

bool Enemy::checkIntersect(const sf::FloatRect& frect)
{
	return hitboxEnemy.getGlobalBounds().intersects(frect);
}

void Enemy::setPos(float x, float y)
{
	hitboxEnemy.setPosition(x, y);
	body.setPosition(hitboxEnemy.getPosition());
	hpBar.setPosition(hitboxEnemy.getPosition());
}

void Enemy::follow()
{
}
