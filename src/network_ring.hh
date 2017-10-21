#include <iostream>
#include <sstream>
#include <stdlib.h>

#define POINT_COUNT 100

class network_ring 
{
    public:
        network_ring();

        struct ring_point 
        {
            int robot_count;
        };
        
        int ring_access_mutex; 
        ring_point ring[POINT_COUNT];

        void move_ring_point(int, int);
};
