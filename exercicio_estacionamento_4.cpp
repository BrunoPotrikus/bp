#include<stdio.h>
#include<stdlib.h>
#define TAM 10

typedef struct sCarro{
	struct sCarro *next;
	struct sCarro *prev;
	int placa;
}Carro;

typedef struct sEstacionamento{
	struct sCarro *head;
	struct sCarro *tail;
	int size;
}Estacionamento;
 
typedef struct sRua{
	struct sCarro *head;
	struct sCarro *tail;
	int size;
}Rua;

Rua* formaFila();
Estacionamento* criaVagas();
void chegaCarro(Rua *rua, Estacionamento *est, int placa);
void liberaVaga(Rua *rua, Estacionamento *est, int placa);
void encontraCarro(Rua *rua, Estacionamento *est);
void mostraEst(Estacionamento *est);
void mostraRua(Rua *rua);

int main(){
	
	Rua *rua = formaFila();
	
	Estacionamento *est = criaVagas();
	
	chegaCarro(rua, est, 1);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 2);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 3);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 4);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 5);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 6);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 7);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 8);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 9);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 10);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 11);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 12);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 13);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 14);
	mostraEst(est);
	mostraRua(rua);
    chegaCarro(rua, est, 15);
	mostraEst(est);
	mostraRua(rua);
    encontraCarro(rua, est);
    liberaVaga(rua, est, 5);
    mostraEst(est);
	mostraRua(rua);
    liberaVaga(rua, est, 2);
    mostraEst(est);
	mostraRua(rua);
}

Rua* formaFila(){
	Rua *rua = (Rua*)malloc(sizeof(Rua));
	rua->head = NULL;
	rua->tail = NULL;
	rua->size = 0;
	return rua;
}

Estacionamento* criaVagas(){
	Estacionamento *est = (Estacionamento*)malloc(sizeof(Estacionamento));
	est->head = NULL;
	est->tail = NULL;
	est->size = 0;
}

void chegaCarro(Rua *rua, Estacionamento *est, int placa){
	
	Carro *entra = (Carro*)malloc(sizeof(Carro));
	entra->placa = placa;
	
	if((est->size < TAM) && (rua->size == 0)){
       
		if(est->size == 0){
            est->head = entra;
			est->head->next = NULL;
			est->head->prev =NULL;
			est->tail = entra;
		}	
		else{
            Carro *aux_entra = est->head;
            int i;

            for(i=0; i < est->size; i++){
                if(aux_entra->next == NULL){
                    aux_entra->next = entra;
                    entra->next = NULL;
                    entra->prev = aux_entra;
                    break;
                }
                aux_entra = aux_entra->next;
            }
	    }
        est->size++;
        printf("\n\nO carro com a placa %i esta estacionado!!!\n\n", entra->placa);
    }
	else{
		printf("\n\nO estacionamento esta lotado!!!\n\n");
		
		if(rua->size == 0){
			rua->head = entra;
            rua->head->next = NULL;
            rua->head->prev = NULL;
            rua->tail = entra;
		}
        else{
            Carro *aux_rua = rua->head;
            int i;

            for(i=0; i < rua->size; i++){
                if(aux_rua->next == NULL){
                    aux_rua->next = entra;
                    entra->next = NULL;
                    entra->prev = aux_rua;
                    break;
                }
                aux_rua = aux_rua->next;
            }
        }
		rua->size++;
        printf("\n\nO carro com a placa %i esta aguardando uma vaga!!!\n\n", entra->placa);
	}	
}

void liberaVaga(Rua *rua, Estacionamento *est, int placa){

    if((est->head != NULL) && (est->size != 0)){
        Carro *sai = est->head;
        int i;

        for(i=0; i < est->size; i++){
            if(sai->placa == placa){
                if(sai == est->head){
                    est->head = sai->next;

                    if(est->head == NULL){
                        est->tail = NULL;
                    }
                    else{
                        sai->next->prev = NULL;
                    }
                }
                else{
                    sai->prev->next = sai->next;

                    if(sai->next == NULL){
                        est->tail = sai->prev;
                    }
                    else{
                        sai->next->prev = sai->prev;
                    }
                }
                free(sai);
                est->size--;
                printf("\n\nO carro com a placa %i saiu do estacionamento!!!\n\n", sai->placa);

                if(rua->size > 0){
                    Carro *in = (Carro*)malloc(sizeof(Carro));
                    int p = rua->head->placa;
                    in->placa = p;
                    Carro *aux_in = est->head;

                    for(i=0; i < est->size; i++){
                        if(aux_in->next == NULL){
                            aux_in->next = in;
                            in->prev = aux_in;
                            in->next = NULL;
                            est->size++;
                            break;
                        }
                        aux_in = aux_in->next;
                    }
                    printf("O carro com a placa %i entrou no estacionamento!!!\n\n", in->placa);

                    Carro *aux_rua = rua->head;
                    rua->head = aux_rua->next;

                    if(rua->head == NULL){
                        rua->tail = NULL;
                    }
                    else{
                        aux_rua->next->prev = NULL;
                    }
                    free(aux_rua);
                    rua->size--;
                } 
                break;
            }
           sai = sai->next; 
        }     
    } 
}

void mostraEst(Estacionamento *est){
	
	Carro *aux = (Carro*)malloc(sizeof(Carro));
	aux = est->head;
	
	int i;
	
	printf("Estacionamento:\n");
	
	for(i=0; i<est->size; i++){
		if(est->head == NULL){
			printf("O estacionamento esta vazio!!!");
		}
		else{
			printf("%i ", aux->placa);
			aux	= aux->next;
		}	
	}
}

void mostraRua(Rua *rua){
	
	Carro *aux = (Carro*)malloc(sizeof(Carro));
	aux = rua->head;
	
	int i;
	
	printf("\nRua:\n");
	
	for(i=0; i<rua->size; i++){
		if(rua->head == NULL){
			printf("Nenhum carro esta aguardando!!!");
		}
		else{
			printf("%i ", aux->placa);
			aux	= aux->next;
		}	
	}	
}

void encontraCarro(Rua *rua, Estacionamento *est){
    Carro *procura_est = est->head;
    int carro = est->head->placa;
    int pos = 1;

    printf("\n\nDigite a placa do carro que voce procura: ");
    scanf("%i", &carro);
    while(procura_est->placa != carro){
        procura_est = procura_est->next;
        pos++;
    }
    printf("\n\nO carro com a placa %i esta na posicao %i do estacionamento!!!\n\n", carro, pos);
}