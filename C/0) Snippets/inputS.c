void inputS(char* buffer){
	char *p;

	fgets(buffer, BUFFER_SIZE, stdin);
	if((p = strchr(buffer, '\n')) != NULL)
		*p = '\0';
}

void clearBuffer(char* buffer){
	buffer[0] = '\0';
}
