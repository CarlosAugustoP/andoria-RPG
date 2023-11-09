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
  int combatFlag;
} Arv;

int combat (int seuHp, Oponente oponente);
int gerarNumeroAleatorio(int inicio, int limite);
void inserir(Arv **t, char texto [3500], int id, int combatFlag);
void game();
void clear();
int choice; // variavel global que sera usada na recursao de game()

int main() {
    int opcao;

    Arv *history = NULL;
    //raiz
    inserir(&history, "Voce chega no palacio real, que encontra-se em um clima funebre...\n O sequestro da doce princesa Melinda parece abalar a todos em sua volta!\n Enquanto voce caminha pelos largos corredores do castelo, a pressao aumenta sobre seus ombros.\n\n O reino inteiro conta com voce!\n\n Finalmente, voce chega ao trono do Rei Tristan.\n Devastado, com lagrimas nos seus olhos, ele fala com voce:\n \"Ah! Cacador... Que bom que voce recebeu o meu convite.\n Devo confessar que os tempos sao dificeis... Mas, gracas aos Deuses, voce esta aqui para nos ajudar.\n Minha amada filha esta escondida no castelo de Eldia, abandonado a seculos!\n Suspeito que os malditos feiticeiros de Nocturia estao protegendo a torre com o Dragao escuro Relgar.\n Por favor, cacador, me ajude. Voce e minha unica esperanca...\"\n\n Apos uma longa noite de pesquisa sobre como enfrentar o dragao Relgar na biblioteca do reino, voce encontra algo!\n Uma espada mitica \"Luminastra\" e a unica que pode abater o dragao!\n No entanto, a pagina que fala de sua localizacao esta rasgada...\n Estranho... Sera que alguem pode lhe ajudar com esse misterio?\n\n ESCOLHA SUA ACAO! 1 - conversar com a bibliotecaria 2 - conversar com o rei ", 200,0);
    //historia carlos 1.1
    inserir(&history, "Voce decide conversar com a bibliotecaria, uma mulher idosa com oculos de leitura e cabelos prateados. Ela olha para voce com olhos sabios e diz:\n\n \"Ah, jovem aventureiro, a espada mitica 'Luminastra' e uma lenda antiga!\n\n Eu adoraria poder ajudar, mas a pagina que fala de sua localizacao esta irremediavelmente rasgada. Nao consigo decifrar o que resta dela.\" Ela suspira com pesar.\n\n \"Entretanto, ha esperanca. No Vale Verde, a leste do reino, vive um sabio elfo chamado Elandor.\n Ele e o guardiao do conhecimento ancestral e pode conhecer o segredo para encontrar a 'Luminastra'. Procure por ele e talvez voce descubra o caminho para a espada que pode abater o Dragao Relgar.\"\n Ela lhe entrega um antigo mapa que mostra a localizacao do Vale Verde.\n\n Seguindo suas cordenadas, você chega em uma vila.\n\nMoradores lhe encaram, deixando claro que sua reputacao claramente nao e muito boa. Um cacador de recompensas sujo... Que segue qualquer ordem por dinheiro.\nSera que isso e verdade?\nVoce chega na casa de Elandor, uma gigantesca arvore, e bate na porta. Mas ninguem lhe atende...\n\n Agora, voce se depara com uma escolha: Arrombar a porta(1) ou Bater mais forte (2)", 100,0);//
    inserir(&history, "Voce decide arrombar a porta da casa do ancião, determinado a encontrar respostas sobre a 'Luminastra'. Ao entrar, depara-se com uma cena aterrorizante. No centro da sala, está o corpo inerte do ancião elfo Elandor. Seus olhos estão vidrados, e sangue mancha o chao. E evidente que ele foi atacado. A sensacao de mal e trevas enche o ar.\n\nAntes que voce possa processar a visao, duas figuras sinistras emergem das sombras. Sao cavaleiros de Nocturia, vestindo capas negras e segurando espadas ameacadoras. Suas peles sao palidas e seus olhos sao completamente negros. Com um sorriso sadico, um deles diz: \"CACADOR! BEM QUE SENTIMOS UMA PRESENCA MAIS SUJA QUE A NOSSA...\" \n\nOs olhos dos cavaleiros brilham com malicia, e ambos puxam suas espadas, apontando-as para sua direcao.\n\n\"ESTRANHO... SENTIMOS CONFLITO EM VOCE... COMO SE AINDA HOUVESSE LUZ...\" \n\nVoce desembainha sua lamina, preparado para uma batalha!\n\n\"...DEIXE-NOS DEVORA-LA!\"\n", 50,1);
    inserir(&history, "Voce decide bater com mais forca na porta da casa do anciao, determinado a entrar. Logo, voce ouve vozes abafadas vindo do interior:\n \"QUEM ESTA FORA?\" \nVoce decide responder corajosamente:\n \"Sou um cacador de recompensas, enviado pelo Rei Tristan!\"\n A porta se abre rapidamente.\n\nAntes que voce possa reagir, laminas que brilham com energia negra atravessam a porta, perfurando seu estomago. A dor e insuportavel, e voce cai ao chao, ferido gravemente. A vida escapa de voce rapidamente.\n\nCom visao turva, voce consegue ver os responsaveis: Cavaleiros de Nocturia! Soldados escuros da legiao que raptou a princesa.\n Em um balcao de alquimia no canto da sala, existe sua unica esperanca. La, voce avista uma pocao misteriosa que pode salvar sua vida, mas a um terrivel custo. A pocao o transformara em um orc, uma criatura selvagem e feroz, nascido da escuridao. Voce se ve diante de uma escolha dificil: beber a pocao e viver como um orc ou recusar e enfrentar a morte como humano.\n\nA decisao esta em suas maos, e o tempo e curto. Qual sera a sua escolha?", 150,0);
    inserir(&history, "Em um movimento agil, os cavaleiros empunham suas espadas e, com precisao cruel, desferem golpes mortais. Voce sente as laminas penetrarem seu corpo, e uma dor lancinante toma conta de voce. Impalado, voce cai ao chao, imovel e a merce dos cavaleiros das trevas. Voce escuta um deles falar, em tom de zombaria com o seu fracasso:\n\"A COISA QUE DEIXA A PRESA MAIS DELICIOSA E O MEDO, CACADOR...\"\nCom visao turva, voce consegue ver os cavaleiros de Nocturia, mas algo esta errado. \nEles comecam a se contorcer de maneira grotesca.\n Suas mandibulas se abrem completamente, como a de uma cobra, revelando uma boca cheia de dentes afiados.\nEm um arrepio de horror, voce percebe que essas criaturas nao sao humanas. Com fome voraz, eles se inclinam sobre voce, suas mandibulas prontas para devora-lo vivo..\n Uma segunda boca se forma, cheia de dentes afiados e sinistros, pronta para devorar.\n A visao e horripilante e surreal, um pesadelo vivo se desenrolando diante de seus olhos.\n\nVoce e presa facil para essas criaturas abominaveis. A agonia toma conta de voce enquanto e devorado vivo pelos cavaleiros de Nocturia, uma morte terrivel e brutal... \nO reino de Andoria nunca sabera do heroi que tentou salva-los, e a esperanca se apaga com sua vida. As trevas triunfam.\n\nFIM DA JORNADA!\n\n", 25,0);
    inserir(&history, "Apos um triunfo epico contra os cavaleiro de Nocturia, O ultimo cavaleiro desmaia no chao, lancando um suspiro final de dor!\n. Suas habilidades superam a ameaca das trevas, e voce emerge vitorioso!\n Os cavaleiros agora estao indefesos diante de voce. \nCom a vantagem a seu favor, voce decide amarrar os cavaleiros para impedi-los de causar mais estragos.\n As cordas apertam seus pulsos, garantindo que nao possam escapar de sua justica. \n\nAgora, com os cavaleiros de Nocturia amarrados e impotentes, voce enfrenta uma decisao crucial\n Apesar da morte do anciao Elandor, podemos ainda extrair as informacoes necessarias...\n Para isso, como voce deseja interroga-los a respeito da espada de Luminastra? Voce tentar persuade-los a falar cooperativamente(1). Ou usar a violencia para extrair suas informacoes(2)", 75,0);
    inserir(&history, "Decidido a obter informacoes sobre a espada Luminastra e os planos macabros dos cavaleiros, voce tenta persuadir os cavaleiros de Nocturia, mas sua paciencia esta se esgotando. Com raiva, voce exige: 'Onde esta Luminastra? O que a Ordem de Nocturia fez com a princesa?'\nOs cavaleiros olham para voce, encarando a intensidade em sua voz.\nEles se contorcem, tentando se libertar, mas suas amarras os mantem firmemente presos. Voce mantem sua postura, deixando claro que nao aceitara evasivas.\n 'Ja ouvi lendas sobre os cavaleiros de Nocturia. Voces ja foram leais ao rei... Olhem so no que se transformaram', voce continua. 'Diga-me onde ela esta, e talvez haja misericordia para voces.'\nOs cavaleiros riem diante de suas palavras, mas um deles finalmente fala: \"NAO SOMOS MAIS AS PESSOAS QUE ERAMOS. NAO TEMOS MAIS ALMA, CACADOR... CEDEMOS NOSSO ESPIRITO PARA UM PROPOSITO MAIOR QUE NOS. E VOCE? QUAL CAUSA VOCE SERVE? APENAS DINHEIRO.\nVoce rebate: \"Voce nao me conhece. Estou aqui para resgatar a princesa. Nada mais.\n\"VOCE ESTA AQUI PARA SUGAR OS COFRES DO REI TRISTAN! PARE DE MENTIR, CACADOR... VOCE TAMBEM CEDEU SUA ALMA...\", diz um dos cavaleiros.\nVoce sente a verdade nas palavras deles, o que o faz refletir. No entanto, voce resiste a tentacao de se juntar as trevas.\n\"VOCE NAO ENTENDE O PODER DA TREVA. EXISTEM COISAS, CACADOR... COISAS QUE SOMENTE A ESCURIDAO PODE LHE OFERECER. JUNTE-SE A NOS, E TOMAREMOS O REINO INTEIRO PARA NOSSO MESTRE! UMA VIDA SEM PROPOSITO E LAMENTAVEL, CACADOR. ESTA NA HORA DE TE DARMOS UM...\"\nNesse momento, um dos cavaleiros toca em seu braco, e uma onda de escuridao percorre seu ser.\nVoce tem uma visao sombria, compreendendo a tentacao e o poder da treva:\nUm escopo inimaginavel de poder, proporcionado por algo muito mais forte que dinheiro: O medo.\nUma voz sussurra em sua mente, tentando seduzi-lo com promessas de poder inimaginavel.\nEsta na hora de decidir: Se juntar a Ordem das Trevas(1) ou fingir se juntar a Ordem das Trevas para persuade-los.(2)\n", 60,0);
    inserir(&history, "Voce decide que a violencia e o unico caminho para obter as informacoes que precisa.\n\n Com uma ferocidade fria, voce se prepara para usar a forca contra os cavaleiros, determinado a faze-los falar.\n\nEnquanto isso, seu olhar perspicaz percebe algo no balcao de alquimia do elfo Anciao Elandor.\n La, voce ve uma pocao de aparencia acida(1) e um facao brilhante(2)\nO facao reluz com promessas de combate, enquanto a pocao misteriosa pode ter usos desconhecidos.", 90,0);
    inserir(&history, "A tentação das trevas ganha força, e você aceita seu destino sombrio.\n\n A energia escura nocturina agora flui por suas veias, moldando sua essência e corrompendo seu coração.\n A luz que outrora brilhava em seu ser se desvanece, e não há mais escape dessa decisão irrevogável.\n\n Os cavaleiros, testemunhas de sua transformação, riem com um misto de prazer e satisfação.\n Eles reconhecem que você aceitou seu destino como senhor das trevas, e se preparam para iniciar a cerimônia de investidura, uma aura maligna pairando sobre todos.\n\nUm dos cavaleiros se levanta e aponta sua espada, que irradia uma energia obscura e sinistra.\n Ela brilha com uma intensidade sombria, revelando o poder negro que agora flui através de você.\n\nVocê está prestes a ser consagrado como um senhor das trevas, e o mundo nunca mais será o mesmo.\n\nApós a investidura, você segue um caminho sinuoso em direção à Floresta de Nocturia, acompanhado pelos dois cavaleiros que o escoltaram até ali.\n As árvores parecem se contorcer com uma vida sombria e sinistra, e sombras dançam entre seus galhos retorcidos.\nNo coração da floresta, encontram um local antigo e sombrio, um santuário de trevas onde reside Morgator, o Lorde Supremo das Trevas.\n Ele é um mago de grande poder e autoridade, de unhas longas e barba prateada.\n Seu olhar penetrante parece vasculhar a sua alma. Morgator cumprimenta o recém-investido senhor das trevas com um sorriso malévolo;\n\"Você fez a escolha certa, jovem senhor das trevas...\", diz Morgator, sua voz ecoando com uma força sobrenatural.\n\n Você se ajoelha perante Morgator, aceitando a escuridão que agora o envolve. Está prestes a embarcar em uma jornada sombria, onde o conhecimento proibido e o poder sinistro o aguardam.\n\n \"Agora em diante, seu nome sera Lord Nihil, o devorador de esperanca...\n Levante-se, meu novo aprendiz...Sinto um futuro promissor em seu treinamento!\"\n\nSeu destino está selado, e o mundo nunca mais será o mesmo, pois você se torna um discípulo de Morgator, o Lorde Supremo das Trevas.\n\n Voce servira para sempre sobre seu comando, e prepara-se para sua primeira missao: destruir o anjo Raziel, protetor da espada de Luminastra.\n\n Voce aceita sua escura missao? nao(1) ou sim(2)\n\n", 55,0);//ainda n acabou
    inserir(&history, "Após fingir ter se juntado à Ordem das Trevas, você agora está em uma posição privilegiada para obter informações. Com cautela, você começa a fazer perguntas aos membros da Ordem, tentando descobrir mais sobre seus planos sinistros.\n\nVocê pergunta: ''Por que a Ordem de Nocturia raptou a princesa Melinda?''\n\nUm dos membros da Ordem, com uma expressão de confiança, responde: ''A princesa Melinda é a chave para o nosso poder. Seu sangue real e a Espada Luminastra corrompida nos darão o poder supremo para conquistar o reino e moldá-lo de acordo com a vontade das trevas. Ela é a peça central de nosso plano.'' Você toma nota mental dessa informação crucial.\n\nEm seguida, você pergunta: ''Onde está a Espada Luminastra?''\n\nO outro cavaleiro, olhando desconfiado, responde: ''A Espada Luminastra está guardada no monte Lumina, sob a proteção do anjo Raziel... O sacrifício real da princesa Melinda a tornará ainda mais poderosa, e então a usaremos para concretizar nossa conquista do reino de Andoria. É o instrumento de nossa ascensão ao poder supremo.\n Você guarda essa informação com cuidado, ciente de sua importância para o destino de Andoria.\n\nAgora, com as informações necessárias em suas mãos, você está pronto para tomar medidas decisivas. O destino do reino depende de suas próximas ações. Você se levanta abruptamente, deixando os dois cavaleiros de Nocturia confusos e perplexos. Eles trocam olhares, visivelmente surpresos com a sua súbita mudança de comportamento. \"EI... VOCE VAI PRA ONDE?\", pergunta um deles, com uma pitada de preocupação na voz. Ao sair da casa, voce nao fala sequer uma palavra.\n\n \"ERM... VOCE NAO VAI NOS DESAMARRAR NAO?\"\n\n Voce decide nao desamarrar os cavaleiros e, em vez disso, sai da casa, determinado a encontrar a Espada Luminastra. No caminho, a floresta escura e sombria a sua frente parece mais imponente do que nunca. Enquanto avanca, voce de repente se depara com um elfo baixo e magro, que fala de um jeito peculiar. Ele e um vendedor de itens, e uma expressao ganancosa ilumina seus olhos enquanto ele se aproxima de voce.\n\n\"Oi, aventureiro! Procurando por algo especial, hm?\" diz o elfo com um sorriso malicioso.\n\nVoce olha para ele, curioso, e pergunta: \"O que voce tem para vender?\"\n\nO elfo puxa uma pequena pocao de vida de seu bolso e diz: \"Tenho algo que pode te salvar de apuros, amigo. Uma pocao de vida que pode te curar em momentos dificeis. Voce nunca sabe quando vai precisar de uma, mmm!\"\n\nVoce pergunta quanto custa, e o elfo peculiar da um risinho astuto. \"Ah, meu amigo, essa pocao de vida nao e barata, mmm. Ela custa uma pequena fortuna, mas pode ser a diferença entre a vida e a morte, mmm. Voce tem o ouro necessario, mmm?\"\n\nVoce verifica sua bolsa e percebe que nao possui o dinheiro necessário para comprar a pocao. Voce olha para o elfo, ponderando suas opçoes. Roubar o elfo poderia ser tentador, mas isso poderia ter consequencias(1). Por outro lado, voce poderia continuar em sua jornada e resgatar a princesa com sua coragem e seu HP atual(2).\n\nA decisao esta em suas maos. O que voce escolhe fazer, mmm?", 65,0);
    
    inserir(&history, "Voce seleciona o facao no balcao do elfo Elandor, segurando-o com firmeza em suas maos enquanto se aproxima dos cavaleiros. Pela primeira vez desde que os encarou, seus olhos demonstram medo. No entanto, sua determinacao e feroz e gelida quando pergunta uma ultima vez:\"Onde esta a espada Luminastra?\"Os cavaleiros lhe encaram com determinacao, recusando-se a ceder diante de sua ameaca.\n\n\"NAO SOMOS COMO VOCE, CACADOR DE RECOMPENSAS... TEMOS HONRA EM NOSSA CAUSA. NUNCA TE DIREMOS\", declara um dos cavaleiros com um tom de escarnio. No entanto, suas palavras nao abalam sua determinacao.\n\nVoce solta uma risada. Nao e a primeira vez que ouviu aquelas mesmas palavras...\n\n Os Nocturinos nao lhe deixaram escolha. Voce avanca com seu plano, comecando pelos dedos do primeiro cavaleiro.\n\nA determinacao nos olhos do cavaleiro rapidamente se transforma em desespero, e ele berra de agonia apos sofrer tanta dor. Voce repete sua pergunta:\n\n\"Onde esta a espada Luminastra?\"\n\nAinda assim, o silencio e a unica resposta que recebe.\n\nVoce se aproxima do segundo cavaleiro e repete o processo, torturando-o de maneira semelhante.\n\n\"Onde esta a espada Luminastra?\" Voce pergunta mais uma vez, mas percebe algo estranho: ambos os cavaleiros parecem ter desmaiado...\n\n Isso nunca aconteceu com voce antes. Agora, voce tem apenas uma escolha: Esperar.\n\n...", 95,0);

    inserir(&history, "Voce decide recorrer a medidas mais extremas para obter as respostas que procura. Com determinacao fria, voce se dirige ao balcao de alquimia do velho Elandor e pega um frasco de acido corrosivo.\n O liquido fumegante goteja da garrafa, e voce se aproxima dos cavaleiros com a substancia em maos.\n\nDespejando o acido cuidadosamente sobre suas botas, voce observa o liquido comecar a corroer o couro.\n Apenas o som do acido faz com que os cavaleiros se encolham de terror, os olhos se arregalando de apreensao.\n\n\"Onde esta a espada Luminastra?\" voce diz, sua voz gelada como o proprio acido.\n\nA agonia e a queimacao do acido finalmente rompem a resistencia dos cavaleiros. Um deles, com o rosto contorcido de dor, finalmente cede:\n\n\"A espada... A espada Luminastra esta no Monte Lumina... Protegida pelo anjo Raziel.\"\n\nSatisfeito com a resposta, voce recua e permite que os cavaleiros aliviem sua dor.\n Agora, voce sabe onde deve ir em sua busca.\n O Monte Lumina aguarda, e o anjo Raziel sera um desafio a ser superado.\n Sua jornada em busca da espada Luminastra esta longe de terminar, mas voce esta um passo mais perto de seu objetivo, gracas ao acido e a determinacao implacavel...\n\n Enquanto voce segue em direcao ao Monte Lumina, atravessa uma vila tranquila. A vila e pitoresca, com casas de madeira e uma atmosfera serena, mas algo parece fora do lugar. No momento em que voce se aproxima da praca central, uma cena aterrorizante se desenrola diante de seus olhos.\n\nUm grupo de bandidos armados e mascarados cerca uma mulher indefesa. Eles a ameacam, exigindo que entregue seus pertences. A mulher, visivelmente assustada, nao tem como se defender. Seu coracao dispara quando percebe a situacao.\n\nNo entanto, ao avaliar a sua propria condicao, voce nota que seu HP ja esta consideravelmente baixo devido as acoes anteriores. Uma escolha dificil se apresenta diante de voce: (1)Arriscar seu hp para proteger a indefesa ou (2)Ignorar a cena.", 85,0);


    inserir(&history, "Diante da situacao perigosa, voce opta por nao se envolver.\n Mesmo com a angustia da mulher a vista, voce decide continuar seu caminho em direcao ao Monte Lumina, preocupado com sua propria seguranca.\n Os bandidos nao sao seus problemas, e voce segue em frente, ignorando o apelo silencioso da mulher.\n\nA cena se desvanece enquanto voce deixa para tras a vila e a angustia que la permanece.\n Sua jornada em busca da espada Luminastra continua, mas a escolha de nao intervir na situacao deixa um peso em seu coracao.\nSera que suas acoes ou inacoes terao consequencias mais adiante em sua jornada?\n\n Com determinacao, voce continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O anjo Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 88,0);

    inserir(&history, "Voce nao pode simplesmente ignorar a angustia da mulher indefesa.\n Mesmo que sua saude esteja fragilizada, sua determinacao e inabalavel.\n Com um coracao corajoso, voce se lanca no meio dos bandidos, determinado a proteger a mulher e enfrentar os assaltantes, apesar dos riscos envolvidos.\n\nOs bandidos, surpresos com sua audacia, imediatamente se preparam para o combate.\n As laminas deles cintilam a luz do sol, e o confronto e iminente.\nSeu destino agora esta entrelacado com o da mulher, enquanto voce se prepara para enfrentar os bandidos em um confronto perigoso. Que a batalha comece!", 82,1);

    inserir(&history, "A batalha e feroz, e voce luta com bravura, demonstrando honra em cada movimento.\n No entanto, os numeros dos bandidos sao superiores, e sua saude ja estava enfraquecida devido as acoes anteriores.\n Apesar de seus esforcos heroicos, voce nao consegue prevalecer contra a forca esmagadora dos assaltantes.\n\nFinalmente, exausto e ferido, voce cai diante dos bandidos.\n Eles o derrotaram, mas sua morte e digna e honrada, defendendo a mulher indefesa ate o fim.\n Seu sacrificio em nome da justica e da honra nao sera esquecido, e sua historia vivera na memoria daqueles que testemunharam sua bravura. Neste momento critico, uma voz celestial ressoa em sua mente. E o anjo Raziel, um ser de luz e justica, guardiao da espada Luminastra.\n Sua voz e serena e poderosa, e ele se comunica diretamente com voce:\n\n\"CORAJOSO BUSCADOR DA LUZ, VOCE DEMONSTROU GRANDE HONRA EM SUA LUTA.\n SEU SACRIFICIO NAO PASSOU DESPERCEBIDO.\n SAIBA QUE VOCE ESTA PERTO DO SEU OBJETIVO. O MONTE LUMINA ESTA AO ALCANCE. MANTENHA SUA HONRA, POIS E A QUALIDADE MAIS VALIOSA QUE UM HEROI PODE POSSUIR. JOGUE DE NOVO...\"", 81,0);

     inserir(&history, "Apesar de sua condição enfraquecida, você supera os bandidos, um por um.\n Seus movimentos são precisos, e você demonstra grande coragem e habilidade na luta. Os bandidos, sob a pressão de sua resistência feroz, são finalmente derrotados e se dispersam, deixando para trás a mulher que tentaram roubar.\n\nA mulher, profundamente grata, agradece a você com lágrimas nos olhos.\nVocê triunfou na batalha, protegendo a inocente e restaurando a paz na vila.\n Sua coragem e honra brilham como um farol, e sua jornada em busca da espada Luminastra continua, fortalecida pela vitória que você conquistou com bravura. Ela diz: \"Voce parece fraco... Tome isso.\"\n Ela te da uma maca! Um presente humilde, mas certamente lhe ajudara.\n Voce regenera 2 de hp.\n\n Com determinacao, voce continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O anjo Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 83,0);




    inserir(&history, "Voce espera os cavaleiros acordarem", 98,0);
    inserir(&history, "Voce e impaciente e se ferra", 92,0);

    inserir(&history, "O mago Morgator sorri maliciosamente, satisfeito com a sua prontidao.\n\n \"Muito bem, Lord Nihil. Agora, vou lhe contar mais detalhes sobre a missao que o aguarda.\"\nEle conduz voce ate uma camara oculta, onde mapas antigos e grimorios empoeirados adornam as prateleiras.\n Morgator desenrola um pergaminho, revelando uma representacao detalhada do reino de Andoria, com marcadores indicando os locais chave.\nEle aponta para a regiao protegida pelo anjo Raziel, o monte Lumina, onde a Espada Luminastra repousa em um altar sagrado.\n \"Aqui e onde reside a ultima esperanca da luz, guardada por Raziel, seu fiel protetor,\" diz Morgator, sua voz carregada de uma mistura sinistra de antecipacao e ganancia.\n\n\n Com um tom sombrio, Morgator revela a verdade oculta: a princesa Melinda, herdeira do trono de Andoria, foi capturada pelos seguidores da escuridao com o proposito perverso de ser sacrificada com a Espada Luminastra.\n Este ato corrompera a lendaria arma, concedendo-lhe um poder inimaginavel e mergulhando Andoria em um reinado de trevas.\n\n\"O sacrificio real da princesa e crucial para o meu plano,\" diz Morgator, seus olhos brilhando com uma ambicao insaciavel.\n \"Uma vez que Luminastra seja corrompida, me tornarei um novo Deus em Andoria!\n\" A revelacao desse plano nefasto ecoa em sua mente, mas a ideia de uma Andoria mergulhada na escuridao nao lhe traz remorso, na verdade, ela lhe traz certo conforto.\n Afinal, voce nunca gostou muito do reino...\n\nA perspectiva de um reino moldado pelas trevas parece mais apropriada ao seu verdadeiro eu.\n O destino esta selado, e agora voce parte em direcao ao seu proximo desafio: a destruicao do anjo Raziel.\n\n Com a determinacao de um discipulo sedento de poder, voce aceita a missao com um firme \"sim\".\n Cada passo que da na direcao do altar de Luminastra e um passo em direcao ao seu papel como o devorador de esperanca. Um homem disposto a moldar Andoria de acordo com a vontade sombria de Morgator, o Lorde Supremo das Trevas.\n A jornada esta chegando ao fim, e o destino de Andoria esta nas maos do novo senhor das trevas.\n\nPREPARE-SE, LORDE NIHIL, PARA A BATALHA FINAL!\n\n",58,0);
    inserir(&history, "Voce se ajoelha diante de Morgator, pronto para aceitar seu destino como senhor das trevas.\n\n No entanto, a medida que voce se inclina, uma sensacao de duvida comeca a se infiltrar em sua mente.\n As palavras e acoes dos cavaleiros, o olhar sinistro de Morgator, tudo isso o faz hesitar.\n\nMas antes que voce possa completar o gesto, uma voz interior grita para voce resistir, para nao se entregar completamente a escuridao.\n\n Num movimento repentino, voce recua e olha nos olhos de Morgator com determinacao.\n\n Morgator, com um sorriso maligno nos labios, estende a mao e agarra seu pescoco com uma forca sobrenatural.\n\n Sua voz ecoa sombriamente enquanto ele diz: \"Voce pagara o preco pela sua falta de ambicao...\"\n\n Com um aperto implacavel, Morgator comeca a sufoca-lo, seus olhos brilhando com crueldade.\n Sua visao comeca a escurecer, e voce luta desesperadamente para respirar.\n A sensacao de traicao toma conta de voce, mas sua decisao de resistir permanece inabalavel.\n No entanto, seus esforcos sao em vao, e a escuridao finalmente o envolve... FIM DE JOGO.", 52,0);
    inserir(&history, "Voce olha para o elfo peculiar e, apesar da tentacao da pocao de vida, decide que nao e o momento de sucumbir a ganancia.\n\n Com determinacao, voce agradece ao elfo e continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O anjo Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 68,0);
    inserir(&history, "Voce olha para o elfo peculiar e discretamente adquire o objeto, sem que ele perceba.\n\n Com determinacao, voce continua sua jornada em busca da Espada Luminastra, subindo o monte de Lumina em direcao ao local onde a lendaria espada repousa.\n\nNo topo do monte de Lumina, voce e recebido por uma visao de tirar o folego. Diante de voce esta uma entidade divina, uma manifestacao do proprio divino: O anjo Raziel.\n\n Seus olhos humanos mal conseguem compreender a magnitude dessa presenca:\n O ser celestial, com sua forma indescritivel, e coberto por inumeras asas resplandecentes que se estendem como um manto de luz.\n Suas penas irradiam cores que vao alem do espectro visivel, criando uma aura hipnotizante de cintilantes matizes que dancam em harmonia.\nSua figura e eterea e sublime, impossivel de ser completamente apreendida pela mente humana.\n\n O ser olha para voce com olhos que parecem conter o conhecimento de todas as eras e galaxias, e sua voz e uma sinfonia celestial que ressoa em sua alma.\n\"OH, DESTEMIDO VIAJANTE, OUSASTE TU ESCALARES O MAJESTOSO MONTE LUMINA EM BUSCA DA LENDARIA ESPADA LUMINASTRA?\", diz o ser celestial.\n\n \"SOU O GUARDIAO VIGILANTE DESTA AREA SAGRADA E O ENVIADO CELESTIAL.\n SAIBA, DISTINTO BUSCADOR DE SONHOS, QUE ANTES DE TE CONCEDER A HONRA DE EMPUNHAR A ESPADA, TU SERAS SUBMETIDO A UMA ESCRUPULOSA AVALIACAO.\nPOIS, DELICADAMENTE, DEVO RESSALTAR QUE MINHA NATUREZA E A DE UM CHERUBIM, UM SER DESIGNADO PARA A PROTECAO DE RELIQUIAS DIVINAS, E ASSIM, A ENTREGA DESTA NOBRE RELIQUIA CARECE DE UMA ESCOLHA REFINADA E PRECISA.\"\n\nA aura divina do ser envolve voce, e voce sente que esta diante de um julgamento que ultrapassa as palavras e os desafios.\n Seu coracao palpita com expectativa.\n\nA decisao sobre sua dignidade e proposito esta nas maos do ser celestial, cuja compreensao vai alem do humano.\n\nA avaliacao esta prestes a comecar...", 62,0);
    
    
    /*
    inserir(&history, "Checkpoint", 2);
    inserir(&history, "Checkpoint", 9);
    */

    //historia pires 1.2
    inserir(&history, "Voce decide voltar para a sala de trono do Rei Tristan, Ele olha para voce com olhos cheios de preocupacao e diz:\n\n \"Luminastra? Essa espada esta proibida! Ela corrompe todos que a procuram! Em nenhuma hipotese irei-\"\n O rei olha para uma pintura de sua amada filha, lembrando a ele de seu amor perdido... Nao existe nada que ele nao fara para tela de volta.\n Apos uma pausa, o Rei Tristan recompose e continua:\n \"Existe alguem que pode lhe ajudar... Sir Cedric, um aposentado cavaleiro de Aldoria, tempos atras cacava esse artefato maldito...\n Ele costumava ser o mais leal senhor da cidade. Hoje, ele e nosso mais leal bebado... Quando nao esta afogando suas magoas em uma taverna, ele geralmente toca musica pela praca da cidade.\"\n O Rei Tristan lhe entrega um mapa da cidade com a marcacao dos locais mencionados.\n\n Agora, voce se depara com uma escolha: partir para a taverna 'O Barril Dourado'(1) ou dirigir-se a praca da cidade para encontrar Sir Cedric.(2)", 300,0);
    inserir(&history, "Checkpoint 1.2.1\nVocê opta por seguir para a taverna \"O Barril Dourado\". Ao entrar, a atmosfera pesada e tensa da taverna o envolve. Os clientes sussurram e lançam olhares desconfiados em sua direção. Você avista um homem idoso, vestido como um cavaleiro, sentado em um banco alto, com uma cerveja pela metade à sua frente. Parece ser Sir Cedric.\nCom cautela, você se aproxima dele e se apresenta como o caçador de recompensas enviado pelo Rei Tristan em busca da espada \"Luminastra\". Sir Cedric olha para você com olhos sombrios e um sorriso sinistro cruza seu rosto. Ele diz: \"AH, O CACADOR DE RECOMPENSAS. PARECE QUE VOCE ESTA BUSANDO ALGO MUITO VALIOSO.\"\nSem aviso, ele se levanta abruptamente e tira o disfarce de Sir Cedric, na verdade ele era um cavaleiro da ordem Nocturia que fingia ser o Sir Cedric! Ele puxa uma espada escura e malevola de suas vestes, revelando sua verdadeira lealdade à Ordem de Nocturia. Ele se prepara para o ataque e diz: \"PREPARE-SE PARA A BATALHA CAÇADOR. VOCE NAO SAIRA DAQUI SEM LUTAR!\"\nSEQUENCIA DE COMBATE INICIADA", 250,1);
    inserir(&history, "Checkpoint 1.2.1.2\nApós a intensa batalha na taverna, você sai vitorioso sobre o impostor da Ordem de Nocturia que estava fingindo ser Sir Cedric. Com sua missão ainda mais urgente em mente, você se depara com duas opções: (1) - informar ao Rei Tristan o ocorrido\n(2) - Procurar o verdadeiro Sir Cedric\n", 275,0);
    inserir(&history, "Checkpoint 1.2.1.2.1\nVocê decide retornar ao palácio e informar imediatamente ao Rei Tristan sobre o incidente na taverna. O Rei precisa saber que a Ordem de Nocturia está ativamente interferindo em seus esforços para recuperar a espada \"Luminastra\" e resgatar a princesa Melinda. Ele pode ter conselhos ou informações adicionais para ajudar em sua jornada.\n", 262,0);
    inserir(&history, "Checkpoint 1.2.1.2.2\nA despeito do confronto anterior, você decide procurar o verdadeiro Sir Cedric na praça da cidade. Confiando em suas habilidades de caçador e em sua intuição, você acredita que encontrar o verdadeiro aliado pode ser essencial para sua missão. Esta escolha o levará a buscar Sir Cedric na praça e tentar obter informações valiosas sobre a localização da espada \"Luminastra\" e como enfrentar o anjo Raziel para resgatar a princesa Melinda.", 262,0);
    inserir(&history, "Checkpoint 1.2.2\nVocê opta por procurar Sir Cedric na praça da cidade, onde encontra um homem idoso vestido como um cavaleiro, tocando suavemente uma bela melodia em seu alaúde, encantando os transeuntes. Com um aceno de cabeça, ele confirma que é, de fato, Sir Cedric.\nNo início, Sir Cedric parece desconfiado ao ouvir sobre sua missão e o pedido do Rei Tristan. No entanto, olhando nos seus olhos, ele percebe sua determinação e compreende a gravidade da ameaça representada pela Ordem de Nocturia para o reino. Sir Cedric, ciente de que você está genuinamente comprometido em salvar a princesa Melinda, decide confiar em você.\nEle revela a verdadeira localização da espada \"Luminastra\", no monte Lumina, uma elevação majestosa na paisagem. Sir Cedric concorda em se unir à sua jornada, trazendo consigo sua habilidade musical e habilidades de combate como ex-cavaleiro. Ele também reforça:\nEXISTEM DOIS CAMINHOS POSSIVEIS PARA O MONTE LUMINA: A TRILHA DAS LAGRIMAS SAGRADAS, O CAMINHO MAIS SEGURO, POREM MAIS DEMORADO. OU O DESFILADEIRO DA TEMPESTADE, MAIS RAPIDO, POREM MAIS PERIGOSO.\nA TRILHA DAS LAGRIMAS SAGRADAS EH ASSIM CHAMADA DEVIDO AS QUEDAS D'AGUAS CRISTALINAS QUE A ACOMPANHAM, QUE SAO CONSIDERADAS SAGRADAS PELAS PESSOAS DA VILA LOCAL, ONDE TEM TAMBEM CRIATURAS MISTERIOSAS.\nO DESFILADEIRO DA TEMPESTADE RECEBE ESSE NOME POR CONTA DOS PERIGOS DESSA PASSAGEM. LA EH POSSIVEL ENCONTRAR ORCS E OUTRAS CRIATURAS SELVAGENS E PERIGOSAS.\nAgora, voce se depara com uma escolha: (1) - ir para A Trilha das Lagrimas Sagradas\n(2) - ir para o Desfiladeiro da Tempestade", 350,0);
    
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
                printf("A destemida PRINCESA MELINDA, herdeira do trono, foi capturada por uma forca maligna conhecida como A ORDEM DE NOCTURIA , Deixando o reino inteiro a beira do abismo!\n");
                sleep(4);
                printf("Desesperado, o sabio REI TRISTAN convoca o mais improvavel dos herois, alguem destinado a trazer a luz de volta a sua amada terra.\n");
                sleep(4);
                printf("Voce, o ultimo raio de esperanca do reino, um CACADOR DE RECOMPENSA e convocado a embarcar em uma jornada epica...\n");
                sleep(10);
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

void inserir(Arv **t, char* texto, int id, int combatFlag) {
    if (*t == NULL) {
        *t = (Arv *)malloc(sizeof(Arv));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->id = id;
        (*t)->texto = (char*) malloc(strlen(texto)+1);
        strcpy((*t)->texto, texto);
        (*t)->combatFlag = combatFlag;
    } else {
        if (id < (*t)->id) {
            inserir(&(*t)->esq, texto,id,combatFlag);
        }
        if (id > (*t)->id) {
            inserir(&(*t)->dir,texto, id,combatFlag);
        }
    }
}

void game(Arv **t){
  Oponente elfo;//sinto que o bug esta relacionada á falta de um break aqui.
  elfo.hp = 10;
  strcpy(elfo.nome,"elfo");
  if(*t != NULL){
    printf("%s\n", (*t)->texto);
    if ((*t)->combatFlag == 1){
        printf("\nPREPARE-SE PARA COMBATE\n");
        if(combat(17, elfo)){
            game(&((*t)->dir));

        }else{
            printf("VOCE PERDEU! GAME OVER!");
        }
    }
    if((*t)->esq != NULL){
      //sleep(6);
      printf("\nINSIRA SUA ESCOLHA: ");
      scanf("%d", &choice);
      if(choice == 1){
        clear();
        //sleep(1);
        game(&((*t)->esq));
      } else {
        clear();
        //sleep(1);
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
    sleep(15);
    clear();
    int numeroAleatorio;
    int danoTomado,hpRecuperado;
    int defesa;
    int acao; 
    char vetorDialogo[9][100] = {
            "%s rosnando, pronto para o próximo ataque, te encara com intensidade.\n\n",
            "Com um olhar feroz, %s se prepara para lançar seu próximo ataque.\n\n",
            "%s mantém seu olhar fixo em você, antecipando o próximo confronto.\n\n",
            "Você vê %s respirando profundamente, se preparando para o próximo golpe.\n\n",
            "Os olhos de %s brilham com determinação enquanto ele se prepara para atacar novamente.\n\n",
            "Com um grunhido ameaçador, %s se prepara para mais um round de combate.\n\n",
            "%s mantém sua postura, observando cada um de seus movimentos atentamente.\n\n",
            "Você sente a tensão no ar enquanto %s se prepara para o próximo ataque.\n\n",
            "%s parece imperturbável, pronto para desferir outro golpe mortal.\n\n"
    };
    while (seuHp>0){
            if (oponente.hp<=0){
              return 1;
            }      
            printf("Seu HP:%d\n",seuHp);
            printf("Hp inimigo: %d\n\n",oponente.hp);      
            char dialogoPersonalizado[300];
            numeroAleatorio = gerarNumeroAleatorio(0,8);
            sprintf(dialogoPersonalizado, vetorDialogo[numeroAleatorio],oponente.nome);
            printf("%s",dialogoPersonalizado);
            time_t tempoInicial = time(NULL); 
            sleep(4);
            printf("Rapidamente! Qual a sua ação? 1: ataque 2: defesa\n\n ");
            if (scanf("%d",&acao)!=1){
                danoTomado = gerarNumeroAleatorio(1,10);
                printf("Você não inseriu um comando a tempo!\n Você perdeu %d de vida!\n" , danoTomado);
                seuHp = seuHp - danoTomado;
            }else{
                    clear();                    
                    time_t tempoFinal = time(NULL);
                    double tempoDecorrido = difftime(tempoFinal, tempoInicial);
                    if (tempoDecorrido <= 11.0) {
                    switch (acao){
                    case 1:
                            danoTomado = gerarNumeroAleatorio(1,10);
                            printf("Você atacou o inimigo com sucesso, gerando %d de dano!\n", danoTomado);
                            oponente.hp = oponente.hp - danoTomado;
                            break;
                    case 2:
                            defesa = gerarNumeroAleatorio(-1,1);
                            danoTomado = gerarNumeroAleatorio(3,5);
                            hpRecuperado = gerarNumeroAleatorio (1,10);
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
                    seuHp = seuHp- danoTomado;

            } else {
                 danoTomado = gerarNumeroAleatorio(3,6);
                 printf("Vez do inimigo! o oponente ataca! voce perde %d de hp \n", danoTomado);
                 seuHp = seuHp - danoTomado;
            }
        }else{
              danoTomado = gerarNumeroAleatorio(3,8);
              printf("Você não atacou a tempo! O oponente desfere um golpe mortal!\n");
              seuHp = seuHp - danoTomado;
        } 
    }
    }
    if (seuHp<0){
        sleep(3);
        clear();
        printf("BATALHA PERDIDA!\n\n");
        sleep(3);
        clear();
        return 0;
    }if (oponente.hp<=0){
        sleep(3);
        clear();
        printf("BATALHA GANHA!\n\n");
        sleep(3);
        clear();
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