#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro () //Fun��o respons�vel por cadasstrar os usu�rios no sistema
{ 
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
    
    //In�cio cria��o de vari�veis/string ou conjunto de string
    char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo[40];
    // Final da cria��o de vari�veis
    
    printf ("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
    scanf ("%s", cpf); // %s refere-se a string (Quando precisa salvar uma string) dentro da vari�vel cpf
    
    strcpy (arquivo,cpf); //Respons�vel por copiar os valores das string
    
    FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); //Criar o arquivo e o "w" = escrever ou writt
	fprintf (file,cpf); //Salvo o valor da vari�vel
	fclose (file); //Fecha o arquivo  
	
	file = fopen(arquivo, "a"); //Criar o arquivo e o "a" = atualizar a arquivo com a nova informa��o.
	fprintf (file, "-"); 
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informa��es adcionais do usu�rio
	scanf ("%s", nome); //Leitura/Salvamento da informa��o fornecida pelo usu�rio dentro da vari�vel (Nome)
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova informa��o. 
	fprintf (file, nome); // Salvo o valor da vari�vel
	fclose (file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar a arquivo com a nova informa��o.
	fprintf (file, "-");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o sobrenome a ser cadstrado: "); //Coletando informa��es adcionais do usu�rio.
	scanf ("%s", sobrenome); //leitura/Salvamento da informa��o fornecida pelo usu�rio dentro da vari�vel (sobrenome)
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova informa��o.
	fprintf (file, sobrenome); //Salvo o valor da vari�vel
	fclose (file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova infroma��o.
	fprintf (file, "-");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o cargo a ser cadastrado: "); //Coletando informa��es adcionais do usu�rio.
	scanf ("%s", cargo); //leitura/Salvamento da informa��o fornecida pelo usu�rio dentro da vari�vel (cargo)
	
	file = fopen (arquivo, "a"); //Criar o arquivo e o "a" = atualizar o arquivo com a nova informa��o.
	fprintf (file, cargo); //Salvo o valor da vari�vel
	fclose (file); //Fecha o arquivo
	
	system ("pause"); //Congela a tela para o usu�rio ver a resposta de seu comando para o programa.
	
	}


int consulta ()
{   
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    // Inicio da cria��o de vari�veis/string ou conjunto de string   
	char cpf[40];
	char conteudo [200];
	//Fim da cria��o de vari�veis/ string ou conjunto de string
	printf ("Digite o CPF a ser consultado: "); //Coletando informa��es de consulta do usu�rio
	scanf ("%s", cpf); //Leitura/Salvamento da informa��o fornecida pelo usu�rio
	
	FILE *file; //Criar o arquivo
	file = fopen (cpf, "r"); // Consultar o arquivo atrav�s do comando "r" = (read ou ler)
	
	if(file == NULL)
	{
		printf ("N�o foi poss�vel acessar o arquivo, n�o localizado! \n");
		
	}
	
	while(fgets(conteudo,200, file) !=	NULL)
	{
		printf ("\nEssas s�o as informa��es do usu�rio: ");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
		
		system ("pause");
}

int deletar ()
{
	char cpf[40];
	
	printf ("Digite o CPF do usu�rio a ser deletado: ");
	scanf ("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("Deletado com sucesso, o usu�rio n�o se encontra no sistema!. \n");
		system ("pause");
	}
	
}

int main ()
    {
	int opcao=0; //Definindo variav�is
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
       system ("cls"); //Respons�vel por limpar a tela
		
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf ("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	   printf ("Escolha a op��o desejada do menu:\n\n");
	   printf ("\t1 - Registrar nomes\n");
	   printf ("\t2 - Consultar nomes\n");
	   printf ("\t3 - Deletar nomes\n\n");
	   printf ("Op��o:"); //Fim do menu
	
	   scanf ("%d", &opcao); //armazendo a escolha do usu�rio
	
	   system ("cls"); // Respons�vel por limpar a tela
	   
	   switch (opcao) //In�cio da sele��o do menu
	   {
	   	case 1: 
	   	registro(); // chamada de fun��es
	   	break;
	   		
	    case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
			
		default:
		printf ("Essa op��o n�o est� dispon�vel!\n");
		system ("pause");
		break;
	   	}//fim da sele��o de menu
	
       }
}
