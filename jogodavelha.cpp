#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

/*
- PROJETO JOGO DA VELHA ELETRÔNICO                       
- MÓDULO DE PROGRAMAÇÃO - PROF BRUNO                      
- ESTRUTURA DE DADOS E ALGORITMOS UM                      
- RENATO LEMOS LIMONGI DE AGUIAR MORAES - 2° PERÍODO (CCOMP)                      
- UNIFESO                                                                               
 */

/* CONSTANTE DA MATRIZ */

const int MAX=3;

/* PROTÓTIPOS DE FUNÇÕES */

void iniciar_tela(char [][15], int *);
void game(int *, char [][15], char [][MAX], int);
void inicializacao(int *, char jogadas[][MAX]);
void matriz(char jogo[][MAX]);
void mensagem(int, char [][15]);
void jogar_de_novo();
void erro();
void jogada_CPU(char [][MAX]);

/* MAIN */

main()
{
  /* DECLARAÇÃO DE VARIÁVEIS: 2 MATRIZES, UMA ARMAZENA O NOME DE 2 JOGADORES COM NO MÁXIMO 15 LETRAS.....
  E UMA MATRIZ "JOGADAS" DE MAX ELEMENTOS... OU SEJA 3x3 COMO DECLARADO LÁ EM CIMA....ESTA VAI ARMAZENAR OS 'X' E OS 'O'....
  UMA VARIÁVEL DENOMINADA RODADA QUE GERENCIA O JOGO TODO... ENTÃO SE FOR RODADA PAR É O P1 QUE JOGA, SE FOR RODADA ÍMPAR É O P2*/
  int opcao;
  char players[2][15]; char jogadas[MAX][MAX]; int rodada;
  system("cls"); // COMANDO PARA LIMPAR A TELA DO PROMPT
  inicializacao(&rodada, jogadas); // INICIALIZA AS VARIÁVEIS.. RODADA COMEÇA COM 0 E JOGADAS COM ESPAÇO " "...
  iniciar_tela(players, &opcao); // A  PRIMEIRA TELA QUE APARECE QUANDO O PROGRAMA É ABERTO SOLICITANDO NOME DOS JOGADORES
  game(&rodada, players, jogadas, opcao); // ESSA FUNÇÃO MANIPULA O JOGO TODO....
}//FIM DA FUNÇÃO

/* DESEJA JOGAR NOVAMENTE */

void jogar_de_novo()
{
  char opcao;
  system("cls");
  system("color b");
  printf("\n\n\n\n\n\n\n\t\t\t       Deseja Jogar novamente \n\n\n\n\t\t\t\t   1 - Sim\n\n\t\t\t\t   2 - Nao");
  opcao=getch(); // A VARIÁVEL RECEBE O CARACTERE ASSIM QUE PRESSIONADO, SEM O USÚARIO PRESSIONAR ENTER
  switch(opcao)
  {
    case '1':
           main();
           break;

    case '2':
          exit(1); // Sair do jogo....
          break;

    default:
          printf("Opcao invalida!");
          break;
  }//FIM DO SWITCH
}//FIM DA FUNÇÃO

/* JOGADA DA MÁQUINA */
void jogada_CPU(char jogadas[][MAX])
{
   int i, j;
   for(i = 0; i<3; i++)
   {
     for(j = 0; j<3; j++)
     {
       if(jogadas[i][j] == ' ') break;
     }//FIM DO FOR
     if(jogadas[i][j] == ' ') break;
   }//FIM DO FOR
   if(i*j == 9)
   {
     printf("Empate \n");
   }//FIM DO IF
   else
   {
     jogadas[i][j] = 'O';
   }//FIM DO ELSE
}//FIM DA FUNÇÃO

/* TELA DE LOGIN E LEITURA DOS PLAYERS */

void iniciar_tela(char jogadores[][15], int* opcao)
{
  system("color b");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  Jogo da Velha eletronico   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   Players   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
  printf("\n\n\t\t\t\t   1 - Jogar Multiplayer");
  printf("\n\n\t\t\t\t   2 - Jogar vc. CPU");
  printf("\n\nOpcao: ");
  scanf("%d",opcao);
  if(*opcao == 1)
  {
    printf("\n\n\t\t\t\t   P1: ");
    fflush(stdin); // LIMPAR BUFFER DO TECLADO.....
    gets(jogadores[0]); // É IGUAL O SCANF("%S",VARIÁVEL).. EFETUA LEITURA DE STRING
    strupr(jogadores[0]); // FUNÇÃO QUE TRANSFORMA A STRING TODA EM CAPS LOOK
    printf("\n\n\t\t\t\t   P2: ");
    fflush(stdin);
    gets(jogadores[1]);
    strupr(jogadores[1]);
  }//FIM DO IF
  else
  {
    printf("\n\n\t\t\t\t   P1: ");
    fflush(stdin); // LIMPAR BUFFER DO TECLADO.....
    gets(jogadores[0]); // É IGUAL O SCANF("%S",VARIÁVEL).. EFETUA LEITURA DE STRING
    strupr(jogadores[0]); // FUNÇÃO QUE TRANSFORMA A STRING TODA EM CAPS LOOK
    strcpy(jogadores[1], "CPU");
  }//FIM DO ELSE
  printf("\n\n\t\t\t\t    Bom jogo!");
  getche(); // IGUAL O SYSTEM PAUSE.. SÓ QUE SEM MENSAGEM.. PRECISA DA BIBLÍOTECA CONIO.H
}//FIM DA FUNÇÃO

