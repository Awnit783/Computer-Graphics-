// Mid-Point Circle Drawing Algorithm 

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void plot_pts (int ,int ,int ,int);
void main()
{
  int gd=DETECT,gm ;
  int x,y,xc,yc;
  float p,r ;

  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  printf("Enter the center co-ordinate :");
  scanf("%d%d",&xc,&yc);
  printf("Enter the radius :");
  scanf("%f",&r);

  x=0;
  y=r;
  p=1.25-r ;

  do{
      plot_pts(xc,yc,x,y);
      if(p<0)
	{
	  p=p+((2*x)+3);
	}
      else
	{
	  p=p+((2*(x-y))+1);
	  y-- ;
	}
      x++ ;
    } while(x<y);

   if(x==y)
      plot_pts(xc,yc,x,y);
    getch();
}

void plot_pts(int x,int y,int x1,int y1)
{  delay(50);
   putpixel(x+x1,y+y1,GREEN);
   putpixel(x-x1,y+y1,GREEN);
   putpixel(x+x1,y-y1,GREEN);
   putpixel(x-x1,y-y1,GREEN);
   putpixel(x+y1,y+x1,GREEN);
   putpixel(x-y1,y+x1,GREEN); 
   putpixel(x+y1,y-x1,GREEN);
   putpixel(x-y1,y-x1,GREEN);
}
   


