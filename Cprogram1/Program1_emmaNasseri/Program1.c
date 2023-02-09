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
	printf("\nSales summary:\n\n");
	//calculate minimum sales
	calculateMinimumSales(monthData, 12);
	calculateMaximumSales(monthData, 12);
	calculateAverageSales(monthData, 12);
	printf("\n");
}


void displayMovingAverageReport(float monthData[]){
	printf("\nSix-Month moving average report:\n\n");
	
	for (int i = 0; i < 7; i++){
			if (i == 0){
				printf("  January-June    ");
			}
			else if (i == 1){
				printf("  February-July   ");
			}
			else if (i == 2){
				printf("  March-August    ");
			}
			else if (i == 3){
				printf("  April-September ");
			}
			else if (i == 4){
				printf("  May-October     ");
			}
			else if (i == 5){
				printf("  June-November   ");
			}
			else if (i == 6){
				printf("  July-December   ");
			}
			float miniTotal = 0;
			for (int j = i; j < i + 6; j++){
				miniTotal += monthData[j];
			}
			printf("%.2f\n", miniTotal / 6);
		}

}

void displayOrderedSalesReport(float monthData[], int listLength){

	printf("\nSales report:\n\n");
	
	printf("  Month        Sales\n");
		float maxUsed = 0;
		int useMax = 0;
		int maxmonth = -1;
		float maxAm = 0;
		int sorting = 1;
		while (sorting){
			maxAm = 0;
			maxmonth = -1;

			for (int i = 0; i < listLength; i ++){
				if (!useMax || monthData[i] < maxUsed){
					//check if this is valid
					if (maxmonth == -1 || monthData[i] > maxAm){
						maxAm = monthData[i];
						maxmonth = i;
					}
				}
			}
			if (maxmonth == -1){
				sorting = 0;
				break;
			}
			//print out data
			printMonthName(maxmonth);
			printf("%.2f\n", maxAm);
			//data setup
			useMax = 1;
			maxUsed = maxAm;
		}
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
	displayOrderedSalesReport(salesData, 12);
	

	
	fclose(inputFile);
	return 0;
	
}
