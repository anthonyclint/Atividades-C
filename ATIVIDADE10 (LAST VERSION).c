//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define ex1
#include<stdio.h>
#include<stdlib.h>

#ifdef ex1

/*
   1 - Faça um programa para:

       1 - criar/abrir um arquivo texto de nome ”arq.txt”,
       2 - receba via teclado diversos caracteres (um por vez) e armazene-os
           nesse arquivo. O caracter '0' finaliza a entrada de dados.
       3 - abra o arquivo. Leia e imprima na tela todos os caracteres armazenados.
*/

void main()
{
   FILE *KP;
   int i = 0, k;
   char c;

   setlocale(LC_ALL,"Portuguese");

   KP = fopen("arq.txt","w");

   printf("\n\t\tENTRADA DE DADOS\n");

   do
   {
      printf("\n\tInsira um caractere: ");
      scanf("%c",&c);
      getchar();

      if(c != '0')
      {
         putc(c,KP);
         i++;
      }
   }while(c != '0');

   fclose(KP);

   printf("\n\n\t");
   system("pause");
   system("cls");

   KP = fopen("arq.txt","r");

   if(KP == NULL)
   {
      printf("\nERRO AO ABRIR O ARQUIVO!!!\n\n");
      exit(404);
   }

   printf("\n\t\tLISTA DE CARACTERES\n");

   for(k=0;k<i;k++)
   {
      printf("\n\n\t%c",getc(KP));
   }

   fclose(KP);

   printf("\n\n\n\n\n\n\n");
}

#endif // ex1

#ifdef ex2

/*
   2 - Faça um programa para gerenciar uma agenda de contatos. Para cada contato
       armazene o nome, o telefone e o aniversário (dia e mês) em uma estrutura
       de dados.
       O programa deve ter as opções:
       1 - inserir contato
       2 - altera contato
       3 - exclui contato
       4 - pesquisar um contato pelo nome
       5 - listar todos os contatos
       6 - listar os contatos cujo nome inicia com uma letra digitada
       7 - imprimir os aniversariantes do mês.
       Sempre que o programa for encerrado, os contatos devem ser escritos no arquivo.
       Quando o programa iniciar os contatos devem ser lidos do arquivo.
       O vetor de estrutura será de 4 elementos como variavel local na funcao main().
       Utilize ponteiros
*/

struct DADOS
{
   unsigned char nome[25];
   char tel[10];
   char aniv[6];
};

FILE *KP;

int ADD(struct DADOS *p, int aux, int ux);

void ALT(struct DADOS *p, int aux);

int EXC(struct DADOS *p, int aux, int ux);

int PESQ(struct DADOS *p, int aux);

void LIST(struct DADOS *p, int aux);

void INI(struct DADOS *p, int aux);

void ANIV(struct DADOS *p, int aux);

void SAIR(struct DADOS *p);

void ERRO(int x);

void LIMPAR(struct DADOS *p);

