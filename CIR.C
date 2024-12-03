// Bresenham's Circle Drawing Algorithm

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
 {
   int gd=DETECT,gm ;
   int xc=300,yc=300,x,y,r,d;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   
   printf("Enter radius of circle : ");
   scanf("%d",&r);

   x=0;
   y=r;
   // d is decision parameter 
   d=(3-(2*r));

   while(x<=y)
   {
     x=x+1;
     if(d<0)
      d=d+(4*x)+6;
     else
      {
       d=d+(4*(x-y))+10;
       y=y-1;
      }
     
     delay(50);

   putpixel(xc+x,yc+y,10);
   putpixel(xc+y,yc+x,10);
   putpixel(xc-y,yc+x,10);
   putpixel(xc-x,yc+y,10);
   putpixel(xc+y,yc-x,10);
   putpixel(xc+x,yc-y,10);
   putpixel(xc-y,yc-x,10);
   putpixel(xc-x,yc-y,10);
  }

 getch();

}
   



   
