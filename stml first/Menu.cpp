#include "Menu.h"

void Menu::initGameoverBackground()
{
	if (!this->GameoverBackgroundtexture.loadFromFile("png2/forestMain6.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->GameoverBackground.setTexture(this->GameoverBackgroundtexture);
	this->GameoverBackground.setScale(1.6f, 1.6f);
}
void Menu::initGameovertext()
{
	//Load font 
	if (!this->gameover.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->gameoverText.setFont(this->gameover);
	this->gameoverText.setCharacterSize(100);
	this->gameoverText.setFillColor(sf::Color::Black/*(15, 207, 115, 255)*/);
	this->gameoverText.setOutlineColor(sf::Color::White);
	this->gameoverText.setOutlineThickness(7.f);
	this->gameoverText.setString("GAMEOVER");
	this->gameoverText.setPosition(360.f,285.f);
}
void Menu::initbuttonMainMenu()
{
	if (!this->buttonMainmenuTex.loadFromFile("png2/button.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMainMenu.setTexture(this->buttonMainmenuTex);
	this->buttonMainMenu.setScale(0.4f, 0.45f);
	this->buttonMainMenu.setPosition(500.f, 417.f);
}
void Menu::initbuttonMainMenuShiny()
{
	if (!this->buttonMainmenuShinyTex.loadFromFile("png2/buttonshiny.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMainmenuShiny.setTexture(this->buttonMainmenuShinyTex);
	this->buttonMainmenuShiny.setScale(0.5f, 0.5f);
	this->buttonMainmenuShiny.setPosition(500.f, 330.f);
}
void Menu::initMainmenuText()
{
	//Load font 
	if (!this->Mainmenu.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->MainmenuText.setFont(this->Mainmenu);
	this->MainmenuText.setCharacterSize(30);
	this->MainmenuText.setFillColor(sf::Color::Black);
	this->MainmenuText.setOutlineColor(sf::Color::White);
	this->MainmenuText.setOutlineThickness(2.f);
	this->MainmenuText.setString("Enter your name   :");
	this->MainmenuText.setPosition(370.f, 435.f);
}

void Menu::initAnimal()
{
	if (!this->AnimalTex.loadFromFile("png2/tigersad.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->Animal.setTexture(this->AnimalTex);
	this->Animal.setScale(0.4f, 0.4f);
	this->Animal.setPosition(250.f, 380.f);

	if (!this->Animal2Tex.loadFromFile("png2/monkeysad.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->Animal2.setTexture(this->Animal2Tex);
	this->Animal2.setScale(0.5f, 0.5f);
	this->Animal2.setPosition(880.f, 285.f);
}



void Menu::initName()
{
	if (!this->Name.loadFromFile("Font/theboldfont.ttf"))//AdventureLandDemoRegular
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->NameText.setFont(this->Name);
	this->NameText.setCharacterSize(100);
	this->NameText.setFillColor(sf::Color::White/*(1, 145, 42,255 )*/);//81 159 103 //1, 145, 42,//53 157 82//23 171 65
	this->NameText.setOutlineColor(sf::Color::Black);
	this->NameText.setOutlineThickness(7.f);
	this->NameText.setString("HANMAPIM FOREST");
	this->NameText.setPosition(180.f, 100.f);
}

void Menu::initMyname()
{
	if (!this->MyName.loadFromFile("Font/theboldfont.ttf"))//AdventureLandDemoRegular
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->MyNameText.setFont(this->MyName);
	this->MyNameText.setCharacterSize(30);
	this->MyNameText.setFillColor(sf::Color::Yellow);//81 159 103 //1, 145, 42,//53 157 82//23 171 65
	this->MyNameText.setOutlineColor(sf::Color::Black);
	this->MyNameText.setOutlineThickness(5.f);
	this->MyNameText.setString("Siraphop    Sangmee    64010893");
	this->MyNameText.setPosition(680.f, 750.f);
}

void Menu::initDontMoveSreen()
{
	if (!this->DontMoveSreen.loadFromFile("Font/theboldfont.ttf"))//AdventureLandDemoRegular
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->DontMoveSreenText.setFont(this->DontMoveSreen);
	this->DontMoveSreenText.setCharacterSize(30);
	this->DontMoveSreenText.setFillColor(sf::Color::Red);//81 159 103 //1, 145, 42,//53 157 82//23 171 65
	this->DontMoveSreenText.setOutlineColor(sf::Color::Black);
	this->DontMoveSreenText.setOutlineThickness(7.f);
	this->DontMoveSreenText.setString("*   Dont let them pass!   ");
	this->DontMoveSreenText.setPosition(850.f,600.f);
}

void Menu::initMainBackground()
{
	if (!this->MainBackgroundtexture.loadFromFile("png2/forestMain7.png"))
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	
	this->MainBackground.setTexture(this->MainBackgroundtexture);
	this->MainBackground.setScale(2.f,2.f);
}

void Menu::initbuttonPlay()
{
	if (!this->buttonMainText.loadFromFile("png2/button.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMain.setTexture(this->buttonMainText);	
	this->buttonMain.scale(0.2f,0.4f);
	this->buttonMain.setPosition(945.f,532.f);

	if (!this->buttonMainShinyText.loadFromFile("png2/buttonshiny.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMainShiny.setTexture(this->buttonMainShinyText);
	this->buttonMainShiny.scale(0.2f, 0.4f);
	this->buttonMainShiny.setPosition(945.f, 532.f);
	
	if (!this->buttonMainLeaderBoardText.loadFromFile("png2/button.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMainLeaderBoard.setTexture(this->buttonMainLeaderBoardText);
	this->buttonMainLeaderBoard.scale(1.1f, 0.6f);
	this->buttonMainLeaderBoard.setPosition(110.f, 470.f);

	if (!this->buttonMainLeaderBoardShinyText.loadFromFile("png2/buttonshiny.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMainLeaderBoardShiny.setTexture(this->buttonMainLeaderBoardShinyText);
	this->buttonMainLeaderBoardShiny.scale(1.1f, 0.6f);
	this->buttonMainLeaderBoardShiny.setPosition(110.f, 470.f);

	if (!this->buttonMainExitText.loadFromFile("png2/button.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMainExit.setTexture(this->buttonMainExitText);
	this->buttonMainExit.scale(0.6f, 0.6f);
	this->buttonMainExit.setPosition(670.f, 470.f);

	if (!this->buttonMainExitShinyText.loadFromFile("png2/buttonshiny.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonMainExitShiny.setTexture(this->buttonMainExitShinyText);
	this->buttonMainExitShiny.scale(0.6f, 0.6f);
	this->buttonMainExitShiny.setPosition(670.f,470.f);

}

void Menu::initNameword()
{
	if (!this->NameTexture.loadFromFile("png2/Nameforest.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->NameGame.setTexture(this->NameTexture);
	this->NameGame.setScale(0.21f, 0.21f);
	this->NameGame.setPosition(200.f, 30.f);
}

void Menu::initinfo()
{
	if (!this->infoText.loadFromFile("png2/info.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->info.setTexture(this->infoText);
	this->info.setScale(0.17f, 0.17f);
	this->info.setPosition(974.5f,608.5f);
}

void Menu::initLeaderBackground()
{
	if (!this->LeaderBoardBackgroundtexture.loadFromFile("png2/forestMain6.png"))
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";

	this->LeaderBoardBackground.setTexture(this->LeaderBoardBackgroundtexture);
	this->LeaderBoardBackground.setScale(1.6f, 1.6f);
}

void Menu::initArrowReverse()
{
	if (!this->ArrowReversetexture.loadFromFile("png2/arrowreverseremove.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->ArrowReverse.setTexture(this->ArrowReversetexture);
	this->ArrowReverse.setScale(0.3f, 0.3f);
	this->ArrowReverse.setPosition(56.f, 660.f);

}

void Menu::initButtonArrowReverse()
{
	if (!this->buttonArrowReverseTex.loadFromFile("png2/button.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonArrowReverse.setTexture(this->buttonArrowReverseTex);
	this->buttonArrowReverse.setScale(0.3f,0.7f);
	this->buttonArrowReverse.setPosition(20.f, 530.f);

	if (!this->buttonArrowReverseShinyTex.loadFromFile("png2/buttonshiny.png"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->buttonArrowReverseShiny.setTexture(this->buttonArrowReverseShinyTex);
	this->buttonArrowReverseShiny.setScale(0.3f, 0.7f);
	this->buttonArrowReverseShiny.setPosition(20.f, 530.f);
}

void Menu::initwhiteboard()
{
	this->whiteboard.setSize(sf::Vector2f(700.f,450.f));
	this->whiteboard.setFillColor(sf::Color(255, 255, 255, 150));
	this->whiteboard.setOutlineColor(sf::Color::Black);
	this->whiteboard.setOutlineThickness(20.f);
	this->whiteboard.setPosition(275.f, 250.f);
}

void Menu::initHowtoPlay()
{
	if (!this->HowtoplayTexture.loadFromFile("png2/Howtoplay.jpg"))
	{
		std::cout << "ERROR::GAME::COULDNOT LOAD BLACKGROUND TEXTURE" << "\n";
	}
	this->Howtoplay.setTexture(this->HowtoplayTexture);
	this->Howtoplay.setScale(0.5f, 0.5f);
	this->Howtoplay.setPosition(0.f,0.f);
}

void Menu::initEnter()
{
	if (!this->gameover.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text 
	this->Enter.setFont(this->gameover);
	this->Enter.setCharacterSize(20);
	this->Enter.setFillColor(sf::Color::Black/*(15, 207, 115, 255)*/);
	this->Enter.setOutlineColor(sf::Color::White);
	this->Enter.setOutlineThickness(2.f);
	this->Enter.setString("Press enter");
	this->Enter.setPosition(535.f, 510.f);
}



Menu::Menu(float width, float height)
{
	this->initbuttonPlay();
	this->initMainBackground();
	this->initGameoverBackground();
	this->initGameovertext();
	this->initbuttonMainMenu();
	this->initbuttonMainMenuShiny();
	this->initMainmenuText();
	this->initArrowReverse();
	this->initButtonArrowReverse();
	this->initLeaderBackground();
	this->initName();
	this->initDontMoveSreen();
	this->initMyname();
	this->initAnimal();
	this->initNameword();
	this->initwhiteboard();
	this->initinfo();
	this->initHowtoPlay();
	this->initEnter();
	if (!MainFont.loadFromFile("Font/theboldfont.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	if (!MainFont2.loadFromFile("Font/theboldfont.ttf"))//AdventureLandDemoRegular
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	this->MainText2[0].setFont(this->MainFont2);
	this->MainText2[0].setCharacterSize(35);
	this->MainText2[0].setFillColor(sf::Color::Black);
	this->MainText2[0].setOutlineColor(sf::Color::White);
	this->MainText2[0].setOutlineThickness(2.f);
	this->MainText2[0].setString("Click here to start");
	this->MainText2[0].setOrigin(MainText2[0].getLocalBounds().width / 2, MainText2[0].getLocalBounds().height / 2);
	this->MainText2[0].setPosition(sf::Vector2f(width/2,height/(MAX_ITEMS+1)*2.5));

	this->MainText2[1].setFont(this->MainFont2);
	this->MainText2[1].setCharacterSize(35);
	this->MainText2[1].setFillColor(sf::Color::White);
	this->MainText2[1].setOutlineColor(sf::Color::Black);
	this->MainText2[1].setOutlineThickness(2.f);
	this->MainText2[1].setString("Click here to start");
	this->MainText2[1].setOrigin(MainText2[0].getLocalBounds().width / 2, MainText2[0].getLocalBounds().height / 2);
	this->MainText2[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2.5));

	this->MainText[0].setFont(this->MainFont);
	this->MainText[0].setCharacterSize(50);
	this->MainText[0].setFillColor(sf::Color::Black);
	this->MainText[0].setOutlineColor(sf::Color::White);
	this->MainText[0].setOutlineThickness(2.f);
	this->MainText[0].setString("leaderboard");
	this->MainText[0].setOrigin(MainText[0].getLocalBounds().width / 2, MainText[0].getLocalBounds().height / 2);
	this->MainText[0].setPosition(sf::Vector2f(width /3.2, height / (MAX_ITEMS + 1) * 3));

	this->MainText[1].setFont(this->MainFont);
	this->MainText[1].setCharacterSize(50);
	this->MainText[1].setFillColor(sf::Color::Black);
	this->MainText[1].setOutlineColor(sf::Color::White);
	this->MainText[1].setOutlineThickness(2.f);
	this->MainText[1].setString("exit");
	this->MainText[1].setOrigin(MainText[1].getLocalBounds().width / 2, MainText[1].getLocalBounds().height / 2);
	this->MainText[1].setPosition(sf::Vector2f(width /1.47, height / (MAX_ITEMS + 1) * 3));
	
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(this->MainText[i]);
	}

	
}
void Menu::renderName(sf::RenderTarget& targetName)
{
	targetName.draw(this->NameGame);
}
void Menu::renderMyname(sf::RenderTarget& targetMyName)
{
	targetMyName.draw(this->MyNameText);
}
void Menu::renderOrder(sf::RenderTarget& targetOrder)
{
	targetOrder.draw(this->DontMoveSreenText);
}
void Menu::renderMainBackground(sf::RenderTarget& targetMain)
{
	targetMain.draw(this->MainBackground);
}

void Menu::renderClickstart(sf::RenderTarget& targetclickstart)
{
	targetclickstart.draw(this->MainText2[1]);
}

void Menu::renderClickstart2(sf::RenderTarget& targetclickstart2)
{
	targetclickstart2.draw(this->MainText2[0]);
}

void Menu::renderbuttonMain(sf::RenderTarget& targetbuttonMain)
{
	targetbuttonMain.draw(this->buttonMain);
}

void Menu::renderbuttonMainShiny(sf::RenderTarget& targetbuttonMainShiny)
{
	targetbuttonMainShiny.draw(this->buttonMainShiny);
}

void Menu::renderbuttonMainLeaderBoard(sf::RenderTarget& targetbuttonMainLeaderBoard)
{
	targetbuttonMainLeaderBoard.draw(this->buttonMainLeaderBoard);
}

void Menu::renderbuttonMainShinyLeaderBoard(sf::RenderTarget& targetbuttonMainLeaderBoardShiny)
{
	targetbuttonMainLeaderBoardShiny.draw(this->buttonMainLeaderBoardShiny);
}

void Menu::renderbuttonMainExit(sf::RenderTarget& targetbuttonMainExit)
{
	targetbuttonMainExit.draw(this->buttonMainExit);
}

void Menu::renderbuttonMainExitShiny(sf::RenderTarget& targetbuttonMainExitShiny)
{
	targetbuttonMainExitShiny.draw(this->buttonMainExitShiny);
}
void Menu::renderinfo(sf::RenderTarget& targetinfo)
{
	targetinfo.draw(this->info);
}
//GAMEOVER
void Menu::renderGameoverBackground(sf::RenderTarget& targetGameover)
{
	targetGameover.draw(this->GameoverBackground);
}

void Menu::renderGameovertext(sf::RenderTarget& targettwoGameover)
{
	targettwoGameover.draw(this->gameoverText);
}

void Menu::renderbuttonMainmenu(sf::RenderTarget& targetthreeGameover)
{
	targetthreeGameover.draw(this->buttonMainMenu);
}

void Menu::renderMainmenuText(sf::RenderTarget& targetfourGameover)
{
	targetfourGameover.draw(this->MainmenuText);
}

void Menu::renderbuttonMainmenuShiny(sf::RenderTarget& targetfiveGameover)
{
	targetfiveGameover.draw(this->buttonMainmenuShiny);
}

void Menu::renderAnimal(sf::RenderTarget& targetAnimal)
{
	targetAnimal.draw(this->Animal);
}

void Menu::renderAnimal2(sf::RenderTarget& targetAnimal2)
{
	targetAnimal2.draw(this->Animal2);
}

void Menu::renderLeaderBoardBackground(sf::RenderTarget& targetLeaderBoard)
{
	targetLeaderBoard.draw(this->LeaderBoardBackground);
}

void Menu::renderArrowReverse(sf::RenderTarget& targetArrowReverse)
{
	targetArrowReverse.draw(this->ArrowReverse);
}

void Menu::renderbuttonArrowReverse(sf::RenderTarget& targetbuttonArrowReverse)
{
	targetbuttonArrowReverse.draw(this->buttonArrowReverse);
}

void Menu::renderbuttonArrowReverseShiny(sf::RenderTarget& targetbuttonArrowReverseShiny)
{
	targetbuttonArrowReverseShiny.draw(this->buttonArrowReverseShiny);
}

void Menu::renderRecWhite(sf::RenderTarget& targetShape)
{
	targetShape.draw(this->whiteboard);
}

void Menu::renderHowtoplay(sf::RenderTarget& targetHow)
{
	targetHow.draw(this->Howtoplay);
}

void Menu::renderEnter(sf::RenderTarget& targetEnter)
{
	targetEnter.draw(this->Enter);
}



