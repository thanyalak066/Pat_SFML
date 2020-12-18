#include "menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("font/font.ttf"))
	{
		//handle error
	}

	menu[0].setFont(font);
	//menu[0].setCharacterSize(70);
	menu[0].setFillColor(sf::Color::Magenta);
	menu[0].setCharacterSize(63);
	menu[0].setString("PLAY!");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(200.0f, 141.0f));
	//menu[0].setPosition(sf::Vector2f(width / 6, height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	//menu[2].setFillColor(sf::Color::Red);
	menu[1].setCharacterSize(45);
	menu[1].setString("HOW TO PLAY");
	menu[1].setOrigin(menu[2].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(132.0f, 300.0f));
	//menu[1].setPosition(sf::Vector2f(width / 5, height / (MAX_ITEMS + 1) * 2.1));

	menu[2].setFont(font);
	//menu[1].setFillColor(sf::Color::Red);
	menu[2].setCharacterSize(45);
	menu[2].setString("TOP SCORE");
	menu[2].setOrigin(menu[1].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(333.0f, 448.0f));
	//menu[2].setPosition(sf::Vector2f(width / 4, height / (MAX_ITEMS + 1) * 3.3));

	menu[3].setFont(font);
	//menu[2].setFillColor(sf::Color::Red);
	menu[3].setCharacterSize(45);
	menu[3].setString("EXIT GAME");
	menu[3].setOrigin(menu[2].getLocalBounds().width / 2, menu[3].getLocalBounds().height / 2);
	menu[3].setPosition(sf::Vector2f(348.0f, 596.0f));
	//menu[3].setPosition(sf::Vector2f(width / 3, height / (MAX_ITEMS + 1) * 4.4));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}

}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}

}