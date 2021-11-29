#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <map>
#include <string>
#include <sstream>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include "LeaderBoard.h"
class Game 
{
private:
	//variables
	//Window
	sf::RenderWindow* window;
	sf::Clock DelayStart;
	bool start = false;
	//Resource
	std::vector<Bullet*> bullets;
	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	//Base
	sf::Texture BaseBackgroundTex;
	sf::Sprite BaseBackground;
	//Bridge
	sf::Texture BridgeBackgroundTex;
	sf::Sprite BridgeBackground[4];
	//heart
	sf::Texture heartTex;
	sf::Sprite heart;
	//frame score
	sf::Texture frameTex;
	sf::Sprite frame;
	//GUI
		//Score
		sf::Font font;
		sf::Text pointText;
		//Score
		sf::Font esc;
		sf::Text escText;
		//Number
		sf::Font number;
		sf::Text numberText;
		//points system
		unsigned points;
	//hp window
	sf::Font hp;
	sf::Text hpText;
	int enemypass;
	
	//Player
	Player* player;
	int damage;
	//Menu
	Menu* menu;
	int Gamestate;
	//LeaderBoard
	sf::Text LeaderBoardTopic;
	LeaderBoard* rankName[6];
	LeaderBoard* rankScore[6];

	FILE* rankingFile;
	std::string name;
	sf::Font font2;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	float spawnTimerCyborg2;
	float spawnTimerCyborg2Max;
	float spawnTimerCyborg3;
	float spawnTimerCyborg3Max;
	float spawnTimerCyborg4;
	float spawnTimerCyborg4Max;
	float spawnTimerCyborg5;
	float spawnTimerCyborg5Max;
	float spawnTimerCyborg6;
	float spawnTimerCyborg6Max;
	std::vector<Enemy*> enemies;
	Enemy* type;
	//Enemy* enemy;
	int CyborgTYPE;

	//Cooldown
	float cooldown;
	float cooldownMax;
	////Ranking 
	//Ranking* topic;
	//Ranking* rankName[6];
	//Ranking* rankScore[6];
	//FILE* rankingFile;
	//TimeGame
	sf::Clock clock;
	float deltaTime;
	float enemyTime=0;
	int fakedeltatime;

	//NAME SATE
	sf::Text EnterNameText;
	std::string EnterNameS;
	sf::String Sendnametoscore;
	
	//Text
	void initWindow();
	void initGUI();
	void initGUINumber();
	void initGUIhp();
	void initEnterName();
	void initEsc();
	//TextureThing
	void initWorld(); 
	void initBase();
	void initBridge();
	void initheart();
	void initframe();
	///private functions
	void initDeleteGame();
	void initSystem();
	void initSystemhp();
	void initPlayer();
	void initEnemies();
	void initEnemiestwo();
	void initEnemiesthree();
	void initEnemiesfour();
	void initEnemiesfive();
	void initEnemiessix();
	//Ranking
	void initRanking();
	//Menu
	void initGamestate();
	void initAllgame();
	void initAlltexture();
	void initMenu();
	

public:
	//Constructors //Destructors
	Game();
	virtual ~Game();
	//Fructions
	void run();
	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateGUINumber();
	void updateGUIhp();
	void updateBullet();
	void updateEnemies();
	void updateCombat();
	void updateTime();
	void updateMainmenu();
	void updateGameover();
	void updateLeaderboard();
	void updateHowtoPlay();
		void update();	

	
	void renderGUI();
	void renderGUINumber();
	void renderGUIhp();
	void renderEsc();
	void renderWorld();
	void renderBridge();
	void renderBase();
	void renderheart();
	void renderframe();
	void renderMain();
	void renderGameover();
	void renderLeaderBoard();
	void renderHowtoplay();


	void render();
	
};



