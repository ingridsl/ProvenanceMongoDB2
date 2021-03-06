#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef project_h
#define project_h

#define N 300

typedef struct project{
	int id;
	char name[N];
	char description[N];
	char inst_funders[N];
	char inst_participants[N];
	char coordinator[N];
	char start_date[N];
	char end_date[N];
	struct project *next;
	char experiment_id[N];
}project;

//inicializa variaveis do projeto
project *create_project();
//insere nós na lista
project *insert_project(project *origin);
//libera memória
void freedom_project(project *origin);

#endif
