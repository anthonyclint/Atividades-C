//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex5b
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
1 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3
*/

main()
{
   char nome1[8],nome2[8],nome3[8],nome4[8],nome5[8],resp;

   setlocale(LC_ALL,"Portuguese");

   do
   {
      printf("\nInsira o 1º nome: ");
      gets(nome1);
      printf("\nInsira o 2º nome: ");
      gets(nome2);
      printf("\nInsira o 3º nome: ");
      gets(nome3);
      printf("\nInsira o 4º nome: ");
      gets(nome4);
      printf("\nInsira o 5º nome: ");
      gets(nome5);

      system("cls");

      printf("\n        10        20        30        40        50\n");
      printf("12345678901234567890123456789012345678901234567890");
      printf("\n  %-7s                                 %-7s\n            %-7s             %-7s\n                      %-7s",nome1,nome5,nome2,nome4,nome3);

      printf("\n\n");

      system("pause");

      system("cls");

      printf("\nDeseja imprimir novos valores?   S/N\t");
      resp=getchar();
      getchar();


      if(resp=='s'||resp=='S')
      {
         system("cls");
      }

   }while(resp=='s'||resp=='S');

}

#endif // ex1

#ifdef ex2

/*
2 - Escreva um programa para receber 3 strings de ate 10 caracteres cada via
    teclado e imprima-as no video no seguinte formato:
    (utilize vetores multidimensionais)

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        string1             string2             string3
*/

main()
{
   int i;
   char vetor[3][11],resp;

   setlocale(LC_ALL,"Portuguese");

   do
   {
      for(i=0;i<3;i++)
      {
         printf("Insira a %dº palavra: ",i+1);
         gets(vetor[i]);
      }
      printf("\n        10        20        30        40        50        60\n");
      printf("123456789012345678901234567890123456789012345678901234567890");
      printf("\n    %-10s          %-10s          %-10s",vetor[0],vetor[1],vetor[2]);

      printf("\n\n");

     system("pause");

     system("cls");

     printf("\nDeseja informar uma nova série de caracteres?   (S/N)\t");
     resp=getchar();
     getchar();

     if(resp=='s'||resp=='S')
     {
        system("cls");
     }

   }while(resp=='s'||resp=='S');
}

#endif // ex2

#ifdef ex3
/*
  3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas.
*/

main()
{
 int i;
 char resp, carc[11];

 setlocale(LC_ALL,"Portuguese");

 do
    {
     for(i=0;i<10;i++)
        {
         printf("\nInforme o %dº caracter: ",i+1);
         scanf("%s",&carc[i]);
        }

     printf("\n\n");

     system("pause");

     system("cls");

     printf("\n   A string informada é:\n\n");

     for(i=0;i<10;i++)
        {
         if(carc[i]>='a' && carc[i]<='z')
            {
             carc[i]=(carc[i]-'a')+'A';
            }
        }

     printf("\t%s",carc);

     printf("\n\n");

     system("pause");

     system("cls");

     printf("\nDeseja informar uma nova série de caracteres?   (S/N)\t");
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
  4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas.
*/

main()
{
 int i;
 char resp, carc[11];

 setlocale(LC_ALL,"Portuguese");

 do
    {
     for(i=0;i<10;i++)
        {
         printf("\nInforme o %dº caracter: ",i+1);
         scanf("%s",&carc[i]);
        }

     printf("\n\n");

     system("pause");

     system("cls");

     printf("\n   A string informada é:\n\n");
     for(i=0;i<10;i++)
        {
         if(carc[i]>=65 && carc[i]<=90)
            {
             carc[i]+=32;
            }
        }

     printf("\t%s",carc);

     printf("\n\n");

     system("pause");

     system("cls");

     printf("\nDeseja informar uma nova série de caracteres?   (S/N)\t");
     getchar();
     resp=getchar();

     if(resp=='s'||resp=='S')
     {
        system("cls");
     }

    }while(resp=='s'||resp=='S');
}

#endif //ex4

#ifdef ex5

/*
  5 - Receba 2 string de ate 10 caracteres via teclado, compare-as mostrando como
    resultado se são IGUAIS ou DIFERENTES.
*/

main()
{
 char s1[11],s2[11],resp;
 int i,a=1;

 setlocale(LC_ALL,"Portuguese");

 do
    {
     for(i=0;i<10;i++)
        {
         printf("\nInforme a %dª letra da string s1: ",i+1);
         scanf("%s",&s1[i]);
        }


     system("cls");

     for(i=0;i<10;i++)
        {
         printf("\nInforme a %dª letra da string s2: ",i+1);
         scanf("%s",&s2[i]);
        }

     i=0;
     while(i<10 && a==1)
        {
         if(s1[i]!=s2[i])
            {
             a=0;
            }
         else
            {
             i+=1;
            }
        }

     if(a==1)
        {
         printf("\nAs strings s1 e s2 são IGUAIS!\n\n");
        }
     else
        {
         printf("\nAs strings s1 e s2 são DIFERENTES!\n\n");
        }

     system("pause");
     system("cls");

     printf("\nDeseja informar novas strings? (S/N)\n");
     getchar();
     resp=getchar();

    }while(resp=='s'||resp=='S');
}

#endif // ex5

#ifdef ex5b

/*
    RESOLUÇÂO DO EXE 5 RECEBENDO AS STRINGS POR INTEIRO

  5 - Receba 2 string de ate 10 caracteres via teclado, compare-as mostrando como
    resultado se são IGUAIS ou DIFERENTES.
*/

main()
{
   char s1[11],s2[11],resp;
   int i,a=1;

   setlocale(LC_ALL,"Portuguese");

   for(;;)
   {
      printf("\nInforme a string s1: ");
      gets(s1);

      printf("\nInforme a string s2: ");
      gets(s2);

      i=0;
      while(s1[i]==s2[i] && s1[i]!= '\0' && s2[i]!= '\0')
      {
         i++;
      }

      if(s1[i] == '\0' && s2[i] == '\0')
      {
         printf("\nAs strings s1 e s2 são IGUAIS!\n\n");
      }
      else
      {
         printf("\nAs strings s1 e s2 são DIFERENTES!\n\n");
      }

      system("pause");
      system("cls");

      printf("\nDeseja informar novas strings? (S/N)\n");
      getchar();
      resp=getchar();

      system("cls");

      if(resp=='n' || resp=='N')
      {
       break;
      }
   }
}
#endif // ex5b
