#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void qryF(int argc, char** argv,FILE* qry, node* head)
{
    char linha[1000];
    while(fgets(linha, 1000, qry))
        {
        gerarSvgQry(linha, qry, head);
        }
}

node* startList()
{
    node *head;
    head = (node*)malloc(sizeof(node));
    head ->index = 0;
    head ->next = NULL;
    return head;

}

node* addToList(node* head, int index, int xi, int yi, int ri, int rw, int rh, char* corb, char* corp, char* txto, char tipo)
{//head, index, xi, yi, ri, wi, hi, corb, corp, txto, tipo
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
    }
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->index = index;
    newNode->x = xi;
    newNode->y = yi;
    newNode->r = ri;
    newNode->w = rw;
    newNode->h = rh;
    newNode->corb = corb;
    newNode->corp = corp;
    newNode->txto = txto;
    newNode->tipo = tipo;

    temp = newNode;
    printf("%d \n", newNode->index);
    return temp->next;

}

void freeAll(node* head)
{
    node* temp = head;
    node* temp2;
    while(temp != NULL)
    {
        temp2 = temp;
        free(temp);
        temp = temp2->next;
    }
}

FILE* abrirFileQry(int argc, char** argv)
{
    FILE* qry;
    qry = (FILE*)malloc(sizeof(FILE));
    fopen(getnomeConsultaPARCIAL(argc, argv), "r");
    return qry;
}

void gerarSvgQry(char* linha, FILE* qry, node* head)
{
    int i=0;
    char comando[10];
    char *mocO = "-o";
    char *mocI = "-i";
    char *mocPnt = "pnt";
    char *mocPntA = "pnt*";
    char *mocDelf = "delf";
    char *mocDelfA = "delf*";
    while(linha[i] != ' ')
    {
        comando[i] = linha[i];
        i++;
    }
    if(strcmp(comando, mocO))
    {
        mocOF(linha, qry, head);
    }
    else if((strcmp(comando, mocI)))
    {
        mocIF(linha, qry, head);
    }
    else if((strcmp(comando, mocPnt)))
    {
        mocPntF(linha, qry, head);
    }
    else if((strcmp(comando, mocPntA)))
    {
        mocPntAF(linha, qry, head);
    }
    else if((strcmp(comando, mocDelf)))
    {
        mocDelfF(linha, qry, head);
    }
    else if((strcmp(comando, mocDelfA)))
    {
        mocDelfAF(linha, qry, head);
    }
}

void mocOF(char* linha, FILE* qry, node* head)
{
    int k = 0;
    int i = 0;
    int j = 0;
    char jF[] = "0000";
    char kF[] = "0000";

    char cursor = linha[0];
    //printf("%s", car);
    for(int i=0; i< 3; i++)
    { 
        j = 0;
        while(cursor != ' ' && cursor != '\0' && cursor != '\n')
        {

            //printf("%c  ",cursor);
            switch (i)
            {
                case (0)://
                break;

                case (1)://i
                jF[j] = cursor;
                //printf("\nOk 1\n");
                break;

                case (2)://r
                //printf("\nOk 2\n");
                kF[j] = cursor;
                break;

            }
            j++;
            k++;
            cursor = linha[k];
        }
        k++;
        cursor = linha[k];
    }
    int indexJ = atoi(jF);
    int indexK = atoi(kF);
    node* tempJ = head;
    node* tempK = head;

    for(int n = 0; n< indexJ; n++)
    {
            tempJ = tempJ->next;
    }
    for(int n = 0; n< indexK; n++)
    {
            tempK = tempK->next;
    }
    if(tempJ->tipo == 'c')
    {

    }
    else if(tempJ->tipo == 'r')
    {

    }
    else if(tempJ->tipo == 't')
    {
        
    }
}

void mocIF(char* linha, FILE* qry, node* head)
{

}

void mocPntF(char* linha, FILE* qry, node* head)
{

}

void mocPntAF(char* linha, FILE* qry, node* head)
{

}

void mocDelfF(char* linha, FILE* qry, node* head)
{

}

void mocDelfAF(char* linha, FILE* qry, node* head)
{

}