void main()
{
   int op, aux=0, ux=0;

   struct DADOS contato[4];

   struct DADOS *p;

   p=&contato[0];

   KP=fopen("contatos.txt","r+");

   if(KP!=NULL)
   {
      int k;

      for(;;)
      {
         k=fread(p,sizeof(*p),1,KP);

         if(k==1)
         {
            if(p->nome[0]=='\0')
            {
               ux++;
            }
         }
         else
         {
            break;
         }
      }

      fseek(KP,0,0);

      fread((p+0),sizeof(*p),1,KP);
      fread((p+1),sizeof(*p),1,KP);
      fread((p+2),sizeof(*p),1,KP);
      fread((p+3),sizeof(*p),1,KP);

      fclose(KP);

      aux=4;
   }

   for(;;)
   {
      system("color 1F");

      printf("\n\n\t\t\t>>>>>> AGENDA <<<<<<\n");

      printf("\n\n\t\t1 - ADICIONAR CONTATO");
      printf("\n\n\t\t2 - ALTERAR CONTATO");
      printf("\n\n\t\t3 - EXCLUIR CONTATO");
      printf("\n\n\t\t4 - PESQUISAR CONTATO");
      printf("\n\n\t\t5 - LISTAR CONTATOS");
      printf("\n\n\t\t6 - LISTAR CONTATO PELA INICIAL");
      printf("\n\n\t\t7 - LISTAR ANIVERSARIANTES DO MES");
      printf("\n\n\t\t8 - SAIR");

      printf("\n\n\n\t\tINFORME A OPCAO: ");
      scanf("%d",&op);
      getchar();

      switch(op)
      {
         case 1:
            aux=ADD(p,aux,ux);

            if(aux==-1)
            {
               aux=4;
               ux=0;
            }
            break;

         case 2:
            ALT(p,aux);
            break;

         case 3:
            ux=EXC(p,aux, ux);
            break;

         case 4:
            PESQ(p,aux);
            break;

         case 5:
            LIST(p,aux);
            break;

         case 6:
            INI(p,aux);
            break;

         case 7:
            ANIV(p,aux);
            break;

         case 8:
            SAIR(p);
            break;

         default:
            ERRO(1); // ESCOLHA INVALIDA
      }

      system("pause");
      system("cls");
   }
}

int ADD(struct DADOS *p, int aux, int ux)
{
   int u;

   KP=fopen("contatos.txt","w+");

   if(ux==0 && aux<4)
   {
      LIMPAR(p);

      for(aux;aux<4;aux++)
      {
         system("cls");
         printf("\n\n\t\t\t>>>>>> CADASTRO DE CONTATO <<<<<<\n\n");
         printf("\n\t\tCONTATO %d\n\n",(aux+1));

         if((p+aux)->nome[0]=='\0')
         {
            printf("\n\t\tINSIRA O NOME DO CONTATO: ");
            gets((p+aux)->nome);
            printf("\n\t\tINSIRA O TELEFONE: ");
            gets((p+aux)->tel);
            printf("\n\t\tINSIRA O ANIVERSARIO (DD/MM): ");
            gets((p+aux)->aniv);
         }
      }

      printf("\n\n\t\t");

      return aux;
   }
   else if(ux==0 && aux>3)
   {
      ERRO(4); // LISTA CHEIA
   }
   else
   {
      for(u=0;u<ux;u++)
      {
         for(aux=0;aux<4;aux++)
         {
            if((p+aux)->nome[0]=='\0')
            {
               system("cls");
               printf("\n\n\t\t\t>>>>>> CADASTRO DE CONTATO <<<<<<\n\n");
               printf("\n\t\tCONTATO %d\n\n",(aux+1));

               printf("\n\t\tINSIRA O NOME DO CONTATO: ");
               gets((p+aux)->nome);
               printf("\n\t\tINSIRA O TELEFONE: ");
               gets((p+aux)->tel);
               printf("\n\t\tINSIRA O ANIVERSARIO (DD/MM): ");
               gets((p+aux)->aniv);
            }
         }

         printf("\n\n\t\t");

         return -1;
      }

      printf("\n\n\t\t");

   }
}

void ALT(struct DADOS *p, int aux)
{
   int pox;

   if((KP=fopen("contatos.txt","r"))==NULL)
      {
         ERRO(2); // LISTA VAZIA
      }
      else
      {
         pox=PESQ(p,aux);

         system("pause");

         if(pox==-1)
         {
            ERRO(5); // PROCESSO CANCELADO
         }
         else
         {
            system("cls");

            printf("\n\n\t\t\t>>>>>> ALTERA CONTATO <<<<<<\n\n");
            printf("\n\t\tCONTATO %d\n\n",(pox+1));

            printf("\n\t\tINSIRA O NOME DO CONTATO: ");
            gets((p+pox)->nome);
            printf("\n\t\tINSIRA O TELEFONE: ");
            gets((p+pox)->tel);
            printf("\n\t\tINSIRA O ANIVERSARIO (DD/MM): ");
            gets((p+pox)->aniv);
            printf("\n\n\t\t");
         }

      }
}

