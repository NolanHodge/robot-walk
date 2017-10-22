#include "network_ring.hh"
#include "robot.hh"
#include "supervisor.hh"
#include "configs.hh"

int main()
{
	network_ring *ring = new network_ring;
	supervisor sup(ring);
	sup.execute();
}