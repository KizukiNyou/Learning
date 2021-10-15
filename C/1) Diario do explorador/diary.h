#ifndef DIARY_H_
#define DIARY_H_

#define ID_SIZE 5
#define ID "diary"
#define MAX_ENTRIES 500+1
#define TITLE_BUFFER_SIZE 100000
#define CONTENT_BUFFER_SIZE 100000
#define MAIN_SAVE_FILE "entries"

typedef struct{
	char* title;
	char* content;
} Entry;

Entry entryList[MAX_ENTRIES]; //Array with the list of entries
int numEntries; //Number of entries
char titleBuffer[TITLE_BUFFER_SIZE]; //Buffer for the title
char contentBuffer[CONTENT_BUFFER_SIZE]; //Buffer for the content
//int page; //Counts the pages of the entries

Entry createEntry(int titleLength, int contentLength);
void destroyEntry(Entry* entry);
void entryCopy(Entry* dest, Entry* src);

Entry newEntry(char* title, char* content); //Retorna uma variavel Entry com as informaçoes dadas
void writeTitle();
void writeContent();
void addEntry(Entry entry); //Adiciona uma pagina ao entryList
void deleteEntry(int index);
void deleteAll();
void editEntry(int index);

void loadInfo();
void saveInfo();

void showEntryList(); //Vector of entries
void showTitle(Entry entry);
void showContent(Entry entry);

void fixString(char* string);

void init();
void finish();
void help();

#endif /* DIARY_H_ */
