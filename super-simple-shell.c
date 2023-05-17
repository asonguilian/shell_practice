#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry Point
 * 
 * Description: This program mimics a shell
 * Return: 0 (Success) or -1 (Failure)
*/

int main(int ac, char *argv[])
{
    /* Declaring my variables */
    char *lineptr, *lineptr_copy = NULL;
    char *delim = " \n";
    size_t n = 0;
    ssize_t leave;
    int num_of_token = 0, i, counter;
    char *token;
    (void) ac;

    /* Starting the infinte loop */
    while (1)
    {
        printf("$ "); // printing the prompt
        leave = getline(&lineptr, &n, stdin);

        /* Condition for exiting the shell */       
        if (leave == -1)
        {
            printf("Exiting...\n");
            return (-1);
        }

        /* Memory allocation for the string copy */
        /**
         * Reason for copying the string?
         * Because after using strtok() om the lineptr string
         * The string will be destroyed so we can have a copy saved
        */
        lineptr_copy = malloc(sizeof(char) * leave);
        if (lineptr_copy == NULL)
        {
            printf("Error: I can't allocate memory");
            return (-1);
        }
        
        /* Making a copy of the string in order to be able to break down the string with strtok */
        strcpy(lineptr_copy, lineptr);

        /* Tokenization of the string */
        token = strtok(lineptr, delim);

        /**
         * We are getting each individual strings from the strtok()
         * When you call strtok() only once, you get only the first string in the string array
         * We're looping so we can get all the strings in the string array
        */
        while (token != NULL)
        {
            num_of_token++;
            token = strtok(NULL, delim);
        }
        num_of_token++; // My guess is that this adds the NULL char num to the total number

        argv = malloc(sizeof(char *) * num_of_token); // Dynamically allocating memory to store the tokens in an array

        /* Storing each of the tokens in the array */
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char *) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim); // This one goes to the next part of the string
        }

        argv[i] = NULL; // Sets the last one to NULL

        printf("%s\n", lineptr);
        free(lineptr);
        free(lineptr_copy);
        free(argv);
    }

 

    return (0);
}
