#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int i, maxx, maxy;

   /* our polygon array */
   int poly[12];
   int tri[8];

   /* initialize graphics, local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
      /* terminate with an error code */
   }

   maxx = getmaxx();
   maxy = getmaxy();

   poly[0] = maxx/2;  /* 1st vertex */
   poly[1] = maxy -50;

   poly[2] = maxx/2 +20;
   poly[3] = maxy -50;

   poly[4] = maxx/2 + 20;
   poly[5] = maxy -100;

   poly[6] = maxx / 2;
   poly[7] = maxy - 100;

   poly[8] = poly[0];
   poly[9] = poly[1];

   /* loop through the fill patterns */
 //  for (i=EMPTY_FILL; i<USER_FILL; i++)
   //{
      /* set fill pattern */
    //  setfillstyle(SOLID_FILL, getmaxcolor());

      /* draw a filled polygon */
     fillpoly(5,poly);

      //	 getch();
 //  }

// drawpoly(5,poly);
  getch();

   /* clean up */
   closegraph();
   return 0;
}
