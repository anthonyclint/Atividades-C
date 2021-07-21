//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex2
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
	1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
        A estrutura é uma variavel local na função main().Receba via teclado o
        conteudo de cada um dos membros numa função e imprima-os no video no
        seguinte fomato(também numa função).

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

recebe(struct tipos *pnum)
{
    printf("Insira um caractere: ");
    scanf("%c", &(*pnum).a);
    printf("\nInsira um número inteiro: ");
    scanf("%d", &(*pnum).b);
    printf("\nInsira um número inteiro: ");
    scanf("%ld", &(*pnum).c);
    printf("\nInsira um número qualquer: ");
    scanf("%f", &(*pnum).d);
    printf("\nInsira um número qualquer: ");
    scanf("%lf", &(*pnum).e);
    getchar();
    printf("\nInsira um caractere: ");
    scanf("%c", &(*pnum).f);
    printf("\nInsira um número inteiro maior ou igual a zero: ");
    scanf("%u", &(*pnum).g);
    printf("\nInsira um número inteiro maior ou igual a zero: ");
    scanf("%lu", &(*pnum).h);
}

imprime(struct tipos* pnum)
{
    printf("\n\n");
    printf("\t         10        20        30        40        50        60        70\n");
    printf("\t1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("\t    %c         %-6d    %-11ld         %-8.1e            %-9.1e\n", (*pnum).a, (*pnum).b, (*pnum).c, (*pnum).d, (*pnum).e);
    printf("\t          %c                   %-5u               %-10lu\n\n\n", (*pnum).f, (*pnum).g, (*pnum).h);
}

void main()
{
    struct tipos num; // variável do tipo "struct tipos" de nome "num"

    struct tipos *pnum;

    pnum = &num;

    char resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {
        recebe(pnum);

        imprime(pnum);

        system("pause");
        system("cls");

        printf("\nDeseja inserir novos valores? S/N\t");
        getchar();
        resp = getchar();

        if (resp == 's' || resp == 'S')
        {
            system("cls");
        }
        else
        {
            printf("\n\n\n");
            break;
        }

    }
}
#endif // ex1

#ifdef ex2

/*
    2 - Escreva um programa que receba n valores via teclado, receba também a
        operação a ser executada. Quando for digitado "=" o programa deve mostrar
        o resultado acumulado dos n valores. As operações aritmeticas e a entrada
        de dados devem ser funções que recebem os valores usando ponteiros.
*/

void recebe(int* pnum)
{
    printf("\n Informe um número: ");
    scanf("%d", pnum);
}

float soma(int* pnum, float* paux)
{
    *paux += *pnum;

    return(*paux);
}

float subtra(int* pnum, float* paux)
{
    *paux -= *pnum;

    return(*paux);
}

float multi(int* pnum, float* paux)
{
    *paux *= *pnum;

    return(*paux);
}

float divide(int* pnum, float* paux)
{
    *paux /= (float)*pnum;

    return(*paux);
}

void main()
{
    int num, *pnum, i;
    float aux, *paux;
    char op, resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {
        pnum = &num;
        paux = &aux;
        *paux = 0;

        i = 0;

        for (;;)
        {
            if (i == 0)
            {
                recebe(pnum);
                *paux = (float)*pnum;
                i = 1;
            }

            do
            {
                printf("\n Insira a operação que deseja realizar\n\n\t(+) SOMA\n\t(-) SUBTRAÇÃO\n\t(*) MULTIPLICAÇÃO\n\t(/) DIVISÃO\n\t(=) FINALIZA\n");
                printf("\n Operação: ");
                getchar();
                op = getchar();

                switch (op)
                {
                case '+':
                {
                    recebe(pnum);

                    *paux = soma(pnum, paux);

                    system("cls");

                    printf("\n\t ___________________________________");
                    printf("\n\t|                                   |");
                    printf("\n\t|  SOMA => %-10.2f               |", *paux);
                    printf("\n\t|___________________________________|\n");

                    break;
                }
                case '-':
                {
                    recebe(pnum);

                    *paux = subtra(pnum, paux);

                    system("cls");

                    printf("\n\t ___________________________________");
                    printf("\n\t|                                   |");
                    printf("\n\t|  SUBTRAÇÃO => %-10.2f          |", *paux);
                    printf("\n\t|___________________________________|\n");

                    break;
                }
                case '*':
                {
                    recebe(pnum);

                    *paux = multi(pnum, paux);

                    system("cls");

                    printf("\n\t ___________________________________");
                    printf("\n\t|                                   |");
                    printf("\n\t|  MULTIPLICAÇÃO => %-10.2f      |", *paux);
                    printf("\n\t|___________________________________|\n");

                    break;
                }
                case '/':
                {
                    do
                    {
                        recebe(pnum);

                        if (*pnum == 0)
                        {
                            printf("\n Não é possível dividir por zero!!!\n");
                        }
                    } while (*pnum == 0);

                    (float)*paux = divide(pnum, paux);

                    system("cls");

                    printf("\n\t ___________________________________");
                    printf("\n\t|                                   |");
                    printf("\n\t|  DIVISÃO => %-10.2f            |", (float)*paux);
                    printf("\n\t|___________________________________|\n");

                    break;
                }
                case '=':
                {
                    system("cls");

                    printf("\n\t ___________________________________");
                    printf("\n\t|                                   |");
                    printf("\n\t|  RESULTADO FINAL => %-10.2f    |", *paux);
                    printf("\n\t|___________________________________|\n\n");

                    break;
                }
                default:
                {
                    printf("\n Operação inválida!!!\n");
                }
                }

            } while (op != '=');

            if (op == '=')
            {
                break;
            }
        }

        printf("\n ");
        system("pause");
        system("cls");

        printf("\n Deseja informar novos valores? (S/N):\t ");
        getchar();
        resp = getchar();

        if (resp == 's' || resp == 'S')
        {
            system("cls");
        }
        else
        {
            break;
        }
    }
}
#endif // ex2

#ifdef ex3

/*
    3 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
        pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa no
        video na funcao main(). O vetor é uma variavel local na função main(). Passe
        como parametro para a funcao o vetor e a letra digitada usando ponteiros.
        Pesquise usando ponteiros. (utilize o comando return)
        vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

int* pRESP;

int pesquisa(char c, char* pvetor)
{
    int i, aux = 0;
    int* pAUX;

    pAUX = &aux;
    pRESP = &i;

    for (i = 0; i < 13; i++)
    {
        if (*(pvetor + i) == c)
        {
            *pAUX = 1;
            *pRESP = i;
            break;
        }
    }
    return(*pAUX);
}

void main()
{
    char c, resp;
    char* cc;

    char vetor[14] = { 'b','d','f','h','j','l','m','o','q','s','u','w','y' };

    setlocale(LC_ALL, "Portuguese");

    cc = &c;

    for (;;)
    {
        system("color 1F");

        printf("\n Insira uma letra: ");
        *cc = getchar();

        if (!(pesquisa(*cc, vetor)))
        {
            printf("\n A letra '%c'  NÃO EXISTE no vetor\n\n", *cc);
        }
        else
        {
            printf("\n A letra '%c' EXISTE na posição vetor[%d]\n\n", *cc, *pRESP);
        }

        system("pause");
        system("cls");

        printf("\n Deseja informar novos valores? (S/N): ");
        getchar();
        resp = getchar();
        getchar();

        if (resp == 's' || resp == 'S')
        {
            system("cls");
        }
        else
        {
            break;
        }
    }
}
#endif // ex3

#ifdef ex4

/*
    4 - Escreva um programa que receba em 1 funcao 2 strings de ate' 10 caracteres.
        Os vetores sao declaradas como variavel local na função main().
        Escreva uma funcao que recebe as 2 strings como parametros usando ponteiros
        e compare estas 2 strings.
        Retorne como resultado da comparacao 0 se forem DIFERENTES, 1 se forem
        IGUAIS, 2 se a string 1 for maior que a string 2, 3 se a string 2 for maior
        que a string 1 e 4 se as string tem tamanhos iguais mas são diferentes.
*/

void recebe(char* ps1, char* ps2)
{
    int i;

    do
    {
        for (i = 0; i < 11; i++)
        {
            *(ps1 + i) = '\0';
        }

        printf("\nInforme a primeira string: ");
        gets(ps1);

        if (*(ps1 + 10) != '\0')
        {
            printf("\nA string deve ter no máx 10 caracteres!!!\n\n");

            system("pause");
            system("cls");
        }
    } while (*(ps1 + 10) != '\0');

    do
    {
        for (i = 0; i < 11; i++)
        {
            *(ps2 + i) = '\0';
        }

        printf("\nInforme a segunda string: ");
        gets(ps2);

        if (*(ps2 + 10) != '\0')
        {
            printf("\nA string deve ter no máx 10 caracteres!!!\n\n");

            system("pause");
            system("cls");
        }
    } while (*(ps2 + 10) != '\0');
}

int compara(char* ps1, char* ps2)
{
    int a = 1, i = 0;

    while (i < 11 && a == 1)
    {
        if (*(ps1 + i) != *(ps2 + i))
        {
            a = 0;
        }
        else
        {
            i += 1;
        }
    }

    return a;
}

int analisa(char* ps1, char* ps2)
{
    int i, j = 0, k = 0;

    for(i = 0; i < 11; i++)
    {
        if (*(ps1 + i) != '\0')
        {
            j += 1;
        }
    }

    for (i = 0; i < 11; i++)
    {
        if (*(ps2 + i) != '\0')
        {
            k += 1;
        }
    }

    if (j > k) // s1 maior que s2
    {
        return (2);
    }
    else if (j < k) // s2 maior que s1
    {
        return (3);
    }
    else // j == k  ==>  s1 e s2 tem o mesmo tamanho
    {
        return (4);
    }
}

void main()
{
    char s1[11], s2[11], resp;
    int i, RESP;

    setlocale(LC_ALL, "Portuguese");

    for(;;)
    {
        recebe(s1, s2);

        RESP = compara(s1, s2);

        if (RESP)
        {
            printf("\n\nAs strings s1 e s2 são IGUAIS!\n\n\n");
        }
        else
        {
            RESP = analisa(s1, s2);

            if (RESP == 2)
            {
                printf("\n\nA string s1 é maior que a string s2, portanto elas são DIFERENTES!\n\n\n");
            }
            else if (RESP == 3)
            {
                printf("\n\nA string s2 é maior que a string s1, portanto elas são DIFERENTES!\n\n\n");
            }
            else
            {
                printf("\n\nAs strings s1 e s2 tem o mesmo tamanho, porém são DIFERENTES!\n\n\n");
            }
        }

        system("pause");
        system("cls");

        printf("\nDeseja informar novas strings? (S/N)\t");
        resp = getchar();
        getchar();

        if (resp == 's' || resp == 'S')
        {
            system("cls");
        }
        else
        {
            break;
        }

    }
}
#endif // ex4

#ifdef ex5

/*
    5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
        de 4 elementos como variavel local na funcao main(). Receba os 4 registros
        sequencialmente pelo teclado numa função e imprima todos os registros no
        video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
        Coloque no menu a opção de sair tambem. Utilize o comando switch.
        (vetor de estruturas)
        nome, end, cidade, estado, cep
*/

struct cad
{
    unsigned char nome[25];
    unsigned char end[35];
    unsigned char cidade[30];
    unsigned char estado[20];
    char cep[10];
};

void CADASTRAR(struct cad *p, int i)
{
   system("cls");
   system("color 1F");

   if (i<=3)
   {
      for(i=0;i<4;i++)
      {
         system("cls");

         printf("\n\t\t     ##### CADASTRO DO CLIENTE #####\n\n\n");

         printf("\t\t CLIENTE %d\n\n",i+1);

         printf("\t\tNOME: ");
         gets((p+i)->nome);
         printf("\n\t\tEND.: ");
         gets((p+i)->end);
         printf("\n\t\tCIDADE: ");
         gets((p+i)->cidade);
         printf("\n\t\tESTADO: ");
         gets((p+i)->estado);
         printf("\n\t\tCEP: ");
         gets((p+i)->cep);
         printf("\n\t\t");
      }

      i = 4;
   }
   else
   {
      system("cls");
      system("color 4F");
      printf("\n\t\t     ##### WARNING #####\n\n\n");
      printf("\n\t\tLISTA LOTADA!\n\n\n\t\t");
   }

   system("pause");
   system("cls");
}

void LISTAR(struct cad *p, int j, int i)
{
   if (i == 0)
   {
      system("cls");
      system("color 4F");
      printf("\n\t\t     ##### WARNING #####\n\n\n");
      printf("\n\t\tLista vazia!\n\n\n\t\t");
   }
   else
   {
       system("cls");
       printf("\n\t\t     ##### DADOS DOS CLIENTES #####\n\n\n");
       for (j = 0; j < i; j++)
      {
         printf("\n\t\tNOME: %s", (p+j)->nome);
         printf("\n\t\tEND.: %s", (p+j)->end);
         printf("\n\t\tCIDADE: %s", (p+j)->cidade);
         printf("\n\t\tESTADO: %s", (p+j)->estado);
         printf("\n\t\tCEP: %s\n", (p+j)->cep);
      }
   }
   printf("\n\t\t");
   system("pause");
   system("cls");
}

void SAIR()
{
   system("cls");
   system("color 70");
   printf("\n\n\n\n\n\t\t\t*** PROGRAMA FINALIZADO ***\n\n\n");
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
   exit(0);
}

void ERRO()
{
   system("cls");
   system("color 4F");
   printf("\n\t\t     ***** WARNING *****\n\n\n");
   printf("\n\t\tESCOLHA INVALIDA!\n\n\n\t\t");
   system("pause");
   system("cls");
}

void main()
{
    int op, i = 0, j = 0;

    struct cad cliente[4];

    struct cad *p;

    p=&cliente[0];

    for (;;)
    {
        system("color 1F");

        printf("\n\t\t     ##### MENU #####\n\n\n");
        printf("\t\t1 - CADASTRAR\n\n");
        printf("\t\t2 - LISTAR\n\n");
        printf("\t\t3 - SAIR\n\n");

        printf("\n\t\tINFORME SUA ESCOLHA: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
            CADASTRAR(p, i);
            i = 4;
            break;

        case 2:
            LISTAR(p, j, i);
            break;

        case 3:
            SAIR();
            break;

        default:
            ERRO();
            break;
        }
    }
}

#endif // ex5

#ifdef ex6

/*
    6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
        exclui um registro.
*/

struct cad
{
    unsigned char nome[25];
    unsigned char end[35];
    unsigned char cidade[30];
    unsigned char estado[20];
    char cep[10];
};

void CADASTRAR(struct cad *p, int i, int b)
{
   system("cls");
   system("color 1F");

   if(b==-1)
   {
      if (i<=3)
      {
         for(i=0;i<4;i++)
         {
            system("cls");
            printf("\n\t\t     ##### CADASTRO DO CLIENTE #####\n\n\n");

             printf("\t\t CLIENTE %d\n\n",i+1);

             printf("\t\tNOME: ");
             gets((p+i)->nome);
             printf("\n\t\tEND.: ");
             gets((p+i)->end);
             printf("\n\t\tCIDADE: ");
             gets((p+i)->cidade);
             printf("\n\t\tESTADO: ");
             gets((p+i)->estado);
             printf("\n\t\tCEP: ");
             gets((p+i)->cep);
             printf("\n\t\t");
         }

         i=4;
      }
      else
      {
         system("cls");
         system("color 4F");
         printf("\n\t\t     ##### WARNING #####\n\n\n");
         printf("\n\t\tLISTA LOTADA!\n\n\n\t\t");
      }
   }
   else
   {
      printf("\n\t\t     ##### CADASTRO DO CLIENTE #####\n\n\n");
      printf("\t\t CLIENTE %d\n\n",b+1);

      printf("\t\tNOME: ");
      gets((p+b)->nome);
      printf("\n\t\tEND.: ");
      gets((p+b)->end);
      printf("\n\t\tCIDADE: ");
      gets((p+b)->cidade);
      printf("\n\t\tESTADO: ");
      gets((p+b)->estado);
      printf("\n\t\tCEP: ");
      gets((p+b)->cep);
   }
}


void LISTAR(struct cad *p, int j, int i)
{
   if (i==0)
   {
      system("cls");
      system("color 4F");
      printf("\n\t\t     ##### WARNING #####\n\n\n");
      printf("\n\t\tLista vazia!\n\n\n\t\t");
   }
   else
   {
      system("cls");
      printf("\n\t\t     ##### DADOS DOS CLIENTES #####\n\n\n");

      for (j=0;j<i;j++)
      {
         if((p+j)->nome[0]!='\0')
         {
            printf("\n\t\tNOME: %s", (p+j)->nome);
            printf("\n\t\tEND.: %s", (p+j)->end);
            printf("\n\t\tCIDADE: %s", (p+j)->cidade);
            printf("\n\t\tESTADO: %s", (p+j)->estado);
            printf("\n\t\tCEP: %s\n", (p+j)->cep);

         }
      }
   }
}

int PROCURAR(struct cad *p, int i)
{
   int u;
   int v;

   if (i==0)
   {
      system("cls");
      system("color 4F");
      printf("\n\t\t     ##### WARNING #####\n\n\n");
      printf("\n\t\tLista vazia!\n\n\n\t\t");
   }
   else
   {
      system("cls");
      system("color 1F");

      printf("\n\t\t     ##### PESQUISA #####\n\n\n");
      printf("\t\tInforme o nome: ");
      gets((*(p+4)).nome);

      for(u=0;u<4;u++)
      {
         for(v=0;(p+4)->nome[v] !='\0';v++)
         {
            if((p+4)->nome[v] !=(p+u)->nome[v])
            {
                break;
            }
         }

         if((p+4)->nome[v] =='\0' && (p+u)->nome[v] =='\0')
         {
             printf("\n\t\tNOME: %s\t\t",(p+u)->nome);
             printf("\n\t\tEND.: %s\t\t",(p+u)->end);
             printf("\n\t\tCIDADE: %s\t\t",(p+u)->cidade);
             printf("\n\t\tESTADO: %s\t\t",(p+u)->estado);
             printf("\n\t\tCEP: %s\n\t\t",(p+u)->cep);

             return u;
         }
      }

      system("cls");
      system("color 4F");
      printf("\n\n\t\tREGISTRO INEXISTENTE!!!\n\n");

      return -1;
  }
}

void ALTERAR(struct cad *p, int i)
{
   int k;

   if (i==0)
   {
      system("cls");
      system("color 4F");
      printf("\n\t\t     ##### WARNING #####\n\n\n");
      printf("\n\t\tLista vazia!\n\n\n\t\t");
   }
   else
   {
      system("cls");
      system("color 1F");

      k=PROCURAR(p,i);

      if(k==-1)
      {
         printf("\t\t");
         system("pause");
         system("cls");
         system("color 4F");

         printf("\n\t\t     ##### WARNING #####\n\n\n");
         printf("\n\t\tPROCESSO CANCELADO!!!\n\n\n\t\t");
      }
      else
           {
              (*(p+k)->nome)='\0';
              (*(p+k)->end)='\0';
              (*(p+k)->cidade)='\0';
              (*(p+k)->estado)='\0';
              (*(p+k)->cep)='\0';

              printf("\n\t\t");
              system("pause");
              system("cls");

              printf("\n\t\t     ##### ALTERAR CLIENTE #####\n\n\n");

              printf("\t\t CLIENTE %d\n\n",k+1);

              printf("\t\tNOME: ");
              gets((p+k)->nome);
              printf("\n\t\tEND.: ");
              gets((p+k)->end);
              printf("\n\t\tCIDADE: ");
              gets((p+k)->cidade);
              printf("\n\t\tESTADO: ");
              gets((p+k)->estado);
              printf("\n\t\tCEP: ");
              gets((p+k)->cep);
              printf("\t\t");

              printf("\n\n\t\tCLIENTE ALTERADO!\n\n\t\t");
           }
   }
}

int EXCLUIR(struct cad *p, int i)
{
   int k;

   if (i==0)
   {
      system("cls");
      system("color 4F");
      printf("\n\t\t     ##### WARNING #####\n\n\n");
      printf("\n\t\tLista vazia!\n\n\n\t\t");

      return -1;
   }
   else
   {
      system("color 1F");

      k=PROCURAR(p,i);

      if(k==-1)
      {
         printf("\t\t");
         system("pause");
         system("cls");
         system("color 4F");

         printf("\n\t\t     ##### WARNING #####\n\n\n");
         printf("\n\t\tPROCESSO CANCELADO!!!\n\n\n\t\t");

         return k;
      }
      else
      {
         (*(p+k)->nome)='\0';
         (*(p+k)->end)='\0';
         (*(p+k)->cidade)='\0';
         (*(p+k)->estado)='\0';
         (*(p+k)->cep)='\0';

         printf("\n\n\t\tCLIENTE EXCLUIDO!\n\n\t\t");

         return k;
      }
   }
}

void SAIR()
{
   system("cls");
   system("color 70");
   printf("\n\n\n\n\n\t\t\t*** PROGRAMA FINALIZADO ***\n\n\n");
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
   exit(0);
}

void ERRO()
{
   system("cls");
   system("color 4F");
   printf("\n\t\t     ***** WARNING *****\n\n\n");
   printf("\n\t\tESCOLHA INVALIDA!\n\n\n\t\t");
}

void main()
{
    int op, i=0, j=0, b=-1;

    struct cad cliente[5];

    struct cad *p;

    p=&cliente[0];

    for (;;)
    {
        system("color 1F");

        printf("\n\t\t     ##### MENU #####\n\n\n");
        printf("\t\t1 - CADASTRAR\n\n");
        printf("\t\t2 - LISTAR\n\n");
        printf("\t\t3 - PROCURAR\n\n");
        printf("\t\t4 - AlTERAR\n\n");
        printf("\t\t5 - EXCLUIR\n\n");
        printf("\t\t6 - SAIR\n\n");

        printf("\n\t\tINFORME SUA ESCOLHA: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
           case 1:
              CADASTRAR(p,i,b);
              i=4;
              break;

           case 2:
              LISTAR(p,j,i);
              break;

           case 3:
              PROCURAR(p,i);
              break;

           case 4:
              ALTERAR(p,i);
              break;

           case 5:
              b=EXCLUIR(p,i);
              break;

           case 6:
              SAIR();
              break;

           default:
              ERRO();
              break;
        }

        printf("\n\t\t");
        system("pause");
        system("cls");
    }
}

#endif // ex6



