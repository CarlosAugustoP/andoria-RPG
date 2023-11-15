char jogador[100];
int idNode;

int game(Arv **t){
  Oponente elfo;//sinto que o bug esta relacionada á falta de um break aqui.
  elfo.hp = 1;
  strcpy(elfo.nome,"elfo");
  int idNode;
  if(*t != NULL){
    idNode = (*t)->id;
    printf("%s\n", (*t)->texto);
    if ((*t)->combatFlag == 1){
        printf("\nPREPARE-SE PARA COMBATE\n");
        if(combat(100, elfo)){
            game(&((*t)->dir));
        }else{
            game(&((*t)->esq));
        }
    } else if((*t)->esq != NULL || (*t)->dir != NULL){
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
    } else {
        printf("\nFIM DO JOGO\n\nPRESSIONE QUALQUER TECLA PARA CONTINUAR");
        getch();
        return;
    }
  }
}

void busca(Arv *aux, int n) {
    printf("%s\n", aux->texto);
    if (aux == (Arv *)NULL)
        return;
    if (aux->id == n)
        return;
    if (n < aux->id)
        busca(aux->esq, n);
    else
        busca(aux->dir, n);
}

FILE *file;
file = fopen("historico.txt", "a");
if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
    }

        // Escreve a string jogador no arquivo
        fprintf(file, "%s,%d\n", jogador, idNode);

        fclose(file);

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
                printf("Desesperado, o sabio REI TRISTAN convoca espioes para descobrir quem esta por tras das trevas de NOCTURIA: O Lorde das Trevas MORGATOR\n");
                sleep(4);
                printf("Voce, o ultimo raio de esperanca do reino, um CACADOR DE RECOMPENSA e convocado pela inquieta real a embarcar em uma jornada epica...\n");
                sleep(10);
                clear();
                sleep(1);
                */