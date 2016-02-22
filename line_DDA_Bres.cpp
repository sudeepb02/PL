#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

class Line1
{
	int x1,y1,x2,y2;
public:
	int col;
	void getdata();
	void simple();
	void simple(int);
	void dotted();
	void dotted(int);
	void dash();
	void dash(int);
	int round(float);
	void thick();
};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver,&gmode,"");

	Line1 l1;
	l1.getdata();
	int c;
	c = l1.col;
	cout<<"1.DDA line \n2. Bres line \n3. DDA Dotted \n4.Bres Dotted\n5.DDA dashed \n6.Bres dashed 7. DDA thick\n";
	cout<<"Enter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
	case 1:
		l1.simple();
		break;
	case 2:
		l1.simple(c);
		break;
	case 3:
		l1.dotted();
		break;
	case 4:
		l1.dotted(c);
		break;
	case 5:
		l1.dash();
		break;
	case 6:
		l1.dash(c);
		break;
	case 7:
		l1.thick();
		break;
	default:
		cout<<"Enter correct choice : ";
		break;
	}
	getch();
	closegraph();
	return 0;
}
void Line1::getdata()
{
	cout<<"Enter the starting point(x1,y1) : \n";
	cin>>x1>>y1;

	cout<<"Enter the end point(x2,y2) : \n";
	cin>>x2>>y2;

	cout<<"Enter the color value(0-15) : ";
	cin>>col;
}
void Line1::simple(int c)	//Bresenham simple line
{
	int dx,dy,pk,pk1,count;
	int x,y;
	x = x1;
	y = y1;

	dx = x2 - x1;
	dy = y2 - y1;

	pk1 = 2*dy - dx;
	count = dx;

	putpixel(x1,y1,c);

	for(int i=0;i<count;i++)
	{
		if(pk1<0)
		{
			x++;
			putpixel(x,y,c);
			pk1 = pk1 + (2*dy);

		}
		else
		{
			x++;
			y++;
			putpixel(x,y,c);
			pk1 = (pk1 + 2*dy) - (2*dx);
		 }
	}
}
void Line1::simple()	//For DDA simple line
{
	int dx,dy,steps;
	float x,y;
	x = x1;
	y = y1;
	float incrx,incry;
	dx = x2 - x1;
	dy = y2 - y1;
	if(abs(dx)>abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}

	incrx = float(dx)/float(steps);
	incry = float(dy)/float(steps);

	putpixel(round(x1),round(y1),col);

	for(int i=0;i<steps;i++)
	{
		x+=incrx;
		y+=incry;
		putpixel(round(x),round(y),col);
	}

}
void Line1::dotted(int c)	//Bresenham dotted line
{
	int dx,dy,pk,pk1,count;
	int x,y;
	x = x1;
	y = y1;

	dx = x2 - x1;
	dy = y2 - y1;

	pk1 = 2*dy - dx;
	count = dx;

	putpixel(x1,y1,c);

	for(int i=0;i<count;i++)
	{
		if(pk1<0)
		{
			x++;
			putpixel(x,y,c);
			pk1 = pk1 + (2*dy);

		}
		else
		{
			x++;
			y++;
			putpixel(x,y,c);
			pk1 = (pk1 + 2*dy) - (2*dx);

		}
		x++;
	}
}
void Line1::dash()		//DDA dashed line
{
        int dx,dy,steps;
        int c=0;
        float x,y;
        x = x1;
        y = y1;
        float incrx,incry;
        dx = x2 - x1;
        dy = y2 - y1;
        if(abs(dx)>abs(dy))
        {
                steps = abs(dx);
        }
        else
        {
                steps = abs(dy);
        }

        incrx = float(dx)/float(steps);
        incry = float(dy)/float(steps);

        putpixel(round(x1),round(y1),15);

        for(int i=0;i<steps;i++)
        {
                x+=incrx;
                y+=incry;
                c++;
               if(c%15<5 || c%15==9)
               {
                putpixel(round(x),round(y),15);

               }

        }

}

void Line1::dotted()	//For DDA dotted
{
	int dx,dy,steps;
	float x,y;
	x = x1;
	y = y1;
	float incrx,incry;
	dx = x2 - x1;
	dy = y2 - y1;
	if(abs(dx)>abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}

	incrx = float(dx)/float(steps);
	incry = float(dy)/float(steps);

	putpixel(round(x1),round(y1),col);

	for(int i=0;i<steps;i=i+2)
	{
		x+=2*incrx;
		y+=2*incry;
		putpixel(round(x),round(y),col);
	}

}

void Line1::dash(int c)	//For Bresenham Dashed
{
	int dx,dy,pk1,count;
	int x,y,steps=0;
	x = x1;
	y = y1;

	dx = x2 - x1;
	dy = y2 - y1;

	pk1 = 2*dy - dx;
	count = dx;

	putpixel(x1,y1,c);

	for(int i=0;i<count;i++)
	{
		steps = i%15;
		if(pk1<0)
		{
			x++;
			if(steps<8)
			{
			putpixel(x,y,c);
			}
			pk1 = pk1 + (2*dy);

		}
		else
		{
			x++;
			y++;
			if(steps<8)
			{
			putpixel(x,y,c);
			}
			pk1 = (pk1 + 2*dy) - (2*dx);

		}
	}
}
int Line1::round(float x)	//To round-off the float
{
	float temp;
	temp = int(x);
	temp+=0.5;
	if(x>=temp)
	{
		return int(x)+1;
	}
	else
	{
		return int(x);
	}
}
void Line1::thick()
{
int dx=x2-x1;
int i=1,thk;
int dy=y2-y1;
float x,y;
cout<<"Enter thickness";
cin>>thk;
float xinc,yinc;int steps;
float wx=( (thk-1)*(sqrt((dx*dx)+(dy*dy))) )/abs(2*dx);
float wy=( (thk-1)*(sqrt((dx*dx)+(dy*dy))) )/abs(2*dy);
if(abs(dx)>abs(dy))
	{steps=abs(dx);}
else
	{steps=abs(dy);}
xinc=float(dx)/float(steps);
yinc=float(dy)/float(steps);
putpixel(round(x1),round(y1),c);
x=x1;y=y1;

while(i<=steps)
	{
		if (dy<=dx)
		{
			for(int j=y-wy; j<y+wy; j++)
			{
				putpixel(round(x),j,col);
			}
		}
		else if(dy>dx)
		{
			for(int k=x-wx; k<x+wx; k++)
			{
				putpixel(k,round(y),col);
			}
		}
		x=x+xinc;
		y=y+yinc;
		i=i+1;
	}
}