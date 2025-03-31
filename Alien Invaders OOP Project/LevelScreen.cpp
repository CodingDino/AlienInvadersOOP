#include "LevelScreen.h"
#include <string> 

LevelScreen::LevelScreen(sf::Vector2f newScreenSize)
	: myPlayer(nullptr)
	, bullets()
	, bulletTex("Assets/spaceMissiles_040.png")
	, basicEnemyTex("Assets/shipBeige_manned.png")
	//--
	, uiFont("Assets/Oxanium-VariableFont_wght.ttf")
	, healthText(uiFont)
	, cityHealth(100)
	, screenSize(newScreenSize)
	//--
{
	// Create the player and positions it based on screen size
	myPlayer = new Player({ screenSize.x / 2.0f,screenSize.y - 100.0f }, this);

	// TEMP: Create enemy
	enemies.push_back(new BasicEnemy(basicEnemyTex, { screenSize.x / 2.0f, 100.0f }));

	// UI Setup
	healthText.setPosition({ 50, 50 });
	healthText.setString("Health: " + std::to_string(cityHealth));
}

LevelScreen::~LevelScreen()
{
	delete myPlayer;

	for (int i = 0; i < bullets.size(); ++i)
	{
		delete bullets[i];
	}
}

void LevelScreen::DrawTo(sf::RenderTarget& target)
{
	myPlayer->DrawTo(target);
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i]->DrawTo(target);
	}

	// Enemies
	for (int i = 0; i < enemies.size(); ++i)
	{
		enemies[i]->DrawTo(target);
	}

	// UI
	target.draw(healthText);
}

void LevelScreen::Update(float frameTime)
{
	myPlayer->Update(frameTime);

	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i]->Update(frameTime);
	}

	// Enemy
	for (int i = enemies.size()-1; i >= 0; --i)
	{
		enemies[i]->Update(frameTime);

		// Check if enemy has gone past the bottom of the screen
		if (enemies[i]->GetHitbox().position.y > screenSize.y)
		{
			// Damage city
			cityHealth -= enemies[i]->GetDamage();
			healthText.setString("Health: " + std::to_string(cityHealth));

			// remove enemy
			delete enemies[i];
			enemies[i] = nullptr;
			enemies.erase(enemies.begin() + i);

			// Continue
			continue;
		}

		// Check if the enemy has been hit by a bullet
		for (int j = bullets.size()-1; j >= 0; --j) // Iterate in reverse due to removing in loop
		{
			if (bullets[j]->CheckCollision(enemies[i]))
			{
				// Damage the enemy
				bullets[j]->DealDamage(enemies[i]);

				// Remove the bullet
				// We are removing during iteration!
				bullets.erase(bullets.begin()+j);
			}
		}

		// Enemy should die when at 0 health
		if (enemies[i]->GetHealth() <= 0)
		{
			// remove enemy
			delete enemies[i];
			enemies[i] = nullptr;
			enemies.erase(enemies.begin() + i);
		}
	}
}

Bullet* LevelScreen::SpawnBullet(sf::Vector2f pos, float speed, float angle)
{
	Bullet* tempBullet = new Bullet(bulletTex,
		speed,
		angle,
		pos);

	bullets.push_back(tempBullet);

	return tempBullet;
}
