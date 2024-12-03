// 2D Rotation

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int gd = DETECT, gm;
int n, xs[100], ys[100], i, xPivot, yPivot;
float angleRad ,angleDeg;

// Function prototypes
void draw();
void rotate();

void main() {
    // Input number of sides of the polygon
    printf("Enter number of sides of the polygon: ");
    scanf("%d", &n);

    // Input the coordinates of the vertices
    printf("Enter coordinates (x, y) for each vertex:\n");
    for (i = 0; i < n; i++) {
	printf("Vertex %d: ", i + 1);
	scanf("%d%d", &xs[i], &ys[i]);
    }

    // Input pivot point for rotation
    printf("Enter pivot point (xPivot, yPivot): ");
    scanf("%d%d", &xPivot, &yPivot);

    // Input rotation angle in degrees

    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angleDeg);
    angleRad = angleDeg * (M_PI / 180.0); // Convert degrees to radians

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cleardevice();

    // Draw the original polygon in RED
    setcolor(RED);
    draw();

    // Perform rotation
    rotate();

    // Draw the rotated polygon in GREEN
    setcolor(GREEN);
    draw();

     getch();
}

// Function to draw the polygon
void draw() {
    for (i = 0; i < n; i++) {
	line(xs[i], ys[i], xs[(i + 1) % n], ys[(i + 1) % n]);
    }
}

// Function to perform rotation
void rotate() {
    for (i = 0; i < n; i++) {
	int xTemp = xs[i] - xPivot;
	int yTemp = ys[i] - yPivot;

	xs[i] = xPivot + (xTemp * cos(angleRad) - yTemp * sin(angleRad));
	ys[i] = yPivot + (xTemp * sin(angleRad) + yTemp * cos(angleRad));
    }
}
