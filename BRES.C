#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, x, y, pk;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Input the start and end points
    printf("Enter the 1st point coordinates (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the 2nd point coordinates (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    // Calculate differences
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine the initial decision parameter
    pk = (2 * dy) - dx;

    // Set starting point
    x = x1;
    y = y1;

    // Draw the initial pixel
    putpixel(x, y, WHITE);

    // Bresenham's Line Algorithm for positive slope
    while (x < x2) {
	x=x+1;
	if (pk >= 0) {
	    y=y+1;
	    pk += (2 * dy) - (2 * dx);
	} else {
	    pk += 2 * dy;
	}
	putpixel(x, y, WHITE);
	delay(10); // Add delay for visualization
    }
    getch();
}
