/*
 * statistics_thread.c
 *
 * A simple C program that calculates statistical values from a list of
 * numbers using multiple threads.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXSIZE 100

void* calc_average();
void* calc_max();
void* calc_min();

int size; // Size of integer array a.
int a[MAXSIZE]; // Pointer to integer array.


int main(int argc, char* argv[]) {
    // Print a help message if not enough arguments are entered.
    if (argc < 2) {
        printf("\n");
        printf("Not enough arguments!");
        printf("\n");
        printf("Usage: ./statistics.o <list of integers, each separated \ 
by a space>");
        printf("\n");

        exit(1);
    }
    else if (argc > MAXSIZE) {
        printf("\n");
        printf("Too many arguments! Try under %d.", MAXSIZE);
        printf("\n");

        exit(1);
    }
    // Else, fill an int array with the numbers given in the CLI args.
    else {
        size = argc - 1;

        // For each integer in the list of args, insert them into a[]. 
        // Start iterating at 1 to ignore the "./statistics.o" arg.
       
        printf("\n");
        printf("Using this list of numbers: ");
        printf("\n");
        
        for (int i = 1; i < argc; i++) {
            // Start at i-1 to ensure a[0] is used.
            // Use atoi() to convert argv[i] to an integer.
            a[i-1] = atoi(argv[i]); 
            // Print the list of numbers to use.
            printf("%d ", a[i-1]);
        }

        printf("\n"); // Print a new line for clarity.
        printf("\n");

        // Number of threads to create.
        int threads = 3;

        for (int i = 0; i < threads; i++) {
            // Thread variables.
            pthread_t tid; // Thread identifier.
            pthread_attr_t attr; // Thread attributes.

            // Initialize each pthread with default attributes.
            pthread_attr_init(&attr);
           
            // Get the default attributes for the thread.
            pthread_attr_init(&attr);

            switch(i) {
                case 0:
                    pthread_create(&tid, &attr, calc_average, NULL);
                    pthread_join(tid, NULL);
			        break;
                case 1:
                    pthread_create(&tid, &attr, calc_max, NULL);
                    pthread_join(tid, NULL);
                    break;
                case 2:
                    pthread_create(&tid, &attr, calc_min, NULL);
                    pthread_join(tid, NULL);
                    break;
            }
        }
    }                        

    return EXIT_SUCCESS;
}

void* calc_average() {
    int sum = 0;
    double average;

    // Add all array contents to sum.
    for (int i = 0; i < size; i++) {
	    sum = a[i] + sum; 
    }
    // Obtain average of array contents.
    average = (double) sum/size;
    printf("The average value is %0.3f\n", average);

    // Finish the thread.
    pthread_exit(0);
}

void* calc_max() {
    int max = a[0]; // Set max equal to the first array value.

    // Loop through remaining array members.
    for (int i = 1; i < size; i++) {
	    // Check current array member w/ max. Set max to highest value.
	    if (a[i] > max) {
    	    max = a[i];
	    }
    }
    printf("The maximum value is %d\n", max);
    
    // Finish the thread.
    pthread_exit(0);
}

void* calc_min() {
    int min = a[0]; // Set a_min equal to the first array value.

    // Loop through remaining array members.
    for (int i = 1; i < size; i++) {
	    // Check current array member w/min. Set min to lowest value.
	    if (a[i] < min) {
	        min = a[i];
	    }
    }
    printf("The minimum value is %d\n", min);

    // Finish the thread.
    pthread_exit(0);
}