int EXC(struct DADOS *p, int aux, int ux)
{
   int pox;

   if((KP=fopen("contatos.txt","r"))==NULL)
      {
         ERRO(2); // LISTA VAZIA
      }
      else
      {
         pox=PESQ(p,aux);

         system("pause");

         if(pox==-1)
         {
            ERRO(5); // PROCESSO CANCELADO
         }
         else
         {
            (p+pox)->nome[0]='\0';
            (p+pox)->tel[0]='\0';
            (p+pox)->aniv[0]='\0';

            ux++;

            printf("\n\n\n\t\t\t>>>>>> CONTATO EXCLUIDO <<<<<<\n\n\n\t\t");
         }

         return ux;
      }

      printf("\n\t\t");
}

int PESQ(struct DADOS *p, int aux)
{
   int j;

   char pesq[25]="\0";

   if((KP=fopen("contatos.txt","r"))==NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>>>>> PESQUISA CONTATO <<<<<<\n\n");

      printf("\n\t\tINFORME O NOME DO CONTATO: ");
      gets(pesq);

      for(int w=0;w<(aux);w++)
      {
         for(j=0;pesq[j]!='\0';j++)
         {
            if(pesq[j]!=((p+w)->nome[j]))
            {
               break;
            }
         }

         if(pesq[j]=='\0' && ((p+w)->nome[j])=='\0')
         {
            printf("\n\t\tNOME: %s",(p+w)->nome);
            printf("\n\t\tTELEFONE: %s",(p+w)->tel);
            printf("\n\t\tANIVERSARIO: %s\n\n\t\t",(p+w)->aniv);

            return (w);
         }

      }

      ERRO(3); // CONTATO NAO ENCONTRADO

      return -1;
   }
}

void LIST(struct DADOS *p, int aux)
{
   int w;

   if((KP=fopen("contatos.txt","r"))==NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>>>>> LISTA CONTATOS <<<<<<\n\n");

      for(w=0;w<aux;w++)
      {
         if((p+w)->nome[0]!='\0')
         {
            printf("\n\t\tNOME: %s",(p+w)->nome);
            printf("\n\t\tTELEFONE: %s",(p+w)->tel);
            printf("\n\t\tANIVERSARIO: %s\n\n",(p+w)->aniv);
         }
      }

      printf("\n\t\t");
   }
}

void INI(struct DADOS *p, int aux)
{
   int w, cont=0;

   char ini;

   if((KP=fopen("contatos.txt","r"))==NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>>>>> PESQUISA POR INICIAL <<<<<<\n\n");

      printf("\n\t\tINFORME A INICIAL: ");
      ini=getchar();

      for(w=0;w<aux;w++)
      {
         if((p+w)->nome[0]==ini)
         {
            printf("\n\t\tNOME: %s",(p+w)->nome);
            printf("\n\t\tTELEFONE: %s",(p+w)->tel);
            printf("\n\t\tANIVERSARIO: %s",(p+w)->aniv);
            printf("\n\n");

            cont++;
         }
      }

      printf("\n\n\t\t");

      if(cont==0)
      {
         ERRO(3); // CONTATO NAO ENCONTRADO
      }
   }
}

void ANIV(struct DADOS *p, int aux)
{
   int w, cont=0;

   char data[3];

   if((KP=fopen("contatos.txt","r"))==NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>>>>> ANIVERSARIANTE DO MES <<<<<<\n\n");

      printf("\n\t\tINFORME O ANIVERSARIO (MM): ");
      gets(data);

      for(w=0;w<aux;w++)
      {
         if((p+w)->aniv[3]==data[0] && (p+w)->aniv[4]==data[1])
         {
            printf("\n\t\tNOME: %s",(p+w)->nome);
            printf("\n\t\tTELEFONE: %s",(p+w)->tel);
            printf("\n\t\tANIVERSARIO: %s",(p+w)->aniv);
            printf("\n\n\t\t");

            cont++;
         }
      }

      if(cont==0)
      {
         ERRO(3); // CONTATO NAO ENCONTRADO
      }
   }
}

