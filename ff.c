// flood_fill 

#include <graphics.h>
#include <stdio.h>
#include<conio.h>
#include<dos.h>

void flood_Fill(int x, int y, int fill_Color, int old_Color)
    {
    if (getpixel(x, y) == old_Color)
      {
        putpixel(x, y, fill_Color); // Set the pixel to the fill color

        // To fill surrounding pixels
       flood_Fill(x + 1, y, fill_Color, old_Color); // Right side
       flood_Fill(x - 1, y, fill_Color, old_Color); // Left side
       flood_Fill(x, y + 1, fill_Color, old_Color); // Down side
       flood_Fill(x, y - 1, fill_Color, old_Color); // Up side
    }
}

void main()
 {
    int gd = DETECT, gm;
    int x, y, fill_Color, old_Color;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // A rectangle's point
    rectangle(100, 100, 200, 200);

    // Set the starting point for filling
    x = 150; 
    y = 150; 

    fill_Color = RED;    
    old_Color = BLACK;      

    flood_Fill(x, y, fill_Color, old_Color);

    getch();
}
