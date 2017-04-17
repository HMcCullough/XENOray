//Shoutout to WL_DEF.H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "quickcg.h"

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
