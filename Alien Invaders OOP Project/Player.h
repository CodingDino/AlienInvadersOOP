#pragma once
#include <SFML/Graphics.hpp>

class Player
{
	// Functionality

public:

	// Constructors
	Player(sf::Vector2f pos);

	// Public functions
	void DrawTo(sf::RenderTarget& target);
	void Update(float frameTime);

	// Private functions
	void Fire();
	void AngleChange(float deltaAngle);
	void StrengthChange(float deltaStrength);

	// Data

private:

	sf::Texture baseTexture;
	sf::Texture gunTexture;
	sf::Texture arrowTexture;

	sf::Sprite baseSprite;
	sf::Sprite gunSprite;
	sf::Sprite arrowSprite;

	float angle;
	float strength;

};

