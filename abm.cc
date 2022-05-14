#include "abm.hh"
#include <string>

NoArvBmais::NoArvBmais()
{
	chaves = new int[9];
	ponteiro = new NoArvBmais*[10];
}
ABM::ABM()
{
	raiz = NULL;
}

ABM::~ABM()
{
	
}

void ABM::BuscaNoArvBMais(int chaveBusca)
{
	if(raiz==NULL)
	{
		std::cout<<"Árvore vazia! \n";
	}
	else
	{
		NoArvBmais* noAtual = raiz;
		while(!noAtual->seFolha)
		{
			for(int i=0;i<noAtual->tamanho;i++)
			{
				if(chaveBusca < noAtual->chaves[i])
				{
					noAtual = noAtual->ponteiro[i];
					break;
				}
				if(i==(noAtual->chaves[i]+1))
				{
					noAtual = noAtual->ponteiro[i];
					break;
				}
			}
		}
		for(int i=0;i<noAtual->tamanho;i++)
		{
			if(noAtual->chaves[i]==chaveBusca)
			{
				std::string nomeArquivo = std::to_string(chaveBusca)+".txt";
				std::ifstream inputStream(nomeArquivo);
				if(!inputStream)
					std::cerr << "Arquivo não encontrado! \n";

				std::string line;

				int numberOperations = 0;
				std::ofstream output;
				output.open("out.txt",std::ofstream::app);

				while (getline(inputStream, line)) 
				{
					std::cout << line << "\n";
					numberOperations++;
				}

				output << "BUS>:" << numberOperations << std::endl;
				output.close();
			}
		}
	}
}


void ABM::BuscaMaiorNoArvBMais(int chaveBusca)
{
	if(raiz==NULL)
	{
		std::cout<<"Árvore vazia! \n";
	}
	else
	{
		NoArvBmais* noAtual = raiz;
		while(!noAtual->seFolha)
		{
			for(int i=0;i<noAtual->tamanho;i++)
			{
				if(chaveBusca < noAtual->chaves[i])
				{
					noAtual = noAtual->ponteiro[i];
					break;
				}
				if(i==(noAtual->chaves[i]+1))
				{
					noAtual = noAtual->ponteiro[i];
					break;
				}
			}
		}
		for(int i=0;i<noAtual->tamanho;i++)
		{
			if(noAtual->chaves[i]>chaveBusca)
			{
				std::string nomeArquivo = std::to_string(noAtual->chaves[i])+".txt";
				std::ifstream inputStream(nomeArquivo);
				if(!inputStream)
					std::cerr << "Arquivo não encontrado! \n";

				std::string line;

				int numberOperations = 0;
				std::ofstream output;
				output.open("out.txt",std::ofstream::app);

				while (getline(inputStream, line)) 
				{
					std::cout << line << "\n";
					numberOperations++;
				}

				output << "BUS>:" << numberOperations << std::endl;
				output.close();
			}
		}
	}
}

void ABM::BuscaMaiorNoArvBMenos(int chaveBusca)
{
	if(raiz==NULL)
	{
		std::cout<<"Árvore vazia! \n";
	}
	else
	{
		NoArvBmais* noAtual = raiz;
		while(!noAtual->seFolha)
		{
			for(int i=0;i<noAtual->tamanho;i++)
			{
				if(chaveBusca < noAtual->chaves[i])
				{
					noAtual = noAtual->ponteiro[i];
					break;
				}
				if(i==(noAtual->chaves[i]+1))
				{
					noAtual = noAtual->ponteiro[i];
					break;
				}
			}
		}
		for(int i=0;i<noAtual->tamanho;i++)
		{
			if(noAtual->chaves[i]<chaveBusca)
			{
				std::string nomeArquivo = std::to_string(noAtual->chaves[i])+".txt";
				std::ifstream inputStream(nomeArquivo);
				if(!inputStream)
					std::cerr << "Arquivo não encontrado! \n";

				std::string line;

				int numberOperations = 0;
				std::ofstream output;
				output.open("out.txt",std::ofstream::app);

				while (getline(inputStream, line)) 
				{
					std::cout << line << "\n";
					numberOperations++;
				}

				output << "BUS<:" << numberOperations << std::endl;
				output.close();
			}
		}
	}
}

