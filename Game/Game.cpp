#include "Game.h"

Game::Game(int width, int height)
{
	setWidth(width);
	setHeight(height);

	mQuit = mIsBossLevel = false;
	mNumEnemies = 0;
	mNumProjectiles = 0;
}

Game::~Game()
{
	for (int i = 0; i < numSounds; ++i)
		if (mSounds.at(i) != nullptr)
			Mix_FreeChunk(mSounds.at(i));
	for ( int i = 0; i < numSongs; ++i)
		if (mSongs.at(i) != nullptr)
			Mix_FreeMusic(mSongs.at(i));
}

void Game::RunGame()
{
	LoadSounds();
	LoadTextures();
	InitPlayer();
	mPlayer.setAmmo(100);
}

void Game::Play(std::string mapName, Songs song)
{
	LoadMap(mapName);
	LoadEnemies(mapName);

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	mPlayer.setHealth(100);

	float deltaMouse = 0.0f;

	playSong(mSongs[song]);

	mQuit = false;
	while(!mQuit)
	{	
		int oldmx, oldmy;
		SDL_GetMouseState(&oldmx, &oldmy);

		readKeys();
		if (keyPressed(SDLK_TAB))
			if(!mMini)
				mMini = true;
			else
				mMini = false;

		Render();
		DrawCrosshair();
		PrintHUD();
		if(mMini)	
			DrawMap();

		//timing for input and FPS counter
		oldTime = time;
		time = getTicks();
		mFrameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		//print(1.0 / mFrameTime); //FPS counter
		//print(mObjects.size(), 0, 20);

		readKeys();
		UpdateRotation(deltaMouse);
		UpdateMovement();
		CheckShoot();
		CheckHit();
		CheckPickup();
		//this will be removed in final build
		CheckQuit();
		CheckPause();
		if (mIsBossLevel)
		{
			if (dynamic_cast<Boss *>(mObjects.at(0))->Update())
			{
				mObjects.deleteAt(0);
				mNumEnemies--;
			}
		}

		if(CheckWin()) { break; }

		if(mPlayer.isDead())
		{
			CutsceneManager cm;

			cm.PlayRange(GAMEOVER1, GAMEOVER5, false, "Music/SoundOfAndy.wav", 2000);
			mQuit = true;
		}
		
		//who the heck made these ints defined in the while loop
		int mx, my;
		SDL_GetMouseState(&mx, &my);

		deltaMouse = mx - oldmx;
		deltaMouse /= 1000.0f;

		SDL_WarpMouse(screenWidth/2, screenHeight/2);
		SDL_ShowCursor(0);

		redraw();
		//std::cout << mEnemies[0].isVisible() << " " << mEnemies[1].isVisible() << std::endl;
	}

	// Clear the list and reset the counters when a level is over
	mObjects.clear();
	mNumEnemies = 0;
	mNumProjectiles = 0;
}

void Game::setPlayerPos(double posX, double posY)
{
	mPlayer.setPosition(posX, posY);
}