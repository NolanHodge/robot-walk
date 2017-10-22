#include "network_ring.hh"

network_ring::network_ring() 
{
    // Do Nothing
}

// Move a robot on the ring, if a collision happens, merge robots.
int network_ring::move_ring_point(robot *r)
{
	ring[r->get_location()].lock.unlock();
	ring[r->get_location()].r = NULL;

	int new_location = normalize_location(r);
	if (ring[new_location].lock.try_lock())
	{
		ring[new_location].r = r;
	}
	else 
	{
		r = ring[new_location].r;
		ring[new_location].r->on_collision();
		return -1;
	}
	return new_location;
}

int network_ring::normalize_location(robot *r)
{
	switch (r->get_direction())
	{
	case LEFT:
		return (r->get_location() - r->get_speed()) % POINT_COUNT;
	case RIGHT:
		return (r->get_location() + r->get_speed()) % POINT_COUNT;
	}
}

int network_ring::get_point_count()
{
	return POINT_COUNT;
}