void SAIR(struct DADOS *p)
{
   system("cls");
   system("color 70");

   KP=fopen("contatos.txt","r+");

   fwrite((p+0),sizeof(*p),1,KP);
   fwrite((p+1),sizeof(*p),1,KP);
   fwrite((p+2),sizeof(*p),1,KP);
   fwrite((p+3),sizeof(*p),1,KP);

   fclose(KP);

   printf("\n\n\n\n\n\n\n\n\n\n");
   printf("\n\t\t\t>>>>>> PROGRAMA FINALIZADO <<<<<<\n\n\n");
   printf("\n\n\n\n\n\n\n\n\n\n");

   exit(0);
}

void ERRO(int x)
{
   system("cls");
   system("color 4F");

   if(x==1)
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      ESCOLHA INVALIDA      \n\n\n\n\t\t");
   }
   else if(x==2)
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      LISTA VAZIA      \n\n\n\n\t\t");
   }
   else if(x==3)
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      CONTATO NAO ENCONTRADO      \n\n\n\n\t\t");
   }
   else if(x==4)
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      LISTA CHEIA      \n\n\n\n\t\t");
   }
   else
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      PROCESSO CANCELADO      \n\n\n\n\t\t");
   }
}

void LIMPAR(struct DADOS *p)
{
   int j;

   for(j=0;j<4;j++)
   {
         (p+j)->nome[0]='\0'; // LIMPA O NOME

         (p+j)->tel[0]='\0'; // LIMPA O TELEFONE

         (p+j)->aniv[0]='\0'; // LIMPA O ANIVERSÁRIO
   }
}

#endif // ex2

#ifdef ex3

/*
   3 - Faça um programa para o controle de mercadorias em uma despensa doméstica.
       Cada produto será armazenado um código numérico, descrição e quantidade atual
       numa estrutura de dados. Utilize ponteiros. A estrutura deve ser declarada
       como variavel local na funcao main().
       O programa deve ter as opções:
       1 - inclui produtos
       2 - altera produtos
       3 - exclui produtos
       4 - pesquisar uma mercadoria pela descrição
       5 - listar todos os produtos
       6 - listar os produtos não disponíveis.
       7 - alterar a quantidade atual
       Escreva os itens das mercadorias direto no arquivo. (utilize a funcao fseek).
*/

struct dados
{
   char cod[5];
   unsigned char desc[30];
   int qnt;
};

void INCLUIR(struct dados *p, FILE *KP);

void ALTERAR(struct dados *p, FILE *KP);

void EXCLUIR(struct dados *p, FILE *KP);

int PESQUISAR(struct dados *p, FILE *KP);

void LISTAR(struct dados *p, FILE *KP);

void CONSULTAR(struct dados *p, FILE *KP);

void QUANTIDADE(struct dados *p, FILE *KP);

void SAIR();

void ERRO(int x);

void LIMPAR(struct dados *p);

void main()
{
   int op;

   struct dados produtos;

   struct dados *p;

   p = &produtos;

   FILE *KP;

   for(;;)
   {
      system("color 1F");

      printf("\n\n\t\t\t>>> MENU <<<\n\n\n\n");

      printf("\t\t1 - INCLUIR PRODUTOS\n\n");
      printf("\t\t2 - ALTERAR PRODUTOS\n\n");
      printf("\t\t3 - EXCLUIR PRODUTOS\n\n");
      printf("\t\t4 - PESQUISAR PRODUTOS\n\n");
      printf("\t\t5 - LISTAR PRODUTOS\n\n");
      printf("\t\t6 - LISTAR PRODUTOS INDISPONIVEIS\n\n");
      printf("\t\t7 - ALTERAR QUANTIDADE DOS PRODUTOS\n\n");
      printf("\t\t8 - SAIR\n\n");

      printf("\n\n\n\t\tESCOLHA: ");
      scanf("%d",&op);
      getchar();

      switch (op)
      {
      case 1:
         INCLUIR(p, KP);
         break;
      case 2:
         ALTERAR(p, KP);
         break;
      case 3:
         EXCLUIR(p, KP);
         break;
      case 4:
         PESQUISAR(p, KP);
         break;
      case 5:
         LISTAR(p, KP);
         break;
      case 6:
         CONSULTAR(p, KP);
         break;
      case 7:
         QUANTIDADE(p, KP);
         break;
      case 8:
         SAIR();
         break;
      default:
         ERRO(1); // VALOR INVÁLIDO
      }

      system("pause");
      system("cls");
   }
}

