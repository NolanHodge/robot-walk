#include <stdlib.h>
#include "configs.hh"

class robot
{
	// Functions
	public:
		robot(int);
		void walk();
		void on_collision();
		int get_speed();
		int get_direction();
		int get_location();
		int set_location(int);
		int get_size();

	private:
		int flip_coin();
		int change_direction();
	
	// Variables
	private:
		int direction;
		network_ring *ring;
		int speed;
		int size;
		int location;

	public:
		int on_round;
};
