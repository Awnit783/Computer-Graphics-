# Computer-Graphics-
Lab File name boundary circle
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

// Line drawing function using DDA
void drawLine(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, i;
    float xIncrement, yIncrement, x = x1, y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    for (i = 0; i <= steps; i++) {
	putpixel((int)x, (int)y, GREEN);
	x += xIncrement;
	y += yIncrement;
	delay(50);
    }
}

// bezeir curve drawing function
void drawBezierCurve(int x[], int y[]) {
    double putx, puty, t;
    for (t = 0.0; t <= 1.0; t += 0.001) {
	putx = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] +
	       3 * t * t * (1 - t) * x[2] + pow(t, 3) * x[3];
	puty = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] +
	       3 * t * t * (1 - t) * y[2] + pow(t, 3) * y[3];
	putpixel((int)putx, (int)puty, WHITE);
    }
}

void main() {
    int x[4], y[4], i;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Input points
    for (i = 0; i < 4; i++) {
	printf("Enter x and y coordinates of point %d: ", i + 1);
	scanf("%d%d", &x[i], &y[i]);
	putpixel(x[i], y[i], GREEN); // Display the points
    }

    // Draw lines between consecutive points for clarity
    for (i = 0; i < 3; i++) {
	drawLine(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Draw the Bezier curve
    drawBezierCurve(x, y);

    getch();
    closegraph();
}
