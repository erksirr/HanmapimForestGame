#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <string>
#define MAX_ITEMS 3
#pragma once
class Menu
{
private:
	int Gamestate;
	int selectedItem = 0;
	//MAIN BACKGOUND
		sf::Texture MainBackgroundtexture;
		sf::Sprite MainBackground;
		//GAME NAME
		sf::Text NameText;
		sf::Font Name;
		sf::Texture NameTexture;
		sf::Sprite NameGame;
		//My NAME
		sf::Text MyNameText;
		sf::Font MyName;
		
		//Order
		sf::Text DontMoveSreenText;
		sf::Font DontMoveSreen;
		//FONT MENU
		sf::Font MainFont;
		sf::Text MainText[MAX_ITEMS];//START LEADERBOARD EXIT
		sf::Font MainFont2;
		sf::Text MainText2[2];
		//BUTTON MainPlay
		sf::Texture buttonMainText;
		sf::Sprite buttonMain;
		//BUTTON MainPlay Shiny
		sf::Texture buttonMainShinyText;
		sf::Sprite buttonMainShiny;
		//BUTTON MainLeaderBoard
		sf::Texture buttonMainLeaderBoardText;
		sf::Sprite buttonMainLeaderBoard;
		//BUTTON MainLeaderBoardShiny
		sf::Texture buttonMainLeaderBoardShinyText;
		sf::Sprite buttonMainLeaderBoardShiny;
		//BUTTON MainExit
		sf::Texture buttonMainExitText;
		sf::Sprite buttonMainExit;
		//BUTTON MainExit Shiny
		sf::Texture buttonMainExitShinyText;
		sf::Sprite buttonMainExitShiny;
		//
		sf::Texture infoText;
		sf::Sprite info;
	//GAMEOVER BACKGROUND
		sf::Texture GameoverBackgroundtexture;
		sf::Sprite GameoverBackground;
		//FONT GAMEOVER
		sf::Font gameover;
		sf::Text gameoverText;
		//BUTTON MAINMENU
		sf::Texture buttonMainmenuTex;
		sf::Sprite buttonMainMenu;
		//BUTTON SHINY MAINMENU
		sf::Texture buttonMainmenuShinyTex;
		sf::Sprite buttonMainmenuShiny;
		//MAINMENUTEXT
		sf::Font Mainmenu;
		sf::Text MainmenuText;
		//AnimalSad
		sf::Texture AnimalTex;
		sf::Sprite Animal;
		sf::Texture Animal2Tex;
		sf::Sprite Animal2;
		sf::Texture Animal3Tex;
		sf::Sprite Animal3;
	//LEADERBOARD BACKGROUND
		sf::Texture  LeaderBoardBackgroundtexture;
		sf::Sprite LeaderBoardBackground;
		//ARROWREVERSE
		sf::Texture ArrowReversetexture;
		sf::Sprite ArrowReverse;
		//BUTTON ARROWREVERSE
		sf::Texture buttonArrowReverseTex;
		sf::Sprite buttonArrowReverse;
		//BUTTON ARROWREVERSESHINY
		sf::Texture buttonArrowReverseShinyTex;
		sf::Sprite buttonArrowReverseShiny;
		//Rectangle
		sf::RectangleShape whiteboard;
	//HOWTOPLAY
		sf::Texture HowtoplayTexture;
		sf::Sprite Howtoplay;
		sf::Text Enter;

	//GAMEOVER BACKGROUND FUNCTION
	void initGameoverBackground();
	void initGameovertext();
	void initbuttonMainMenu();
	void initbuttonMainMenuShiny();
	void initMainmenuText();
	void initAnimal();

	//MAINMENU	
	void initName();
	void initMyname();
	void initDontMoveSreen();
	void initMainBackground();
	void initbuttonPlay();
	void initNameword();
	void initinfo();
	
	//LEADERBOARD
	void initLeaderBackground();
	void initArrowReverse();
	void initButtonArrowReverse();
	void initwhiteboard();
	
	//HOWTOPLAY
	void initHowtoPlay();
	void initEnter();

public:
	Menu(float width, float height);
	virtual ~Menu();
	void draw(sf::RenderWindow& window);
	//MAINMENU
	void renderName(sf::RenderTarget& targetName);
	void renderMyname(sf::RenderTarget& targetMyName);
	void renderOrder(sf::RenderTarget& targetOrder);
	void renderMainBackground(sf::RenderTarget& targetMain);
	void renderClickstart(sf::RenderTarget& targetclickstart);
	void renderClickstart2(sf::RenderTarget& targetclickstart2);
	void renderbuttonMain(sf::RenderTarget& targetbuttonMain);
	void renderbuttonMainShiny(sf::RenderTarget& targetbuttonMainShiny);
	void renderbuttonMainLeaderBoard(sf::RenderTarget& targetbuttonMainLeaderBoard);
	void renderbuttonMainShinyLeaderBoard(sf::RenderTarget& targetbuttonMainLeaderBoardShiny);
	void renderbuttonMainExit(sf::RenderTarget& targetbuttonMainExit);
	void renderbuttonMainExitShiny(sf::RenderTarget& targetbuttonMainExitShiny);
	void renderinfo(sf::RenderTarget& targetinfo);

	//GAMEOVER
	void renderGameoverBackground(sf::RenderTarget& targetGameover);
	void renderGameovertext(sf::RenderTarget& targettwoGameover);
	void renderbuttonMainmenu(sf::RenderTarget& targetthreeGameover);
	void renderMainmenuText(sf::RenderTarget& targetfourGameover);
	void renderbuttonMainmenuShiny(sf::RenderTarget& targetfiveGameover);
	void renderAnimal(sf::RenderTarget& targetAnimal);
	void renderAnimal2(sf::RenderTarget& targetAnimal2);

	//LEADERBOARD
	void renderLeaderBoardBackground(sf::RenderTarget& targetLeaderBoard);
	void renderArrowReverse(sf::RenderTarget& targetArrowReverse);
	void renderbuttonArrowReverse(sf::RenderTarget& targetbuttonArrowReverse);
	void renderbuttonArrowReverseShiny(sf::RenderTarget& targetbuttonArrowReverseShiny);
	void renderRecWhite(sf::RenderTarget& targetShape);

	//HOWTOPLAY
	void renderHowtoplay(sf::RenderTarget& targetHow);
	void renderEnter(sf::RenderTarget& targetEnter);
	//void 
};

