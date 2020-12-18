#include "PLatform.h"

PLatform::PLatform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(sf::Vector2f(size / 2.0f));
	body.setTexture(texture);
	body.setPosition(position);
}

PLatform::~PLatform()
{
}

void PLatform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}