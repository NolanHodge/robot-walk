#include "robot.hh"

// Ctor
robot::robot(int l)
{
	direction = change_direction();
	location = l;
    generate_random_id();
    steps_taken = 0;
    size = 0;
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

// Generate a random ID for the robot
int robot::generate_random_id()
{
    id = rand();
}

// Reset the amount of steps a robot has taken
void robot::reset_steps_taken()
{
    steps_taken = 0;
}

// Increment the amount of steps taken based on the speed of the robot
void robot::increase_steps_taken()
{
    steps_taken+=ROBOT_SPEED;
}

// Public accessor for the amount of steps a robot has taken
int robot::get_steps_taken()
{
    return steps_taken;
}

// Public accessor for the robots ID
int robot::get_id()
{
    return id;
}

// Public accessor for the robots size
int robot::get_size()
{
    return size;
}

// Increment the size of the robot based on the size of the collided robot
int robot::increase_size(int robot_size)
{
    size += robot_size;
}

// Get the current location of the robot
int robot::get_location()
{
	return location;
}

// Get the direction the robot is travelling in
int robot::get_direction()
{
	return direction == LEFT ? LEFT : RIGHT;
}

// Set a new location for the robot
int robot::set_location(int new_location)
{
	location = new_location;
}
