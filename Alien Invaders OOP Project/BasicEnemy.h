#pragma once

#include <SFML/Graphics.hpp>


class BasicEnemy
{
	// Functionality

public:

	// Constructors
	BasicEnemy(sf::Texture& enemyTex, 
		sf::Vector2f position);

	
	// Public Functions
	void DrawTo(sf::RenderTarget& target);
	void Update(float frameTime);

	// Getters
	sf::FloatRect GetHitbox();
	int GetDamage();
	int GetHealth();

	// Setters
	void ChangeHealth(int amount);

protected:

	virtual void Move(float frameTime);
	

protected:

	int health;
	float speed;
	int damage;

private:

	sf::Sprite sprite;
};

