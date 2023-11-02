#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <string.h>
typedef struct  {
    char nome[20];
    int hp;

}Oponente;

typedef struct arv {
  char texto [500];
  int id;
  struct arv *esq;
  struct arv *dir;
} Arv;

int combat (int seuHp, Oponente oponente);
int gerarNumeroAleatorio(int inicio, int limite);
void inserir(Arv **t, char texto [600], int id);

int main() {
    int opcao;
    
    while (1) {
   
        #ifdef _WIN32 
            system("cls");
        #else 
            system("clear");
        #endif
 
        printf(" /   /   /   /   /   /   /   /   /   /   /\n");
        printf("/   /   /   /   /   /   /   /   /   /   /   /\n");
        printf("A   N   D   O   R   I   A\n");
        printf(" /   /   /   /   /   /   /   /   /   /   /   /\n");
        printf("/   /   /   /   /   /   /   /   /   /   /   /\n");
        
        printf("1 - Entrar no jogo\n");
        printf("2 - Jogar\n");
        printf("3 - Histórias passadas\n");
        printf("4 - Sair\n");
        
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        Oponente oponente;
        switch (opcao) {
            case 1:
                printf("Você escolheu entrar no jogo.\n");
                break;
            case 2:
                printf("Você escolheu jogar.\n");
                break;
            case 3:
                printf("Você escolheu historias passadas.\n");
                break;
            case 4:
                printf("Você escolheu sair do jogo. Ate logo!\n");
                return 0;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }
    
    return 0;
}

void inserir(Arv **t, char texto [600], int id) {
  if (*t == NULL) {
    *t = (Arv *)malloc(sizeof(Arv));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->id = id;
    strcpy((*t)->texto, texto);
  } else {
    if (id< (*t)->id) {
      inserir(&(*t)->esq, texto,id);
    }
    if (id > (*t)->id) {
      inserir(&(*t)->dir,texto, id);
    }
  }
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
    
    char vetorDialogo[9][100] = {
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
                printf("Você não inseriu um comando a tempo!\n Você perdeu %d de vida!\n" , danoTomado);
                seuHp = seuHp - danoTomado;
            
            }else{
                    time_t tempoFinal = time(NULL);
                    double tempoDecorrido = difftime(tempoFinal, tempoInicial);
                    if (tempoDecorrido <= 5.0) {
                    switch (acao){
                    case 1:
                            danoTomado = gerarNumeroAleatorio(1,10);
                            printf("Você atacou o inimigo com sucesso, gerando %d de dano!\n", danoTomado);
                            oponente.hp = oponente.hp - danoTomado;
                            break;
                    case 2:
                            defesa = gerarNumeroAleatorio(-1,1);
                            danoTomado = gerarNumeroAleatorio(3,5);
                            hpRecuperado = gerarNumeroAleatorio (1,4);
                            if (defesa){
                                printf("Você defendeu com sucesso e recuperou %d de hp\n",hpRecuperado);
                                seuHp = seuHp+hpRecuperado;
                            }else{
                                printf("Você falhou na sua defesa, e perdeu %d de hp\n", danoTomado);
                                seuHp = seuHp - danoTomado;
                            }                     
                }if (!defesa){
                    danoTomado = gerarNumeroAleatorio(3,8);
                    printf("Agora é a vez do inimigo!\n Você perdeu %d de hp!",danoTomado );
                    seuHp = seuHp- danoTomado;//acho que isso está na ordem errada
                  
            } else {
                 danoTomado = gerarNumeroAleatorio(3,8);
                 printf("Tempo esgotado! O oponente ataca.\n");
                 seuHp = seuHp - danoTomado;
            }
        }       
    }
    }
    if (seuHp<0){
        return 0;
    }else{
        return 1;
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