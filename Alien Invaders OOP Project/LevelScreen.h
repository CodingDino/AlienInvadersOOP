#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class LevelScreen
{

public:

	// Constructors
	LevelScreen(sf::Vector2f screenSize);
	~LevelScreen();

	// Public Functions
	void DrawTo(sf::RenderTarget& target);
	void Update(float frameTime);

private:

	Player* myPlayer;

};

