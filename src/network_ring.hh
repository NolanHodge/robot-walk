#ifndef NETWORK_RING_H
#define NETWORK_RING_H
#endif

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <mutex>

#include "robot.hh"
#include "configs.hh"

class network_ring 
{
    public:
        network_ring();
        int move_ring_point(robot*);
		int* get_robot_positions();
		int robot_count;
	private:
		int normalize_location(robot*);
        void draw_ring();
        
    private:
        struct ring_point 
        {
			std::mutex lock;
		    bool has_robot;
            robot *r;
		};
        ring_point ring[POINT_COUNT];
};
