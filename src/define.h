/*
 * define.h
 *
 *  Created on: 18 de set de 2018
 *      Author: julio
 */

#ifndef DEFINE_H_
#define DEFINE_H_

// ------------ include ---------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

// ----------- definições --------------
#define TRUE 1
#define FALSE 0
#define QT_MAX_OPE 10
#define TAM_EXPRESSAO 50


// ----------- structs ----------------
struct No{
	char elemento;
	struct No *esq;
	struct No *dir;
} typedef No;

struct Pilha{
	No *no;
	struct Pilha *prox;
}typedef Pilha;

#endif /* DEFINE_H_ */
