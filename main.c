#include <GL/glut.h>

static int window_width, window_height;

static void on_reshape(int width, int height){
	window_width = width;
	window_height = height;
}

static void on_keyboard(unsigned char key, int x, int y){
	switch(key){
		case 27:
			exit(0);
			break;
	}
}

static void on_display(void){

	GLfloat light_position[] = { 12, 30, 26, 0 };
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1 };
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    GLfloat ambient_coeffs[] = { 1.0, 1.0, 1.0, 1 };
    GLfloat diffuse_coeffs[] = { 1.0, 1.0, 1.0, 1 };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            1, 50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
		10, 28, 22,
		5, 0, 5,
		0, 1, 0
    );
	
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);
	glEnd();
	glColor3f(0, 1, 1);
	glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);
	glEnd();
	
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
    	glVertex3f(-40, 0, -40);
    	glVertex3f(-40, 0, 40);
    	glVertex3f(40, 0, 40);
    	glVertex3f(40, 0, -40);
    glEnd();
	
	GLfloat ambient_coeffs1[] = { 0.0, 0.0, 1.0, 1 };
    GLfloat diffuse_coeffs1[] = { 0.0, 0.0, 1.0, 1 };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs1);
	
    glColor3f(0, 0, 1);
    glPushMatrix();
		glTranslatef(1, 3, 1);
		glScalef(1, 3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(5, 3, 1);
		glScalef(1, 3, 1);
		glutSolidCube(2);
	glPopMatrix();
    
    glPushMatrix();
		glTranslatef(9, 3, 1);
		glScalef(1, 3, 1);
		glutSolidCube(2);
	glPopMatrix();
	
	GLfloat ambient_coeffs2[] = { 0.0, 1.0, 1.0, 1 };
    GLfloat diffuse_coeffs2[] = { 0.0, 1.0, 1.0, 1 };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs2);
	
    glColor3f(0, 1, 1);
    glPushMatrix();
		glTranslatef(1, 3, 5);
		glScalef(1, 3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(5, 3, 5);
		glScalef(1, 3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(9, 3, 5);
		glScalef(1, 3, 1);
		glutSolidCube(2);
    glPopMatrix();
	
	GLfloat ambient_coeffs3[] = { 1.0, 0.0, 1.0, 1 };
    GLfloat diffuse_coeffs3[] = { 1.0, 0.0, 1.0, 1 };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs3);
	
	glColor3f(1, 1, 0);
	glPushMatrix();
		glTranslatef(1, 3, 9);
		glScalef(1, 3, 1);
		glutSolidCube(2);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(5, 3, 9);
		glScalef(1, 3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(9, 3, 9);
		glScalef(1, 3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
	glutSwapBuffers();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutKeyboardFunc(on_keyboard);
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(3);
		
	glutMainLoop();
	return 0;
}
