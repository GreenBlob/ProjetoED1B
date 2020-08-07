/* Esse programa cria um arquivo SVG de acordo com as instrucoes dadas atravez do arquivo .geo.
    O executavel e os arquivos objeto sao criados atravez do comando make
    O executavel deve ser executado atravez do comando ./makesiguel -e (parametro)-o (parametro)-q (parametro)-f(parametro)
    Os parametros devem conter:
    -e: caminho do arquivo de entrada
    -o: caminho para a saida (.svg)
    -f: nome do arquivo de entrada
    -q: nome do arquivo de consuta

    Por falta de tempo, infelizmente nao consegui adicionar todas as funcionalidades requeridas
    pela primeira fase do trabalho.

    Esse programa cria um arquivo .svg de acordo com as intrucoes providas no arquivo .geo, mas nao
    le ou interpreta o arquivo de consulta .qry.

    As funcionalidades aux\sentes serao adicionadas nos proximos dias.
*/

#pragma once


char* getCaminhoEntradaPARCIAL(int argc, char** argv);
char* getcaminhoSaidaPARCIAL(int argc, char** argv);
char* getnomeEntrada(int argc, char** argv);
char* getnomeConsultaPARCIAL(int argc, char** argv);
char* getNomeSaida(int argc, char** argv);

char* getCaminhoEntradaCOMPLETO(int argc, char** argv);
char* getCaminhoSaidaCOMPLETO(int argc, char** argv);

FILE* abrirFileEntrada(int argc, char** argv);
FILE* abrirFileSaida(int argc,  char** argv);
void separarLinhas(int argc, char** argv, FILE* fileEntrada, FILE* fileSaida);
void gerarSvg(char* car, FILE* fileSaida, int flag);
char* gerarCirculo(char* car);
char* gerarRetangulo(char* car);
char* gerarTexto(char *car);