/* INICIALIZA A STRING COM VÁZIO E A QUANTIDADE DE JOGADAS (RODADA) COM 0 */

void inicializacao(int *rodada, char jogadas[][MAX])
{
  int i, j;
  for(i=0; i<MAX; i++)
    for(j=0; j<MAX; j++)
      jogadas[i][j]=' ';
   (*rodada)=0; // A VARIÁVEL RODADA QUE É DO TIPO INTEIRO FOI PASSADA POR REFERÊNCIA... ENTÃO ESSA É A SINTAXE DE ATRIBUIÇÃO DE VALORES
}//FIM DA FUNÇÃO  

/* MENSAGEM DE ERRO DE POSIÇÃO JÁ PREENCHIDA */

void erro()
{
  printf("\n\n\t\t\t\t Espaco ja preenchido!");
  getche();
}//FIM DA FUNÇÃO

/* NOTIFICAÇÃO DO VENCEDOR OU DA VELHA */

void mensagem(int result, char players[][15])
{
  if(result==2)
  {
    system("cls");
    system("color a");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t%s foi o ganhador!",players[0]);
    getche();
    jogar_de_novo();
  }//FIM DO IF
  else
  if(result==3)
  {
    system("cls");
    system("color a");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t%s foi o ganhador!",players[1]);
    getche();
    jogar_de_novo();
  }//FIM DO IF
  else
  {
    system("cls");
    system("color c");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tVELHA! ");
    getche();
    jogar_de_novo();
  }//FIM DO ELSE
}//FIM DA FUNÇÃO

/* MATRIZ DO JOGO DA VELHA */

void matriz(char jogo[][MAX])
{
  system("cls");
  system("color f");
  printf("\n\n\n\n\n\t\t\t\t  %c   %c\t  %c   %c   %c\n\t\t\t\t      %c\t      %c\n\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\t\t\t\t  %c   %c\t  %c   %c   %c\n\t\t\t\t      %c\t      %c\n\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\t\t\t\t  %c   %c\t  %c   %c   %c\n\t\t\t\t      %c\t      %c",jogo[0][0],186, jogo[0][1] ,186, jogo[0][2],186, 186,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,jogo[1][0],186, jogo[1][1] ,186, jogo[1][2],186, 186,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,jogo[2][0],186, jogo[2][1] ,186, jogo[2][2],186,186);
}//FIM DA FUNÇÃO

/* FUNÇÃO QUE GERENCIA O JOGO DA VELHA */

