#include<iostream.h>
#include<conio.h>
#include<graphics.h>
class fillCol
{
	int x,y,col;
public:
	fillCol(){};
 //	void getdata();
	void boundaryfill(int,int,int,int);
//	void floodfill(int,int,int,int);
};
void fillCol::boundaryfill(int sx,int sy,int fillc,int borderc)
{
	int color = getpixel(sx,sy);
	if((color!=borderc) && (color!=fillc))
	{
		putpixel(sx,sy,fillc);
		boundaryfill(sx+1,sy,fillc,borderc);
		boundaryfill(sx-1,sy,fillc,borderc);
		boundaryfill(sx,sy+1,fillc,borderc);
		boundaryfill(sx,sy-1,fillc,borderc);
	}
}

int main()
{
	int gdriver = DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"");

	int x1,y1,x2,y2;
	int seedx,seedy;
	cout<<"Enter the co-ordinates of top corner of rectangle :(x1,y1) ";
	cin>>x1>>y1;
	cout<<"(x2,y2)";
	cin>>x2>>y2;

	rectangle(x1,y1,x2,y2);
	seedx = (x1+x2)/2;
	seedy = (y1+y2)/2;


	fillCol obj;
	obj.boundaryfill(seedx,seedy,4,15);

	getch();
	closegraph();
	return 0;
}

