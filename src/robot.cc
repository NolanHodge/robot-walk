#include "robot.hh"

// Ctor
robot::robot(int l)
{
	direction = change_direction();
	location = l;
	speed = SPEED;
    generate_random_id();
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
void robot::on_collision()
{
	size++;
	direction = change_direction();
}

int robot::generate_random_id()
{
    id = rand();
}

int robot::get_id()
{
    return id;
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
