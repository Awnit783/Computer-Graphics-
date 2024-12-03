// MID_POINT_LINE_ALGORITHM

#include <graphics.h>
#include <stdio.h>
#include<conio.h>
void drawLineMidpoint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int p = 2 * dy;
    int q = 2 * (dy - dx);
    int x = x1, y = y1;

    putpixel(x, y, WHITE); // Draw the initial point

    while (x < x2) {
        if (d <= 0) {
            // Choose E
            d += p;
        } else {
            // Choose NE
            d += q;
            y++;
        }
        x++;
        putpixel(x, y, WHITE);
    }
}

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLineMidpoint(x1, y1, x2, y2);

    getch();
    closegraph(); 
    }