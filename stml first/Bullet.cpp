#include "Bullet.h"
Bullet::Bullet( float pos_x, float pos_y, float movement_speed,int PlayerGetDir)
{
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(0.2f, 0.2f);
	this->movementSpeed = movement_speed;
	this->Dir = PlayerGetDir;
	if (this->Dir == 1)
	{
		this->texture.loadFromFile("png2/arrow1.png");
	}
	if (this->Dir == 2)
	{
		this->texture.loadFromFile("png2/arrow2.png");
	}
	if (this->Dir == 3)
	{
		this->texture.loadFromFile("png2/arrow3.png");
	}
	if (this->Dir == 4)
	{
		this->texture.loadFromFile("png2/arrow4.png");
	}
	this->shape.setTexture(this->texture);
}



Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	//Movement
	
	if (this->Dir == 1)
	{
		this->shape.move(this->movementSpeed * -2,0.f);
	}
	if (this->Dir == 2)
	{
		this->shape.move(this->movementSpeed * 2,0.f);
	}
	if (this->Dir == 3)
	{
		this->shape.move(0.f,this->movementSpeed * -2);
	}
	if (this->Dir == 4)
	{
		this->shape.move(0.f,this->movementSpeed * 2);
	}
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
