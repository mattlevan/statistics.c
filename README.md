# statistics.c
A simple C program that calculates stastical values from a list of
numbers using multiple processes.

Authors:
  * Matt Levan
  * Nolan Thompson

Professor:
  * Dr. Bin Tang

Course:
  * CSC341
  * Spring 2016

CONTRIBUTIONS
	Matt Levan:
		Command line input acceptance
		Conversion of arguments to integers
		Child process generation and function assignment
		Program organization
		
	Nolan Thompson
		Average function
		Minimum function
		Maximum function
        Readme
		
INSTRUCTIONS STATISTICS.C 
	To use program statistics.c, open the command line terminal and
	navigate to the directory containing the file "statistics.c".  
	Next, compile the C program file "statistics.c" in the desired 
	directory using the command below:
	    
    	Example compile command:
    	user:~/file/path$ gcc -o statistics statistics.c -std=c99
	    *NOTE: You must use C language standard C99 to compile this
	     program.
	
	Following successful compilation of the program, run the program
	by entering the program name "statistics" followed by any 
	number of INTEGER inputs separated by spaces.  Only the integer 
	portion of any float values entered are kept by the program. Any
	string or character arguments are converted to 0.
    
        Example program execution command:
        user:~/program/file/path$ statistics 10 9 8 7 6 c v b s 1.5
        
        Example output:
        (Parent: 7685) Using this list of numbers: 10 9 8 7 6 0 0 0 0 1 
        (child: 7686) The average value is 4
        (child: 7687) The minimum value is 0
        (child: 7688) The maximum value is 10



INSTRUCTIONS TO USE STATISTICS_THREAD.C

	To use the program statistics_thread.c, open the command line
	terminal and navigate to the directory containing the file
	"statistics_thread.c".  Next, compile the C program file in the
	desired directory using the command below:

		Example compile command:
		user:/path$ -pthread -o statsthread statistics_thread.c -std=c99
		*NOTE: You must use C language standard C99 and specify -pthread
		 in the compilation instruction to correctly link to and compile
		 the program using the pthread library.

	Following successful compilation of the program, run it by entering
	the program name "statsthread" follwed by any number of INTEGER
	inputs separated by spaces.  Only the integer portion of any float
	values entered are kept by the program.  Any string or character
	arguments are converted to 0.

		Example program execution command:
		user:~/path$ ./statsthread 1 2 3 4 5 6 10

		Using this list of numbers: 
		1 2 3 4 5 6 10 

		The average value is 4.429
		The maximum value is 10
		The minimum value is 1


