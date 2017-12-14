#ifndef ROBOT_H
#define ROBOT_H
#endif

#include <stdlib.h>
#include <random>
#include <mutex>

#include "configs.hh"
#include "prandom.hh"

class robot
{
	// Functions
	public:
		robot(int);
		void walk();
		void on_collision();
		int get_direction();
		int get_location();
		int set_location(int);
		int increase_size(int);
		int get_size();
        int get_id();
        int get_steps_taken();
        void increase_steps_taken();
        void reset_steps_taken();
		int change_direction();
		void flip_direction();

	private:
		int flip_coin();
	    int generate_random_id();
        
	// Variables
	private:
		int direction;
		int speed;
		int size;
		int location;
        int id;
        int steps_taken;

	public:
		int on_round;
		int last_token_seen;
};
