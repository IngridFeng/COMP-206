/*
Yige Feng 260803777
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	if (argc <= 3 || argc > 4) {
		printf("ERROR: Accept exactly 3 command-line arguments.\n");//error when number of arguments incorrect
	}
	else{
		FILE *fptr;
		char string[256];
		fptr = fopen (argv[1], "r");//open the file
		float a = atof (argv[2]);
		float b = atof (argv[3]);
		if (fptr == NULL ){
			printf("Error: bad file\n");
			exit(-1);
		}//bad file when no file is found
		
		int countA = 0;
		int countB = 0;
		while (fgets (string, 256, fptr) != NULL){
			if (strstr(string, "#A#")){
				countA ++;
			}
			if (strstr(string, "#B#")){
				countB ++;
			}
		}
		if (countA != 1 || countB != 1){
			printf("Error: bad file\n");
			exit(-1);
		}//bad file when the number of #A# or #B# in the file is incorrect (none or larger than one)
		
		if (a == 0.000000){
			if (*argv[2] == '0'){}//in case 0 was inputted as a command-line argument
			else{		
				printf("Error: bad float arg\n");
				exit(-1);
			}
		}//bad float arg when a is not a number
		
		if (b == 0.000000){
			if (*argv[2] == '0'){}//in case 0 was inputted as a command-line argument
			else{		
				printf("Error: bad float arg\n");
				exit(-1);
			}
		}//bad float arg when b is not a number
			
		fclose(fptr);
		fptr = fopen (argv[1], "r");
		
		while (fgets (string, 256, fptr) != NULL){
			if (strstr(string, "#A#")){
				printf("a= %.6f\n", a);
			}
			else if (strstr(string, "#B#")){
				printf("b= %.6f\n", b);
			}
			else {
				printf("%s", string);
			}

		}//print out with #A# and #B# replaced by a and b respectively
	
		fclose(fptr);
	}
 	return 0;
}

