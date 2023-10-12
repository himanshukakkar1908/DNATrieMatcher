#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

void add_DNA_to_database(char *sequence)
{
    FILE *file = fopen("dna_database.txt", "a");

    if (file == NULL)
    {
        perror("Unable to open the file");
    }

    // Append the DNA sequence to the file using fputs
    if (fputs(sequence, file) == EOF)
    {
        perror("Error in appending sequence to the file");
    }

    // Append a newline character to start a new line
    fputc('\n', file);

    fclose(file);

    printf("DNA '%s' appended to the file successfully.\n", sequence);
}

void get_DNA_from_database(Trie *trie)
{
    FILE *file = fopen("dna_database.txt", "r");

    if (file == NULL)
    {
        perror("Unable to open the file");
    }

    char line[100]; // Adjust the size as needed to accommodate your longest line

    while (fgets(line, sizeof(line), file))
    {
        // Process the line or print it
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }
        insert(trie, line);
    }

    fclose(file);
}

void remove_DNA_from_database(const char *sequence)
{

    FILE *file = fopen("dna_database.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL)
    {
        perror("Unable to open the file(s)");
        return;
    }

    char line[100]; // Adjust the size as needed to accommodate your longest line

    while (fgets(line, sizeof(line), file))
    {
        // Remove the newline character at the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Remove the newline character at the end of the input sequence
        char trimmedSequence[100]; // Adjust the size as needed
        strcpy(trimmedSequence, sequence);
        trimmedSequence[strcspn(trimmedSequence, "\n")] = '\0';

        // Check if the current line matches the trimmed input sequence
        if (strcmp(line, trimmedSequence) != 0)
        {
            // If not, write it to the temp file
            fputs(line, tempFile);
            fputc('\n', tempFile); // Add a newline to separate lines
        }
    }

    fclose(file);
    fclose(tempFile);

        rename("temp.txt", "dna_database.txt");
    const char *file_path = "./dna_database.txt";
    remove(file_path);
}

int main()
{
    Trie *trie = createTrie();
    printf("\nWELCOME TO THE DNA TRIE MATCHER\n");
    while (1)
    {
        printf("\n Select the operation\n\n 1: Add a DNA sequence  \n\n 2: Search a DNA sequence \n\n 3: Search with prefix \n\n 4: Starts with prefix \n\n 0: Exit the program\n\n");
        int num;
        scanf("%d", &num);
        getchar();
        if (num == 0)
        {
            break;
        }
        char input[100];

        switch (num)
        {

        case 1:
            // Assuming a maximum input length of 100 characters

            while (1)
            {
                printf("\n Enter a DNA sequence to add (or enter 0 to exit) ");
                fgets(input, sizeof(input), stdin);

                if (input[0] > '0' && input[0] <= '9')
                {
                    printf("\nEnter the valid String \n ");
                    continue;
                }

                // Remove the newline character at the end of the input
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, "0") == 0)
                {
                    break; // Exit the loop if the user enters '0'
                }
                else
                {
                    // Insert the user input DNA sequence into the trie
                    // insert(trie, input);
                    add_DNA_to_database(input);
                }
            }
            break;
        case 2:

            get_DNA_from_database(trie);

            while (1)
            {
                printf("\nEnter a DNA sequence to search (or enter 0 to exit)  ");
                fgets(input, sizeof(input), stdin);

                if (input[0] > '0' && input[0] <= '9')
                {
                    printf(" \nEnter the valid String \n");
                    continue;
                }

                // Remove the newline character at the end of the input
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, "0") == 0)
                {
                    break; // Exit the loop if the user enters '0'
                }
                else
                {
                    // Search for the user input DNA sequence in the trie
                    if (search(trie, input))
                    {
                        printf(" \n '%s' found in the trie.\n", input);
                    }
                    else
                    {
                        printf(" \n '%s' not found in the trie.\n", input);
                    }
                }
            }
            break;
        case 3:

            get_DNA_from_database(trie);
            while (1)
            {
                printf("\nEnter a prefix to search with (or enter 0 to exit)  ");
                fgets(input, sizeof(input), stdin);

                if (input[0] > '0' && input[0] <= '9')
                {
                    printf(" \nEnter the valid String value\n");
                    continue;
                }

                // Remove the newline character at the end of the input
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, "0") == 0)
                {
                    break; // Exit the loop if the user enters '0'
                }
                else
                {
                    searchWithPrefix(trie, input);
                }
            }
            break;

        case 4:

            get_DNA_from_database(trie);

            while (1)
            {

                printf("\nEnter a prefix to start with (or enter 0 to exit)  ");
                fgets(input, sizeof(input), stdin);
                int num = 0;
                // printf("%c", input[0]);
                if (input[0] > '0' && input[0] <= '9')
                {
                    printf(" \nEnter the valid String \n");
                    continue;
                }

                // Remove the newline character at the end of the input
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, "0") == 0)
                {
                    break; // Exit the loop if the user enters '0'
                }
                else
                {
                    int get = startsWith(trie, input);
                    if (get == 0)
                    {
                        printf("no DNA sequence that starts with the prefix %s \n", input);
                    }
                    else
                    {
                        printf("yes there is a DNA sequence starts  with prefix %s \n", input);
                    }
                }
            }
            break;
        default:
            printf("\nEnter the valid string \n");
            break;
        }
    }

    return 0;
}
