#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
//


void separarLinhas(int argc, char** argv, FILE* fileEntrada, FILE* fileSaida, FILE* qry) //Lê o arquivo e separa em linhas
{  
    node* head = startList();
    char footerSvg[] = "</svg>";
    char linha[1000];
    char *result ;
    int flag = 0; 
    while(fgets(linha, 1000, fileEntrada))
        {
        
        //printf("%s", result);
        
        //printf("%lu", strlen(flinha));
        gerarSvg(linha, fileSaida, flag, head);
        flag ++;
        }
    fputs(footerSvg, fileSaida);
    qryF(argc, argv, qry, head);
    printf("Fim\n");
    freeAll(head);
    

    return;    
}

void gerarSvg(char* car, FILE* fileSaida, int flag, node* head)
{
    char headerSvg[] = "<svg version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">\n";
    if(flag == 0)
    {
        fputs(headerSvg, fileSaida);
    }
    if(car != NULL)
    { 
        char inicial = car[0];
        switch(inicial)
        {
            case('c'): //circulo
            fputs(gerarCirculo(car, head), fileSaida);
            break; 

            case('r')://retangulo
            fputs(gerarRetangulo(car, head), fileSaida);
            break;

            case('t')://texto
            fputs(gerarTexto(car, head),fileSaida);
            break;

            case('n')://aumentar numero
            break;
        }
    }

    return;
}

char* gerarCirculo(char* car, node* head)
{
    char placeholder[1000];
    char cursor, tipo;
    char x[50], y[50], r[50], corb[50], corp[50], index[50];
    char *retorno;
    for (int m = 0; m<50; m++)
    {
        x[m] = '\0';
        y[m] = '\0';
        r[m] = '\0';
        corb[m] = '\0';
        corp[m] = '\0';
        index[m] = '\n'; 
    }
    int k = 0;
    int i = 0;
    int j = 0;
    cursor = car[0];
    //printf("%s", car);
    for(int i=0; i< 7; i++)
    { 
        j = 0;
        while(cursor != ' ' && cursor != '\0' && cursor != '\n')
        {

            //printf("%c  ",cursor);
            switch (i)
            {
                case (0)://
                tipo = cursor;
                break;

                case (1)://i
                index[j] = cursor;
                //printf("\nOk 1\n");
                break;

                case (2)://r
                //printf("\nOk 2\n");
                r[j] = cursor;
                break;
                
                case (3)://x
                //printf("\nOk 3\n");
                x[j] = cursor;
                break;
                
                case (4)://y
                //printf("\nOk 4\n");
                y[j] = cursor;
                break;
                
                case (5)://corb
                //printf("\nOk 5\n");
                corb[j] = cursor;
                break;
                
                case (6)://corp
                //printf("\nOk 6\n");
                corp[j] = cursor;
                break;
                
            }
            j++;
            k++;
            cursor = car[k];
        }
        k++;
        cursor = car[k];
    }
   
    sprintf (placeholder, "<circle cx=\"%s\" cy=\"%s\" r=\"%s\" stroke=\"%s\" stroke-width=\"4\" fill=\"%s\" />\n",x, y, r, corb, corp  );
    retorno = (char*)malloc(strlen(placeholder)+1);
    retorno = placeholder;
    int indexi = atoi(index);
    int xi = atoi(x);
    int yi = atoi(y);
    int ri = atoi(r);
    addToList(head, indexi, xi, yi, ri, 0, 0, corb, corp, "\0", tipo);
   return retorno;
}

