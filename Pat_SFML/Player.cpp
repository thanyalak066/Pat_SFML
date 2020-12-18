#include "Player.h"
#include "Animation.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime) //  sf::Vector2f size
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;// this-> is *pointer 

	row = 0;
	faceRight = true;
	fire = false;
	canJump = false;

	body.setSize(sf::Vector2f(125.f, 128.f)); //scale charactor
	body.setTexture(texture);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);
	body.setPosition(275.0f, 312.0f); // position

	hitbox.setSize(sf::Vector2f(44.f, 88.f));
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOutlineColor(sf::Color::Blue);
	hitbox.setPosition(body.getPosition());

	playHP.loadFromFile("hp/playerHP.png");
	HPbar.setTexture(&playHP);
	HPbar.setSize(sf::Vector2f(260.0f, 94.0f));

	if (row == 0)
	{
		switchTime = 0.3f;
	}
	else if (velocity.y < 0.0f)
	{
		switchTime = 0.0f;
	}
	else
	{
		switchTime = 0.1f;
	}

	hp = 150.0f;
	iframe = 1.7f;
	invince = 1.7f;
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::Vector2f direction)
{

	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
		faceRight = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
		faceRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 499.0f * jumpHeight);
		row = 1;
		//square root (2.0f * gravity * jumpHeight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fire = true;
		row = 1;
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
	if (velocity.y != 0.0f && fire == true)
	{
		row = 1;
	}
	fire = false;
	if (velocity.x != 0.0f && fire == false)
	{
		row = 2;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	//velocity.y += 999.0f * deltaTime; /////////

	animation.Update(row, deltaTime, faceRight, fire);
	body.setTextureRect(animation.uvRect);
	hitbox.move(velocity * deltaTime);
	body.setPosition(hitbox.getPosition());
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}

void Player::OnCollision(sf::Vector2f direction)
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
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//collision on the top.
		velocity.y = 0.0f;
	}
}

void Player::pos(sf::Vector2f playerPosition)
{
	return this->body.setPosition(playerPosition.x, playerPosition.y);
}

void Player::stateChange(sf::RenderWindow& window)
{
	hitbox.setPosition(14070.0f, 0.0f);
	body.setPosition(hitbox.getPosition());
}

void Player::stateChange1(sf::RenderWindow& window)
{
	hitbox.setPosition(14240.0f, 400.0f);
	body.setPosition(hitbox.getPosition());
}

void Player::setPosition(float x, float y)
{
	hitbox.setPosition(x, y);
	body.setPosition(hitbox.getPosition());
}

float Player::iframeTimer(float deltaTime, sf::Vector2f direction)
{
	if (iframe < invince)
	{
		iframe += deltaTime;
	}
	if (iframe <= 0.25f)
	{
		if (direction.x < 0.0f)
		{
			//left			
			body.move(-100.0f * deltaTime, 0.0f);
		}
		else if (direction.x > 0.0f)
		{
			//right
			body.move(100.0f * deltaTime, 0.0f);

		}
		if (direction.y != 0.0f)
		{
			if (faceRight == false)
			{
				body.move(100.0f * deltaTime, 0.0f);
			}
			if (faceRight == true)
			{
				body.move(-100.0f * deltaTime, 0.0f);
			}
		}
	}
	return iframe;
}

void Player::damaged(int dmg)
{
	if (iframe >= invince)
	{
		int i = 0;
		for (i = 0; i < dmg; i++)
		{
			if (hp > 0.0f)
			{
				hp = hp - 1.0f;
			}
		}
		iframe = 0;
	}
}

void Player::HPre()
{
	hp = 150;
}


void Player::drawbar(sf::Vector2f barpos, sf::RenderWindow& window, sf::Vector2f pos)
{
	sf::RectangleShape hpbar;
	sf::RectangleShape hpback;

	hpbar.setSize(sf::Vector2f(hp * 1.5, 25.0f));
	hpbar.setOrigin(body.getSize() / 2.0f);
	hpbar.setPosition(barpos.x - 400.0f, barpos.y - 270.0f);
	hpbar.setFillColor(sf::Color::Red);
	hpback.setSize(sf::Vector2f(150.0f, 25.0f));
	hpback.setOrigin(body.getSize() / 2.0f);
	hpback.setPosition(barpos.x - 400.0f, barpos.y - 270.0f);
	hpback.setFillColor(sf::Color::White);
	HPbar.setPosition(pos.x - 516, pos.y - 342);  //(sf::Vector2f(24.0f, 18.0f));

	window.draw(HPbar);
	window.draw(hpback);
	window.draw(hpbar);
}