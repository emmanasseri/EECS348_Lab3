/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: emmanasseri
 */

#include <stdio.h>
#include <stdlib.h>

void printMonthName(int monthNum){
	if (monthNum == 0){
		printf("  January      ");
	}
	else if (monthNum == 1){
		printf("  February     ");
	}
	else if (monthNum == 2){
		printf("  March        ");
	}
	else if (monthNum == 3){
		printf("  April        ");
	}
	else if (monthNum == 4){
		printf("  May          ");
	}
	else if (monthNum == 5){
		printf("  June         ");
	}
	else if (monthNum == 6){
		printf("  July         ");
	}
	else if (monthNum == 7){
		printf("  August       ");
	}
	
	else if (monthNum == 8){
		printf("  September    ");
	}
	else if (monthNum == 9){
		printf("  October      ");
	}
	else if (monthNum == 10){
		printf("  November     ");
	}
	else if (monthNum == 11){
		printf("  December     ");
	}
}

void displaySalesReport(float monthData[], int lengthOfList){
	printf("  Month        Sales\n");
	for(int i=0; i <lengthOfList; i++){
		printMonthName(i);
		printf("$");
		printf("%.2f\n", monthData[i]); //this .2 rounds off the value after 2 decimals
	}
	
}

int main(){

	FILE* inputFile;
	//opens input file in read mode
	inputFile = fopen("input.txt", "r");
	float salesData[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	//reads input data from input.txt
	for (int i = 0; i < 12; i++){
		fscanf(inputFile, "%f", &salesData[i]);
	}

	printf("\nMonthly sales report for 2022:\n\n");
	displaySalesReport(salesData, 12);
	printf("\nSales summary\n\n");
	
	printf("\nSix-Month moving average report\n\n");

	printf("\nSales report\n\n");
	
	fclose(inputFile);
	return 0;
	
}
