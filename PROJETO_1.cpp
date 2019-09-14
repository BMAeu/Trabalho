// Nome: Bruno Morgan Almeida	DRE: 117043484

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h>
#include<stdlib.h> 
#include<stdio.h> 
#include <vector>



struct Aluno
{
	std::string nome;
	long int telefone;
	long int dre;
	std::string email;
};


void merge(Aluno arr[], int l, int m, int r, int ordenador)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	std::vector<Aluno> L, R;
	
	for (i = 0; i < n1; i++) 
	{
		L.push_back(arr[l + i]);
	}
	for (j = 0; j < n2; j++) 
	{
		R.push_back(arr[m + 1 + j]);
	}

	i = 0; 
	j = 0; 
	k = l;  
	if (ordenador == 1) {
		while (i < n1 && j < n2)
		{
			if (L[i].nome <= R[j].nome)
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	if (ordenador == 2) {
		while (i < n1 && j < n2)
		{
			if (L[i].telefone <= R[j].telefone)
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	if (ordenador == 3) {
		while (i < n1 && j < n2)
		{
			if (L[i].dre <= R[j].dre)
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	if (ordenador == 4) {
		while (i < n1 && j < n2)
		{
			if (L[i].email <= R[j].email)
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}

}

// Funcao que aplica o Merge Sort
void mergeSort(Aluno arr[], int l, int r, int ordenador)
{
	if (l < r)
	{
		
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m, ordenador);
		mergeSort(arr, m + 1, r, ordenador);

		merge(arr, l, m, r, ordenador);
	}
}

// Funcao que aplica o Bubble Sort.
void Bubble(Aluno arr[], int n, int ordenador)
{
	int i, j;
	if (ordenador == 1) {
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (arr[j].nome > arr[j + 1].nome)
				{
					Aluno f;
					f = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = f;


				}
			}
		}
	}
	if (ordenador == 2) {
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (arr[j].telefone > arr[j + 1].telefone)
				{
					Aluno f;
					f = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = f;
				}
			}
		}
	}
	if (ordenador == 3) {
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (arr[j].dre > arr[j + 1].dre)
				{
					Aluno f;
					f = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = f;
				}
			}
		}
	}
	if (ordenador == 4) {
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (arr[j].email > arr[j + 1].email)
				{
					Aluno f;
					f = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = f;
				}
			}
		}
	}

}

// Procura elemento em lista.
int procurar(int alvo, int lista[], int tam_lista)
{
	int k = 2;
	int i = 0;
	while (k != 0 && k != 1) {
		if (lista[i] == alvo) {
			k = 1;
		}
		if (i == tam_lista - 1 && lista[i] != alvo) {
			k = 0;
		}
		i++;
	}
	return k;
}

//Escreve a tabela com os atributos determinados pelo usuário.
void tabela(int arr[], Aluno lista[], int tam_lista, int tam_arr)
{
	std::ofstream tabela;
	tabela.open("tabela.csv");
	// Escreve os campos que o usuario escolheu
	for (int j = 0; j < 5; j++)
	{
		if (arr[j] == 1) {
			tabela << "Nome" << ", ";
		}
		if (arr[j] == 2) {
			tabela << "Telefone" << ", ";
		}
		if (arr[j] == 3) {
			tabela << "DRE" << ", ";
		}
		if (arr[j] == 4) {
			tabela << "E-mail" << ", ";
		}
		if (arr[j] == 0) {
			j = 5;
		}
	}
	tabela << std::endl;
	//Preenche os campos que o usuario escolheu
	for (int i = 0; i < tam_lista; i++)
	{
		if (procurar(1, arr, tam_arr) == 1)
		{
			tabela << lista[i].nome << ", ";
		}
		if (procurar(2, arr, tam_arr) == 1)
		{
			tabela << lista[i].telefone << ", ";
		}
		if (procurar(3, arr, tam_arr) == 1)
		{
			tabela << lista[i].dre << ", ";
		}
		if (procurar(4, arr, tam_arr) == 1)
		{
			tabela << lista[i].email << ", ";
		}
		tabela << std::endl;

	}
	tabela.close();
}

