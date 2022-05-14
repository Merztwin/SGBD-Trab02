#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "abm.hh"


int main(int argc, char** argv)
{
    // printf("Hello world! \n");
    // for (int i = 1; i < argc; ++i)
    //     std::cout << argv[i] << "\n";
    std::ifstream inputStream("in.txt");
    std::string line;

    ABM minhaAbm;
    std::string operacao;
    std::string auxValor;
    int valor;

    std::ofstream clearOut;
    clearOut.open("out.txt", std::ofstream::out | std::ofstream::trunc);
    clearOut.close();

    while (getline(inputStream, line)) 
    {
        operacao = line.substr(0, 3);
        if(operacao=="BUS")
        {
            operacao = line.substr(0, 4);
            auxValor = line.substr(5, line.length()-1);
            valor = std::stoi(auxValor);

            if (operacao=="BUS=")
            {
                minhaAbm.BuscaNoArvBMais(valor);
            }
            else if (operacao=="BUS>")
            {
                minhaAbm.BuscaMaiorNoArvBMais(valor);
            }
            else if (operacao=="BUS<")
            {
                minhaAbm.BuscaMaiorNoArvBMenos(valor);
            }
        }
        else
        {
            auxValor = line.substr(4, line.length()-1);
            valor = std::stoi(auxValor);

            if(operacao=="INC")
            {
                minhaAbm.InclusaoNoArvBMais(valor);
            }
            else if(operacao=="REM")
            {
                if(minhaAbm.RemoveNoArvBMais(valor))
                {
                    std::string line;

                    int numberOperations = 0;
                    std::string nomeArquivo = std::to_string(valor)+".txt";
                    std::ifstream textStream(nomeArquivo);

                    std::ofstream output;
                    output.open("out.txt",std::ofstream::app);

                    while (getline(textStream, line)) 
                    {
                        numberOperations++;
                    }
                    output << "REM:" << numberOperations << std::endl;
	                output.close();

                    std::ofstream clearArq;
                    clearArq.open(nomeArquivo, std::ofstream::out | std::ofstream::trunc);
                    clearArq.close();

                }
            }
            else 
            {
                std::cerr << "Sem comandos! \n";
                return EXIT_FAILURE;
            }
        }
    }
    // std::cout << operacao << " realizada com valor " << argv[2] << "\n";
    return EXIT_SUCCESS;
}