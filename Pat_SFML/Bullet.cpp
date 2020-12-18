#include "Bullet.h"
#include "Animation.h"
#include <iostream>

Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos, sf::Vector2f size, float cool) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->cool = cool;
	row = 0;
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(pos);
	body.setTexture(texture);
	bool faceleft = false;
	cooling = 0.3; //time is cooldown
}

Bullet::~Bullet()
{
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Bullet::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
		rea = true;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
		rea = true;
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

void Bullet::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos.x - 20.0f, pos.y - 20.0f);
}

void Bullet::updateL(float deltaTime)
{
	velocity.y = 0;
	velocity.x = speed;

	body.move(-(velocity * deltaTime));
	animation.updateBullet(row, deltaTime, false);
	body.setTextureRect(animation.uvRect);
}

void Bullet::updateR(float deltaTime)
{
	velocity.y = 0;
	velocity.x = speed;

	body.move(velocity * deltaTime);
	animation.updateBullet(row, deltaTime, true);
	body.setTextureRect(animation.uvRect);
}

void Bullet::attackL(sf::Vector2f pos)
{
	if (rea == true)
	{
		body.setPosition(pos.x - 50.0f, pos.y);//position bullet L
		rea = false;
	}
}

void Bullet::attackR(sf::Vector2f pos)
{
	if (rea == true)
	{
		body.setPosition(pos.x + 50.0f, pos.y); //position bullet R
		rea = false;
	}
}

float Bullet::cooldown(float deltaTime, int check)
{
	if (cooling < cool) // cooling begin is time //cool 
	{
		cooling += deltaTime;
	}
	if (cooling >= cool)
	{
		if (check != 0)// check bullet              
		{
			cooling = 0.0f;
		}
	}
	return cooling;
}

bool Bullet::checkIntersect(const sf::FloatRect& frect)
{
	return body.getGlobalBounds().intersects(frect);
}

bool Bullet::ready() // status bullet
{
	rea = true;
	return rea;
}