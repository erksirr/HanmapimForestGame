#include "Game.h"
//private function
void Game::initGamestate()
{
	this->Gamestate = 0;
}
void Game::initWindow()
{
	this->DelayStart.restart();

	this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Hanmapim", sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initGUI()
{
	//Load font		
	if (!this->font.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(30);
	this->pointText.setFillColor(sf::Color(15, 207, 115, 255));
	this->pointText.setOutlineColor(sf::Color::Black);
	this->pointText.setOutlineThickness(2.f);
	this->pointText.setString("score");
	this->pointText.setPosition(225.f, 732.f);

}
void Game::initGUINumber()
{

	//Load font 
	if (!this->number.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->numberText.setFont(this->number);
	this->numberText.setCharacterSize(40);
	this->numberText.setFillColor(sf::Color(15, 207, 115, 255));
	this->numberText.setOutlineColor(sf::Color::Black);
	this->numberText.setOutlineThickness(2.f);
	//this->numberText.setString(": 0");
	this->numberText.setPosition(325.f, 725.f); //200.f, 95.f
}
void Game::initGUIhp()
{
	//Load font 
	if (!this->hp.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->hpText.setFont(this->hp);
	this->hpText.setCharacterSize(30);
	this->hpText.setFillColor(sf::Color(15, 207, 115, 255));
	this->hpText.setOutlineColor(sf::Color::Black);
	this->hpText.setOutlineThickness(2.f);
	//this->hpText.setString("9");
	this->hpText.setPosition(140.f, 732.f); //200.f, 95.f
}
void Game::initEnterName()
{
	this->EnterNameText.setOrigin(EnterNameText.getGlobalBounds().width / 2, EnterNameText.getGlobalBounds().height / 2);
	this->EnterNameText.setFillColor(sf::Color::White);
	this->EnterNameText.setFont(this->esc);
	this->EnterNameText.setCharacterSize(30);
	this->EnterNameText.setPosition(660.f, 435.f);
	this->EnterNameText.setOutlineColor(sf::Color::Black);
	this->EnterNameText.setOutlineThickness(2.f);
}
void Game::initEsc()
{
	if (!this->esc.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->escText.setFont(this->esc);
	this->escText.setCharacterSize(20);
	this->escText.setFillColor(sf::Color::White);
	this->escText.setOutlineColor(sf::Color::Black);
	this->escText.setOutlineThickness(2.f);
	this->escText.setString("**   Press ESC for exit to main menu   **");
	this->escText.setPosition(800.f, 750.f);

}
void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("png2/forest9.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
	this->worldBackground.scale(1.f, 1.1f);
}
void Game::initBase()
{
	if (!this->BaseBackgroundTex.loadFromFile("png2/base2.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->BaseBackground.setTexture(this->BaseBackgroundTex);
	this->BaseBackground.scale(0.5f, 0.5f);
	this->BaseBackground.setPosition(-110.f, 300.f);
}
void Game::initBridge()
{
	if (!this->BridgeBackgroundTex.loadFromFile("png2/bridge1.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	for (int i = 0; i < 4; i++)
	{
		this->BridgeBackground[i].setTexture(this->BridgeBackgroundTex);
		this->BridgeBackground[i].scale(0.5f, 0.4f);
		this->BridgeBackground[i].setRotation(90.f);
	}
	this->BridgeBackground[0].setPosition(750.f, -50.f);
	this->BridgeBackground[1].setPosition(750.f, 180.f);
	this->BridgeBackground[2].setPosition(750.f, 410.f);
	this->BridgeBackground[3].setPosition(750.f, 642.f);
}
void Game::initheart()
{
	if (!this->heartTex.loadFromFile("png2/heart2.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->heart.setTexture(this->heartTex);
	this->heart.scale(0.2f, 0.2f);
	this->heart.setPosition(90.f, 732.f);
}
void Game::initframe()
{
	if (!this->frameTex.loadFromFile("png2/frameremove.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->frame.setTexture(this->frameTex);
	this->frame.scale(1.7f, 0.7f);
	this->frame.setPosition(20.f, 700.f);

}
void Game::initDeleteGame()
{
	int n = this->enemies.size();
	for (int i = 0; i < n; i++)
	{
		delete this->enemies.at(0);
		this->enemies.erase(this->enemies.begin());
	}
	n = this->bullets.size();
	for (int i = 0; i < n; i++)
	{
		delete this->bullets.at(0);
		this->bullets.erase(this->bullets.begin());
	}
	this->enemyTime = 0;
}
void Game::initSystem()
{
	this->points = 0;
}
void Game::initSystemhp()
{
	this->enemypass = 20;
}
void Game::initPlayer()
{
	this->player = new Player();
	this->damage = 5;
}
void Game::initEnemies()
{
	this->spawnTimerMax = 3.f;
	this->spawnTimer = this->spawnTimerMax;
}
void Game::initEnemiestwo()
{
	this->spawnTimerCyborg2Max = 10.f;
	this->spawnTimerCyborg2 = this->spawnTimerCyborg2Max;
}
void Game::initEnemiesthree()
{
	this->spawnTimerCyborg3Max = 25.f;
	this->spawnTimerCyborg3 = this->spawnTimerCyborg3Max;
}
void Game::initEnemiesfour()
{
	this->spawnTimerCyborg4Max = 25.f;
	this->spawnTimerCyborg4 = this->spawnTimerCyborg4Max;
}
void Game::initEnemiesfive()
{
	this->spawnTimerCyborg5Max = 35.f;
	this->spawnTimerCyborg5 = this->spawnTimerCyborg5Max;
}
void Game::initEnemiessix()
{
	this->spawnTimerCyborg6Max = 20.f;
	this->spawnTimerCyborg6 = this->spawnTimerCyborg6Max;
}

void Game::initRanking()
{
	char tempRank[255];
	int scoreRank[6];
	std::string nameRank[6];
	std::vector <std::pair<int, std::string>> userScore;
	this->font2.loadFromFile("Font/theboldfont.ttf");

	this->LeaderBoardTopic.setFont(this->font2);
	this->LeaderBoardTopic.setString("Leader Board");
	this->LeaderBoardTopic.setCharacterSize(80);
	this->LeaderBoardTopic.setFillColor(sf::Color::Black);
	this->LeaderBoardTopic.setOutlineColor(sf::Color::White);
	this->LeaderBoardTopic.setOutlineThickness(5.f);
	this->LeaderBoardTopic.setPosition(sf::Vector2f(370.f,85.f));

	//Read
	this->rankingFile = fopen("./LeaderBoard.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(this->rankingFile, "%s", &tempRank);
		nameRank[i] = tempRank;
		fscanf(this->rankingFile, "%d", &scoreRank[i]);
		userScore.push_back(std::make_pair(scoreRank[i], nameRank[i]));
		//cout << temp << " " << score;
	}
	nameRank[5] = this->name;
	scoreRank[5] = this->points;
	userScore.push_back(std::make_pair(scoreRank[5], nameRank[5]));
	sort(userScore.begin(), userScore.end());
	fclose(this->rankingFile);


	//Write
	fopen("./LeaderBoard.txt", "w");
	for (int i = 5; i >= 1; i--)
	{
		strcpy(tempRank, userScore[i].second.c_str());
		std::cout << tempRank << std::endl;
		std::cout << userScore[i].first << std::endl;
		fprintf(this->rankingFile, "%s %d\n", tempRank, userScore[i].first);
	}
	fclose(this->rankingFile);

	int posRankingNameX = 350;
	int posRankingScoreX = 850;
	int PosRankingY = 700;



	for (int i = 1; i <= 5; i++)
	{

		this->rankName[i] = new LeaderBoard(posRankingNameX, PosRankingY - (i * 80), userScore[i].second, &this->font2);
		this->rankScore[i] = new LeaderBoard(posRankingScoreX, PosRankingY - (i * 80), std::to_string(userScore[i].first), &this->font2);
		/*if (i == 5)
		{
			this->rankName[i]->setFontSize(50);
			this->rankScore[i]->setFontColor(Color::Red);
			
		}*/
	}

}

void Game::initAllgame()
{
	this->initPlayer();
	this->initGUI();
	this->initGUINumber();
	this->initGUIhp();
	this->initEsc();
	this->initEnterName();
	this->initSystem();
	this->initSystemhp();
	this->initEnemies();
	this->initEnemiestwo();
	this->initEnemiesthree();
	this->initEnemiesfour();
	this->initEnemiesfive();
	this->initEnemiessix();

}
void Game::initAlltexture()
{
	this->initWorld();
	this->initBase();
	this->initBridge();
	this->initheart();
	this->initframe();
}
void Game::initMenu()
{
	this->menu = new Menu(1200.f, 800.f);
}
//Constructors /Des
Game::Game()
{
	this->initGamestate();
	this->initRanking();
	this->initMenu();
	this->initWindow();
	this->initAlltexture();
	this->initEsc();
	this->initEnterName();
	//this->initDelay();

}
Game::~Game()
{
	delete this->window;
	delete this->player;
	//Delete Bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
	//Delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}
}
//Function
void Game::run()
{
	while (this->window->isOpen())
	{
		this->deltaTime = this->clock.restart().asSeconds();
		this->EnterNameText.setString(this->EnterNameS);
		if (this->Gamestate==0)
		{
			this->EnterNameS = '  ';
			this->renderMain();
			this->updateMainmenu();
		}
		else if (this->Gamestate == 1)
		{
			this->updatePollEvents();
			if (this->enemypass > 0)
			{
				this->update();
				this->render();
			}	
			else if (this->enemypass <= 0)
			{
			
				this->updateGameover();

				this->renderGameover();
				
			}
		}
		else if (this->Gamestate == 2)
		{
			this->renderLeaderBoard();
			//this->renderRanking();
			this->updateLeaderboard();
		}
		else if (this->Gamestate == 3)
		{
			this->updateHowtoPlay();
			this->renderHowtoplay();
		}
		
	}
}
void Game::updatePollEvents()
{
	
	sf::Event event;
	while (this->window->pollEvent(event))
	{
			if (event.Event::type == sf::Event::Closed)
				this->window->close();
			if (this->enemypass<=0)
			{
				if (event.type == sf::Event::TextEntered && event.text.unicode < 128)
				{
					if (event.text.unicode == 8) //delete button
					{
						if (this->EnterNameS.length())
						{
							EnterNameS.pop_back();
						}
					}
					else if (event.text.unicode != 13) //Enter button
					{
						EnterNameS += (char)event.text.unicode;
					}
					EnterNameText.setString(EnterNameS);
					std::cout << EnterNameText.getString().toAnsiString() <<std:: endl;
				}
			}
			
		
	}
}

void Game::updateInput()
{
	//player shoot
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(
			this->player->getPos().x + this->player->getBounds().width / 2.f,
			this->player->getPos().y + 20,
			5.f,
			this->player->GetDir()));
		this->player->updateAnimationsShooting(true);
	}
}
void Game::updateGUI()
{
}

void Game::updateGUINumber()
{
	std::stringstream ss;
	ss << ": " << this->points;
	this->numberText.setString(ss.str());
}
void Game::updateGUIhp()
{
	std::stringstream sr;
	sr << "x " << this->enemypass;
	this->hpText.setString(sr.str());
}
void Game::updateBullet()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		//Bullet culling (top of screen)
		if (bullet->getBounds().left + bullet->getBounds().width > 1200.f)
		{
			//Delete Bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			//std::cout << this->bullets.size() << "\n";
			break;
		}
		else if (bullet->getBounds().left + bullet->getBounds().width < 0.f)
		{
			//Delete Bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			//std::cout << this->bullets.size() << "\n";
			break;
		}
		else if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete Bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			//std::cout << this->bullets.size() << "\n";
			break;
		}
		else if (bullet->getBounds().top + bullet->getBounds().width > 800.f)
		{
			//Delete Bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			//std::cout << this->bullets.size() << "\n";
			break;
		}
		++counter;
	}
}
void Game::updateEnemies()
{
	//Update
	//unsigned counter = 0;
	//for (auto* enemy : this->enemies)
	for(int counter=0;counter<enemies.size();counter++)
	{
		enemies[counter]->update();

		if (enemies[counter]->getBounds().left > this->window->getSize().x)
		{
			this->enemypass -= enemies[counter]->getLimitdie();
			delete this->enemies[counter];
			this->enemies.erase(this->enemies.begin() + counter);
			continue;
			
		}
		//counter++;

	}

}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		for (size_t k = 0; k < this->bullets.size() ; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->enemies[i]->loseHP(this->damage);
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
				if (this->enemies[i]->getHP() <= 0)
				{
					this->points += this->enemies[i]->getPoint();
					if (this->enemies[i]->getType() == 3)
					{
						this->enemypass += 2;
					}
					if (this->enemies[i]->getType() == 4)
					{
						this->player->updateChangeAttack(15,360);
					}
					if (this->enemies[i]->getType() == 5)
					{
						this->enemypass += 4;
					}
					if (this->enemies[i]->getType() == 6)
					{
						this->player->updateChangeAttack(7, 360);
					}
					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);
					break;
				}

			}
		}
	}
}
void Game::updateTime()
{
	this->enemyTime += this->deltaTime;
	std::cout<<this->enemyTime<<std::endl;
	/*std::cout << mousePos.x << " , " << mousePos.y << std::endl;*/
	if (this->enemyTime >= 5.f)
	{
		this->spawnTimer += this->deltaTime;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 1, enemyTime));
			this->spawnTimer = 0.f;
			if (this->enemyTime >= 200.f)
			{
				this->spawnTimerMax = 5.f;
			}
			if (this->enemyTime >= 110.f)
			{
				this->spawnTimerMax = 6.f;
			}
			if (this->enemyTime >= 200.f)
			{
				this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 1, enemyTime));
			}
			if (this->enemyTime >= 250.f)
			{
				this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 1, enemyTime));
			}
		}
	}
	if (this->enemyTime >= 25.f)
	{
		this->spawnTimerCyborg2 += this->deltaTime;
		if (this->spawnTimerCyborg2 >= this->spawnTimerCyborg2Max)
		{
			this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 2, enemyTime));
			this->spawnTimerCyborg2 = 0.f;
			if (this->enemyTime >= 100.f)
			{
				this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 2, enemyTime));
			}
			if (this->enemyTime >= 200.f )
			{
				this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 1, enemyTime));
			}

		}
	}
	if (this->enemyTime >= 50.f)
	{
		this->spawnTimerCyborg3 += this->deltaTime;
		if (this->spawnTimerCyborg3 >= this->spawnTimerCyborg3Max)
		{
			this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 3, enemyTime));
			this->spawnTimerCyborg3 = 0.f;
			if (this->enemyTime >= 190.f)
			{
				this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 3, enemyTime));
			}
			if (this->enemyTime >= 270.f)
			{
				this->enemies.push_back(new Enemy(130.f, rand() % 200 + 286, 3, enemyTime));
			}
		}

	}
	//Item
	if (this->enemyTime >= 60.f)
	{
		this->spawnTimerCyborg4 += this->deltaTime;
		if (this->spawnTimerCyborg4 >= this->spawnTimerCyborg4Max)
		{
			this->enemies.push_back(new Enemy(rand()%36+631, rand() %725, 4, 0));
			this->spawnTimerCyborg4 = 0.f;
		}
		
	}
	if (this->enemyTime >= 90.f)
	{
		this->spawnTimerCyborg5 += this->deltaTime;
		if (this->spawnTimerCyborg5 >= this->spawnTimerCyborg5Max)
		{
			this->enemies.push_back(new Enemy(rand() % 36 + 631, rand() % 725, 5, 0));
			this->spawnTimerCyborg5 = 0.f;
		}

	}
	if (this->enemyTime >= 150.f)
	{
		this->spawnTimerCyborg6 += this->deltaTime;
		if (this->spawnTimerCyborg6 >= this->spawnTimerCyborg6Max)
		{
			this->enemies.push_back(new Enemy(rand() % 36 + 631, rand() % 725, 6, 0));
			this->spawnTimerCyborg6 = 0.f;
			if (this->enemyTime > 170.f)
			{
				this->spawnTimerCyborg6Max = 15.f;
			}
		
		}

	}
}


