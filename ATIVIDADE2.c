//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex1
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#ifdef ex1

/*
1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize
    o comando if-else.
*/

main()
   {
    int Maior=98,Menor=1,Guess;
    char ch;

    setlocale(LC_ALL,"Portuguese");

    printf("\nPense num número entre 1 e 99.\n\n");

    system("pause");

    while(1)
       {
        Guess=((Maior-Menor)/2)+Menor;

        printf("\n%d\n",Guess);

        printf("\nEsse número é maior, menor ou igual ao que você pensou?\nDigite >, < ou = ");

        ch=getchar();
        getchar();

        if(ch=='<')
           {
            Menor=Guess+1;
           }
        else if(ch=='>')
           {
            Maior=Guess-1;
           }
        else if(ch=='=')
           {
            printf("\nEsse é o seu número: %d !!!\n",Guess);

            break;
           }
        }
   }

#endif //ex1

#ifdef ex2

/*
2 - Resecreva o programa do exercicio anterior agora utilizando o comando
    switch. Conte o n. de tentativas e imprima o resultado no video.
*/

main()
   {
    int Num,Maior=98,Menor=1,Guess;
    char ch;

    setlocale(LC_ALL,"Portuguese");

    printf("\nPense num número entre 1 e 99.\n\n");

    system("pause");

    while(1)
       {
        Guess=((Maior-Menor)/2)+Menor;

        printf("\n%d\n",Guess);

        printf("\nEsse número é maior, menor ou igual ao que você pensou?\nDigite >, < ou = : ");

        ch=getchar();
        getchar();

        switch(ch)
           {
            case '<':
            Menor=Guess+1;
            break;

            case '>':
            Maior=Guess-1;
            break;

            case '=':
            Guess=Num;
            printf("\nEsse é o seu número: %d !!!\n\n");
            break;

            default:
            printf("\nResposta inválida!\n\n");
           }

        if(Guess==Num)
        {
         break;
        }

       }

   }

#endif // ex2

#ifdef ex3

/*
3 - De um modo geral, as ligações telefônicas são cobradas pelas suas durações. O sistema
    registra os instantes em que a ligação foi iniciada e concluída. Escreva um programa
    que recebe via teclado dois instantes dados em horas, minutos e segundo e determina o
    intervalo de tempo (em horas, minutos e segundos) decorrido entre eles.
*/

main()
{
   int seg, hora, hora2, min, tempo;
   char resp;

   setlocale(LC_ALL,"Portuguese");

   for(;;)
   {
      system("cls");
      printf("Insira o horário inicial da ligação:\n");
      do
      {
         scanf("%d",&hora, printf("\nhoras: "));
         if(hora<0 || hora>23)
         {
            printf("\nValor inválido!\n");
         }
      }while(hora<0 || hora>23);
      do
      {
         scanf("%d",&min, printf("\nminutos: "));
         if(min<0 || min>=60)
            {
               printf("\nValor inválido!\n");
            }
      }while(min<0 || min>=60);
      do
      {
         scanf("%d",&seg, printf("\nsegundos: "));
      if(seg<0 || seg>=60)
            {
               printf("\nValor inválido!\n");
            }
      }while(seg<0 || seg>=60);

      tempo=hora*3600+min*60+seg;

      printf("\nInsira o horário final da ligação:\n");
      do
      {
         scanf("%d",&hora2, printf("\nhoras: "));
         if(hora2<0 || hora2>23)
         {
            printf("\nValor inválido!\n");
         }
      }while(hora2<0 || hora2>23);
      do
      {
         scanf("%d",&min, printf("\nminutos: "));
         if(min<0 || min>=60)
            {
               printf("\nValor inválido!\n");
            }
      }while(min<0 || min>=60);
      do
      {
         scanf("%d",&seg, printf("\nsegundos: "));
      if(seg<0 || seg>=60)
            {
               printf("\nValor inválido!\n");
            }
      }while(seg<0 || seg>=60);

      if(hora2<hora)
      {
         tempo=hora2*3600+min*60+seg+24*3600-tempo;
      }
      else
      {
         tempo=hora2*3600+min*60+seg-tempo;
      }

      hora=tempo/3600;

      min=(tempo-(3600*hora))/60;

      seg=(tempo-(3600*hora)-(min*60));

      printf("\nO tempo total da ligação foi:\t%dh : %dm : %ds \n\n",hora,min,seg);

      system("pause");

      system("cls");

      printf("\nDeseja consultar outra ligação?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='n' || resp=='N')
         break;
   }
}

#endif // ex3

#ifdef ex4

/*
4 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.
*/

main()
   {
    int num,soma=0,cont=0;
    float media;

    setlocale(LC_ALL,"Portuguese");

    for(;;)
       {
        printf("\nInforme um número: ");
        scanf("%d",&num);

        if(num>0)
           {
            soma=soma+num;

            cont=cont+1;
           }

        else
           {
            media=(float)soma/(float)cont;
            break;
           }
       }

    printf("\nA média dos números positivos é igual a %.2f.\n",media);
   }

#endif // ex4

#ifdef ex5

/*
5 - Escreva um programa que realize arredondamentos de números
    utilizando a seguinte regra:
    - se a parte fracionaria for menor ou igual a 0,24 o número
      é arredondado para 0;
    - se a parte fracionaria for maior ou igual a 0,25 e menor
      ou igual a 0,74 o número é arredondado para 0,5;
    - se a parte fracionaria for maior ou igual a 0,75 o número
      é arredondado para o inteiro imediatamente superior.
*/

main()
{
   float num;
   int aux;
   char resp;

   setlocale(LC_ALL,"Portuguese");

   for(;;)
   {
      system("cls");

      printf("Insira o número que deseja arredondar: ");
      scanf("%f",&num);

      aux=num*100;

      if(abs(aux%100)<25)
      {
         printf("\nO número arredondado é: %.f\n\n",num);
      }
      else
      {
         if(abs(aux%100)>=25 && abs(aux%100)<75)
         {
            if(num<0)
            {
               num=(aux-aux%100)/100;
               num=num-0.5;
               printf("\nO número arredondado é: %.2f\n\n",num);
            }
            else
            {
               num=(aux-aux%100)/100;
               num=num+0.5;
               printf("\nO número arredondado é: %.2f\n\n",num);
            }
         }
         else
         {
            if(abs(aux%100)>=75)
            {
               if(num<0)
               {
                  num=(aux-aux%100)/100;
                  num=num-1;
                  printf("\nO número arredondado é: %.2f\n\n",num);
               }
               else
               {
                  num=(aux-aux%100)/100;
                  num=num+1;
                  printf("\nO número arredondado é: %.2f\n\n",num);
               }
            }
         }
      }

      system("pause");

      system("cls");

      printf("\nDeseja fazer outro arredondamento?   S/N\t");
      getchar();
      resp=getchar();

      if(resp=='n' || resp=='N')
      {
         break;
      }
   }
}

#endif // ex5
