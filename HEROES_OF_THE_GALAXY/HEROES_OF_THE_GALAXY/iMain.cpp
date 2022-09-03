#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_LEN 1280
#define SCREEN_WIDTH 720
#define MAX_BULLET 22
#define BULLET_SPEED 20

#define MAX_ENEMY 11
#define ENEMY_SPEED 5


#define INTRO 10
#define MENU 1
#define GAME 2
#define HIGHSCORE 3
#define INSTRUCTION 4
#define PAUSE 5
#define CREDITS 6
#define GAMEOVER 8
#define WINNER 7
#define NAMEINPUT 15

int CollisionTimer, BulletTimer, EnemyTimer, EnemyBulletTimer, Enemy_BulletTimerVariable;
int ShieldUseTimer, PlayerCollisionTimer, healthMoveTimer;

bool ShieldBool = false;
int ShieldTimer = 5000;
int ShieldNum = 3;
void ShieldUseMethod();

char scorePrint[100];
int score = 0;

char lifePrint[100];
int life = 200;

char AttackerPrint[100];
int Attacker = 500; //Galaxy life 

int superAttack = 3;

int shipx = 500;
int shipy = 0;

//health--------------------
int hx = 2000;
int hy = 2000;
void healthMove();
//for high score------------
struct highscore{
	char name[30];
	int score;
	char scorePrint[100];
}highscore[5];

void HighSCore();
void ScoreDraw();


//for name input ----------------------------------
char str[100], str2[100];
int len;
int NameMode;
void textBoxDraw();

void NewGameFunction(); //IMPORTANT

void PlayerCollision();
void GameOver();

void menuAnimation();
void resetAnimation();
void AnimationDraw();

void EnemyCollision();
void createBullet(int bulletX, int bulletY);
void resetBullet(int bulletNumber);
void BulletMove(void);
void bulletDraw(void);

void resetEnemy(int enemyNumber);
void EnemyMove(void);
void enemyDraw(void);

void EnemyBulletDraw();
void resetEnemyBullet(int Enemy_BulletNum);
void Enemy_BulletMove();
void iInitialize_EnemyBullet();
void Enemy_BulletTimer();
void iInitializeEnemy();

void ResumeGame();
void PauseGame();

struct bulletStruct
{
	int mode;
	int bulletX;
	int bulletY;

};

struct enemyStruct
{
	int Ex;
	int Ey;
	int EnemeSpeed;
};

struct enemyStruct enemy[MAX_ENEMY] = { 0 };
struct bulletStruct bullet[MAX_BULLET] = { 0 };



void createBullet(int bulletX, int bulletY)
{

	int i;
	for (i = 0; i < MAX_BULLET+1; i++)
	{
		if (bullet[i].mode == 0)
		{
			break;
		}
	}
		bullet[i].mode = 1;
		bullet[i].bulletX = bulletX;
		bullet[i].bulletY = bulletY;
	
}



void resetEnemy(int enemyNumber)
{
	enemy[enemyNumber].Ex = rand() % 1000;
	enemy[enemyNumber].Ey = 700;
	enemy[enemyNumber].EnemeSpeed = (rand() % 5) + 5;
}


void enemyDraw()
{
	iShowBMP2(enemy[0].Ex, enemy[0].Ey, "enemy_ship.bmp", 0);
	iShowBMP2(enemy[1].Ex, enemy[1].Ey, "Asteroids01.bmp", 0);
	iShowBMP2(enemy[2].Ex, enemy[2].Ey, "enemy_ship.bmp", 0);
	iShowBMP2(enemy[3].Ex, enemy[3].Ey, "Asteroids02.bmp", 0);
	iShowBMP2(enemy[4].Ex, enemy[4].Ey, "enemy_ship.bmp", 0);
	iShowBMP2(enemy[5].Ex, enemy[5].Ey, "Asteroids01.bmp", 0);
	iShowBMP2(enemy[6].Ex, enemy[6].Ey, "enemy_ship.bmp", 0);
	iShowBMP2(enemy[7].Ex, enemy[7].Ey, "Asteroids02.bmp", 0);
	iShowBMP2(enemy[8].Ex, enemy[8].Ey, "enemy_ship.bmp", 0);
	iShowBMP2(enemy[9].Ex, enemy[9].Ey, "Asteroids01.bmp", 0);
	iShowBMP2(enemy[10].Ex, enemy[10].Ey, "enemy_ship.bmp", 0);
	iShowBMP2(enemy[11].Ex, enemy[11].Ey, "Asteroids02.bmp", 0);
}


