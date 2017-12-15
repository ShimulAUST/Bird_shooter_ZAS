#include "iGraphics.h"
#include "bitmap_loader.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define ScreenWidth 1000
#define ScreenHeight 700
int bulletTimer = 0;
int bulletCount = 0;
int GunManX = 0 ;
int GunManY = 0;
bool homeMusicOn=true;
bool playMusicOn=true;
int numberOfHomeMenu=6;
int numberOfOptionMenu=2;
int birdTimer=0;
int pointCount=0;
char StrPoint[50];
int healthPoint=5;
int healthPoint1=3;
int healthX=420;
int healthY=650;
int pointShowX=100;
int pointShowY=650;
int OptionState=-1;
int gameState=-1;
int gameOverState=-1;   
int BirdX=1100;
int BirdY=550;
char secondsString[10];
char minutesString[10];
int startime;
int timeElapsed;
int Second;
int minute;
int startTime;
int bulletCount2=0;
int timeElapsed2=0;
char secondsString2[10];
char minutesString2[10];
int Second2;
int minute2;
int BackGroundTimer=0;
int SpecialFeaturesTimer=0;
int BackGroundTimer2=0;
int bullet2Timer=0;
int SpecialFeature2Timer=0;
int gameStateOver=0;


int numberArray[100];
int arrayIndex = 0, stringIndex = 0;
char st[100][100];
int numberIndex = 0;
char nhigh[100];




//******************************Array of the Birds**************************************************//
char birds1[6][15]={"Birds\\1(a).bmp", "Birds\\2(a).BMP", "Birds\\1(a).BMP","Birds\\4.BMP","Birds\\5(a).bmp","Birds\\2(b).bmp"};
char birds2[6][15]={"Birds\\1(b).bmp", "Birds\\2(b).BMP", "Birds\\1(b).BMP","Birds\\4.BMP","Birds\\5(b).bmp","Birds\\2(a).bmp"};

//******************************Array of the Home Menu Background**************************************************//
char homeMenu[15]="Main\\Home.BMP";

//******************************Array of the home Menu**************************************************//
char gamePlay[6][15]={"Main\\1.bmp","Main\\2.bmp","Main\\3.bmp","Main\\4.bmp","Main\\5.bmp","Main\\6.bmp"};

//******************************Array of the Help Menu**************************************************//
char Help[20]="Main\\Helpcopy.bmp";

//******************************Array of the About Picture**************************************************//
char About[20]="Main\\Aboutcopy.bmp";

//******************************Array of the option Background**************************************************//
char option[20]="Main\\Optioncopy.bmp";

//******************************Array of the game Background for Move**************************************************//
char back[101][101]={"Back\\1.bmp","Back\\2.bmp","Back\\3.bmp","Back\\4.bmp","Back\\5.bmp","Back\\6.bmp","Back\\7.bmp","Back\\8.bmp","Back\\9.bmp","Back\\10.bmp","Back\\11.bmp","Back\\12.bmp","Back\\13.bmp","Back\\14.bmp","Back\\15.bmp","Back\\16.bmp","Back\\17.bmp","Back\\18.bmp","Back\\19.bmp","Back\\20.bmp","Back\\21.bmp","Back\\22.bmp","Back\\23.bmp","Back\\24.bmp","Back\\25.bmp","Back\\26.bmp","Back\\27.bmp","Back\\28.bmp","Back\\29.bmp","Back\\30.bmp","Back\\31.bmp","Back\\32.bmp","Back\\33.bmp","Back\\34.bmp","Back\\35.bmp","Back\\36.bmp","Back\\37.bmp","Back\\38.bmp","Back\\39.bmp","Back\\40.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\1.bmp","Back\\2.bmp","Back\\3.bmp","Back\\4.bmp","Back\\5.bmp","Back\\6.bmp","Back\\7.bmp","Back\\8.bmp","Back\\9.bmp","Back\\10.bmp","Back\\11.bmp","Back\\12.bmp","Back\\13.bmp","Back\\14.bmp","Back\\15.bmp","Back\\16.bmp","Back\\17.bmp","Back\\18.bmp","Back\\19.bmp","Back\\20.bmp","Back\\21.bmp","Back\\22.bmp","Back\\23.bmp","Back\\24.bmp","Back\\25.bmp","Back\\26.bmp","Back\\27.bmp","Back\\28.bmp","Back\\29.bmp","Back\\30.bmp","Back\\31.bmp","Back\\32.bmp","Back\\33.bmp","Back\\34.bmp","Back\\35.bmp","Back\\36.bmp","Back\\37.bmp","Back\\38.bmp","Back\\39.bmp","Back\\40.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\41.bmp","Back\\1.bmp"};
char background[20][30]={"Background\\medium200.bmp","Background\\medium400.bmp","Background\\medium600.bmp","Background\\medium800.bmp","Background\\medium1000.bmp"};

