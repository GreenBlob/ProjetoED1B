#pragma once
typedef struct node
{
    struct node* next;
    int index;
    int x;
    int y;
    int r;
    int w;
    int h;
    char *corb, *corp, *txto;
    char tipo;
}node;

char* getCaminhoEntradaPARCIAL(int argc, char** argv);
char* getcaminhoSaidaPARCIAL(int argc, char** argv);
char* getnomeEntrada(int argc, char** argv);
char* getnomeConsultaPARCIAL(int argc, char** argv);
char* getNomeSaida(int argc, char** argv);

char* getCaminhoEntradaCOMPLETO(int argc, char** argv);
char* getCaminhoSaidaCOMPLETO(int argc, char** argv);

FILE* abrirFileEntrada(int argc, char** argv);
FILE* abrirFileSaida(int argc,  char** argv);
void separarLinhas(int argc, char** argv, FILE* fileEntrada, FILE* fileSaida,FILE* qry);
void gerarSvg(char* car, FILE* fileSaida, int flag, node* head);
char* gerarCirculo(char* car, node* head);
char* gerarRetangulo(char* car, node* head);
char* gerarTexto(char *car, node* head);

FILE* abrirFileQry(int argc, char** argv);
node* startList();
node* addToList(node* head, int index, int xi, int yi, int ri, int rw, int rh, char* corb, char* corp, char* txto, char tipo);
void freeAll(node* head);
void qryF(int argc, char** argv, FILE* qry, node* head);
void gerarSvgQry(char* linha, FILE* qry, node* head);
void mocOF(char* linha, FILE* qry, node* head);
void mocIF(char* linha, FILE* qry, node* head);
void mocPntF(char* linha, FILE* qry, node* head);
void mocPntAF(char* linha, FILE* qry, node* head);
void mocDelfF(char* linha, FILE* qry, node* head);
void mocDelfAF(char* linha, FILE* qry, node* head);