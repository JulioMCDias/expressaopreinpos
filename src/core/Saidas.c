/*
 * Saidas.c
 *
 *  Created on: 28 de out de 2018
 *      Author: julio
 */

#include "Saidas.h"
//==================== Print Saida =====================
//-------------------- In ordem -----------------------
void saidaInFixo(No *no,int prioAnt){
	int prio = prioAnt;
	prioridade(no->elemento, &prio);
	if(prioAnt > prio)
		printf("(");
	if(no->esq != NULL)
		saidaInFixo(no->esq, prio);
	printf("%c",no->elemento);
	if(no->dir != NULL)
		saidaInFixo(no->dir, prio+1);
	if(prioAnt > prio)
		printf(")");
}

//-------------------- Pos ordem -----------------------
void saidaPosFixo(No *no){
	if(no->esq != NULL)
		saidaPosFixo(no->esq);
	if(no->dir != NULL)
		saidaPosFixo(no->dir);
	printf("%c",no->elemento);

}

//-------------------- Pre ordem -----------------------
void saidaPreFixo(No *no){
	printf("%c",no->elemento);
	if(no->esq != NULL)
		saidaPreFixo(no->esq);
	if(no->dir != NULL)
		saidaPreFixo(no->dir);
}
