#include "ui.hh"

void ui::draw(network_ring *ring)
{
	for (int i = 0; i < POINT_COUNT; i++)
	{
		if (ring->ring[i].r != NULL )
		{
			std::cout << "R:" << ring->ring[i].r->get_size() << " -- ";
		}
		else
		{
			std::cout << " R:0 -- ";
		}
	}
}