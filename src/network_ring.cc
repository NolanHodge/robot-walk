#include "network_ring.hh"

network_ring::network_ring() 
{
    // Do Nothing
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
        ring[new_location].r->increase_size(r->get_size());
        ring[new_location].r->reset_steps_taken();
		ring[new_location].r->on_collision();
		return -1;
	}
    draw_ring();
    return new_location;
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
