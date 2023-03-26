#include "definitions.h"
#include "mygl.h"
#include <GL/glew.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <gl/GL.h>

using namespace std;
 
void DrawLine(void)
{
     GLfloat x1 = 120, y1 = 50, x2 = 300, y2 = 100;
     GLfloat M, p, dx, dy, x, y, t;
     glClear(GL_COLOR_BUFFER_BIT);

     if ((x2 - x1) == 0) {                         
         M = (y2 - y1);
     }
     else {
         M = (y2 - y1) / (x2 - x1);                        
     }

     if (fabs(M) < 1) {

         if (x1 > x2) {

             t = x1;
             x1 = x2;
             x2 = t;

             t = y1;
             y1 = y2;
             y2 = t;
         }

         dx = fabs(x2 - x1);
         dy = fabs(y2 - y1);

         p = 2 * dy - dx;

         x = x1;
         y = y1;

         glColor3f(1.0, 1.0, 1.0);
         glBegin(GL_POINTS);
         while (x <= x2) {

             glVertex2f(x, y);
             x = x + 1;

             if (p >= 1) {

                 if (M < 1) {
                     y = y + 1;
                 }
                 else {
                     y = y - 1;
                 }
                 p = p + 2 * dy - 2 * dx;
             }
             else {
                 y = y;
                 p = p + 2 * dy;
             }
         }
         glEnd();
     }

     if (fabs(M) >= 1) {

         if (y1 > y2) {

             t = x1;
             x1 = x2;
             x2 = t;

             t = y1;
             y1 = y2;
             y2 = t;
         }

         dx = fabs(x2 - x1);
         dy = fabs(y2 - y1);

         p = 2 * dx - dy;

         x = x1;
         y = y1;

         glBegin(GL_POINTS);
         while (y <= y2) {

             glVertex2f(x, y);
             y = y + 1;

             if (p >= 1) {

                 if (M >= 1) {
                     x = x + 1;
                 }
                 else {
                     x = x - 1;
                 }
                 p = p + 2 * dx - 2 * dy;
             }
             else {
                 x = x;
                 p = p + 2 * dx;
             }
         }
         glEnd();
     }
     glFlush(); 
}   
void PutPixel(void) 
{   // Escreve um pixel vermelho na posicao (x, y) da tela:     para o pixel aparecer na posição (x, y) escolhida é necessário fazer o cálculo:  i = x * 4 + y * 512 * 4
    //                                                          quando encontrado o valor de i precisa - se mudar o valor de FBptr[] de modo que :

    FBptr[525312] = 255; // componente R                        FBptr[i]                                                                        
    FBptr[525312] = 0;   // componente G                        FBptr[i+1] 
    FBptr[525312] = 0;   // componente B                        FBptr[i+2]                                                                          
    FBptr[525312] = 255; // componente A                        FBptr[i+3] 
}

void DrawTriangle(void) 
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0, 1.0, 1.0);

     glBegin(GL_LINE_LOOP);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.4, 0.4);
        glVertex2f(0.3, 0.6);
        
     glEnd();
     glFlush();
}
 
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    PutPixel();
    DrawLine();
    DrawTriangle();
}