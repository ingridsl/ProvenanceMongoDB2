#include <bson.h>
#include <bcon.h>
#include <mongoc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "documents.h"
#include "dataFile.h"
#include "machine.h"
#include "agent.h"

bson_t   *PROVIDER_DOC(provider *proOriginal, cluster *cluOriginal, machine *macOriginal){
	dataFile *aux = macOriginal->dataFiles;
	bson_t   *provider, cluster, machine, dataFiles;
	char     *provider_str;
	bson_oid_t oid;

	bson_oid_init (&oid, NULL);
	provider = BCON_NEW ("_id", BCON_OID (&oid), "key", BCON_UTF8 ("old_value"));
	//cluster = BCON_NEW ("_id", BCON_OID (&oid), "key", BCON_UTF8 ("old_value"));

	//falta machine

	char str_clu_id[15];
	sprintf(str_clu_id, "%d", cluOriginal->id);

	char str_clu_number_machines[15];
	sprintf(str_clu_number_machines, "%d", cluOriginal->number_machines);

	char str_pro_id[15];
	sprintf(str_pro_id, "%d", proOriginal->id);

	char str_pro_localization_id[15];
	sprintf(str_pro_localization_id, "%d", proOriginal->localization_id);

	char str_mac_id[15];
	sprintf(str_mac_id, "%d", macOriginal->id);

	char str_mac_localization_id[15];
	sprintf(str_mac_localization_id, "%d", macOriginal->localization_id);

	char str_mac_ip[36];
	sprintf(str_mac_ip, "%ld", macOriginal->ip);

	char str_mac_cpu[15];
	sprintf(str_mac_cpu, "%d", macOriginal->cpu);

	char str_mac_ram_memory[15];
	sprintf(str_mac_ram_memory, "%d", macOriginal->ram_memory);

	char str_mac_disk[36];
	sprintf(str_mac_disk, "%ld", macOriginal->disk);

	char str_mac_price[36];
	sprintf(str_mac_price, "%ld", macOriginal->price);

	char str_mac_price_type[36];
	sprintf(str_mac_price_type, "%ld", macOriginal->price_type);

	provider = BCON_NEW (
      "id", str_pro_id,
      "name", proOriginal->name,
      "url", proOriginal->url,
      "description", proOriginal->description,
      "localization_id", str_pro_localization_id,
      "localization_region", proOriginal->localization_region,
      "localization_zone", proOriginal->localization_zone
     );

	BSON_APPEND_DOCUMENT_BEGIN(provider, "cluster", &cluster);
	BSON_APPEND_UTF8 (&cluster, "id", str_clu_id);
	BSON_APPEND_UTF8 (&cluster, "name", cluOriginal->name);
	BSON_APPEND_UTF8 (&cluster, "number_machines", str_clu_number_machines);
	BSON_APPEND_UTF8 (&cluster, "description", cluOriginal->description);

	BSON_APPEND_DOCUMENT_BEGIN(&cluster, "machine", &machine);
	BSON_APPEND_UTF8 (&machine, "id", str_mac_id);
	BSON_APPEND_UTF8 (&machine, "hostname", macOriginal->hostname);
	BSON_APPEND_UTF8 (&machine, "ip", str_mac_ip);
	BSON_APPEND_UTF8 (&machine, "type", macOriginal->type);
	BSON_APPEND_UTF8 (&machine, "operational_system", macOriginal->operational_system);
	BSON_APPEND_UTF8 (&machine, "cpu", str_mac_cpu);
	BSON_APPEND_UTF8 (&machine, "ram_memory", str_mac_ram_memory);
	BSON_APPEND_UTF8 (&machine, "disk", str_mac_disk);
	BSON_APPEND_UTF8 (&machine, "disk_type", macOriginal->disk_type);
	BSON_APPEND_UTF8 (&machine, "localization", macOriginal->localization);
	BSON_APPEND_UTF8 (&machine, "price", str_mac_price);
	BSON_APPEND_UTF8 (&machine, "price_type", str_mac_price_type);
	BSON_APPEND_UTF8 (&machine, "localization_id", str_mac_localization_id);
	BSON_APPEND_UTF8 (&machine, "localization_region", macOriginal->localization_region);
	BSON_APPEND_UTF8 (&machine, "localization_zone", macOriginal->localization_zone);
	char str_mac_dataFiles_id[36];
	uint32_t    i;
    char        buf[16];
    const       char *key;
    size_t      keylen;
	BSON_APPEND_ARRAY_BEGIN(&machine, "data_file_id", &dataFiles);
	while(aux != NULL){
		sprintf(str_mac_dataFiles_id, "%d", aux->id);
     	keylen = bson_uint32_to_string (i, &key, buf, sizeof buf);
      	bson_append_utf8 (&dataFiles, key, (int) keylen, str_mac_dataFiles_id, -1);

      	i++;
		aux = aux->next;
	}

	bson_append_array_end(&machine, &dataFiles);
	bson_append_document_end(&cluster, &machine);

	bson_append_document_end(provider, &cluster);
   /*
    * Print the document as a JSON string.
    */
	provider_str = bson_as_json (provider, NULL);
	printf ("\n\t%s\n\n", provider_str);
	bson_free (provider_str);
   /*
    * Clean up allocated bson documents.
    */
	return provider;
}



