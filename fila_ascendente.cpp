#include<stdio.h>
#include<stdlib.h>

typedef struct sElemento{
    struct sElemento *next;
    struct sElemento *prev;
    int dado;
}Elemento;

typedef struct sFila{
    struct sElemento *front;
    struct sElemento *rear;
    int size;
}Fila;

Fila* criaFila();
void pqInsert(Fila *fila, int dado);
void pqMinDelete(Fila *fila);
void mostraFila(Fila *fila);
void mostraMin(Fila *fila);
void empty(Fila *fila);
void apagaFila(Fila *fila);

int main(){
    
    Fila* fila= criaFila();
   
    pqInsert(fila, 24);
    mostraFila(fila);
    mostraMin(fila);
    empty(fila);
    pqInsert(fila, 2);
    mostraFila(fila);
    mostraMin(fila);
    empty(fila);
    pqInsert(fila, 43);
    mostraFila(fila);
    mostraMin(fila);
    empty(fila);
    pqInsert(fila, 10);
    mostraFila(fila);
    mostraMin(fila);
    empty(fila);
    pqMinDelete(fila);
    mostraFila(fila);
    mostraMin(fila);
    empty(fila);
    apagaFila(fila);
    mostraFila(fila);
    mostraMin(fila);
    empty(fila); 
}

Fila* criaFila(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->front = NULL;
    fila->rear = NULL;
    fila->size = 0;
    return fila;
}

void pqInsert(Fila *fila, int dado){
    Elemento *insert = (Elemento*)malloc(sizeof(Elemento));
    insert->dado = dado;

    if(fila->size == 0){
        fila->front = insert;
        fila->front->next = NULL;
        fila->front->prev = NULL;
        fila->rear = insert;
    }
    else{
        Elemento *aux_insert = fila->front;
        int i;

        for(i=0; i < fila->size; i++){
            if(aux_insert->next == NULL){
                aux_insert->next = insert;
                insert->next = NULL;
                insert->prev = aux_insert;
                break;
            } 
            aux_insert = aux_insert->next;
        }
    }
    fila->size++;
    printf("Elemento %i foi adicionado com sucesso!!!\n\n", insert->dado);
}

void pqMinDelete(Fila *fila){
    Elemento *del = fila->front;
    int i;
    int min = fila->front->dado;
    Elemento * aux_del;

    for(i=0; i < fila->size; i++){
        if(del->dado < min){
            min = del->dado;
            aux_del = del;
        }
        del = del->next;
    }
    if(aux_del == fila->front){
        fila->front = aux_del->next;

        if(fila->front == NULL){
            fila->rear = NULL;
        }
        else{
            aux_del->next->prev = NULL;
        }
    }
    else{
        aux_del->prev->next = aux_del->next;

        if(aux_del->next == NULL){
            aux_del->prev = fila->rear;
        }
        else{
            aux_del->next->prev = aux_del->prev;
        }
    }
    fila->size--;
    printf("\n\nO elemento %i foi removido da fila!!!\n\n", aux_del->dado);
}

void mostraFila(Fila * fila){
    Elemento *aux = (Elemento*)malloc(sizeof(Elemento));
	aux = fila->front;
	int i;
	 
	for(i=0; i < fila->size; i++){
		printf("%i ", aux->dado);
		aux	= aux->next;
	}
}

void mostraMin(Fila *fila){
    Elemento *del = fila->front;
    int i;
    int min = fila->front->dado;

    for(i=0; i < fila->size; i++){
        if(del->dado < min){
            min = del->dado;
        }
        del = del->next;
    }
    printf("\n\nO menor elemento da fila eh: %i", min);
}

void empty(Fila *fila){
    if(fila->size == 0){
        printf("A fila esta vazia!!!");
    }
    else{
        printf("\n\nA fila possui %i elementos!!!\n\n", fila->size);
    }
}

void apagaFila(Fila *fila){
    Elemento *apaga;

    while(fila->size > 0){
        apaga = fila->front;
        fila->front = apaga->next;

        if(fila->front == NULL){
            fila->rear = NULL;
        }
        else{
            apaga->next->prev = NULL;
        }
        free(apaga);
        fila->size--;
    }
    free(fila);
    printf("A fila foi apagada permanentemente!!!");
}
