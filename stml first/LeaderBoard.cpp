#include "LeaderBoard.h"
void LeaderBoard::initBackground()
{
	if (!this->backgroundTex.loadFromFile("Textures/menu_bg.png"))
	{
		std::cout << "ERROR::GUN::INITTEXTURE::Could not load textures file." << "\n";
	}
	this->background.setTexture(this->backgroundTex);
	this->background.setScale(1.f, 1.f);
	this->background.setPosition(0, 0);
}

void LeaderBoard::initBackgroundGameOver()
{
	if (!this->backgroundGameOverTex.loadFromFile("Textures/map.png"))
	{
		std::cout << "ERROR::GUN::INITTEXTURE::Could not load textures file." << "\n";
	}
	this->backgroundGameOver.setTexture(this->backgroundGameOverTex);
	this->backgroundGameOver.setScale(3.f, 3.f);
	this->backgroundGameOver.setPosition(0, 0);
	this->backgroundGameOver.setColor(Color(255, 255, 255, 50));
}

void LeaderBoard::initText()
{

}

LeaderBoard::LeaderBoard(int x, int y, std::string word, Font* font)
{
	this->initBackgroundGameOver();
	this->initBackground();
	this->text.setFont(*font);
	this->text.setPosition(x, y);
	this->text.setString(word);
	this->text.setOutlineThickness(5);
	this->text.setCharacterSize(35);
}

LeaderBoard::~LeaderBoard()
{

}

void LeaderBoard::getSize()
{
	this->text.getGlobalBounds().width;
}

void LeaderBoard::setFontColor(Color color)
{
	this->text.setFillColor(color);
}

void LeaderBoard::setFontSize(int size)
{
	this->text.setCharacterSize(size);
}

void LeaderBoard::renderBackground(RenderTarget& target)
{
	target.draw(this->background);
}

void LeaderBoard::renderBackgroundGameOver(RenderTarget& target)
{
	target.draw(this->backgroundGameOver);
}

void LeaderBoard::render(RenderTarget& target)
{
	target.draw(this->text);
}