bson_t   *PROJECT_DOC(project *proOriginal, experiment *expOriginal, activity *activitys, agent *ageOriginal){
	activity *actOriginal = activitys;

	bson_t   *project, experiment, agent;
	char     *project_str;
	bson_oid_t oid;
	int answer = 0;

	bson_oid_init (&oid, NULL);
	project = BCON_NEW ("_id", BCON_OID (&oid), "key", BCON_UTF8 ("old_value"));
	//cluster = BCON_NEW ("_id", BCON_OID (&oid), "key", BCON_UTF8 ("old_value"));

	//falta machine

	char str_pro_id[15];
	sprintf(str_pro_id, "%d", proOriginal->id);

	char str_exp_id[15];
	sprintf(str_exp_id, "%d", expOriginal->id);

	char str_exp_version[15];
	sprintf(str_exp_version, "%d", expOriginal->version);

	char str_exp_execution_time[15];
	sprintf(str_exp_execution_time, "%d", expOriginal->execution_time);

	char str_exp_execution_cost[24];
	sprintf(str_exp_execution_cost, "%f", expOriginal->execution_cost);

	char str_act_execution_status[15];
	sprintf(str_act_execution_status, "%d", actOriginal->execution_status);

	project = BCON_NEW (
      "id", str_pro_id,
      "name", proOriginal->name,
      "description", proOriginal->description,
      "inst_funders", proOriginal->inst_funders,
      "inst_participants", proOriginal->inst_participants,
      "coordinator", proOriginal->coordinator,
      "start_date", proOriginal->start_date,
      "end_date", proOriginal->end_date
     );

	BSON_APPEND_DOCUMENT_BEGIN(project, "experiment", &experiment);
	BSON_APPEND_UTF8 (&experiment, "id", str_exp_id);
	BSON_APPEND_UTF8 (&experiment, "name", expOriginal->name);
	BSON_APPEND_UTF8 (&experiment, "description", expOriginal->description);
	BSON_APPEND_UTF8 (&experiment, "local", expOriginal->local);
	BSON_APPEND_UTF8 (&experiment, "start_date", expOriginal->start_date);
	BSON_APPEND_UTF8 (&experiment, "end_date", expOriginal->end_date);
	BSON_APPEND_UTF8 (&experiment, "annotation", expOriginal->annotation);
	BSON_APPEND_UTF8 (&experiment, "version", str_exp_version);
	BSON_APPEND_UTF8 (&experiment, "version_date", expOriginal->version_date);
	BSON_APPEND_UTF8 (&experiment, "execution_time", str_exp_execution_time);
	BSON_APPEND_UTF8 (&experiment, "execution_cost", str_exp_execution_cost);


	char str_age_id[15];
	sprintf(str_age_id, "%d", ageOriginal->id);

		//comandos daqui
	while(actOriginal->next !=NULL){
		bson_t activity;

		char str_act_id[15];
		sprintf(str_act_id, "%d", actOriginal->id);

		BSON_APPEND_DOCUMENT_BEGIN(&experiment, "activity", &activity);
		BSON_APPEND_UTF8 (&activity, "id", str_act_id);
		BSON_APPEND_UTF8 (&activity, "name", actOriginal->name);
		BSON_APPEND_UTF8 (&activity, "program_name", actOriginal->program_name);
		BSON_APPEND_UTF8 (&activity, "program version", actOriginal->program_version);
		BSON_APPEND_UTF8 (&activity, "command_line", actOriginal->command_line);
		/*BSON_APPEND_UTF8 (&activity, "start_date", actOriginal->start_date);
		BSON_APPEND_UTF8 (&activity, "start_hour", actOriginal->start_hour);
		BSON_APPEND_UTF8 (&activity, "end_date", actOriginal->end_date);
		BSON_APPEND_UTF8 (&activity, "end_hour", actOriginal->end_hour);
		BSON_APPEND_UTF8 (&activity, "execution_status", str_act_execution_status);*/

		BSON_APPEND_DOCUMENT_BEGIN(&activity, "agent", &agent);
		BSON_APPEND_UTF8 (&agent, "id", str_age_id);
		BSON_APPEND_UTF8 (&agent, "name", ageOriginal->name);
		BSON_APPEND_UTF8 (&agent, "login", ageOriginal->login);
		BSON_APPEND_UTF8 (&agent, "instituition", ageOriginal->instituition);
		BSON_APPEND_UTF8 (&agent, "position", ageOriginal->position);
		BSON_APPEND_UTF8 (&agent, "role", ageOriginal->role);
		BSON_APPEND_UTF8 (&agent, "annotation", ageOriginal->annotation);
		bson_append_document_end(&activity, &agent);
		
		
		actOriginal = actOriginal->next;
		bson_append_document_end(&experiment, &activity);
		answer = 0;
	}
	//até aqui
	bson_append_document_end(project, &experiment);
   /*
    * Print the document as a JSON string.
    */
	project_str = bson_as_json (project, NULL);
	printf ("\n\t%s\n\n", project_str);
	bson_free (project_str);
   /*
    * Clean up allocated bson documents.
    */
	return project;
}

