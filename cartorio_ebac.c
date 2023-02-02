#include <stdio.h> //biblioteca que printa na tela as informa��es pro usu�rio
#include <stdlib.h> //biblioteca que reserva um espa�o na mem�ria 
#include <locale.h> //biblioteca que permite caracteres conforme a regi�o escolhida
#include <string.h> //biblioteca das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu CPF: ");
	scanf("%s", cpf);

	strcpy(arquivo, cpf); //esse comando copia os valores das strings
	
	FILE *file; //cria um arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria um arquivo novo e abre o arquivo e o 'w' � de writer
	fprintf(file, cpf);//salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a' � de atualizar
	fprintf(file,", ");
	fclose(file); //o close � de fechar
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);//o "%s" � dizendo que a vari�vel 'nome' � uma string
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file,sobrenome);	
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o seu cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que voc� quer consultar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("CPF n�o localizado.\n");
		
	}
	
	while(fgets(conteudo,200, file)!= NULL )
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int del()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s",cpf);
	
	system("cls");
	
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf, "r");
	
		
	if(file == NULL)
	{	
		printf("Usu�rio n�o se econtra no sistema.\n");
		system("pause");	
	}
	
}

int main()
{
	int option=0;
	int loop=1;
	
	for(loop=1;loop=1;)
	{
	
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Escolha a op��o desejada no menu: \n\n");
	printf("\t1) - Registrar nomes\n");
	printf("\t2) - Consultar nomes\n ");
	printf("\t3) - Deletar nomes\n\n");
	printf("Op��o: ");
	
	scanf("%d",&option);
	
	system("cls"); //apaga as informa��es da tela
	
		switch(option)
		{
				
		case 1:
		registro();
		break;
			
		case 2:
		consulta();
		break;
			
		case 3:
		del();
		break;
			
		default:
		printf("Op��o inexistente.\n\n");
		system("pause");
		break;
			
		}
			
					
	}
	
	
}

