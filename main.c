#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <string.h>
#ifdef _WIN32
    #include <conio.h>
#endif

int karma;
int choice; // variavel global que sera usada na recursao de game()
int hpPlayer;

typedef struct  {
    char nome[20];
    int hp;
}Oponente;

typedef struct arv {
  char *texto;
  int id;
  int karma;
  struct arv *esq;
  struct arv *dir;
  int combatFlag;
  int hpIncrease;
} Arv;

typedef struct players {
    char nome[100];
    int idLastNode;
    struct players *next;
} Players;

int combat (int seuHp, Oponente oponente, int waitFlag);
int gerarNumeroAleatorio(int inicio, int limite);
void inserir(Arv **t, char *texto, int id, int combatFlag, int karma, int hpIncrease);
int game();
void clear();
void busca(Arv *aux, int n);
void printLastPlayers(Players *head);
void bubblesortByName(Players **head);
void insertPlayers(Players **head, const char playerName[100], int node);
int combatfinal(int seuHp, Oponente oponente);
void libere(Arv* raiz) ;

int main() {
    
                                    
    int opcao;
    char jogador[100];
    int idLastNode = -1;
    int c;
    int codigo;
    Players *head = NULL;

    Arv *history = NULL;
    //raiz
    inserir(&history, "Voce chega no palacio real, que encontra-se em um clima funebre...\n A falta da doce princesa Melinda parece abalar a todos em sua volta!\n Enquanto voce caminha pelos largos corredores do castelo, a pressao aumenta sobre seus ombros.\n\n O reino inteiro conta com voce!\n\n Finalmente, voce chega ao trono do Rei Tristan.\n Devastado, com lagrimas nos seus olhos, ele fala com voce:\n \"Ah! Cacador... Que bom que voce recebeu o meu convite.\n Devo confessar que os tempos sao dificeis... Mas, gracas aos Deuses, voce esta aqui para nos ajudar.\n Minha amada filha esta escondida no castelo de Eldia, abandonado a seculos!\n Suspeito que os malditos feiticeiros de Nocturia estao protegendo a torre com o Dragao escuro Relgar.\n Por favor, cacador, me ajude. Voce e minha unica esperanca...\"\n\n Apos uma longa noite de pesquisa sobre como enfrentar o dragao Relgar na biblioteca do reino, voce encontra algo!\n Uma espada mitica \"Luminastra\" e a unica que pode abater o dragao!\n No entanto, a pagina que fala de sua localizacao esta rasgada...\n Estranho... Sera que alguem pode lhe ajudar com esse misterio?\n\n ESCOLHA SUA ACAO! 1 - conversar com a bibliotecaria 2 - conversar com o rei ", 200, 0, 0,0);
    //historia carlos 1.1
    inserir(&history, "Voce decide conversar com a bibliotecaria, uma mulher idosa com oculos de leitura e cabelos prateados. Ela olha para voce com olhos sabios e diz:\n\n \"Ah, jovem aventureiro, a espada mitica 'Luminastra' e uma lenda antiga!\n\n Eu adoraria poder ajudar, mas a pagina que fala de sua localizacao esta irremediavelmente rasgada. Nao consigo decifrar o que resta dela.\" Ela suspira com pesar.\n\n \"Entretanto, ha esperanca. No Vale Verde, a leste do reino, vive um sabio elfo chamado Elandor.\n Ele e o guardiao do conhecimento ancestral e pode conhecer o segredo para encontrar a 'Luminastra'. Procure por ele e talvez voce descubra o caminho para a espada que pode abater o Dragao Relgar.\"\n Ela lhe entrega um antigo mapa que mostra a localizacao do Vale Verde.\n\n Voce chega na casa de Elandor, uma gigantesca arvore, e bate na porta. Mas ninguem lhe atende, e voce escuta o barulho de uma espada sendo guardada.\n\n Preocupado, voce se depara com uma escolha: Derrubar a porta, exercendo sua autoridade dada pelo Rei(1) ou Bater mais forte (2)", 100,0, 0,0);
    inserir(&history, "Voce decide derrubar a porta da casa do anciao, determinado a encontrar respostas sobre a 'Luminastra'. Ao entrar, depara-se com uma cena aterrorizante. No centro da sala, esta o desmaiado anciao elfo Elandor. E evidente que ele foi atacado. A sensacao de mal e trevas enche o ar.\n\nAntes que voce possa processar a visao, duas figuras sinistras emergem das sombras. Sao cavaleiros de Nocturia, vestindo capas negras e segurando espadas ameacadoras. Suas peles sao palidas e seus olhos sao completamente negros. Com um sorriso, um deles diz: \"UM CACADOR DE RECOMPENSAS! BEM QUE SENTIMOS O PECADO DA GANANCIA...\" \n\nOs olhos dos cavaleiros brilham com malicia, e ambos puxam suas espadas, apontando-as para sua direcao.\n\n\"ESTRANHO... SENTIMOS CONFLITO EM VOCE... COMO SE HOUVESSE LUZ...\" \n\nVoce desembainha sua lamina, preparado para uma batalha!\n\n\"...VAMOS APAGA-LA!\"\n", 50, 1, 1,0);
    inserir(&history, "Voce decide bater com mais forca na porta da casa do anciao, determinado a entrar. Logo, voce ouve vozes abafadas vindo do interior:\n \"QUEM ESTA FORA?\" \nVoce decide responder corajosamente:\n \"Sou um cacador de recompensas, enviado pelo Rei Tristan!\"\n A porta se abre rapidamente.\n\nAntes que voce possa reagir, laminas que brilham com energia negra atravessam a porta, golpeando voce.\n\n", 150,0, -10000,0);
    inserir(&history, "Em um movimento agil, os cavaleiros empunham suas espadas e com precisao cruel, desferem golpes contundentes.\n\n Voce perde a batalha!.\n\n", 25 , 0, -10000,0);
    inserir(&history, "Apos um triunfo epico contra os cavaleiro de Nocturia, O ultimo cavaleiro se torna poeira!\n. Suas habilidades superam a ameaca das trevas, e voce emerge vitorioso!\n Os cavaleiros agora estao indefesos diante de voce. \nCom a vantagem a seu favor, voce decide amarrar os cavaleiros para impedi-los de causar mais estragos.\n As cordas apertam seus pulsos, garantindo que nao possam escapar de sua justica. \n\nAgora, com os cavaleiros de Nocturia amarrados e impotentes, voce enfrenta uma decisao crucial\n Apesar da inconsciencia do anciao Elandor, podemos ainda extrair as informacoes necessarias...\n Para isso, como voce deseja interroga-los a respeito da espada de Luminastra? Voce tentar persuadi-los a falar cooperativamente(1). Ou usar magia para extrair suas informacoes(2)", 75, 0, 0,0);
    inserir(&history, "Decidido a obter informacoes sobre a espada Luminastra e os planos macabros dos cavaleiros, voce tenta persuadir os cavaleiros de Nocturia, mas sua paciencia esta se esgotando. Com raiva, voce exige: 'Onde esta Luminastra? O que a Ordem de Nocturia fez com a princesa?'\nOs cavaleiros olham para voce, encarando a intensidade em sua voz.\nEles se contorcem, tentando se libertar, mas suas amarras os mantem firmemente presos. Voce mantem sua postura, deixando claro que nao aceitara evasivas.\n 'Ja ouvi lendas sobre os cavaleiros de Nocturia. Voces ja foram leais ao rei... Olhem so no que se transformaram', voce continua. 'Diga-me onde ela esta, e talvez poderemos te ajudar.'\nOs cavaleiros riem diante de suas palavras, mas um deles finalmente fala: \"NAO SOMOS MAIS AS PESSOAS QUE ERAMOS, CACADOR... CEDEMOS NOSSA LUZ. E VOCE? QUAL CAUSA VOCE SERVE? APENAS DINHEIRO.\nVoce rebate: \"Voce nao me conhece. Estou aqui para resgatar a princesa. Nada mais.\n\"VOCE ESTA AQUI PARA SUGAR OS COFRES DO REI TRISTAN!\", diz um dos cavaleiros.\"VOCE NAO ENTENDE O PODER DE NOCTURIA. EXISTEM COISAS, CACADOR... COISAS QUE SOMENTE A ESCURIDAO PODE LHE OFERECER. JUNTE-SE A NOS, E TOMAREMOS O REINO INTEIRO PARA NOSSO MESTRE!\n UMA VIDA SEM PROPOSITO E LAMENTAVEL, CACADOR. ESTA NA HORA DE TE DARMOS UM...\"\nEsta na hora de decidir: Se juntar a Ordem das Trevas(1) ou fingir se juntar a Ordem das Trevas para persuade-los.(2)\n", 60, 0, 0,0);
    
    inserir(&history, "Enquanto explora o ambiente, seu olhar perspicaz se fixa no balcao de alquimia do elfo Anciao Elandor, onde voce avista varios tipos de pocoes de magia da luz e escuridao.\n\nLa, existem duas pocoes misteriosas de cores diferentes roxa(1) e preta(2).\n\n Cada uma emite uma aura magica unica, sugerindo propriedades distintas.\n Uma decisao se desenha diante de voce, e voce precisa escolher entre essas duas pocoes intrigantes.", 90, 0, 1,0);

    inserir(&history, "A tentacao ganha forca, e voce aceita seu destino sombrio.\n\n A energia escura nocturina agora flui por suas veias, moldando sua essencia.\n nao ha mais escape dessa decisao irrevogavel.\n\n Os cavaleiros, testemunhas de sua transformacao, riem com satisfacao.\n Eles reconhecem que voce aceitou seu destino, e se preparam para iniciar a cerimonia de investidura.\n\nApos a investidura, voce segue um caminho sinuoso em direcao a Floresta de Nocturia, acompanhado pelos dois cavaleiros que o escoltaram ate ali.\n As arvores parecem se contorcer com uma vida sombria, e sombras dancam entre seus galhos retorcidos.\nNo coracao da floresta, encontram um local antigo e sombrio, um santuario de trevas onde reside Morgator, o Lorde Supremo das Trevas.\n Ele e um mago de grande poder e autoridade, de unhas longas e barba prateada.\n Seu olhar penetrante parece vasculhar a sua alma. Morgator cumprimenta o recem-investido senhor das trevas com um sorriso malevolo:\n\"Voce fez a escolha certa, jovem...\", diz Morgator, sua voz ecoando com uma forca sobrenatural.\n\n Voce se ajoelha perante Morgator.\n\n \"Agora em diante, seu nome sera Lord Nihil...\n Levante-se, meu novo aprendiz...Sinto um futuro promissor em seu treinamento!\"\n\n Voce aceita sua escura missao? nao(1) ou sim(2)\n\n", 55, 0, 1000,0);//ainda n acabou

    inserir(&history, "Ao fingir se infiltrar na Ordem das Trevas, voce indaga sobre seus sinistros planos. Descobre que a Ordem rapta a princesa Melinda devido a uma profecia: unir Melinda, Lord Morgator e a espada Luminastra concede poder ilimitado. A espada esta no monte Lumina, protegida pelo Guardiao Raziel. Determinado, deixa os cavaleiros de Nocturia perplexos e decide nao desamarra-los.\nAo sair, depara-se com um elfo vendedor de itens na sinistra floresta. Ele oferece uma cara pocao de vida, vital em momentos dificeis. No entanto, seu ouro e insuficiente. O elfo, com um risinho astuto, diz: \"Ah, meu amigo, essa pocao de vida nao e barata, mmm. Ela custa uma pequena fortuna, mas pode ser a diferenca entre a vitoria e a derrota, mmm. Voce tem o ouro necessario, mmm?\"\nDiante das opcoes, pondera se deve discretamente pegar a pocao (1) ou prosseguir na jornada, confiando em sua coragem e HP atual para resgatar a princesa (2).\nA decisao e sua. O que escolhe fazer, mmm?", 65, 0, 0,0);

    
    inserir(&history, "Voce seleciona a pocao de cor preta, segurando-a com cuidado em suas maos enquanto se aproxima dos cavaleiros.\n\n Pela primeira vez desde que os encarou, seus olhos demonstram medo e incerteza. No entanto, sua determinacao e feroz e gelida quando pergunta uma ultima vez: \"Onde esta a espada Luminastra?\" Os cavaleiros lhe encaram com determinacao, recusando-se a ceder diante de sua ameaca.\n\n\"NAO SOMOS COMO VOCE, CACADOR DE RECOMPENSAS... TEMOS HONRA EM NOSSA CAUSA. NUNCA LHE DIREMOS\", declara um dos cavaleiros com um tom de escarnio. No entanto, suas palavras nao abalam sua determinacao.\n\nVoce solta uma risada. Nao e a primeira vez que ouve aquelas mesmas palavras...\n\nOs Nocturinos nao lhe deixaram escolha. Voce avanca com seu plano, comecando pela pocao. Com habilidade, voce faz com que ambos os cavaleiros inalem o suave aroma, e logo eles caem em um sono profundo.\n\nEles roncam de sono, levando voce a perceber que suas respostas terao de esperar...\n\n Que constrangedor... \n\n Voce espera algumas horas...\n\nE mais outras horas...\n\n E eles continuam em sono profundo. (1) sair da casa. (2)esperar mais.", 95, 0, 1,0);

    inserir(&history, "Voce decide recorrer a magia do anciao para obter as respostas que procura. Com determinacao fria, voce se dirige ao balcao de alquimia do velho Elandor e pega um frasco da pocao roxa.\n O liquido fumegante goteja da garrafa, e voce se aproxima dos cavaleiros com a substancia em maos.\n\nDespejando a pocao cuidadosamente sobre suas botas, voce observa o liquido comecar a transformar o couro em poeira.\n Apenas o som da substancia magica faz com que os cavaleiros tenham medo, os olhos se arregalando de apreensao.\n\n\"Onde esta a espada Luminastra?\" voce diz, sua voz gelada como a proprio pocao.\n\n Um deles finalmente cede:\n\n\"A espada... A espada Luminastra esta no Monte Lumina... Protegida pelo Guardiao Raziel.\"\n\nSatisfeito com a resposta, voce recua e permite que os cavaleiros aliviem-se.\n Agora, voce sabe onde deve ir em sua busca.\n O Monte Lumina aguarda, e o Guardiao Raziel sera um desafio a ser superado.\n Sua jornada em busca da espada Luminastra esta longe de terminar, mas voce esta um passo mais perto de seu objetivo, gracas a pocao e sua determinacao implacavel...\n\n Enquanto voce segue em direcao ao Monte Lumina, atravessa uma vila tranquila. A vila e pitoresca, com casas de madeira e uma atmosfera serena, mas algo parece fora do lugar. No momento em que voce se aproxima da praca central, uma cena aterrorizante se desenrola diante de seus olhos.\n\nUm grupo de bandidos armados e mascarados cerca um elfo indefeso. Eles o ameacam, exigindo que entregue seus pertences. \n\nVoce adoraria poder ajudar, mas ao avaliar a sua propria condicao, voce nota que seu HP ja esta consideravelmente baixo devido as acoes anteriores.\n Uma escolha dificil se apresenta diante de voce: (1)Arriscar seu hp para proteger o elfo ou (2)Ignorar a cena.", 85, 0, 0,0);

    inserir(&history, "Diante da situacao perigosa, voce opta por nao se envolver.\n Sua jornada em busca da espada Luminastra continua, mas a escolha de nao intervir na situacao deixa um peso em seu coracao.\nSera que suas acoes ou inacoes terao consequencias mais adiante em sua jornada?\n\n Com determinacao, voce continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O Guardiao Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 88, 0, 1,0);

    inserir(&history, "Voce nao pode simplesmente ignorar a angustia do elfo indefeso!\n\n Mesmo que sua saude esteja fragilizada, sua determinacao e inabalavel.\n\n Com um coracao corajoso, voce se lanca no meio dos bandidos, determinado a proteger o elfo e enfrentar os assaltantes, apesar dos riscos envolvidos.\n\nOs bandidos, surpresos com sua audacia, imediatamente se preparam para o combate.\n\n As laminas deles cintilam a luz do sol. Que a batalha comece!", 82,1, 0,0);

    inserir(&history, "A batalha e feroz, e voce luta com bravura, demonstrando honra em cada movimento.\n No entanto, os numeros dos bandidos sao superiores, e sua saude ja estava enfraquecida devido as acoes anteriores.\n Apesar de seus esforcos heroicos, voce nao consegue prevalecer contra a forca esmagadora dos assaltantes.\n\nFinalmente, voce cai diante dos bandidos.\n\n Sua luta em nome da justica e da honra nao sera esquecido, e sua historia vivera na memoria daqueles que testemunharam sua bravura. Neste momento critico, uma voz celestial ressoa em sua mente. E Raziel, um ser de luz e justica, guardiao da espada Luminastra.\n Sua voz e serena e poderosa, e ele se comunica diretamente com voce:\n\n\"CORAJOSO BUSCADOR DA LUZ, VOCE DEMONSTROU GRANDE HONRA EM SUA LUTA.\n SEU SACRIFICIO NAO PASSOU DESPERCEBIDO.\n SAIBA QUE VOCE ESTA PERTO DO SEU OBJETIVO. O MONTE LUMINA ESTA AO ALCANCE. MANTENHA SUA HONRA, POIS E A QUALIDADE MAIS VALIOSA QUE UM HEROI PODE POSSUIR. JOGUE DE NOVO, E ESCOLHA CONVENCER OS CAVALEIROS...\"", 81, 0, -10000,0);

    inserir(&history, "Apesar de sua condicao enfraquecida, voce supera os bandidos, um por um.\n Seus movimentos sao precisos, e voce demonstra grande coragem e habilidade na luta. Os bandidos, sob a pressao de sua resistencia feroz, sao finalmente derrotados e se dispersam, deixando para tras o elfo que tentaram roubar.\n\nO elfo, profundamente grato, agradece a voce com lagrimas nos olhos e uma maca que restaura seu hp.\nVoce triunfou na batalha, protegendo a inocente e restaurando a paz na vila.\n Sua coragem e honra brilham como um farol, e sua jornada em busca da espada Luminastra continua, fortalecida pela vitoria que voce conquistou com bravura.\n\n Com determinacao, voce continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O Guardiao Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 83, 0, 0,5);

    inserir(&history, "Com paciencia, voce aguarda os cavaleiros das trevas de Nocturia acordarem.\n Durante esse tempo, voce decide explorar novamente o balcao do velho Elandor.\n Dessa vez, seus olhos se fixam em uma pocao da verdade, uma escolha diferente da anterior.\n\n Segurando a pocao com cuidado, voce aguarda o despertar dos cavaleiros.\n\nQuando recobram a consciencia, voce oferece a pocao da verdade. Apos ingeri-la, os cavaleiros comecam a falar. Eles revelam que a espada Luminastra esta no Monte Lumina, protegida pelo Guardiao Raziel.\n Em seguida, confessam que, alem de capturarem a princesa, planejam cumprir uma velha profecia, denominada \"A profecia da triforca\"...\n\nEssa profecia milenar dita que um dia, um mago de grande poder escuro, Morgator, unira seu poder a espada Lumisastra e criara uma conexao com a luz da realeza, atraves de uma princesa, tornando sua magia indestrutivel!\n\nA verdade desvelada diante de voce lanca luz sobre a verdadeira natureza de sua missao.\n\n Finalmente, eles revelam algo que voce nunca esperava:\n\nA localizacao do supremo mago da ordem de Nocturia, a fonte da energia obscura deles: O mesmo Lord Morgator, que reside na floresta sombria de Nocturia.\n\n Agora, voce diante de uma escolha crucial: solicitar reforcos ao rei e atacar a ordem de Nocturia diretamente, atingindo o mago Morgator(1), Ou seguir em sua jornada para resgatar a princesa no castelo de Eldia(2)", 98, 0, 0,0);

    inserir(&history, "Com a verdade revelada, a decisao pesa em seus ombros como a lamina de uma espada afiada.\n Determinado a impedir os planos nefastos da ordem de Nocturia, voce decide que e hora de chamar os reforcos do rei e marchar com o exercito real em direcao a floresta sombria de Voriar, onde o sinistro Morgator aguarda.\n\nA mensagem e enviada ao rei, convocando a forca militar do reino para a batalha iminente.\n Sob a luz do dia, o exercito real se reune, estandartes tremulando ao vento, cavaleiros equipando suas armaduras reluzentes e soldados ajustando as lancas e arcos. O som estrondoso dos cascos dos cavalos ecoa pela planicie enquanto voce lidera a marcha em direcao a temida Voriar.\n\nAo chegar a entrada da floresta sombria, a escuridao se adensa, e uma presenca maligna paira no ar. As arvores retorcidas sussurram segredos sinistros, antecipando a chegada iminente da batalha. O exercito real se posiciona, preparando-se para enfrentar as trevas que se escondem entre as sombras.\n\nDe repente, cavaleiros das trevas emergem da escuridao, liderados por sinistras figuras encapuzadas. O confronto se inicia com um choque de aco contra aco, enquanto a luz dos cavaleiros reais luta para dissipar a escuridao que os envolve. As magias colidem no campo de batalha, criando um espetaculo de cores e explosoes misticas.\n\nEm meio ao caos, voce avanca corajosamente em direcao ao epicentro da escuridao, onde Morgator aguarda. O supremo mago da ordem de Nocturia surge, um ser envolto em sombras, emanando uma aura de pura malevolencia.\n\n\"EM OUTRA VIDA, PODERIAMOS SER UNIDOS... MAS SE VOCE QUER COMBATE, TERA!\" O escuro senhor, de barba prateada e unhas longas lhe diz.\n PREPARE-SE PARA A BATALHA FINAL!", 97, 0, 3000,0);

    inserir(&history, "Com determinacao, voce continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O Guardiao Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...\n\n", 99, 0, 0,0);

    inserir(&history, "Voce deixa a casa, impaciente com o sono profundo dos cavaleiros.\n\n Sua unica fonte de respostas desvanece, e as informacoes necessarias para resgatar a princesa Melinda jamais serao encontradas...\n\n!", 92, 0, -10000,0);

    inserir(&history, "O mago Morgator sorri, satisfeito com a sua prontidao.\n\n \"Muito bem, Lord Nihil. Agora, vou lhe contar mais detalhes sobre a missao que o aguarda.\"\nEle conduz voce ate uma camara oculta, onde mapas antigos e grimorios empoeirados adornam as prateleiras.\n Morgator desenrola um pergaminho, revelando uma representacao detalhada do reino de Andoria, com marcadores indicando os locais chave.\nEle aponta para a regiao protegida pelo Guardiao Raziel, o monte Lumina, onde a Espada Luminastra repousa em um altar sagrado.\n \"Aqui e onde reside a poderosa espada da luz, Luminastra, guardada por Raziel, seu fiel protetor,\" diz Morgator, sua voz carregada de uma mistura sinistra de antecipacao e ganancia.\n\n\n Com um tom sombrio, Morgator revela a verdade oculta:\n a princesa Melinda, herdeira do trono de Andoria, foi capturada pelos seguidores da escuridao com o proposito perverso de cumprir uma escura profecia, tendo sua luz da realeza unida com a escuridao de Morgator e a espada Luminastra, criando uma triforca indestrutivel, e deixando seus poderes indestrutiveis.\n\n\"Isso e crucial para o meu plano,\" diz Morgator, seus olhos brilhando com uma ambicao insaciavel.\n \"Uma vez que a triforca seja feita, me tornarei um novo Deus em Andoria!\"\n\n O destino esta selado, e agora voce parte em direcao ao seu proximo desafio: a destruicao do Guardiao Raziel.\n\n Com a determinacao de um discipulo sedento de poder, voce aceita a missao com um firme \"sim\".\n \nCada passo que da na direcao do altar de Luminastra e um passo em direcao ao seu papel como o homem disposto a moldar Andoria de acordo com a vontade de Morgator, o Lorde Supremo das Trevas.\n A jornada esta chegando ao fim, e o destino de Andoria esta nas suas maos.\n\nPREPARE-SE, LORDE NIHIL, PARA A BATALHA FINAL!\n\n", 58, 0, 1,0);

    inserir(&history, "Voce se ajoelha diante de Morgator, pronto para aceitar seu destino como senhor das trevas.\n\n No entanto, a medida que voce se inclina, uma sensacao de duvida comeca a se infiltrar em sua mente.\n As palavras e acoes dos cavaleiros, o olhar sinistro de Morgator, tudo isso o faz hesitar.\n\nMas antes que voce possa completar o gesto, uma voz interior grita para voce resistir, para nao se entregar completamente a escuridao.\n\n Num movimento repentino, voce recua e olha nos olhos de Morgator com determinacao.\n\n Morgator, com um sorriso maligno nos labios, estende a mao e lhe paralisa com uma forca sobrenatural.\n\n Sua voz ecoa sombriamente enquanto ele diz: \"Voce pagara o preco pela sua falta de ambicao...\"\n\n De forma implacavel, Morgator comeca a transforma-lo em poeira, o destino de todos os cavaleiros de Nocturia derrotados...\n\n", 52, 0, 0,0);

    inserir(&history, "Voce olha para o elfo peculiar e, apesar da tentacao da pocao de vida, decide que nao e o momento de sucumbir a ganancia.\n\n Com determinacao, voce agradece ao elfo e continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O protetor Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 68, 0, 0,0);

    inserir(&history, "Voce olha para o elfo peculiar e discretamente adquire o objeto, sem que ele perceba.\n\n Com determinacao, voce continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O protetor Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 62, 0, 0, 5);
    
    /*
    inserir(&history, "Checkpoint", 2);
    inserir(&history, "Checkpoint", 9);
    */

    //historia pires 1.2
    inserir(&history, "Voce decide voltar para a sala de trono do Rei Tristan, Ele olha para voce com olhos cheios de preocupacao e diz:\n\n \"Luminastra? Essa espada esta proibida! Ela corrompe todos que a procuram! Em nenhuma hipotese irei-\"\n O rei olha para uma pintura de sua amada filha, lembrando a ele de seu amor perdido... Nao existe nada que ele nao fara para tela de volta.\n Apos uma pausa, o Rei Tristan recompose e continua:\n \"Existe alguem que pode lhe ajudar... Sir Cedric, um aposentado cavaleiro de Aldoria, tempos atras cacava esse artefato maldito...\n Ele costumava ser o mais leal senhor da cidade. Hoje, ele decepciona o reino com sua ociosidade... Quando nao esta afogando suas magoas em uma taverna, ele geralmente toca musica pela praca da cidade.\"\n O Rei Tristan lhe entrega um mapa da cidade com a marcacao dos locais mencionados.\n\n E antes de partir, lhe fala: \"Cacador, perdoe-me por ofuscar um detalhe importante para sua jornada...\n Mas acredito que sei  quem rasgou a pagina...\n A ordem de Nocturia tambem a procura. Creio que eles desejam cumprir a profecia escura da triforca, juntando minha filha com o Lord Escuro deles e o poder da espada... Eles seriam indestrutiveis... E minha filha sera deles para sempre.\" \n\n\"Voce precisa impedir isso. A todo custo.\"\n\n Agora, voce se depara com uma escolha: partir para a taverna 'O Barril Dourado'(1) ou dirigir-se a praca da cidade para encontrar Sir Cedric.(2)", 300, 0, 0, 0);

    // ir a taverna
    inserir(&history, "Checkpoint 1.2.1\nVoce opta por seguir para a taverna \"O Barril Dourado\". Ao entrar, a atmosfera pesada e tensa da taverna o envolve. Os clientes sussurram e lancam olhares desconfiados em sua direcao. Voce avista um homem idoso, vestido como um cavaleiro, sentado em um banco alto, com uma bebida pela metade a sua frente. Parece ser Sir Cedric.\nCom cautela, voce se aproxima dele e se apresenta como o cacador de recompensas enviado pelo Rei Tristan em busca da espada \"Luminastra\". Sir Cedric olha para voce com olhos sombrios e um sorriso sinistro cruza seu rosto. Ele diz: \"AH, O CACADOR DE RECOMPENSAS ENVIADO PELO REI... PARECE QUE VOCE ESTA BUSANDO ALGO MUITO VALIOSO.\"\nSem aviso, ele se levanta abruptamente e tira o disfarce de Sir Cedric, na verdade ele era um cavaleiro da ordem Nocturia que fingia ser o Sir Cedric! Ele puxa uma espada escura e malevola de suas vestes, revelando sua verdadeira lealdade a Ordem de Nocturia. Ele se prepara para o ataque e diz: \"PREPARE-SE PARA A BATALHA CACADOR. VOCE NAO SAIRA DAQUI SEM LUTAR!\"\n", 202, 1, 0, 0);

    inserir(&history, "Checkpoint 1.2.1.1\nFIM DE JOGO!\n", 201, 0, -10000, 0);

    // ganhou o combate
    inserir(&history, "Checkpoint 1.2.1.2\nApos uma batalha intensa, voce emerge vitorioso, enquanto o cavaleiro, agora imobilizado, respira ofegante no chao poeirento. O som do metal ressoa, e a tensao paira no ar enquanto voce pondera sobre o proximo passo. A cena se desenrola em um cenario desolado, com destrocos de pedra e pocas d'agua criadas pela chuva que se desfez durante a batalha.\nOs olhos do cavaleiro, antes cheios de determinacao, agora mostram uma mistura de resignacao e desafio. Voce tem diante de si uma fonte potencial de informacoes valiosas que podem moldar o rumo da missao. No entanto, voce agora tem duas opcoes:\n(1) - questionar o cavaleiro utilizando as pocoes dele\n(2) - convencer o cavaleiro a te passar informacoes\n", 220, 0, 0, 0);

    // convencer o prisioneiro
    inserir(&history, "Checkpoint 1.2.1.2.2\nO cavaleiro permanece irredutivel, recusando-se a compartilhar informacoes vitais. No entanto, no auge da incerteza, Sir Cedric, figura que parecia perdida, irrompe na cena, seu corpo marcado por sinais de batalha recente. Com um semblante determinado, ele urgentemente declara: \"CACADOR, SOU O SIR CEDRIC, O REI ME ENVIOU PARA QUE EU TE AJUDE EM SUA JORNADA. HA MUITOS CAVALEIROS DA ORDEM DE NOCTURIA POR AQUI! PRECISAMOS PARTIR AGORA PARA O MONTE LUMINA, PELO DESFILADEIRO DAS TEMPESTADES!\"\nAs palavras de Sir Cedric, respaldadas por sua autoridade e a clareza da missao, ressoam no ar tenso. Ele se revela como um aliado inesperado, enviado pelo rei para apoiar a busca. Apesar do conhecimento de que o Caminho das Lagrimas Sagradas e o caminho mais perigoso, a necessidade de rapidez na busca pela espada torna essa rota a escolha mais pragmatica.\nNo entanto, ao alcancar o Monte Lumina, as esperancas sao obscurecidas pela presenca ameacadora de Azrathul, o Arauto do Fim, que emerge como o aliado principal da Ordem de Nocturia.\nAzrathul diz: VOCES CHEGARAM AO FIM!\nSEQUENCIA DE COMBATE INICIADA", 222, 1, 0, 0);

    inserir(&history, "Checkpoint 1.2.1.2.2.1\nFIM DE JOGO ", 221, 0, -10000, 0);
    
    inserir(&history, "Checkpoint 1.2.1.2.2.1\nApos uma batalha incrivel, voce deixa Azrathul, o Arauto do Fim, fraco, e agora o Arauto esta em seu proprio fim. Entretanto, ele usa suas ultimas forcas para desferir um golpe em voce. De repente, Sir Cedric surge diante de voce e se joga na sua frente para te salvar. Com suas ultimas palavras, ele diz: \"ACHE A ESPADA, SALVE O REINO.\"Voce deixa aquela para tras com remorso e segue viagem em direcao ao Monte Lumina.\n\nVoce avista uma luz, que te traz esperanca. A luz aparenta ser um guardiao. E o guardiao Raziel, o protetor da espada Luminastra!\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 230, 0, 0, 0);

    inserir(&history, "Checkpoint 1.2.1.2.1\nApos uma interrogacao intensa usando sua pocao de magia nocturina, o cavaleiro, agora enfraquecido pela sua propria magia, revela a localizacao da espada Luminastra. As palavras saem entrecortadas, ecoando onde a cena se desenrola.\nEle diz: \"NO MONTE LUMINA, SIGA O CAMINHO DAS LAGRIMAS SAGRADAS, ENCONTRE O GUARDIAO RAZIEL...\".\n\nAgora, voce possui duas escolhas: (1) -  Seguir em sua jornada \n(2) - Entregar o cavaleiro de Nocturia as autoridades", 210, 0, 1, 0);

    inserir(&history, "Checkpoint 1.2.1.2.1.2\nOs guardas reais levam o prisioneiro e voce segue para a trilha das Lagrimas Sagradas...\nDepois de passar por grandes desafios e dias de viagem, voce sente uma implacavel fome. Voce esta ha apenas algumas horas do Monte Lumina. Mas, guiado pela determinacao, voce avista uma fazenda proxima. A tentacao de pegar alguns alimentos e avassaladora. \nVoce se ve em duas opcoes: \n(1)- Tomar uma espiga de milho\n (2) - Continuar com fome e seguir viagem", 215, 0, 0, 0);

    // roubar a fazenda
    inserir(&history, "\nCheckpoint 1.2.2.2.2.1.1\nVoce cede ao instinto e se alimenta, recuperando seu HP.\n\nChegando ao topo Monte Lumina, voce visualiza um ser iluminado, e rapidamente uma aura de paz passa por voce. E o Guardiao Raziel, protetor da espada Luminastra, com sua aura divina, observa voce com olhos penetrantes. Sua escolha de tomar o milho nao passa despercebida, e a reacao do Guardiao Raziel e desconhecida. Pode ser que ele, como ser celestial, tenha percepcoes e julgamentos diferentes em relacao as acoes dos mortais.\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 212, 0, 1, 0);

    // seguir com fome e nao roubar a fazenda
    inserir(&history, "\nAo chegar ao Monte Lumina, voce se encontra fraco.\nEntretanto, ao avistar o Guardiao Raziel, protetor da espada Luminastra no topo, uma mudanca imediata ocorre. Uma aura de paz envolve voce, dissipando as sombras negativas. O Guardiao Raziel, com sua presenca divina, ilumina o ambiente ao seu redor, transformando a desesperanca em esperanca.\nA fome que o atormentava e a miseria que acompanhava cada passo se dissipam na presenca do Guardiao. A paz que emana dele traz alivio para seu corpo e alma cansados. E como se a luz divina do Guardiao Raziel tivesse o poder nao apenas de purificar, mas tambem de renovar e fortalecer aqueles que buscam redencao.\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...\n", 217, 0, 0, 0);

    inserir(&history, "Checkpoint 1.2.1.2.1.1\nVoce segue o caminho das lagrimas sagradas.\n\n No entanto, ao chegar la, uma descoberta terrivel aguarda!\n\nDiante de voce esta \"Azrathul, o Arauto do Fim\", aliado principal da ordem de Nocturia. Ele emerge das sombras, sua presenca imponente ecoando uma aura de destruicao. Azrathul e conhecido por sua maldade!.\n\nEle diz: \"SE PREPARE, CACADOR, SUA HORA CHEGOU, E O SEU FIM!\"", 203, 1, 0, 0);

    inserir(&history, "Checkpoint 1.2.1.2.1.1.1\nFIM DE JOGO!\n", 202, 0, -10000, 0);

    inserir(&history, "Checkpoint 1.2.1.2.1.1.2\nApos uma vitoria custosa, voce avanca em direcao ao Monte Lumina, enfrentando a exaustao que lhe assola.\n\n No entanto, a medida que alcanca o topo do Monte Lumina, uma transformacao notavel ocorre. Uma aura de alegria permeia o ambiente, e seu corpo e envolto em uma luz que transcende a escuridao circundante. Uma sensacao de renovacao toma conta de voce, proporcionando um alivio momentaneo da miseria que o acompanhou. \nO apice desse resplendor e revelado quando uma luz deslumbrante, como um farol celestial, emana do topo do monte, indicando a presenca do Guardiao Raziel, o protetor da espada Luminastra. Agora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...\n", 204, 0, 0, 0);

    // 1.2.2
    inserir(&history, "Checkpoint 1.2.2\nVoce opta por procurar Sir Cedric na praca da cidade, onde encontra um homem idoso vestido como um cavaleiro, tocando suavemente uma bela melodia em seu alaude, encantando os transeuntes. Com um aceno de cabeca, ele confirma que e, de fato, Sir Cedric.\nNo inicio, Sir Cedric parece desconfiado ao ouvir sobre sua missao e o pedido do Rei Tristan. No entanto, olhando nos seus olhos, ele percebe sua determinacao e compreende a gravidade da ameaca representada pela Ordem de Nocturia para o reino. Sir Cedric, ciente de que voce esta genuinamente comprometido em salvar a princesa Melinda, decide confiar em voce.\nEle revela a verdadeira localizacao da espada \"Luminastra\", no monte Lumina, uma elevacao majestosa na paisagem. Sir Cedric concorda em se unir a sua jornada, trazendo consigo sua habilidade musical e habilidades de combate como ex-cavaleiro. Ele tambem reforca:\n\"EXISTEM DOIS CAMINHOS POSSIVEIS PARA O MONTE LUMINA: A TRILHA DAS LAGRIMAS SAGRADAS, O CAMINHO MAIS RAPIDO E PERIGOSO, OU O DESFILADEIRO DA TEMPESTADE, MAIS LENTO E SEGURO.\"\nVoce se questiona a peculiaridade da escolha de tais nomes, mas segue em frente.\n\n Agora, voce se depara com uma escolha: (1) - ir para o Desfiladeiro da Tempestade\n(2) - ir para A Trilha das Lagrimas Sagradas", 350, 0, 0, 0);

    inserir(&history, "\nCheckpoint 1.2.2.2\nAo escolher o atalho da trilha das lagrimas sagradas, voce optou pela rota mais rapida, cortando caminho atraves das encostas ingremes e rochosas. Contudo, durante a ascensao desafiadora da trilha, voce se depara com uma presenca sinistra conhecida como \"AZRATHUL, O ARAUTO DO FIM\"\nA atmosfera ao redor se torna densa e pesada, indicando a presenca do mal que se aproxima. Voce e Sir Cedric preparam-se para o combate.\n\nEle diz a voce: NAO ESCAPARAS DE MIM CACADOR!", 352, 1, 0, 0);

    // morreu
    inserir(&history, "\nCheckpoint 1.2.2.2.1\nFIM DE JOGO\n", 351, 0, -10000, 0);
    // ganhou
    inserir(&history, "\nCheckpoint 1.2.2.2.2\nApos uma feroz batalha, voce deixa Azrathul, o Arauto do Fim, fraco.\nAgora o Arauto esta em seu proprio fim.\n Entretanto, ele usa suas ultimas forcas para desferir um golpe feroz em voce.\n De repente, Sir Cedric surge diante de voce e se joga na sua frente para te salvar.\nCom suas ultimas palavras ele diz: \"ACHE A ESPADA, SALVE O REINO.\" \n\nCom remorso, voce deixa aquela cena tras e segue viagem em direcao ao Monte Lumina, exausto e com fome apos uma cansada batalha, alem de entristecido pelo evento.\nNo caminho, voce avista uma estatua da Deusa Yamir, provedora dos alimentos e da alegria. Voce gostaria de parar para fazer uma oracao?(1) Seguir em frente\n(2) - Orar, pedindo boa sorte e alimento\n", 356, 0, 0, 0);

    // seguir em frente
    inserir(&history, "\n Ao ignorar a Deusa do alimento, e depois de passar por grandes desafios e dias de viagem, voce sente uma implacavel fome. Voce esta ha apenas algumas horas do Monte Lumina. Mas, guiado pela determinacao, voce avista uma fazenda proxima. A tentacao de pegar alguns alimentos e avassaladora. \nVoce se ve em duas opcoes: \n(1)- Tomar uma espiga de milho\n (2) - Continuar com fome e seguir a viagem", 354, 0, 1, 0);

    // tomar uma espiga de milho
    inserir(&history, "\nCheckpoint 1.2.2.2.2.1.1\nAo topo do Monte Lumina, voce visualiza um ser iluminado, e rapidamente uma aura de paz passa por voce. E o Guardiao Raziel, protetor da espada Luminastra, com sua aura divina, observa voce com olhos penetrantes.\n\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\n\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 353, 0, 1, 0);

    // seguir com fome e nao roubar a fazenda
    inserir(&history, "\nAo chegar ao Monte Lumina, voce se encontra exausto, mas ao avistar o Guardiao Raziel, protetor da espada Luminastra, no topo, uma mudanca imediata ocorre.\n Uma aura de paz envolve voce, dissipando as sombras da fome e da miseria.\n O Guardiao Raziel, com sua presenca divina, ilumina o ambiente ao seu redor, transformando a desesperanca em esperanca.\nA fome que o atormentava e a miseria que acompanhava cada passo se dissipam na presenca do Guardiao. A paz que emana dele traz alivio para seu corpo e alma cansados. E como se a luz divina do Guardiao Raziel tivesse o poder nao apenas de purificar, mas tambem de renovar e fortalecer aqueles que buscam redencao.\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\n\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...\n", 355, 0, 0, 0);

    // orar pedingo boa sorte a deusa
    inserir(&history, "Checkpoint 1.2.2.2.2.2\nVoce segue sua viagem, apos ter respeito pela estatua e orar por ela, e, de maneira surpreendente, encontra uma vila.\n\n Ao mencionar sua jornada em direcao ao Monte Lumina, os habitantes da vila ficam desconfiados e relutantes em compartilhar informacoes.\n\n A falta de confianca em voce e palpavel, pois eles temem os perigos que podem se desdobrar na trilha para o Monte Lumina.\nDiante dessa desconfianca, voce enfrenta duas opcoes:(1) - Persuadi-los\n(2) - Deixar a vila", 360, 0, 0, 0);

    // persuadi-los
    inserir(&history, "Checkpoint 1.2.2.2.2.2.1\nAo escolher persuadir os habitantes da vila de suas intencoes benevolentes, voce consegue romper a barreira da desconfianca. Explicando suas motivacoes e compartilhando as provacoes enfrentadas, voce ganha a confianca deles.\n\n Em resposta, eles revelam uma passagem secreta que parte da vila, prometendo leva-lo ao Monte Lumina enquanto o mantem longe de possiveis perigos.\n\nAo seguir essa passagem dissimulada, voce se encontra em uma jornada tranquila e segura em direcao ao monte.\n\n Chegando a base do Monte Lumina, uma sensacao de paz toma conta de voce. Enquanto sobe, uma luz brilhante emerge no topo, revelando a presenca do Guardiao Raziel, protetor da espada Luminastra.\n\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial!\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 359, 0, 1, 0);

    // deixar a vila
    inserir(&history, "Checkpoint 1.2.2.2.2.2.2\nAo escolher deixar a vila, voce abandona possiveis informacoes importantes para sua batalha final, ainda deixando um rastro de desconfianca em seu caminho...\n\n Claramente o povo da vila nao acredita muito nos cacadores de recompensa, e seu KARMA nao e tao bom...\n\n  De repente, voce escuta um chamado da luz:\n\n \"AVENTUREIRO... SIGA MINHA VOZ.\"\n\n Apos dias seguindo seu celestial chamado, voce chega no monte Lumina, mas uma sensacao de desconforto persiste em voce. A medida que voce sobe, uma luz brilhante emerge no topo, revelando a presenca do Guardiao Raziel.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 361, 0, 0, 0);

    inserir(&history, "Checkpoint 1.2.2.1\nAo escolher o \"Desfiladeiro da Tempestade\", voce segue o caminho sinuoso ate a vila local que margeia essa trilha. Contudo, ao chegar, e recebido por uma cena desoladora: a vila esta em ruinas, completamente destruida pelos cavaleiros da Ordem de Nocturia que tambem buscam o poder da espada de Luminastra.\n\nEm meio ao caos, voce percebe um campones indefeso sendo atacado por um cavaleiro sombrio da Ordem. Determinado a proteger os inocentes e enfrentar a ameaca da Ordem de Nocturia, voce parte rapidamente para o socorro do campones. O confronto e inevitavel, e a batalha se desenrola em meio as ruas devastadas da vila!\n", 325, 1, 0, 0);

    inserir(&history, "\nFIM DE JOGO\n", 324, 0, -10000, 0);

    inserir(&history, "Checkpoint 1.2.2.1.2.1\nO campones agradecido, ainda ofegante do que sofreu, detalha o atalho que conhece para o Monte Lumina. Ele menciona uma trilha secreta, escondida nas profundezas da floresta adjacente a vila, que serpenteia por entre arvores antigas e riachos cristalinos.\n\n Esse caminho menos percorrido, conhecido apenas pelos locais, oferece uma rota mais rapida para o Monte Lumina, evitando as estradas principais que poderiam estar sob vigilancia da Ordem de Nocturia.\nO campones ressalta a importancia de seguir as marcas naturais no caminho, como pedras marcadas e arvores especificas, para nao se perder nas entranhas da floresta. Ele destaca que o atalho, embora mais rapido, tambem e repleto de desafios naturais, como terrenos irregulares e a possibilidade de encontrar criaturas selvagens.\nAgora, voce tem duas opcoes: (1) - seguir o atalho do aldeao\n(2) - continuar por sua trilha\n", 337, 0, 0, 0);

    // decidi continuar por minha trilha
    inserir(&history, "Checkpoint 1.2.2.1.2.1.2\nRejeitando o atalho do campones, voce opta por seguir o caminho normal, adentrando uma paisagem que revela os horrores provocados pelo exercito de Nocturia. A medida que avanca, encontra um cenario aterrorizante: florestas outrora exuberantes agora estao destruidas, arvores retorcidas e rios poluidos, testemunhando a crueldade infligida pela Ordem.\nEm meio a escuridao da noite, surge um dilema diante de voce. A distancia, voce avista um pequeno acampamento de refugiados que buscam abrigo da tirania da Ordem de Nocturia. Voce se lembra que cavaleiros de Nocturia podem fingir ser outras pessoas utilizando sua magia negra. Eles clamam por ajuda, desesperados por protecao e orientacao. Agora, voce tem duas opcoes cruciais:\n(1) - Confiar nos refugiados\n(2) - Por medo dos cavaleiros, seguir em frente.\n", 344, 0, 0, 0);

    // decidi continuar sem intervencao
    inserir(&history, "Checkpoint 1.2.2.1.2.1.2.2\nAo optar por cacar a Luminarca e ganhar poder, voce se sente fortalecido pela criatura rara, seu corpo pulsando com uma energia renovada.\n\n No entanto, a medida que voce e Sir Cedric se aproximam do Monte Lumina, a aura misteriosa da floresta cede lugar a um ambiente mais sombrio e tenso.\nAo alcancar o Monte Lumina, voce depara-se com uma cena inesperada: um dos lideres do exercito da Ordem de Nocturia esta presente, liderando uma busca pelo mesmo artefato, a espada \"Luminastra\". Sir Cedric, percebendo a ameaca iminente, sugere que voce corra para o monte e busque a espada enquanto ele fica para atrasar o cavaleiro.\nVoce enfrenta uma nova decisao: (1) - ficar e proteger Sir Cedric\n(2) - buscar a espada", 348, 0, 0, 10);

    // decidi buscar a espada
    inserir(&history, "Checkpoint 1.2.2.1.2.1.2.2.2\nAo escolher buscar a espada, voce ignora Sir Cedric enfrentando os cavaleiros da Ordem sozinho. Ao chegar ao topo do Monte Lumina, uma visao terrivel segue a distancia: Sir Cedric foi capturado pelos cavaleiros!.\nA impotencia da situacao pesa em seu coracao.\nA dor emocional e profunda, mas voce sabe que focar em sua missao e essencial para honrar seu leal companheiro.\nAcima da montanha, revela-se um ser mitico, o Guardiao Raziel, protetor da espada \"Luminastra\". Agora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 349, 0, 1, 0);

    inserir(&history, "Checkpoint 1.2.2.1.2.1.2.2.1\nVoce opta por ficar e proteger o Sir Cedric.\nSir Cedric diz para voce com tom de raiva, mas tambem de alivio: PARA UM CACADOR DE RECOMPENSAS VOCE NAO E TAO ESPERO!HAHAH, DEVERIA TER IDO BUSCAR A ESPADA!", 346, 1, 0, 0);
    
    inserir(&history, "Checkpoint 1.2.2.1.2.1.2.2.1.1FIM DE JOGO!\n", 345, 0, -10000, 0);
    inserir(&history, "Checkpoint 1.2.2.1.2.1.2.2.1.2\nA batalha continua ardua, cada movimento e uma danca perigosa. O cavaleiro da Ordem de Nocturia mantem sua ferocidade, desferindo ataques poderosos.\n O combate atinge um apice quando, de repente, Sir Cedric, mesmo gravemente ferido, surge diante de voce. Com bravura, ele enfrenta o ataque do cavaleiro, retribuindo com golpes determinados.\nEm meio aos clamores da batalha, Sir Cedric, com voz alta e clara, pronuncia palavras que ecoam no campo de luta: \"CONSIGA A ESPADA. VOCE E O ESCOLHIDO. VOCE DEVE SALVAR A PRINCESA E SALVAR O REINO.\" Sir Cedric cai no chao desmaiado junto com os cavaleiros, ambos tranformados em po, como os cavaleiros se transformam apos uma derrota, algo que decorre de sua magia negra.\n\n A cena te arrepia, mas voce segue com uma fusao de tristeza e determinacao.\n\n voce chega ao topo do Monte Lumina, carregando as memorias de toda sua jornada.\n\n. Ao chegar ao cume, uma luz iluminada, um ser transcendental, recebe voce. E o Guardiao Raziel, guardiao da espada Luminastra, trazendo um lampejo de esperanca em meio a escuridao.\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 347, 0, 0, 0);

    // decidi nao seguir o atalho do aldeao
    inserir(&history, "Checkpoint 1.2.2.1.2.1.2.1\nVoce decide que e uma armadilha, e desvia do caminho principal para se aproximar do acampamento. A medida que se aproxima, o cenario revela-se ainda mais desolador.O ar esta impregnado com a tensao palpavel da opressao imposta pela Ordem de Nocturia.\nEnquanto voce se apresenta como um defensor do reino, os refugiados compartilham historias angustiantes sobre os abusos que sofreram. Em meio a esses relatos, voce percebe que um cavaleiro da Ordem esta se aproximando, ciente de sua presenca na area.\nEle diz: \"FINALMENTE ENCONTREI VOCE, CACADOR... ESPEREI MUITO POR ESTA BATALHA!!\"\n\n\n", 341, 1, 0, 0);
    inserir(&history, "FIM DE JOGO!", 340, 0, -10000, 0);
    inserir(&history, "\nApos a intensa batalha, os refugiados expressam profunda gratidao. Consciente da necessidade continua de ajuda, Sir Cedric observa a destruicao ao redor e toma uma decisao corajosa. Ele se oferece para ficar e ajudar os refugiados, comprometendo-se a ser o apoio necessario enquanto voce segue sozinho em direcao ao Monte Lumina.\nDespedindo-se de Sir Cedric, voce continua sua jornada, carregando consigo as cicatrizes da batalha e o peso das escolhas dificeis. Ao chegar ao Monte Lumina, um sentimento de isolamento se instala, mas sua determinacao permanece inabalavel. No topo, voce encontra o Guardiao Raziel, guardiao da espada Luminastra, uma presenca iluminada em meio a escuridao que envolve o reino.\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 342, 0, 0, 0);

    // decidi seguir o atalho do aldeao
    inserir(&history, "Checkpoint 1.2.2.1.2.1.1\nAo seguir o atalho do campones, voce e Sir Cedric exploram um caminho misterioso na floresta, cercado pela densa vegetacao e iluminado apenas pela luz filtrada pelas copas das arvores. Durante essa jornada, voce se depara com uma criatura rara, cuja presenca e quase mitologica na regiao.\nEsta criatura, conhecida como \"Luminarca\", e uma especie de ser etereo com pele resplandecente. Enquanto observa a criatura, Sir Cedric percebe que a carne dela tem propriedades especiais. Sir Cedric sugere que, se consumir a carne da Luminarca, voce pode ganhar forca adicional.\nAgora, voce tem duas opcoes: (1) - seguir a criatura para ganhar poder (aumente seu HP maximo em 10)\n(2) - seguir viagem e permitir que o ser misterioso viva livre.\n", 333, 0, 0, 0);

    // decidi matar a criatura
    inserir(&history, "Checkpoint 1.2.2.1.2.1.1.1\nAo optar por seguir a Luminarca e ganhar poder, voce se sente fortalecido pela criatura rara, seu corpo pulsando com uma energia renovada. No entanto, a medida que voce e Sir Cedric se aproximam do Monte Lumina, a aura misteriosa da floresta cede lugar a um ambiente mais sombrio e tenso.\nAo alcancar o Monte Lumina, voce depara-se com uma cena inesperada: um dos lideres do exercito da Ordem de Nocturia esta presente, liderando uma busca pelo mesmo artefato, a espada \"Luminastra\". Sir Cedric, percebendo a ameaca iminente, sugere que voce corra para o monte e busque a espada enquanto ele fica para atrasar o cavaleiro.\nVoce enfrenta uma nova decisao: (1) - ficar e proteger Sir Cedric\n(2) - buscar a espada", 329, 0, 1, 10);

    // decidi nao matar a criatura
    inserir(&history, "Checkpoint 1.2.2.1.2.1.1.2\nAo optar por nao perseguir a  criatura, um elo de simpatia se forma entre voces, e ela decide juntar-se a jornada. Agora, acompanhado pela Luminarca e Sir Cedric, voces avancam pela trilha em busca da preciosa espada Luminastra. O cenario ao redor revela um rastro devastador deixado pelos Cavaleiros da Ordem de Nocturia. Entretanto, ao avistar uma luz, um sentimento de alegria e uma aurea de felicidade despertam em voces. A luz e o Guardiao Raziel, protetor da espada Luminastra.\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...\n", 334, 0, 0, 0);

    // decidi ficar e proteger o sir cedric
    inserir(&history, "Checkpoint 1.2.2.1.2.1.1.1.1\nVoce opta por ficar e proteger o Sir Cedric.\nSir Cedric diz para voce com tom de raiva, mas tambem de alivio: PARA UM CACADOR DE RECOMPENSAS VOCE NAO EH TAO ESPERO, HAHAH. DEVERIA TER IDO BUSCAR A ESPADA!\nMas, de repente o cavaleiro ataca voces.\nSEQUENCIA DE COMBATE INICIADA", 327, 1, 0, 0);
    
    inserir(&history, "Checkpoint 1.2.2.1.2.1.1.1.1.1\nFIM DE JOGO!\n", 326, 0, -10000, 0);
    inserir(&history, "Checkpoint 1.2.2.1.2.1.1.1.1.1\nA batalha continua ardua, cada movimento e uma danca perigosa. O cavaleiro da Ordem de Nocturia mantem sua ferocidade, desferindo ataques poderosos. O combate atinge um apice quando, de repente, Sir Cedric, mesmo gravemente ferido, surge diante de voce. Com bravura, ele enfrenta o ataque do cavaleiro, retribuindo com golpes determinados.\nEm meio aos clamores da batalha, Sir Cedric, com voz alta e clara, pronuncia palavras que ecoam no campo de luta: \"CONSIGA A ESPADA. VOCE E O ESCOLHIDO. VOCE DEVE SALVAR A PRINCESA E SALVAR O REINO.\" Sir Cedric cai no chao junto com os cavaleiros, desmaiado. Estes estao ambos tranformados em po, como transforma-se todos os cavaleiros de nocturia, apos uma derrota, algo decorrente de sua magia negra.\n\n A cena te arrepia, mas voce segue com uma mistura de tristeza e determinacao.\n\n voce chega ao topo do Monte Lumina, carregando as memorias de toda sua jornada\n\n. Ao chegar ao cume, uma luz iluminada, um ser transcendental, recebe voce. E o Guardiao Raziel, guardiao da espada Luminastra, trazendo um lampejo de esperanca em meio a escuridao.\nAgora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 328, 0, 0, 0);

    // decidi fugir
    inserir(&history, "Checkpoint 1.2.2.1.2.1.2.2.2\nAo escolher buscar a espada, voce ignora deixar Sir Cedric enfrentando os cavaleiros da Ordem sozinho. Ao chegar ao topo do Monte Lumina, uma visao terrivel segue a distancia: Sir Cedric foi capturado pelos cavaleiros!.\nA impotencia da situacao pesa em seu coracao.\nA dor emocional e profunda, mas voce sabe que focar em sua missao e essencial para honrar seu leal companheiro.\nAcima da montanha, revela-se um ser mitico, o Guardiao Raziel, protetor da espada \"Luminastra\". Agora, diante dessa entidade celestial, sua missao atinge um ponto crucial.\nSeus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 330, 0, 1, 0);
    
    while (1) {
        karma = 0;
        hpPlayer = 20;

        clear();
 
        printf("\033[1;33m /   /   /   /   /   /   /   /   /   /   /\n");
        printf("/   /   /   /   /   /   /   /   /   /   /   /\n");
        printf("A   N   D   O   R   I   A\n");
        printf(" /   /   /   /   /   /   /   /   /   /   /   /\n");
        printf("/   /   /   /   /   /   /   /   /   /   /   /\n\033[0m");
        
        printf("\033[1;37;3m1 - Entrar no jogo\n");
        printf("2 - Visualizar ultima trajetoria\n");
        printf("3 - Historias passadas\n");
        printf("4 - Sair\033[0m\n");

        Oponente oponente;

        FILE *file;
        file = fopen("historico.txt", "r");
        if (file == NULL) {
            file = fopen("historico.txt", "w");
            if(file == NULL){
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }
        }

        char playerName[100];
        int node;

        while (fscanf(file, "%99[^-] - %d\n", playerName, &node) == 2) {
            insertPlayers(&head, playerName, node);
            idLastNode = node;
        }

        fclose(file);

        bubblesortByName(&head);

        printf("\033[1;33;3mEscolha uma opcao: \033[0m");
        scanf("%d", &opcao);

        switch (opcao) { 
            
            case 1:


                while ((c = getchar()) != '\n' && c != EOF);

                printf("Jogador, informe o seu nome: ");
                fgets(jogador, sizeof(jogador), stdin);
                
                jogador[strcspn(jogador, "\n")] = '\0';

                 clear();
                system("color 0E");
                 printf("Para a visibilidade de todo o texto, sugerimos aumentar o tamanho do terminal\n");
                 sleep(4);
                 clear();
                 printf("DESESPERO!\n");
                 sleep(2);
                 printf("Em meio a escuridao da noite, no majestoso reino de Andoria, um ato nefasto abalou a tranquilidade do humilde povo!\n");
                 sleep(5);
                 printf("A destemida PRINCESA MELINDA, herdeira do trono, foi capturada por uma forca maligna conhecida como A ORDEM DE NOCTURIA , Deixando o reino inteiro a beira do abismo!\n");
                 sleep(5);
                 printf("Desesperado, o sabio REI TRISTAN convoca o mais improvavel dos herois, alguem destinado a trazer a luz de volta a sua amada terra.\n");
                 sleep(5);
                 printf("Voce, o ultimo raio de esperanca do reino, um CACADOR DE RECOMPENSA e dado poder de cavaleiro pelo rei e convocado a embarcar em uma jornada epica...\n");
                 sleep(16);
                 clear();
                 sleep(1);
                 system("color 0F");
                

                idLastNode = game(&history);

                if(karma < 0) printf ("\n\nJOGUE NOVAMENTE!\n"); // aqui eh caso o usuario tenha perdido um combate
                else if(karma >= 2){
                    if(karma < 1000){
                        printf("\n\nVOCE TOMOU %d DECISOES ERRADAS DURANTE SUA TRAJETORIA, %s! VOCE NAO CONSEGUIU A ESPADA!\nPressione qualquer tecla para continuar...", karma, jogador);
                        // aqui eh caso o usuario tenha tomado decisoes erradas e karma > 2, nao ganha espada
                    } else if (karma < 3000) {
                        printf("\n\n Voce chega ao Monte Lumina!\n Prepare-se para o boss final, %s!", jogador);
                        sleep(5);
                        clear();
                        Oponente GuardiaoRaziel;    
                        GuardiaoRaziel.hp = 999;
                        strcpy(GuardiaoRaziel.nome, "Guardiao Raziel");        
                        if(combatfinal(hpPlayer,GuardiaoRaziel)){
                            clear();
                            sleep(2);
                            printf("YOU WIN! Pressione qualquer tecla para continuar...");
                            fflush(stdout);
                            sleep(10);
                        }
                        else{
                            printf("YOU LOSE! Pressione qualquer tecla para continuar...");
                            fflush(stdout);
                            sleep(10);
                        }
                    }else{
                        printf("\n\n Voce chega a Floresta de Nocturia!\n Prepare-se para o boss final, %s!", jogador);
                        sleep(5);
                        clear();
                        Oponente LordMorgator;    
                        LordMorgator.hp = 999;
                        strcpy(LordMorgator.nome, "Lord Morgator");        
                        if(combatfinal(hpPlayer,LordMorgator)){
                            clear();
                            sleep(2);
                            printf("YOU WIN! Pressione qualquer tecla para continuar...");
                            fflush(stdout);
                            sleep(10);
                        }
                        else{
                            printf("YOU LOSE! Pressione qualquer tecla para continuar...");
                            fflush(stdout);
                            sleep(10);
                        }
                    }
                } else {
                    // aqui eh o final normal. karma >= 0 e karma < 2. ganha espada
                    printf("\n\nPARABENS, %s! VOCE TOMOU BOAS DECISOES E CONSEGUIU A ESPADA!\n\n ", jogador);
                    printf("\033[1;33m"); // Set text color to gold
                     printf("\033[1;33m"); // Set text color to gold
                    printf("\n\
                                                       /\\ \n\
                                                      |  |\n\
                                                      |  |\n\
                                                      |  |\n\
                                            /\\        |  |\n\
                                            /  \\      |  |\n\
                                           |----|     |  |\n\
                                            \\  /      |  |\n\
                                            \\/        |  |\n\
                                                      |  |\n\
                                                      |  |\n\
                                                      |  |\n\
                                                  ____________\n\
                                                      |  |\n\
                                                      |  |\n\
                                                      |  |\n\
                                                     _____\
                                        \n\
                                        ");
                    printf("\033[0m"); // Reset text color to default
                    sleep(7);
                    printf("Voce chega ao castelo de Eldia! Prepare-se para o boss final, %s!\n", jogador);
                    sleep(3);
                    clear();
                    Oponente DragaoRelgar;    
                    DragaoRelgar.hp = 999;
                    strcpy(DragaoRelgar.nome, "Dragao Relgar");        
                    if(combatfinal(hpPlayer,DragaoRelgar)){
                            clear();
                            sleep(2);
                            printf("YOU WIN! Pressione qualquer tecla para continuar...");
                            sleep(5);
                        }
                        else{
                            sleep(2);
                            clear();
                            printf("YOU LOSE! Pressione qualquer tecla para continuar...");
                            sleep(5);
                        }
                }

                FILE *file;
                file = fopen("historico.txt", "a");
                if (file == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                // Escreve a string jogador no arquivo
                fprintf(file, "%s - %d\n", jogador, idLastNode);

                fclose(file);

                getch();
                break;
            case 2:
                clear();
                if(idLastNode == -1) printf("Nenhum jogo registrado...\n");
                else busca(history, idLastNode);
                printf("\nPressione qualquer tecla para continuar...\n");
                getch();
                break;
            case 3:
                clear();
                printf("Voce escolheu historias passadas.\n");

                printLastPlayers(head);

                printf("\033[1;33;3mEscolha o codigo ao lado do jogador que voce deseja visualizar sua trajetoria: \033[0m");
                scanf("%d", &codigo);

                busca(history, codigo);

                getch();

                break;
            case 4:
                printf("Voce escolheu sair do jogo. Ate logo!\n");
                libere(history);
                return 0;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }
    return 0;
}

void busca(Arv *aux, int n) {
    clear();
    printf("%s\n", aux->texto);
    if (aux == (Arv *)NULL)
        return;
    if (aux->id == n)
        return;
    if (n < aux->id){
        printf("\033[1;33;3m\nPRESSIONE QUALQUER TECLA PARA VER SEU PROXIMO PASSO!\033[0m\n");
        getch();
        busca(aux->esq, n);
    }else{
        printf("\033[1;33;3m\nPRESSIONE QUALQUER TECLA PARA VER SEU PROXIMO PASSO!\033[0m\n");
        getch();
        busca(aux->dir, n);
    }

}

void inserir(Arv **t, char* texto, int id, int combatFlag, int karma, int hpIncrease) {
    if (*t == NULL) {
        *t = (Arv *)malloc(sizeof(Arv));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->id = id;
        (*t)->texto = (char*) malloc(strlen(texto)+1);
        strcpy((*t)->texto, texto);
        (*t)->combatFlag = combatFlag;
        (*t)->karma = karma;
        (*t)->hpIncrease = hpIncrease;
    } else {
        if (id < (*t)->id) {
            inserir(&(*t)->esq, texto,id,combatFlag, karma, hpIncrease);
        }
        if (id > (*t)->id) {
            inserir(&(*t)->dir,texto, id,combatFlag, karma, hpIncrease);
        }
    }
}

int game(Arv **t){
    int lastVisitedNode = -1;
    Oponente elfo;
    elfo.hp = 8;
    strcpy(elfo.nome,"Inimigo");
    if(*t != NULL){
        printf("\033[1;34m%s\033[0m\n", (*t)->texto);
        if((*t)->karma) karma = karma + (*t)->karma;
        if((*t)->hpIncrease) hpPlayer = hpPlayer + (*t)->hpIncrease;
        if ((*t)->combatFlag == 1){
            printf("\nPREPARE-SE PARA COMBATE\n");
            if(combat(hpPlayer, elfo, 1)){
                lastVisitedNode = game(&((*t)->dir));
            }else{
                lastVisitedNode = game(&((*t)->esq));
            }
        } else if((*t)->esq != NULL || (*t)->dir != NULL){
            //sleep(6);
            printf("\n");
            printf("\033[1;32mHP atual: %d\033[0m", hpPlayer);
            printf("\033[1;3;5m\nINSIRA SUA ESCOLHA: \033[0m");

            do{
                scanf("%d", &choice);
                if(choice != 1 && choice != 2) printf("\033[1;33;3m\nCOMANDO INVALIDO! INSIRA SUA ESCOLHA NOVAMENTE: \033[0m");
            } while (choice != 1 && choice != 2);
    
            if(choice == 1){
                clear();
                //sleep(1);
                lastVisitedNode = game(&((*t)->esq));
            } else {
                clear();
                //sleep(1);
                lastVisitedNode = game(&((*t)->dir));
            }
        } else {
            printf("\033[1;33;3m\n\033[3m\033[33mFIM DO JOGO INTERATIVO!\033[0m\n\n\033[1;33;3mPRESSIONE QUALQUER TECLA PARA CONTINUAR\033[0m");
            getch();
            lastVisitedNode = (*t)->id;
        }
        return lastVisitedNode;
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
int combat (int seuHp, Oponente oponente, int waitFlag){
    if (waitFlag == 1){
        sleep(30);
     
    }
    else{
     sleep(2);
    }
    
    clear();
    int numeroAleatorio;
    int danoTomado,hpRecuperado;
    int defesa;
    int acao; 

    char vetorDialogo[9][100] = {
            "%s rosnando, pronto para o proximo ataque, te encara com intensidade.\n\n",
            "Com um olhar feroz, %s se prepara para lancar seu proximo ataque.\n\n",
            "%s mantem seu olhar fixo em voce, antecipando o proximo confronto.\n\n",
            "Voce ve %s respirando profundamente, se preparando para o proximo golpe.\n\n",
            "Os olhos de %s brilham com determinacao enquanto ele se prepara para atacar novamente.\n\n",
            "Com um grunhido ameacador, %s se prepara para mais um round de combate.\n\n",
            "%s mantem sua postura, observando cada um de seus movimentos atentamente.\n\n",
            "Voce sente a tensao no ar enquanto %s se prepara para o proximo ataque.\n\n",
            "%s parece imperturbavel, pronto para desferir outro golpe poderoso.\n\n"
    };
    while (seuHp>0){
            system("color 0C");
            
            if (oponente.hp<=0){
              sleep(3);
              clear();
              printf("BATALHA GANHA!\n\n");
              sleep(3);
              clear();
                hpPlayer = seuHp;
                system("color 0F"); 
              return 1;
            }      
            
            system("color 0A");
            printf("Seu HP:%d\n",seuHp);
            system("color 0C");
            printf("Hp inimigo: %d\n\n",oponente.hp); 
                 
            char dialogoPersonalizado[300];
            numeroAleatorio = gerarNumeroAleatorio(0,8);
            sprintf(dialogoPersonalizado, vetorDialogo[numeroAleatorio],oponente.nome);
            printf("%s",dialogoPersonalizado);
            time_t tempoInicial = time(NULL); 
            sleep(4);
            printf("Rapidamente! Qual a sua acao? 1: ataque 2: defesa\n\n ");
            
            do{
                scanf("%d",&acao);
                if(acao != 1 && acao != 2) printf("Comando invalido! Digite novamente: ");
            } while(acao!=1 && acao!=2); 

            clear();                    
            time_t tempoFinal = time(NULL);
            double tempoDecorrido = difftime(tempoFinal, tempoInicial);
            if (tempoDecorrido <= 11.0) {
                switch (acao){
                    case 1:
                        danoTomado = gerarNumeroAleatorio(1,10);
                        printf("Voce atacou o inimigo com sucesso, gerando %d de dano!\n", danoTomado);
                        oponente.hp = oponente.hp - danoTomado;
                        break;
                    case 2:
                        defesa = gerarNumeroAleatorio(-1,1);
                        danoTomado = gerarNumeroAleatorio(3,5);
                        hpRecuperado = gerarNumeroAleatorio (1,10);
                        if (defesa){
                            printf("Voce defendeu com sucesso e recuperou %d de hp\n",hpRecuperado);
                            seuHp = seuHp+hpRecuperado;
                        }else{
                            printf("Voce falhou na sua defesa, e perdeu %d de hp\n", danoTomado);
                            seuHp = seuHp - danoTomado;
                        }
                        break;
                    default:
                        printf("Comando invalido!\n");  
                        break;              
                }if (!defesa){
                    danoTomado = gerarNumeroAleatorio(3,8);
                    printf("Agora e a vez do inimigo!\n Voce perdeu %d de hp!",danoTomado );
                    seuHp = seuHp- danoTomado;

            } else {
                 danoTomado = gerarNumeroAleatorio(3,6);
                 printf("Vez do inimigo! o oponente ataca! voce perde %d de hp \n", danoTomado);
                 seuHp = seuHp - danoTomado;
            }
        }else{
              danoTomado = gerarNumeroAleatorio(3,8);
              printf("Voce nao atacou a tempo! O oponente desfere um golpe poderosol!\n");
              seuHp = seuHp - danoTomado;
        } 
    }
    if (seuHp<0){
        sleep(3);
        clear();
        printf("BATALHA PERDIDA!\n\n");
        sleep(3);
        clear();
        hpPlayer = seuHp;
        system("color 0F"); 
        return 0;
    }
}

void printLastPlayers(Players *head) {
    while (head != NULL) {
        printf("%s - %d\n", head->nome, head->idLastNode);
        head = head->next;
    }
}

void insertPlayers(Players **head, const char *nome, int idLastNode) {
    Players *newPlayer = (Players *)malloc(sizeof(Players));
    if (newPlayer == NULL) {
        printf("Erro ao alocar memória para novo jogador.\n");
        return;
    }

    strncpy(newPlayer->nome, nome, sizeof(newPlayer->nome) - 1);
    newPlayer->nome[sizeof(newPlayer->nome) - 1] = '\0'; //a string eh terminada adequadamente
    newPlayer->idLastNode = idLastNode;
    newPlayer->next = NULL;

    if (*head == NULL) {
        *head = newPlayer;
    } else {
        Players *aux = *head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newPlayer;
    }
}

void bubblesortByName(Players **head) {
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return; //lista vazia ou com um único elemento, não precisa ordenar
    } else {
        int swapped;
        Players *temp = NULL;
        do {
            swapped = 0;
            Players *current = *head;
            while (current->next != NULL) {
                if (strcmp(current->nome, current->next->nome) > 0) {
                    char tempNome[100];
                    strcpy(tempNome, current->nome);
                    strcpy(current->nome, current->next->nome);
                    strcpy(current->next->nome, tempNome);
                    swapped = 1;
                }
                current = current->next;
            }
        } while (swapped);
    }
}

int combatfinal(int seuHp, Oponente oponente) {
      int numeroAleatorio;
      int danoTomado, hpRecuperado;
      int defesa;
      int acao;
      char vetorDialogo[9][200]; 
      char golpeEspecial[100];
      char passwordEscolhido[10];
  
      if (strcmp(oponente.nome, "Dragao Relgar") == 0) {
            strcpy(golpeEspecial, "Voce aponta a espada Luminastra para o dragao, e um raio de luz sai dela, deixando ele fraco!\n\n");
            const char* relgarDialogo[] = {
                "Relgar solta um rugido poderoso, suas chamas crepitam ao redor dele.\n\n",
                "A furia ardente de Relgar se manifesta em seu olhar penetrante...\n\n",
                "Relgar encara voce com intensidade, as chamas refletindo em seus olhos.\n\n",
                "Voce ve Relgar inspirando profundamente, preparando-se para desferir chamas poderosas.\n\n",
                "Voce escuta a Princesa Melinda lhe encorajando, lhe enchendo de determinacao!.\n\n",
                "Com um rugido estrondoso, Relgar se prepara para mais uma investida.\n\n",
                "Relgar mantem sua postura majestosa, observando cada um de seus movimentos atentamente.\n\n",
                "Voce sente o calor intenso no ar enquanto Relgar se prepara para o proximo sopro de fogo.\n\n",
                "Enquanto o dragao lhe encara com intensidade, a princesa lhe encara com esperanca.\n\n"
            };

            for (int i = 0; i < 9; ++i) {
            strcpy(vetorDialogo[i], relgarDialogo[i]);
    }
} else if (strcmp(oponente.nome, "Guardiao Raziel") == 0) {
         strcpy(golpeEspecial, "Voce cria um feitico nocturino que ataca o Guardiao, deixando ele fraco!\n\n");
    const char* razielDialogo[] = {
        "Raziel, o Guardiao Celestial, te encara com decepcao em seus olhos.\n\n",
        "Com um olhar celestial feroz, Raziel se prepara para lancar seu proximo ataque.\n\n",
        "Raziel mantem seu olhar divino fixo em voce, expressando desapontamento pelo caminho que voce escolheu.\n\n",
        "Voce ve Raziel respirando profundamente, seu semblante celestial demonstrando tristeza pelo seu desvio.\n\n",
        "Os olhos divinos de Raziel brilham com determinacao, mas tambem com um toque de tristeza, enquanto ele se prepara para atacar novamente.\n\n",
        "Com um suspiro celestial, Raziel se prepara para mais um round de combate, lamentando a sua queda.\n\n",
        "Raziel mantem sua postura celestial, observando cada um de seus movimentos com uma expressao de desaprovacao.\n\n",
        "Voce sente a tensao no ar, misturada com a tristeza divina de Raziel, enquanto ele se prepara para o proximo ataque.\n\n",
        "Raziel parece imperturbavel, mas seus olhos refletem a decepcao por suas escolhas, pronto para desferir outro golpe, esperando que voce mude de rumo.\n\n"
    };

    for (int i = 0; i < 9; ++i) {
        strcpy(vetorDialogo[i], razielDialogo[i]);
    }
} else {
        strcpy(golpeEspecial, "Voce convoca reforcos do exercicito real, que atacam Lord Morgator, deixando-o fraco!\n\n");
    const char* morgatorDialogo[] = {
        
        "Diante de voce esta Lord Morgator, o Mago das Trevas, cujos olhos lancam faiscas de magia negra, pronto para dancar com o destino.\n\n",
        "Um olhar sombrio domina o rosto de Lord Morgator, enquanto ele acena com as maos, invocando sombras para seu proximo truque.\n\n",
        "A presenca imponente de Lord Morgator encara voce, sua figura envolta em um manto de misterio, antecipando o confronto iminente.\n\n",
        "Observando com astucia, voce ve Lord Morgator respirar profundamente, alimentando-se da energia das trevas para lancar seu feitico.\n\n",
        "Os olhos hipnoticos de Lord Morgator brilham com a promessa de poder enquanto ele se prepara para entrelacar a magia negra em seu proximo ataque.\n\n",
        "Com um sussurro soturno, Lord Morgator se prepara para mais uma danca entre as sombras, desencadeando sua magia sinistra.\n\n",
        "A postura majestosa de Lord Morgator projeta uma aura de dominio, enquanto seus olhos observam cada movimento seu, desvendando seus segredos.\n\n",
        "Voce sente a magia pulsante no ar, carregada com a intencao malevola de Lord Morgator, enquanto ele se prepara para lancar um feitico sombrio.\n\n",
        "Lord Morgator parece imperturbavel, as sombras ao seu redor dancam em harmonia com sua vontade, prestes a desferir um feitico que ecoara pelas eras.\n\n"
    };


    for (int i = 0; i < 9; ++i) {
        strcpy(vetorDialogo[i], morgatorDialogo[i]);
    }
        
    }
    char passwordArray [3][10] = {"ataque","golpe","impacto"};
    while (seuHp>0){
            system("color 0D");
            if (oponente.hp<=0){
              sleep(2);
              printf("Antes do seu fim, %s invoca 2 suditos com sua ultima faisca de poder! Eles lentamente se aproximam de voce...",oponente.nome);
              Oponente sudito;
              strcpy(sudito.nome ,"Sudito");
              sudito.hp = 7;
              sleep(6);
              clear();
              if (combat(10,sudito,0)){
                if(combat(10,sudito,0)){
                  system("color 0F");
                  return 1;
                }
                else{
                  system("color 0F");
                  return 0;
                }
              }else{
                system("color 0F");
                return 0;
              }
            }      
            numeroAleatorio = gerarNumeroAleatorio(0, 8);
            printf("Seu HP:%d\n",seuHp);
            printf("Hp inimigo: %d\n\n",oponente.hp);      
            printf("%s",vetorDialogo[numeroAleatorio]);
            time_t tempoInicial = time(NULL); 
           
            
            sleep(4);
            
      int test = gerarNumeroAleatorio(0, 1);
      if (test == 1) {
            strcpy(passwordEscolhido,passwordArray[gerarNumeroAleatorio(0,2)]);
            printf("Voce tem uma chance de acertar um ponto critico!\n\n");
            sleep(3);
            
            printf("Preste atencao! Quando a proxima mensagem aparecer, escreva a palavra %s o mais rapido possivel!\n",passwordEscolhido);
      
            sleep(gerarNumeroAleatorio(1, 5));         
            time_t inicio = time(NULL);
        
            printf("AGORA!\n");
      
            char buffer[256];
            scanf("%s",buffer);
      
            time_t fim = time(NULL);
            double tempoDecorrido = difftime(fim, inicio);
      
            if (tempoDecorrido < 4.5 && strcmp(buffer,passwordEscolhido)==0) {
                printf("%s\n", golpeEspecial);
                oponente.hp = oponente.hp - 333;
            } else {
                printf("Voce nao escreveu %s a tempo e perdeu sua chance!\n",passwordEscolhido);
            }
              
            }else{

            printf("Rapidamente! Qual a sua acao? 1: ataque\n 2: defesa (mais poderoso que antes)\n ");
            if (scanf("%d",&acao)!=1){
                danoTomado = gerarNumeroAleatorio(1,10);
                printf("Voce nao inseriu um comando a tempo!\n Voce perdeu %d de vida!\n" , danoTomado);
                seuHp = seuHp - danoTomado;
              
            }else{
                    
                    clear();                    
                    time_t tempoFinal = time(NULL);
                    double tempoDecorrido = difftime(tempoFinal, tempoInicial);
                    if (tempoDecorrido <= 11.0) {
                    switch (acao){
                    case 1:
                            danoTomado = gerarNumeroAleatorio(1,10);
                            printf("Voce atacou o inimigo com sucesso, gerando %d de dano!\n", danoTomado);
                            oponente.hp = oponente.hp - danoTomado;
                            break;
                    case 2:
                            defesa = gerarNumeroAleatorio(-1,1);
                            danoTomado = gerarNumeroAleatorio(3,5);
                            hpRecuperado = gerarNumeroAleatorio (1,13);
                            if (defesa){
                                printf("Voce defendeu com sucesso e recuperou %d de hp\n",hpRecuperado);
                                seuHp = seuHp+hpRecuperado;
                            }else{
                                printf("Voce falhou na sua defesa, e perdeu %d de hp\n", danoTomado);
                                seuHp = seuHp - danoTomado;
                            }
                    
                }if (!defesa){
                    danoTomado = gerarNumeroAleatorio(3,8);
                    printf("Agora e a vez do inimigo!\n Voce perdeu %d de hp!",danoTomado );
                    seuHp = seuHp- danoTomado;

            } else {
                 danoTomado = gerarNumeroAleatorio(3,6);
                 printf("Vez do inimigo! o oponente ataca! voce perde %d de hp \n", danoTomado);
                 seuHp = seuHp - danoTomado;
            }
        }else{
              danoTomado = gerarNumeroAleatorio(3,8);
              printf("Voce nao atacou a tempo! O oponente desfere um golpe poderoso!\n");
              seuHp = seuHp - danoTomado;
        } 
    }
    }
    }
    if (seuHp<=0){
        system("color 0F");
        return 0;
    }if (oponente.hp<=0){
        system("color 0F");
        return 1;
    }
}

void libere(Arv* raiz) {
    if (raiz != NULL) {
        libere(raiz->esq);
        libere(raiz->dir);
        free(raiz);
    }
}