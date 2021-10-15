#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diary.h"

Entry createEntry(int titleLength, int contentLength){
	Entry entry = {
		(char*)malloc((titleLength+100)*sizeof(char)),
		(char*)malloc((contentLength+100)*sizeof(char))
	};
	return entry;
}

void destroyEntry(Entry* entry){
	free(entry->title);
	free(entry->content);
}

void entryCopy(Entry* dest, Entry* src){
	dest->title = src->title;
	dest->content = src->content;
}

Entry newEntry(char* title, char* content){
	Entry entry = createEntry(strlen(title)+1, strlen(content)+1);

	strncpy(entry.title, title, strlen(title)+1);
	strncpy(entry.content, content, strlen(content)+1);

	return entry;
}

void writeTitle(){
	fgets(titleBuffer, TITLE_BUFFER_SIZE, stdin);
	int len = strlen(titleBuffer);
	if (titleBuffer[len-1] == '\n') titleBuffer[len-1] = '\0';
	fixString(titleBuffer);
}

void writeContent(){
	int i=0; for (; i<4; i++) contentBuffer[i] = ' ';
	fgets(contentBuffer+4, CONTENT_BUFFER_SIZE, stdin);
	int len = strlen(contentBuffer);
	if (contentBuffer[len-1] == '\n') contentBuffer[len-1] = '\0';
	fixString(contentBuffer);
}

//Adiciona uma pagina ao entryList
void addEntry(Entry entry){
	numEntries++;
	entryList[numEntries] = entry;
}

void deleteEntry(int index){
	Entry temp = createEntry(strlen(entryList[numEntries].title)+1,
			strlen(entryList[numEntries].content)+1);

	entryCopy(&temp, &entryList[index]);

	int i=index; for (; i<numEntries; i++){
		entryCopy(&entryList[i], &entryList[i+1]);
	}

	entryCopy(&entryList[numEntries], &temp);
	destroyEntry(&entryList[numEntries]);

	numEntries--;
}

void deleteAll(){
	int i=1; for (; i<numEntries; i++){ destroyEntry(&entryList[i]); }
	numEntries = 0;
}

void editEntry(int index){}

void loadInfo(){
	FILE *file = fopen(MAIN_SAVE_FILE, "rb");

	if (file == NULL) return;

	int size;

	//Le as informaçoes do arquivo chamado <MAIN_SAVE_FILE>
	char id[ID_SIZE];
	fread(id, sizeof(char), ID_SIZE, file);
	int n; fread(&n, sizeof(int), 1, file);

	int i=1; for (; i<=n; i++){
		//Le o título
		fread(&size, sizeof(int), 1, file);
		fread(titleBuffer, sizeof(char), size, file);

		//Le o conteúdo
		fread(&size, sizeof(int), 1, file);
		fread(contentBuffer, sizeof(char), size, file);

		//Adiciona uma entrada
		addEntry(newEntry(titleBuffer, contentBuffer));
	}

	fclose(file);
}

void saveInfo(){
	FILE *file = fopen(MAIN_SAVE_FILE, "wb+");
	int size;

	//Salva o resultado em um arquivo chamado <fileName>
	fwrite(ID, sizeof(char), ID_SIZE, file);
	fwrite(&numEntries, sizeof(int), 1, file);

	int i=1; for (; i<=numEntries; i++){
		//Salva o titulo
		size = strlen(entryList[i].title)+1;
		fwrite(&size, sizeof(int), 1, file);
		fwrite(entryList[i].title, sizeof(char), size, file);

		//Salva o conteúdo
		size = strlen(entryList[i].content)+1;
		fwrite(&size, sizeof(int), 1, file);
		fwrite(entryList[i].content, sizeof(char), size, file);
	}

	fclose(file);
}

void showEntryList(){
	int i=1; for (; i<=numEntries; i++){
		printf("%d) ", i);
		showTitle(entryList[i]);
	}
}

void showTitle(Entry entry){
	puts(entry.title);
}

void showContent(Entry entry){
	puts(entry.content);
}

void fixString(char* string){
	int len = strlen(string)+1;
	int MAX_LEN = 80;
	if (len>MAX_LEN){
		int i = MAX_LEN;
		int pos = i;
		int flag = 0;
		for (; i<len && i<=CONTENT_BUFFER_SIZE-MAX_LEN+5; i+=MAX_LEN){
			pos = i;
			if (flag==0){ pos-=2; }
			while (string[i]!= ' '){
				i--;
				if (i<pos-20){
					i=pos;

					while (string[i]!= ' '){
						i++;
						if (i>pos+20){
							i=pos;
							break;
						}
					}

					break;
				}
			}
			pos = i+1;
			memmove(string+pos+1, string+pos, len-pos+1);
			string[pos] = '\n';
			flag = 1;
		}
	}
}

void init(){
	numEntries = 0;
	loadInfo();
}

void finish(){
	puts("\nAdeus explorador. Estou ansioso para saber que aventuras serao escritas na proxima vez "
			"que voce me abrir.");
}

void help(){
	//Printar lista de comandos
	//printf("\nLISTA DE COMANDOS:\n");
	puts("\nLISTA DE COMANDOS:");
	puts("delete -> Deleta uma pagina do diario.");
	puts("delete all -> Deleta todas as paginas do diario.");
	puts("entries -> Mostra todas as paginas do diario.");
	puts("exit -> Sai do programa.");
	puts("help -> Mostra a lista de comandos");
	puts("new -> Adiciona uma nova pagina ao diario.");
	puts("read -> Acessa o conteudo de uma pagina.");
	puts("save -> Salva as informacoes.");
}

