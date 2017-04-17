#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../Character/Player.h"
#include "../HelperClasses/List.h"
#include "../HelperClasses/HelperFunctions.h"
#include "../quickcg.h"
using namespace QuickCG;

#define screenWidth 800
#define screenHeight 600

#define texWidth 64
#define texHeight 64

#define mapWidth 30
#define mapHeight 30

#define numTextures 26

enum Textures
{
	ShipWallRaised, ShipWallStraight, ShipWallBloodRaised, ShipWallBloodStraight, ShipWallBloodStraight2,
	ShipWallCircuit, ShipWallPort, ShipWallWindowLeft, ShipWallWindowRight, ShipWallWindow, ShipGrate,
	ShipGrateBottomLeft, ShipGrateBottomRight, ShipGrateTopLeft, ShipGrateTopRight, ShipRoomFloor, ShipRoomFloorBlood2,
	ShipRoomFloorBlood, ShipCeiling, ShipCeilingLatch,

	CaveCeiling, CaveWall, CaveWallMushroom, CaveWallMushroom2, CaveFloor, TestSprite
};

typedef struct mapTile
{
	int floor;
	int object;
	int ceiling;
}mapTile;

typedef struct sprite
{
	double x, y;
	int texture;
} Sprite;

#define numSprites 1

class Game
{
public:
	Game(int width = screenWidth, int height = screenHeight);

	int getWidth() const { return mScreenWidth; }
	int getHeight() const { return mScreenHeight; }

	void setWidth(const int width) { mScreenWidth = width; }
	void setHeight(const int height) { mScreenHeight = height; }

	void RunGame(std::string mapName);
private:
	Player mPlayer;
	double mFrameTime;
	int mScreenWidth, mScreenHeight;
	std::vector<Uint32> mTextures[numTextures];
	Uint32 mBuffer[screenHeight][screenWidth];

	//1D Zbuffer
	double mZBuffer[screenWidth];

	//arrays used to sort the sprites
	int spriteOrder[numSprites];
	double spriteDistance[numSprites];
	bool mQuit;

	mapTile mMap[mapWidth][mapHeight];

	List<Character *> mEnemies;
	List<Sprite> mDoors,
			  	 mPickups;
	Sprite sprite[numSprites] =
	{
	  {5, 5, TestSprite}
	};

	//function used to sort the sprites
	void combSort(int* order, double* dist, int amount);

	void loadMap(std::string mapName);

	void LoadTextures();

	void Render();
	void CheckQuit();

	void DrawSprites();

	void UpdateMovement();
	void UpdateRotation(float deltaMouse);

	// Friend Functions
	friend Vector2<int> Raycast(Vector2<int> &rayPos, Vector2<double> &rayDir, int &hit, int &side);
};
