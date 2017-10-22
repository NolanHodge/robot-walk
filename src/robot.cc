#include "robot.hh"

// Ctor
robot::robot(int l)
{
	direction = change_direction();
	location = l;
	speed = SPEED;
}

// Flip a fair coin; heads or tails
int robot::flip_coin() 
{
	return rand() % 2;
}

// Change the direction the robot walks based on 
int robot::change_direction()
{
	return flip_coin();
}

// When we collide with another robot
// Increase the size of the robot and flip another fair coin
int robot::on_collision()
{
	size++;
	direction = change_direction();
}

int robot::get_location()
{
	return location;
}

int robot::get_speed()
{
	return speed;
}

int robot::get_direction()
{
	return direction == LEFT ? LEFT : RIGHT;
}

int robot::set_location(int new_location)
{
	location = new_location;
}
