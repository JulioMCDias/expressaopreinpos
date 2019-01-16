/*
 * FuncoesPilha.c
 *
 *  Created on: 18 de set de 2018
 *      Author: julio
 */

#include "FuncoesPilha.h"

//================== fuções structs ==================

void criaNo(No **no){
	(*no) = malloc(sizeof(No));
	(*no)->dir = NULL;
	(*no)->esq = NULL;
}

void excluirArvore(No **no){
	if((*no)->esq !=NULL)
		excluirArvore(&(*no)->esq);
	if((*no)->dir !=NULL)
		excluirArvore(&(*no)->dir);
	free(*no);
}



void criaPilha(Pilha **pilha){
	*pilha = malloc(sizeof(Pilha));
	(*pilha)->prox = NULL;
	criaNo(&(*pilha)->no);
}

void adicionaPilha(Pilha **pilha, char caracter){
	if(*pilha == NULL){
		criaPilha(pilha);
		(*pilha)->no->elemento = caracter;
		return;
	}
	Pilha *p = *pilha;

	while(p->prox != NULL)
		p = p->prox;
	criaPilha(&p->prox);
	p->prox->no->elemento = caracter;
}