void Game::updateMainmenu()
{

	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (mousePos.x > 430.f && mousePos.x < 765.f &&
		mousePos.y>489.f && mousePos.y < 518.f)
	{
		//this->menu->renderbuttonMainShiny(*this->window);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			this->Gamestate = 1;
			this->initAllgame();
			this->enemyTime = 0;

		}
	}
	if (mousePos.x > 158.f && mousePos.x < 585.f &&
		mousePos.y>567.f && mousePos.y < 656.f)
	{

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->Gamestate = 2;
			std::cout << this->Gamestate << std::endl;
		}
	}

	if (mousePos.x > 698.f && mousePos.x < 925.f &&
		mousePos.y>567.f && mousePos.y < 659.f)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->window->close();
		}
	}
	if (mousePos.x > 957.f && mousePos.x < 1030.f &&
		mousePos.y>600.f && mousePos.y < 652.f)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->Gamestate = 3;
		}
	}
}

void Game::updateGameover()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (/*mousePos.x > 521.f && mousePos.x < 715.f &&
		mousePos.y>411.f && mousePos.y < 487.f*/sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			this->name = this->EnterNameText.getString().toAnsiString();
			this->initRanking();
			this->Gamestate = 0;
			this->initDeleteGame();
			//std::cout << this->Gamestate << std::endl;'
			std::cout << this->name << std::endl;
		}
	}
}
void Game::updateLeaderboard()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (mousePos.x > 35.f && mousePos.x < 145.f &&
		mousePos.y>645.f && mousePos.y < 749.f)
	
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->Gamestate = 0;
			this->initDeleteGame();
			std::cout << this->Gamestate << std::endl;

		}
	}
}
void Game::updateHowtoPlay()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (mousePos.x > 35.f && mousePos.x < 145.f &&
		mousePos.y>645.f && mousePos.y < 749.f)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->Gamestate = 0;
			this->initDeleteGame();
			std::cout << this->Gamestate << std::endl;

		}
	}
}
void Game::update()
{
	
		this->updateTime();
		this->updateInput();
		this->player->update();
		this->updateBullet();
		this->updateEnemies();
		this->updateCombat();
		this->updateGUI();
		this->updateGUINumber();
		this->updateGUIhp();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->Gamestate = 0;
			this->initDeleteGame();
			std::cout << this->Gamestate << std::endl;
		}
}



