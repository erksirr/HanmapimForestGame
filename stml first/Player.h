#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
enum PLAYER_ANIMATION_STATES
{IDLE = 0,
MOVING_LEFT,
MOVING_RIGHT,
MOVING_TOP,
MOVING_DOWN,
};
class Player
{
	private:
		sf::Sprite sprite;
		sf::Texture texture;  
		sf::Clock animationTimer;
		int target;

		int deltaTime = 0;
		int DirPlayer;
		int shootingmini = 1;
		int DirForShoot;
		int ShootspeedCooldown;
		float movementSpeed;
		float AttackCooldown;
		float AttackCooldownMax;
		bool isShooting = false;
		//Animation 
		short animState;
		sf::IntRect currentFrame;
		//Private functions
		void initVariables();
		void initTexture();
		void initSprite();
		void initAnimation();
	public:
		Player();
		virtual ~Player();
		//Accessor
		const sf::Vector2f& getPos()const;
		const sf::FloatRect getBounds() const;
		

		const int GetDir() const;
		//Function
		void move(const float dirX,const float dirY);
		const bool canAttack();
		void updateAnimations();
		void updateAnimationsShooting(bool shooting);
		void updateMovement();
		void updateChangeAttack(float at,int time);
		void updateAttack();
		void update();
		void render(sf::RenderTarget& target);
};

