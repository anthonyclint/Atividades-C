//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex5
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
    1 - Escreva um programa que receba via teclado 2 numeros inteiros e
        imprima-os no video com o resultado das 4 operacoes aritmeticas.
*/

void main()
{
    int a, b;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {
        printf("\nInforme um número inteiro para a : ");
        scanf_s("%d", &a);

        printf("\n");

        printf("\nInforme um número inteiro para b : ");
        scanf_s("%d", &b);

        printf("\n\n");

        system("pause");
        system("cls");

        printf("\n %d + %d = %d", a, b, a + b);
        printf("\n %d - %d = %d", a, b, a - b);
        printf("\n %d x %d = %d", a, b, a * b);

        if (b == 0)
        {
            printf("\n Não é possível realizar divisões por ZERO!!!");
        }
        else
        {
            printf("\n %d / %d = %.2f", a, b, (float)a / (float)b);
        }

        printf("\n\n");

        system("pause");
        system("cls");

        if (a + b >= 100 || a * b >= 1000)
        {
            break;
        }
    }
}
#endif // ex1

#ifdef ex2

/*
    2 - Reescreva o exercicio anterior utilizando operadores
        de atribuição composta.
*/

void main()
{
    int a, b, c;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {
        printf("\nInforme um número inteiro para a : ");
        scanf_s("%d", &a);

        printf("\n");

        printf("\nInforme um número inteiro para b : ");
        scanf_s("%d", &b);

        printf("\n\n");

        system("pause");
        system("cls");

        c = a;
        c += b;
        printf("\n %d + %d = %d", a, b, c);

        c = a;
        c -= b;
        printf("\n %d - %d = %d", a, b, c);

        c = a;
        c *= b;
        printf("\n %d x %d = %d", a, b, c);

        if (b == 0)
        {
            printf("\n Não é possível realizar divisões por ZERO!!!");
        }
        else
        {
            c = a;
            (float)c /= (float)b;
            printf("\n %d / %d = %.2f", a, b, (float)c);
        }

        printf("\n\n");

        system("pause");
        system("cls");

        if (a + b >= 100 || a * b >= 1000)
        {
            break;
        }
    }
}
#endif // ex2

#ifdef ex3

/*
    3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
        as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
        video no formato decimal e hexadecimal.
*/

