#include "A4_sort_helpers.h"
#include <stdlib.h>
// Function: read_all() 
// Provided to read an entire file, line by line.
// No need to change this one.
void read_all( char *filename ){
    
    FILE *fp = fopen( filename, "r" );
    int curr_line = 0;
	
    while( curr_line < MAX_NUMBER_LINES && 
           fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) )
    {
        curr_line++;
    }
	
    text_array[curr_line][0] = '\0';
    fclose(fp);
}

// Function: read_all() 
// Provided to read only the lines of a file staring with first_letter.
// No need to change this one.
void read_by_letter( char *filename, char first_letter ){

    FILE *fp = fopen( filename, "r" );
    int curr_line = 0;
    text_array[curr_line][0] = '\0';
	
    while( fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) ){
        if( text_array[curr_line][0] == first_letter ){
            curr_line++;
        }

        if( curr_line == MAX_NUMBER_LINES ){
            sprintf( buf, "ERROR: Attempted to read too many lines from file.\n" );
            write( 1, buf, strlen(buf) );
            break;
        }
    }
	
    text_array[curr_line][0] = '\0';
    fclose(fp);
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q1.
void sort_words( ){
	int numWords = 0;
	while (text_array[numWords][0] != '\0'){
		numWords++;
		}//count total number of words
	for (int i = 1; i < numWords; i++){//recursively insert words into the array of sorted words
	       	int j = i-1;
		char* curWord = (char*)malloc(sizeof(char)*MAX_LINE_LENGTH);//allocate memory
		strcpy(curWord, text_array[i]);//save the current word into curWord
      		while (j >= 0 && strcmp(curWord, text_array[j]) < 0){
			strcpy(text_array[j + 1], text_array[j]);
			//move all the words after curWord in the sorted array one line down to provide a space for curWord
           		j--;
       		}
		strcpy(text_array[j + 1], curWord);//put curWord into its correct position
		free(curWord);
	}
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q2.
sem_t* sem_arr[33]; //initialize global array of semaphores
int initialize( ){
    // Remove the current place-holder code, and write your own.
    //sprintf(buf, "Initializing.\n"  );
    //write(1, buf, strlen(buf));
	char name_arr[30]; //initialize semaphore name
	sprintf(name_arr, "Letter_%c", 'a');//formatted output names to the array
	sem_unlink(name_arr);
	sem_arr[0] = sem_open( name_arr, O_CREAT, 0666, 1 );//sem_open for semaphore with count 1
	for (int i = 1; i < 33; i++){//recursively do sem_open for semaphores with count 0
		sprintf(name_arr, "Letter_%c", 'a'+i);
    		sem_unlink(name_arr);
    		sem_arr[i] = sem_open( name_arr, O_CREAT, 0666, 0 );
    	}
    	
	FILE *fp = fopen("temp.txt", "w");//create a temporary file
	if (fp == NULL){
        	puts("Unable to create temp file");
        	return EXIT_FAILURE;
	}
	fclose(fp);
    	return 0;
}

// YOU MUST COMPLETE THIS FUNCTION FOR Q2 and Q3.   
int process_by_letter( char* input_filename, char first_letter ){
    // For Q2, keep the following 2 lines in your solution (maybe not at the start).
    // Add lines above or below to ensure the "This process will sort..." lines
    // are printed in the right order (alphabetical). 
     
	int i = (int)first_letter - (int)'a';//calculate index of the semaphore
	sem_wait(sem_arr[i]);//start this process
	
    // For Q3, uncomment the following 2 lines and integrate them with your overall solution.
    
	read_by_letter( input_filename, first_letter );//read all the words start with this letter into the array
	sort_words( );//sort words
	
	FILE *fp = fopen("temp.txt", "a");//open the file to append
	if (fp == NULL){
        	puts("Unable to create temp file");
        	return EXIT_FAILURE;
	}//exit if failure
	
	int numWords = 0;
	while (text_array[numWords][0] != '\0'){
		numWords++;
		}//count total number of words
		
	for (int k = 0; k < numWords; k++){//recursively write sorted words into temporary file
		fputs(text_array[k],fp);
		fflush(fp);
	}
	fclose(fp);
	sem_post(sem_arr[i+1]);//notify next process
	return 0;
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q2 and Q3.
int finalize( ){
    // For Q2, keep the following 2 lines in your solution (maybe not at the start).
    // Add lines above or below to ensure the "Sorting complete!" line
    // is printed at the very end, after all letter lines.
    
	sem_wait(sem_arr[26]);
	FILE *fp = fopen("temp.txt", "a");
	if (fp == NULL){
        	puts("Unable to create temp file");
        	return EXIT_FAILURE;
	}
	fputs("Sorting complete!\n",fp);//write the final line into file
	fflush(fp);
	fclose(fp);
	sem_post(sem_arr[27]);

    // For Q3, come up with a way to accumulate the sorted results from each
    // letter process and print the overal sorted values to standard out.
    // You are not allowed to read from the input file, or call sort_words
    // directly from this function.
	
	fopen("temp.txt", "r");
	char* buf2 = (char*)malloc(sizeof(char)*MAX_NUMBER_LINES*MAX_LINE_LENGTH);
	fread(buf2, sizeof(char), MAX_NUMBER_LINES*MAX_LINE_LENGTH, fp );
	//read all contents of temporary file into allocated memory
	write(1,buf2,strlen(buf2));
	//write the sorted words and "sorting complete" into stdout
	fclose(fp);
	free(buf2);
	
	for (int i = 0; i < 33; i++){//recursively do sem_close for all semaphores
		sem_close(sem_arr[i]);
    	}
	
    	return 0;
}

