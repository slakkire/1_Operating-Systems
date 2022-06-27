#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

/* Structure to add an ENTRY */
typedef struct {
	string keyword;
	int count;
} Entry;

// char Entry *Table; // OPTIONAL

/* Methods and operations on a table of entries */
Entry *init_table(int count, string *keywords);
void update_table(Entry *t, string keyword, int count);
void display_table(Entry *t, int count);

int main(int argc, char **argv)
{
	int word_count = argc - 1;
	string *word_list = malloc(word_count * sizeof(string));

	int i = 0;
	for (; i < word_count; ++i)
		word_list[i] = argv[i + 1];

	/*=== INITIALIZE A TABLE ===*/
	Entry *t = init_table(word_count, word_list);
	assert(t != NULL);

	/*=== UPDATE THE TABLE ===*/
	string line = NULL;
	size_t maxlen = 0;
	ssize_t n;

	while ((n = getline(&line, &maxlen, stdin)) > 0)
	{
		// Ignore the trailing newline character
		line[strcspn(line, "\n")] = 0x0;

		// Tokenize a line with spaces as delimiters
		char *word = strtok(line, " ");
		while (word != NULL)
		{
			// Update the table by comparing the given word
			update_table(t, word, word_count);
			word = strtok(NULL, " ");
		}
		
		free(word);
	}

	free(line);

	/*=== DISPLAY THE TABLE ===*/
	display_table(t, word_count);

	return EXIT_SUCCESS;
}

// Method to initialize a table - TABLE CONSTRUCTOR
Entry *init_table(int count, string *keywords)
{
	Entry *t = (Entry *) malloc(sizeof(Entry) * count);

	int i = 0;
	for (; i < count; ++i)
	{
		t[i].keyword = keywords[i];
		t[i].count = 0;
	}

	return t;
}

// Method to update a table - UPDATE TABLE
void update_table(Entry *t, string keyword, int count)
{
	int i = 0;
	for (; i < count; ++i)
		if (!strcmp(keyword, t[i].keyword))
		{
			t[i].count += 1;
			break;
		}
}

// Method to display a table - DISPLAY TABLE
void display_table(Entry *t, int count)
{
	if (count > 0)
		printf("Here is the number of times each keyword appears:\n");

	int i = 0;
	for (; i < count; ++i)
		printf("%s: %d\n", t[i].keyword, t[i].count);
}
