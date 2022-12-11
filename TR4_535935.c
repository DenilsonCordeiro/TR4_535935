#include "ordvetor.h"

//coloco os valores/separo espaco conforme os atributos da struct vetord nescessitam.
VETORORD* VETORD_create(int n, COMP* compara){
	VETORORD* new_vetord = (VETORORD*)malloc(sizeof(VETORORD));
	new_vetord -> N = n;
	new_vetord -> P = 0;
	new_vetord -> elems = malloc(sizeof(void*)*n);
	new_vetord -> comparador = compara;
	
	return new_vetord;
}

void VETORD_add(VETORORD* vetor, void* newelem) {
	if (vetor->N > vetor->P){//checagem de espaco para no vetor
	vetor->elems[vetor->P] = newelem;//vetor->P = Numero de elementos + 1, logo, novo elemento = ultimo elemento
		for (int i = vetor->P; i > 0; i--){
			if (vetor->comparador(vetor->elems[i-1], vetor->elems[i])==-1){
			//trocar newelem por elemto anterior ate que o newelem esteja na posicao certa(comparador != -1)
				void* aux = vetor->elems[i-1];
				vetor->elems[i-1] = vetor->elems[i];
				vetor->elems[i] = aux;
			}
		}
		vetor->P++;
	}
}

void* VETORD_remove(VETORORD* vetor) {
	//elems[0] e o menor elemento, separado para retorno no aux
	void* aux = vetor->elems[0];
	for (int i = 0; i < vetor->P; i++){
		//todos apartir de elems[1] voltam uma posicao no vetor, excluindo elems[0] que ja foi separado para retorno
		vetor->elems[i] = vetor->elems[i+1];	
	}
	vetor->P--;
	return aux;
}
