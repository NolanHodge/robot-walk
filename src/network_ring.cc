#include "network_ring.hh"

network_ring::network_ring() 
{
    // Do Nothing
    for ( int i=0; i<POINT_COUNT; i++ ) 
    {
        std::cout << ring[i] << std::endl;
    }
}

void network_ring::move_ring_point(int speed, int position)
{
    while ( !ring_access_mutex )
    {
        //sleep(1);
    }
    ring[position].robot_count--;
    ring[(position + speed)%POINT_COUNT]++;
}

int main()
{
}
