#include <graphics.h>
#include <stdio.h>
#include<conio.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor)
  {

    if (getpixel(x,y)!= boundaryColor && getpixel(x,y)!= fillColor) {
	putpixel(x, y, fillColor); // Set the pixel to the fill color
		  delay(30);
	boundaryFill(x + 1, y, fillColor, boundaryColor); // Right
	boundaryFill(x, y-1, fillColor, boundaryColor); // Left
	boundaryFill(x, y + 1, fillColor, boundaryColor); // Down
	boundaryFill(x-1, y , fillColor, boundaryColor); // Up

    }
}

void main()
{
    int gd = DETECT, gm;
    int x, y, fillColor, boundaryColor;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw a closed boundary (e.g., a circle)
    circle(200, 200, 50);

    // Set the starting point inside the boundary
    x = 200;
    y = 200;

    fillColor = RED;
    boundaryColor = WHITE;

    boundaryFill(x, y, fillColor, boundaryColor);
    getch();
}