//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex1
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
    1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
        Receba dados via teclado e imprima estes conteudos no video no seguinte
        formato.
                 char, int, long, float, double
                 unsigned char, unsigned int, unsigned long,

                 10        20        30        40        50        60        70
        1234567890123456789012345678901234567890123456789012345678901234567890
            char      int       long                float               double
                  unsigned char       unsigned int        unsigned long

*/

struct tipos // novo tipo de variável
{
    char a;
    int b;
    long int c;
    float d;
    double e;
    unsigned char f;
    unsigned int g;
    unsigned long int h;
};

struct tipos num; // variável do tipo "struct tipos" de nome "num"

void main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("Insira um caractere: ");
    scanf("%c", &num.a);
    printf("\nInsira um número inteiro: ");
    scanf("%d", &num.b);
    printf("\nInsira um número inteiro: ");
    scanf("%ld", &num.c);
    printf("\nInsira um número qualquer: ");
    scanf("%f", &num.d);
    printf("\nInsira um número qualquer: ");
    scanf("%lf", &num.e);
    getchar();
    printf("\nInsira um caractere: ");
    scanf("%c", &num.f);
    printf("\nInsira um número inteiro maior ou igual a zero: ");
    scanf("%u", &num.g);
    printf("\nInsira um número inteiro maior ou igual a zero: ");
    scanf("%lu", &num.h);

    printf("\n\n");
    printf("\t         10        20        30        40        50        60        70\n");
    printf("\t1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("\t    %c         %-6d    %-11ld         %-8.1e            %-9.1e\n", num.a, num.b, num.c, num.d, num.e);
    printf("\t          %c                   %-5u               %-10lu\n\n", num.f, num.g, num.h);
}

#endif // ex1

#ifdef ex2
/*
    2 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
        de 4 elementos. Receba os dados pelo teclado e imprima-os no video. Faça
        um menu. (vetor de estruturas)
		nome, end, cidade, estado, cep
*/

struct cadastro //criando a struct
{
   char nome[20];
   char end[30];
   char cidade[20];
   char estado[20];
   char cep[9];
};

struct cadastro cliente[4];//criando o vetor da struct

void main()
{
   int op, i = 0, j;

   setlocale(LC_ALL, "Portuguese"); //estabelecendo o idioma

   for(;;) //loop infinito para o menu
   {
      system("color 1F"); //tornado o fundo azul e as letras brancas

      printf("\n\t\t     ##### MENU #####\n\n\n");
      printf("\t\t1-Cadastrar cliente.\n\n");
      printf("\t\t2-Lista de clientes.\n\n");
      printf("\t\t3-Fechar programa.\n\n");

      printf("\n\t\tInforme a função desejada: ");
      scanf("%d", &op);

      switch(op)
      {
         case 1:
            system("cls");
            system("color 1F"); //tornado o fundo azul e as letras brancas
            if (i <= 3)
            {
                printf("\n\t\t     ##### CADASTRO DO CLIENTE #####\n\n\n");
                getchar();
                printf("\t\tInforme o nome do cliente: ");
                gets(cliente[i].nome);
                printf("\n\t\tInforme o endereço do cliente: ");
                gets(cliente[i].end);
                printf("\n\t\tInforme a cidade: ");
                gets(cliente[i].cidade);
                printf("\n\t\tInforme estado: ");
                gets(cliente[i].estado);
                printf("\n\t\tInforme o CEP: ");
                gets(cliente[i].cep);
                printf("\n\t\t");
                i++;
            }
            else
            {
               system("cls");
               system("color 4F"); //tornando a tela vermelha e as letras brancas
               printf("\n\t\t     ##### ATENÇÃO #####\n\n\n");
               printf("\n\t\tLista lotada!\n\n\n\t\t");
            }

            system("pause");
            system("cls");
            break;

         case 2:
            system("cls");
            printf("\n\t\t     ##### DADOS DOS CLIENTES #####\n\n\n");

            if (i == 0)
            {
                system("cls");
                system("color 4F"); //tornando a tela vermelha e as letras brancas
                printf("\n\t\t     ##### ATENÇÃO #####\n\n\n");
                printf("\n\t\tLista vazia!\n\n\n\t\t");
            }
            else
            {
                for (j = 0; j < i; j++)
                {
                    printf("\n\t\tNOME: %s", cliente[j].nome);
                    printf("\n\t\tENDEREÇO: %s", cliente[j].end);
                    printf("\n\t\tCIDADE: %s", cliente[j].cidade);
                    printf("\n\t\tESTADO: %s", cliente[j].estado);
                    printf("\n\t\tCEP: %s\n", cliente[j].cep);
                }
            }
            printf("\n\t\t");
            system("pause");
            system("cls");
            break;

         case 3:
            system("cls");
            system("color 70");
            printf("\n\n\n\n\n\t\t\t*** PROGRAMA FINALIZADO ***\n\n\n");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            exit(0);
            break;

         default:
            system("cls");
            system("color 4F"); //tornando a tela vermelha e as letras brancas
            printf("\n\t\t     ***** ATENÇÃO *****\n\n\n");
            printf("\n\t\tA opção informada não existe!\n\n\n\t\t");
            system("pause");
            system("cls");
            break;
      }
   }
}
#endif // ex2

#ifdef ex3

/*
    3 - Crie uma estrutura para representar as coordenadas de um ponto no plano
        (posicoes X e Y).Em seguida, declare e leia do teclado um ponto e exiba a
        distancia dele ate' a origem das coordenadas, isto é, posição (0, 0). Para
        realizar o cálculo, utilize a fórmula a seguir :
            d = raiz quadrada de ( (XB - XA)² + (YB - YA)² )
        Em que :
            d = distância entre os pontos A e B
            X = coordenada X em um ponto
            Y = coordenada Y em um ponto
*/

struct coord //criando struct para as coordenadas
{
    float posx;
    float posy;
    float orix;
    float oriy;
};

struct coord ponto = { 0,0,0,0 }; //criando variável da struct;

void main()
{
    float d; //variável para cálculo da distância
    char resp; //resposta do user

    setlocale(LC_ALL, "Portuguese"); //estabelecendo idioma

    for (;;) //loop infinito
    {
        system("color 1F"); //fundo azul e letras brancas
        printf("\n\t\t     ###### DISTÂNCIA ENTRE DOIS PONTOS ######\n\n\n");

        printf("\t\tInforme a abscissa (X): ");
        scanf("%f", &ponto.posx);
        printf("\n");

        printf("\t\tInforme a ordenada (Y): ");
        scanf("%f", &ponto.posy);
        printf("\n");

        d = sqrt((ponto.posx - ponto.orix)*(ponto.posx - ponto.orix) + (ponto.posy - ponto.oriy)*(ponto.posy - ponto.oriy));

        printf("\n\t\tDistância entre (%.1f , %.1f) e (%.2f , %.2f) é igual a: %.2f\n\n\n\t\t", ponto.orix, ponto.oriy, ponto.posx, ponto.posy, d);

        system("pause");
        system("cls");
        system("color E4"); //fundo amarelo e letras vermelhas

        printf("\n\n\t\tDeseja informar um novo ponto? (S/N):  ");
        getchar(); //limpa o buffer
        resp = getchar();

        if (resp == 'n' || resp == 'N')
        {
            system("color 2F"); //fundo verde e letras brancas
            system("cls");
            printf("\n\n\n\n\n\t\t\t*** PROGRAMA FINALIZADO ***\n\n\n");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            break; //sai do loop
        }
        else
        {
            system("cls"); //limpa tela para retorno ao início
        }
    }
}
#endif // ex3
