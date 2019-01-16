/*
 * Convert.c
 *
 *  Created on: 18 de set de 2018
 *      Author: julio
 */
#include "Convert.h"

// ------- prioridade ----------
int prioridade(char operador, int *prio){
	switch (operador){
		case '+': case '-':
			if(prio != NULL)
			*prio = 1;
			break;
		case '/': case '*':
			if(prio != NULL)
			*prio = 2;
			break;
		case '^':
			if(prio != NULL)
			*prio = 3;
			break;
		default:
			return FALSE;
	}
	return TRUE;
}



//========================= Criar arvore binaria ==============================

//------------------------------- In Fixo------------------------------
int buscarMenorOpe(char expressao[], int inicio, int fim){
	int i, posOpe = -1, prioFinal = INT_MAX, prioOpe = 0, prioParent = 0;
	for(i=inicio; i<fim; i++){
		if(expressao[i] == '(')
			prioParent += QT_MAX_OPE;

		else if(expressao[i] == ')')
			prioParent -=QT_MAX_OPE;

		else if(prioridade(expressao[i], &prioOpe)){
			if(prioOpe + prioParent <= prioFinal){
				posOpe = i;
				prioFinal = prioOpe + prioParent;
			}
		}
	}
	return posOpe;
}

//------------------------------- In Fixo------------------------------
void inFixoCriaArvore(No **no, char expressao[], int inicio, int fim){
	int index;
	criaNo(no);
	index = buscarMenorOpe(expressao, inicio, fim);
	if(index != -1)
		(*no)->elemento = expressao[index];
	else{
		for(; expressao[inicio] == '('; inicio++);
		(*no)->elemento = expressao[inicio];
		return;
	}

	if(index > inicio)
		inFixoCriaArvore(&(*no)->esq, expressao, inicio, index);
	if(index < fim)
		inFixoCriaArvore(&(*no)->dir, expressao, index+1, fim);
}



//-------------------------- Pos Fixo ----------------------------------
void posFixoLigaNos(Pilha **p){
	Pilha *pilha = NULL;
	while((*p)->prox->prox->prox != NULL)
		p = &(*p)->prox;
	(*p)->prox->prox->no->dir = (*p)->prox->no;
	(*p)->prox->prox->no->esq = (*p)->no;
	pilha = (*p);
	(*p) = (*p)->prox->prox;
	free(pilha->prox);
	free(pilha);
}


void posFixoCriaArvore(No **no, char expressao[]){
	Pilha *pilha = NULL;

	for(; *expressao != '\0'; expressao++){
		adicionaPilha(&pilha,*expressao);

		if(prioridade(*expressao, NULL))
			posFixoLigaNos(&pilha);
	}
	*no = pilha->no;
}


// --------------------- Pre Fixo --------------------------------
char *preFixoCriaArvore(No **no, char *expressao){
	criaNo(no);
	(*no)->elemento = *expressao;
	if(prioridade(*expressao, NULL)){
		expressao = preFixoCriaArvore(&(*no)->esq, expressao+1);
		return preFixoCriaArvore(&(*no)->dir, expressao);
	}
	return expressao+1;
}





