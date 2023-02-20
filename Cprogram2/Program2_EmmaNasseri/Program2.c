#include <stdio.h>

void possibleScores(int score){
    int touchdown=6;
    int fieldG=3;
    int safety=2;
    int touchDExtra=7;
    int touchDTwo=8;
    for(int x=0; x*touchDTwo<=score; x++){
        int num1=x;
        int total1=touchDTwo*x;
        int rem1=score-total1;
        for(int y=0; y*touchDExtra<=rem1; y++){
            int num2=y;
            int total2=touchDExtra*y;
            int rem2=rem1-total2;
            for(int z=0; z*touchdown<=rem2;z++){
                int num3=z;
                int total3=touchdown*z;
                int rem3=rem2-total3;
                for(int a=0; a*fieldG<=rem3; a++){
                    int num4=a;
                    int total4=fieldG*a;
                    int rem4=rem3-total4;
                    for(int b=0; b*safety<=rem4; b++){
                        int num5=b;
                        int total5=b*safety;
                        int rem5=rem4-total5;
                        if(rem5==0){
                            printf(" %d TD with two extra points + %d TD with extra point + %d TD + %d field goal + %d safety\n", num1, num2, num3, num4, num5);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    while(1){
        int score;
        printf("Enter 1 quit, Enter Score: ");
        scanf(" %d", &score);
        if(score==1){
            break;
        }
        possibleScores(score);
    }

    return 0;
}