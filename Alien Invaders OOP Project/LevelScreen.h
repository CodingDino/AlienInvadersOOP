#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"

class LevelScreen
{

public:

	// Constructors
	LevelScreen(sf::Vector2f screenSize);
	~LevelScreen();

	// Public Functions
	void DrawTo(sf::RenderTarget& target);
	void Update(float frameTime);

	Bullet* SpawnBullet(sf::Vector2f pos,
		float speed,
		float angle);

private:

	Player* myPlayer;
	std::vector<Bullet*> bullets;
	sf::Texture bulletTex;

};

