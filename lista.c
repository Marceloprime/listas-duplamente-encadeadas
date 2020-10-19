#include "lista.h"

/*Funcao cria lista um ponteiro lista eh alocacao e o inicio e o fim da lista eh inicializados e
o ponteiro eh retornado para a main;
*/
LISTA *cria_lista(){
    LISTA *l;
    l = (LISTA*) malloc (sizeof(LISTA));
    if(l == NULL){
        printf("Erro de alocacao");
    }
    l->inicio = NULL;
    l->fim = NULL;
    
    return l;
}

/*Na funcao libera lista uma variavel auxilia eh declarada para guarda o a posicao do NO
em seguida enquanto a lista for diferente de NULL, aux receber o no atual
e a lista receber o proximo no, e o aux reliza a liberacao da memoria ate a lista se igual a NULL*/
void libera(LISTA *l){
    NO *aux;
    while(l->inicio != NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    return;
}

/*Funcao que verificar se a lista esta vazia
caso o inicio seja igual a NULL ele returna 1,caso
contraio ele retorna 0*/
int lista_vazia(LISTA *l){
    if(l->inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

/*Funcao insere, ela retorna 1 casso nao seja possivel alocar um novo no, e 0 caso  a insercao seja realizada com sucesso, essa 
funcao insere o elemento no inicio da lista, sendo assim o inicio eh atualizado a cada insercao*/
int insere_no_inicio(LISTA *l, ELEM x){
    if(l == NULL){
        //Erro, alista nao existe;
        return 1;
    }
    NO *bloco;
    bloco = (NO*) malloc (sizeof(NO));
    if(bloco == NULL){
        //Erro, nao foi possivel alocar memoria;
        return 1;
    }
    
    //Prenchimento do NO;
    bloco->infor = x;
    bloco->ant = NULL;
    bloco->prox = NULL;
    
    if(lista_vazia(l) == 1){
        l->inicio = bloco;
        l->fim = l->inicio;
    }
    else{
    
        l->inicio->ant = bloco;
        bloco->prox = l->inicio;
        l->inicio = bloco;
    }
        
    return 0;
}

/*Nessa funcao a insercao ocorre de forma ordenada, tratando dos tres casos possivies de
insercao ordenada*/
int insercao_ordenada(LISTA *l, ELEM x){
    if(l == NULL){
        //Erro, alista nao existe;
        return 1;
    }
    
    NO *bloco;
    bloco = (NO*) malloc (sizeof(NO));
     if(bloco == NULL){
        //Erro, nao foi possivel alocar memoria;
        return 1;
    }
    //Prenchimento do NO;
    bloco->infor = x;
    bloco->ant = NULL;
    bloco->prox = NULL;
    
    //Caso lista esteja vazia, o fim e inicio sao o mesmo;
    if(lista_vazia(l) == 1){
        l->inicio = bloco;
        l->fim = l->inicio;
    }
    //Se a lista nao tive vazia;
    else{
        //Primeiro eh buscado a posicao atraves do numero, contido no tipo de dado
        NO *anti,*aux = l->inicio;
        //Busca da posicao de insercao
        while(aux != NULL && aux->infor.num < bloco->infor.num){
            anti = aux;
            aux = aux->prox;
        }
        
        //Caso a insercao, seja realizada no fim da lista;
        if(aux == NULL){
          anti->prox = bloco; 
          bloco->ant = anti;
          l->fim = bloco;
        }
        //Caso a insercao, seja realizada no inicio da lista;
        else if(aux == l->inicio){
            l->inicio->ant = bloco; 
            bloco->prox = l->inicio;
            l->inicio = bloco;
        }
        
        //Caso a insercao, seja realizada no meio da lista;
        else{
            bloco->prox = anti->prox;
            anti->prox = bloco;
            bloco->ant = anti;
            aux->ant = bloco;
        }
    }
    return 0;
}


/*Funcao insere, ela retorna 1 casso nao seja possivel alocar um novo no, e 0 caso  a insercao seja realizada com sucesso, essa 
funcao insere o elemento no inicio da lista, sendo assim o inicio eh atualizado a cada insercao*/
int insere_no_final(LISTA *l,ELEM x){
    if(l == NULL){
        //Erro, alista nao existe;
        return 1;
    }
    NO *bloco;
    bloco = (NO*) malloc (sizeof(NO));
     if(bloco == NULL){
        //Erro, nao foi possivel alocar memoria;
        return 1;
    }
    
    //Prenchimento do NO;
    bloco->infor = x;
    bloco->ant = NULL;
    bloco->prox = NULL;
    
    NO *aux = l->inicio;
    //caso a lista esteja vazia
    if(lista_vazia(l) == 1){
        l->inicio = bloco;
        l->fim = bloco;
    }
    else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = bloco;
        bloco->ant = aux;
    }
}

void impressao(LISTA *l){
    NO *aux = l->inicio;
    while(aux != NULL){
        printf("%d %c\n",aux->infor.num,aux->infor.word);
        aux = aux->prox;
    }
}

int quantidade(LISTA *l){
    int i = 0;

    if(lista_vazia == 1){
        return i;
    }

    NO *aux = l->inicio;
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }

    return i;
}

int remocao(LISTA *l,ELEM x){
    NO *ant, *aux = l->inicio;
    if(lista_vazia == 1){
        return 0;
    }

    while(aux != NULL && aux->infor.num != x.num){
        ant = aux;
        aux = aux->prox;
    }
    //ELemento nao encontrado na lista
    if(aux == NULL){
        return 0;
    }
    
    //se houve apenas um ELemento na lista
    if(aux == l->inicio){
        l->inicio = aux->prox;
        free(aux);
    }

    else{
        ant->prox = aux->prox;
        free(aux);
    }
    return 1;
}
