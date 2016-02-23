#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

class line1
{
protected:
	int x1,y1,x2,y2;
public:
	void getdata();
	line1();
};

class circle1:public line1
{
	int radius;
	int x0,y0;
public:
	circle1();
	void cradius();
	void brescircle();
};
void line1::getdata()
{
	cout<<"Enter starting point (x1,y1)\n";
	cin>>x1>>y1;

	cout<<"Enter end point (x2,y2)\n";
	cin>>x2>>y2;
}
line1::line1()
{
	x1 = y1 = x2 = y2 = 0;
}
circle1::circle1()
{
	x0 = y0 = radius = 0;
}
void circle1::cradius()
{
	radius = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	x0 = x2;
	y0 = y2;
}
void circle1::brescircle()
{
	int x = 0;
	int col = 15;
	int y = radius;
	int d=3-2*radius;
	while(x<y)
	{
		if(d<=0)
		{
			d = d+4*x+6;
		}
		else
		{
			d = d+4*(x-y) + 10;
			y = y-1;
		}
		x = x+1;
		delay(100);
		putpixel(x0+x,y0+y,col);
		putpixel(x0+x,y0-y,col);
		putpixel(x0-x,y0+y,col);
		putpixel(x0-x,y0-y,col);
		putpixel(x0+y,y0+x,col);
		putpixel(x0+y,y0-x,col);
		putpixel(x0-y,y0+x,col);
		putpixel(x0-y,y0-x,col);

	}
}
int main()
{
	int gdriver = DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"");

	circle1 c1;
	c1.getdata();
	c1.cradius();
	c1.brescircle();

	getch();
	closegraph();
	return 0;
}