void ABM::InclusaoNoArvBMais(int chave)
{
	if(raiz==NULL)
	{
		raiz = new NoArvBmais;
		raiz->chaves[0] = chave;
		raiz->seFolha = true;
		raiz->tamanho = 1;
	}
	else
	{
		NoArvBmais* noAtual = raiz;
		NoArvBmais* pai;

		while(noAtual->seFolha == false)
		{
			pai = noAtual;
			for(int i = 0; i < noAtual->tamanho; i++)
			{
				if(chave < noAtual->chaves[i])
				{
					noAtual = noAtual->ponteiro[i];
					break;
				}
				if(i == noAtual->tamanho - 1)
				{
					noAtual = noAtual->ponteiro[i+1];
					break;
				}
			}
		}

		if(noAtual->tamanho < MAX)
		{
			int i = 0;
			while(chave > noAtual->chaves[i] && i < noAtual->tamanho) i++;
			for(int j = noAtual->tamanho;j > i; j--)
			{
				noAtual->chaves[j] = noAtual->chaves[j-1];
			}

			noAtual->chaves[i] = chave;
			noAtual->tamanho++;
			noAtual->ponteiro[noAtual->tamanho] = noAtual->ponteiro[noAtual->tamanho-1];
			noAtual->ponteiro[noAtual->tamanho-1] = NULL;
		}
		else
		{
			NoArvBmais* novaFolha = new NoArvBmais;
			int virtualNode[MAX+1];

			for(int i = 0; i < MAX; i++)
			{
				virtualNode[i] = noAtual->chaves[i];
			}

			int i = 0, j;
			while(chave > virtualNode[i] && i < MAX) i++;

			for(int j = MAX+1;j > i; j--)
			{
				virtualNode[j] = virtualNode[j-1];
			}
			virtualNode[i] = chave; 
			novaFolha->seFolha = true;

			noAtual->tamanho = (MAX+1)/2;
			novaFolha->tamanho = MAX+1-(MAX+1)/2;
			noAtual->ponteiro[noAtual->tamanho] = novaFolha;
			novaFolha->ponteiro[novaFolha->tamanho] = noAtual->ponteiro[MAX];
			noAtual->ponteiro[MAX] = NULL;

			for(i = 0; i < noAtual->tamanho; i++)
			{
				noAtual->chaves[i] = virtualNode[i];
			}
			for(i = 0, j = noAtual->tamanho; i < novaFolha->tamanho; i++, j++)
			{
				novaFolha->chaves[i] = virtualNode[j];
			}

			if(noAtual == raiz)
			{
				NoArvBmais* novaRaiz = new NoArvBmais;
				novaRaiz->chaves[0] = novaFolha->chaves[0];
				novaRaiz->ponteiro[0] = noAtual;
				novaRaiz->ponteiro[1] = novaFolha;
				novaRaiz->seFolha = false;
				novaRaiz->tamanho = 1;
				raiz = novaRaiz;
			}
			else
			{
				incluiInterno(novaFolha->chaves[0],pai,novaFolha);
			}
		}
	}

	std::string line;

	int numberOperations = 0;
	std::string nomeArquivo = std::to_string(chave)+".txt";
	std::ifstream textStream(nomeArquivo);

	std::ofstream output;
	output.open("out.txt",std::ofstream::app);

	while (getline(textStream, line)) 
	{
		numberOperations++;
	}
	output << "INC:" << numberOperations << std::endl;
	output.close();
}
void ABM::incluiInterno(int chaveInclusaoInterna, NoArvBmais* noAtual, NoArvBmais* filho)
{
	if(noAtual->tamanho < MAX)
	{
		int i = 0;
		while(chaveInclusaoInterna > noAtual->chaves[i] && i < noAtual->tamanho) i++;
		for(int j = noAtual->tamanho;j > i; j--)
		{
			noAtual->chaves[j] = noAtual->chaves[j-1];
		}

		for(int j = noAtual->tamanho+1; j > i+1; j--)
		{
			noAtual->ponteiro[j] = noAtual->ponteiro[j-1];
		}

		noAtual->chaves[i] = chaveInclusaoInterna;
		noAtual->tamanho++;
		noAtual->ponteiro[i+1] = filho;
	}
	else
	{
		NoArvBmais* newInternal = new NoArvBmais;

		int virtualchaves[MAX+1];
		NoArvBmais* virtualponteiro[MAX+2];
		for(int i = 0; i < MAX; i++)
		{
			virtualchaves[i] = noAtual->chaves[i];
		}
		for(int i = 0; i < MAX+1; i++)
		{
			virtualponteiro[i] = noAtual->ponteiro[i];
		}

		int i = 0, j;
		while(chaveInclusaoInterna > virtualchaves[i] && i < MAX) i++;
		for(int j = MAX+1;j > i; j--)
		{
			virtualchaves[j] = virtualchaves[j-1];
		}
		virtualchaves[i] = chaveInclusaoInterna; 

		for(int j = MAX+2;j > i+1; j--)
		{
			virtualponteiro[j] = virtualponteiro[j-1];
		}

		virtualponteiro[i+1] = filho; 
		newInternal->seFolha = false;

		noAtual->tamanho = (MAX+1)/2;
		newInternal->tamanho = MAX-(MAX+1)/2;

		for(i = 0, j = noAtual->tamanho+1; i < newInternal->tamanho; i++, j++)
		{
			newInternal->chaves[i] = virtualchaves[j];
		}
		for(i = 0, j = noAtual->tamanho+1; i < newInternal->tamanho+1; i++, j++)
		{
			newInternal->ponteiro[i] = virtualponteiro[j];
		}

		if(noAtual == raiz)
		{
			NoArvBmais* novaRaiz = new NoArvBmais;
			novaRaiz->chaves[0] = noAtual->chaves[noAtual->tamanho];
			novaRaiz->ponteiro[0] = noAtual;
			novaRaiz->ponteiro[1] = newInternal;
			novaRaiz->seFolha = false;
			novaRaiz->tamanho = 1;
			raiz = novaRaiz;
			std::cout<<"Criada nova raiz \n";
		}
		else
		{
			//Recursão
			incluiInterno(noAtual->chaves[noAtual->tamanho] ,encontraPai(raiz,noAtual) ,newInternal);
		}
	}
}
NoArvBmais* ABM::encontraPai(NoArvBmais* noAtual, NoArvBmais* filho)
{
	NoArvBmais* pai;
	if(noAtual->seFolha || (noAtual->ponteiro[0])->seFolha)
	{
		return NULL;
	}
	for(int i = 0; i < noAtual->tamanho+1; i++)
	{
		if(noAtual->ponteiro[i] == filho)
		{
			pai = noAtual;
			return pai;
		}
		else
		{
			pai = encontraPai(noAtual->ponteiro[i],filho);
			if(pai!=NULL)return pai;
		}
	}
	return pai;
}

