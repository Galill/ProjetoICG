#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
 
void DrawLine(int *x0, int *y0, int *x1, int *y1)
{
    int dx, dy, x, y, p;

    x = *x0;
    y = *y0;
    dx = *x1 - *x0;
    dy = *y1 - *y0;
    p = 0;

    if ((dx > 0) && (dy  > 0) && (dx >= dy)) {                     //Calcula no primeiro octante
        while (x <= *x1) {
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
        while (y <= *y1) {
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
        while (x >= *x1) {
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
        while (y >= *y1) {
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
        while (x >= *x1) {
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
        while (y <= *y1) {
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
        while (x <= *x1) { 
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
        while (y >= *y1) {
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
        while (y <= *y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y + 1;
        }
    } else if ((dy == 0) && (dx > 0)) {                                      //Calcula se a reta é horizontal caso o dx seja positivo
        while (x <= *x1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            x = x + 1;
        }
    } else if ((dx == 0) && (dy < 0)) {                                      //Calcula se a reta é vertical caso o dy seja negativo
        while (y >= *y1) {
            FBptr[x * 4 + y * 512 * 4] = 255;
            FBptr[x * 4 + y * 512 * 4 + 1] = 0;
            FBptr[x * 4 + y * 512 * 4 + 2] = 0;
            FBptr[x * 4 + y * 512 * 4 + 3] = 255;
            y = y - 1;
        }
    } else if ((dy == 0) && (dx < 0)) {                                      //Calcula se a reta é horizontal caso o dx seja negativo
        while (x >= *x1) {
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

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    //Desenha uma linha ligando os dois primeiros pixels
    DrawLine(&x1, &y1, &x2, &y2);
    //Desenha uma linha ligando o segundo e o terceiro pixel
    DrawLine(&x2, &y2, &x3, &y3);
    //Desenha uma linha ligando o primeiro e o terceiro pixel
    DrawLine(&x1, &y1, &x3, &y3);
}
 
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    int a;
    std::cout << "O que deseja fazer? (1 para plotar o pixel, 2 para traçar a linha, 3 para o triangulo, 4 para traçar oito octantes, 5 para desenhar um triangulo padrão)";
    std::cin >> a;
    if (a == 1) {
        PutPixel();
    }
    else if (a == 2) {
        int xi, yi, xf, yf;
        std::cout << "Digite a coordenada (x, y) do primeiro pixel!";
        std::cin >> xi >> yi;
        std::cout << "Digite a coordenada (x, y) do segundo pixel!";
        std::cin >> xf >> yf;
        DrawLine(&xi, &yi, &xf, &yf);
    }
    else if (a == 3) {
        int a1, b1, a2, b2, a3, b3;
        std::cout << "Digite a coordenada (x, y) do primeiro pixel!";
        std::cin >> a1 >> b1;
        std::cout << "Digite a coordenada (x, y) do segundo pixel!";
        std::cin >> a2 >> b2;
        std::cout << "Digite a coordenada (x, y) do terceiro pixel!";
        std::cin >> a3 >> b3;

        DrawTriangle(a1, b1, a2, b2, a3, b3);
    }
    else if(a == 4){
        int coord1 = 0, coord2 = 256, coord3 = 512;

        //Desenha a linha (0, 0) (256, 256)
        DrawLine(&coord1, &coord1, &coord2, &coord2);
        //Desenha a linha (256, 256) (512, 512)
        DrawLine(&coord2, &coord2, &coord3, &coord3);
        //Desenha a linha (256, 0) (256, 256)
        DrawLine(&coord2, &coord1, &coord2, &coord2);
        //Desenha a linha (256, 256) (256, 512)
        DrawLine(&coord2, &coord1, &coord2, &coord3);
        //Desenha a linha (512, 0) (256, 256)
        DrawLine(&coord3, &coord1, &coord2, &coord2);
        //Desenha a linha (256, 256) (0, 512)
        DrawLine(&coord2, &coord2, &coord1, &coord3);
        //Desenha a linha (0, 256) (256, 256)
        DrawLine(&coord1, &coord2, &coord2, &coord2);
        //Desenha a linha (256, 256) (512, 256)
        DrawLine(&coord2, &coord2, &coord3, &coord2);

    }
    else if(a == 5) {
        int j = 30, k = 256, l = 482;

        //Desenha um triangulo a partir dos pixeis (256, 30) (30, 256) (482, 256)
        DrawLine(&k, &j, &j, &k);
        DrawLine(&k, &j, &l, &k);
        DrawLine(&j, &k, &l, &k);

    }
    else {
        std::cout << "entrada desconhecida;";
        exit;
    }
}
