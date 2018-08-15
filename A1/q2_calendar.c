/*
Yige Feng 260803777
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calendar(int DAYSIZE, int FIRSTDAY);  

int main(int argc, char *argv[]){
	
	if (argc <= 2 || argc > 3) {
		printf("ERROR: Accept exactly 2 command-line arguments.\n");
	}//error when number of arguments incorrect
	
	else{
		int DAYSIZE = strtol(argv[1], NULL, 10);
		int FIRSTDAY = strtol(argv[2], NULL, 10);

		if(DAYSIZE < 2){
			printf("ERROR: Cannot print days smaller than size 2.\n");
			//error when input for DAYSIZE is not a number or the number is not in the range
			if(FIRSTDAY < 1 || FIRSTDAY > 7){
				printf("ERROR: The first day of the week must be between 1 and 7.\n");
			}//error when input for FIRSTDAY is not a number or the number is not in the range
		}

		else{ 
			if(FIRSTDAY < 1 || FIRSTDAY > 7){
				printf("ERROR: The first day of the week must be between 1 and 7.\n");
			}//error when input for FIRSTDAY is not a number or the number is not in the range
		
			else{
				calendar(DAYSIZE, FIRSTDAY);
			}
		}
	}
	return 0;
}

void Month (int monNum, int DAYSIZE){
        char month[10];
	if(monNum == 1){
		char temp[10] = "January";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 2){
		char temp[10] = "February";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 3){
		char temp[10] = "March";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 4){
		char temp[10] = "April";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 5){
		char temp[10] = "May";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 6){
		char temp[10] = "June";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 7){
		char temp[10] = "July";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 8){
		char temp[10] = "August";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 9){
		char temp[10] = "September";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 10){
		char temp[10] = "October";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 11){
		char temp[10] = "November";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	if(monNum == 12){
		char temp[10] = "December";
		for(int i = 0; i < 10; i++){
			month[i] = temp[i];
		}
	}
	printf("|");
	int numOfSym = (3 + DAYSIZE) * 7 + 1;
	int bef = (numOfSym - 2 - strlen(month))/2;
	for (int j = 0; j < bef; j++){
		printf(" ");
	}
	printf("%s", month);
	int aft = numOfSym - bef - 2 - strlen(month);
	for (int j = 0; j < aft; j++){
		printf(" ");
	}
	printf("|\n");

}//print month name

void dashLine(int DAYSIZE){
	int numOfSym = (3 + DAYSIZE) * 7 + 1;
	printf("|");
	for (int i = 0; i < numOfSym - 2; i++){
		printf("-");
	}	
	printf("|\n");								
}//print seperator line

void weekday(int DAYSIZE){
	char* weekday[8] = {"Sunday   ", "Monday   ", "Tuesday  ", "Wednesday", "Thursday ", "Friday   ", "Saturday "};
	for (int i = 0; i < 7; i++){
		printf("|");
		printf(" ");
		if(DAYSIZE < 9){
		for(int j = 0; j < DAYSIZE; j++){
			printf("%c", weekday[i][j]);
			}
		}
		else {
			printf("%s", weekday[i]);
			for(int k = 0; k < DAYSIZE - 9; k++){
				printf(" ");
			}
		}
		printf(" ");
	}	
	printf("|\n");
}//print names of weekdays/weekend days

int day(int DAYSIZE, int FIRSTDAY){
	for (int i = 1; i < FIRSTDAY; i++){
		printf("|");
		for (int nSpace = 0; nSpace < DAYSIZE + 2; nSpace++){
			printf(" ");
		}//print blank days at the start of the month
	}
	int day = 1;
	while (day < 31) {
		printf("| %d ", day);
		char dayStr[10];
		sprintf(dayStr, "%d", day);
		for (int j = 0; j < DAYSIZE - strlen(dayStr); j++){
			printf(" ");
		}
		if (FIRSTDAY == 1 && day % 7 == 0){
			printf("|\n");
		}
		else {
			if (day % 7 == 8 - FIRSTDAY){
				printf("|\n");
			}//turn to next line when a week of days is filled
		}
		day++;
		
	}//print days
	int nSpaceAft = 0;
	int SpaceInd = 29 + FIRSTDAY + nSpaceAft;
	while (SpaceInd % 7 != 0){
		printf("|");
		for (int nSpace = 0; nSpace < DAYSIZE + 2; nSpace++){
			printf(" ");
		}
		nSpaceAft++;
		SpaceInd++;
		if (SpaceInd % 7 == 0){
			printf("|\n");
		}

	}//print blank days at the end of the month
	return nSpaceAft;
}

void calendar(int DAYSIZE, int FIRSTDAY) {
	dashLine(DAYSIZE);
	int nSpaceAft = 0;
	for (int monNum = 1; monNum < 13; monNum++){
		Month (monNum, DAYSIZE);
		dashLine(DAYSIZE);
		
		weekday(DAYSIZE);
		dashLine(DAYSIZE);
				
		nSpaceAft = day(DAYSIZE,FIRSTDAY);
		FIRSTDAY = 8 - nSpaceAft;
		if (FIRSTDAY == 8) {
			FIRSTDAY = 1;
		}
		dashLine(DAYSIZE);
				
	}//recursively print 12 months	
}

	
	
	
	
	
	
	

