# ProvenanceMongoDB2

Compile command:
gcc main.c database.c project.c experiment.c activity.c agent.c  provider.c cluster.c machine.c dataFile.c menu.c documents.c -o test


#compilaçoes com MongoC

gcc -o hello_mongoc hello_mongoc.c \
    -I/usr/local/include/libbson-1.0 -I/usr/local/include/libmongoc-1.0 \
    -lmongoc-1.0 -lbson-1.0


gcc -o test_mongoc main.c database.c project.c experiment.c activity.c agent.c  provider.c cluster.c machine.c dataFile.c menu.c documents.c\
    -I/usr/local/include/libbson-1.0 -I/usr/local/include/libmongoc-1.0 \
    -lmongoc-1.0 -lbson-1.0


gcc -o hello_mongoc hello_mongoc.c $(pkg-config --libs --cflags libmongoc-static-1.0)

gcc -o test_mongoc  main.c database.c project.c experiment.c activity.c agent.c  provider.c cluster.c machine.c dataFile.c menu.c providerDoc.c $(pkg-config --libs --cflags libmongoc-static-1.0)


gcc -o hello_mongoc hello_mongoc.c $(pkg-config --libs --cflags libmongoc-1.0)


#compilação usada:
---> gcc -o test_mongoc  main.c database.c project.c experiment.c activity.c agent.c  provider.c cluster.c machine.c dataFile.c  documents.c $(pkg-config --libs --cflags libmongoc-1.0)


