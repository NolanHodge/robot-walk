#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#endif

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <chrono>

#include "network_ring.hh"
#include "configs.hh"

class supervisor
{
    public:
	    supervisor();
    	robot *robots[ROBOT_COUNT];
	    network_ring *ring;
    	void execute();
    	int select_random_location();
		int* get_robot_positions();
		int get_robot_count();
    	void walk(robot *r);
    	int round_count;
		int rendezvouz_count;
		int* get_robot_sizes();
		void log(std::string, robot *r);
		int total_steps_taken;
};