void INCLUIR(struct dados *p, FILE *KP)
{
   system("cls");

   KP = fopen("lista.txt","a");

   LIMPAR(p);

   printf("\n\n\t\t\t>>> CADASTRO DE PRODUTO <<<\n\n");

   printf("\n\t\tInsira o codigo do produto: ");
   gets(p->cod);
   printf("\n\n\t\tInsira o nome do produto: ");
   gets(p->desc);

   do
   {
      printf("\n\n\t\tInsira a quantidade do produto: ");
      scanf("%d",&(*p).qnt);

      if(((*p).qnt)<0)
      {
         ERRO(1); // VALOR INVÁLIDO

         system("pause");
         system("cls");
         system("color 1F");

         printf("\n\n\t\t\t>>> CADASTRO DE PRODUTO <<<\n\n");

         printf("\n\t\tInsira o codigo do produto: %s\n", p->cod);
         printf("\n\n\t\tInsira o nome do produto: %s\n", p->desc);
      }
   }while(((*p).qnt)<0);

   fwrite(p,sizeof(*p),1,KP);

   fclose(KP);

   printf("\n\n\t\t");
}

void ALTERAR(struct dados *p, FILE *KP)
{
   int k, y;

   KP = fopen("lista.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQUISAR(p, KP);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         printf("\n\t\t\t>>> ALTERA PRODUTO <<<\n\n");

         printf("\n\t\tInsira o codigo do produto: ");
         gets(p->cod);
         printf("\n\n\t\tInsira o nome do produto: ");
         gets(p->desc);

         do
         {
            printf("\n\n\t\tInsira a quantidade do produto: ");
            scanf("%d",&(*p).qnt);

            if(((*p).qnt)<0)
            {
               ERRO(1); // VALOR INVÁLIDO

               system("pause");
               system("cls");
               system("color 1F");

               printf("\n\n\t\t\t>>> ALTERA PRODUTO <<<\n\n");

               printf("\n\t\tInsira o codigo do produto: %s\n", p->cod);
               printf("\n\n\t\tInsira o nome do produto: %s\n", p->desc);
            }
         }while(((*p).qnt)<0);

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);
         fwrite(p,sizeof(*p),1,KP);

         fclose(KP);

         printf("\n\n\t\t");
      }
   }
}

void EXCLUIR(struct dados *p, FILE *KP)
{
   int k, y;

   KP = fopen("lista.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQUISAR(p, KP);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         p->cod[0] = '*';
         p->desc[0] = '*';
         p->qnt = -1;

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);
         fwrite(p,sizeof(*p),1,KP);

         fclose(KP);

         printf("\n\t\t\t>>> PRODUTO EXCLUIDO <<<\n\n");

         printf("\n\n\t\t");
      }
   }
}

int PESQUISAR(struct dados *p, FILE *KP)
{
   int i, j, cont=0;
   unsigned char pesq[30] = "\0";

   KP = fopen("lista.txt","r");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>> PESQUISA DE PRODUTO <<<\n\n");

      printf("\n\t\tInsira o nome do produto: ");
      gets(pesq);

      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->desc[0] != '*')
            {
               for (j = 0; p->desc[j] != '\0'; j++)
               {
                  if (p->desc[j] != pesq[j])
                  {
                     break;
                  }
               }
            }

            cont++;

            if (p->desc[j] == '\0' && pesq[j] == '\0')
            {
               printf("\n\t\t ________________________________________________");
               printf("\n\t\t|        |                               |       |");
               printf("\n\t\t| CODIGO |           DESCRICAO           |  QNT. |");
               printf("\n\t\t|________|_______________________________|_______|");
               printf("\n\t\t|        |                               |       |");
               printf("\n\t\t|  %-5s | %-30s|  %-5d|",p->cod, p->desc, p->qnt);
               printf("\n\t\t|________|_______________________________|_______|\n\n\n\t\t");

               return (cont);
            }
         }
         else
         {
            break;
         }
      }

      ERRO(3); // PRODUTO NÃO ENCONTRADO

      fclose(KP);

      return (-1);
   }
}