void game(int *rodada, char jogadores[][15], char jogadas[][MAX], int opcao)
{
  // VARIÁVEIS AUXILIARES QUE FAZEM A LEITURA DAS JOGADAS DOS JOGADORES...
  int aux_linha, aux_coluna, vencedor, i, j;
  while(1)
  { // LOOP INFINITO..LA PRA FRENTE COM O DECORRER DO PROGRAMA TERÁ UM BREAK QUE SAI DESSE LOOP..
    matriz(jogadas);
    if(opcao == 1)
    {
      if((*rodada)%2==0)
      { /* JOGADOR DE RODADA PAR FAZ SUA JOGADA */
        printf("\n\n\n\n\t\t\t\t   Jogador %s\n\n", jogadores[0]);
        printf("\n\t\t\t\t     Linha: ");
        scanf("%d",&aux_linha);
        printf("\n\t\t\t\t     Coluna: ");
        scanf("%d",&aux_coluna);
        if(jogadas[aux_linha-1][aux_coluna-1]==' ')
        {
          jogadas[aux_linha-1][aux_coluna-1]='X';
          matriz(jogadas);
          (*rodada)++;
        }//FIM DO IF
         else erro();
      }//FIM DO IF
      else
      { /* JOGADOR DE RODADA ÍMPAR FAZ SUA JOGADA */
        printf("\n\n\n\n\t\t\t\t   Jogador %s\n\n", jogadores[1]);
        printf("\n\t\t\t\t     Linha: ");
        scanf("%d",&aux_linha);
        printf("\n\t\t\t\t     Coluna: ");
        scanf("%d",&aux_coluna);
        if(jogadas[aux_linha-1][aux_coluna-1]==' ')
        {
          jogadas[aux_linha-1][aux_coluna-1]='O';
          matriz(jogadas);
          (*rodada)++;
        }//FIM DO IF
        else erro();
      }//FIM DO ELSE

      if(*rodada>=5)
      { /* SÓ COMEÇA TESTAR O VENCEDOR ACIMA DE 5 JOGADOS */
        if((*rodada)==9)
          mensagem(vencedor=4, jogadores);
        else
        {
          for(i=0; i<MAX; i++)
            for(j=0; j<MAX; j++)
              if((jogadas[i][j]=='X' && jogadas[i][j]==jogadas[i+1][j] && jogadas[i+1][j]==jogadas[i+2][j]) || (jogadas[i][j]=='X' && jogadas[i][j]==jogadas[i+1][j+1] && jogadas[i+1][j+1]==jogadas[i+2][j+2]) || (jogadas[1][3]=='X' && jogadas[0][2]==jogadas[1][1] && jogadas[1][1]==jogadas[2][0] ) || (jogadas[i][j]=='X' && jogadas[i][j]==jogadas[i][j+1] && jogadas[i][j+1]==jogadas[i][j+2] ))
                mensagem(2, jogadores);

          for(i=0; i<MAX; i++)
            for(j=0; j<MAX; j++)
              if((jogadas[i][j]=='O' && jogadas[i][j]==jogadas[i+1][j] && jogadas[i+1][j]==jogadas[i+2][j]) || (jogadas[i][j]=='O' && jogadas[i][j]==jogadas[i+1][j+1] && jogadas[i+1][j+1]==jogadas[i+2][j+2]) || (jogadas[1][3]=='O' && jogadas[0][2]==jogadas[1][1] && jogadas[1][1]==jogadas[2][0] ) || (jogadas[i][j]=='O' && jogadas[i][j]==jogadas[i][j+1] && jogadas[i][j+1]==jogadas[i][j+2] ))
                 mensagem(3, jogadores);
        }//FIM DO ELSE
      }//FIM DO IF
    }//FIM DO IF
    else
    {
      if((*rodada)%2==0)
      { /* JOGADOR DE RODADA PAR FAZ SUA JOGADA */
        printf("\n\n\n\n\t\t\t\t   Jogador %s\n\n", jogadores[0]);
        printf("\n\t\t\t\t     Linha: ");
        scanf("%d",&aux_linha);
        printf("\n\t\t\t\t     Coluna: ");
        scanf("%d",&aux_coluna);
        if(jogadas[aux_linha-1][aux_coluna-1]==' ')
        {
          jogadas[aux_linha-1][aux_coluna-1]='X';
          matriz(jogadas);
          (*rodada)++;
        }//FIM DO IF
        else erro();
      }//FIM DO IF
      else
      { /* A CPU FAZ SUA JOGADA */
        jogada_CPU(jogadas);
        matriz(jogadas);
        (*rodada)++;
      }//FIM DO ELSE
      if(*rodada>=5)
      { /* SÓ COMEÇA TESTAR O VENCEDOR ACIMA DE 5 JOGADAS */
        if((*rodada)==9)
          mensagem(vencedor=4, jogadores);
        else
        {
          for(i=0; i<MAX; i++)
            for(j=0; j<MAX; j++)
              if((jogadas[i][j]=='X' && jogadas[i][j]==jogadas[i+1][j] && jogadas[i+1][j]==jogadas[i+2][j]) || (jogadas[i][j]=='X' && jogadas[i][j]==jogadas[i+1][j+1] && jogadas[i+1][j+1]==jogadas[i+2][j+2]) || (jogadas[1][3]=='X' && jogadas[0][2]==jogadas[1][1] && jogadas[1][1]==jogadas[2][0] ) || (jogadas[i][j]=='X' && jogadas[i][j]==jogadas[i][j+1] && jogadas[i][j+1]==jogadas[i][j+2] ))
                mensagem(2, jogadores);

          for(i=0; i<MAX; i++)
            for(j=0; j<MAX; j++)
              if((jogadas[i][j]=='O' && jogadas[i][j]==jogadas[i+1][j] && jogadas[i+1][j]==jogadas[i+2][j]) || (jogadas[i][j]=='O' && jogadas[i][j]==jogadas[i+1][j+1] && jogadas[i+1][j+1]==jogadas[i+2][j+2]) || (jogadas[1][3]=='O' && jogadas[0][2]==jogadas[1][1] && jogadas[1][1]==jogadas[2][0] ) || (jogadas[i][j]=='O' && jogadas[i][j]==jogadas[i][j+1] && jogadas[i][j+1]==jogadas[i][j+2] ))
                mensagem(3, jogadores);
        }//FIM DO ELSE
      }//FIM DO IF
    }//FIM DO ELSE
  }//FIM DO WHILE
}//FIM DA FUNÇÃO
