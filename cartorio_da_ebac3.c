#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro () //Função responsável por cadasstrar os usuários no sistema
{ 
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
    
    //Início criação de variáveis/string ou conjunto de string
    char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo[40];
    // Final da criação de variáveis
    
    printf ("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
    scanf ("%s", cpf); // %s refere-se a string (Quando precisa salvar uma string) dentro da variável cpf
    
    strcpy (arquivo,cpf); //Responsável por copiar os valores das string
    
    FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); //Criar o arquivo e o "w" = escrever ou writt
	fprintf (file,cpf); //Salvo o valor da variável
	fclose (file); //Fecha o arquivo  
	
	file = fopen(arquivo, "a"); //Criar o arquivo e o "a" = atualizar a arquivo com a nova informação.
	fprintf (file, "-"); 
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informações adcionais do usuário
	scanf ("%s", nome); //Leitura/Salvamento da informação fornecida pelo usuário dentro da variável (Nome)
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova informação. 
	fprintf (file, nome); // Salvo o valor da variável
	fclose (file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar a arquivo com a nova informação.
	fprintf (file, "-");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o sobrenome a ser cadstrado: "); //Coletando informações adcionais do usuário.
	scanf ("%s", sobrenome); //leitura/Salvamento da informação fornecida pelo usuário dentro da variável (sobrenome)
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova informação.
	fprintf (file, sobrenome); //Salvo o valor da variável
	fclose (file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova infromação.
	fprintf (file, "-");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o cargo a ser cadastrado: "); //Coletando informações adcionais do usuário.
	scanf ("%s", cargo); //leitura/Salvamento da informação fornecida pelo usuário dentro da variável (cargo)
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova informação.
	fprintf (file, cargo); //Salvo o valor da variável
	fclose (file); //Fecha o arquivo
	
	system ("pause"); //Congela a tela para o usuário ver a resposta de seu comando para o programa.
	
	}


int consulta ()
{   
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    // Inicio da criação de variáveis/string ou conjunto de string   
	char cpf[40];
	char conteudo [200];
	//Fim da criação de variáveis/ string ou conjunto de string
	printf ("Digite o CPF a ser consultado: "); //Coletando informações de consulta do usuário
	scanf ("%s", cpf); //Leitura/Salvamento da informação fornecida pelo usuário
	
	FILE *file; //Criar o arquivo
	file = fopen (cpf, "r"); // Consultar o arquivo através do comando "r" = (read ou ler)
	
	if(file == NULL)
	{
		printf ("Não foi possível acessar o arquivo, não localizado! \n");
		
	}
	
	while(fgets(conteudo,200, file) !=	NULL)
	{
		printf ("\nEssas são as informações do usuário: ");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
		
		system ("pause");
}

int deletar ()
{
	char cpf[40];
	
	printf ("Digite o CPF do usuário a ser deletado: ");
	scanf ("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("Deletado com sucesso, o usuário não se encontra no sistema!. \n");
		system ("pause");
	}
	
}

int main ()
    {
	int opcao=0; //Definindo variavéis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
       system ("cls"); //Responsável por limpar a tela
		
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf ("### Cartório da EBAC ###\n\n"); //Início do menu
	   printf ("Escolha a opção desejada do menu:\n\n");
	   printf ("\t1 - Registrar nomes\n");
	   printf ("\t2 - Consultar nomes\n");
	   printf ("\t3 - Deletar nomes\n\n");
	   printf ("Opção:"); //Fim do menu
	
	   scanf ("%d", &opcao); //armazendo a escolha do usuário
	
	   system ("cls"); // Responsável por limpar a tela
	   
	   switch (opcao) //Início da seleção do menu
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
		printf ("Essa opção não está disponível!\n");
		system ("pause");
		break;
	   	}//fim da seleção de menu
	
       }
}
