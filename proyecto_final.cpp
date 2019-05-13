//Semestre 2019-2
RCSE
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include <windows.h>
#include <mmsystem.h>
#include "cmodel/CModel.h"

#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

float pX = 0, pY = 0, pZ = 0, tamX = 1, tamY = 1, tamZ = 1, rot1 = 0;

//Para crear una figura

float rot = 0.0;
int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
//CTexture ladrillo;
//CTexture pisoMadera;
CTexture pisoLoceta;
CTexture pisoLocetaExt;
//CTexture bardaRustica;
CTexture tree;
//CTexture palmera1;
//CTexture palmera2;
//CTexture pino1;
//CTexture arbusto1;
//CTexture savila1;
//CTexture pvz2;
//CTexture pvz3;
//CTexture planta1;
//CTexture planta2;
//CTexture planta3;
//CTexture planta4;
//CTexture planta5;
//CTexture planta6;
//CTexture planta7;
//CTexture planta8;
//CTexture planta9;
//CTexture tree1;
CTexture pisojardin;

CTexture hoja;
CTexture door;
CTexture pasto;
CTexture alfombra;
CTexture garage;
CTexture gpiso;
CTexture paredpink;
CTexture ParedBlanca;
CTexture ParedBlanca2;
CTexture VentanaSimple;
CTexture Ventana;
CTexture verd;
CTexture manta;
CTexture azul;
CTexture alfombra4;
CTexture alfombra5;
CTexture tcesped1;

////Textura Muebles
CTexture cabecera;
CTexture SabanaColchon;
CTexture Buro;

CTexture buro;
CTexture cobijaac;
CTexture azulgris;
CTexture metallamp;
CTexture metallamp2;
CTexture tlamp1;
CTexture tlamp2;
CTexture bmetalico;
CTexture tlamp3;
CTexture tlamp4;

CFiguras sky;
//CFiguras fig2;
CFiguras bardas;
CFiguras obj;  //obj prisma, obj esfera.  obj.esfera


void lamp(GLuint textura1, GLuint textura2)
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-18.0, 0.20, -6.35);
	obj.cilindro(0.20, 0.05, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-18.0, 0.25, -6.35);
	obj.cilindro(0.03, 0.5, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-18.0, 0.75, -6.35);
	obj.cilindro(0.2, 0.6, 20, textura2);
	glEnable(GL_LIGHTING);
	glPopMatrix();

}

