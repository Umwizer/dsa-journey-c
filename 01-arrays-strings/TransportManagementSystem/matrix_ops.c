

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transport.h"


static void readLine(char *buffer,int size){
    fgets(buffer,size,stdin);
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n'){
        buffer[len - 1] = '\0';
    }
}
static float readFloatLine(void){
    char temp[50];
    readLine(temp,sizeof(temp));
    return (float)atof(temp);
}
// 11. Matrix Input and Displays
void inputRevenueMatrix(void){
    if(busCount == 0){
        printf("Add buses first (Fleet is empty). \n");
        return;
    }
    for(int i=0;i<busCount;i++){
        printf("\nRevenue for bus %s:\n",fleet[i].plateNumber);
        for(int j=0;j<MONTHS;j++){
            revenue[i][j] = readFloatLine();
        }
    }
    printf("\n Revenue matrix recorded.\n");
}
void displayRevenueMatrix(void){
    if(busCount == 0 ){
        printf("Fleet is empty. \n");   
    }printf("\n%-14s","Bus");
    for(int j=0;j<MONTHS;j++){
        printf("M%-9d",j+1);
        printf("\n");
    }for(int i=0;i<busCount;i++){
        printf("%-14s",fleet[i].plateNumber);
        for(int j=0;j<MONTHS;j++){
            printf("%-10.2f",revenue[i][j]);
        }
        printf("\n");
    }
}