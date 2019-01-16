/*
 ============================================================================
 Name        : ExpressaoPreInPos.c
 Author      : Julio Marques Correa Dias
 Version     : 1.0
 Copyright   : JulioMarquesDeveloper
 Description : Expressão inFix para Pre e PosFix in C, Ansi-style
 ============================================================================
 */

#include "define.h"
#include "core/Saidas.h"
#include "core/Convert.h"
#include "core/FuncoesPilha.h"
#include "core/ValidaExpressao.h"


char telaErro[80]="Erro na expressao";

int main(void) {
	No *no = NULL;
	char expressao[TAM_EXPRESSAO];
	int w = 0;
	while(1){
	w = 0;
		printf("\n|============= Converter expressoes Pre, Pos e In Fixo =================|\n");
	printf("| Expressao: ");
	fgets(expressao, TAM_EXPRESSAO, stdin);

	if(validaInFixo(expressao, &w))
		inFixoCriaArvore(&no, expressao, 0, strlen(expressao));
	else if(validaPosFixo(expressao, &w))
		posFixoCriaArvore(&no, expressao);
	else if(validaPreFixo(expressao, &w))
		preFixoCriaArvore(&no,expressao);
	else{
		printf("%s",telaErro);
	//	return EXIT_SUCCESS;
	}

	printf("\n--------- In Fixo ------------\n");
	saidaInFixo(no, 0);
	printf("\n--------- Pos Fixo ------------\n");
	saidaPosFixo(no);
	printf("\n--------- Pre Fixo ------------\n");
	saidaPreFixo(no);

	excluirArvore(&no);
	}
	return EXIT_SUCCESS;
}
