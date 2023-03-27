#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
 
void DrawLine(void)
{
    int x0, y0, x1, y1, dx, dy, x, y, p;
    float M;

    std::cout << "Digite a coordenada (x, y) do primeiro pixel!";
        std::cin >> x0 >> y0;
    std::cout << "Digite a coordenada (x, y) do segundo pixel!";
        std::cin >> x1 >> y1;

    x = x0;
    y = y0;
    dx = x1 - x0;
    dy = y1 - y0;
    p = 2 * dy - dx;
    if ((x1 - x0) == 0) {
        M = dy;
    }
    else {
        M = dy / dx;
    }

    if (M < 1) {
        while (x < x1) {
            if (p >= 0) {
                FBptr[x * 4 + y * 512 * 4] = 255;
                FBptr[x * 4 + y * 512 * 4 + 1] = 0;
                FBptr[x * 4 + y * 512 * 4 + 2] = 0;
                FBptr[x * 4 + y * 512 * 4 + 3] = 255;
                y = y + 1;
                p = p + 2 * dy - 2 * dx;
            }
            else {
                FBptr[x * 4 + y * 512 * 4] = 255;
                FBptr[x * 4 + y * 512 * 4 + 1] = 0;
                FBptr[x * 4 + y * 512 * 4 + 2] = 0;
                FBptr[x * 4 + y * 512 * 4 + 3] = 255;
                p = p + 2 * dy;
            }
            x = x + 1;
        }
    }
    else  if (M >= 1) {
        while (y < y1) {
            if (p >= 0) {
                FBptr[x * 4 + y * 512 * 4] = 255;
                FBptr[x * 4 + y * 512 * 4 + 1] = 0;
                FBptr[x * 4 + y * 512 * 4 + 2] = 0;
                FBptr[x * 4 + y * 512 * 4 + 3] = 255;
                x = x + 1;
                p = p + 2 * dy - 2 * dx;
            }
            else {
                FBptr[x * 4 + y * 512 * 4] = 255;
                FBptr[x * 4 + y * 512 * 4 + 1] = 0;
                FBptr[x * 4 + y * 512 * 4 + 2] = 0;
                FBptr[x * 4 + y * 512 * 4 + 3] = 255;
                p = p + 2 * dx;
            }
            y = y + 1;
        }
    }
}   
void PutPixel(void) 
{   
    // Escreve um pixel vermelho na posição (x, y) da tela:     para o pixel aparecer na posição (x, y) escolhida é necessário fazer o cálculo:  i = x * 4 + y * 512 * 4
    //                                                          quando encontrado o valor de i precisa - se mudar o valor de FBptr[] de modo que :
    int x = 0, y = 0, i;
    std::cout << "Digite a coordenada (x, y) do seu pixel!";
        std::cin >> x >> y;

    i = x * 4 + y * 512 * 4;

    FBptr[i] = 255; // componente R                            FBptr[i]                                                                        
    FBptr[i + 1] = 0;   // componente G                        FBptr[i+1] 
    FBptr[i + 2] = 0;   // componente B                        FBptr[i+2]                                                                          
    FBptr[i + 3] = 255; // componente A                        FBptr[i+3] 
}

void DrawTriangle(void) 
{
     
}
 
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    PutPixel();
    DrawLine();
    DrawTriangle();
}
