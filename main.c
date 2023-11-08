#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <string.h>
#ifdef _WIN32
    #include <conio.h>
#endif

int karma=0;

typedef struct  {
    char nome[20];
    int hp;

}Oponente;

typedef struct arv {
  char *texto;
  int id;
  struct arv *esq;
  struct arv *dir;
} Arv;

int combat (int seuHp, Oponente oponente);
int gerarNumeroAleatorio(int inicio, int limite);
void inserir(Arv **t, char texto [2800], int id);
void game();
void clear();
int choice; // variavel global que sera usada na recursao de game()

int main() {
    int opcao;

    Arv *history = NULL;
    //raiz
    inserir(&history, "Voce chega no palacio real, que encontra-se em um clima funebre...\n O sequestro da doce princesa Melinda parece abalar a todos em sua volta!\n Enquanto voce caminha pelos largos corredores do castelo, a pressao aumenta sobre seus ombros.\n\n O reino inteiro conta com voce!\n\n Finalmente, voce chega ao trono do Rei Tristan.\n Devastado, com lagrimas nos seus olhos, ele fala com voce:\n \"Ah! Cacador... Que bom que voce recebeu o meu convite.\n Devo confessar que os tempos sao dificeis... Mas, gracas aos Deuses, voce esta aqui para nos ajudar.\n Minha amada filha esta escondida no castelo de Eldia, abandonado a seculos!\n Suspeito que os malditos feiticeiros de Nocturia estao protegendo a torre com o Dragao escuro Relgar.\n Por favor, cacador, me ajude. Voce e minha unica esperanca...\"\n\n Apos uma longa noite de pesquisa sobre como enfrentar o dragao Relgar na biblioteca do reino, voce encontra algo!\n Uma espada mitica \"Luminastra\" e a unica que pode abater o dragao!\n No entanto, a pagina que fala de sua localizacao esta rasgada...\n Estranho... Sera que alguem pode lhe ajudar com esse misterio?\n\n ESCOLHA SUA ACAO! 1 - conversar com a bibliotecaria 2 - conversar com o rei ", 10);
    //historia carlos 1.1
    inserir(&history, "Voce decide conversar com a bibliotecaria, uma mulher idosa com oculos de leitura e cabelos prateados. Ela olha para voce com olhos sabios e diz:\n\n \"Ah, jovem aventureiro, a espada mitica 'Luminastra' e uma lenda antiga!\n\n Eu adoraria poder ajudar, mas a pagina que fala de sua localizacao esta irremediavelmente rasgada. Nao consigo decifrar o que resta dela.\" Ela suspira com pesar.\n\n \"Entretanto, ha esperanca. No Vale Verde, a leste do reino, vive um sabio elfo chamado Elandor.\n Ele e o guardiao do conhecimento ancestral e pode conhecer o segredo para encontrar a 'Luminastra'. Procure por ele e talvez voce descubra o caminho para a espada que pode abater o Dragao Relgar.\"\n Ela lhe entrega um antigo mapa que mostra a localizacao do Vale Verde.\n\n Seguindo suas cordenadas, você chega em uma vila.\n\nMoradores lhe encaram, deixando claro que sua reputacao claramente nao e muito boa. Um cacador de recompensas sujo... Que segue qualquer ordem por dinheiro.\nSera que isso e verdade?\nVoce chega na casa de Elandor, uma gigantesca arvore, e bate na porta. Mas ninguem lhe atende...\n\n Agora, voce se depara com uma escolha: Arrombar a porta(1) ou Bater mais forte (2)", 8);//
    inserir(&history, "Voce decide arrombar a porta da casa do ancião, determinado a encontrar respostas sobre a 'Luminastra'. Ao entrar, depara-se com uma cena aterrorizante. No centro da sala, está o corpo inerte do ancião elfo Elandor. Seus olhos estão vidrados, e sangue mancha o chao. E evidente que ele foi atacado. A sensacao de mal e trevas enche o ar.\n\nAntes que voce possa processar a visao, duas figuras sinistras emergem das sombras. Sao cavaleiros de Nocturia, vestindo capas negras e segurando espadas ameacadoras. Suas peles sao palidas e seus olhos sao completamente negros. Com um sorriso sadico, um deles diz: \"CACADOR! BEM QUE SENTIMOS UMA PRESENCA MAIS SUJA QUE A NOSSA...\" \n\nOs olhos dos cavaleiros brilham com malicia, e ambos puxam suas espadas, apontando-as para sua direcao.\n\n\"ESTRANHO... SENTIMOS CONFLITO EM VOCE... COMO SE AINDA HOUVESSE LUZ...\" \n\nVoce desembainha sua lamina, preparado para uma batalha!\n\n\"...DEIXE-NOS DEVORA-LA!\"\n", 7);
    inserir(&history, "Em um movimento agil, os cavaleiros empunham suas espadas e, com precisao cruel, desferem golpes mortais. Voce sente as laminas penetrarem seu corpo, e uma dor lancinante toma conta de voce. Impalado, voce cai ao chao, imovel e a merce dos cavaleiros das trevas. Voce escuta um deles falar, em tom de zombaria com o seu fracasso:\n\"A COISA QUE DEIXA A PRESA MAIS DELICIOSA E O MEDO, CACADOR...\"\nCom visao turva, voce consegue ver os cavaleiros de Nocturia, mas algo esta errado. \nEles comecam a se contorcer de maneira grotesca.\n Suas mandibulas se abrem completamente, como a de uma cobra, revelando uma boca cheia de dentes afiados.\nEm um arrepio de horror, voce percebe que essas criaturas nao sao humanas. Com fome voraz, eles se inclinam sobre voce, suas mandibulas prontas para devora-lo vivo..\n Uma segunda boca se forma, cheia de dentes afiados e sinistros, pronta para devorar.\n A visao e horripilante e surreal, um pesadelo vivo se desenrolando diante de seus olhos.\n\nVoce e presa facil para essas criaturas abominaveis. A agonia toma conta de voce enquanto e devorado vivo pelos cavaleiros de Nocturia, uma morte terrivel e brutal... \nO reino de Andoria nunca sabera do heroi que tentou salva-los, e a esperanca se apaga com sua vida. As trevas triunfam.\n\nFIM DA JORNADA!\n\n",9 );//acho que o problema é que nao estamos fazendo isso apontar pra nulo
    inserir(&history, "Apos um triunfo epico contra os cavaleiro de Nocturia, O ultimo cavaleiro desmaia no chao, lancando um suspiro final de dor!\n. Suas habilidades superam a ameaca das trevas, e voce emerge vitorioso!\n Os cavaleiros agora estao indefesos diante de voce. \nCom a vantagem a seu favor, voce decide amarrar os cavaleiros para impedi-los de causar mais estragos.\n As cordas apertam seus pulsos, garantindo que nao possam escapar de sua justica. \n\nAgora, com os cavaleiros de Nocturia amarrados e impotentes, voce enfrenta uma decisao crucial: Apesar da morte do anciao Elandor, podemos ainda extrair as informacoes necessarias...\n Para isso, como voce deseja interroga-los a respeito da espada de Luminastra? Voce pode usar a forca bruta e violencia para extrair informacoes(1) ou tentar persuade-los a falar cooperativamente(2).", 5);
    inserir(&history, "Checkpoint ", 1);
    inserir(&history, "Decidido a obter informacoes sobre a espada Luminastra e os planos macabros dos cavaleiros, voce tenta persuadir os cavaleiros de Nocturia, mas sua paciencia esta se esgotando.\n Com raiva, voce exige: \"Onde esta Luminastra? O que a Ordem de Nocturia fez com a princesa?\"\nOs cavaleiros olham para voce, encarando a intensidade em sua voz.\nEles se contorcem, tentando se libertar, mas suas amarras os mantem firmemente presos. Voce mantem sua postura, deixando claro que nao aceitara evasivas.\n \"Ja ouvi lendas sobre os cavaleiros de Nocturia. Voces ja foram leais ao rei... Olhem so no que se transformaram\", voce continua.\n \"Diga-me onde ela esta, e talvez haja misericordia para voces.\"\nOs cavaleiros riem diante de suas palavras, mas um deles finalmente fala: \"NAO SOMOS MAIS AS PESSOAS QUE ERAMOS. NAO TEMOS MAIS ALMA, CACADOR... CEDEMOS NOSSO ESPIRITO PARA UM PROPOSITO MAIOR QUE NOS. E VOCE? QUAL CAUSA VOCE SERVE? APENAS DINHEIRO.\nVoce rebate: \"Voce nao me conhece. Estou aqui para resgatar a princesa. Nada mais.\n\"VOCE ESTA AQUI PARA SUGAR OS COFRES DO REI TRISTAN! PARE DE MENTIR, CACADOR... VOCE TAMBEM CEDEU SUA ALMA...\", diz um dos cavaleiros.\nVoce sente a verdade nas palavras deles, o que o faz refletir. No entanto, voce resiste a tentacao de se juntar as trevas.\n\"VOCE NAO ENTENDE O PODER DA TREVA. EXISTEM COISAS, CACADOR... COISAS QUE SOMENTE A ESCURIDAO PODE LHE OFERECER. JUNTE-SE A NOS, E TOMAREMOS O REINO INTEIRO PARA NOSSO MESTRE! UMA VIDA SEM PROPOSITO E LAMENTAVEL, CACADOR. ESTA NA HORA DE TE DARMOS UM...\"\nNesse momento, um dos cavaleiros toca em seu braco, e uma onda de escuridao percorre seu ser.\nVoce tem uma visao sombria, compreendendo a tentacao e o poder da treva:\nUm escopo inimaginavel de poder, proporcionado por algo muito mais forte que dinheiro: O medo.\nUma voz sussurra em sua mente, tentando seduzi-lo com promessas de poder inimaginavel.\nEsta na hora de decidir: Se juntar a Ordem das Trevas(1) ou fingir se juntar a Ordem das Trevas para persuadi-los.(2)\n", 7);
    inserir(&history, "Checkpoint", 2);
    inserir(&history, "Checkpoint", 9);
    //historia pires 1.2
    inserir(&history, "Voce decide voltar para a sala de trono do Rei Tristan, Ele olha para voce com olhos cheios de preocupacao e diz:\n\n \"Luminastra? Essa espada esta proibida! Ela corrompe todos que a procuram! Em nenhuma hipotese irei-\"\n O rei olha para uma pintura de sua amada filha, lembrando a ele de seu amor perdido... Nao existe nada que ele nao fara para tela de volta.\n Apos uma pausa, o Rei Tristan recompose e continua:\n \"Existe alguem que pode lhe ajudar... Sir Cedric, um aposentado cavaleiro de Aldoria, tempos atras cacava esse artefato maldito...\n Ele costumava ser o mais leal senhor da cidade. Hoje, ele e nosso mais leal bebado... Quando nao esta afogando suas magoas em uma taverna, ele geralmente toca musica pela praca da cidade.\"\n O Rei Tristan lhe entrega um mapa da cidade com a marcacao dos locais mencionados.\n\n Agora, voce se depara com uma escolha: partir para a taverna 'O Barril Dourado'(1) ou dirigir-se a praca da cidade para encontrar Sir Cedric.(2)", 15);
    inserir(&history, "Checkpoint 1.2.1", 12);
    inserir(&history, "Checkpoint 1.2.2", 17);
    
    while (1) {
   
        clear();
 
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
            /*
                clear();
                printf("Para a visibilidade de todo o texto, sugerimos aumentar o tamanho do terminal\n");
                sleep(2);
                clear();
                printf("DESESPERO!\n");
                sleep(1);
                printf("Em meio a escuridao da noite, no majestoso reino de Andoria, um ato nefasto abalou a tranquilidade do humilde povo!\n");
                sleep(4);
                printf(" A destemida PRINCESA MELINDA, herdeira do trono, foi capturada por uma forca maligna conhecida como A ORDEM DE NOCTURIA , Deixando o reino inteiro a beira do abismo!\n");
                sleep(4);
                printf("Desesperado, o sabio REI TRISTAN convoca o mais improvavel dos herois, alguem destinado a trazer a luz de volta a sua amada terra.\n");
                sleep(4);
                printf(" Voce, o ultimo raio de esperanca do reino, um CACADOR DE RECOMPENSA e convocado a embarcar em uma jornada epica...\n");
                sleep(5);
                clear();
                sleep(1);
              */  
                game(&history);
                getch();
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

void inserir(Arv **t, char* texto, int id) {
    if (*t == NULL) {
        *t = (Arv *)malloc(sizeof(Arv));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->id = id;
        (*t)->texto = (char*) malloc(strlen(texto)+1);
        strcpy((*t)->texto, texto);
    } else {
        if (id < (*t)->id) {
            inserir(&(*t)->esq, texto,id);
        }
        if (id > (*t)->id) {
            inserir(&(*t)->dir,texto, id);
        }
    }
}

void game(Arv **t){
  if(*t != NULL){
    printf("%s\n", (*t)->texto);
    if((*t)->esq != NULL){
      //sleep(6);
      printf("\nINSIRA SUA ESCOLHA: ");
      scanf("%d", &choice);
      if(choice == 1){
        clear();
        sleep(1);
        game(&((*t)->esq));
      } else {
        clear();
        sleep(1);
        game(&((*t)->dir));
      }
    }
  }
}

int gerarNumeroAleatorio(int inicio, int limite) {
    srand(time(NULL));
    int numeroAleatorio = rand();
    numeroAleatorio = inicio + (numeroAleatorio % (limite - inicio + 1));
    
    return numeroAleatorio;
}
void clear(){
    #ifdef _WIN32 
            system("cls");
        #else 
            system("clear");
        #endif
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