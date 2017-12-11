#include "supervisor.hh"
#include "configs.hh"

int main()
{
	clock_t start = clock();
    
    supervisor sup;
 	sup.execute();

    clock_t end = clock();
    clock_t ticks = end - start;

    std::cout << ticks / (double) CLOCKS_PER_SEC << std::endl;
}
