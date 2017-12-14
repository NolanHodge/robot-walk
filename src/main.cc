#include "supervisor.hh"
#include "configs.hh"

int main(int argc, char* argv[])
{
	supervisor sup;
	sup.execute();
	
	std::cout << "steps taken : " << sup.total_steps_taken << std::endl;
	std::cout << "num robots : " << ROBOT_COUNT << std::endl;
}
