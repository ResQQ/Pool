#ifndef TABLE_H
#define TABLE_H

#include "../SFML/Graphics.hpp"
#include "Ball.h"
#include <vector>

#define TABLE_EDGE 84
#define TABLE_LENGTH 1410
#define TABLE_HEIGHT 705

using std::vector;

class Table
{
private:
	sf::Sprite botLayer;
	sf::Texture botTexture;

	sf::Sprite topLayer;
	sf::Texture topTexture;

	sf::Texture ballTex;
	sf::Texture ballStripeTex;

	sf::Sprite ballShadow;
	sf::Texture ballShadowTex;

	float friction;
	float wallCollisionLoss;
	float firePow;

	//balls
	vector<Ball> b;

public:
	~Table();
	void init();
	void update(float deltaTime);
	void mpostest(vec2 in);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void ballFriction(float deltaTime);
	void moveBalls(float deltaTime);
	void collideWall();
	void collideBall();

	void fire(vec2 pos, float charge);
};

#endif