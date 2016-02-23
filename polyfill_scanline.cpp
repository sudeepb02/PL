#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
class polyfill
{
	int n;
	int edge[20][4];
	int *poly;
public:
	polyfill();
	void getdata();
	void draw();
	void fillpol();
	void drawtable();
	void sorttable();
};
polyfill::polyfill()
{
}
void polyfill::draw()
{
}
void polyfill::getdata()
{
	cout<<"Enter number of vertices : ";
	cin>>n;
	int index;
	index = 2*n;
	poly = new int[index+2];

	for(int i=0;i<index;i++)
	{
		cout<<"Enter x co-ordinate : ";
		cin>>poly[i];
		i++;
		cout<<"Enter y co-ordinate : ";
		cin>>poly[i];
	}
	poly[index] = poly[0];
	poly[index+1] = poly[1];


	drawpoly(index+1,poly);

}

int main()
{

	int gdriver = DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"");

	polyfill p;
	p.getdata();
	p.fillpol();
	getch();
	closegraph();
	return 0;
}
void polyfill::drawtable()
{

}
void polyfill::fillpol()
{
//	clrscr();
	int temp,i;
	getch();
	clearviewport();
 //	int edge[20][4];
	cout<<"y1 \t y2 \tx1 \t x2\n";
	for(i=0;i<2*n;i=i+2)
	{
		edge[i][0] = poly[i+1];
		edge[i][1] = poly[i+3];
		edge[i][2] = poly[i];
		edge[i][3] = poly[i+2];
		cout<<edge[i][0]<<"\t"<<edge[i][1]<<"\t"<<edge[i][2]<<"\t"<<edge[i][3]<<"\n";
	}
	cout<<"===========================\n";

       //	clearviewport();
	sorttable();
}

void polyfill::sorttable()
{
	int i,temp;
	cout<<"y1 \t y2 \tx1 \t x2\n";

	for(i=0;i<2*n;i=i+2)
	{
		if(edge[i][0]<edge[i][1])
		{
			temp = edge[i][0];
			edge[i][0] = edge[i][1];
			edge[i][1] = temp;
		}
		if(edge[i][2]<edge[i][3])
		{
			temp = edge[i][2];
			edge[i][2] = edge[i][3];
			edge[i][3] = temp;
		}
	cout<<edge[i][0]<<"\t"<<edge[i][1]<<"\t"<<edge[i][2]<<"\t"<<edge[i][3]<<"\n";
	}
	cout<<"============================\n";
	cout<<"y1 \t y2 \tx1 \t x2\n";

	for(i=0;i<n;i++)
	{
		for(int j=i;j<n-1;j++)
		{
			if(edge[j][0]<edge[j+1][0])
			{
				temp = edge[j][0];
				edge[j][0] = edge[j+1][0];
				edge[j+1][0] = temp;


				temp = edge[j][1];
				edge[j][1] = edge[j+1][1];
				edge[j+1][1] = temp;


				temp = edge[j][2];
				edge[j][2] = edge[j+1][2];
				edge[j+1][2] = temp;


				temp = edge[j][3];
				edge[j][3] = edge[j+1][3];
				edge[j+1][3] = temp;
			}
		}
	cout<<edge[i][0]<<"\t"<<edge[i][1]<<"\t"<<edge[i][2]<<"\t"<<edge[i][3]<<"\n";

	}


}
