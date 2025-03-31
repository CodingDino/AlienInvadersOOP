#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(sf::Texture& enemyTex, 
	sf::Vector2f position)
	: health (30)
	, speed (50.0f)
	, damage (5)
	, sprite (enemyTex)
{
	sprite.setScale({ 0.5f,0.5f });
	sprite.setOrigin(sprite.getGlobalBounds().size * 0.5f);
	sprite.setPosition(position);
}

void BasicEnemy::DrawTo(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void BasicEnemy::Update(float frameTime)
{
	Move(frameTime);
}

sf::FloatRect BasicEnemy::GetHitbox()
{
	return sprite.getGlobalBounds();
}

int BasicEnemy::GetDamage()
{
	return damage;
}

int BasicEnemy::GetHealth()
{
	return health;
}

//---
void BasicEnemy::ChangeHealth(int amount)
{
	health += amount;
}
//---

void BasicEnemy::Move(float frameTime)
{
	// Move straight downward
	sprite.move({ 0.0f,speed * frameTime });
}
