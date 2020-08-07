#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
// -e: caminho do arquivo de entrada
// -o: caminho para salvar a saida
// -f: nome do arquivo de entrada
// -q: nome do arquivo de consuta

int main(int argc, char** argv)
    {
        FILE* fileEntrada = abrirFileEntrada(argc, argv);
        FILE* fileSaida = abrirFileSaida( argc, argv);//deve existir apenas no main
        separarLinhas( argc,  argv,  fileEntrada, fileSaida);
        fclose(fileEntrada);
        fclose(fileSaida);
        return 0;
    }