bool ABM::RemoveNoArvBMais(int chaveRemocao)
{
	if(raiz==NULL)
	{
		std::cout<<"Árvore vazia\n";
	}
	else
	{
		NoArvBmais* noAtual = raiz;
		NoArvBmais* pai;
		int irmaoEsq, irmaoDir;

		while(noAtual->seFolha == false)
		{
			for(int i = 0; i < noAtual->tamanho; i++)
			{
				pai = noAtual;
				irmaoEsq = i-1;
				irmaoDir =  i+1;
				if(chaveRemocao < noAtual->chaves[i])
				{	
					noAtual = noAtual->ponteiro[i];
					break;
				}
				if(i == noAtual->tamanho - 1)
				{
					irmaoEsq = i;
					irmaoDir = i+2;
					noAtual = noAtual->ponteiro[i+1];
					break;
				}
			}
		}

		bool achado = false;
		int pos;
		for(pos = 0; pos < noAtual->tamanho; pos++)
		{
			if(noAtual->chaves[pos] == chaveRemocao)
			{
				achado = true;
				break;
			}
		}
		if(!achado)
		{
			return false;
		}

		for(int i = pos; i < noAtual->tamanho; i++)
		{
			noAtual->chaves[i] = noAtual->chaves[i+1];
		}
		noAtual->tamanho--;

		if(noAtual == raiz)
		{
			for(int i = 0; i < 11; i++)
			{
				noAtual->ponteiro[i] = NULL;
			}
			if(noAtual->tamanho == 0)
			{
				std::cout<<"Árvore vazia! \n";
				delete[] noAtual->chaves;
				delete[] noAtual->ponteiro;
				delete noAtual;
				raiz = NULL;
			}
			return true;
		}

		noAtual->ponteiro[noAtual->tamanho] = noAtual->ponteiro[noAtual->tamanho+1];
		noAtual->ponteiro[noAtual->tamanho+1] = NULL;

		if(noAtual->tamanho >= 5)
		{
			return true;
		}

		if(irmaoEsq >= 0)
		{
			NoArvBmais *noEsq = pai->ponteiro[irmaoEsq];
			//check if it is possible to transfer
			if(noEsq->tamanho >= 6)
			{
				//make space for transfer
				for(int i = noAtual->tamanho; i > 0; i--)
				{
					noAtual->chaves[i] = noAtual->chaves[i-1];
				}
				//shift pointer to next leaf
				noAtual->tamanho++;
				noAtual->ponteiro[noAtual->tamanho] = noAtual->ponteiro[noAtual->tamanho-1];
				noAtual->ponteiro[noAtual->tamanho-1] = NULL;
				//transfer
				noAtual->chaves[0] = noEsq->chaves[noEsq->tamanho-1];
				//shift pointer of irmaoEsq
				noEsq->tamanho--;
				noEsq->ponteiro[noEsq->tamanho] = noAtual;
				noEsq->ponteiro[noEsq->tamanho+1] = NULL;
				//update pai
				pai->chaves[irmaoEsq] = noAtual->chaves[0];
				return true;
			}
		}
		if(irmaoDir <= pai->tamanho)
		{
			NoArvBmais *noDir = pai->ponteiro[irmaoDir];
			if(noDir->tamanho >= 6)
			{
				noAtual->tamanho++;
				noAtual->ponteiro[noAtual->tamanho] = noAtual->ponteiro[noAtual->tamanho-1];
				noAtual->ponteiro[noAtual->tamanho-1] = NULL;
				noAtual->chaves[noAtual->tamanho-1] = noDir->chaves[0];

				noDir->tamanho--;
				noDir->ponteiro[noDir->tamanho] = noDir->ponteiro[noDir->tamanho+1];
				noDir->ponteiro[noDir->tamanho+1] = NULL;

				for(int i = 0; i < noDir->tamanho; i++)
				{
					noDir->chaves[i] = noDir->chaves[i+1];
				}

				pai->chaves[irmaoDir-1] = noDir->chaves[0];
				return true;
			}
		}

		if(irmaoEsq >= 0)
		{
			NoArvBmais* noEsq = pai->ponteiro[irmaoEsq];
			for(int i = noEsq->tamanho, j = 0; j < noAtual->tamanho; i++, j++)
			{
				noEsq->chaves[i] = noAtual->chaves[j];
			}

			noEsq->ponteiro[noEsq->tamanho] = NULL;
			noEsq->tamanho += noAtual->tamanho;
			noEsq->ponteiro[noEsq->tamanho] = noAtual->ponteiro[noAtual->tamanho];

			removeInterno(pai->chaves[irmaoEsq],pai,noAtual);

			delete[] noAtual->chaves;
			delete[] noAtual->ponteiro;
			delete noAtual;
			return true;
		}
		else if(irmaoDir <= pai->tamanho)
		{
			NoArvBmais* noDir = pai->ponteiro[irmaoDir];
			for(int i = noAtual->tamanho, j = 0; j < noDir->tamanho; i++, j++)
			{
				noAtual->chaves[i] = noDir->chaves[j];
			}
			noAtual->ponteiro[noAtual->tamanho] = NULL;
			noAtual->tamanho += noDir->tamanho;
			noAtual->ponteiro[noAtual->tamanho] = noDir->ponteiro[noDir->tamanho];

			removeInterno(pai->chaves[irmaoDir-1],pai,noDir);
			delete[] noDir->chaves;
			delete[] noDir->ponteiro;
			delete noDir;
			return true;
		}
	}
	return false;
}