void resetBullet(int bulletNumber)
{
	bullet[bulletNumber].mode = 0;
	bullet[bulletNumber].bulletX = 2000;
	bullet[bulletNumber].bulletY = 2000;
}


void bulletDraw(void)
{
	iShowBMP2(bullet[0].bulletX, bullet[0].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[1].bulletX, bullet[1].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[2].bulletX, bullet[2].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[3].bulletX, bullet[3].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[4].bulletX, bullet[4].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[5].bulletX, bullet[5].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[6].bulletX, bullet[6].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[7].bulletX, bullet[7].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[8].bulletX, bullet[8].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[9].bulletX, bullet[9].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[10].bulletX, bullet[10].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[11].bulletX, bullet[11].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[12].bulletX, bullet[12].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[13].bulletX, bullet[13].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[14].bulletX, bullet[14].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[15].bulletX, bullet[15].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[16].bulletX, bullet[16].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[17].bulletX, bullet[17].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[18].bulletX, bullet[18].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[19].bulletX, bullet[19].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[20].bulletX, bullet[20].bulletY, "bullet.bmp", 0);
	iShowBMP2(bullet[21].bulletX, bullet[21].bulletY, "bullet.bmp", 0);
}

void BulletMove(void)
{
	for (int bulleti = 0; bulleti < MAX_BULLET+1 ; bulleti++){

		if (bullet[bulleti].mode == 1)
		{
			
			bullet[bulleti].bulletY += BULLET_SPEED;

			if (bullet[bulleti].bulletY > SCREEN_WIDTH)
			{
				resetBullet(bulleti);
			}
		}
	}
}


void EnemyMove()
{
	for (int k = 0; k<MAX_ENEMY + 1; k++)
	{
		enemy[k].Ey = enemy[k].Ey - enemy[k].EnemeSpeed;
		if (enemy[k].Ey <= 0)
		{
			resetEnemy(k);
			if (k == 0 || k % 2 == 0)
				Attacker--;
		}
		
	}

}

