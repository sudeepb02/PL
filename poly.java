import java.awt.*;
import java.applet.*;
import java.util.*;

public class poly extends Applet {
	int x1[]=new int[10];
	int y1[]=new int[10];
	int x2[]=new int[10];
	int y2[]=new int[10];
	int n;
	
	public void paint(Graphics g)
	{
		g.drawPolygon(x1,y1,n);
		g.fillPolygon(x2,y2,n);
	}
	public void init()
	{
		System.out.println("enter the number of co ordinates to drawpoly");
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		System.out.println("enter the co ordinates");
		for(int i=0;i<n;i++)
		{
			x1[i]=s.nextInt();
			y1[i]=s.nextInt();
			System.out.println("_____________");
		}
		for(int i=0;i<n;i++)
		{
			x2[i]=x1[i]+300;
			y2[i]=y1[i];
			
		}
		System.out.println("polygons are drawn");
	}

}

