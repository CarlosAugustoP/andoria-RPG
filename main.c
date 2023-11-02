#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 


typedef struct  {
    char nome[20];
    int hp;

}Oponente;

int combat (int seuHp, Oponente oponente);

int gerarNumeroAleatorio(int inicio, int limite);

int main(void) {
  printf("Hello World\n");
  return 0;
}

int gerarNumeroAleatorio(int inicio, int limite) {
    srand(time(NULL));
    int numeroAleatorio = rand();
    numeroAleatorio = inicio + (numeroAleatorio % (limite - inicio + 1));
    
    return numeroAleatorio;
}

int combat (int seuHp, Oponente oponente){
    int numeroAleatorio;
    int danoTomado,hpRecuperado;
    int defesa;
    int acao; 
    
    char vetorDialogo[9][80] = {
        "%s rosnando, pronto para o próximo ataque, te encara com intensidade.",
        "Com um olhar feroz, %s se prepara para lançar seu próximo ataque.",
        "%s mantém seu olhar fixo em você, antecipando o próximo confronto.",
        "Você vê %s respirando profundamente, se preparando para o próximo golpe.",
        "Os olhos de %s brilham com determinação enquanto ele se prepara para atacar novamente.",
        "Com um grunhido ameaçador, %s se prepara para mais um round de combate.",
        "%s mantém sua postura, observando cada um de seus movimentos atentamente.",
        "Você sente a tensão no ar enquanto %s se prepara para o próximo ataque.",
        "%s parece imperturbável, pronto para desferir outro golpe mortal."
    };
    while (seuHp>0){
        char dialogoPersonalizado[80];
        numeroAleatorio = gerarNumeroAleatorio(0,8);
        sprintf(dialogoPersonalizado, vetorDialogo[numeroAleatorio],oponente.nome);
        time_t tempoInicial = time(NULL); 
        
        printf("Rapidamente! Qual a sua ação? 1: ataque 2: defesa\n ");
        if (scanf("%d",&acao)!=1){
            danoTomado = gerarNumeroAleatorio(1,10);
            printf("Você não inseriu um comando a tempo!\n Você perdeu %d de vida!" , danoTomado);
            seuHp = seuHp - danoTomado;
            
        }else{
            time_t tempoFinal = time(NULL);
            double tempoDecorrido = difftime(tempoFinal, tempoInicial);
            if (tempoDecorrido <= 5.0) {
                switch (acao){
                    case 1:
                        danoTomado = gerarNumeroAleatorio(1,10);
                        printf("Você atacou o inimigo com sucesso, gerando %d de dano!", danoTomado);
                        oponente.hp = oponente.hp - danoTomado;
                        break;
                    case 2:
                        defesa = gerarNumeroAleatorio(0,1);
                        hpRecuperado = gerarNumeroAleatorio (1,4);
                        if (defesa){
                            printf("Você defendeu com sucesso e recuperou %d de hp",hpRecuperado);
                            seuHp = seuHp+hpRecuperado;
                        }
                        

                        
                }
                
                
            } else {
                printf("Tempo esgotado! O oponente ataca.\n");
            
            }
        }       
    }
}

/** 
 * carlos 
 * pires 
 * ziraldo 
 * 
 * ou isso ou exibimos a estrutura da arvore, que seria mais dificil 
 * exemplo:
 * 
 * Suas últimas vidas:
 * adriano
 * bernardo
 * carlos
 * 
 *(o usuario escolhe carlos)

 1 - iniciar jogo
 2 - sair de jogo
 3 - ver ultimos jogos
 */