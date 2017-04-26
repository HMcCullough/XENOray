#include "Projectile.h"

Projectile::Projectile(double posX, double posY, double directionX, double directionY, double speed, int damage, int texture):
	Object(posX, posY, directionX, directionY, texture, false)
{
	mDamage = damage;
	mSpeed = speed;
}

Projectile::Projectile(Vector2<double> pos, Vector2<double> dir, double speed, int damage, int texture):
	Object(pos, dir, texture, false)
{
	mDamage = damage;
	mSpeed = speed;
}

int Projectile::getDamage(){return mDamage;}
void Projectile::setDamage(int newDamage){mDamage = newDamage;}

double Projectile::getSpeed() {return mSpeed;}
void Projectile::setSpeed(double newSpeed){mSpeed = newSpeed;}

void Projectile::Move(Vector2<double> dir) { Move(dir.x, dir.y); }
void Projectile::Move(double x, double y) // Direction
{
	if (x != mDirection.x || y != mDirection.y)
		setDirection(x, y);
	setPosition(mSpeed * mDirection);
}