char* gerarRetangulo(char* car, node* head) //<rect width=\"%s\" height=\"%s\" cx=\"%s\" yx=\"%s\"   stroke = \"%s" fill =\"%s\" />\n;
{                               // w h x y corb corp
    char placeholder[1000];
    char cursor, tipo;
    char x[50], y[50], h[50],w[50], corb[50], corp[50],index[50];
    char *retorno;
    for (int m = 0; m<50; m++)
    {
         x[m] = '\0';
        y[m] = '\0';
        h[m] = '\0';
        w[m] = '\0';
        corb[m] = '\0';
        corp[m] = '\0'; 
        index[m] = '\n'; 
    }
    int k = 0;
    int i = 0;
    int j = 0;
    cursor = car[0];
    //printf("%s", car);
    for(int i=0; i< 8; i++)
    { 
        j = 0;
        while(cursor != ' ' && cursor != '\0' && cursor != '\n')
        {

            //printf("%c  ",cursor);
            switch (i)
            {
                case (0)://
                tipo = cursor;
                break;

                case (1)://i
                index[j] = cursor;
                break;

                case (2)://r
                w[j] = cursor;
                break;
                
                case (3)://x
                h[j] = cursor;
                break;
                
                case (4)://y
                x[j] = cursor;
                break;
                
                case (5)://corb
                y[j] = cursor;
                break;
                
                case (6)://corp
                corb[j] = cursor;
                break;

                case (7):
                corp[j] = cursor;
                break;
                
            }
            j++;
            k++;
            cursor = car[k];
        }
        k++;
        cursor = car[k];
    }
    //printf("%s %s %s %s %s %s\n", w, h, x, y, corb, corp);
    sprintf (placeholder, "<rect width=\"%s\" height=\"%s\" x=\"%s\" y=\"%s\" stroke = \"%s\" fill =\"%s\" />\n",w, h, x, y, corb, corp  );
    retorno = (char*)malloc(strlen(placeholder)+1);
    retorno = placeholder;
    int indexi = atoi(index);
    int xi = atoi(x);
    int yi = atoi(y);
    int wi = atoi(w);
    int hi = atoi(h);
    addToList(head, indexi, xi, yi, 0, wi, hi, corb, corp, "\0", tipo);
   return retorno;
}

char* gerarTexto(char *car, node* head) //<text x=\"%s\" y=\"%s\" fill=\"%s\">%s</text>, i, x, y, corb, corp, txto
{                           //i x y corb corp txto
    {                               // w h x y corb corp
    char placeholder[1000];
    char cursor, tipo;
    char x[50], y[50], corb[50], corp[50], txto[100],index[50];;
    char *retorno;
    for (int m = 0; m<50; m++)
    {
        x[m] = '\0';
        y[m] = '\0';
        corb[m] = '\0';
        corp[m] = '\0'; 
        index[m] = '\n';
    }
    for(int n=0; n<100; n++)
    {
        txto[n] = '\0';
    }
    int k = 0;
    int i = 0;
    int j = 0;
    cursor = car[0];
    //printf("%s", car);
    for(int i=0; i< 7; i++)
    { 
        j = 0;
        while(cursor != ' ' && cursor != '\0' && cursor != '\n')
        {

            //printf("%c  ",cursor);
            switch (i)
            {
                case (0)://
                tipo = cursor;
                break;

                case (1)://i
                index[j] = cursor;
                break;

                case (2)://x
                x[j] = cursor;
                break;
                
                case (3)://y
                y[j] = cursor;
                break;
                
                case (4)://corb
                corb[j] = cursor;
                break;
                
                case (5)://corp
                corp[j] = cursor;
                break;
                
                case (6)://txto
                
                while(cursor != '\0' && cursor != '\n')
                {
                    txto[j] = car[k];
                    k++;
                    j++;
                    cursor = car[k];
                }
                break;
            }
            j++;
            k++;
            cursor = car[k];
        }
        k++;
        cursor = car[k];
    }
    //printf("%s %s %s %s %s \n", x, y, corb, corp, txto);
    sprintf (placeholder, "<text x=\"%s\" y=\"%s\" stroke = \"%s\" fill=\"%s\">%s</text>\n", x, y, corb, corp, txto  );
    retorno = (char*)malloc(strlen(placeholder)+1);
    retorno = placeholder;
    int indexi = atoi(index);
    int xi = atoi(x);
    int yi = atoi(y);
    addToList(head, indexi, xi, yi, 0, 0, 0, corb, corp, txto, tipo);
    return retorno;
    }
}

FILE* abrirFileEntrada(int argc, char** argv)//só posso abrir uma vez
{
    FILE* fileEntrada;
    char* entradaCompleta = getCaminhoEntradaCOMPLETO(argc, argv);
    fileEntrada = fopen(entradaCompleta, "r");
    if(fileEntrada == NULL)
    {
        printf("Erro ao abrir file de entrada.\n");
    }
    return fileEntrada;

}

FILE* abrirFileSaida(int argc, char** argv)//só posso abrir uma vez
{
    FILE* fileSaida;
    char* saidaCompleta = getCaminhoSaidaCOMPLETO(argc, argv);
    fileSaida = fopen(saidaCompleta, "w");
        if(fileSaida == NULL)
    {
        printf("Erro ao abrir file de saida.\n");
    }
    return fileSaida;

}

