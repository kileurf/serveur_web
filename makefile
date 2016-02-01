#Fichier Makefile racine

#la variable folder contient la liste des sous repertoire

FOLDERS=webserver

#indique les regles qui ne correspondent pas a la creation d un fichier

.PHONY: all $(FOLDERS)

#la regle qio sera execute si on lance make sans arguments

all: $(FOLDERS)

#cette regle va lancer make dans le repertoire webserver
#option -C de make
webserver:
	make -C webserver
