#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//Tudo com # é uma diretiva
//Evite números mágicos (i = 3, o que é 3? NOMEAR)
//Só use uma variável depois de inicializada
//O compilador lê o código da direita pra esquerda
//01/01/1970 EPOCH

int main(){
    //Imprime cabeçalho do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Welcome to      \n");
    printf("     |_|_|nnnn nnnn|_|_|       GUESSING GAME!    \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    srand(time(0));
    int numerosecreto = rand() % 100;
    int chute;
    int acertou = 0;
    int tentativas = 1;
    double pontos = 1000;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil \n(2) Médio \n(3) Difícil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;
    switch(nivel){
      case 1:
        numerodetentativas = 20;
        break;
      case 2:
        numerodetentativas = 15;
        break;
      case 3:
        numerodetentativas = 6;
        break;
      default:
       printf("Nível inválido, escolha novamente.\n");
       printf("Qual o nível de dificuldade?\n");
       printf("(1) Fácil \n(2) Médio \n(3) Difícil\n");
       printf("Escolha: ");
       scanf("%d", &nivel);
       
       switch(nivel){
          case 1:
            numerodetentativas = 20;
            break;
          case 2:
            numerodetentativas = 15;
            break;
          case 3:
            numerodetentativas = 6;
            break;
        }
    }

    for(int i = 1; i <= numerodetentativas; i++){
      printf("\nTentativa %d\n", tentativas);
      printf("Qual é seu chute? \n");
      scanf("%d", &chute);
      //printf("Seu chute foi: %d \n", chute);

      if(chute < 0){
        printf("Você não pode chutar números negativos!\n");
        //Não executa o restante do bloco mas também não cancela o loop
        continue;
      }

      acertou = (chute == numerosecreto);
      int maior = chute > numerosecreto;

      if(acertou){
        printf("\nPARABÉNS! Você acertou! \n");
        printf("Jogue novamente, vamos ver se é assim tão esperto! \n");

        break;
      }
      else if(maior){
        printf("Seu chute foi MAIOR que o número secreto \n\n");
      }
      else{
        printf("Seu chute foi MENOR que o número secreto. \n\n");
      }
      tentativas++;

      double pontosperdidos = abs((chute - numerosecreto))/(double)2;
      pontos = pontos - pontosperdidos;
    }
    if(acertou){
      printf("***************************************** \n");
      printf("*             WINNER!              * \n");
      printf("*           Points: %.2f           * \n", pontos);
      if(tentativas < 10){
        printf("*             Tentativas: %d             * \n", tentativas);
      }else if(tentativas >= 10 && tentativas < 100){
        printf("*             Tentativas: %d            * \n", tentativas);
      }
      printf("*              o  o   o  o              * \n");
      printf("*              |\\/ \\^/ \\/|              * \n");
      printf("*              |,-------.|              * \n");
      printf("*            ,-.(|)   (|),-.            * \n");
      printf("*            \\_*._ ' '_.* _/            * \n");
      printf("*             /`-.`--' .-'\\             * \n");
      printf("*        ,--./    `---'    \\,--.        * \n");
      printf("*        \\   |(  )     (  )|   /        * \n");
      printf("*         \\  | ||       || |  /         * \n");
      printf("*          \\ | /|\\     /|\\ | /          * \n");
      printf("*          /  \\-._     _,-/  \\          * \n");
      printf("*         //| \\\\  `---'  // |\\\\         * \n");
      printf("*        /,-.,-.\\       /,-.,-.\\        * \n");
      printf("*       o   o   o      o   o    o       * \n");
      printf("*          THANKS FOR PLAYING!          * \n");
      printf("***************************************** \n");
    }else{
      printf("*************************************** \n");
      printf("*             LOSER!            * \n");
      printf("*          Points: %.2f          * \n", pontos);
      if(tentativas < 10){
        printf("*             Tentativas: %d           * \n", tentativas-1);
      }else if(tentativas >= 10 && tentativas < 100){
        printf("*            Tentativas: %d          * \n", tentativas-1);
      }
      printf("*              ,-.___.-.              * \n");
      printf("*           ,-.(_)   (_),-.           * \n");
      printf("*           \\_*._ ' '_.* _/           * \n");
      printf("*            /`- .--. .-'\\            * \n");
      printf("*       ,--./    `---'    \\,--.       * \n");
      printf("*       \\   |(  )     (  )|   /       * \n");
      printf("*        \\  | ||       || |  /        * \n");
      printf("*         \\ | /|\\     /|\\ | /         * \n");
      printf("*         /  \\-._     _,-/  \\         * \n");
      printf("*        //| \\  `---'  // |\\\\         * \n");
      printf("*       /,-.,-.\\       /,-.,-.\\       * \n");
      printf("*      o   o   o      o   o    o      * \n");
      printf("*         THANKS FOR PLAYING!         * \n");
      printf("*************************************** \n");
    }
}
