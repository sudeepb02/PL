#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
class polyfill
{
	int n;
	int *poly;
public:
	polyfill();
	void getdata();
	void draw();
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

	getch();
	closegraph();
	return 0;
}