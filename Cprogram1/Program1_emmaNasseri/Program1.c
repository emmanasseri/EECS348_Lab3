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

void displayMonthlySalesReport(float monthData[], int lengthOfList){
	printf("\nMonthly sales report for 2022:\n\n");
	printf("  Month        Sales\n");
	for(int i=0; i <lengthOfList; i++){
		printMonthName(i);
		printf("$");
		printf("%.2f\n", monthData[i]); //this .2 rounds off the value after 2 decimals
	}
	
}



void calculateMinimumSales(float monthData[], int lengthOfList){
	int minimumIndex = 0;
	
	
	for(int i=0; i<lengthOfList;i++){
		if(monthData[i] < monthData[minimumIndex]){
			minimumIndex = i;
		}
	}
	printf("  Minimum sales: %.2f (", monthData[minimumIndex]);
	printMonthName(minimumIndex);
	printf(")\n");

}
void calculateMaximumSales(float monthData[], int lengthOfList){

	int maximumIndex = 0;
		
	for(int i=0; i<lengthOfList;i++){
		if(monthData[i] > monthData[maximumIndex]){
			maximumIndex = i;
		}
	}
	printf("  Maximum sales: %.2f (", monthData[maximumIndex]);
	printMonthName(maximumIndex);
	printf(")\n");

}

void calculateAverageSales(float monthData[], int lengthOfList){
	float sum = 0;
	
	for(int i=0; i<lengthOfList;i++){
		sum += monthData[i];
	}
	printf("  Average sales: %.2f ", sum/lengthOfList);

}

void displaySalesSummary(float monthData[]){
	printf("\nSales summary:\n");
	//calculate minimum sales
	calculateMinimumSales(monthData, 12);
	calculateMaximumSales(monthData, 12);
	calculateAverageSales(monthData, 12);
}

void displayMovingAverageReport(float monthData[]){
	printf("\nSix-Month moving average report:\n\n");
}

void displayOrderedSalesReport(){

	printf("\nSales report:\n\n");
	
}

int main(){

	FILE* inputFile;
	//opens input file in read mode
	inputFile = fopen("input.txt", "r");
	float salesData[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	const char monthArray[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	//reads input data from input.txt
	for (int i = 0; i < 12; i++){
		fscanf(inputFile, "%f", &salesData[i]);
	}


	
	displayMonthlySalesReport(salesData, 12);
	displaySalesSummary(salesData);
	displayMovingAverageReport(salesData);
	displayOrderedSalesReport();
	

	
	fclose(inputFile);
	return 0;
	
}
