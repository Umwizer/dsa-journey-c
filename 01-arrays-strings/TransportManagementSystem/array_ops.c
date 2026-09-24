#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transport.h"

static void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

void addBuses(void) {
    char temp[50];
    int n;
    printf("Enter number of buses to add (max %d): ", MAX - busCount);
    readLine(temp, sizeof(temp));
    n = atoi(temp);
    if (n <= 0 || n > (MAX - busCount)) {
        printf("Invalid number of buses. Please try again.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter details for bus %d:\n", busCount + 1);
        printf("Plate Number: ");
        readLine(fleet[busCount].plateNumber, PLATE_LEN);
        printf("Route Name: ");
        readLine(fleet[busCount].routeName, NAME_LEN);
        printf("Driver Name: ");
        readLine(fleet[busCount].driverName, NAME_LEN);
        printf("Capacity: ");
        readLine(temp, sizeof(temp));
        fleet[busCount].capacity = atoi(temp);
        printf("Fare: ");
        readLine(temp, sizeof(temp));
        fleet[busCount].fare = (float)atof(temp);
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
//02. Array Statistics
void fareStatistics(void) {
    if (busCount == 0) { printf("Fleet is empty.\n"); return; }

    float total = 0, max = fleet[0].fare, min = fleet[0].fare;
    for (int i = 0; i < busCount; i++) {
        total += fleet[i].fare;
        if (fleet[i].fare > max) max = fleet[i].fare;
        if (fleet[i].fare < min) min = fleet[i].fare;
    }
    float average = total / busCount;

    int above = 0, below = 0;
    for (int i = 0; i < busCount; i++) {
        if (fleet[i].fare > average) above++;
        else if (fleet[i].fare < average) below++;
    }

    printf("\nTotal fares : %.2f\n", total);
    printf("Average fare: %.2f\n", average);
    printf("Highest fare: %.2f\n", max);
    printf("Lowest fare : %.2f\n", min);
    printf("Buses above average: %d\n", above);
    printf("Buses below average: %d\n", below);
}
//03. Array Traversal
void traverseFleet(void){
    if(busCount == 0){
     printf("No buses in the fleet to traverse.\n");
     return ;
    }
    printf("\nForward traversal:\n");
    for(int i=0; i < busCount; i++){
         printf("[%d] %s - %s\n", i, fleet[i].plateNumber, fleet[i].routeName);
         printf("\nBackward traversal:\n");
         for(int i = busCount - 1; i >= 0; i--){
             printf("[%d] %s - %s\n", i, fleet[i].plateNumber, fleet[i].routeName);
         }
    }
}
//04.Array Insertion
void insertBus(int pos , Bus newBus){
    if(busCount >= MAX){
        printf("Fleet is full. Cannot insert new bus.\n");
        return;
    }
    if(pos < 0 || pos > busCount){
        printf("Invalid position. Please try again.\n");
        return;
    }
    for(int i = busCount; i > pos; i--){
        fleet[i] = fleet[i - 1];
    }
    fleet[pos] = newBus;
    busCount++;
    printf("Bus inserted at position %d.\n", pos);
}
//05. Array Deletion
void deleteBus(int pos){
    if(busCount == 0){
        printf("Fleet is empty. Cannot delete bus.\n");
        return;
    }
    if(pos < 0 || pos >= busCount){
        printf("Invalid position. Please try again.\n");
        return;
    }
    for(int i = pos; i < busCount - 1; i++){
        fleet[i] = fleet[i + 1];
    }
    busCount--;
    printf("Bus at position %d deleted.\n", pos);
}
//06. Linear Search 
int linearSearchByPlate(const char* plateNumber){
    for(int i = 0; i < busCount; i++){
        if(strcmp(fleet[i].plateNumber, plateNumber) == 0){
            return i; 
        }
    }
    return -1; 
}
//07. Binary Search
static void sortByFare(void){
    for(int i = 0; i < busCount - 1; i++){
        for(int j = 0; j < busCount - i - 1; j++){
            if(fleet[j].fare > fleet[j + 1].fare){
                Bus temp = fleet[j];
                fleet[j] = fleet[j + 1];
                fleet[j + 1] = temp;
            }
        }
    }
}
int binarySearchByFare(float fare){
    sortByFare();
    int left = 0, right = busCount - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(fleet[mid].fare == fare){
            return mid; 
        } else if(fleet[mid].fare < fare){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}
//08. Array Updating
void updateBus(int pos) {
    if (pos < 0 || pos >= busCount) { printf("Invalid position.\n"); return; }

    printf("Current: %s | Capacity: %d | Fare: %.2f\n",
           fleet[pos].plateNumber, fleet[pos].capacity, fleet[pos].fare);

    printf("Enter new capacity: ");
    scanf("%d", &fleet[pos].capacity);
    printf("Enter new fare: ");
    scanf("%f", &fleet[pos].fare);

    printf("Updated: %s | Capacity: %d | Fare: %.2f\n",
           fleet[pos].plateNumber, fleet[pos].capacity, fleet[pos].fare);
}
void findDuplicateFares(void){
    int reported[MAX] = {0};
    int foundAny = 0;

    for(int i = 0; i < busCount; i++){
        if(reported[i]) continue;
        int count = 1;
        for(int j = i + 1; j < busCount; j++){
            if(fleet[i].fare == fleet[j].fare){
                count++;
                reported[j] = 1;
            }
        }
        if(count > 1){
            foundAny = 1;
            printf("Fare %.2f is duplicated %d times.\n", fleet[i].fare, count);
        }
    }
}
void reverseFleet(void){
    for(int i = 0; i < busCount / 2; i++){
        Bus temp = fleet[i];
        fleet[i] = fleet[busCount - 1 - i];
        fleet[busCount - 1 - i] = temp;
    }
    printf("Fleet order reversed.\n");
}