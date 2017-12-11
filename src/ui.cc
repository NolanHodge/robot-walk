
#include "supervisor.hh"

#include <thread>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795
 
#define WIDTH 1080
#define HEIGHT 900
 
static int radius = 2;
const float DEG2RAD = 3.14159/180; 
supervisor sup;
int *pos = {};
int len = 0;

void init()
{
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void reshape(int h, int w)
{
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void clear_circle() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void draw_circle() {
	glColor3f(0.2, 0.3, 0.5);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	for(int i=0;i<POINT_COUNT;++i)
	{
    	glVertex3f(cos(2*3.14159*i/1000.0),sin(2*3.14159*i/1000.0),0);
	}
	glEnd(); 
	glutDisplayFunc(glutPostRedisplay);
}

void draw_robots() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw_circle();
	for (int i=0; i<len; i++) {
		glPointSize(10.0);
		glBegin(GL_POINTS); 
		glColor3f(255, 0, 0);
	    glVertex3f(cos(2*3.14159*pos[i]/1000.0),sin(2*3.14159*pos[i]/1000.0),0);
		glEnd();
	}
	glutSwapBuffers();
}

void display()
{
	glPushMatrix();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	draw_circle();
	draw_robots();
	glPushMatrix();
	glPopMatrix();
	glutPostRedisplay();
}

void timer(int)
{
	pos = sup.get_robot_positions();
	len = sup.get_robot_count();
	draw_robots();
    glutPostRedisplay();
    glutTimerFunc(UI_SPEED, timer, 0);
}

void execute()
{
	sup.execute();
}

int main(int argc, char **argv) 
{
	std::thread t(execute);	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("Robot Walk");
	init();
    glutTimerFunc(1000.0/60.0, timer, 0);
    glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
 

