#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diary.h"

#define BUFFER_SIZE 10000

void input(char* buffer);

int main() {
	char buffer[BUFFER_SIZE];
	char frase[BUFFER_SIZE];

	init();

	strncpy(frase,
			"\nBem vindo ao diario do explorador! Voce pode checar as paginas do seu diario digitando "
			"\"entries\", adicionar uma nova pagina digitando \"new\" ou sair do "
			"programa digitando \"exit\". Para acessar a lista de comandos disponiveis, basta "
			"digitar \"help\".",
			BUFFER_SIZE);

	fixString(frase);
	puts(frase);

	do{
		puts("\nO que deseja fazer?");
		input(buffer);

		//Lista de comandos
		if (strcmp(buffer, "delete") == 0){
			if (numEntries == 0){
				puts("\nVoce ainda nao escreveu nada no seu diario! Para adicionar uma "
						"pagina, digite \"new entry\".");
			}else{
				puts("\nDigite o numero da pagina que deseja excluir:");
				input(buffer);
				int num = atoi(buffer);
				if (num > numEntries || num < 0){
					puts("\nPagina nao encontrada! Por favor, insira um numero valido da proxima vez.");
				}else{
					puts("\nTem certeza de que deseja deletar essa pagina? (Y/N)");
					input(buffer);
					if (strcmp(buffer, "Y") == 0 || strcmp(buffer, "y") == 0){
						deleteEntry(num);
						puts("\nPagina deletada!");
					}
				}
			}
		}

		else if (strcmp(buffer, "delete all") == 0){
			puts("\nTem certeza de que deseja deletar todos os seus dados? (Y/N)");
			input(buffer);
			if (strcmp(buffer, "Y") == 0 || strcmp(buffer, "y") == 0){
				deleteAll();
				puts("\nSeus dados foram deletados.");
			}
		}

		else if (strcmp(buffer, "entries") == 0){
			if (numEntries == 0){
				puts("\nVoce ainda nao escreveu nada no seu diario! Para adicionar uma "
						"pagina, digite \"new entry\".");
			}else{
				showEntryList();
			}
		}

		else if (strcmp(buffer, "exit") == 0){
			break;
		}

		else if (strcmp(buffer, "help") == 0){
			help();
		}

		else if (strcmp(buffer, "new") == 0){
			if (numEntries>=500){
				puts("\nVoce alcancou o numero maximo de paginas! Caso deseje escrever outra pagina, "
						"delete uma pagina existente.");
			}
			else{
				//Titulo
				puts("\nEscreva o titulo da sua pagina, e aperte \"Enter\" para salvar o resultado.");
				writeTitle();

				//Conteúdo
				puts("\nEscreva o conteudo da sua pagina, e aperte \"Enter\" para salvar o resultado.");
				writeContent();

				//Cria uma pagina
				addEntry(newEntry(titleBuffer, contentBuffer));
			}
		}

		else if (strcmp(buffer, "read") == 0){
			puts("\nDigite o numero da pagina que deseja ler:");
			input(buffer);
			int num = atoi(buffer);
			if (num > numEntries || num < 0){
				puts("\nPagina nao encontrada! Por favor, insira um numero valido da proxima vez.");
			}else{
				printf("\nPagina %d: ", num);
				showTitle(entryList[num]);
				showContent(entryList[num]);
			}
		}

		else if (strcmp(buffer, "save") == 0){
			puts("\nDeseja salvar suas alteracoes? (Y/N)");
			input(buffer);
			if (strcmp(buffer, "Y") == 0 || strcmp(buffer, "y") == 0){
				saveInfo();
				puts("\nAlteracoes salvas.");
			}else{
				puts("\nSuas alteracoes nao foram salvas.");
			}

		}

		//else if (strcmp(buffer, "test") == 0){ }

		else{
			//Comando nao reconhecido
			strncpy(frase,
					"\nBem, caro explorador, parece que esse comando nao esta incluido na minha lista de "
					"funcoes.\nVoce pode conferir que comandos consigo executar digitando \"help\".",
					BUFFER_SIZE);
			fixString(frase);
			puts(frase);
		}

		//Limpando o buffer
		buffer[0] = '\0';

	}while(1);

	puts("\nDeseja salvar suas alteracoes? (Y/N)");
	input(buffer);
	while (1){
		if (strcmp(buffer, "Y") == 0 || strcmp(buffer, "y") == 0){
			saveInfo();
			puts("\nAlteracoes salvas.");
			break;
		}else if (strcmp(buffer, "N") == 0 || strcmp(buffer, "n") == 0){
			break;
		}
		puts("\nPor favor insira um input valido.");
		input(buffer);
	}

	finish();

	return 0;
}

void input(char* buffer){
	char *p;

	fgets(buffer, BUFFER_SIZE, stdin);
	if((p = strchr(buffer, '\n')) != NULL)
		*p = '\0';
}
