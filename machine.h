#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cluster.h"
#include "dataFile.h"
#ifndef machine_h
#define machine_h

#define N 300


typedef struct machine{
	int id;
	char hostname[N];
	long ip;
	char type[N];
	char operational_system[N];
	int cpu;
	int ram_memory;
	long disk;
	char disk_type[N];
	char localization[N];
	long price;
	long price_type;

	//localization
	int localization_id;
	char localization_region[N];
	char localization_zone[N];

	dataFile *dataFiles;

	struct machine *next;
}machine;

machine *create_machine(dataFile *data);
machine *insert_machine(machine *origin, dataFile *originDataFile);
void freedom_machine(machine *origin);
bool existsClusterId(int expIdClu, cluster *originClu);
machine *listDataFiles(machine *origin, dataFile *originDataFile);

#endif
