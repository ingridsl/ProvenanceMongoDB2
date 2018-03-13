#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "provider.h"

provider *create_provider(){
	provider *new = (provider*)malloc(sizeof(provider));

    if(!new){
		printf("\nError");
	    exit(1);
	}

	printf("Type provider's id: ");
	scanf("%d", &new->id);
	printf("Type provider's name: ");
	scanf("%s", new->name);
	printf("Type provider's url: ");
	scanf("%s", new->url);
	printf("Type provider's description: ");
	scanf("%s", new->description);
	
	//Localization
	printf("Type machine's localization id: "); 
	scanf("%d", &new->localization_id);
	printf("Type machine's localization region: ");
	scanf("%s", new->localization_region);
	printf("Type machine's localization zone: ");
	scanf("%s", new->localization_zone);


	return new;
}


provider *insert_provider(provider *origin){
	provider *aux = origin;
    
	provider *new = create_provider(new);
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

void freedom_provider(provider *origin){
    provider *aux1 = origin;

    while(aux1!=NULL){
    	provider *aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }
}
