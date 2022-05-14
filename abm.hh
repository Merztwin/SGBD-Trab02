#pragma once
#include <cstdbool>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<climits>
#include <vector>

class ABM; //self explanatory classes
class NoArvBmais
{
	bool seFolha = false;
	int *chaves, tamanho;
	NoArvBmais** ponteiro;
	friend class ABM;
public:
	NoArvBmais();
};

class ABM
{
    const int MAX = 10;
	NoArvBmais *raiz;
	void incluiInterno(int,NoArvBmais*,NoArvBmais*);
	bool removeInterno(int,NoArvBmais*,NoArvBmais*);
	NoArvBmais* encontraPai(NoArvBmais*,NoArvBmais*);
public:
	ABM();
	void BuscaNoArvBMais(int chave);
	void BuscaMaiorNoArvBMais(int chave);
	void BuscaMaiorNoArvBMenos(int chave);
	void InclusaoNoArvBMais(int chave);
	bool RemoveNoArvBMais(int chave);
	void display(NoArvBmais*);
	NoArvBmais* getRaiz();
	void cleanUp(NoArvBmais*);
	~ABM();
};