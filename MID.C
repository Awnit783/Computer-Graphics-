// Mid-Point Line Drawing Algorithm 

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
 {
   int gd=DETECT,gm ;
   // pk is decision parameter 
   int x1,y1,x2,y2,dx,dy,x,y,p ;
   
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   printf("Enter the 1st point co-ordinates :");
   scanf("%d%d",&x1,&y1);
   printf("Enter the last point co-ordinates :");
   scanf("%d%d",&x2,&y2);

   dx=x2-x1;
   dy=y2-y1;

   p=((2*dy)-dx);  // calculate p
   x=x1;
   y=y1;
   while(x1<=x2)   // checking for 2 condition of p
    {
      delay(50);
     if(p>=0)
       {
         putpixel(x,y,10);
         p=p+dy-dx;
         y=y+1;
       }
     else
       {
         putpixel(x,y,10);
         p=p+dy;
       }
       x=x+1;   // Here x value increase in both conditions
 
   getch();
    }

}

