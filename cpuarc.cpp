
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

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
  // xmax = getmaxx();
  // ymax = getmaxy();

   /* draw a diagonal line */

	rectangle(100,70,200,270);	//Mem
	outtextxy(125,170,"MEMORY");

	rectangle(200,100,270,130);          //Arrow
	line(270,100,265,95);
	line(270,100,265,105);

	line(200,130,205,125);
	line(200,130,205,135);

	rectangle(200,200,270,230);          //arrow
	line(270,200,265,195);
	line(270,200,265,205);

	line(200,230,205,225);
	line(200,230,205,235);

	rectangle(270,50,400,150);       	//alu
	outtextxy(300,60,"ALU");
	rectangle(280,80,320,140);
	rectangle(280,80,320,90);
	rectangle(280,80,320,100);
	rectangle(280,80,320,110);
	rectangle(280,80,320,120);
	rectangle(280,80,320,130);

	rectangle(340,140,380,110);//AC
	outtextxy(350,125,"AC");



	rectangle(270,180,400,280);          //pcu
	outtextxy(320,270,"PCU");

	rectangle(320,180,350,150);
	line(320,180,315,175);
	line(320,180,325,175);

	line(350,150,345,155);
	line(350,150,355,155);


	rectangle(280,190,320,220);
	outtextxy(290,205,"IR");

	rectangle(350,190,390,220);
	outtextxy(360,205,"PC");

	//rectan

   /* clean up */
   getch();
   closegraph();
   return 0;
}

