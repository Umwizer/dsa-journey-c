
#include <stdio.h>
#include <string.h>
#include "transport.h"

void addBuses(void){
    int n;
    printf("Enter number of buses to add (max %d): ", MAX - busCount);
    scanf("%d", &n);
    if(n <= 0 || n > (MAX - busCount)){
        printf("Invalid number of buses. Please try again.\n");
        return;
    }
    for(int i = 0; i < n; i++){
        printf("Enter details for bus %d:\n", busCount + 1);
        printf("Plate Number: ");
        scanf("%s", fleet[busCount].plateNumber);
        printf("Route Name: ");
        scanf("%s", fleet[busCount].routeName);
        printf("Driver Name: ");
        scanf("%s", fleet[busCount].driverName);
        printf("Capacity: ");
        scanf("%d", &fleet[busCount].capacity);
        printf("Fare: ");
        scanf("%f", &fleet[busCount].fare);
        busCount++;
    }
    printf("\nFleet size is now: %d\n", busCount);
}
void displayFleet(void){
    if(busCount == 0){
        printf("No buses in the fleet.\n");
        return;
    }
    printf("\nCurrent Fleet:\n");
    printf("%-15s %-30s %-30s %-10s %-10s\n", "Plate Number", "Route Name", "Driver Name", "Capacity", "Fare");
    for(int i = 0; i < busCount; i++){
        printf("%-15s %-30s %-30s %-10d %-10.2f\n",
               fleet[i].plateNumber,
               fleet[i].routeName,
               fleet[i].driverName,
               fleet[i].capacity,
               fleet[i].fare);
    }
}