//******************************Array of the Option Menu**************************************************//
char optionMenu1[20][30]={"Main\\Easy.BMP","Main\\hard.BMP"};
//******************************Array of Life/health picture**********************************************//
char lifes[15]="Extra\\life.bmp";
//*******************************Array of Special Feature*************************************************//
char special[4][15]={"Extra\\1.bmp","Extra\\2.bmp","Extra\\3.bmp","Extra\\5.bmp"};
char special1[4][15]={"Extra\\1.bmp","Extra\\2.bmp","Extra\\3.bmp","Extra\\4.bmp"};

//********************************GunMan2**************************************************************//
char GunManNew[12]="GunMan2.bmp";
//*******************************Array of Background For level 2****************************************////
char background2[51][20]={"BackGround2\\1.bmp","BackGround2\\2.bmp","BackGround2\\3.bmp","BackGround2\\4.bmp","BackGround2\\5.bmp","BackGround2\\6.bmp","BackGround2\\7.bmp","BackGround2\\8.bmp","BackGround2\\9.bmp","BackGround2\\10.bmp","BackGround2\\11.bmp","BackGround2\\12.bmp","BackGround2\\13.bmp","BackGround2\\14.bmp","BackGround2\\15.bmp","BackGround2\\16.bmp","BackGround2\\17.bmp","BackGround2\\18.bmp","BackGround2\\19.bmp","BackGround2\\20.bmp","BackGround2\\21.bmp","BackGround2\\22.bmp","BackGround2\\23.bmp","BackGround2\\24.bmp","BackGround2\\25.bmp","BackGround2\\1.bmp","BackGround2\\2.bmp","BackGround2\\3.bmp","BackGround2\\4.bmp","BackGround2\\5.bmp","BackGround2\\6.bmp","BackGround2\\7.bmp","BackGround2\\8.bmp","BackGround2\\9.bmp","BackGround2\\10.bmp","BackGround2\\11.bmp","BackGround2\\12.bmp","BackGround2\\13.bmp","BackGround2\\14.bmp","BackGround2\\15.bmp","BackGround2\\16.bmp","BackGround2\\17.bmp","BackGround2\\18.bmp","BackGround2\\19.bmp","BackGround2\\20.bmp","BackGround2\\21.bmp","BackGround2\\22.bmp","BackGround2\\23.bmp","BackGround2\\24.bmp","BackGround2\\25.bmp","BackGround2\\1.bmp"};

struct Bullet //structure Of the Coordinates of Bullet
{
	int x,y,x1,y1;
	bool hasActive;// controls if bullet is visible or not
	bool DeActive,DeActive1;
	bool hasActive1;//If bullet collide with the Bird then it will be true otherwise false
	
}bullet[30],bullet1[20];


struct background{
	int x;
	int y;
	int x1,y1;
}back2[101],background1[51];//sturcture array for background CoOrdinates 

struct play{
int x;
int y;

}playMenu[6];//structure array of Coordinates homePlayMenu


struct option{
int x;
int y;

}optionMenu[2];//structure array Of Coordinates of Option menu
struct bird{

	int x, y;
	bool active;
}bird[6];//structure array of the coordinates and active birds


struct life {
	int x, y;
	bool show;
	int x1,y1;
	bool show1;
}life[5],life1[3];//Structure Array of the life 


struct GunMan{
	int x,y;
	bool active;
	int x1,y1;
	bool active1;
}GunMan,GunMan2;//Structure Of GunMan

struct Special{
int x,y,x1,y1;
bool active,active1;

}SpecialFeature,SpecialFeature1;//structure of the Special Feature


char Score[10];

void gameOver()//call from iDraw for Showing That the Game Is Over
{	
	iShowBMP(0,0,"Main//gameOver.bmp");
	
	itoa(pointCount,Score,10);
	
	iText(400,200,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);

	iText(520,200,Score,GLUT_BITMAP_TIMES_ROMAN_24);

}

void setSpecialFeature()//set the coordinates of special features in level 1 call from main function
{
	if(SpecialFeature.active==true)
	{
	SpecialFeature.x=(ScreenWidth-200)-rand()%600;
	SpecialFeature.y=ScreenHeight-100;
	}
}



int s = rand() % 4;
void showSpecialFeature()//call from Dowork function which is call from iDraw
{
	if(SpecialFeature.active)
	{
			
		iShowBMP2(SpecialFeature.x,SpecialFeature.y,special[s],255);
	
	}
	
}