void Game::renderGUI()
{
	this->window->draw(this->pointText);
}
void Game::renderGUINumber()
{
	this->window->draw(this->numberText);
}
void Game::renderGUIhp()
{
	this->window->draw(this->hpText);
}
void Game::renderEsc()
{
	this->window->draw(this->escText);
}
void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}
void Game::renderBridge()
{
	for (int i = 0; i < 4; i++)
	{
		this->window->draw(this->BridgeBackground[i]);
	}
}
void Game::renderBase()
{
	this->window->draw(this->BaseBackground);
}
void Game::renderheart()
{
	this->window->draw(this->heart);
}
void Game::renderframe()
{
	this->window->draw(this->frame);
}
void Game::renderMain()
{
	this->window->clear();
	this->menu->renderMainBackground(*this->window);
	this->menu->renderbuttonMain(*this->window);
	this->menu->renderName(*this->window);
	this->menu->renderMyname(*this->window);
	this->menu->renderbuttonMainExit(*this->window);
	this->menu->renderbuttonMainLeaderBoard(*this->window);
	this->menu->renderClickstart2(*this->window);
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (mousePos.x > 430.f && mousePos.x < 765.f &&
		mousePos.y>489.f && mousePos.y < 518.f)
	{
		this->menu->renderClickstart(*this->window);
	}
	if (mousePos.x > 158.f && mousePos.x < 585.f &&
		mousePos.y>567.f && mousePos.y < 656.f)
	{
		this->menu->renderbuttonMainShinyLeaderBoard(*this->window);
	}
	if (mousePos.x > 698.f && mousePos.x < 925.f &&
		mousePos.y>567.f && mousePos.y < 659.f)
	{
		this->menu->renderbuttonMainExitShiny(*this->window);
	}
	if (mousePos.x > 957.f && mousePos.x < 1030.f &&
		mousePos.y>600.f && mousePos.y < 652.f)
	{
		this->menu->renderbuttonMainShiny(*this->window);
	}
	//this->menu->renderbuttonMain(*this->window);
	this->menu->draw(*this->window);	
	this->menu->renderinfo(*this->window);
	this->window->display();

	//std::cout << mousePos.x << " , " << mousePos.y << std::endl;
}

