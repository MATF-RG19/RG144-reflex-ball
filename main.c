#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#include <windows.h>
//#include <windowsx.h>
//#include <mmsystem.h>

#define pi M_PI

static int window_width, window_height;
static int timer_active;
static int height1;
static int height2;
static int height3;
static int height4;
static int height5;
static int height6;
static int height7;
static int height8;
static int height9;
static int active1;
static int active2;
static int active3;
static int active4;
static int active5;
static int active6;
static int active7;
static int active8;
static int active9;
static int life;
static int score;
static int high_score;
static int level[7];
static int pointer;
static float theta;
static float delta_theta;
static int timer_rotate1_active;
static int timer_rotate2_active;
static int first_rotate_active;

static void on_reshape(int width, int height){
	window_width = width;
	window_height = height;
}

static void on_timer_rotate(int value){
	if(value != 0)
		return;
	if(timer_rotate1_active)
		theta += delta_theta;
	else if(timer_rotate2_active)
		theta -= delta_theta;
	glutPostRedisplay();
	if(timer_rotate1_active == 1 || timer_rotate2_active == 1)
		glutTimerFunc(50, on_timer_rotate, 0);
}

static void on_timer(int value){
	if(value != 0)
		return;
		
	time_t t;
	srand((unsigned) time(&t));
	
	int switcher = rand();
	switcher = switcher % 2;
	
	if(life <= 0){
		int i;
		for(i=0; i<5; i++)
			printf("\n");
		printf("Igra je zavrsena!\n");
		printf("HIGH SCORE: %d\n", high_score);
		printf("POINTER: %d\n", pointer);
		exit(0);
	}
	
	if(score > (pointer+1)*10 && pointer != 6)
		pointer++;
	
	if(pointer >= 1 && first_rotate_active == 0){
		timer_rotate1_active = 1;
		first_rotate_active = 1;
		glutTimerFunc(50, on_timer_rotate, 0);
	}
	
	if(timer_rotate1_active && switcher == 0){
		timer_rotate1_active = 0;
		timer_rotate2_active = 1;
	}
	else if(timer_rotate2_active && switcher == 0){
		timer_rotate1_active = 1;
		timer_rotate2_active = 0;
	}
	
	int num = rand();
	num = num % 9;
	
	while( (num == 0 && active1 == 1) || (num == 1 && active2 == 1) ||
		(num == 2 && active3 == 1) || (num == 3 && active4 == 1) ||
		(num == 4 && active5 == 1) || (num == 5 && active6 == 1) ||
		(num == 6 && active7 == 1) || (num == 7 && active8 == 1) ||
		(num == 8 && active9 == 1) ){
			num = rand();
			num = num % 9;
	}
	
	if(active1)
		height1++;
	if(active2)
		height2++;
	if(active3)
		height3++;
	if(active4)
		height4++;
	if(active5)
		height5++;
	if(active6)
		height6++;
	if(active7)
		height7++;
	if(active8)
		height8++;
	if(active9)
		height9++;
	
	if(num == 0 && active1 == 0){
		height1++;
		active1 = 1;
	}
	else if(num == 1 && active2 == 0){
		height2++;
		active2 = 1;
	}
	else if(num == 2 && active3 == 0){
		height3++;
		active3 = 1;
	}
	else if(num == 3 && active4 == 0){
		height4++;
		active4 = 1;
	}
	else if(num == 4 && active5 == 0){
		height5++;
		active5 = 1;
	}
	else if(num == 5 && active6 == 0){
		height6++;
		active6 = 1;
	}
	else if(num == 6 && active7 == 0){
		height7++;
		active7 = 1;
	}
	else if(num == 7 && active8 == 0){
		height8++;
		active8 = 1;
	}
	else if(num == 8 && active1 == 9){
		height9++;
		active9 = 1;
	}
		
	if(height1 == 6){
		height1 = 0;
		active1 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height2 == 6){
		height2 = 0;
		active2 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height3 == 6){
		height3 = 0;
		active3 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height4 == 6){
		height4 = 0;
		active4 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height5 == 6){
		height5 = 0;
		active5 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height6 == 6){
		height6 = 0;
		active6 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height7 == 6){
		height7 = 0;
		active7 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height8 == 6){
		height8 = 0;
		active8 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	if(height9 == 6){
		height9 = 0;
		active9 = 0;
		life--;
		if(score > high_score)
			high_score = score;
		score -= 10;
		pointer--;
		printf("Broj zivota: %d\n", life);
	}
	
	if(life <= 0){
		int i;
		for(i=0; i<5; i++)
			printf("\n");
		printf("Igra je zavrsena!\n");
		printf("HIGH SCORE: %d\n", high_score);
		printf("POINTER: %d\n", pointer);
		exit(0);
	}
	
	glutPostRedisplay();
	
	if(timer_active)
		glutTimerFunc(level[pointer], on_timer, 0);
}

static void on_keyboard(unsigned char key, int x, int y){
	switch(key){
		case 27:
			exit(0);
			break;
		case 's':
		case 'S':
			if(!timer_active){
				timer_active = 1;
				glutTimerFunc(level[pointer], on_timer, 0);
			}
			glutPostRedisplay();
			break;
		case 'p':
		case 'P':
			timer_active = 0;
			glutPostRedisplay();
			break;
		case '1':
			height1 = 0;
			if(active1 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active1 = 0;
			glutPostRedisplay();
			break;
		case '2':
			height2 = 0;
			if(active2 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active2 = 0;
			glutPostRedisplay();
			break;
		case '3':
			height3 = 0;
			if(active3 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active3 = 0;
			glutPostRedisplay();
			break;
		case '4':
			height4 = 0;
			if(active4 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active4 = 0;
			glutPostRedisplay();
			break;
		case '5':
			height5 = 0;
			if(active5 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active5 = 0;
			glutPostRedisplay();
			break;
		case '6':
			height6 = 0;
			if(active6 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active6 = 0;
			glutPostRedisplay();
			break;
		case '7':
			height7 = 0;
			if(active7 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active7 = 0;
			glutPostRedisplay();
			break;
		case '8':
			height8 = 0;
			if(active8 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active8 = 0;
			glutPostRedisplay();
			break;
		case '9':
			height9 = 0;
			if(active9 == 0){
				life--;
				printf("Broj zivota: %d\n", life);
				if(score > high_score)
					high_score = score;
				score -= 10;
				pointer--;
			}
			else{
				score++;
				printf("SCORE: %d\n",score);
			}
			active9 = 0;
			glutPostRedisplay();
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
		10*sin(theta)+5, 20, 10*cos(theta)+5,
		5, 0, 5,
		0, 1, 0
    );
	
	/*glColor3f(0, 1, 0);
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
	glEnd();*/
	
	GLfloat ambient_coeffs0[] = { 0.3, 0.3, 0.3, 1 };
    GLfloat diffuse_coeffs0[] = { 0.3, 0.3, 0.3, 1 };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs0);
	
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
		glScalef(1, height7+3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(5, 3, 1);
		glScalef(1, height8+3, 1);
		glutSolidCube(2);
	glPopMatrix();
    
    glPushMatrix();
		glTranslatef(9, 3, 1);
		glScalef(1, height9+3, 1);
		glutSolidCube(2);
	glPopMatrix();
	
	GLfloat ambient_coeffs2[] = { 0.0, 1.0, 1.0, 1 };
    GLfloat diffuse_coeffs2[] = { 0.0, 1.0, 1.0, 1 };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs2);
	
    glColor3f(0, 1, 1);
    glPushMatrix();
		glTranslatef(1, 3, 5);
		glScalef(1, height4+3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(5, 3, 5);
		glScalef(1, height5+3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(9, 3, 5);
		glScalef(1, height6+3, 1);
		glutSolidCube(2);
    glPopMatrix();
	
	GLfloat ambient_coeffs3[] = { 1.0, 0.0, 1.0, 1 };
    GLfloat diffuse_coeffs3[] = { 1.0, 0.0, 1.0, 1 };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs3);
	
	glColor3f(1, 1, 0);
	glPushMatrix();
		glTranslatef(1, 3, 9);
		glScalef(1, height1+3, 1);
		glutSolidCube(2);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(5, 3, 9);
		glScalef(1, height2+3, 1);
		glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(9, 3, 9);
		glScalef(1, height3+3, 1);
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
	
	timer_active = 0;
	timer_rotate1_active = 0;
	timer_rotate2_active = 0;
	first_rotate_active = 0;
	height1 = 0;
	height2 = 0;
	height3 = 0;
	height4 = 0;
	height5 = 0;
	height6 = 0;
	height7 = 0;
	height8 = 0;
	height9 = 0;
	score = 0;
	high_score = 0;
	pointer = 0;
	theta = 0.0001;
	delta_theta = pi / 90;
	level[0] = 2000;
	level[1] = 1500;
	level[2] = 1200;
	level[3] = 1000;
	level[4] = 800;
	level[5] = 500;
	level[6] = 330;
	
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutKeyboardFunc(on_keyboard);
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(3);
	life = 3;
	printf("Lives remaining: %d\n",life);
	printf("SCORE: %d\n",score);
	glutMainLoop();
	return 0;
}
