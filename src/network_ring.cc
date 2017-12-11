#include "network_ring.hh"

int move_count = 0;
int robot_positions[ROBOT_COUNT];

network_ring::network_ring() 
{
	robot_count = ROBOT_COUNT;
}

// Move a robot on the ring, if a collision happens, merge robots.
// A collison has happend when a robot tries to to move to a ring point
// already occupied by another robot.
// In such case the robots "merge" into a robot of size = (robot1.size + robot2.size).
int network_ring::move_ring_point(robot *r)
{
	ring[r->get_location()].has_robot = false;
    ring[r->get_location()].lock.unlock();
    
	int new_location = normalize_location(r);
    if (ring[new_location].lock.try_lock())
	{
		ring[new_location].r = r;
        ring[new_location].has_robot = true;
	    ring[r->get_location()].r = NULL;
	}
	else 
	{
		robot_count--;    	
		ring[new_location].r->increase_size(r->get_size());
        ring[new_location].r->reset_steps_taken();
		ring[new_location].r->on_collision();
		return -1;
	}
	draw_ring();
    return new_location;
}

int* network_ring::get_robot_positions() {
	return robot_positions;
}

// Normalize the location of the robot to keep it within the boundaries of the ring
int network_ring::normalize_location(robot *r)
{
	switch (r->get_direction())
	{
	case LEFT:
        return ( (r->get_location() - ROBOT_SPEED) % POINT_COUNT + POINT_COUNT) % POINT_COUNT;
	case RIGHT:
		return (r->get_location() + ROBOT_SPEED) % POINT_COUNT;
	}
}

void network_ring::draw_ring()
{
	UI_CHECK;
	if (move_count == robot_count) 
	{
		move_count = 0;
	} 
	else 
	{
		move_count++;
		return;
	}
	if (DRAW_ASCII) 
	{
		std::string s = "\r";
	    for (int i=0; i<POINT_COUNT; i++)
	    {
	        s+="-[";
	        if (ring[i].has_robot)
	        {
	            s+="X";
	        }
	        else
	        {
	            s+=" ";
	        }
	        s+="]-";
    	}
	    std::cout << s;
	    fflush(stdout);
	}
	int robot_counter = 0;
	if (DRAW_OPENGL) {
		for (int i=0; i<POINT_COUNT; i++)
	    {
	        if (ring[i].has_robot)
	        {
				robot_positions[robot_counter++] = i;
	        }
    	}
	}
}
