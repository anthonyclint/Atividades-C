//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex3
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
1 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
*/

main()
{
   int a[3],i;
   long int b[3];
   unsigned int c[3];
   float d[3];
   double e[3];
   char resp;

   setlocale(LC_ALL,"Portuguese");

   do
   {
      for(i=0;i<3;i++)
      {
         printf("\nInsira um número inteiro: ");
         scanf("%d",&a[i]);
         printf("\nInsira um número inteiro: ");
         scanf("%ld",&b[i]);
         printf("\nInsira um número inteiro: ");
         scanf("%u",&c[i]);
         printf("\nInsira um número qualquer: ");
         scanf("%f",&d[i]);
         printf("\nInsira um número qualquer: ");
         scanf("%lf",&e[i]);
      }

      system("cls");

      printf("\n        10        20        30        40        50\n");
      printf("12345678901234567890123456789012345678901234567890");

      for(i=0;i<3;i++)
      {
         printf("\n  %-6d              %-11ld         %-5u\n            %-8.1e            %-9.1e",a[i],b[i],c[i],d[i],e[i]);
      }

      printf("\n\n");

      system("pause");

      system("cls");

      printf("\nDeseja imprimir novos valores?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='s'||resp=='S')
      {
         system("cls");
      }

   }while(resp=='s'||resp=='S');

}

#endif // ex1

#ifdef ex2

/*
2 - Receba via teclado dez valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores em ordem.
*/

main()
   {
    int NUM[10], A,i,j;
    char resp;

    setlocale(LC_ALL,"Portuguese");

    do
      {
       for(i=0;i<10;i++)
       {
        printf("\nInforme o %dº número: ",i+1);

        scanf("%d",&NUM[i]);

        for(j=0;j<i;j++)
           {
            if(NUM[i]<=NUM[j])
               {
                A=NUM[i];

                NUM[i]=NUM[j];

                NUM[j]=A;
               }
           }
       }

      printf("\nOs números em ordem crescente são:\n");

      for(i=0;i<10;i++)
         {printf("%d, ",NUM[i]);}

      printf("\n\n");

      system("pause");

      system("cls");

      printf("\nDeseja ordenar novos valores?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='s'||resp=='S')
         {
          system("cls");
         }

      }while(resp=='s'||resp=='S');
   }
#endif // ex2

#ifdef ex3

/*
3 - Um vetor é palíndromo se ele não se altera quando as posições dos componentes
    são invertidos. Por exemplo, o vetor v = {1, 3, 5, 2, 2, 5, 3, 1} é palíndromo.
    Escreva um programa que verifique se um vetor é palíndromo. Receba o vetor
    via teclado (tamanho 10)
*/

main()
   {
    int NUM[10],i,j,palindromo=1;
    char resp;

    setlocale(LC_ALL,"Portuguese");

    do
      {
       for(i=0;i<10;i++)
         {
          printf("\nInforme o %dº número: ",i+1);
          scanf("%d",&NUM[i]);
         }

       i=0;
       j=9;
       while(i<j && palindromo==1)
          {
           if(NUM[i]!=NUM[j])
              {
               palindromo=0;
              }
           else
              {
               i+=1;
               j-=1;
              }
          }

       if(palindromo==1)
          {
           printf("\nOs elementos do vetor formam um palíndromo.\n");
          }

       else
          {
           printf("\nOs elementos do vetor não formam um palíndromo.\n");
          }

        printf("\n");

        system("pause");

        system("cls");

        printf("\nDeseja realizar outra subtração?   S/N\t");
        getchar();
        resp=getchar();

        if(resp=='s'||resp=='S')
           {
            system("cls");
           }

      }while(resp=='s'||resp=='S');

   }

#endif // ex3

#ifdef ex4

/*
4 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um
    programa que recebe os dados via teclado para esses 2 vetores. Usando
    o operador subtracao "-", subtraia os elementos de mesmo indice dos 2
    vetores e guarde o resultado num 3° vetor. Imprima na tela o indice,
    os valores e o resultado dos 6 elementos dos vetores.
*/

main()
   {
    int VET1[2][3],VET2[2][3],VET3[2][3],i,j,k,a;
    char resp;

    setlocale(LC_ALL,"Portuguese");

    do
      {
       for(k=0;k<2;k++)
          {
           a=1;
           system("cls");
           for(i=0;i<2;i++)
              {
               for(j=0;j<3;j++)
                  {
                   printf("\nInforme o %dº elemento do vetor %d: ",a,k+1);
                   if(k==0)
                      {
                       scanf("%d",&VET1[i][j]);
                      }
                   else
                      {
                       scanf("%d",&VET2[i][j]);
                      }
                   a+=1;
                  }
              }
          }

       system("cls");

       printf("\nApós a subtração entre as matrizes (1) e (2)\nsurge uma matriz (3), cujos elementos são:\n\n\tMatriz (3)\n\n");

       for(i=0;i<2;i++)
          {
           for(j=0;j<3;j++)
              {
               VET3[i][j]=VET1[i][j]-VET2[i][j];
               printf("\t[%d] [%d]= %d \n",i,j,VET3[i][j]);
              }
          }

       printf("\n");

       system("pause");

       system("cls");

       printf("\nDeseja realizar outra subtração?   S/N\t");
       getchar();
       resp=getchar();

       if(resp=='s'||resp=='S')
       {
        system("cls");
       }

      }while(resp=='s'||resp=='S');
   }

#endif // ex4

#ifdef ex5

/*
5 - Receba via teclado valores para uma matriz 5 x 5. Receba via teclado um valor X.
    O programa dever fazer a busca desse valor x na matriz e, ao final escrever a
    localizacao (linha e coluna) ou uma mensagem de "nao encontrado".
*/

main()
{
   int matriz[5][5],i,j,x=1,cont=0;
   char resp;

   setlocale(LC_ALL,"Portuguese");

   do
      {
         for(i=0;i<5;i++)
         {
            for(j=0;j<5;j++)
            {
               printf("\nInsira o %dº elemento da matriz: ",x);
               scanf("%d",&matriz[i][j]);
               x+=1;
            }
         }

         system("timeout 5");

         system("cls");

         printf("Insira o valor que deseja procurar na matriz: ");
         scanf("%d",&x);

         for(i=0;i<5;i++)
         {
            for(j=0;j<5;j++)
            {
               if(matriz[i][j]==x)
               {
                  printf("\nA posição do valor %d na matriz é: [%d] [%d]\n",x,i,j);
                  cont+=1;
               }
            }
         }

         if(cont==0)
         {
            printf("\nNão foi possível encontrar o valor %d na matriz.\n",x);
         }

         printf("\n");

         system("pause");

         system("cls");

         printf("\nDeseja realizar outra busca?   S/N\t");
         getchar();
         resp=getchar();

         if(resp=='s'||resp=='S')
         {
            system("cls");
         }

      }while(resp=='s'||resp=='S');
}

#endif // ex5
