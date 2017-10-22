#include <stdlib.h>
#include "network_ring.hh"
#include "robot.hh"
#include "configs.hh"


class supervisor
{
public:
	supervisor(network_ring*);
	robot *robots[ROBOT_COUNT];
	network_ring *ring;
	void execute();
	int get_robot_count();
	int select_random_location();
	void walk(robot *r);
	int round_count;
};
