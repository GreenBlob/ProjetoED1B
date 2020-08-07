#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
//-e: caminho do arquivo de entrada
//-o: caminho para salvar a saida
//-f: nome do arquivo de entrada
//-q: nome do arquivo de consuta
//-e testesGeo/ -o saida/ -f hino-txt-002.geo -q testesGeo/
int main(int argc, char** argv)
    {
        FILE* fileEntrada = abrirFileEntrada(argc, argv);
        FILE* fileSaida = abrirFileSaida( argc, argv);//deve existir apenas no main
        FILE* qry = abrirFileQry(argc, argv);
        FILE* txt = abrirTxt(argc, argv);
        FILE* fileSaida2 = abrirFileSaidas(argc, argv);
        separarLinhas( argc,  argv,  fileEntrada, fileSaida, qry);
        fclose(fileEntrada);
        fclose(fileSaida);
        return 0;
    }