void cesped(GLuint textura1)
{
	GLfloat vertice[8][3] = {
		{ 0.0 ,0.0, 0.0 },    //Coordenadas Vértice 0 V0
	{ 1.0 ,0.0, 0.0 },    //Coordenadas Vértice 1 V1
	{ 1.0 ,1.0, 0.0 },    //Coordenadas Vértice 2 V2
	{ 0.0 ,1.0, 0.0 },    //Coordenadas Vértice 3 V3
	{ 0.0 ,0.0, 1.0 },    //Coordenadas Vértice 4 V4
	{ 1.0 ,0.0, 1.0 },    //Coordenadas Vértice 5 V5
	{ 1.0 ,1.0, 1.0 },    //Coordenadas Vértice 6 V6
	{ 0.0 ,1.0, 1.0 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();


	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();


	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(10.0, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(10.0, 10.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0, 10.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();

}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
	text1.LoadTGA("sky1.tga");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text3.LoadTGA("texturas/city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();
	
	pisojardin.LoadTGA("texturas/pisojardin.tga");
	pisojardin.BuildGLTexture();
	pisojardin.ReleaseImage();

	hoja.LoadTGA("texturas/hoja.tga");
	hoja.BuildGLTexture();
	hoja.ReleaseImage();

	door.LoadTGA("texturas/door.tga");
	door.BuildGLTexture();
	door.ReleaseImage();

	pasto.LoadTGA("texturas/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	alfombra.LoadTGA("texturas/alfombra.tga");
	alfombra.BuildGLTexture();
	alfombra.ReleaseImage();

	garage.LoadTGA("texturas/garage.tga");
	garage.BuildGLTexture();
	garage.ReleaseImage();

	gpiso.LoadTGA("texturas/gpiso.tga");
	gpiso.BuildGLTexture();
	gpiso.ReleaseImage();

	pisoLocetaExt.LoadTGA("texturas/pisogris.tga");
	pisoLocetaExt.BuildGLTexture();
	pisoLocetaExt.ReleaseImage();

	VentanaSimple.LoadTGA("texturas/VentanaSimple.tga");
	VentanaSimple.BuildGLTexture();
	VentanaSimple.ReleaseImage();
	
	paredpink.LoadTGA("texturas/paredpink.tga");
	paredpink.BuildGLTexture();
	paredpink.ReleaseImage();

	ParedBlanca2.LoadTGA("texturas/ParedBlanca2.tga");
	ParedBlanca2.BuildGLTexture();
	ParedBlanca2.ReleaseImage();

	//texturas muebles
	
	buro.LoadTGA("texturas/buro.tga");//buro
	buro.BuildGLTexture();
	buro.ReleaseImage();

	azulgris.LoadTGA("texturas/azulgris.tga");
	azulgris.BuildGLTexture();
	azulgris.ReleaseImage();

	metallamp.LoadTGA("texturas/metallamp.tga");
	metallamp.BuildGLTexture();
	metallamp.ReleaseImage();

	metallamp2.LoadTGA("texturas/metallamp2.tga");
	metallamp2.BuildGLTexture();
	metallamp2.ReleaseImage();

	tlamp1.LoadTGA("texturas/lamp2.tga");
	tlamp1.BuildGLTexture();
	tlamp1.ReleaseImage();

	bmetalico.LoadTGA("texturas/bmetalico.tga");
	bmetalico.BuildGLTexture();
	bmetalico.ReleaseImage();

	verd.LoadTGA("texturas/verd.tga");
	verd.BuildGLTexture();
	verd.ReleaseImage();

	manta.LoadTGA("texturas/manta.tga");
	manta.BuildGLTexture();
	manta.ReleaseImage();

	azul.LoadTGA("texturas/azul.tga");
	azul.BuildGLTexture();
	azul.ReleaseImage();

	alfombra4.LoadTGA("texturas/alfombra4.tga");
	alfombra4.BuildGLTexture();
	alfombra4.ReleaseImage();

	alfombra5.LoadTGA("texturas/alfombra5.tga");
	alfombra5.BuildGLTexture();
	alfombra5.ReleaseImage();

	tree.LoadTGA("texturas/tree.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	cabecera.LoadTGA("texturas/cabecera.tga");
	cabecera.BuildGLTexture();
	cabecera.ReleaseImage();

	SabanaColchon.LoadTGA("Muebles/SabanaColchon.tga");
	SabanaColchon.BuildGLTexture();
	SabanaColchon.ReleaseImage();

	Buro.LoadTGA("Muebles/Buro.tga");
	Buro.BuildGLTexture();
	Buro.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();	
	

	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	
		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(-20,67,-35);
				glColor3f(1.0, 1.0, 1.0);
				sky.skybox(180.0, 180.0, 180.0,text1.GLindex);// Cielo
				glEnable(GL_LIGHTING);
				//glColor3f(1.0, 1.0, 1.0);
			glPopMatrix();
			//Colocamos codigo 
			//Elementos que dibujaremos
	glPushMatrix();///////////////////////////
			

			///////////////////////////////////////////////////////////////////////////////jardin
			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-40.80, -4.99, 22.10);
			bardas.prisma(0.01,3.80,2.25, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-41.20, -4.99, 16.61);
			glRotatef(45, 0, 1, 0);
			bardas.prisma(0.01, 3.86, 2.34, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-39.40, -4.99, 18.80);
			glScalef(1, 0.01, 1);
			bardas.esfera(1.4, 20, 20, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-41.50,-4.99,13);
			glScalef(0.49, 0.01, 1.31);
			bardas.esfera(1.4, 20, 20, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-39.20, -4.99, 13.70);
			glScalef(0.49, 0.01, 1.31);
			bardas.esfera(1.4, 20, 20, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-40.40, -4.99, 9.90);
			glRotatef(-45, 0, 1, 0);
			bardas.prisma(0.01, 3.56, 2.83, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////////////////////////////////////////////////////////////loceta puerta garage 
			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, -9.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, -5.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, -1.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, 3.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, 7.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, 12.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, 17.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//loceta piso
			glDisable(GL_LIGHTING);
			glTranslatef(-22, -4.99, 22.10);
			bardas.prisma(0.01, 7.80, 3.5, gpiso.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////////////////////////////////////////////////////////////////////////Cesped
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(-38, -5, -2.89);
				glScalef(10,1,2.79);
				cesped(pasto.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
		//////////////////////////////////////////////////////////////plantas 
			 glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-36,1.0,-1);
			obj.esfera(0.9, 2, 20, hoja.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //tronco
			glDisable(GL_LIGHTING);
			glTranslatef(-36,-7.0,-1);
			obj.cilindro(0.03, 7.28, 20, tree.GLindex); //textura tronco arbol
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();//2
			glDisable(GL_LIGHTING);
			glTranslatef(-33, 1.0, -1);
			obj.esfera(0.9, 2, 20, hoja.GLindex); 
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //tronco arbol
			glDisable(GL_LIGHTING);
			glTranslatef(-33, -7.0, -1);
			obj.cilindro(0.03, 7.28, 20, tree.GLindex); //textura tronco arbol
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();//3
			glDisable(GL_LIGHTING);
			glTranslatef(-30, 1.0, -1);
			obj.esfera(0.9, 2, 20, hoja
				.GLindex); 
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //tronco arbol
			glDisable(GL_LIGHTING);
			glTranslatef(-30, -7.0, -1);
			obj.cilindro(0.03, 7.28, 20, tree.GLindex); //textura tronco arbol
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();  ///////////////////////////////////////////////////////////CESPED PUERTAA
				glDisable(GL_LIGHTING);
				glTranslatef(-59.80, -5.10, 1.30);
				glScalef(35, 0.01, 25);
				cesped(pasto.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();///////////////////////////////////cesped derecha
			glDisable(GL_LIGHTING);
			glTranslatef(-27.7, -5.0, -70);
			glScalef(40, 0.01, 95);
			cesped(pasto.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			/////////////////////////CESPED ORILLAS 
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-27.7, -5.0, -70);
			glScalef(40, 0.01, 95);
			cesped(pasto.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-85.7, -5.0, -70);
			glScalef(35, 0.01, 95);
			cesped(pasto.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			////////////////////////////////////////////////////////////7muebles
			glDisable(GL_LIGHTING);
			glPushMatrix();//Cama 	
			glPushMatrix();//Cabecera
			glTranslatef(-37,1.5,-39.7);
			glRotatef(180, 0.0, 1.0, 0.0);
			bardas.prisma(5, 10, 0.5, cabecera.GLindex);
			glPopMatrix();

			glPushMatrix();//Colchon rosa
			glTranslatef(-37, -1.3,-35.7);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(6.7, 2.7, 4, manta.GLindex);
			glPopMatrix();
			//glPushMatrix();//Cobija
			//glTranslatef(-37.1, 0.70, -35.7);
			//glRotatef(90, 1.0, 0.0, 0.0);
			//bardas.prisma(6.7, 2.7, 0.1, CabeceraColchon.GLindex);
			//glPopMatrix();
			glPushMatrix();//Almohada
			glTranslatef(-37,0.70,-37.7);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(1.6, 1.3, 1.2, SabanaColchon.GLindex);
			glPopMatrix();
			
			glPushMatrix();//Colchon verde
			glTranslatef(-40, -1.3, -35.7);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(6.7, 2.7, 4, verd.GLindex);
			glPopMatrix();
			glPushMatrix();//Almohada
			glTranslatef(-40, 0.70, -37.7);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(1.6, 1.3, 1.2, SabanaColchon.GLindex);
			glPopMatrix();

			glPushMatrix();//Colchon azul
			glTranslatef(-34, -1.3, -35.7);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(6.7, 2.7, 4, azul.GLindex);
			glPopMatrix();
		
			glPushMatrix();//Almohada
			glTranslatef(-34, 0.70, -37.7);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(1.6, 1.3, 1.2, SabanaColchon.GLindex);
			glPopMatrix();

			glPopMatrix();

		//////////////////////////////////////////////////////	////Creacion del Buro		
			glPushMatrix();//Mueble
			glTranslatef(-44, -1.3, -35.7);
			//glRotatef(180, 0.0, 1.0, 0.0);
			bardas.prisma(3, 1.5, 1.5, cabecera.GLindex);
			glPopMatrix();

			glPushMatrix();//Frente
			glTranslatef(-44, -1.3, -34.99);
			//glRotatef(180, 0.0, 1.0, 0.0);
			bardas.prisma(3, 1.5, 0.1, Buro.GLindex);
			glPopMatrix();

			glPopMatrix();

			//////////////////////////////////////////////////////////Creacion del Buro 2
			glPushMatrix();//Mueble
			glTranslatef(-30, -2.5, -22.5);
			//glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(3, 1.5, 1.5, cabecera.GLindex);
			glPopMatrix();

			glPushMatrix();//Frente
			glTranslatef(-30.8, -2.5, -22.5);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(3, 1.5, 0.1, Buro.GLindex);
			glPopMatrix();

			glPushMatrix();//repisa
			glTranslatef(-31, 5, -40.5);
			//glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(0.55, 1.7, 0.4, cabecera.GLindex);
			glPopMatrix();

			glPushMatrix();//repisa 2
			glTranslatef(-31, 7, -40.5);
			bardas.prisma(0.55, 1.7, 0.4, cabecera.GLindex);
			glPopMatrix();

			glPushMatrix();//repisa libros
			glTranslatef(-43, 7, -40.5);
			bardas.prisma(0.55, 1.7, 0.4, cabecera.GLindex);
			glPopMatrix();

			///////////////////////////////////////////////////LIBROS
			//glPushMatrix();//pata
			//glTranslatef(3.25, -2.75, 0);
			//glRotatef(90, 0.0, 1.0, 0.0);
			//bardas.prisma(5, 1, 0.5, Cabecera.GLindex);
			//glPopMatrix();
			
		
			/////////////////////////////////////////////////////////////////////////lampara de buro
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(-8.49 - 1.30, -3.39+ 3.19, -22.50 - 1.40);
				glScaled(1 + 0.90, 1 + 0.90, 1 + 0.90);
				lamp(metallamp.GLindex, tlamp1.GLindex);  //cambiar la textura
				glEnable(GL_LIGHTING);
			glPopMatrix();

	
/////////////////////////////////////////////////////////////CONSTRUCCION BARDAS
			glPushMatrix();//19 Pivote
			glDisable(GL_LIGHTING);
			glTranslatef(0, 5, -11.25);
			glRotatef(90, 0.0, 1.0, 0.0);
			glEnable(GL_LIGHTING);
			glPopMatrix();

////////////////////////////////////CASA CENTRAL 
			glPushMatrix();//Fachada
			glDisable(GL_LIGHTING);
			glTranslatef(-46.5, 5.5, -2.9);
			bardas.prisma(60, 3, 0.2, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Puerta Fachada Barda Arriba
			glDisable(GL_LIGHTING);
			glTranslatef(-37, 28, -2.9);
			bardas.prisma(16, 18, 0.01, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glPushMatrix();//circulos ventanas
			glDisable(GL_LIGHTING);
			glTranslatef(-42, 28, -2.9);
			obj.esfera(2,25, 25, VentanaSimple.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glBindTexture(GL_TEXTURE_2D, 0);
			glDisable(GL_BLEND);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glPushMatrix();//circulos ventanas
			glDisable(GL_LIGHTING);
			glTranslatef(-37, 28, -2.9);
			obj.esfera(2, 25, 25, VentanaSimple.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glBindTexture(GL_TEXTURE_2D, 0);
			glDisable(GL_BLEND);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glPushMatrix();//circulos ventanas
			glDisable(GL_LIGHTING);
			glTranslatef(-32, 28, -2.9);
			obj.esfera(2, 25,25, VentanaSimple.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glBindTexture(GL_TEXTURE_2D, 0);
			glDisable(GL_BLEND);
			////////////////////////////////////////Creacion de las PAREDES
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-48, 0, -23);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(70, 40.0, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();//dentro cuarto
			glDisable(GL_LIGHTING);
			glTranslatef(-47.7, 0, -22.7);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(69, 39.5, 0.6, paredpink.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-28, 0, -25.5);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(70, 34.5, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();//dentro cuarto
			glDisable(GL_LIGHTING);
			glTranslatef(-29, 0, -25);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(69, 34, 0.6, paredpink.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////////////////////////pared ventana abajo pricipal
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-33, -1.3, -2.9);
			bardas.prisma(7.7, 10.5, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			///////////////////////////////////ventana abajo pared
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-28, -1.3, -5.5);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(7.7, 5.5, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//////////////////////////////ventana arriba pared
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-28, 26.5, -5.5);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(17.7, 5.5, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//atras
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-38, 0, -43);
			glRotatef(180, 0.0, 1.0, 0.0);
			bardas.prisma(70, 20.0, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();//dentro cuarto
			glDisable(GL_LIGHTING);
			glTranslatef(-38, 0, -42);
			glRotatef(180, 0.0, 1.0, 0.0);
			bardas.prisma(69, 19, 0.6, paredpink.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();// Puerta Entrada
			glDisable(GL_LIGHTING);
			glTranslatef(-41.7, 6.0, -2.9);
			//glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(28, 7, 0.01, door.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//pared ventana y puerta
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-37, 11.0, -2.9);
			bardas.prisma(18, 2.5, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//arriba ventana puerta 
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-32, 19, -2.9);
			bardas.prisma(2.5, 8, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			/////////////////////////Loceta exterior cubre todo el terreno
			glPushMatrix();//loceta exterior
			glDisable(GL_LIGHTING);
			glTranslatef(-41.7, -5.1, -37.5);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(125, 60, 0.01, pisoLocetaExt.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//Ventana Simple Vidrio Fachada
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-32, 10.0, -2.9);
			bardas.prisma(15.2, 8., 0.01, VentanaSimple.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glBindTexture(GL_TEXTURE_2D, 0);
			glDisable(GL_BLEND);
			//Ventana Simple Vidrio Fachada
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-28, 10.0, -5.9);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(15.2, 6.5, 0.01, VentanaSimple.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glBindTexture(GL_TEXTURE_2D, 0);
			glDisable(GL_BLEND);
			/////////////////////////////////////////////////////////GARAGE
			//Creacion de las PAREDS
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-22, 0, -28);
			glRotatef(180, 0.0, 1.0, 0.0);
			bardas.prisma(25, 12, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//puerta arriba
			glDisable(GL_LIGHTING);
			glTranslatef(-22, 12, -12);
			glRotatef(180, 0.0, 1.0, 0.0);
			bardas.prisma(3.5, 12, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-16, 0, -20);
			glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(25, 17, 0.6, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			// Techo
				glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-21.5, 13, -19.5);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(19, 10, 0.2, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

		//puerta garageeeeeeeeeee
			glPushMatrix();// Puerta Entrada
			glDisable(GL_LIGHTING);
			glTranslatef(-22, 0, -12);
			//glRotatef(90, 0.0, 1.0, 0.0);
			bardas.prisma(20, 12, 0.6, garage.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			// Techo 
			glPushMatrix();// Techo mas grande
			glDisable(GL_LIGHTING);
			glTranslatef(-38, 34, -22.5);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(39, 20, 0.2, ParedBlanca2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();// Pisoo
			glDisable(GL_LIGHTING);
			glTranslatef(-38, -4, -22.5);
			glRotatef(90, 1.0, 0.0, 0.0);
			bardas.prisma(39, 20, 0.2, alfombra.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

	glPopMatrix();

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{

	/*fig2.text_izq -= 0.001;
	fig2.text_der -= 0.001;
	if (fig2.text_izq<-1)
		fig2.text_izq = 0;
	if (fig2.text_der<0)
		fig2.text_der = 1;
	*/
	rot += 00000000000000000000.1;


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 400.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 'x':
	case 'X':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case ' ':		//Poner algo en movimiento
					//g_fanimacion^= true; //Activamos/desactivamos la animacíon
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;

	//case 'b':
	//	pX += 0.1;
	//	break;

	//case 'B':
	//	pX -= 0.1;
	//	break;

	//case 'n':
	//	pY += 0.1;
	//	break;

	//case 'N':
	//	pY -= 0.1;
	//	break;

	//case 'm':
	//	pZ += 0.1;
	//	break;

	//case 'M':
	//	pZ -= 0.1;
	//	break;
	//	///////////////////////////////////////////////////////////////////////////
	//case 'j':
	//	tamX += 0.01;
	//	break;

	//case 'J':
	//	tamX -= 0.01;
	//	break;

	//case 'k':
	//	tamY += 0.01;
	//	break;

	//case 'K':
	//	tamY -= 0.01;
	//	break;

	//case 'l':
	//	tamZ += 0.01;
	//	break;

	//case 'L':
	//	tamZ -= 0.01;
	//	break;

	//case '+':
	//	rot1 += 1.0;
	//	break;

	//case '-':
	//	rot1 -= 1.0;
	//	break;

	//case 'P':
	//case 'p':
	//	printf("tamX %f\n", tamX);
	//	printf("tamY %f\n", tamY);
	//	printf("tamZ %f\n", tamZ);

	//	printf("posX %f\n", pX);
	//	printf("posY %f\n", pY);
	//	printf("posZ %f\n", pZ);

	//	printf("Rot %f\n", rot);
	//	break;


	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
