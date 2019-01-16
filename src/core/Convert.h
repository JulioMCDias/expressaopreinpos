/*
 * Convert.h
 *
 *  Created on: 18 de set de 2018
 *      Author: julio
 */

#ifndef CONVERT_H_
#define CONVERT_H_

#include "../define.h"
#include "FuncoesPilha.h"

/**
 * converte a expressão e salva na pilha
 */
extern int prioridade(char operador, int *prio);
extern void inFixoCriaArvore(No **no, char expressao[], int inicio, int fim);
extern void posFixoLigaNos(Pilha **p);
extern void posFixoCriaArvore(No **no, char expressao[]);
extern char *preFixoCriaArvore(No **no, char *expressao);


#endif /* CONVERT_H_ */
