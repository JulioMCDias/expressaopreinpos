/*
 * ValidaExpressao.c
 *
 *  Created on: 30 de out de 2018
 *      Author: julio
 */

#include "ValidaExpressao.h"


// ==================== Infixo =================================
int validaInFixo(char expressao[], int *index);
int validaInFixoElemen(char expressao[], int *index);
int validaInFixoParent(char expressao[], int *index);

//---------------
int validaInFixoElemen(char expressao[], int *index){
	if(expressao[*index] == '\n')
		return TRUE;

	if(prioridade(expressao[*index], NULL)){
		(*index)++;
		return validaInFixo(expressao, index);
	}
	return FALSE;
}
//-----------------
int validaInFixoParent(char expressao[], int *index){
	validaInFixo(expressao, index);
	if(expressao[*index] == ')'){
		(*index)++;
		return validaInFixoElemen(expressao, index);
	}else
		return FALSE;
}
//----------------
int validaInFixo(char expressao[], int *index){
	if(expressao[*index] == '\n')
		return TRUE;
	if(isalnum(expressao[*index])){
		(*index)++;
		return validaInFixoElemen(expressao, index);
	}
	if(expressao[*index] == '('){
		(*index)++;
		return validaInFixoParent(expressao, index);
	}
	return FALSE;
}


//================= Posfixo ==============
int validaPosFixo(char expressao[], int *index){
	int i = *index;
	if(expressao[*index] == '\n')
		return TRUE;
	if(isalnum(expressao[*index])){
		while(1){
			if(expressao[(*index)+1] == '\n')
				return i == 0;
			(*index)++;
			if(isalnum(expressao[*index])){
				if(!validaPosFixo(expressao,index))
					return FALSE;
			}else
				return prioridade(expressao[*index], NULL) && i != 0;
		}
	}
	return FALSE;
}


//=============== Prefixo ================
int validaPreFixo(char expressao[], int *index){
	char expreInver[51];
	int i, j = 0;
	for(i = strlen(expressao)-2; i >= 0; i--)
		expreInver[j++] = expressao[i];
	expreInver[j] ='\n';
	return validaPosFixo(expreInver, index);
}