void LISTAR(struct dados *p, FILE *KP)
{
   int i;

   KP = fopen("lista.txt","r");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>> LISTA DE PRODUTOS <<<\n\n");

      printf("\n\t\t ________________________________________________");
      printf("\n\t\t|        |                               |       |");
      printf("\n\t\t| CODIGO |           DESCRICAO           |  QNT. |");
      printf("\n\t\t|________|_______________________________|_______|");

      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->cod[0] != '*')
            {
               printf("\n\t\t|        |                               |       |");
               printf("\n\t\t|  %-5s | %-30s|  %-5d|",p->cod, p->desc, p->qnt);
               printf("\n\t\t|________|_______________________________|_______|");
            }
         }
         else
         {
            break;
         }
      }

      printf("\n\n\n\n\t\t");

      fclose(KP);
   }
}

void CONSULTAR(struct dados *p, FILE *KP)
{
   int i, cont = 0;

   KP = fopen("lista.txt","r");

   if(KP == NULL )
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->cod[0] != '*')
            {
               if(p->qnt == 0)
               {
                  cont++;
               }
            }
         }
         else
         {
            break;
         }
      }

      if(cont == 0)
      {
         ERRO(2); // LISTA VAZIA
      }
      else
      {
         system("cls");

         printf("\n\n\t\t\t>>> LISTA DE PRODUTOS INDISPONIVEIS <<<\n\n");

         printf("\n\t\t ________________________________________________");
         printf("\n\t\t|        |                               |       |");
         printf("\n\t\t| CODIGO |           DESCRICAO           |  QNT. |");
         printf("\n\t\t|________|_______________________________|_______|");

         fseek(KP,0,0);

         for(;;)
         {

            i = fread(p,sizeof(*p),1,KP);

            if(i == 1)
            {
               if(p->cod[0] != '*')
               {
                  if(p->qnt == 0)
                  {
                     printf("\n\t\t|        |                               |       |");
                     printf("\n\t\t|  %-5s | %-30s|  %-5d|",p->cod, p->desc, p->qnt);
                     printf("\n\t\t|________|_______________________________|_______|");
                  }
               }
            }
            else
            {
               break;
            }
         }

         printf("\n\n\n\n\t\t");

         fclose(KP);
      }
   }
}

void QUANTIDADE(struct dados *p, FILE *KP)
{
   int k, y, alt;

   KP = fopen("lista.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQUISAR(p, KP);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         do
         {
            y = sizeof(*p)*(k-1);

            fseek(KP,y,0);

            fread(p,sizeof(*p),1,KP);

            printf("\n\t\t\t>>> ALTERA QUANTIDADE DE PRODUTO <<<\n\n");

            printf("\n\n\t\tInsira o acrescimo ou decrescimo: ");
            scanf("%d",&alt);

            p->qnt += alt;

            if(((*p).qnt)<0)
            {
               ERRO(5); // ESTOQUE NEGATIVO

               system("pause");
               system("cls");
               system("color 1F");
            }
         }while(((*p).qnt)<0);

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);

         fwrite(p,sizeof(*p),1,KP);

         fclose(KP);

         printf("\n\n\n\t\t");
      }
   }
}

void SAIR()
{
   system("cls");
   system("color 70");

   printf("\n\n\n\n\n\n\n\n\n\n");
   printf("\n\t\t\t>>> PROGRAMA FINALIZADO <<<\n\n\n");
   printf("\n\n\n\n\n\n\n\n\n\n\n\n");

   exit(0);
}