void moveSpecialFeature()//call by IsetTimer in Main Function
{

	SpecialFeature.y-=10;
	if(SpecialFeature.y <= -2150)
	{
		s = rand() % 4;
		SpecialFeature.x=(ScreenWidth-200)-rand()%600;
		SpecialFeature.y = 600;
		SpecialFeature.active=true;
		
	}

}
void random00()//call from AddOrDestroyLife01 for level 1 if rand()%4==0 then healthpoint is up
{
	
	if(GunMan.active==true && SpecialFeature.active==true)
		{
			if (SpecialFeature.y <= GunMan.y + 200 && SpecialFeature.y >= GunMan.y + 180)
				{
					if (SpecialFeature.x>= GunMan.x && SpecialFeature.x<=GunMan.x + 136)
						{
							SpecialFeature.active=false;
							if(SpecialFeature.active==false && healthPoint<5)
							{
									healthPoint++;
							}
						}
				}

		}
		
}
void random01()//call from AddOrDestroyLife01 for level 1 if rand()%4==1 then healthpoint is up And PointCount is up twice
{
	
	if(GunMan.active==true && SpecialFeature.active==true)
		{
			if (SpecialFeature.y <= GunMan.y + 200 && SpecialFeature.y >= GunMan.y + 180)
				{
					if (SpecialFeature.x>= GunMan.x && SpecialFeature.x<=GunMan.x + 136)
						{
							SpecialFeature.active=false;
							if(SpecialFeature.active==false && healthPoint<=5)
							{
									healthPoint++;
									pointCount+=2;
							}
						}
				}

		}
		
}
void random02()//call from AddOrDestroyLife01 for level 1 if rand()%4==2 then healthpoint is up
{
	
	if(GunMan.active==true && SpecialFeature.active==true)
		{
			if (SpecialFeature.y <= GunMan.y + 200 && SpecialFeature.y >= GunMan.y + 180)
				{
					if (SpecialFeature.x>= GunMan.x && SpecialFeature.x<=GunMan.x + 136)
						{
							SpecialFeature.active=false;
							if(SpecialFeature.active==false && healthPoint<5)
							{
									healthPoint++;
							}
						}
				}

		}
		
}
void random03()//call from AddOrDestroyLife01 for level 1 if rand()%4==0 then healthpoint is up and pointCount up 8
{
	
	if(GunMan.active==true && SpecialFeature.active==true)
		{
			if (SpecialFeature.y <= GunMan.y + 200 && SpecialFeature.y >= GunMan.y + 180)
				{
					if (SpecialFeature.x>= GunMan.x && SpecialFeature.x<=GunMan.x + 136)
						{
							SpecialFeature.active=false;
							if(SpecialFeature.active==false && healthPoint<=5)
							{
									healthPoint++;
									pointCount+=8;
							}
						}
				}

		}
		
}
void AddOrDestroyLife01()//call from doWork which is call by iDraw
{
	if(s==0)
		random00();
	if(s==1)
		random01();
	if(s==2)
		random02();
	if(s==3)
		random03();
}
void setLife()//setting the value of the coordinates of life picture and Called from main function
{
	life[0].x = healthX-20;
	life[0].y = healthY;
	life[0].show = true;
	for (int i = 1 ; i < 5 ; i++)
	{
		life[i].x = life[i-1].x + 40;
		life[i].y = healthY;
		life[i].show = true;
	}
}

void showLife()//showing the life picture called from doWork function which is called from iDraw
{	iSetColor(65,105,225);
	iFilledRectangle(healthX-85,healthY-5,260,40);
	iSetColor(255,255,255);
	iText(healthX-80,healthY+8,"Life:",GLUT_BITMAP_TIMES_ROMAN_24);
	for (int i = 0 ; i <healthPoint ; i++)
	{
		if (life[i].show)
		{
			iShowBMP2(life[i].x , life[i].y, lifes,0);
		}
	}
		
}

void destroyLife()//destroying Life which is call from doWork function which is call by iDraw Function
{
	
	for(int i = 0; i < bulletCount ; i++)
		{
			if(bullet[i].hasActive== true )
				{
					if(bullet[i].DeActive==false)	
						{
							if(bullet[i].x>ScreenWidth||bullet[i].y>ScreenHeight)
								{								
									healthPoint--;
									bullet[i].hasActive=false;
								}
						}

				}
		}
}

void SetGunman()//Setting the Coordinates of the GunMan Called From Main Function
{
	GunMan.x=GunManX;
	GunMan.y=GunManY;
	GunMan.active=true;
}
void GunManShow()//call from doWork Function which call from iDraw when the gameState is O for show the Gunman
{
	if(GunMan.active)
	{
	iShowBMP2(GunMan.x,GunMan.y, "22.bmp", 255);
	}
}
void backgroundShow()//function for Background Show & it is call from Idraw
{
	iShowBMP(0,0,"Background\\lowerPart.bmp");
	iShowBMP(0,473,"Background\\upper.bmp");
	for(int i=0;i<101;i++)
		{
			iShowBMP(back2[i].x,back2[i].y,back[i]);
		}
}

void setBack()//setting background Coordinates And Called From Main Function
{
	int sum=0;
	for(int i=0;i<101;i++)
		{
			back2[i].y=195;
			back2[i].x=sum;
			sum+=10;
		}
}

void changeback()//call by iSetTimer in Main function for background move
{
	for(int i=0;i<101;i++)
		{
			back2[i].x-=10;
			if(back2[i].x<0)
				{
					back2[i].x=ScreenWidth;
				}
		}
}

void BulletShot() // Called from isettimer in Main Function for Moving the Bullet Automatically after a certain time and if the bullet pass the screenhight & ScreenWidth then the bullet is deactivate
{
	for(int i = 0 ; i < bulletCount ; i++)
		{
			if(bullet[i].hasActive)
				{
					bullet[i].y += 25;
					bullet[i].x+=30;
				}
			
		}
}

