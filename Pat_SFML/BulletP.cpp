#include "BulletP.h"

BulletP::BulletP(sf::Vector2f size)
{
	bulletPlayer.setSize(size);
	bulletPlayer.setFillColor(sf::Color::Blue);
	/*body.setSize(size);
	body.setOrigin(sf::Vector2f(size / 2.0f));
	body.setTexture(texture);
	body.setPosition(position);*/
}

BulletP::~BulletP()
{
}

void BulletP::Fire(float Bspeed)
{
	bulletPlayer.move(Bspeed, 0);
}

void BulletP::Draw(sf::RenderWindow& window)
{
	window.draw(bulletPlayer);
}

void BulletP::setPos(sf::Vector2f newPos)
{
	bulletPlayer.setPosition(newPos);
}

float BulletP::getRight()
{
	return bulletPlayer.getPosition().x + bulletPlayer.getSize().x;
}

float BulletP::getLeft()
{
	return bulletPlayer.getPosition().x;
}

float BulletP::getTop()
{
	return bulletPlayer.getPosition().y;
}

float BulletP::getBottom()
{
	return bulletPlayer.getPosition().y + bulletPlayer.getSize().y;
}