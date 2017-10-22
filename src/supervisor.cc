#include "supervisor.hh"

supervisor::supervisor(network_ring *n)
{
	for (int i = 0; i < ROBOT_COUNT; i++) {
		int location = select_random_location();
		robots[i] = new robot(location);
	}
	ring = n;
	round_count = 0;
}

void supervisor::execute()
{
	for (int i = 0; i < ROBOT_COUNT; i++) {
		walk(robots[i]);
	}
}

int supervisor::get_robot_count()
{
	return ROBOT_COUNT;
}

// Select a random location on the ring
int supervisor::select_random_location()
{
	return rand() % ring->get_point_count();
}

void supervisor::walk(robot *r)
{
	while (true)
	{
		r->set_location(ring->move_ring_point(r));

		if (r->get_location() == -1)
		{
			return; // were done here
		}
		_sleep(500);
	}
}