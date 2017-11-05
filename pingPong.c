#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

/* A simple ping pong game */

// global variables
static GLint windowSizeX = 800, windowSizeY = 1200;
static GLint orthoSizeX = 600, orthoSizeY = 400;

// game variables
static GLint player1_score = 0, player2_score = 0;
static GLint player1_life = 3, player2_life = 3;
static GLint paddle_boundary = 350, paddle_height = 80, paddile_velocity = 8.0;
static GLint player1_paddile_y = 0, player2_paddile_y = 0, paddle_x = 550;
static GLfloat ball_velocity_x = 0, ball_velocity_y = 0, ball_radius = 20;
static GLint ball_pos_x = 0, ball_pos_y = 0;

void init(void) {
    // initalise display with black colors
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);

    srand(time(NULL));   // should only be called once
}

void drawCenterLines() {
    // center lines start
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -410);
    glVertex2f(2 , -410);
    glVertex2f(2 , -390);
    glVertex2f(-2 , -390);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -370);
    glVertex2f(2 , -370);
    glVertex2f(2 , -350);
    glVertex2f(-2 , -350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -330);
    glVertex2f(2 , -330);
    glVertex2f(2 , -310);
    glVertex2f(-2 , -310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -290);
    glVertex2f(2 , -290);
    glVertex2f(2 , -270);
    glVertex2f(-2 , -270);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -250);
    glVertex2f(2 , -250);
    glVertex2f(2 , -230);
    glVertex2f(-2 , -230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -210);
    glVertex2f(2 , -210);
    glVertex2f(2 , -190);
    glVertex2f(-2 , -190);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -170);
    glVertex2f(2 , -170);
    glVertex2f(2 , -150);
    glVertex2f(-2 , -150);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -130);
    glVertex2f(2 , -130);
    glVertex2f(2 , -110);
    glVertex2f(-2 , -110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -90);
    glVertex2f(2 , -90);
    glVertex2f(2 , -70);
    glVertex2f(-2 , -70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -50);
    glVertex2f(2 , -50);
    glVertex2f(2 , -30);
    glVertex2f(-2 , -30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -10);
    glVertex2f(2 , -10);
    glVertex2f(2 , 10);
    glVertex2f(-2 , 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 30);
    glVertex2f(2 , 30);
    glVertex2f(2 , 50);
    glVertex2f(-2 , 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 70);
    glVertex2f(2 , 70);
    glVertex2f(2 , 90);
    glVertex2f(-2 , 90);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 110);
    glVertex2f(2 , 110);
    glVertex2f(2 , 130);
    glVertex2f(-2 , 130);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 150);
    glVertex2f(2 , 150);
    glVertex2f(2 , 170);
    glVertex2f(-2 , 170);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 190);
    glVertex2f(2 , 190);
    glVertex2f(2 , 210);
    glVertex2f(-2 , 210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 230);
    glVertex2f(2 , 230);
    glVertex2f(2 , 250);
    glVertex2f(-2 , 250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 270);
    glVertex2f(2 , 270);
    glVertex2f(2 , 290);
    glVertex2f(-2 , 290);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 310);
    glVertex2f(2 , 310);
    glVertex2f(2 , 330);
    glVertex2f(-2 , 330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 350);
    glVertex2f(2 , 350);
    glVertex2f(2 , 370);
    glVertex2f(-2 , 370);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 390);
    glVertex2f(2 , 390);
    glVertex2f(2 , 410);
    glVertex2f(-2 , 410);
    glEnd();
    // center lines end
}

// x, y is the top left corodinate of the paddle
void drawPaddle(int x, int y) {
    glPushMatrix();

    glTranslatef(x, y, 0);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    int height = paddle_height / 2;
    glVertex2f(-5 , height);
    glVertex2f(5 , height);
    glVertex2f(5 , -height);
    glVertex2f(-5, -height);
    glEnd();

    glPopMatrix();
}

void drawBall(int x, int y) {
    glPushMatrix();

    glTranslatef(x, y, 0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere (ball_radius, 20, 16);

    glPopMatrix();
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCenterLines();

    drawPaddle(-paddle_x, player1_paddile_y);
    drawPaddle(paddle_x, player2_paddile_y);

    drawBall(ball_pos_x, ball_pos_y);

    glutSwapBuffers();
    glFlush();
}

void startGame(void) {

    // move the ball
    ball_pos_x += ball_velocity_x;
    ball_pos_y += ball_velocity_y;

    // ball hits the top or bottom
    if (ball_pos_y + ball_radius > orthoSizeY || ball_pos_y - ball_radius < -orthoSizeY)
        ball_velocity_y = -ball_velocity_y;

    // ball hits the left paddle
    if (ball_pos_x - ball_radius < -paddle_x && ball_pos_x - ball_radius < -paddle_x - 2)
        if (ball_pos_y < player1_paddile_y + paddle_height && ball_pos_y > player1_paddile_y - paddle_height)
            ball_velocity_x = -ball_velocity_x;

    // ball hits the right paddle
    if (ball_pos_x + ball_radius > paddle_x && ball_pos_x + ball_radius < paddle_x + 2)
        if (ball_pos_y < player2_paddile_y + paddle_height && ball_pos_y > player2_paddile_y - paddle_height)
            ball_velocity_x = -ball_velocity_x;

    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-orthoSizeX, orthoSizeX, -orthoSizeY, orthoSizeY, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            ball_velocity_x = (rand() % 5) -  (rand() % 3);
            ball_velocity_y = (rand() % 5) -  (rand() % 3);
            glutIdleFunc(startGame);
            break;
        case GLUT_MIDDLE_BUTTON:
            ball_pos_x = 0;
            ball_pos_y = 0;
            if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
            break;
        default:
        break;
    }
}


void keyboard (unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
            if (player1_paddile_y < paddle_boundary)
                player1_paddile_y += paddile_velocity;
            glutPostRedisplay();
            break;
        case 'a':
            if (player1_paddile_y > -paddle_boundary)
                player1_paddile_y -= paddile_velocity;
            glutPostRedisplay();
            break;
        case 'o':
            if (player2_paddile_y < paddle_boundary)
                player2_paddile_y += paddile_velocity;
            glutPostRedisplay();
            break;
        case 'l':
            if (player2_paddile_y > -paddle_boundary)
                player2_paddile_y -= paddile_velocity;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

/*
* Request double buffer display mode.
* Register mouse input callback functions
*/
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (10, 10);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
