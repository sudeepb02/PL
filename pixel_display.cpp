#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

	setcolor(getmaxcolor());
	xmax = getmaxx();
	ymax = getmaxy();

	cout<<"Displaying pixel at co-ordinate :("<<xmax/2<<" "<<ymax/2<<" )\n";
	
	putpixel(xmax/2,ymax/2,15);
	getch();
	closegraph();
	return 0;
}

