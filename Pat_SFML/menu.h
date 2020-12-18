#pragma once
#include <sfml/Graphics.hpp>
#include <stdio.h>
#define MAX_ITEMS 4

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem()
	{
		return selectedItemIndex;
	}

private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];

};