bson_t   *DATA_DOC(dataFile *dataOriginal){
	bson_t   *dataFile;
	char     *dataFile_str;
	bson_oid_t oid;

	bson_oid_init (&oid, NULL);
	dataFile = BCON_NEW ("_id", BCON_OID (&oid), "key", BCON_UTF8 ("old_value"));
	//cluster = BCON_NEW ("_id", BCON_OID (&oid), "key", BCON_UTF8 ("old_value"));

	//falta machine
	char str_data_id[15];
	sprintf(str_data_id, "%d", dataOriginal->id);

	char str_data_size[15];
	sprintf(str_data_size, "%d", dataOriginal->size);

	char str_data_machine_id[15];
	sprintf(str_data_machine_id, "%d", dataOriginal->machine_id);

	dataFile = BCON_NEW (
      "id", str_data_id,
      "name", dataOriginal->name,
      "description", dataOriginal->description,
      "localization", dataOriginal->localization,
      "annotation", dataOriginal->annotation,
      "size", str_data_size,
      "insertion_date",dataOriginal->insertion_date,
      "machine_id", str_data_machine_id,
      "type", dataOriginal->type
      //"file", "file"
     );
   /*
    * Print the document as a JSON string.
    */
	dataFile_str = bson_as_json (dataFile, NULL);
	printf ("\n\t%s\n\n", dataFile_str);
	bson_free (dataFile_str);
   /*
    * Clean up allocated bson documents.
    */
	return dataFile;
}