void Game::render()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	//std::cout << mousePos.x << " , " << mousePos.y << std::endl;
	this->window->clear();
		//Draw world
		this->renderWorld();
		//Draw Base
		this->renderBase();

		//Draw enemy
		for (auto* enemy : this->enemies)
		{
			if (enemy->getType() <= 3)
			{
				enemy->render(this->window);
			}
		}
		//Draw Bridge
		this->renderBridge();
		//Draw bullet
		for (auto* bullet : this->bullets)
		{
			bullet->render(this->window);
		}
		for (auto* enemy : this->enemies)
		{
			if (enemy->getType() > 3)
			{
				enemy->render(this->window);
			}
		}
		this->player->render(*this->window);

		this->renderframe();

		this->renderGUI();

		this->renderGUINumber();

		this->renderEsc();

		this->renderheart();

		this->renderGUIhp();

		this->menu->renderOrder(*this->window);

		
		this->window->display();
		this->window->draw(this->EnterNameText);
}



void Game::renderGameover()
{
	//GAMEOVER
	this->window->clear();
	this->menu->renderGameoverBackground(*this->window);
	//this->menu->renderAnimal(*this->window);
	//this->menu->renderAnimal2(*this->window);
	this->menu->renderGameovertext(*this->window);
	this->menu->renderbuttonMainmenu(*this->window);
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (/*mousePos.x > 521.f && mousePos.x < 715.f &&
		mousePos.y>411.f && mousePos.y < 487.f*/sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		//this->menu->renderbuttonMainmenuShiny(*this->window);
		
	}
	this->menu->renderMainmenuText(*this->window);
	this->window->draw(this->EnterNameText);
	this->menu->renderEnter(*this->window);
	//std::cout << mousePos.x << " , " << mousePos.y << std::endl;
	
	this->window->display();

}

