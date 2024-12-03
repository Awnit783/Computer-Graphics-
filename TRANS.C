// 2D Translation

#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int gd = DETECT, gm;
int n, xs[100], ys[100], i, tx, ty;

void draw();
void translate();

void main() {
    // Input number of sides of the polygon
    printf("Enter number of sides of polygon: ");
    scanf("%d", &n);

    // Input the coordinates for each vertex
    printf("Enter coordinates (x, y) for each vertex:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d%d", &xs[i], &ys[i]);
    }

    // Input translation distances
    printf("Enter distance for translation (in x and y direction): ");
    scanf("%d%d", &tx, &ty);

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cleardevice();

    // Draw the original polygon in RED
    setcolor(RED);
    draw();

    // Perform translation
    translate();

    // Draw the translated polygon in GREEN
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

// Function to perform translation
void translate() {
    for (i = 0; i < n; i++) {
        xs[i] += tx;
        ys[i] += ty;
    }
}
