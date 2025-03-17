#include "LevelScreen.h"

LevelScreen::LevelScreen(sf::Vector2f screenSize)
	: myPlayer(nullptr)
	, bullets()
	, bulletTex("Assets/spaceMissiles_040.png")
{
	// Create the player and positions it based on screen size
	myPlayer = new Player({ screenSize.x / 2.0f,screenSize.y - 100.0f });

	/*
	tempBullet = new Bullet(bulletTex,
		50,
		45,
		{ screenSize.x / 2.0f,screenSize.y - 100.0f });
	*/
	// TEMP
	SpawnBullet({ screenSize.x / 2.0f,screenSize.y - 100.0f },
		50,
		45);
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
}

void LevelScreen::Update(float frameTime)
{
	myPlayer->Update(frameTime);
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i]->Update(frameTime);
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
