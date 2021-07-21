//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex1
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
    1 - Escreva um programa que receba via teclado usando ponteiros um char,
        int, long, unsigned,float, double, unsigned long e unsigned char,
        e imprima-os no video utilizando ponteiros e o operador de conteudo *
        no seguinte formato:

                 10        20        30        40        50        60
        123456789012345678901234567890123456789012345678901234567890
            int                 long                unsigned
                      float               double              char
                 unsigned long       unsigned char
*/

struct tipos // novo tipo de variável
{
    int a;
    long int b;
    unsigned int c;
    float d;
    double e;
    char f;
    unsigned long int g;
    unsigned char h;
};

struct tipos num; // variável do tipo "struct tipos" de nome "num"

void main()
{
    char resp, * presp;

    setlocale(LC_ALL, "Portuguese");

    struct tipos* ponteiro;

    ponteiro = &num;

    presp = &resp;

    for (;;)
    {
        printf("Insira um número inteiro: ");
        scanf("%d", &(*ponteiro).a);
        printf("\nInsira um número inteiro: ");
        scanf("%ld", &(*ponteiro).b);
        printf("\nInsira um número inteiro maior ou igual a zero: ");
        scanf("%u", &(*ponteiro).c);
        printf("\nInsira um número qualquer: ");
        scanf("%f", &(*ponteiro).d);
        printf("\nInsira um número qualquer: ");
        scanf("%lf", &(*ponteiro).e);
        getchar();
        printf("\nInsira um caractere: ");
        scanf("%c", &(*ponteiro).f);
        printf("\nInsira um número inteiro maior ou igual a zero: ");
        scanf("%lu", &(*ponteiro).g);
        getchar();
        printf("\nInsira um caractere: ");
        scanf("%c", &(*ponteiro).h);

        printf("\n\n");
        printf("\t         10        20        30        40        50        60        70\n");
        printf("\t1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("\t    %-6d              %-11ld         %-5u\n", (*ponteiro).a, (*ponteiro).b, (*ponteiro).c);
        printf("\t              %-8.1e            %-9.1e           %c\n", (*ponteiro).d, (*ponteiro).e, (*ponteiro).f);
        printf("\t         %-10lu          %c\n\n\n", (*ponteiro).g, (*ponteiro).h);

        system("pause");
        system("cls");

        printf("Deseja inserir novos valores? S/N\t");
        getchar();
        *presp = getchar();

        if (*presp == 's' || *presp == 'S')
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
    2 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
        Receba os dados pelo teclado usando ponteiros e imprima-os no video
        também usando ponteiros. Utilize um comando de loop. (vetor de estruturas)
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

struct cad cliente[4];

void main()
{
    int op, i = 0, j;

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

        switch (op)
        {
           case 1:
              system("cls");
              system("color 1F");
              if (i <= 3)
              {
                 printf("\n\t\t     ##### CADASTRO DO CLIENTE #####\n\n\n");
                 getchar();
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
                 i++;
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
              break;

           case 2:

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
              system("color 4F");
              printf("\n\t\t     ***** WARNING *****\n\n\n");
              printf("\n\t\tESCOLHA INVALIDA!\n\n\n\t\t");
              system("pause");
              system("cls");
              break;
        }
    }

}
#endif // ex2


#ifdef ex3
/*
    3 - Receba um caracter via teclado usando ponteiros e compara com o vetor abaixo
        usando ponteiros. Mostre como resultado se são EXISTE ou NAO EXISTE.
        vetor -> b,d,f,h,j,l,m,o,q,s,u,w,y
*/


char vetor[14] = { 'b','d','f','h','j','l','m','o','q','s','u','w','y' };
int* pRESP;

int pesquisa(char c)
{
    int i, aux = 0;
    int * pAUX;
    char* pvetor;

    pAUX = &aux;
    pRESP = &i;

    for (i = 0; i < 13; i++)
    {
        pvetor = &vetor[i];

        if (*pvetor == c)
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

    setlocale(LC_ALL, "Portuguese");

    cc = &c;

    for (;;)
    {
        system("color 1F");

        printf("\n Insira uma letra: ");
        *cc = getchar();

        if (!(pesquisa(*cc)))
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
    4 - Receba 2 string de ate 10 caracteres via teclado, compare-as usando ponteiros
        e mostre como resultado se são IGUAIS ou DIFERENTES.
*/

struct str
{
    char s1[11];
    char s2[11];
};

struct str string;

main()
{
    char resp;
    int i, a = 1;
    struct str* p;

    p = &string;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {
        system("cls");
        system("color 1F");
        printf("\n\t\t###### COMPARAÇÃO DE STRINGS ######\n\n");
        printf("\n\t\tInforme a string s1: ");
        gets((*p).s1);

        printf("\n\t\tInforme a string s2: ");
        gets((*p).s2);

        i = 0;
        while ((*p).s1[i] == (*p).s2[i] && (*p).s1[i] != '\0' && (*p).s2[i] != '\0')
        {
            i++;
        }

        if ((*p).s1[i] == '\0' && (*p).s2[i] == '\0')
        {
            printf("\n\t\tAs strings s1 e s2 são IGUAIS!\n\n");
        }
        else
        {
            printf("\n\t\tAs strings s1 e s2 são DIFERENTES!\n\n");
        }

        system("pause");
        system("cls");

        printf("\n\t\tDeseja informar novas strings?(S/N): ");

        resp = getchar();
        getchar();

        if (resp == 's' || resp == 'S')
        {
            p->s1[0]='\0';
            p->s2[0]='\0';
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
    5 - Escreva um programa que receba via teclado numeros inteiros positivos usando
        ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
        a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
        feitos usando ponteiro.
*/

main()
{
    int num, * pnum, soma = 0, * psoma, cont = 0, * pcont;
    float media, * pmedia;

    setlocale(LC_ALL, "Portuguese");

    pnum = &num;
    psoma = &soma;
    pcont = &cont;
    pmedia = &media;

    for (;;)
    {
        printf("\nInforme um número: ");
        scanf("%d", pnum);

        if (*pnum >= 0)
        {
            *psoma = *psoma + *pnum;

            *pcont = *pcont + 1;
        }
        else
        {
            *pmedia = ((float)*psoma) / ((float)*pcont);
            break;
        }
       }

    printf("\nA média dos números positivos é igual a %.2f.\n", *pmedia);
}
#endif // ex5

#ifdef ex6

/*
    6 - Escreva um programa que contenha uma estrutura representando uma data
        valida. Essa estrutura deve conter os campos dia, mes e ano. Em seguida,
        leia duas datas e armazene nessa estrutura usando ponteiros. Calcule e exiba o
        numero de dias que decorreram entre as duas datas usando ponteiros.
*/

struct data
{
    int dia, mes, ano;
};

struct data periodo[3];

void main()
{
    struct data *pperiodo;

    pperiodo = &periodo[0];

    int i, p;
    char resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {

        for (i = 0; i < 2; i++)
        {
            do
            {
                p = 0;

                printf("\nInsira a %dª data: \n\n", i + 1);
                printf(" Dia: ");
                scanf("%d", &(*(pperiodo + i)).dia);
                printf(" Mês: ");
                scanf("%d", &(*(pperiodo + i)).mes);
                printf(" Ano: ");
                scanf("%d", &(*(pperiodo + i)).ano);

                if (((*(pperiodo + i)).dia < 1 || (*(pperiodo + i)).dia >31) || ((*(pperiodo + i)).mes < 1 || (*(pperiodo + i)).mes > 12) || ((*(pperiodo + i)).ano < 1))
                {
                    p = 1;
                }

                if (((*(pperiodo + i)).mes == 4 || (*(pperiodo + i)).mes == 6 || (*(pperiodo + i)).mes == 9 || (*(pperiodo + i)).mes == 11) && (*(pperiodo + i)).dia > 30)
                {
                    p = 1;
                }

                if (((*(pperiodo + i)).mes == 2) && ((*(pperiodo + i)).dia + (*(pperiodo + i)).mes) > 31)
                {
                    p = 1;
                }

                if (((*(pperiodo + i)).mes == 2) && ((*(pperiodo + i)).dia == 29))
                {
                    if (!(((*(pperiodo + i)).ano % 4 == 0) && ((*(pperiodo + i)).ano % 100 != 0) || ((*(pperiodo + i)).ano % 400 == 0)))
                    {
                        p = 1;
                    }
                }

                if (p)
                {
                    printf("\nA data %d/%d/%d não é válida!\n", (*(pperiodo + i)).dia, (*(pperiodo + i)).mes, (*(pperiodo + i)).ano);
                }

            } while (p);
        }

        if ((*(pperiodo + 1)).ano < (*(pperiodo)).ano)
        {
            (*(pperiodo + 2)).ano = (*(pperiodo)).ano;
            (*(pperiodo)).ano = (*(pperiodo + 1)).ano;
            (*(pperiodo + 1)).ano = (*(pperiodo + 2)).ano;
            (*(pperiodo + 2)).mes = (*(pperiodo)).mes;
            (*(pperiodo)).mes = (*(pperiodo + 1)).mes;
            (*(pperiodo + 1)).mes = (*(pperiodo + 2)).mes;
            (*(pperiodo + 2)).dia = (*(pperiodo)).dia;
            (*(pperiodo)).dia = (*(pperiodo + 1)).dia;
            (*(pperiodo + 1)).dia = (*(pperiodo + 2)).dia;
        }

        if ((*(pperiodo)).mes > (*(pperiodo + 1)).mes)
        {
            (*(pperiodo)).ano += 1;
            (*(pperiodo + 1)).mes += 11;
        }

        if ((*(pperiodo)).dia > (*(pperiodo + 1)).dia)
        {
            (*(pperiodo + 1)).dia += 30;
        }

        (*(pperiodo + 2)).ano = abs((*(pperiodo)).ano - (*(pperiodo + 1)).ano);
        (*(pperiodo + 2)).mes = abs((*(pperiodo)).mes - (*(pperiodo + 1)).mes);
        (*(pperiodo + 2)).dia = abs((*(pperiodo)).dia - (*(pperiodo + 1)).dia);

        printf("\nDecorreram %d ano(s) %d mes(es) %d dia(s) \n\n", (*(pperiodo + 2)).ano, (*(pperiodo + 2)).mes, (*(pperiodo + 2)).dia);

        system("pause");
        system("cls");

        printf("\n Deseja calcular outro período? S/N\t");
        getchar();
        resp = getchar();

        printf("\n");

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
#endif // ex6
