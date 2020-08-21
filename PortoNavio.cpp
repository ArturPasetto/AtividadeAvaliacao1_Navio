// aula 3 ----- primitivas programa minimo
//////////////////////////////////////////

#include <stdlib.h>
#include <GL/glut.h>
#define largura_janela 400
#define altura_janela 400

void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

    glutInitWindowSize(largura_janela, altura_janela);  // tamanho da janela

    //glutFullScreen();  // full screen

    glutInitWindowPosition(10, 300); // posicao inicial da janela

    glutCreateWindow("Exercício criar casa");   /// cria a janela

    glutKeyboardFunc(&keyboard);

    glutReshapeFunc(&resize); // 

    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key){
        case '\x1B':
            exit(EXIT_SUCCESS);
        break;
    }
}

void resize(GLsizei w, GLsizei h)
{

    if (h == 0) h = 1;  // Evita a divisao por zero

    glViewport(0, 0, w, h);  // Especifica as dimensões da Viewport

   // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    if (w <= h)
    {
        gluOrtho2D(0.0f, largura_janela, 0.0f, altura_janela * h / w);
    }
    else
    {
        gluOrtho2D(0.0f, largura_janela * w / h, 0.0f, altura_janela);
    }
    glMatrixMode(GL_MODELVIEW);


}



void navio() {
    glBegin(GL_QUADS);
        glColor3f(0.75f, 0.25f, 0.0f);
        glVertex2f(-100, 0);
        glVertex2f(100.0, 0);
        glVertex2f(50.0, -50.0);
        glVertex2f(-50, -50.0);
    glEnd();
}

void mastro_um() {
    glBegin(GL_QUADS);
    glColor3f(0.75f,0.25f,0.0f);
    glVertex2f(-50.0, 75.0);
    glVertex2f(-62.5, 75.0);
    glVertex2f(-62.5, 0.0);
    glVertex2f(-50.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-50.0, 75.0);
    glVertex2f(-50.0, 25.0);
    glVertex2f(0, 50.0);
    glEnd();
}

void mastro_dois() {
    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.25f, 0.0f);
    glVertex2f(5.0, 125.0);
    glVertex2f(25.0, 125.0);
    glVertex2f(25.0, 0.0);
    glVertex2f(5.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(25.0, 125.0);
    glVertex2f(25.0, 75.0);
    glVertex2f(100.0, 100.0);
    glEnd();
}

void mastro_tres() {
    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.25f, 0.0f);
    glVertex2f(50.0, 75.0);
    glVertex2f(62.5, 75.0);
    glVertex2f(62.5, 0.0);
    glVertex2f(50.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(62.5, 75.0);
    glVertex2f(62.5, 25.0);
    glVertex2f(112.5, 50.0);
    glEnd();
}

void ancora() {
    glPointSize(3);
    glBegin(GL_POINTS);
        glColor3f(0.0f,0.0f,0.0f);


        int i = 0;
        for (i = 0; i > (-198); i -= 3) {
            if (i%2==0) {
                glVertex2f(45, i);
            }
            else {
                glVertex2f(44, i);
            }
        }

        glVertex2f(40, -190);
        glVertex2f(40, -192);
        glVertex2f(40, -195);
        glVertex2f(42, -198);
        //glVertex2f(40, -200);

        glVertex2f(48, -190);
        glVertex2f(48, -192);
        glVertex2f(48, -195);
        glVertex2f(46, -198);
        //glVertex2f(50, -200);

        glVertex2f(44, -198);
        glVertex2f(44, -200);

       
        //glVertex2f(50, -200);
    glEnd();
}

void pier() {
    glBegin(GL_QUADS);
        glColor3f(0.75f, 0.25f, 0.0f);
        glVertex2f(150.0, 0);
        glVertex2f(200.0, 0);
        glVertex2f(200.0, -25);
        glVertex2f(150.0, -25);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.75f, 0.25f, 0.0f);
        glVertex2f(150.0, -25);
        glVertex2f(175.0, -25);
        glVertex2f(175.0, -50);
        glVertex2f(150.0, -50);
    glEnd();
}

void mar() {

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(-200.0, -50);
    glVertex2f(200.0, -50);
    glVertex2f(200.0, -200);
    glVertex2f(-200.0, -200);
    glEnd();
}

void ceu() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.25f, 0.4f);
    glVertex2f(-200.0, 200.0);
    glVertex2f(200.0, 200.0);
    glColor3f(1.0f, 1.0f, 0.25f);
    glVertex2f(200.0, -200);
    glVertex2f(-200.0, -200);
    glEnd();
}


void display()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.5f, 0.25f, 0.5f, 1);  // cor do fundo

    glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

    glTranslatef(largura_janela / 2, altura_janela / 2, 0.0f);
    
    ceu();
    mar();
    navio();
    mastro_um();
    mastro_tres();
    mastro_dois();
    pier();
    ancora();
    
    glFlush(); // executa o desenho
}