void bulletShow()//call from doWork function which Call from iDraw function for Show the Bullet
{
	for(int i = 0; i < bulletCount ; i++)
		{
			if(bullet[i].hasActive== true )
				{
					iShowBMP2(bullet[i].x,bullet[i].y,"99.BMP",255);
				}
			if(bulletCount==30)
			{
			bullet[bulletCount-1].hasActive=false;
			
			}
		}	
}

void CountBullet()//count the Bullet when The bullet shoot 100 bullet then the gun reloaded with 20 bullet and it is call from SetBullet
{
	if(bulletCount < 30)
		{
			bulletCount++;
		}
	if(bulletCount<30)
	{	
		if(healthPoint>0)
			{
				if(pointCount==20)
				{
					startime=clock();
					OptionState=1;
					
				}
			}
	}
	
}

void SetBullet()//Setting bullet Coordinates and it is call for when we want to press any key or mouse button 
{
	CountBullet();
	bullet[bulletCount-1].hasActive = true;
	bullet[bulletCount-1].y = GunMan.y + 167;
	bullet[bulletCount-1].x = GunMan.x+100;

}


void homeMenuShow()//Show the HomeMenu
{
	iShowBMP(0,0,homeMenu);
	for(int i=0;i<numberOfHomeMenu;i++)
		{
			iShowBMP2(playMenu[i].x,playMenu[i].y,gamePlay[i],255);
		}
}

void setHomeMenu()//the coordinates of homeplay menu sets & it is call from Main Function
{	
	int CurrentYPosition=80;
	for(int i=numberOfHomeMenu-1;i>=0;i--)
		{
			playMenu[i].x=408;
			playMenu[i].y=CurrentYPosition;
			CurrentYPosition+=90;
		}
}

void optionMenuShow()//call from doWork Function which call from iDraw to Show optionmenu   
{
	iShowBMP(0,0,option);
	for(int i=0;i<numberOfOptionMenu;i++)
		{
			iShowBMP2(optionMenu[i].x,optionMenu[i].y,optionMenu1[i],255);
		}
		
}


void setOptionMenu()//the coordinates of option menu sets & it is call from Main Function
{	
	int CurrentYPosition=250;
	for(int i=numberOfOptionMenu-1;i>=0;i--)
		{
			optionMenu[i].x=650;
			optionMenu[i].y=CurrentYPosition;
			CurrentYPosition+=100;
		}
}

void setBird()//setting the coordinates of the birds and it is call from main function
{
	for (int i = 0, x1 = 80; i < 6 ; i++, x1 += 80)
		{
			bird[i].x = BirdX + x1;
			bird[i].y = BirdY - rand() % 250;
			bird[i].active = true;
		}
}
void showBird()//Showing the birds & called from doWork which is call from iDraw
{
	for (int i = 0 ; i < 6 ; i++)
		{

			if (bird[i].active)
				{
					iShowBMP2(bird[i].x,bird[i].y,birds1[i],255);
				}
		}
}

void moveBird()//Moving the birds & called from iSetTimer in main function  
{
	for (int i = 0,x1=80 ; i < 6 ; i++,x1+=80)
		{
		bird[i].x -= 10;

		if(bird[i].x<0 )
		{	bird[i].x =BirdX + x1;
			bird[i].y = BirdY- rand() % 250;
			bird[i].active = true;
		}
	}
}

void killBird()//deactive the birds called from dowork which is called from idraw
{
	for (int i = 0; i < bulletCount ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if(bullet[i].hasActive && bird[j].active)
						{
							if (bullet[i].x+25 >= bird[j].x && bullet[i].x+25 <= bird[j].x +70)
								{
									if (bullet[i].y+25 >= bird[j].y && bullet[i].y+25 <= bird[j].y + 70)
											{
												bird[j].active = false;
												bullet[i].DeActive=true;
												if(bird[j].active==false)
												{
													pointCount++;
												}
											}
								}
						}
				}
		}
	
}

