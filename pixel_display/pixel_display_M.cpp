#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");


   int xmax = getmaxx();
   int ymax = getmaxy();
   int x1,y1;
   int i,j;
   x1 = xmax/3;
   y1 = ymax/3;

	for(i=0;i<100;i++)
	{
		putpixel(x1,y1,15);
	      //	x1++;
		y1--;
		delay(10);
	}
	for(i=0;i<40;i++)
	{
	   putpixel(x1,y1,15);
	   x1++;
	   y1++;
	   delay(10);
	}
	for(i=0;i<40;i++)
	{
		putpixel(x1,y1,15);
		x1++;
		y1--;
		delay(10);
	}
	for(i=0;i<100;i++)
	{
		putpixel(x1,y1,15);
	      //	x1++;
		y1++;
		delay(10);
	}

   /* clean up */
   getch();
   closegraph();
   return 0;
}

