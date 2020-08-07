#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


char *getCaminhoEntradaPARCIAL(int argc, char** argv)//-e
{
    char dirEntry[] = "-e"; //flag caminho do arquivo de entrada
    char *caminhoEntrada;
    caminhoEntrada = NULL;
    for( int i=0; i<argc; i++)
        {
            if(strcmp (argv[i], dirEntry) == 0) //próximo argumento será caminho de entrada
            {
                caminhoEntrada = argv[i+1];
            }
        }
    
    return caminhoEntrada;
}

char *getcaminhoSaidaPARCIAL(int argc, char** argv)//-o
{
    char dirOut[] = "-o"; //flag caminho do arquivo de saida
    char *caminhoSaida;
    caminhoSaida = NULL;


    for( int i=0; i<argc; i++)
    {
        if(strcmp (argv[i], dirOut) == 0) //próximo argumento será caminho de saída
        {
            caminhoSaida = argv[i+1];
        }  
    }
    return caminhoSaida;
}

char *getnomeEntrada(int argc, char** argv)//-f
{
    char arqEntry[] = "-f"; //flag nome do arquivo de entrada
    char  *nomeEntrada;
    nomeEntrada = NULL;


    for( int i=0; i<argc; i++)
    {
        if(strcmp (argv[i], arqEntry) == 0) //próximo argumento será nome do arquivo de entrada
        {
            nomeEntrada= argv[i+1];
        }   
    }
    return nomeEntrada;
}

char *getnomeConsultaPARCIAL(int argc, char** argv)//-q
{
    char arqCons[] = "-q"; //flag nome do arquivo de consulta
    char *nomeConsulta;
    nomeConsulta = NULL;


    for( int i=0; i<argc; i++)
    {

        if(strcmp (argv[i], arqCons) == 0) //próximo argumento será nome do arquivo de consulta
        {
            nomeConsulta = argv[i+1];
        }
        
    }
    return nomeConsulta;
}

char *getNomeSaida(int argc, char** argv)  //modifica nome da entrada
{
    char* nomeSaida;
    char* nomeEntrada = getnomeEntrada(argc, argv);
    char svgExtension[] = "svg";

    nomeSaida = (char*)malloc(strlen(nomeEntrada)+1);
    if (nomeSaida == NULL)
    {
        printf("Falha ao alocar memória\n");
        
    }
    int i = 0;
    nomeSaida[i] = nomeEntrada[i];
    while (nomeEntrada[i] != '.')
    {
        i++;
        nomeSaida[i] = nomeEntrada[i];
    }
    nomeSaida = strcat(nomeSaida, svgExtension);

    return nomeSaida;

}

char* getCaminhoEntradaCOMPLETO(int argc, char** argv)
{
    char* caminhoEntradaParcial = getCaminhoEntradaPARCIAL(argc, argv);
    char* nomeEntrada = getnomeEntrada(argc, argv);
    char* caminhoEntradaCOMPLETO;
    caminhoEntradaCOMPLETO = (char*)malloc(strlen(caminhoEntradaParcial) + strlen(nomeEntrada) +1);
    if(caminhoEntradaParcial != NULL)
    {
    strcpy(caminhoEntradaCOMPLETO, caminhoEntradaParcial);
    strcat(caminhoEntradaCOMPLETO, nomeEntrada);       
    }
    else
    {
        caminhoEntradaCOMPLETO = nomeEntrada;
    }
    return caminhoEntradaCOMPLETO;
}

char* getCaminhoSaidaCOMPLETO(int argc, char** argv)
{
    char *caminhoSaida = getcaminhoSaidaPARCIAL(argc, argv);
    char *nomeSaida = getNomeSaida(argc, argv);
    char *caminhoSaidaCompleto;
    caminhoSaidaCompleto = (char*)malloc(strlen(caminhoSaida) + strlen(nomeSaida) + 1);
    strcpy(caminhoSaidaCompleto,caminhoSaida);
    strcat(caminhoSaidaCompleto,nomeSaida);
    return caminhoSaidaCompleto;
}
