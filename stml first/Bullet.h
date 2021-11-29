#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Bullet
{
private:
	sf::Sprite shape;
	sf::Texture texture;
	float movementSpeed;
	int Dir;
	//Animation 
	
	
public:
	Bullet(float pos_x ,float pos_y ,float movement_speed, int PlayerGetDir);
	virtual ~Bullet();
	//Accessor
	const sf::FloatRect getBounds() const;
	void update();

	void render(sf::RenderTarget* target);
};

#endif //!BULLET_H