int main(int argc, char **argv)
{
	shell_loop();

	return EXIT_SUCCESS;
}

void shell_loop()
{
	char *line;
	char **args;
	int status;

	do {
		printf(">");
		line = shell_read_line();
		args = shell_split_line(line);
		status = shell_execute(args);

		free(line);
		free(args):
	} while (status);
}

#define SHELL_RL_BUFSIZE 1024
char *shell_read_line()
{
	int bufsize = SHELL_RL_BUFSIZE:
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		//read character
		c = getchar();

		// if end of file, replace with null character and return
		if (c = EOF || c == "\n") {
			buffer[position] = "\0";
			return buffer;
		} else {
			buffer[position] = c;
		}
		position++;

		// if buffer is exceeded, reallocate
		if (position >= bufsize) {
			bufsize += SHELL_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}	