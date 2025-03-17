#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <math.h>

Bullet::Bullet(sf::Texture& bulletTex,
	float firingSpeed,
	float firingAngle,
	sf::Vector2f position)
	: sprite(bulletTex)
	, velocity({0,0})
	, damage(10) // Update as needed
{
	// Sprite setup
	sprite.setOrigin(sprite.getGlobalBounds().size * 0.5f);
	sprite.setPosition(position);
	sprite.setRotation(sf::degrees(firingAngle-90.0f));

	// Calculate velocity
	// Angle is in degrees - must convert to radians
	float angleInDegrees = firingAngle;
	float angleInRadians = angleInDegrees * M_PI / 180.0f;

	// Use cos to convert to x and sin to convert to y
	float x = cos(angleInRadians);
	float y = -sin(angleInRadians); // negative because up is negative

	// Multiply x and y by firingSpeed to scale the velocity
	x *= firingSpeed;
	y *= firingSpeed;

	// Set our velocity to a vector using x and y
	velocity = { x, y };
}

void Bullet::DrawTo(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Bullet::Update(float frameTime)
{
	sprite.move(velocity * frameTime);
}

bool Bullet::CheckCollision()
{
	// TODO: Return to this when enemies are created
	return false;
}

void Bullet::DealDamage()
{
	// TODO: Return to this when enemies are created
}
