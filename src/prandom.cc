#include "prandom.hh"

std::mt19937 mt_rand(time(0));

prandom::prandom() {
	// Do nothing
}

int prandom::get_random_number(int modu) {
	return mt_rand() % modu;
}
