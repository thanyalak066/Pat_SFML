#include "Boss.h"
#include "Animation.h"
#include <iostream>

Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	hp = 30;

	row = 0;
	faceLeft = true;
	fire = false;
	canJump = true;

	body.setTexture(texture);
	body.setPosition(position);
	body.setSize(sf::Vector2f(213.f, 261.0f));
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	//hp bar boss
	hpBar.setPosition(sf::Vector2f(body.getPosition().x - 60, body.getPosition().y - 150));
	hpBar.setOrigin(hpBar.getSize() / 2.0f);

	hitboxBoss.setSize(sf::Vector2f(96.0f, 124.0f));
	hitboxBoss.setOrigin(hitboxBoss.getSize() / 2.f);
	hitboxBoss.setFillColor(sf::Color::Transparent);
	hitboxBoss.setOutlineThickness(1.f);
	hitboxBoss.setOutlineColor(sf::Color::Green);
	hitboxBoss.setPosition(body.getPosition());
}

Boss::~Boss()
{
}

void Boss::posi(sf::Vector2f playerPosition)
{
	return this->body.setPosition(playerPosition.x, playerPosition.y);
}

void Boss::Update(float deltaTime, sf::Vector2f direction)
{
	hpBar.setPosition(sf::Vector2f(body.getPosition().x - 60, body.getPosition().y - 150));

	velocity.x = 0.0f;
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
			faceLeft = true;
		else
			faceLeft = false;
	}
	hpBar.setSize(sf::Vector2f(hp * 4, 18.0f));
	hpBar.setFillColor(sf::Color::Green);
	animation.updateEnemy(row, deltaTime, faceLeft);
	body.setTextureRect(animation.uvRect);
	hitboxBoss.move(velocity * deltaTime);
	body.setPosition(hitboxBoss.getPosition());
}

void Boss::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitboxBoss);
	window.draw(hpBar);
}

void Boss::OnCollision2(sf::Vector2f direction)
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

void Boss::updateHP(int hit)
{
	if (hp > 0)
	{
		hp -= hit;
	}
}

bool Boss::checkIntersect(const sf::FloatRect& frect)
{
	return hitboxBoss.getGlobalBounds().intersects(frect);
}

void Boss::setPos(float x, float y)
{
	hitboxBoss.setPosition(x, y);
	body.setPosition(hitboxBoss.getPosition());
}