#include "supervisor.hh"

supervisor::supervisor()
{
    network_ring *r = new network_ring();
	for (int i = 0; i < ROBOT_COUNT; i++) 
    {
		int location = select_random_location();
		robots[i] = new robot(location);
	}
	ring = r;
	round_count = 0;
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
    log("is now walking..", r);
    while (true)
	{
		r->set_location(ring->move_ring_point(r));
        log("has moved", r);
        
		if (r->get_location() == -1)
		{
            log("has collided", r);
            return; // were done here
		}
        sleep(500);
	}
}

void supervisor::execute()
{
    for (robot *r : robots)
    {
        log("has been dropped", r);
		std::thread _t(&supervisor::walk, this, r);
        _t.detach();
	}
    while (true)
    {
    }
}

void supervisor::log(std::string s, robot *r)
{
    std::cout << "[Robot:" << r->get_id() << " Location:" << r->get_location() << "] " << s << std::endl;
}
