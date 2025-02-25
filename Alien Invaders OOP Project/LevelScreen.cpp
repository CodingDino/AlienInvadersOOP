#include "LevelScreen.h"

LevelScreen::LevelScreen(sf::Vector2f screenSize)
	: myPlayer(nullptr)
{
	// Create the player and positions it based on screen size
	myPlayer = new Player({ screenSize.x / 2.0f,screenSize.y - 100.0f });

}

LevelScreen::~LevelScreen()
{
	delete myPlayer;
}

void LevelScreen::DrawTo(sf::RenderTarget& target)
{
	myPlayer->DrawTo(target);
}

void LevelScreen::Update(float frameTime)
{
	myPlayer->Update(frameTime);
}
