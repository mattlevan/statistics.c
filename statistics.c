/*
 * statistics.c
 *
 * A simple C program that calculates statistical values from a list of
 * numbers using multiple processes.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void calc_average(int a[], int a_size) {
    int a_sum = 0;
    int a_average;
    // Add all array contents to a_sum.
    for (int i = 0; i < a_size; i++) {
	    a_sum = a[i] + a_sum; 
    }
    // Obtain average of array contents.
    a_average = a_sum/a_size;
    printf("(child: %d) The average value is %d\n", getpid(), a_average);
}

void calc_max(int a[], int a_size) {
    int a_max = a[0]; // Set a_max equal to the first array value.
    // Loop through remaining array members.
    for (int i = 1; i < a_size; i++) {
	    // Check current array member w/ max. Set a_max to highest value.
	    if (a[i] > a_max) {
    	    a_max = a[i];
	    }
    }
    printf("(child: %d) The maximum value is %d\n", getpid(), a_max);
}

void calc_min(int a[], int a_size) {
    int a_min = a[0]; // Set a_min equal to the first array value.
    // Loop through remaining array members.
    for (int i = 1; i < a_size; i++) {
	    // Check current array member w/a_min. Set a_min to lowest value.
	    if (a[i] < a_min) {
	        a_min = a[i];
	    }
    }
    printf("(child: %d) The minimum value is %d\n", getpid(), a_min);
}

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
        // Declare an int array of size argc-1.
        int a[argc-1];

        // For each integer in the list of args, insert them into a[]. 
        // Start iterating at 1 to ignore the "./statistics.o" arg.
       
        printf("\n");
        printf("(Parent: %d) Using this list of numbers: ", getpid());
        
        for (int i = 1; i < argc; i++) {
            // Start at i-1 to ensure a[0] is used.
            // Use atoi() to convert argv[i] to an integer.
            a[i-1] = atoi(argv[i]); 
            // Print the list of numbers to use.
            printf("%d ", a[i-1]);
       }

        printf("\n");
        // Fork three children, one for each caculation.
        int children = 3; // An int limit for a for loop.
        // pid_t pid[children]; // An array containing pids of children.
        pid_t pid;

        for (int i = 0; i < children; i++) {
            if ((pid = fork()) < 0) {
                perror("Fork failed.\n");
                return 1;
            }
            if (pid == 0) {
                switch(i) {
                    case 0:
                        calc_average(a, (argc-1));
			break;
                    case 1:
                        calc_min(a, (argc-1));
                        break;
                    case 2:
                        calc_max(a, (argc-1));
                        break;
                }
                
                break;
            }
        }
    }                        

    return EXIT_SUCCESS;
}

