#include "supervisor.hh"

// Ctor
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

// Select a random location on the ring
int supervisor::select_random_location()
{
	return rand() % ring->get_point_count();
}

// Place the robot on the ring and command robot to walk
void supervisor::walk(robot *r)
{
    std::string s1("is now walking ");
    std::string s2((r->get_direction() == LEFT ? "LEFT" : "RIGHT"));
    log(s1 + s2, r);
    while (true)
	{
        if (r->get_steps_taken() == POINT_COUNT) 
        {
            log("is the final robot", r);
            return;
        }
        r->set_location(ring->move_ring_point(r));
        r->increase_steps_taken();
         
		if (r->get_location() == -1)
		{
            log("has collided", r);
            return; // were done here
		}
        log("has moved", r);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

// Main thread of execution
// Places each robot into a single thread
void supervisor::execute()
{
    std::thread threads[ROBOT_COUNT];
    int i = 0;
    for (robot *r : robots)
    {
        log("has been dropped", r);
		threads[i++] = std::thread(&supervisor::walk, this, r);
    }
    for (int i=0; i<ROBOT_COUNT; i++)
    {
        threads[i].join();
    }
}

// Log the output for each robot
void supervisor::log(std::string s, robot *r)
{
    std::cout << "[Robot:" << r->get_id() << " Location:" << r->get_location() << " Steps Taken: " << r->get_steps_taken() <<  "] " << s << std::endl;
}
