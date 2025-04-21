#include "HorizontalEnemy.h"

HorizontalEnemy::HorizontalEnemy(sf::Texture& enemyTex, 
	sf::Vector2f position, 
	float newScreenWidth)
	: BasicEnemy(enemyTex, position)
	, screenWidth(newScreenWidth)
	, hVel(5.0f * speed)
{

}

void HorizontalEnemy::Move(float frameTime)
{
	// Move horizontally and down
	sprite.move({ hVel*frameTime,speed * frameTime });

	// If the right side of the sprite is touching or to the right of the right side of the screen
	if (sprite.getGlobalBounds().position.x + sprite.getGlobalBounds().size.x >= screenWidth)
	{
		hVel = -5.0f*speed;
	}
	// If the left side of the sprite is touching or to the left of the left side of the screen
	if (sprite.getGlobalBounds().position.x <= 0)
	{
		hVel = 5.0f * speed;
	}
}