int main()
{
	Aluno alunos[45];
	int ar[4] = { 0,0,0,0 };
	int value, i = 0;
	int ordenador;
	int tamanho = (sizeof(alunos) / sizeof(alunos[0]));
	clock_t t_bubble, t_merge;
	{
		//Preenchendo a lista de alunos
		alunos[0]  = { "Bruno"    , 993705411, 117043484, "bruno.morgan123@gmail.com" };
		alunos[1]  = { "Joao"     , 957495336, 115263457, "joao@gmail.com" };
		alunos[2]  = { "Isabella" , 929029942, 119045680, "isa1793@gmail.com" };
		alunos[3]  = { "Guilherme", 996416670, 110351225, "guilherme390@gmail.com" };
		alunos[4]  = { "Lucas"    , 936667481, 116245835, "lucas.tt@gmail.com" };
		alunos[5]  = { "Carolina" , 994843422, 114335495, "carolui@gmail.com" };
		alunos[6]  = { "Hera"     , 993556543, 113556546, "olimolim@gmail.com" };
		alunos[7]  = { "Luisa"    , 981328057, 113565565, "lulwen@gmail.com" };
		alunos[8]  = { "Luan"     , 950055115, 111852565, "luanter@gmail.com" };
		alunos[9]  = { "Gabriela" , 996266253, 113265593, "Gbadc@gmail.com" };
		alunos[10] = { "Haroldo"  , 992626232, 161651161, "fwer213gmail.com"};
		alunos[11] = { "Juca"     , 952315632, 112162621, "dcqwefw@gmail.com"};
		alunos[12] = { "Ignolda"  , 956451653, 115626262, "wdqdqw@hotmail.com"};
		alunos[13] = { "Rasputin" , 956312332, 115236562, "haif@globo.com"};
		alunos[14] = { "Larissa"  , 952325162, 102258559, "eeefd33@gmail.com"};
		alunos[15] = { "Manuela"  , 952565132, 100556655, "haig@hotmail.com"};
		alunos[16] = { "Eduarda"  , 956513653, 151515512, "wewe@gmail.com"};
		alunos[17] = { "Joel"     , 956251516, 144785233, "wesdtgy@gmail.com"};
		alunos[18] = { "Milton"   , 996623251, 123569877, "poljki@gmail.com"};
		alunos[19] = { "Anna"     , 956262652, 155266565, "haif@globomail.com"};
		alunos[20] = { "Maria"    , 999995213, 121262600, "haif@gmail.com"};
		alunos[21] = { "Olga"     , 952665624, 126516512, "adwrfsd@gmail.com"};
		alunos[22] = { "Nora"     , 926232323, 122222222, "wefwe@gmail.com"};
		alunos[23] = { "Pedro"    , 926036325, 111111111, "fwce@gmail.com"};
		alunos[24] = { "Sandra"   , 959626266, 133333333, "tnhbgrtv@gmail.com"};
		alunos[25] = { "Adao"     , 995526213, 151555555, "ynjhbg@gmail.com"};
		alunos[26] = { "Alan"     , 956325133, 144444444, "tgrhg@gmail.com"};
		alunos[27] = { "Aaaron"   , 952697421, 155555555, "rtgef@gmail.com"};
		alunos[28] = { "Gin"      , 987563125, 166666666, "EGRwe@gmail.com"};
		alunos[29] = { "Paulo"    , 987456321, 177777777, "wfe@globo.com"};
		alunos[30] = { "Paula"    , 912345678, 188888888, "rtbv@gmail.com"}; 
		alunos[31] = { "Marcelo"  , 956225533, 199999999, "piouyhb@gmail.com"};
		alunos[32] = { "Ze"       , 985322235, 100000000, "treresfdv@gmail.com"};
		alunos[33] = { "Jorge"    , 941853322, 151555595, "oiknkj98802@gmail.com"};
		alunos[34] = { "Marcos"   , 841560332, 123668456, "o9i87u6y545@gmail.com"};
		alunos[35] = { "Andre"    , 845332023, 112862325, "87uy6hutrge@gmail.com"};
		alunos[36] = { "Hamilton" , 874815633, 121632225, "y4rute@gmail.com"};
		alunos[37] = { "Jose"     , 898465163, 132552562, "8786564534rf@gmail.com"};
		alunos[38] = { "Harry"    , 948956151, 126266565, "243rf4wear@gmail.com"};
		alunos[39] = { "Mark"     , 954156123, 156259562, "67u5tyfwf@gmail.com"};
		alunos[40] = { "Judas"    , 957576222, 159595626, "434tw3atra3@gmail.com"};
		alunos[41] = { "Jo"       , 962418558, 123647885, "13r23rf2@gmail.com"};
		alunos[42] = { "Fernanda" , 945454815, 134659875, "78rf3tf@gmail.com"};
		alunos[43] = { "Fernando" , 911111112, 126549752, "byo3qu@gmail.com"};
		alunos[44] = { "No"       , 922222222, 149979897, "12er97@gmail.com"};

	}
	std::cout << "Quais informacoes voce quer ver da tabela?" << std::endl;
	std::cout << "1 - Nome \n2 - Telefone \n3 - DRE \n4 - E-mail";
	std::cout << "\nDigite os numeros correspondentes as areas que voce quer ver, aperte ENTER entre cada numero e 0 quando terminar.\n";
	while (std::cin >> value && value != 0)
	{
		ar[i] = value;
		i++;
	}
	std::cout << "\nDigite o numero pelo qual voce quer ordenar a tabela.\n";
	std::cin >> ordenador;
	t_bubble = clock();
	Bubble(alunos, tamanho, ordenador);
	t_bubble = clock() - t_bubble;
	t_merge = clock();
	mergeSort(alunos, 0, tamanho - 1, ordenador);
	t_merge = clock() - t_merge;
	tabela(ar, alunos, tamanho, 4);
	std::cout << "O tempo de ordenacao do Bubble Sort e de: " << ((float)t_bubble)/CLOCKS_PER_SEC << " segundos.\n";
	std::cout << "O tempo de ordenacao do Merge Sort e de: " << ((float)t_merge)/CLOCKS_PER_SEC << " segundos.";
	return 0;
}