#include "supervisor.hh"
#include "configs.hh"

int main(int argc, char* argv[])
{
	for (int i=0; i<50; i++) {
	    supervisor sup;
	 	sup.execute();
		std::cout << sup.total_steps_taken << ", ";
	}
	std::cout << "num robots : " << ROBOT_COUNT << std::endl;
	std::cout << "ring size  : " << POINT_COUNT << std::endl;
}
