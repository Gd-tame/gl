void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius;

    while (x <= y) {
        glColor3ub(0,0,0);
        drawPixel(xc + x, yc + y); // Octant 1
        glColor3ub(0,0,0);

        drawPixel(xc - x, yc + y); // Octant 2
        glColor3ub(0,0,0);

        drawPixel(xc + x, yc - y); // Octant 8
        glColor3ub(0,0,0);

        drawPixel(xc - x, yc - y); // Octant 7
        glColor3ub(0,0,0);

        drawPixel(xc + y, yc + x); // Octant 3
        glColor3ub(0,0,0);

        drawPixel(xc - y, yc + x); // Octant 4
        glColor3ub(0,0,0);

        drawPixel(xc + y, yc - x); // Octant 5
        glColor3ub(0,0,0);

        drawPixel(xc - y, yc - x); // Octant 6

        x++;

        if (p < 0) {
            p += 4 * x + 6;
        }
        else {
            y--;
            p += 4 * (x - y) + 10;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(320, 240, 100);
    drawCircle(520, 240, 100);
    glFlush();
}