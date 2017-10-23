#include "ui.hh"

void ui::draw()
{
    int center = 100;
    for (int i = 0; i < POINT_COUNT/2; i++)
	{
        int left = i;
        int right = POINT_COUNT-i;
        printf("%d  %50d\n",left,right);
    }
    printf("'%5d'", center);    
}
