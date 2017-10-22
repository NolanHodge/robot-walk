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

        struct ring_point 
        {
			std::mutex lock;
			robot *r;
            int size;
		};
        ring_point ring[POINT_COUNT];

        int move_ring_point(robot*);
		int get_point_count();

	private:
		int normalize_location(robot*);
};
