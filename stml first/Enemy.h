#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture CyborgTex;
	sf::Sprite Cyborg;
	int type;
	int hp;
	int hpMax;
	int points;
	int enemypass;
	float patternplus;
	float patternplus2;
	float patternplus3;
	float patternplus4;
	int limitdie;
	//int patternplus3;
	int Type;
	float speedMove;
	

public:
	
	Enemy(float pos_x, float pos_y,int type,int Pattern);
	virtual ~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;	
	const int& getPoint() const;
	const int& getType() const;
	const int& getHP() const;
	const int& getLimitdie()const;
	void loseHP(int lose);
	void loseLimit(int lose2);
	//Function
	void updateCyborgType(int type);
	void updateMomentGame(int type);

	void update();
	void updateEnemy();
	void render(sf::RenderTarget* target);
};
#endif //!ENEMY_H