void main()
{
    int a, b;
    char resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {
        printf("Insira 2 números inteiros:\n\n");
        scanf_s("%d %d", &a, &b);

        printf("\n\n Operadores bit-a-bit         DECIMAL   HEXADECIMAL\n\n");
        printf("      AND       a & b   -->     %3d        0x%x\n", a & b, a & b);
        printf("      OU        a | b   -->     %3d        0x%x\n", a | b, a | b);
        printf(" OU EXCLUSIVO   a ^ b   -->     %3d        0x%x\n", a ^ b, a ^ b);

        printf("\n\n");

        system("pause");
        system("cls");

        printf(" Deseja realizar outra operação lógica bit a bit ? S/N\t");
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
    4 - Escreva um programa que receba um numero inteiro via teclado, divida-o
        por 8 e multiplique-o por 8 utilizando os operadores de deslocamento.
        Imprima no video o numero recebido e os resultados obtidos.
*/

void main()
{
    int num, auxnum1, auxnum2;
    char resp;

    setlocale(LC_ALL, "Portuguese");

    for (;;)

    {
        printf("\n Insira um número inteiro: ");
        scanf_s("%d", &num);

        auxnum1 = num >> 3;
        auxnum2 = num << 3;

        printf("\n\n");

        system("pause");
        system("cls");

        printf("\n Número digitado: %d\n\n Número dividido por 8: %d\n\n Número multiplicado por 8: %d\n\n\n", num, auxnum1, auxnum2);

        system("pause");
        system("cls");

        printf("\n Deseja inserir outro número? S/N\t");
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
#endif // ex4

#ifdef ex5

/*
    5 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses
        e dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e
        a data (dia, mes e ano) atual.
*/

void main()
{
    int dia[3], mes[3], ano[3], i, p;
    char resp, info[2][19] = { "data de nascimento","data atual" };

    setlocale(LC_ALL, "Portuguese");

    for (;;)
    {

        for (i = 0; i < 2; i++)
        {
            do
            {
                p = 0;

                printf("\nInsira a %s: \n\n", info[i]);
                printf(" Dia: ");
                scanf_s("%d", &dia[i]);
                printf(" Mês: ");
                scanf_s("%d", &mes[i]);
                printf(" Ano: ");
                scanf_s("%d", &ano[i]);
                
                if ((dia[i] < 1 || dia[i]>31) || (mes[i] < 1 || mes[i]>12) || (ano[i] < 1))
                {
                    p = 1;
                }

                if ((mes[i] == 4 || mes[i] == 6 || mes[i] == 9 || mes[i] == 11) && dia[i] > 30)
                {
                    p = 1;
                }

                if ((mes[i] == 2) && (dia[i] + mes[i]) > 31)
                {
                    p = 1;
                }

                if ((mes[i] == 2) && (dia[i] == 29))
                {
                    if (!((ano[i] % 4 == 0) && (ano[i] % 100 != 0) || (ano[i] % 400 == 0)))
                    {
                        p = 1;
                    }
                }

                if (p)
                {
                    printf("\nA data %d/%d/%d não é válida!\n", dia[i], mes[i], ano[i]);
                }

            } while (p);
        }

        if (ano[1] < ano[0])
        {
            printf("\n Data de nascimento maior que data de comparação!!!\n\n");
        }
        else
        {
            if (mes[0] > mes[1])
            {
                ano[0] += 1;
                mes[1] += 11;
            }

            if (dia[0] > dia[1])
            {
                dia[1] += 30;
            }

            dia[2] = abs(dia[0] - dia[1]);
            mes[2] = abs(mes[0] - mes[1]);
            ano[2] = abs(ano[0] - ano[1]);

            printf("\nA pessoa tem %d anos, %d meses e %d dias\n\n", ano[2], mes[2], dia[2]);
        }

        system("pause");
        system("cls");

        printf("\n Deseja calcular outra idade? S/N\t");
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
#endif // ex5

#ifdef ex6

/*
    6 - Escreva um programa para determinar o dia da semana de uma determinada
        data (dia, mes e ano).
*/

void main()
{
    int dia, mes, ano, p;
    char resp;

    setlocale(LC_ALL, "Portuguese");


    for (;;)
    {
        do
        {
            p = 0;

            printf("\nInsira a data desejada:\n\n");

            printf(" Dia: ");
            scanf_s("%d", &dia);

            printf(" Mês: ");
            scanf_s("%d", &mes);

            printf(" Ano: ");
            scanf_s("%d", &ano);

            if ((dia < 1 || dia>31) || (mes < 1 || mes>12) || (ano < 1))
            {
                p = 1;
            }

            if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
            {
                p = 1;
            }

            if ((mes == 2) && (dia + mes) > 31)
            {
                p = 1;
            }

            if ((mes == 2) && (dia == 29))
            {
                if (!((ano % 4 == 0) && (ano % 100 != 0) || (ano % 400 == 0)))
                {
                    p = 1;
                }
            }

            if (p)
            {
                printf("\nA data %d/%d/%d não é válida!\n", dia, mes, ano);
            }

        } while (p);

        switch (mes)
        {
        case 1: break;
        case 2: dia += 31; break;
        case 3: dia += 59; break;
        case 4: dia += 90; break;
        case 5: dia += 120; break;
        case 6: dia += 151; break;
        case 7: dia += 181; break;
        case 8: dia += 212; break;
        case 9: dia += 243; break;
        case 10: dia += 273; break;
        case 11: dia += 304; break;
        case 12: dia += 334; break;
        }

        if (((ano % 4) == 0) && (((ano % 100) != 0) || ((ano % 400) == 0)) && (mes > 2))
        {
            dia += 1;
        }

        dia += -1 + ((ano - 1) * 365) + ((ano - 1) / 4) - ((ano - 1) / 100) + ((ano - 1) / 400);

        switch (dia % 7)
        {
        case 0: printf("\nSegunda-feira\n\n"); break;
        case 1: printf("\nTerça-feira\n\n"); break;
        case 2: printf("\nQuarta-feira\n\n"); break;
        case 3: printf("\nQuinta-feira\n\n"); break;
        case 4: printf("\nSexta-feira\n\n"); break;
        case 5: printf("\nSábado.\n\n"); break;
        case 6: printf("\nDomingo.\n\n"); break;
        }

        system("pause");
        system("cls");

        printf("\n Deseja inserir outra data? S/N\t");
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