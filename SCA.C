// 2D Scaling

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int gd = DETECT, gm;
int n, x[100], y[100], i;
float sx, sy;
void draw();
void scale();

void main() {
    // Input number of sides of the polygon
    printf("Enter number of sides of the polygon: ");
    scanf("%d", &n);

    // Input the coordinates of the vertices
    printf("Enter coordinates (x, y) for each vertex:\n");
    for (i = 0; i < n; i++) {
	printf("Vertex %d: ", i + 1);
	scanf("%d%d", &x[i], &y[i]);
    }

    // Input scaling factors
    printf("Enter scaling factors (sx, sy): ");
    scanf("%f%f", &sx, &sy);

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cleardevice();

    // Draw the original polygon in RED
    setcolor(RED);
    draw();

    // Perform scaling
    scale();

    // Draw the scaled polygon in GREEN
    setcolor(GREEN);
    draw();

    getch();
}

// Function to draw the polygon
void draw() {
    for (i = 0; i < n; i++) {
	line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

// Function to perform scaling
void scale() {
    for (i = 0; i < n;i++) {
	x[i]=x[i]* sx;
	y[i]=y[i]* sy;
    }
}
