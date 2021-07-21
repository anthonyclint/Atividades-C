//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex4
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
1 - Escreva um programa que receba dados via teclado para variaveis
    do tipo short, long, int, float, double e um char e imprima-os
    no video no seguinte formato:

         10        20        30        40        50        60
12345678901234567890123456789012345678901234567890123456789012345
    short               long                int
              float               double              char
*/

main()
{
   short int a;
   long int b;
   int c;
   float d;
   double e;
   char f;

   setlocale(LC_ALL,"Portuguese");

   printf("Insira um número inteiro: ");
   scanf("%hd",&a);
   printf("\nInsira um número inteiro: ");
   scanf("%ld",&b);
   printf("\nInsira um número inteiro: ");
   scanf("%d",&c);
   printf("\nInsira um número qualquer: ");
   scanf("%f",&d);
   printf("\nInsira um número qualquer: ");
   scanf("%lf",&e);
   printf("\nInsira um caractere qualquer: ");
   getchar();
   f=getchar();

   system("cls");

   printf("\n         10        20        30        40        50        60\n");
   printf("12345678901234567890123456789012345678901234567890123456789012345");
   printf("\n    %-6hd              %-11ld         %-6d\n              %-8.1e            %-9.1e           %c\n",a,b,c,d,e,f);

}

#endif // ex1

#ifdef ex2

/*
2 - Escreva um programa que receba via teclado um tempo em segundos
    e converta um para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.
*/

main()
{
   int seg, hora, min, time;
   char resp;

   setlocale(LC_ALL,"Portuguese");

   do
   {
      do
      {
         system("color 07");

         printf("\nInforme um tempo em segundos: ");
         scanf("%d",&time);

         if(time<=0)
         {
            system("color 4F");

            printf("\nO valor não pode ser nulo ou negativo!\n\n");

            system("pause");

            system("cls");
         }

      }while(time<=0);

      system("color 07");

      printf("\n");

      hora=time/3600;

      min=(time-(3600*hora))/60;

      seg=(time-(3600*hora)-(min*60));

      printf("%dh : %dm : %ds \n",hora,min,seg);

      printf("\n");

      system("pause");

      system("cls");

      printf("\nDeseja permutar outros valores?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='s' || resp=='S')
         system("cls");

   }while (resp=='s' || resp=='S');

}

#endif // ex2

#ifdef ex3

/*
3 - Escreva um programa para ler um numero inteiro, positivo de tres digitos,
    e gere outro número formado pelos dígitos invertidos do número lido.
    Ex:   NúmeroLido = 123
          NúmeroGerado = 321
*/

main()
{
   int Num,cent,dez,uni;
   char resp;

   setlocale(LC_ALL,"Portuguese");

   do
   {
      do
      {
         system("color 07");

         printf("\nInforme um número positivo de 3 dígitos: ");
         scanf("%d",&Num);

         if(Num>999 || Num<100)
         {
            system("color 4F");

            printf("\nO número deve ser POSITIVO e ter 3 dígitos!\n\n");

            system("pause");

            system("cls");
         }

      }while(Num>999 || Num<100);

      system("color 07");

      cent=Num/100; //123/100 = 1,23 ~=1

      Num=Num%100; //123%100 = 23

      dez=Num/10;//23/10 = 2,3 ~= 2

      uni=Num%10;// 23%10 = 3

      printf("\nO número invertido é %d%d%d\n",uni,dez,cent);

      printf("\n");

      system("pause");

      system("cls");

      printf("\nDeseja permutar outros valores?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='s' || resp=='S')
         system("cls");

   }while (resp=='s' || resp=='S');

}

#endif // ex3

#ifdef ex4

/*
4 - Escreva um programa que permute o conteúdo de duas variáveis
    sem utilizar uma variável auxiliar.
*/

main()
{
   int a,b;
   char resp;

   setlocale(LC_ALL,"Portuguese");

   do
   {
      printf("Insira um valor para a: ");
      scanf("%d",&a);
      printf("\nInsira um valor para b: ");
      scanf("%d",&b);

      system("cls");

      printf("\nValores digitados:\n\n\ta = %d\n\tb = %d",a,b);
      b=a-b;
      a=a-b;
      b=a+b;
      printf("\n\nValores permutados:\n\n\ta = %d\n\tb = %d\n",a,b);

      printf("\n");

      system("pause");

      system("cls");

      printf("\nDeseja permutar outros valores?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='s' || resp=='S')
         system("cls");

   }while (resp=='s' || resp=='S');

}

#endif // ex4

#ifdef ex5

/*
5 - Escreva um programa que lê um valor em reais e calcula qual o
    menor número possível de notas de $100, $50, $10, $5, $2 e $1
    em que o valor lido pode ser decomposto. Escrever o valor lido
    e a relação de notas necessárias.
*/

main()
{
   int valor,v100,v50,v20,v10,v5,v2,v1;
   char resp;

   setlocale(LC_ALL,"Portuguese");

   do
   {
      do
      {
         system("color 07");

         printf("\nInforme um valor em reais: R$");
         scanf("%d",&valor);

         if(valor<=0)
         {
            system("color 4F");

            printf("\nInforme um valor válido!\n\n");

            system("pause");

            system("cls");
         }

      }while(valor<=0);

      system("color 07");

      v100=valor/100;
      valor=valor-(v100*100);

      v50=valor/50;
      valor=valor-(v50*50);

      v20=valor/20;
      valor=valor-(v20*20);

      v10=valor/10;
      valor=valor-(v10*10);

      v5=valor/5;
      valor=valor-(v5*5);

      v2=valor/2;
      valor=valor-(v2*2);

      v1=valor;

      if(v100!=0)
         printf("\n%6d nota(s) de R$100\n",v100);
      if(v50!=0)
         printf("\n%6d nota(s) de R$50\n",v50);
      if(v20!=0)
         printf("\n%6d nota(s) de R$20\n",v20);
      if(v10!=0)
         printf("\n%6d nota(s) de R$10\n",v10);
      if(v5!=0)
         printf("\n%6d nota(s) de R$5\n",v5);
      if(v2!=0)
         printf("\n%6d nota(s) de R$2\n",v2);
      if(v1!=0)
         printf("\n%6d nota(s) de R$1\n",v1);

      printf("\n");

      system("pause");

      system("cls");

      printf("\nDeseja verificar outro valor?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='s' || resp=='S')
         system("cls");

   }while (resp=='s' || resp=='S');

}

#endif // ex5