void ERRO(int x)
{
   system("cls");
   system("color 4F");

   if(x == 1)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tVALOR INVALIDO!!!\n\n\n\n\t\t");
   }
   else if (x == 2)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tLISTA VAZIA!!!\n\n\n\n\t\t");
   }
   else if (x == 3)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tPRODUTO NAO ENCONTRADO!!!\n\n\n\n\t\t");
   }
   else if (x == 4)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tPROCESSO CANCELADO!!!\n\n\n\n\t\t");
   }
   else
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tO ESTOQUE NAO PODE SER NEGATIVO!!!\n\n\n\n\t\t");
   }
}

void LIMPAR(struct dados *p)
{
   int i;

   for(i=0; i<30; i++)
   {
      p->cod[i] = '\0'; // LIMPA CÓDIGO PRODUTO

      p->desc[i] = '\0'; // LIMPA DESCRIÇÃO PRODUTO
   }
}

#endif // ex3

#ifdef ex4

/*
   4 - A partir do exercico 6 do capitulo de funcoes, retire o vetor de estrutura
       e escreva e leia os registros direto no arquivo. (utilize a funcao fseek).
*/

struct dados
{
   unsigned char nome[25];
   unsigned char end[35];
   unsigned char cidade[30];
   unsigned char estado[20];
   char cep[10];
};

FILE *KP;

void ADD(struct dados *p);

void LIST(struct dados *p);

int PESQ(struct dados *p);

void ALT(struct dados *p);

void EXC(struct dados *p);

void SAIR();

void ERRO(int x);

void LIMPAR(struct dados *p);

void main()
{
   int op;

   struct dados clientes;

   struct dados *p;

   p = &clientes;

   for(;;)
   {
      system("color 1F");

      printf("\n\n\t\t\t>>>>>> MENU <<<<<<\n\n\n");
      printf("\n\t\t1 - CADASTRAR CLIENTE\n");
      printf("\n\t\t2 - LISTAR CLIENTES\n");
      printf("\n\t\t3 - PROCURAR CLIENTE\n");
      printf("\n\t\t4 - ALTERAR CLIENTE\n");
      printf("\n\t\t5 - EXCLUIR CLIENTE\n");
      printf("\n\t\t6 - SAIR\n\n");

      printf("\n\n\t\tINFORME SUA ESCOLHA: ");
      scanf("%d",&op);
      getchar();

      switch(op)
      {
         case 1:
            ADD(p);
            break;

         case 2:
            LIST(p);
            break;

         case 3:
            PESQ(p);
            break;

         case 4:
            ALT(p);
            break;

         case 5:
            EXC(p);
            break;

         case 6:
            SAIR();
            break;

         default:
            ERRO(1); // ESCOLHA INVÁLIDA
      }

      system("pause");
      system("cls");
   }
}

void ADD(struct dados *p)
{
   system("cls");

   KP = fopen("clientes.txt","a");

   LIMPAR(p);

   printf("\n\n\t\t\t>>>>>> CADASTRO DE CLIENTE <<<<<<\n\n");

   printf("\n\t\tNOME: ");
   gets(p->nome);
   printf("\n\t\tEND.: ");
   gets(p->end);
   printf("\n\t\tCIDADE: ");
   gets(p->cidade);
   printf("\n\t\tESTADO: ");
   gets(p->estado);
   printf("\n\t\tCEP: ");
   gets(p->cep);

   fwrite(p,sizeof(*p),1,KP);

   fclose(KP);

   printf("\n\n\t\t");
}

void LIST(struct dados *p)
{
   int k;

   KP=fopen("clientes.txt","r");

   if(KP==NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>>>>> LISTA DE CLIENTES <<<<<<\n");

      for(;;)
      {
         k = fread(p,sizeof(*p),1,KP);

         if(k == 1)
         {
            if(p->nome[0] != '*')
            {
               printf("\n\n\t\tNOME: %s",p->nome);
               printf("\n\t\tEND.: %s",p->end);
               printf("\n\t\tCIDADE: %s",p->cidade);
               printf("\n\t\tESTADO: %s",p->estado);
               printf("\n\t\tCEP: %s",p->cep);
            }
         }
         else
         {
            break;
         }
      }

      fclose(KP);

      printf("\n\n\n\t\t");
   }
}

