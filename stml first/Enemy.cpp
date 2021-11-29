#include "Enemy.h"
#include <iostream>

Enemy::Enemy(float pos_x, float pos_y,int type,int Pattern)
{
	this->patternplus = (Pattern / 100);
	this->patternplus2 = (Pattern / 125);
	this->patternplus3 = (Pattern / 150)*25;
	this->patternplus4 = (Pattern / 60) * 0.1;
	this->Cyborg.setPosition(pos_x, pos_y);
	this->updateCyborgType(type);
}
Enemy::~Enemy()
{

}
//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->Cyborg.getGlobalBounds();
}
const int& Enemy::getPoint() const
{
	return this->points;
}
const int& Enemy::getType() const
{
	return this->Type;
}
const int& Enemy::getHP() const
{
	return this->hp;
}

const int& Enemy::getLimitdie() const
{
	return this->limitdie;
}

void Enemy::loseHP(int lose)
{
	this->hp -= lose;
	if (this->hp < 0)this->hp = 0;
}

void Enemy::loseLimit(int lose2)
{
	this->limitdie -= lose2;
	if (this->limitdie < 0)this->limitdie = 0;
}

void Enemy::updateCyborgType(int type)
{
	if (type == 1)
	{
		if (!this->CyborgTex.loadFromFile("png2/cyborg1new-removebg-preview.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file" << "\n";
		}
		this->Cyborg.setScale(0.3f, 0.3f);
		this->hpMax = 10;
		this->points = 2;
		this->speedMove = 2.f+float(patternplus);
		this->Type = 1;
		this->limitdie = 1;
		//this->Cyborg.setColor(sf::Color::Red);
		
	}
	else if (type == 2)
	{
		if (!this->CyborgTex.loadFromFile("png2/cyborg2remove.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file" << "\n";
		}
		this->Cyborg.setScale(0.1f, 0.1f);
		this->hpMax = 3;
		this->points = 6;
		this->speedMove = 5.f+float(patternplus2);
		this->Type = 2;
		this->limitdie = 2;
		//this->Cyborg.setColor(sf::Color::Green);
		
	}
	else if (type == 3)
	{
		if (!this->CyborgTex.loadFromFile("png2/cyborg3remove.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file" << "\n";
		}
		this->Cyborg.setScale(0.3f, 0.3f);
		this->hpMax = 45+float(patternplus3);
		this->points = 12;
		this->Type = 3;
		this->speedMove = 0.2f+float(patternplus4);
		this->limitdie = 4;
	}
	else if (type == 4)
	{
		if (!this->CyborgTex.loadFromFile("png2/itemstrong.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file" << "\n";
		}
		this->Cyborg.setScale(0.3f, 0.3f);
		this->hpMax = 3;
		this->speedMove = 0.f;
		this->Type = 4;
		this->points = 0;
	}
	else if (type == 5)
	{
		if (!this->CyborgTex.loadFromFile("png2/itemheartremove.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file" << "\n";
		}
		this->Cyborg.setScale(0.08f, 0.08f);
		this->hpMax = 3;
		this->speedMove = 0.f;
		this->Type = 5;
		this->points = 0;
	}
	else if (type == 6)
	{
		if (!this->CyborgTex.loadFromFile("png2/itemstrong2remove.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file" << "\n";
		}
		this->Cyborg.setScale(0.4f, 0.4f);
		this->hpMax = 10;
		this->speedMove = 0.f;
		this->Type = 6;
		this->points = 0;
	}
	this->hp = this->hpMax;
	this->Cyborg.setTexture(this->CyborgTex);
}
void Enemy::updateMomentGame(int type)
{
	
}
//Function

void Enemy::update()
{
	this->Cyborg.move(this->speedMove, 0.f);
}

void Enemy::updateEnemy()
{
	
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->Cyborg);	
}


