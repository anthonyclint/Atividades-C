//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex1

#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
    1 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
        pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
        no video na funcao main(). Passe como informacao para a funcao a letra
        digitada.(utilize o comando return). O vetor deve ser uma variavel global.

        vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

char vetor[14] = { 'b','d','f','h','j','k','m','o','q','s','u','w','y' };
int RESP;

int pesquisa(char c)
   {
    int i, aux = 0;

    for (i = 0; i < 13; i++)
       {
        if (vetor[i] == c)
           {
            aux = 1;
            RESP = i;
            break;
           }
       }

    return(aux);

   }

void main()
   {
    char c, resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
       {
        printf("\n Insira uma letra: ");
        scanf("%c", &c);

        if (!(pesquisa(c)))
           {
            printf("\n A letra '%c'  não foi encontrada no vetor\n\n", c);
           }
        else
           {
            printf("\n A letra '%c' foi encontrada na posição vetor[%d]\n\n", c, RESP);
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
#endif // ex1

#ifdef ex1b

/*
    1 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
        pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
        no video na funcao main(). Passe como informacao para a funcao a letra
        digitada.(utilize o comando return). O vetor deve ser uma variavel global.

        vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

char vetor[14] = { 'b','d','f','h','j','k','m','o','q','s','u','w','y' };
int RESP[2];

void pesquisa(char c)
{
    int i, aux = 0;

    for (i = 0; i < 13; i++)
    {
        if (vetor[i] == c)
        {
            aux = 1;
            RESP[0] = i;
            break;
        }
    }

    RESP[1] = aux;

}

void main()
{
    char c, resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {
        printf("\n Insira uma letra: ");
        scanf_s("%c", &c);

        pesquisa(c);

        if (!(RESP[1]))
        {
            printf("\n A letra '%c'  não foi encontrada no vetor\n\n", c);
        }
        else
        {
            printf("\n A letra '%c' foi encontrada na posição vetor[%d]\n\n", c, RESP[0]);
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
#endif // ex1b

#ifdef ex2

/*
    2 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
        uma funcao para cada operacoes aritmeticas e passe como parametro os 2
        valores recebidos na funcao main(). Retorne os resultados usando o comando
        return e imprima-os no video na funcao main().
*/

int soma(int a, int b)
   {
    return (a+b);
   }

int subtra(int a, int b)
   {
    return(a-b);
   }

int multi(int a, int b)
   {
    return(a*b);
   }

float divide(int a, int b)
   {
    return(((float)a / (float)b));
   }

void main()
   {
    int a, b;
    char resp;

    setlocale(LC_ALL, "Portuguese");

    do
       {
        printf("\n Informe o primeiro valor: ");
        scanf("%d", &a);

        printf("\n Informe o segundo valor: ");
        scanf("%d", &b);

        printf("\n");
        system("pause");
        system("cls");

        printf("\n\t%d + %d = %d\n", a, b, soma(a, b));

        printf("\n\t%d - %d = %d\n", a, b, subtra(a, b));

        printf("\n\t%d x %d = %d\n", a, b, multi(a, b));

        if (b == 0)
           {
            printf("\n\tNão é possível realizar divisão por zero!\n");
           }
        else
           {
            printf("\n\t%d / %d = %.2f\n", a, b, divide(a, b));
           }

        printf("\n");
        system("pause");
        system("cls");

        printf("\nDeseja informar novos valores? (S/N):\t ");
        getchar();
        resp = getchar();

        if (resp == 's' || resp == 'S')
           {
            system("cls");
           }

       }while (resp == 's' || resp == 'S');
   }
#endif // ex2

#ifdef ex3

/*
    3 - Reescreva o programa do exercicio anterior para receber via
        teclado n valores. Os n valores nao sao definidos previamente.
*/

int soma(int a, int ad)
   {
    ad += a;

    return (ad);
   }

int subtra(int a, int sub)
   {
    sub -= a;

    return (sub);
   }

int multi(int a, int mult)
   {
    mult *= a;

    return (mult);
   }

float divide(int a, float div)
   {
    div /= (float)a;

    return (div);

   }

void main()
   {
    int a, ad, sub, mult, i;
    float div;
    char resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
       {
        i = 0;

        do
           {
            printf("\n Informe valor desejado ou digite 0 para finalizar: ");
            scanf("%d", &a);

            if (i == 0 && a!=0)
               {
                ad = a;
                sub = a;
                mult = a;
                div = (float)a;
                i = 1;
               }
            else if (a != 0)
               {
                ad = soma(a, ad);
                sub = subtra(a, sub);
                mult = multi(a, mult);
                div = divide(a, div);

                printf("\n      RESULTADOS PRELIMINARES\n\n");

                printf("\n\tSOMA => %d\n", ad);

                printf("\n\tSUBTRAÇÃO => %d\n", sub);

                printf("\n\tMULTIPLICAÇÃO => %d\n", mult);

                printf("\n\tDIVISÃO => %.2e\n", div);

                printf("\n");
                system("pause");
                system("cls");
               }

           }while (a != 0);

        if (i == 0)
           {
            printf("\n O programa foi finalizado sem nenhuma entrada de dados!!!\n");
           }
        else if (i == 1)
           {
            printf("\n Não foi possivel realizar as operações pois foi inserido apenas 1 número\n");
           }
        else
           {
            printf("\n      RESULTADOS FINAIS\n\n");

            printf("\n  SOMA => %d\n", ad);

            printf("\n  SUBTRAÇÃO => %d\n", sub);

            printf("\n  MULTIPLICAÇÃO => %d\n", mult);

            printf("\n  DIVISÃO => %.2e\n", div);
           }

        printf("\n");
        system("pause");
        system("cls");

        printf("\nDeseja informar novos valores? (S/N):\t ");
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
#endif // ex3

#ifdef ex4

/*
    4 - Aproveitando o programa anterior, e inclua a selecao das operacoes aritmeticas
        para transforma-lo em uma calculadora. (utilize o comando switch).
*/

float soma(int a, float aux)
   {
    aux += a;

    return (aux);
   }

float subtra(int a, float aux)
   {
    aux -= a;

    return (aux);
   }

float multi(int a, float aux)
   {
    aux *= a;

    return (aux);
   }

float divide(int a, float aux)
   {
    aux /= (float)a;

    return (aux);
   }

void main()
   {
    int a, i;
    float aux;
    char op, resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
       {
        aux = 0;
        i = 0;

        for (;;)
           {
            printf("\nPara finalizar digite 0\n");
            printf("\nInforme o %dº número: ", i + 1);
            scanf("%d", &a);

            if (i == 0 && a != 0)
               {
                aux = a;
                i = 1;
               }
            else if (i != 0 && a != 0)
               {
                do
                   {
                    printf("\nInsira a operação que deseja realizar   +   -   *   /\n");
                    printf("\nOperação: ");
                    getchar();
                    op = getchar();

                    i++;

                    switch (op)
                       {
                        case '+':
                           {
                            aux = soma(a, aux);

                            printf("\nSOMA => %.2f\n", aux);

                            break;
                           }

                        case '-':
                           {
                            aux = subtra(a, aux);

                            printf("\nSUBTRAÇÃO => %.2f\n", aux);

                            break;
                           }

                        case '*':
                           {
                            aux = multi(a, aux);

                            printf("\nMULTIPLICAÇÃO => %.2f\n", aux);

                            break;
                           }

                        case '/':
                           {
                            (float)aux=divide(a,aux);

                             printf("\nDIVISÃO => %.2f\n", (float)aux);

                             break;
                           }

                        default:
                           {
                            printf("\nOperação inválida!!!\n");
                           }
                       }

                   }while (op != '+' && op != '-' && op != '*' && op != '/');
               }

            if (a == 0)
               {
                if (i == 0)
                   {
                    printf("\nO programa foi finalizado sem nenhuma entrada de dados!!!\n");
                   }
                else if (i == 1)
                   {
                    printf("\nNão foi possivel realizar as operações pois foi inserido apenas 1 número\n");
                   }
                else
                   {
                    printf("\n");
                    system("pause");
                    system("cls");

                    printf("\nRESULTADO FINAL => %.2f\n", aux);
                   }

                break;
               }
           }

        printf("\n");
        system("pause");
        system("cls");

        printf("\nDeseja informar novos valores? (S/N):\t ");
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
#endif // ex4

#ifdef ex5
/*
  5 - Escreva um programa que receba na funcao main() 2 strings de ate' 10 caracteres.
    Escreva a funcao que compare estas 2 strings e retorne se sao IGUAIS 1 e
    se DIFERENTES 0. Declare as strings como variavel global.
*/

char str1[11], str2[11];

int compara()
   {
    int a = 1, i;

    i = 0;
    while (i < 10 && a == 1)
       {
        if (str1[i] != str2[i])
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

main()
   {
    int b;
    char resp;

    setlocale(LC_ALL, "Portuguese");

    do
       {
        do
           {
            for(int i=0;i<11;i++)
               {str1[i]=0;}

            printf("\nInforme a primeira string: ");
            gets(str1);

            if (str1[10] != '\0')
               {
                printf("\nA string deve ter no máx 10 caracteres!!!\n\n");

                system("pause");
                system("cls");
               }
           } while (str1[10] != '\0');

        do
           {
            for(int i=0;i<11;i++)
               {str2[i]=0;}

            printf("\nInforme a segunda string: ");
            gets(str2);

            if (str2[10] != '\0')
               {
                printf("\nA string deve ter no máx 10 caracteres!!!\n\n");

                system("pause");
                system("cls");
               }
           } while (str2[10] != '\0');

        b=compara();

        if(b)
           {
            printf("\nAs strings str1 e str2 são IGUAIS!\n\n");
           }
        else
           {
            printf("\nAs strings str1 e str2 são DIFERENTES!\n\n");
           }

        system("pause");
        system("cls");

        printf("\nDeseja informar novas strings? (S/N): ");
        resp = getchar();
        getchar();

        if (resp == 's' || resp == 'S')
           {
            system("cls");
           }

       } while (resp == 's' || resp == 'S');
   }
#endif // ex5
