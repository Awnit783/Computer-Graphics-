#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int gd = DETECT, gm;
int n, xs[100], ys[100], i;
char axis;
int midX,midY;
// Function prototypes
void drawPolygon(int xs[], int ys[], int n, int color);
void reflectPolygon(int xs[], int ys[], int n, char axis);

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

    // Input axis of reflection
    printf("Enter axis of reflection (x/y): ");
    scanf(" %c", &axis);

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

       midX = getmaxx() / 2;
       midY = getmaxy() / 2;

    cleardevice();

    // Draw coordinate axes
    setcolor(WHITE);
    line(0, midY, getmaxx(), midY); // x-axis
    line(midX, 0, midX, getmaxy()); // y-axis

    // Draw the original polygon in RED
    setcolor(RED);
    drawPolygon(xs, ys, n, RED);

    // Reflect the polygon
    reflectPolygon(xs, ys, n, axis);

    // Draw the reflected polygon in GREEN
    setcolor(GREEN);
    drawPolygon(xs, ys, n, GREEN);

    getch();

    // Close graphics mode
    closegraph();


}

// Function to draw the polygon
void drawPolygon(int xs[], int ys[], int n,int color)
 {
    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    for (i = 0; i < n; i++)
     {
	int x1 = midX + xs[i];
	int y1 = midY - ys[i];
	int x2 = midX + xs[(i + 1) % n];
	int y2 = midY - ys[(i + 1) % n];
	line(x1, y1, x2, y2);
     }
}

// Function to reflect the polygon
void reflectPolygon(int xs[], int ys[], int n, char axis) {
    if (axis == 'x' || axis == 'X') {
	for (i = 0; i < n; i++) {
	    ys[i] = -ys[i]; // Reflect about x-axis
	}
    } else if (axis == 'y' || axis == 'Y') {
	for (i = 0; i < n; i++) {
	    xs[i] = -xs[i]; // Reflect about y-axis
	}
    }
}
