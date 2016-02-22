#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
class ddacircle
{
	int radius,x0,y0,col;
	float eps;
public:
	void getvalue();
	void drawcircle();
	void calceps();
};
void ddacircle::getvalue()
{
	cout<<"Enter radius of circle : ";
	cin>>radius;
	cout<<"Enter centre of the circle (x0,y0) : ";
	cin>>x0>>y0;
	cout<<"Enter color (0-15) : ";
	cin>>col;
}

void ddacircle::calceps()
{
	int n=0;
	int temp;
	temp = 0;
	while(temp<radius)
	{
		temp = pow(2,n);
		n++;
	}
	n--;
	cout<<"n = "<<n;
	eps = pow(2,-n);
	cout<<"Eps = "<<eps;
}

int main()
{
	int gdriver = DETECT,gmode, errorcode;
	initgraph(&gdriver,&gmode,"");

	ddacircle c1;
	c1.getvalue();
	c1.calceps();
	c1.drawcircle();

	getch();
	closegraph();
	return 0;

}
void ddacircle::drawcircle()
{
	float x1,x2,y1,y2,t=0;
	float startx,starty;

	x1 = radius*cos(t);
	y1 = radius*sin(t);
	startx = x1;
	starty = y1;

      //	eps = 2^(-n);// where 2^n-1<=r<=2^n
	do
	{
		x2 = x1 + eps*y1;
		y2 = y1 - eps*x2;

		putpixel(x0+x2,y0+y2,col);

		x1 = x2;
		y1 = y2;

	      //	delay(100);
	}while((y1-starty)<eps || (startx - x1) > eps);
}