bool ABM::removeInterno(int chaveRemocaoInterna, NoArvBmais* noAtual, NoArvBmais* filho)
{
	if(noAtual == raiz)
	{
		if(noAtual->tamanho == 1)
		{
			if(noAtual->ponteiro[1] == filho)
			{
				delete[] filho->chaves;
				delete[] filho->ponteiro;
				delete filho;
				raiz = noAtual->ponteiro[0];
				delete[] noAtual->chaves;
				delete[] noAtual->ponteiro;
				delete noAtual;
				std::cout<<"Mudou raíz \n";
				return true;
			}
			else if(noAtual->ponteiro[0] == filho)
			{
				delete[] filho->chaves;
				delete[] filho->ponteiro;
				delete filho;
				raiz = noAtual->ponteiro[1];
				delete[] noAtual->chaves;
				delete[] noAtual->ponteiro;
				delete noAtual;
				std::cout<<"Mudou raíz \n";
				return true;
			}
		}
	}
	int pos;
	for(pos = 0; pos < noAtual->tamanho; pos++)
	{
		if(noAtual->chaves[pos] == chaveRemocaoInterna)
		{
			break;
		}
	}
	for(int i = pos; i < noAtual->tamanho; i++)
	{
		noAtual->chaves[i] = noAtual->chaves[i+1];
	}

	for(pos = 0; pos < noAtual->tamanho+1; pos++)
	{
		if(noAtual->ponteiro[pos] == filho)
		{
			break;
		}
	}
	for(int i = pos; i < noAtual->tamanho+1; i++)
	{
		noAtual->ponteiro[i] = noAtual->ponteiro[i+1];
	}
	noAtual->tamanho--;
	if(noAtual->tamanho >= 4)
	{
		return true;;
	}
	if(noAtual==raiz)return true;
	NoArvBmais* pai = encontraPai(raiz, noAtual);
	int irmaoEsq, irmaoDir;

	for(pos = 0; pos < pai->tamanho+1; pos++)
	{
		if(pai->ponteiro[pos] == noAtual)
		{
			irmaoEsq = pos - 1;
			irmaoDir = pos + 1;
			break;
		}
	}

	if(irmaoEsq >= 0)
	{
		NoArvBmais *noEsq = pai->ponteiro[irmaoEsq];
		if(noEsq->tamanho >= 5)
		{
			for(int i = noAtual->tamanho; i > 0; i--)
			{
				noAtual->chaves[i] = noAtual->chaves[i-1];
			}

			noAtual->chaves[0] = pai->chaves[irmaoEsq];
			pai->chaves[irmaoEsq] = noEsq->chaves[noEsq->tamanho-1];

			for (int i = noAtual->tamanho+1; i > 0; i--)
			{
				noAtual->ponteiro[i] = noAtual->ponteiro[i-1];
			}

			noAtual->ponteiro[0] = noEsq->ponteiro[noEsq->tamanho];
			noAtual->tamanho++;
			noEsq->tamanho--;

			return true;
		}
	}
	if(irmaoDir <= pai->tamanho)
	{
		NoArvBmais *noDir = pai->ponteiro[irmaoDir];

		if(noDir->tamanho >= 5)
		{
			noAtual->chaves[noAtual->tamanho] = pai->chaves[pos];
			pai->chaves[pos] = noDir->chaves[0];

			for (int i = 0; i < noDir->tamanho -1; i++)
			{
				noDir->chaves[i] = noDir->chaves[i+1];
			}
			noAtual->ponteiro[noAtual->tamanho+1] = noDir->ponteiro[0];
			for (int i = 0; i < noDir->tamanho; ++i)
			{
				noDir->ponteiro[i] = noDir->ponteiro[i+1];
			}
			noAtual->tamanho++;
			noDir->tamanho--;

			return true;
		}
	}

	if(irmaoEsq >= 0)
	{
		NoArvBmais *noEsq = pai->ponteiro[irmaoEsq];
		noEsq->chaves[noEsq->tamanho] = pai->chaves[irmaoEsq];
		for(int i = noEsq->tamanho+1, j = 0; j < noAtual->tamanho; j++)
		{
			noEsq->chaves[i] = noAtual->chaves[j];
		}
		for(int i = noEsq->tamanho+1, j = 0; j < noAtual->tamanho+1; j++)
		{
			noEsq->ponteiro[i] = noAtual->ponteiro[j];
			noAtual->ponteiro[j] = NULL;
		}
		noEsq->tamanho += noAtual->tamanho+1;
		noAtual->tamanho = 0;

		removeInterno(pai->chaves[irmaoEsq], pai, noAtual);

		return true;
	}
	else if(irmaoDir <= pai->tamanho)
	{
		NoArvBmais *noDir = pai->ponteiro[irmaoDir];
		noAtual->chaves[noAtual->tamanho] = pai->chaves[irmaoDir-1];
		for(int i = noAtual->tamanho+1, j = 0; j < noDir->tamanho; j++)
		{
			noAtual->chaves[i] = noDir->chaves[j];
		}
		for(int i = noAtual->tamanho+1, j = 0; j < noDir->tamanho+1; j++)
		{
			noAtual->ponteiro[i] = noDir->ponteiro[j];
			noDir->ponteiro[j] = NULL;
		}
		noAtual->tamanho += noDir->tamanho+1;
		noDir->tamanho = 0;
		removeInterno(pai->chaves[irmaoDir-1], pai, noDir);

		return true;
	}
	return false;
}