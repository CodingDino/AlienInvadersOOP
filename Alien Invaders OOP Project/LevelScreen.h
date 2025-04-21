#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "BasicEnemy.h"

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
	sf::Texture basicEnemyTex;

	//---
	sf::Font uiFont;
	sf::Text healthText;

	int cityHealth;
	sf::Vector2f screenSize;
	//---


	std::vector<BasicEnemy*> enemies;
	float timeSinceSpawn;
	float spawnCooldown;
	//BasicEnemy* tempEnemy;

};

