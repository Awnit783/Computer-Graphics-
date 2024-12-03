// DDA Line Drawing algorithm

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
 {
   int gd=DETECT,gm ;
   int x1,x2,y1,y2,i,step,dx,dy,xn,yn ;

   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   printf("Enter the 1st point co-ordinates :");
   scanf("%d%d",&x1,&y1);
   printf("Enter the 2nd point co-ordinates :");
   scanf("%d%d",&x2,&y2);
   cleardevice();

   dx=x2-x1;
   dy=y2-y1;

   if(abs(dx)>abs(dy))
     step=abs(dx);
   else
     step=abs(dy);

   xn=dx/step;
   yn=dy/step;

   for(i=1;i<=step;i++)
   {
     putpixel(x1,y1,WHITE);
     delay(50);
     x1=x1+xn;
     y1=y1+yn;
   }

 getch();
}