#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "machine.h"

#if defined(_WIN32) || defined(_WIN64)
        const char* operational_system = "Windows";
#else
#ifdef __linux
        const char* operational_system = "Linux";
#else
        const char* operational_system = "Unknown";
#endif
#endif


machine *create_machine(dataFile *data){
	machine *new = (machine*)malloc(sizeof(machine));

    if(!new){
		printf("\nError");
	    exit(1);
	}

	printf("Type machine's id: ");
	scanf("%d", &new->id);
	printf("Type machine's hostname: ");
	scanf("%s", new->hostname);
	printf("Type machine's ip: ");
	scanf("%ld", &new->ip);
	printf("Type machine's type: ");
	scanf("%s", new->type);
	printf("\nGetting machine's operational system: ");
	strcpy(new->operational_system, operational_system);
	printf("\nType machine's cpu: ");
	scanf("%d", &new->cpu);
	printf("Type machine's ram memory: ");
	scanf("%d", &new->ram_memory);
	printf("Type machine's disk: ");
	scanf("%ld", &new->disk);
	printf("Type machine's disk type: "); 
	scanf("%s", new->disk_type);
	printf("Type machine's price: "); 
	scanf("%ld", &new->price);
	printf("Type machine's price type: "); 
	scanf("%ld", &new->price_type);
	//Localization
	printf("Type machine's localization id: "); 
	scanf("%d", &new->localization_id);
	printf("Type machine's localization region: ");
	scanf("%s", new->localization_region);
	printf("Type machine's localization zone: ");
	scanf("%s", new->localization_zone);

	new->dataFiles = data;

	return new;
}


machine *insert_machine(machine *origin, dataFile *originDataFile){
	machine *aux = origin;
    
	machine *new = create_machine(originDataFile);
	if(aux==NULL){
	    aux = new;
	    new->next = NULL;
	    return new;
	}
	while(aux->next!=NULL){
		aux = aux->next;
	}
	aux->next = new;
	new->next = NULL;
	return origin;
}

void freedom_machine(machine *origin){
    machine *aux1 = origin;

    while(aux1!=NULL){
    	machine *aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }
}

bool existsClusterId(int expIdClu, cluster *originClu){
 	cluster *auxClu = originClu;
    while(auxClu!=NULL){
    	if(expIdClu == auxClu->id)
    		return true;
       	auxClu = auxClu->next;
    }

return false;
}