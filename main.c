#include "monty.h"
/**
 * main - function to run monty files
 *
 * @argc: int number of args
 * @argv: char const * to args
 *
 * Return: 00
 */

int main(int argc, char const *argv[])
{
	FILE *fp;
	char *linestr = NULL;
	char *opcode = NULL;
	char *data;
	size_t n;
	ssize_t charsprinted;
	unsigned int counter = 0;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((charsprinted = getline(&linestr, &n, fp)) != -1)
	{
		int i = 0;

		counter++;
		while (linestr[i] == ' ')
			i++;
		if (linestr[i] == '#')
			continue;
		linestr = strtok(linestr, "\n");
		opcode = strtok(linestr, " ");
		data = strtok(NULL, " ");
		if (opcode)
			execute(opcode, counter, data);
	}
	fclose(fp);
	free(linestr);
	free_dlistint(head);
	return (0);
}
