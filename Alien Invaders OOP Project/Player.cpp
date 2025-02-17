#include "Player.h"
#include <iostream>

Player::Player(sf::Vector2f pos)
	: baseTexture("Assets/turretBase_big.png")
	, gunTexture("Assets/gun08.png")
	, arrowTexture("Assets/tank_arrowFull.png")
	, baseSprite(baseTexture)
	, gunSprite(gunTexture)
	, arrowSprite(arrowTexture)
	, angle(0.0f)
	, strength(1.0f)
{
	baseSprite.setOrigin(baseSprite.getGlobalBounds().size * 0.5f);
	baseSprite.setPosition(pos);
	gunSprite.setOrigin({ gunSprite.getGlobalBounds().size.x * 0.5f, 0 });
	gunSprite.setPosition(pos);
	gunSprite.setRotation(sf::degrees(-90.0f));
	arrowSprite.setOrigin({ -70, arrowSprite.getGlobalBounds().size.y * 0.5f });
	arrowSprite.setPosition(pos);
}

void Player::DrawTo(sf::RenderTarget& target)
{
	target.draw(baseSprite);
	target.draw(gunSprite);
	target.draw(arrowSprite);
}

void Player::Update(float frameTime)
{
	const float ANGLE_SPEED = 90.0f;
	const float STRENGTH_SPEED = 1.0f;

	// Input handling
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		// Fire ze lazers!
		Fire();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		// Decrease Angle
		AngleChange(-ANGLE_SPEED*frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		// Increase Angle
		AngleChange(ANGLE_SPEED * frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		// Increase Strength
		StrengthChange(STRENGTH_SPEED * frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		// Decrease Strength
		StrengthChange(-STRENGTH_SPEED * frameTime);
	}
}

void Player::Fire()
{
	// TEMP: Print out fire
	std::cout << "FIRE!\n";
}

void Player::AngleChange(float deltaAngle)
{
	angle += deltaAngle;
	const float LOW_LIMIT = -180.0f;
	const float UP_LIMIT = 0.0f;
	if (angle < LOW_LIMIT) angle = LOW_LIMIT;
	if (angle > UP_LIMIT) angle = UP_LIMIT;

	// Update sprites
	gunSprite.setRotation(sf::degrees(angle - 90.0f));
	arrowSprite.setRotation(sf::degrees(angle));
}

void Player::StrengthChange(float deltaStrength)
{
	strength += deltaStrength;
	const float LOW_LIMIT = 0.75f;
	const float UP_LIMIT = 1.5f;
	if (strength < LOW_LIMIT) strength = LOW_LIMIT;
	if (strength > UP_LIMIT) strength = UP_LIMIT;

	// Update sprites
	arrowSprite.setScale({ strength, strength });

}
