
#include "Player.h"
#include<time.h>
#include<Windows.h>
void Player::initVariables()
{
	this->AttackCooldownMax = 30.f;
	this->AttackCooldown = this->AttackCooldownMax;
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->DirPlayer = 4;
	this->DirForShoot = 4;
}
void Player::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("png2/hunterhunter.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file" << "\n";
	}
}
void Player::initSprite()
{
	//Set the texture to the sprite 
	this->sprite.setTexture(this->texture); 
	//Resize the sprite
	this->sprite.scale(0.85f,0.85f);
	this->sprite.setPosition(650.f, -3.f);
	this->currentFrame = sf::IntRect(0,128,64,64);

	this->sprite.setTextureRect(this->currentFrame);

}
void Player::initAnimation()
{
	this->animationTimer.restart();
}
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimation();
}
Player::~Player()
{

}
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY); 
}
const sf::Vector2f& Player::getPos() const
{
	// TODO: insert return statement here
	return this->sprite.getPosition();
}
const bool Player::canAttack()
{
	if (this->AttackCooldown >= this->AttackCooldownMax)
	{
		this->AttackCooldown = 0.f;
			return true;
	}
	return false;
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int Player::GetDir() const
{
	return this->DirPlayer;
}
void Player::updateChangeAttack(float at,int time)
{
	this->ShootspeedCooldown = time;
	this->AttackCooldownMax = at;
}
void Player::updateMovement()
{
	//std::cout << this->sprite.getPosition().x << " , " << this->sprite.getPosition().y << std::endl;
	
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	//Movement Player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&this->sprite.getPosition().x> 631.f)//631.f
	{
		this->sprite.move(-4.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
		this->DirPlayer = 1;
		this->DirForShoot = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& this->sprite.getPosition().x< 667.f)//667.f
	{
		this->sprite.move(4.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
		this->DirPlayer = 2;
		this->DirForShoot = 2;
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&this->sprite.getPosition().y >= -1.f)
	{
		this->sprite.move(0.f, -4.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_TOP;
		this->DirPlayer = 3;
		this->DirForShoot = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&this->sprite.getPosition().y <= 724.f)
	{
		this->sprite.move(0.f, 4.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_DOWN;
		this->DirPlayer = 4;
		this->DirForShoot = 4;
	}
}
void Player::updateAnimations()
{
	
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		/*if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 448.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}*/
	//Walk
	}
	if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			
			this->currentFrame.top = 576.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 576.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
			
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 704.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 576.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_TOP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 512.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 576.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_DOWN)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 640.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 576.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	//Shoot
	if (this->DirForShoot == 1)
	{
		if (this->isShooting ==true)
		{

			//std::cout << "isShooting" << std::endl;
			this->deltaTime++;
			if (this->deltaTime == 5)
			{
				//std::cout << "Kuay" << std::endl;
				this->shootingmini++;
				this->deltaTime = 0;
				this->currentFrame.top = 1088.f;
				//std::cout << 64.f * this->shootingmini << std::endl;
				this->currentFrame.left += (64.f * this->shootingmini);
				//std::cout << 64.f * this->shootingmini << std::endl;
				if (this->currentFrame.left >= 832.f)
					this->currentFrame.left = 0;
			   	this->sprite.setTextureRect(this->currentFrame);
			}
			if (shootingmini == 5)
			{
				this->shootingmini = 1;
				//Sleep(50);
				//std::cout << "isRestart" << std::endl;
				this->animationTimer.restart();
				this->isShooting = false;
			}
		}
	}
	if (this->DirForShoot == 2)
	{
		if (this->isShooting == true)
		{

			//std::cout << "isShooting" << std::endl;
			this->deltaTime++;
			if (this->deltaTime == 5)
			{
				//std::cout << "Kuay" << std::endl;
				this->shootingmini++;
				this->deltaTime = 0;
				this->currentFrame.top = 1216.f;
				//std::cout << 64.f * this->shootingmini << std::endl;
				this->currentFrame.left += (64.f * this->shootingmini);
				//std::cout << 64.f * this->shootingmini << std::endl;
				if (this->currentFrame.left >= 832.f)
					this->currentFrame.left = 0;
				this->sprite.setTextureRect(this->currentFrame);
			}
			if (shootingmini == 5)
			{
				this->shootingmini = 1;
				//Sleep(50); 
				//std::cout << "isRestart" << std::endl;
				this->animationTimer.restart();
				this->isShooting = false;
			}
		}
	}
	if (this->DirForShoot == 3)
	{
		if (this->isShooting == true)
		{

			//std::cout << "isShooting" << std::endl;
			this->deltaTime++;
			if (this->deltaTime == 5)
			{
				//std::cout << "Kuay" << std::endl;
				this->shootingmini++;
				this->deltaTime = 0;
				this->currentFrame.top = 1024.f;
				//std::cout << 64.f * this->shootingmini << std::endl;
				this->currentFrame.left += (64.f * this->shootingmini);
				//std::cout << 64.f * this->shootingmini << std::endl;
				if (this->currentFrame.left >= 832.f)
					this->currentFrame.left = 0;
				this->sprite.setTextureRect(this->currentFrame);
			}
			if (shootingmini == 5)
			{
				this->shootingmini = 1;
				//Sleep(50);
				//std::cout << "isRestart" << std::endl;
				this->animationTimer.restart();
				this->isShooting = false;
			}
		}
	}
	if (this->DirForShoot == 4)
	{
		if (this->isShooting == true)
		{

			//std::cout << "isShooting" << std::endl;
			this->deltaTime++;
			if (this->deltaTime == 5  ) 
			{
				//std::cout << "Kuay" << std::endl;
				this->shootingmini++;
				this->deltaTime = 0;
				this->currentFrame.top = 1152.f;
				//std::cout << 64.f * this->shootingmini << std::endl;
				this->currentFrame.left += (64.f * this->shootingmini);
				//std::cout << 64.f * this->shootingmini << std::endl;
				if (this->currentFrame.left >= 832.f)
					this->currentFrame.left = 0;
				this->sprite.setTextureRect(this->currentFrame);
			}
			if (shootingmini == 5)
			{
				this->shootingmini = 1;
				//Sleep(50);
				//std::cout << "isRestart" << std::endl;
				this->animationTimer.restart();
				this->isShooting = false;
			}
		}
	}
}
void Player::updateAttack()
{
	if (this->AttackCooldown < this->AttackCooldownMax)
		this->AttackCooldown += 0.7f;
	
}
void Player::update()
{
	this->updateAttack();
	this->updateMovement();
	this->updateAnimations();
	this->ShootspeedCooldown -= 1;
	if (this->ShootspeedCooldown <= 0)
	{
		this->AttackCooldownMax = 30.f; 
	}

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}



void Player::updateAnimationsShooting(bool shooting)
{
	this->isShooting = shooting;
}

