#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
 
void DrawLine(void)
{
    int x0, y0, x1, y1, dx, dy, x, y, p;

    std::cout << "Digite a coordenada (x, y) do primeiro pixel!";
    std::cin >> x0 >> y0;
    std::cout << "Digite a coordenada (x, y) do segundo pixel!";
    std::cin >> x1 >> y1;

    x = x0;
    y = y0;
    dx = x1 - x0;
    dy = y1 - y0;
    p = 0;

    if ((dx > 0) && (dy  > 0) && (dx >= dy)) {                     //Calcula no primeiro octante
        while (x <= x1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            x = x + 1;
            p = p + 2*dy;
            if (p >= dx) {
                y = y + 1;
                p = p - 2 * dx;
            }
        }
    } else if ((dx > 0) && (dy > 0) && (dy >= dx)) {                     //Calcula no segundo octante
        while (y <= y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y + 1;
            p = p + 2 * dx;
            if (p >= dx) {
                x = x + 1;
                p = p - 2 * dy;
            }
        }
    } else if ((dx < 0) && (dy < 0) && (abs(dx) >= abs(dy))) {                     //Calcula o terceiro octante
        while (x >= x1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            x = x - 1;
            p = p + 2 * dy;
            if (p <= dx) {
                y = y - 1;
                p = p - 2 * dx;
            }
        }
    } else if ((dx < 0) && (dy < 0) && (abs(dy) >= abs(dx))) {                      //Calcula o quarto octante
        while (y >= y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y - 1;
            p = p + 2 * dx;
            if (p <= dy) {
                x = x - 1;
                p = p - 2 * dy;
            }
        }
    } else if ((dx < 0) && (dy > 0) && (abs(dx) >= dy)) {                     //Calcula o quinto octante
        while (x >= x1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            x = x - 1;
            p = p - 2 * dy;
            if (p <= dx) {
                y = y + 1;
                p = p - 2 * dx;
            }
        }
    } else if ((dx < 0) && (dy > 0) && (dy >= abs(dx))) {                     //Calcula o sexto octante
        while (y <= y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y + 1;
            p = p - 2 * dx;
            if (p >= dy) {
                x = x - 1;
                p = p - 2 * dy;
            }
        }
    }else if ((dx > 0) && (dy < 0) && (dx >= abs(dy))) {                     //Calcula o sétimo octante
        while (x <= x1) { 
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            x = x + 1;
            p = p - 2 * dy;
            if (p >= dx) {
                y = y - 1;
                p = p - 2 * dx;
            }
        }
    } else if ((dx > 0) && (dy < 0) && (abs(dy) >= dx)) {                     //Calcula o oitavo octante
        while (y >= y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y - 1;
            p = p - 2 * dx;
            if (p <= dy) {
                x = x + 1;
                p = p - 2 * dy;
            }
        }
    } else if ((dx == 0) && (dy > 0)) {                                      //Calcula se a reta é vertical caso o dy seja positivo
        while (y <= y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y + 1;
        }
    } else if ((dy == 0) && (dx > 0)) {                                      //Calcula se a reta é horizontal caso o dx seja positivo
        while (x <= x1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            x = x + 1;
        }
    } else if ((dx == 0) && (dy < 0)) {                                      //Calcula se a reta é vertical caso o dy seja negativo
        while (y >= y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y - 1;
        }
    } else if ((dy == 0) && (dx < 0)) {                                      //Calcula se a reta é horizontal caso o dx seja negativo
        while (x >= x1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            x = x - 1;
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
    int a;
    std::cout << "O que deseja fazer? (1 para plotar o pixel, 2 para traçar a linha, 3 para o triangulo)";
    std::cin >> a;
    if (a == 1) {
        PutPixel();
    }
    else if (a == 2) {
        DrawLine();
    }
    else if (a == 3) {
        //DrawTriangle();
    }
    else {
        std::cout << "entrada desconhecida;";
        exit;
    }
}
