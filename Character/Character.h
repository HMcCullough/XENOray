#pragma once
#include "../Objects/Object.h"
#include <SDL/SDL.h>

//Takes from object, describes "living" objects
class Character : public Object
{
public:
	Character(int health, double speed, double posX, double posY, double directionX, double directionY, int texture);
	Character(int health, double speed, Vector2<double> pos, Vector2<double> dir, int texture);

	~Character();

	virtual void TakeDamage(int damage) = 0;
	virtual void Move(double x, double y); // x and y represent the new position vector components
	virtual void Shoot() = 0;

	int getHealth() const;
	double getSpeed() const;

	void setHealth(int health);
	void setSpeed(double speed);
	
	void setDamageSound(Mix_Chunk *damageSound);
	void setDeathSound(Mix_Chunk *deathSound);
	void setShootSound(Mix_Chunk *shootSound);

	int getMaxHealth();
	void setMaxHealth(const int &maxHealth); 
	//Used to get ammo reward, could be used for more

	bool isDead(); //Hugely useful for sound, animation and other logic

protected:
	virtual void Die() = 0;

	Mix_Chunk *mDamageSound = nullptr,
			  *mTauntSound = nullptr,
			  *mDeathSound = nullptr,
			  *mShootSound = nullptr;

	int mHealth;
	int mMaxHealth;

	double mSpeed;
	bool mIsDead;
};
