#include "network_ring.hh"

network_ring::network_ring() 
{
    // Do Nothing
}

// Move a robot on the ring, if a collision happens, merge robots.
int network_ring::move_ring_point(robot *r)
{
	ring[r->get_location()].size = 0;
	ring[r->get_location()].lock.unlock();

	int new_location = normalize_location(r);
    if (ring[new_location].lock.try_lock())
	{
		ring[new_location].r = r;
	    ring[r->get_location()].r = NULL;
	}
	else 
	{
	    ring[new_location].r->reset_steps_taken();
		ring[new_location].r->on_collision();
		return -1;
	}
	return new_location;
}

// Normalize the location of the robot to keep it within the boundaries of the ring
int network_ring::normalize_location(robot *r)
{
	switch (r->get_direction())
	{
	case LEFT:
        return ( (r->get_location() - r->get_speed()) % POINT_COUNT + POINT_COUNT) % POINT_COUNT;
	case RIGHT:
		return (r->get_location() + r->get_speed()) % POINT_COUNT;
	}
}