void CreditsDraw()
{
	iShowBMP2(594, 516, "menu_title.bmp", 0);
	iText(120, 450, "ID", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(280, 450, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(70, 450 - 50, "19 02 04 106", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(230, 450 - 50, "JANAK MALLIK", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(70, 400 - 50, "19 02 04 111", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(230, 400 - 50, "SHOVON CHOWDHURY", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(70, 350 - 50, "19 02 04 110", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(230, 350 - 50, "SARKAR BULBUL AHAMMED", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(70, 300 - 50, "19 02 04 100", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(230, 300 - 50, "ANINDA MAZUMDER", GLUT_BITMAP_TIMES_ROMAN_24);
}

char SpaceShip[25] = "spaceship_fire.bmp";
char shipefire[25] = "spacefire.bmp";

struct enemyBulletStruct
{
	int ebx; //ebx = enemy bullet x
	int eby; //eby = enemy bullet y
};
struct enemyBulletStruct eb[11] = { 0 }; //eb = enemy bullet

bool bulletSound = false;
//
int maShipx = 790;
int maShipy = 30;

int maEnemyx = 900;
int maEnemyy = 400;
bool resumeBool = false;
//
int GameState = INTRO;
void iDraw()
{
	iClear();
	iSetColor(255, 255, 255);
	if (GameState == INTRO)
	{
		iShowBMP2(213, 251, "title.bmp", 0);
	}

	if (GameState == MENU)
	{

		AnimationDraw();

		iShowBMP2(594, 516, "menu_title.bmp", 0);
		iShowBMP2(70, 400, "menu\\newgame.bmp", 0);
		//330 60
		iShowBMP2(70, 325, "menu\\highscore.bmp", 0);
		iShowBMP2(70, 250, "menu\\instructions.bmp", 0);
		iShowBMP2(70, 175, "menu\\credits.bmp", 0);
		iShowBMP2(70, 100, "menu\\exit.bmp", 0);
	}
	if (GameState == HIGHSCORE)
	{
		AnimationDraw();
		iShowBMP2(594, 516, "menu_title.bmp", 0);
		ScoreDraw();
	}
	if (GameState == INSTRUCTION)
	{

		iShowBMP(0, 0, "page\\instructions.bmp");
	}
	if (GameState == CREDITS)
	{
		AnimationDraw();
		CreditsDraw();
	}
	if (GameState == GAMEOVER)
	{
		iShowBMP(0, 0, "page\\gameover.bmp");
		iShowBMP2(70, 100, "menu\\exit.bmp", 0);
		iText(500, 500, "YOUR SCORE", GLUT_BITMAP_HELVETICA_18);
		iText(660, 500, scorePrint, GLUT_BITMAP_HELVETICA_18);

		iText(500, 560, "YOUR NAME", GLUT_BITMAP_HELVETICA_18);
		iText(660, 560, str2, GLUT_BITMAP_HELVETICA_18);
		//you can add score here
	}
	/*if (GameState == PAUSE)
	{
		AnimationDraw();
		iShowBMP2(594, 516, "menu_title.bmp", 0);

		iShowBMP2(70, 400, "menu\\resume.bmp", 0);
		iShowBMP2(70, 325, "menu\\newgame.bmp", 0);
		iShowBMP2(70, 250, "menu\\highscore.bmp", 0);
		iShowBMP2(70, 175, "menu\\instructions.bmp", 0);
		iShowBMP2(70, 100, "menu\\credits.bmp", 0);
		iShowBMP2(70, 25, "menu\\exit.bmp", 0);
	}*/
	//if (GameState == WINNER)
	//{
	//	iShowBMP(0, 0, "page\\winner.bmp");
	//}
	///*	INTRO 0
	//	MENU 1
	//	GAME 2
	//	HIGHSCORE 3
	//	INSTRUCTION 4
	//	PAUSE 5
	//	CREDITS 6
	//	GAMEOVER 7*/

	if (GameState == NAMEINPUT)
	{
		AnimationDraw();
		iShowBMP2(594, 516, "menu_title.bmp", 0);
		iText(50, 290, "INPUT YOUR NAME HERE", GLUT_BITMAP_HELVETICA_18);

		iText(50, 200, "YOU ARE A WARRIOR. NOW YOU HAVE TO SAVE OUR GALAXY FROM THE", GLUT_BITMAP_HELVETICA_18);
		iText(50, 170, "ENEMYS. YOU HAVE 200 LIFE POWER TO FIGHT WITH THOSE ENEMIES.", GLUT_BITMAP_HELVETICA_18);
		iText(50, 120, "AND REMEMBER DON'T LET THE ENEMIES TO PASS YOU. 500 ENEMIES", GLUT_BITMAP_HELVETICA_18);
		iText(50, 90, "ARE ENOUGH TO DESTROY THE GALAXY.", GLUT_BITMAP_HELVETICA_18);
		iText(50, 60, "GOOD LUCK!!", GLUT_BITMAP_HELVETICA_18);
		textBoxDraw();
		if (NameMode == 1)
		{
			iText(55, 260, str, GLUT_BITMAP_HELVETICA_18);
			printf("%s", str2);
		}
	}

	if (GameState == GAME || GameState == PAUSE)
	{
		iShowBMP2(hx, hy, "health.bmp", 0);
		bulletDraw();
		EnemyBulletDraw();
		enemyDraw();
		iShowBMP2(shipx, shipy, "spaceship_fire.bmp", 0);


		sprintf_s(scorePrint, "%d", score);
		iText(60, 650, "SCORE", GLUT_BITMAP_HELVETICA_18);
		iText(200, 650, scorePrint, GLUT_BITMAP_HELVETICA_18);

		iText(60, 480, "PLAYER NAME", GLUT_BITMAP_HELVETICA_18);
		iText(220, 480, str2, GLUT_BITMAP_HELVETICA_18);


		sprintf_s(AttackerPrint, "%d", Attacker);
		iText(60, 600, "GALAXY LIFE", GLUT_BITMAP_HELVETICA_18);
		iText(200, 600, AttackerPrint, GLUT_BITMAP_HELVETICA_18);

		iRectangle(60, 580, 200, 10);
		iFilledRectangle(60, 580, (Attacker*200)/500, 10);

		sprintf_s(lifePrint, "%d", life);
		iText(60, 550, "LIFE", GLUT_BITMAP_HELVETICA_18);
		iText(200, 550, lifePrint, GLUT_BITMAP_HELVETICA_18);
		
		GameOver();

		iRectangle(60, 530, 200, 10);
		iFilledRectangle(60, 530, life, 10);
		if (GameState == PAUSE)
		{
			//paused
			iShowBMP2(350, 300, "paused.bmp", 0);
			iShowBMP2(70, 100, "menu\\exit.bmp", 0);
		}
	}
}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	printf("%d %d\n", mx, my);
}

void iMouse(int button, int state, int mx, int my)
{
	//INTRO to MENU
	if (GameState == INTRO)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			/*if (GameState == INTRO)*/
			GameState = MENU;
			resetAnimation();
			printf("menu");
		}
	}

	if (GameState == GAMEOVER)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if ((mx >= 70 && mx <= 400) && (my >= 100 && my <= 160))
			{
			exit(0);
			}
		}
	}

	//MENU
	 if (GameState == MENU)
	{
		
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			printf("game");
			//NewGame
			if ((mx >= 70 && mx <= 400) && (my >= 400 && my <= 460))
			{
				GameState = NAMEINPUT;
				printf("game2");
				//NewGameFunction();
			}
			//highScore
			if ((mx >= 70 && mx <= 400) && (my >= 325 && my <= 385))
			{
				GameState = HIGHSCORE;
				//printf("game2");
				HighSCore();
			}
			//instructions
			if ((mx >= 70 && mx <= 400) && (my >= 250 && my <= 310))
			{
				GameState = INSTRUCTION;
				//printf("game2");
			}
			//credits
			if ((mx >= 70 && mx <= 400) && (my >= 175 && my <= 235))
			{
				GameState = CREDITS;
				printf("game2");
			}
			//exit
			if ((mx >= 70 && mx <= 400) && (my >= 100 && my <= 160))
			{
				exit(0);
				/*GameState = GAME;
				printf("game2");*/
			}
		}
	}
	 //name input--------------
	 if (GameState == NAMEINPUT)
	 {
		 if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		 {
			 if (mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && NameMode == 0)
			 {
				 NameMode = 1;
			 }
		 }
	 }
	//GAME
	 if (GameState == GAME)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			createBullet(shipx + 35, shipy + 150);
			/*bulletSound = true;
			if (bulletSound == true)
				PlaySound("music\\bullet.wav",NULL,SND_ASYNC);*/
		}
	}
	//PAUSE
	 if (GameState == PAUSE)
	 {
		 if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		 {
			 if ((mx >= 70 && mx <= 400) && (my >= 100 && my <= 160))
			 {
				 HighSCore();
				 exit(0);
				 /*GameState = GAME;
				 printf("game2");*/
			 }
		 }
		 //if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		 //{
			// //printf("game");
			// ////RESUME
			// //if ((mx >= 70 && mx <= 400) && (my >= 400 && my <= 460))
			// //{
			//	// ResumeGame();
			//	// GameState = GAME;
			//	// printf("game2");
			// //}
			// ////NEWGAME
			// //if ((mx >= 70 && mx <= 400) && (my >= 325 && my <= 385))
			// //{
			//	// GameState = NAMEINPUT;
			// //}
			// ////HIGHSCORE
			// //if ((mx >= 70 && mx <= 400) && (my >= 250 && my <= 310))
			// //{
			//	// GameState = HIGHSCORE;
			//	// printf("game2");
			// //}
			// ////INSTRUCTION
			// //if ((mx >= 70 && mx <= 400) && (my >= 175 && my <= 235))
			// //{
			//	// GameState = INSTRUCTION;
			//	// printf("game2");
			// //}
			// ////credits
			// //if ((mx >= 70 && mx <= 400) && (my >= 100 && my <= 160))
			// //{
			//	// GameState = CREDITS;
			//	// printf("game2");
			// //}
			// //exit
			// if ((mx >= 70 && mx <= 400) && (my >= 25 && my <= 85))
			// {
			//	 exit(0);
			// }	 
		 }
	 //}

	 ////winner
	 //if (GameState == WINNER)
	 //{
		// if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		// {
		//	 /*if (GameState == INTRO)*/
		//	 GameState = MENU;
		//	 printf("menu");
		// }
	 //}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (GameState == PAUSE)
	{
		if (key == 'r' || key == 'R')
		{
			ResumeGame();
			GameState = GAME;
		}
	}
	//HIGH SCORE
	if (GameState == HIGHSCORE)
	{
		if (key == '\b')
		{
				GameState = MENU;
		}
	}
	//INSTRUCTIONS
	if (GameState == INSTRUCTION)
	{
		if (key == '\b')
		{
			if (key == '\b')
			{
				GameState = MENU;
			}
		}
	}
	//CREDITS
	if (GameState == CREDITS)
	{
		if (key == '\b')
		{
			if (key == '\b')
			{
				GameState = MENU;
			}
		}
	}
	//FOR NAME INPUT---------
	if (GameState == NAMEINPUT)
	{
		int i;
		if (NameMode == 1)
		{
			if (key == '\r')
			{
				NameMode = 0;
				strcpy_s(str2, str);
				printf("%s \n", str2);
				for (i = 0; i < len; i++)
				{
					str[i]=0;
					len = 0;
				}
				resumeBool = false;
				GameState = GAME;
				printf("game2");
				NewGameFunction();
			}
			else
			{
				str[len] = key;
				len++;
			}
		}
	}
	//GAME
	if (GameState == GAME)
	{
		if (key == '\b')
		{
			PauseGame();
			GameState = PAUSE;
		}
		//PLAYER MOVE
		if (key == 'a' || key == 'A')
		{
			shipx = shipx - 10;
		}

		if (key == 'd' || key == 'D')
		{
			shipx = shipx + 10;
		}

		if (key == 's' || key == 'S')
		{
			shipy = shipy - 5;
		}
		if (key == 'w' || key == 'W')
		{
			shipy = shipy + 5;
		}
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_UP)
	{
		shipy = shipy + 5;
	}
	if (key == GLUT_KEY_DOWN)
	{
		shipy = shipy - 5;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		shipx = shipx + 10;
	}
	if (key == GLUT_KEY_LEFT)
	{
		shipx = shipx - 10;
	}
}

//EnemyCollision
void EnemyCollision()
{
	
	int m;
	int n;
	for (m = 0; m < MAX_BULLET + 1; m++)
	{
		for (n = 0; n < MAX_ENEMY + 1; n++)
		{

			int bx = bullet[m].bulletX;
			int by = bullet[m].bulletY;

			int ex = enemy[n].Ex;
			int ey = enemy[n].Ey;

			if (bx>=ex && bx<=(ex+60) && by>=ey && by<=(ey+50))
			{
				if (bullet[m].mode == 1)
				{
					resetEnemy(n);
					resetBullet(m);
					score+=2;
					printf("collsion");
				}
			}

		}
	}
}

void iInitializeEnemy()
{

	for (int j = 0; j< MAX_ENEMY + 1; j++)
	{
		enemy[j].Ex = rand() % 900;
		enemy[j].Ey = 700;
		enemy[j].EnemeSpeed = (rand() % 5) + 5;
	}

}
void iInitializeBullet(){
	for (int Bulletj = 0; Bulletj< MAX_BULLET + 1; Bulletj++)
	{
		bullet[Bulletj].mode = 0;
		bullet[Bulletj].bulletX = 2000;
		bullet[Bulletj].bulletY = 2000;
	}
}

int main()
{
	hx = 700;
	hy = 700;
	len = 0;
	NameMode = 0;
	str[0] = 0;

	iInitializeEnemy();
	iInitializeBullet();
	iInitialize_EnemyBullet();

	CollisionTimer = iSetTimer(100, EnemyCollision);
	BulletTimer = iSetTimer(100, BulletMove);
	EnemyTimer = iSetTimer(100, EnemyMove);
	EnemyBulletTimer = iSetTimer(10, Enemy_BulletMove);

	Enemy_BulletTimerVariable = iSetTimer(1000, iInitialize_EnemyBullet);

	PlayerCollisionTimer = iSetTimer(100, PlayerCollision);
	healthMoveTimer = iSetTimer(100, healthMove);

	iSetTimer(100, menuAnimation);

	iInitialize(1280, 720, "HEROES OF THE GALAXY");

	iStart();
	return 0;
}

void PauseGame(){
	iPauseTimer(CollisionTimer);
	iPauseTimer(BulletTimer);
	iPauseTimer(EnemyTimer);
	iPauseTimer(EnemyBulletTimer);
	iPauseTimer(healthMoveTimer);
}

void ResumeGame(){
	iResumeTimer(CollisionTimer);
	iResumeTimer(BulletTimer);
	iResumeTimer(EnemyTimer);
	iResumeTimer(EnemyBulletTimer);
	iResumeTimer(healthMoveTimer);
}

void EnemyBulletDraw(){
	iShowBMP2(eb[0].ebx, eb[0].eby, "enemy_bullet.bmp", 0);
	iShowBMP2(eb[2].ebx, eb[2].eby, "enemy_bullet.bmp", 0);
	iShowBMP2(eb[4].ebx, eb[4].eby, "enemy_bullet.bmp", 0);
	iShowBMP2(eb[6].ebx, eb[6].eby, "enemy_bullet.bmp", 0);
	iShowBMP2(eb[8].ebx, eb[8].eby, "enemy_bullet.bmp", 0);
	iShowBMP2(eb[10].ebx, eb[10].eby, "enemy_bullet.bmp", 0);
}

void resetEnemyBullet(int Enemy_BulletNum){
	eb[Enemy_BulletNum].ebx = 3000;
	eb[Enemy_BulletNum].eby = 3000;
}

void Enemy_BulletMove(){
	for (int ebi = 0; ebi < 12; ebi++)
	{
		eb[ebi].eby = eb[ebi].eby-10;
		if (eb[ebi].eby <= 0)
		{
			resetEnemyBullet(ebi);
		}
	}
}

void iInitialize_EnemyBullet()
{
	for (int ebj = 0; ebj < 12; ebj++)
	{
		eb[ebj].ebx = enemy[ebj].Ex + 23;
		eb[ebj].eby = enemy[ebj].Ey;
	}
}

void Enemy_BulletTimer()
{
	for (int ebj = 0; ebj < 12; ebj++)
	{
		resetEnemyBullet(ebj);
	}

}

 //PlayerCollision
void PlayerCollision()
{
	
	int ebm; //enemy bullet m
	//int pn; //player n
	//for (ebm = 0; ebm < 7 ; ebm++)
	for (ebm = 0; ebm < 11 ; ebm+=2)
	{
			int ebcx = eb[ebm].ebx;
			int ebcy = eb[ebm].eby;
			//int ebcx2 = 

			int pcx = shipx;
			int pcy = shipy;

if (ebcx >= pcx && ebcx <= (pcx + 84) && ebcy >= pcy && ebcy <= (pcy + 150))
{

		resetEnemyBullet(ebm);
		life--;
		printf("PlayerCollision");
}

		}
	}

void GameOver()
{
	if (life <= 0 || Attacker <= 0)
	{
		HighSCore();
		PauseGame();
		GameState = GAMEOVER;
	}
}


void resetAnimation()
{
	 maShipx = 790;
	 maShipy = 30;

	 maEnemyx = 900;
	 maEnemyy = 400;
}

void menuAnimation()
{

		maShipx+=2;
		maShipy+=2;

		maEnemyx-=2;
		maEnemyy-=2;
		if (maEnemyy <= 70)
		{
			resetAnimation();
		}
}

void AnimationDraw()
{
	iShowBMP2(maShipx, maShipy, "ma\\ship.bmp", 0);
	iShowBMP2(maEnemyx, maEnemyy, "ma\\enemy.bmp", 0);
}

void NewGameFunction()
{
	score = 0;
	life = 200;
	Attacker = 500; //Galaxy life 
	iInitialize_EnemyBullet();
	iInitializeBullet();
	iInitializeEnemy();
}

void ShieldUseMethod()
{
	if (ShieldBool == true && ShieldTimer <= 0)
	{
		ShieldTimer--;
		iPauseTimer(PlayerCollisionTimer);
	}
	else
	{
		ShieldBool = false;
		iResumeTimer(PlayerCollisionTimer);
	}
}

void textBoxDraw()
{
	iRectangle(50, 250, 250, 30);
}

void HighSCore()
{

	int i;
	//file to array of structure-------------- start
	FILE *scorePointer;// = fopen("highScore.txt", "r");
	scorePointer = fopen("highScore.txt", "r");
	for (i = 0; i < 5; i++)
	{
		fscanf(scorePointer, "%s %d", highscore[i].name, &highscore[i].score);
	}
	fclose(scorePointer);
	//file to array of structure-------------- end

	highscore[5].score = score;
	strcpy_s(highscore[5].name,str2);

	for (int i = 0; i < 6 - 1; i++){
		for (int j = i + 1; j < 6; j++)
		{
			if (highscore[i].score < highscore[j].score)
			{
				int temp;
				temp = highscore[i].score;
				highscore[i].score = highscore[j].score;
				highscore[j].score = temp;
				//
				char temp3[100];
				strcpy_s(temp3, highscore[i].name);
				strcpy_s(highscore[i].name, highscore[j].name);
				strcpy_s(highscore[j].name, temp3);
			}
		}
		//FILE *fp;
		scorePointer = fopen("highScore.txt", "w");
		for (int i = 0; i < 5; i++){
			fprintf(scorePointer, "%s %d\n", highscore[i].name, highscore[i].score);
		}
		fclose(scorePointer);
	}
}

void ScoreDraw()
{
	//HighSCore();
	for (int i = 0; i < 5; i++)
	{
		sprintf(highscore[i].scorePrint, "%d", highscore[i].score);
	}

	//iText(125, 1050, highscore[0].scorePrint, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText(125, 400, "1", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(125, 350, "2", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(125, 300, "3", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(125, 250, "4", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(125, 200, "5", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(175, 400, highscore[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(175, 350, highscore[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(175, 300, highscore[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(175, 250, highscore[3].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(175, 200, highscore[4].name, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(375, 400, highscore[0].scorePrint, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(375, 350, highscore[1].scorePrint, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(375, 300, highscore[2].scorePrint, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(375, 250, highscore[3].scorePrint, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(375, 200, highscore[4].scorePrint, GLUT_BITMAP_TIMES_ROMAN_24);
}

void healthMove()
{
	hy = hy-3;
	if (hy <= 0)
	{
		hx = rand() % 1000;
		hy = 700;
	}

	if (hx >= shipx && hx <= (shipx + 64) && hy >= shipy && hy <= (shipy + 64))
	{
		if (life >= 190)
		{
			life = 200;
			hx = (rand() % 900)+100;
			hy = 700;
		}
		else
		{
			life+=10;
			hx = rand() % 1000;
			hy = 700;
		}
	}
}

