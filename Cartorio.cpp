#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>// biblioteca responsavél por cuidar das string

int registro() // função responsavel por cadastrar os usuários no sistema
{
	// inicio criação de variaveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// inicio criação de variaveis / string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informação do usuário 
	scanf("%s", cpf); //%refere-se a string
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores dos string
	
	FILE *file;// cria o arquivo
	file= fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvar valor do variavel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	

	printf("digite o sobrenome a ser cadastrado:");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	}

int consulta()
{
	setlocale(LC_ALL,"portuguese"); // Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: " );
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usúario não se encontra no sistema!.\n");
		system("pause");
	}
	

}



int main()
{


	int opcao=0; // definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	system("cls");
		
	setlocale(LC_ALL,"portuguese"); // Definindo a linguagem
	printf("### Cartório da EBAC ###\n\n"); // inicio do menu
	printf("Escolha a opeção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");//fim do menu
	printf("Opção:");
	
	scanf("%d", &opcao); //armazenando a escolha do usuário
	
	system("cls"); //responsavel por limpar a tela 
	
	switch(opcao) // inicio da seleção do menu
	{
		case 1:
		registro(); // chamada de funções 
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();	
		break;
		
			
		default:
		printf("Essa opçâo não está disponivel\n");
		system("pause");
		break;
			
		}
	
		
			}
}