int PESQ(struct dados *p)
{
   int k, j, cont = 0;
   unsigned char pesq[25] = "\0";

   KP = fopen("clientes.txt","r");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>>>>> PESQUISA DE CLIENTE <<<<<<\n\n");

      printf("\n\t\tInsira o nome do cliente: ");
      gets(pesq);

      for(;;)
      {
         k = fread(p,sizeof(*p),1,KP);

         if(k == 1)
         {
            if(p->nome[0] != '*')
            {
               for (j = 0; p->nome[j] != '\0'; j++)
               {
                  if (p->nome[j] != pesq[j])
                  {
                     break;
                  }
               }
            }

            cont++;

            if (p->nome[j] == '\0' && pesq[j] == '\0')
            {
               printf("\n\n\t\tNOME: %s",p->nome);
               printf("\n\t\tEND.: %s",p->end);
               printf("\n\t\tCIDADE: %s",p->cidade);
               printf("\n\t\tESTADO: %s",p->estado);
               printf("\n\t\tCEP: %s",p->cep);

               printf("\n\n\n\t\t");

               fclose(KP);

               return (cont);
            }
         }
         else
         {
            break;
         }
      }

      ERRO(3); // PRODUTO NÃO ENCONTRADO

      fclose(KP);

      return -1;

      printf("\n\n\t\t");
   }
}

void ALT(struct dados *p)
{
   int k, y;

   KP = fopen("clientes.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQ(p);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         printf("\t>>> ALTERA CLIENTE <<<\n\n");

         printf("\n\t\tNOME: ");
         gets(p->nome);
         printf("\n\t\tEND.: ");
         gets(p->end);
         printf("\n\t\tCIDADE: ");
         gets(p->cidade);
         printf("\n\t\tESTADO: ");
         gets(p->estado);
         printf("\n\t\tCEP: ");
         gets(p->cep);

         KP = fopen("clientes.txt","r+");

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);

         fwrite(p,sizeof(*p),1,KP);

         fclose(KP);

         printf("\n\n\t\t");
      }
   }
}

void EXC(struct dados *p)
{
   int k, y;

   KP = fopen("clientes.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQ(p);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         p->nome[0] = '*';
         p->end[0] = '*';
         p->cidade[0] = '*';
         p->estado[0] = '*';
         p->cep[0] = '*';

         KP = fopen("clientes.txt","r+");

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);

         fwrite(p,sizeof(*p),1,KP);

         printf("\t>>> CLIENTE EXCLUIDO <<<\n");

         fclose(KP);

         printf("\n\n\t\t");
      }
   }
}

void SAIR()
{
   system("cls");
   system("color 70");

   printf("\n\n\n\n\n\n\n\n\n\n");
   printf("\n\t\t\t>>>>>> PROGRAMA FINALIZADO <<<<<<\n\n\n");
   printf("\n\n\n\n\n\n\n\n\n\n\n\n");

   exit(0);
}

void ERRO(int x)
{
   system("cls");
   system("color 4F");

   if(x == 1)
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      ESCOLHA INVALIDA      \n\n\n\n\t\t");
   }
   else if(x == 2)
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t        LISTA VAZIA      \n\n\n\n\t\t");
   }
   else if(x == 3)
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      CLIENTE NAO ENCONTRADO      \n\n\n\n\t\t");
   }
   else
   {
      printf("\n\n\t\t\t>>>>>> ERRO <<<<<<\n\n\n");
      printf("\n\t\t      PROCESSO CANCELADO      \n\n\n\n\t\t");
   }
}

void LIMPAR(struct dados *p)
{
   p->nome[0]='\0'; // LIMPA O NOME

   p->end[0]='\0'; // LIMPA O ENDEREÇO

   p->cidade[0]='\0'; // LIMPA A CIDADE

   p->estado[0]='\0'; // LIMPA O ESTADO

   p->cep[0]='\0'; // LIMPA O CEP
}

#endif // ex4
