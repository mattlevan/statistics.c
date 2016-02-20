/*
 * statistics.c
 *
 * A simple C program that calculates statistical values from a list of
 * numbers using multiple processes.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void calc_average(int* a[]);
void calc_min(int* a[]);
void calc_max(int* a[]);

int main(int argc, char* argv[]) {
    // Print a help message if not enough arguments are entered.
    if (argc < 2) {
        printf("\n");
        printf("Not enough arguments!");
        printf("\n");
        printf("Usage: ./statistics.o <list of integers, each separated \ 
by a space>");
        printf("\n");
    }
    // Else, fill an int array with the numbers given in the CLI args.
    else {
        // Declare pid_t var.
        pid_t pid;

        // Declare an int array of size argc-1.
        int a[argc-1];

        // For each integer in the list of args, insert them into a[]. 
        // Start iterating at 1 to ignore the "./statistics.o" arg.
        for (int i = 1; i < argc; i++) {
            // Start at i-1 to ensure a[0] is used.
            // Use atoi() to convert argv[i] to an integer.
            a[i-1] = atoi(argv[i]); 
            printf("Using this list of numbers:\n");
            printf("%d ", a[i-1]);
        }

        // Fork process three times, one for each calculation.
        pid = fork();
        pid = fork();
        pid = fork();

        // Error occured.
        if (pid < 0) {
            printf("Fork failed.\n");
            return 1;
        }
        else if (pid == 0) {
            calc_average(a[0]);
        }
        else if (pid == 1) {

        }
        else if (pid == 2) {

        }
        calc_average(a[0]);
        calc_min(a[0]);
        calc_max(a[0]);
    }

    return EXIT_SUCCESS;
}
