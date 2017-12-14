#include "supervisor.hh"

// Ctor
supervisor::supervisor()
{
	ring = new network_ring();
	for (int i = 0; i < ROBOT_COUNT; i++) 
    {
		int location = select_random_location();
		robots[i] = new robot(location);
	}
	round_count = 0;
	rendezvouz_count = 0;
	total_steps_taken = 0;
}

// Select a random location on the ring
int supervisor::select_random_location()
{
	prandom r;
	return r.get_random_number(POINT_COUNT);
}

int* supervisor::get_robot_sizes() 
{
	int *sizes = (int*)malloc(sizeof(int)*ROBOT_COUNT);
	for (int i=0; i<ROBOT_COUNT; i++) 
	{
		sizes[i] = robots[i]->get_size();
	}
	return sizes;
}

// Place the robot on the ring and command robot to walk
void supervisor::walk(robot *r)
{
    std::string s1("is now walking ");
    std::string s2((r->get_direction() == LEFT ? "LEFT" : "RIGHT"));
    log(s1 + s2, r);
	while (true)
	{
		if (r->get_size() == ROBOT_COUNT) 
        {
			rendezvouz_count++;
			log("is the final robot", r);
			total_steps_taken += r->get_steps_taken();
            return;
		}	
        r->set_location(ring->move_ring_point(r));
        r->increase_steps_taken();
		total_steps_taken++;
		if (r->get_location() == -1)
		{
            log("has collided", r);
			rendezvouz_count++;
            return; // were done here
		}
		if (r->get_steps_taken() == POINT_COUNT/2) 
		{
			r->change_direction();
		}
		log("has moved", r);
        std::this_thread::sleep_for(std::chrono::milliseconds(UI_SPEED));
	}
}

// Main thread of execution
// Places robots into individual threads
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

int* supervisor::get_robot_positions() {
	int *robot_positions = (int*)malloc(sizeof(int)*ROBOT_COUNT);
	int i = 0;
    for (robot *r : robots)
    {
		robot_positions[i++] = r->get_location();
	}
	return robot_positions;
}

int supervisor::get_robot_count() {
	return ring->robot_count;
}
// Log the output for each robot
void supervisor::log(std::string s, robot *r)
{
    LOG_CHECK;
    std::cout << "[Robot:" << r->get_id() << " Size:" << r->get_size() << " Location:" << r->get_location() << " Steps Taken: " << r->get_steps_taken() <<  "] " << s << std::endl;
}
