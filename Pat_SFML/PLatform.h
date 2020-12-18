#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
class PLatform
{
public:
	PLatform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~PLatform();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider()
	{
		return Collider(body);
	}

private:
	sf::RectangleShape body;

};