void pointShow()//show the point of the killing birds and called from doWork function which is called from iDraw
{
	
	itoa(pointCount,StrPoint,10);
	iSetColor(65,105,225);
	iFilledRectangle(pointShowX-10,pointShowY-5,98,40);
	iSetColor(255,255,255);
	iText(pointShowX,pointShowY+8,"Point:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(pointShowX+63,pointShowY+6,StrPoint,GLUT_BITMAP_TIMES_ROMAN_24);
}
void timeShow()//showing the time Elapsed Call from doWork which is call from iDraw
{
	int endTime=clock();
	
	timeElapsed=180-(endTime-startime)/CLOCKS_PER_SEC;
	Second=timeElapsed%60;
	minute=timeElapsed/60;
	itoa(minute,minutesString,10);
    itoa(Second,secondsString,10);
	iSetColor(65,105,225);
	iFilledRectangle(805,640,140,40);
	iSetColor(255,255,255);
	iText(820,650,"Time ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(895,650,": ",GLUT_BITMAP_TIMES_ROMAN_24);
	
	iText(910,650,secondsString,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(880,650,minutesString,GLUT_BITMAP_TIMES_ROMAN_24);
		

}
void setBackgroundLevel2()//setting Coordinates of the background for level 2 which is call from Main Function
{

	int sum=0;
	for(int i=0;i<51;i++)
		{
			background1[i].y1=439;
			background1[i].x1=sum;
			sum+=20;
		}

}
void changeBackgroundLevel2()//moving the background for level 2 which is call from iSetTimer
{
	
	for(int i=0;i<51;i++)
		{
		background1[i].x1-=20;
			if(background1[i].x1<0)
				{
					background1[i].x1=ScreenWidth;
				}
		}

}
void showBackgroundLevel2()//showing thebackground for level 2 which is call from doWork which is call from iDraw
{

	iShowBMP(0,0,"BackGround2\\lower.bmp");
	for(int i=0;i<51;i++)
		{
			iShowBMP(background1[i].x1,background1[i].y1,background2[i]);
		}

}
void SetGunman2()//Setting the Coordinates of the GunMan in level 2 Called From Main Function
{
	GunMan2.x1=GunManX;
	GunMan2.y1=GunManY;
	GunMan2.active1=true;
}
void GunManShow2()//call from doWork Function which call from iDraw when the option state is 1 for show the Gunman for level 2
{
	if(GunMan2.active1)
		{
			iShowBMP2(GunMan2.x1,GunMan2.y1, GunManNew, 255);
		}
}

void BulletShot2() // Called from isettimer in Main Function for Moving the Bullet Automatically after a certain time 
{
	for(int i = 0 ; i < bulletCount2 ; i++)
		{
			if(bullet1[i].hasActive1)
				{
					bullet1[i].y1 += 22;
					bullet1[i].x1+=30;
				}
		}
}


void bulletShow2()//call from doWork function which Call from iDraw function for Show the Bullet
{
	for(int i = 0; i < bulletCount2 ; i++)
		{
			if(bullet1[i].hasActive1== true )
				{
					iShowBMP2(bullet1[i].x1,bullet1[i].y1,"99.BMP",255);
				}
			if(bulletCount2==30 )
				{
					bullet1[bulletCount2-1].hasActive1=false;
				}
		}	
}


void CountBullet2()//count the Bullet when The bullet shoot 100 bullet then the gun reloaded with 100 bullet and it is call from SetBullet
{
	if(bulletCount2 < 20)
		{
			bulletCount2++;
		}
	if(bulletCount2<20)
	{
		if(pointCount==50)
		{
			gameOverState=-2;
		}
	}
}

void SetBullet2()//Setting bullet Coordinates and it is call for when we want to press any key or mouse button 
{
	CountBullet2();
	bullet1[bulletCount2-1].hasActive1 = true;
	bullet1[bulletCount2-1].y1 = GunMan2.y1 + 190;
	bullet1[bulletCount2-1].x1 = GunMan2.x1+125;
	
}

void setLife2()//setting the value of the coordinates of life picture and Called from main function
{
	life1[0].x1 = healthX-20;
	life1[0].y1 = healthY;
	life1[0].show1 = true;
	for (int i = 1 ; i < 3 ; i++)
	{
		life1[i].x1 = life1[i-1].x1 + 40;
		life1[i].y1 = healthY;
		life1[i].show1 = true;
	}
}

void showLife2()//showing the life picture called from doWork function which is called from iDraw
{	iSetColor(65,105,225);
	iFilledRectangle(healthX-85,healthY-5,190,40);
	iSetColor(255,255,255);
	iText(healthX-80,healthY+8,"Life:",GLUT_BITMAP_TIMES_ROMAN_24);
	for (int i = 0 ; i <healthPoint1 ; i++)
	{
		if (life1[i].show1)
		{
			iShowBMP2(life1[i].x1 , life1[i].y1, lifes,0);
		}
	}
		
}
void killBird2()//deactive the birds called from dowork which is called from idraw
{
	for (int i = 0; i < bulletCount2 ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if(bullet1[i].hasActive1 && bird[j].active)
						{
							if (bullet1[i].x1+25 >= bird[j].x && bullet1[i].x1+25 <= bird[j].x +70)
								{
									if (bullet1[i].y1+25 >= bird[j].y && bullet1[i].y1+25 <= bird[j].y + 70)
											{
												bird[j].active = false;
												bullet1[i].DeActive1=true;
												
												if(bird[j].active==false)
												{
													pointCount++;
												}
											}
								}
						}
				}
		}
	
}


void setSpecialFeature2()//Set the Coordinates of the Special Features in lvl 2 call from main function
{
	if(SpecialFeature1.active1==true)
	{
	SpecialFeature1.x1=(ScreenWidth-200)-rand()%600;
	SpecialFeature1.y1=ScreenHeight-100;
	}
}
void destroyLife1()//destroying Life which is call from doWork function which is call by iDraw Function
{
	
	for(int i = 0; i < bulletCount2 ; i++)
		{
			if(bullet1[i].hasActive1== true )
				{
					if(bullet1[i].DeActive1==false)	
						{
							if(bullet1[i].x1>ScreenWidth||bullet1[i].y1>ScreenHeight)
								{								
									healthPoint1--;
							printf("%d",healthPoint);	
							bullet1[i].hasActive1=false;
							}
						}

			}
		}
}



int s1 = rand() % 4;
void showSpecialFeature2()//show Special Feature in level 2 which is call from Dowork Function Which is Call from iDraw
{
	if(SpecialFeature1.active1)
	{
			
		iShowBMP2(SpecialFeature1.x1,SpecialFeature1.y1,special1[s1],255);
	
	}
	
}

void moveSpecialFeature2()//move the special features in level 2 called by iSetTimer
{

	SpecialFeature1.y1-=10;
	if(SpecialFeature1.y1 <= -2150)
	{
		s1 = rand() % 4;
		SpecialFeature1.x1=(ScreenWidth-200)-rand()%600;
		SpecialFeature1.y1 = 600;
		SpecialFeature1.active1=true;
		
	}

}

void random0()//if rand()%4==0 then in level 2 life up 
{
	
	if(GunMan2.active1==true && SpecialFeature1.active1==true)
		{
			if (SpecialFeature1.y1 <= GunMan2.y1 + 200 && SpecialFeature1.y1 >= GunMan2.y1 + 180)
				{
					if (SpecialFeature1.x1>= GunMan2.x1 && SpecialFeature1.x1<=GunMan2.x1 + 136)
						{
							SpecialFeature1.active1=false;
							if(SpecialFeature.active1==false && healthPoint1<3)
							{
									healthPoint1++;
							}
						}
				}

		}
		
}
void random1()//if rand()%4==1 then in level 2 life up Two
{
	
	if(GunMan2.active1==true && SpecialFeature1.active1==true)
		{
			if (SpecialFeature1.y1 <= GunMan2.y1 + 200 && SpecialFeature1.y1 >= GunMan2.y1 + 180)
				{
					if (SpecialFeature1.x1>= GunMan2.x1 && SpecialFeature1.x1<=GunMan2.x1 + 136)
						{
							SpecialFeature1.active1=false;
							if(SpecialFeature.active1==false && healthPoint1<3)
							{
									healthPoint1+=2;
							}
						}
				}

		}
	
}
void random2()//if rand()%4==2 then in level 2 life up 
{
	
	if(GunMan2.active1==true && SpecialFeature1.active1==true)
		{
			if (SpecialFeature1.y1 <= GunMan2.y1 + 200 && SpecialFeature1.y1 >= GunMan2.y1 + 180)
				{
					if (SpecialFeature1.x1>= GunMan2.x1 && SpecialFeature1.x1<=GunMan2.x1 + 136)
						{
							SpecialFeature1.active1=false;
							if(SpecialFeature.active1==false && healthPoint1<3)
							{
									healthPoint1++;
							}
						}
				}

		}
	
}
void random3()//if rand()%4==3 then in level 2 healthpoint=0 which is call from AddOrDestroyLife Function Which is Call from Dowork which call from iDraw
{
	
	if(GunMan2.active1==true && SpecialFeature1.active1==true)
		{
			if (SpecialFeature1.y1 <= GunMan2.y1 + 200 && SpecialFeature1.y1 >= GunMan2.y1 + 180)
				{
					if (SpecialFeature1.x1>= GunMan2.x1 && SpecialFeature1.x1<=GunMan2.x1 + 136)
						{
							SpecialFeature1.active1=false;
							if(SpecialFeature.active1==false && healthPoint1<=3)
							{
									healthPoint-=1;
							}
						}
				}

		}
	
	
	
}
void AddOrDestroyLife()//call from Dowork
{
	if(s1==0)
		random0();
	if(s1==1)
		random1();
	if(s1==2)
		random2();
	if(s1==3)
		random3();
}
void timeShow2()//showing the time Elapsed Call from doWork which is call from iDraw
{
	
	int endTime2=clock();
	
	timeElapsed2=120-(endTime2-startime)/1000;
	Second2=timeElapsed2%60;
	minute2=timeElapsed2/60;
	itoa(minute2,minutesString2,10);
    itoa(Second2,secondsString2,10);
	iSetColor(65,105,225);
	iFilledRectangle(805,640,140,40);
	iSetColor(255,255,255);
	iText(820,650,"Time ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(895,650,": ",GLUT_BITMAP_TIMES_ROMAN_24);
	
	iText(910,650,secondsString2,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(880,650,minutesString2,GLUT_BITMAP_TIMES_ROMAN_24);
		

}
void appendHighScore(char name[], int n)
{
	FILE *fp = fopen("D:\\HighScore.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%s\n", name);
		fprintf(fp, "%d\n", n);
	}

	fclose(fp);

}
void readHighScore()
{
	FILE *fp = fopen("D:\\HighScore.txt", "r");
	char str[100];

	if (fp != NULL)
	{
		while (fgets(str, 15, fp) != NULL)
		{
			strcpy(st[stringIndex++], str);
			fgets(str, 15, fp);
			numberArray[arrayIndex++] = atoi(str);
			
		}
	}

	fclose(fp);
}
void SortingHighScore()//Sorting the highScores and Call from showHighScore
{
	int temp;
	char t[100];

	for (int i = 0; i < arrayIndex - 1; i++)
	{
		for (int j = 0; j < arrayIndex - 1; j++)
		{
			if (numberArray[j] < numberArray[j + 1])
			{
				temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
				strcpy(t, st[j]);
				strcpy(st[j], st[j + 1]);
				strcpy(st[j + 1], t);
			}
		}
	}
	

}
void highScoreShow()//show the highScore call from doWork which is call from iDraw
{
	SortingHighScore();
	iClear();
	iShowBMP(0,0,"highScore.bmp");
	for (int k = 0,y=240; k < 6; k++, y-=50)
	{
		char str[100];
		itoa(numberArray[k], str, 10);
		iSetColor(0, 0, 255);
		iText(550, 50+y, str,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400, 50+y, st[k],GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
void showName()//when the game is over then Show Game Over page And Show Enter Your Name And When press the keyboard then Show the Letters in Screen And Called From DoWork which is call from IDraw
{
	iSetColor(255,255,255);
	iText(410, 550, "Enter Your Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(430, 500, nhigh,GLUT_BITMAP_TIMES_ROMAN_24);
}

void Dowork()//call from iDraw for All work
{
	
	if(gameState==-1)//home menu show
		{
			homeMenuShow();
		}
	else if(gameStateOver==-2)
	{
		
		gameOver();
		showName();
	
	}
	

	else if(gameState==0)//play the game 
	{
			gameState=1;
						
	}
	else if(gameState==1)//select the game level
		{
			if(OptionState==-1)
				{
					optionMenuShow();
				} 
			else if(OptionState==0)
				{
					if(bulletCount<30 && healthPoint>0 && timeElapsed>=0)
					{
						backgroundShow();
						bulletShow();
						GunManShow();
						showBird();
						killBird();
						pointShow();		
						showLife();	
						timeShow();
						destroyLife();
						showSpecialFeature();
						AddOrDestroyLife01();					
					}
					else
					{
						gameStateOver=-2;
						
					}
				}

				
			else if(OptionState==1)
				{
					if(bulletCount2<20 && healthPoint1>0 && timeElapsed2>=0)
						{
							showBackgroundLevel2();
							GunManShow2();
							showBird();
							bulletShow2();
							pointShow();
							showLife2();
							killBird2();
							showSpecialFeature2();
							AddOrDestroyLife();
							destroyLife1();
							timeShow2();
						}
					else
						{
							gameStateOver=-2;
						}	
				}
		}

	else if(gameState==2)//how to play the game 
		{
			iShowBMP(0,0,Help);
		}

	else if(gameState==3)//About the game
		{
			iShowBMP(0,0,About);
		}

	else if(gameState==4)//high Score of the players
		{
			
			highScoreShow();

		}

	else if(gameState==5)//exit from game if press exit 
		{			
			exit(0);
		}
	
	
						
	
		
}
void reset()//when game is over then All values Are reset call from iMouse when we press enter
{
	gameState=-1;
	gameStateOver=0;
	healthPoint = 5;
	healthPoint1 = 3;
	setBird();
	SetGunman();
	SetGunman2();
	SetBullet();
	OptionState = -1;
	nhigh[0] = '\0';
	pointCount = 0;
	bulletTimer = 0;
	bulletCount = 0;
	bulletCount2=0;
	timeElapsed2=0;
	arrayIndex = 0, stringIndex = 0;
	st[100][100];
	numberIndex = 0;
	nhigh[100];
	setSpecialFeature();
	setLife();
	setBird();
	setBack();
	setBackgroundLevel2();
	SetBullet2();
	setSpecialFeature2();
}

void iDraw()
{
	iClear();
	Dowork();
				
}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button ==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
		{
			for(int i=0;i<6;i++)
				{
					if(mx>=playMenu[i].x && mx<=playMenu[i].x+200	&& my>=playMenu[i].y && my<=playMenu[i].y+50 &&gameState==-1)
						{
							gameState=i;
							if (i == 4)
							{
								readHighScore();
							}
							
						}
					

					if(gameState==0)
						{
							if(homeMusicOn)
								{
									homeMusicOn=false;
									PlaySound(0,0,0);
								}
							else
								{
									if(playMusicOn)
										{
											PlaySound("Music\\play.wav",NULL,SND_LOOP|SND_ASYNC);
										}
								}

						}
					else if(gameState==1)
						{
							
							if(homeMusicOn)
								{
									homeMusicOn=false;
									PlaySound(0,0,0);
								}
							else
								{
									if(playMusicOn)
										{
											PlaySound("Music\\play.wav",NULL,SND_LOOP|SND_ASYNC);
										}
								}
							
							for(int j=0;j<2;j++)
								{
									if(mx>=optionMenu[j].x && mx<=optionMenu[j].x+200	&& my>=optionMenu[j].y && my<=optionMenu[j].y+53)
										{
											OptionState=j;	
											if ( j == 0)
											{
												startime = clock();
											}
											if(j==1)
											{
												startime= clock();
											}
										
										}
								}
						}
					
				}

		}
	
	
	if (button ==GLUT_RIGHT_BUTTON && state == GLUT_DOWN && OptionState==0 )
		{
				SetBullet();
		}
}

void iKeyboard(unsigned char key)
{
	
	if(key=='r' && (gameState==2 || gameState==3||gameState==4 ))
		{
			gameState=-1;	
		}
	if(key == 'r' && gameState==1)
		{
			gameState=-1;
		}
	if(key==27 && (gameState==0||gameState==1||gameState==2||gameState==3||gameState==4))
		{
			exit(0);
		}
	if(key=='w')
		{	if(OptionState==0)
				{
				SetBullet();
				}
			if(OptionState==1)
				{
					SetBullet2();
				}
		}

	if(key=='d')
		{
			if(OptionState==0)
				{
					if(GunMan.x<865 && GunMan.active==true)
						{
						GunMan.x += 20;
						}
					else
						{
						GunMan.active=true;
					
						GunMan.x=865;	
						}
			
				}
		
			if(OptionState==1)	
				{
					if (GunMan2.x1 <865 && GunMan2.active1==true )
						{
							GunMan2.x1 += 20;

						}
					else
						{ 
							GunMan2.active1=true;
							GunMan2.x1=865;
						}
				}
	
		}

	if(key=='a')
		{
			if(OptionState==0)
				{
					if (GunMan.x > 0 && GunMan.active==true )
						{
							GunMan.x -= 20;

						}
					else
						{ 
						GunMan.x=0;
						}
				}
			 if(OptionState==1)	
				{
					if (GunMan2.x1 > 0 && GunMan2.active1==true )
						{
							GunMan2.x1 -= 20;

						}
				else
						{ 
							GunMan2.x1=0;
						}
				}

		}
	if(key=='r' && (OptionState==1||OptionState==2))
	{
		OptionState=-1;
	}
	if(key== ' ')
	{
		if(OptionState==0){
		SetBullet();
		}
		if(OptionState==1){
			SetBullet2();
		}

	}
	if(gameStateOver==-2)
	{
		char chr;
		if ((chr = key) != '\r')
		{
			nhigh[numberIndex++] = chr;
			nhigh[numberIndex] = '\0';
			if (chr == '\b' && numberIndex >= 2)
			{
				numberIndex--;
				nhigh[--numberIndex] = '\0';
			}
		}
		if (key == '\r')
		{
			appendHighScore(nhigh, pointCount);
			//highScoreShow();
			reset();
				
		}
	}
	
}


void iSpecialKeyboard(unsigned char key)
{
	if (key ==  GLUT_KEY_UP){
		if(OptionState==0)
		{
			SetBullet();
		}
		if(OptionState==1)
		{
			SetBullet2();
		}
	}

	if (key == GLUT_KEY_RIGHT)
		{
			if(OptionState==0){
			if(GunMan.x<865 && GunMan.active==true)
				{
					GunMan.x += 20;
					
				}
			}
			else
			{
				GunMan.active=true;
				GunMan.x=865;
				
			}	
			if(OptionState==1)
			{	
			if(GunMan2.x1<865 && GunMan.active==true)
				{
					GunMan2.x1 += 20;
					
				}
			
			else
			{
				GunMan2.active1=true;
				GunMan2.x1=865;
				
			}	
	

			}
			
		}	

	if (key == GLUT_KEY_LEFT)
		{
			if(OptionState==0){
			if (GunMan.x > 0 && GunMan.active==true)
				{	
					GunMan.x -= 20;
					
				}
			
			else 
				{
					GunMan.active=true;
					GunMan.x=0;
					
				}
			}
			if(OptionState==1){
			if (GunMan2.x1 > 0 && GunMan2.active1==true)
				{	
					GunMan2.x1 -= 20;
					
				}
			
			else 
				{
					GunMan2.active1=true;
					GunMan2.x1=0;
					
				}
			}
		}
	if (key ==  GLUT_KEY_END)
		{
			exit(0);
		}
}

int main()
{	
	srand(time(NULL));
	startTime=clock();
	SpecialFeaturesTimer = iSetTimer(90,moveSpecialFeature);
	setHomeMenu();
	setOptionMenu();
	setLife();
	setBack();
	birdTimer=iSetTimer(5, moveBird);
	BackGroundTimer=iSetTimer(1000,changeback);	
	bulletTimer = iSetTimer(150,BulletShot);
	setBird();
	SetGunman();
	setSpecialFeature();
	setBackgroundLevel2();
	SetGunman2();
	BackGroundTimer2=iSetTimer(1000,changeBackgroundLevel2);
	bullet2Timer=iSetTimer(150,BulletShot2);
	setLife2();
	setSpecialFeature2();
	SpecialFeature2Timer=iSetTimer(90,moveSpecialFeature2);

	

	if(homeMusicOn)
		{
			PlaySound("Music\\home.wav",NULL,SND_LOOP|SND_ASYNC);
		}
	iInitialize(ScreenWidth,ScreenHeight, "Bird Shooter ZAS");
	return 0;
	
}
