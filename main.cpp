// DESARROLLADORES
//  José  Alexander Guandique Flores GF12011
//  Dámaris Abigaíl Alas Guzmán AG120124
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

//Definimos variables
float mat_amb0 = 0;
float mat_diff0 = 0;
float mat_spec0 = 0;
float mat_amb1 = 0;
float mat_diff1 = 0;
float mat_spec1 = 0;
float mat_amb2 = 0;
float mat_diff2 = 0;
float mat_spec2 = 0;
float shin = 0;

float luz_position_x=0;
float luz_position_y=0;
float luz_position_z=0;
//funcion para mover la luz con el mouse
void luz(float x,float y,float z){
	 
	 //propiedades de la luz

GLfloat luz_ambient []  = {1.0, 1.0, 0.0, 1.0 };
GLfloat luz_diffuse []  = { 1.0, 1.0, 1.0, 1.0 };
GLfloat luz_specular [] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat luz_position [] = { luz_position_x,luz_position_y,luz_position_z, 0.0 };
GLfloat foco_direccion [] = { 0.0, 0.0, -1.0 };
    //setLuces
    
glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambient);//intensidad ambiente RGBA de la luz
glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_diffuse);//intensidad difusa RGBA de la luz
glLightfv(GL_LIGHT0, GL_SPECULAR, luz_specular);//intensidad especular RGBA de la luz
glLightfv(GL_LIGHT0, GL_POSITION, luz_position);//posición (x,y,z,w) de la luz
glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, foco_direccion);//dirección (x,y,z) del foco de luz
	}
	
void mouse(int button, int state,int x, int y){
switch(button){
case GLUT_RIGHT_BUTTON:
if(state == GLUT_DOWN){
luz_position_x+=190;
 luz(luz_position_x,luz_position_y,luz_position_z); 
}
if(state == GLUT_UP){
luz_position_x+=190;
 luz(luz_position_x,luz_position_y,luz_position_z); 
}
break;
case GLUT_MIDDLE_BUTTON:
if(state == GLUT_DOWN){
luz_position_z+=190;
luz(luz_position_x,luz_position_y,luz_position_z); 
}
if(state == GLUT_UP){
luz_position_z+=190;
 luz(luz_position_x,luz_position_y,luz_position_z); 
}
break;
case  GLUT_LEFT_BUTTON:
if(state == GLUT_DOWN){
luz_position_y+=190;
 luz(luz_position_x,luz_position_y,luz_position_z); 
}
if(state == GLUT_UP){
luz_position_y+=190;
 luz(luz_position_x,luz_position_y,luz_position_z); 
}
break;
}
   glutPostRedisplay(); 
}

void material(float mat_amb0,float mat_amb1,float mat_amb2,float mat_diff0,float mat_diff1,float mat_spec0,float mat_spec1,float mat_spec2,float shin)
{
 
  //Propiedades del material 
        GLfloat mat_ambient[] = { mat_amb0,mat_amb1,mat_amb2};
        GLfloat mat_diffuse[] = { mat_diff0,mat_diff1,mat_diff2};
        GLfloat mat_specular[] = {mat_spec0,mat_spec1,mat_spec2};
        GLfloat shininess [] = {shin};
 
  //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);                                     	
        
  
	}
void init(void)
{

// Activamos la fuente de luz
 glEnable(GL_LIGHTING);//Activamos las luces
 glEnable(GL_LIGHT0); //Activamos las luces en 0
 glDepthFunc(GL_LESS); //comparación de profundidad
 glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
 
}
void reshape(int w, int h)
{
 glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
 glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
 glLoadIdentity();
// Usamos proyeccion ortogonal
 glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
 glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
 glLoadIdentity();
}

void display(void)
{
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode( GL_MODELVIEW_MATRIX );
 glLoadIdentity();
 glPushMatrix();
 glutSolidSphere(200,270,270);//dibujando la esfera
   
 glFlush();
}

// Función para controlar teclas especiales

 void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
		
    case 'c':
    
   //Propiedades del material cooper
        mat_amb0 = 0.19125;
        mat_amb1 = 0.0735;
        mat_amb2 = 0.0225;
        mat_diff0 = 0.70388;
        mat_diff1 = 0.27048;
        mat_diff2 = 0.0828;
        mat_spec0 = 0.25677;
        mat_spec1 = 0.137622;
        mat_spec2 = 0.086014;
        shin =0.1;
        material(mat_amb0,mat_amb1,mat_amb2,mat_diff0,mat_diff1,mat_spec0,mat_spec1,mat_spec2,shin);  
        break;
        
    case 'r':
    
   //Propiedades del material red plastic
        mat_amb0 = 0.0;
        mat_amb1 = 0.0;
        mat_amb2 = 0.0;
        mat_diff0 = 0.5;
        mat_diff1 = 0.0;
        mat_diff2 = 0.0;
        mat_spec0 = 0.7;
        mat_spec1 = 0.6;
        mat_spec2 = 0.6;
        shin =0.25;
        material(mat_amb0,mat_amb1,mat_amb2,mat_diff0,mat_diff1,mat_spec0,mat_spec1,mat_spec2,shin);  
        break;
   
   case 'g':
    
   //Propiedades del material gold
        mat_amb0 = 0.24725;
        mat_amb1 = 0.1995;
        mat_amb2 = 0.0745;
        mat_diff0 = 0.75164;
        mat_diff1 = 0.60648;
        mat_diff2 = 0.22648;
        mat_spec0 = 0.628281;
        mat_spec1 = 0.555802;
        mat_spec2 = 0.366065;
        shin =0.4;
        material(mat_amb0,mat_amb1,mat_amb2,mat_diff0,mat_diff1,mat_spec0,mat_spec1,mat_spec2,shin);  
        break;
   
    case 'b':
    
   //Propiedades del material brass
        mat_amb0 = 0.329412;
        mat_amb1 = 0.223529;
        mat_amb2 = 0.027451;
        mat_diff0 = 0.780392;
        mat_diff1 = 0.568627;
        mat_diff2 = 0.113725;
        mat_spec0 = 0.992157;
        mat_spec1 = 0.941176;
        mat_spec2 = 0.807843;
        shin =0.21794872;
        material(mat_amb0,mat_amb1,mat_amb2,mat_diff0,mat_diff1,mat_spec0,mat_spec1,mat_spec2,shin);  
        break;
        case 's':
    
   //Propiedades del material silver
        mat_amb0 = 0.19225;
        mat_amb1 = 0.19225;
        mat_amb2 = 0.19225;
        mat_diff0 = 0.50754;
        mat_diff1 = 0.50754;
        mat_diff2 = 0.50754;
        mat_spec0 = 0.508273;
        mat_spec1 = 0.508273;
        mat_spec2 = 0.508273;
        shin =0.4;
        material(mat_amb0,mat_amb1,mat_amb2,mat_diff0,mat_diff1,mat_spec0,mat_spec1,mat_spec2,shin);  
        break;
        
    case 'q':
        exit(0);			// exit
    }
  glutPostRedisplay();   
} 

int main(int argc, char **argv)
{
// Inicializo OpenGL
 glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
 glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
 glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
 glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
 glutCreateWindow ("Esfera con Materiales y Luz");
// Inicializamos el sistema
 init();
 //calls
 glutMouseFunc(mouse);//llamando a la funcion mouse
 glutDisplayFunc(display);//llamando a display
 glutKeyboardFunc(keyboard);// llamando a funcion keyboard
 glutReshapeFunc(reshape);//llamando a la funcion reshape
 glutMainLoop();
 
 return 0;//retorna al sistema
}