void Game::renderLeaderBoard()
{
	this->window->clear();
	this->menu->renderLeaderBoardBackground(*this->window);
	this->menu->renderbuttonArrowReverse(*this->window);
	this->menu->renderRecWhite(*this->window);
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (mousePos.x > 35.f && mousePos.x < 145.f &&
		mousePos.y>645.f && mousePos.y < 749.f)
	{
		this->menu->renderbuttonArrowReverseShiny(*this->window);
		
	}
	this->menu->renderArrowReverse(*this->window);
	this->window->draw(this->LeaderBoardTopic);
	for (int i = 1; i <= 5; i++) {
		this->rankScore[i]->render(*this->window);
		this->rankName[i]->render(*this->window);
	}
	//this->topic->render(*this->window);
	this->window->display();
	//std::cout << mousePos.x << " , " << mousePos.y << std::endl;
}
void Game::renderHowtoplay()
{
	this->window->clear();
	this->menu->renderHowtoplay(*this->window);
	this->menu->renderbuttonArrowReverse(*this->window);
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (mousePos.x > 35.f && mousePos.x < 145.f &&
		mousePos.y>645.f && mousePos.y < 749.f)
	{
		this->menu->renderbuttonArrowReverseShiny(*this->window);

	}
	this->menu->renderArrowReverse(*this->window);
	this->window->display();
}



