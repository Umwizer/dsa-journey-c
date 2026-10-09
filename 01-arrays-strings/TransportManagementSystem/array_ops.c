#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transport.h"

// reads one full line (works with spaces)
static void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';   // remove the enter key
}

// 01. Basic input and output
void addBuses(void) {
    char temp[50];
    int n;

    printf("How many buses do you want to add (max %d)? ", MAX - busCount);
    readLine(temp, sizeof(temp));
    n = atoi(temp);

    if (n <= 0 || n > MAX - busCount) {
        printf("Invalid number of buses.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nBus %d\n", busCount + 1);

        printf("Plate number: ");
        readLine(fleet[busCount].plateNumber, PLATE_LEN);

        printf("Route name: ");
        readLine(fleet[busCount].routeName, NAME_LEN);

        printf("Driver name: ");
        readLine(fleet[busCount].driverName, NAME_LEN);

        printf("Capacity: ");
        readLine(temp, sizeof(temp));
        fleet[busCount].capacity = atoi(temp);

        printf("Fare: ");
        readLine(temp, sizeof(temp));
        fleet[busCount].fare = atof(temp);

        busCount++;
    }
    printf("\nNumber of buses in the fleet: %d\n", busCount);
}

void displayFleet(void) {
    if (busCount == 0) {
        printf("The fleet is empty.\n");
        return;
    }
    printf("\n%-4s %-12s %-22s %-20s %-8s %-8s\n",
           "No", "Plate", "Route", "Driver", "Seats", "Fare");
    for (int i = 0; i < busCount; i++) {
        printf("%-4d %-12s %-22s %-20s %-8d %-8.2f\n", i,
               fleet[i].plateNumber, fleet[i].routeName,
               fleet[i].driverName, fleet[i].capacity, fleet[i].fare);
    }
}

// 02. Statistics on the fares
void fareStatistics(void) {
    if (busCount == 0) {
        printf("The fleet is empty.\n");
        return;
    }

    float total = 0;
    float max = fleet[0].fare;
    float min = fleet[0].fare;

    for (int i = 0; i < busCount; i++) {
        total = total + fleet[i].fare;
        if (fleet[i].fare > max) max = fleet[i].fare;
        if (fleet[i].fare < min) min = fleet[i].fare;
    }
    float average = total / busCount;

    int above = 0, below = 0;
    for (int i = 0; i < busCount; i++) {
        if (fleet[i].fare > average) above++;
        if (fleet[i].fare < average) below++;
    }

    printf("\nTotal   : %.2f\n", total);
    printf("Average : %.2f\n", average);
    printf("Highest : %.2f\n", max);
    printf("Lowest  : %.2f\n", min);
    printf("Above average: %d\n", above);
    printf("Below average: %d\n", below);
}

// 03. Traversal
void traverseFleet(void) {
    if (busCount == 0) {
        printf("The fleet is empty.\n");
        return;
    }

    printf("\nFirst to last:\n");
    for (int i = 0; i < busCount; i++) {
        printf("[%d] %s - %s\n", i, fleet[i].plateNumber, fleet[i].routeName);
    }

    printf("\nLast to first:\n");
    for (int i = busCount - 1; i >= 0; i--) {
        printf("[%d] %s - %s\n", i, fleet[i].plateNumber, fleet[i].routeName);
    }
}

// 04. Insertion
void insertBus(int pos, Bus newBus) {
    if (busCount >= MAX) {
        printf("The fleet is full.\n");
        return;
    }
    if (pos < 0 || pos > busCount) {
        printf("Invalid position.\n");
        return;
    }

    printf("\nBefore insertion:");
    displayFleet();

    // move everything from pos one step to the right
    for (int i = busCount; i > pos; i--) {
        fleet[i] = fleet[i - 1];
    }
    fleet[pos] = newBus;
    busCount++;

    printf("\nAfter insertion:");
    displayFleet();
}

// 05. Deletion
void deleteBus(int pos) {
    if (pos < 0 || pos >= busCount) {
        printf("Invalid position.\n");
        return;
    }

    printf("\nBefore deletion:");
    displayFleet();

    printf("\nDeleting bus %s\n", fleet[pos].plateNumber);

    // move everything after pos one step to the left
    for (int i = pos; i < busCount - 1; i++) {
        fleet[i] = fleet[i + 1];
    }
    busCount--;

    printf("\nAfter deletion:");
    displayFleet();
}

// 06. Linear search (by plate number)
int linearSearchByPlate(const char *plate) {
    int comparisons = 0;

    for (int i = 0; i < busCount; i++) {
        comparisons++;
        if (strcmp(fleet[i].plateNumber, plate) == 0) {
            printf("\nBus %s found at position %d (%d comparisons)\n",
                   plate, i, comparisons);
            return i;
        }
    }
    printf("\nBus %s not found (%d comparisons)\n", plate, comparisons);
    return -1;
}

// sorts the buses by fare, smallest first (bubble sort)
static void sortByFare(void) {
    for (int i = 0; i < busCount - 1; i++) {
        for (int j = 0; j < busCount - 1 - i; j++) {
            if (fleet[j].fare > fleet[j + 1].fare) {
                Bus temp = fleet[j];
                fleet[j] = fleet[j + 1];
                fleet[j + 1] = temp;
            }
        }
    }
}

// 07. Binary search (by fare)
int binarySearchByFare(float fare) {
    sortByFare();   // binary search only works on a sorted array
    printf("\nFleet sorted by fare:");
    displayFleet();

    int low = 0;
    int high = busCount - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        printf("low=%d high=%d mid=%d fare at mid=%.2f\n",
               low, high, mid, fleet[mid].fare);

        if (fleet[mid].fare == fare) {
            printf("Fare %.2f found at position %d\n", fare, mid);
            return mid;
        }
        if (fleet[mid].fare < fare) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Fare %.2f not found\n", fare);
    return -1;
}

// 08. Update
void updateBus(int pos) {
    char temp[50];

    if (pos < 0 || pos >= busCount) {
        printf("Invalid position.\n");
        return;
    }

    printf("\nCurrent: %s | seats: %d | fare: %.2f\n",
           fleet[pos].plateNumber, fleet[pos].capacity, fleet[pos].fare);

    printf("New capacity: ");
    readLine(temp, sizeof(temp));
    fleet[pos].capacity = atoi(temp);

    printf("New fare: ");
    readLine(temp, sizeof(temp));
    fleet[pos].fare = atof(temp);

    printf("Updated: %s | seats: %d | fare: %.2f\n",
           fleet[pos].plateNumber, fleet[pos].capacity, fleet[pos].fare);
}

// 09. Duplicate fares
void findDuplicateFares(void) {
    int checked[MAX] = {0};   // 1 means we already counted this bus
    int found = 0;

    printf("\nDuplicate fares:\n");
    for (int i = 0; i < busCount; i++) {
        if (checked[i] == 1) continue;

        int count = 1;
        for (int j = i + 1; j < busCount; j++) {
            if (fleet[j].fare == fleet[i].fare) {
                count++;
                checked[j] = 1;
            }
        }
        if (count > 1) {
            printf("Fare %.2f appears %d times\n", fleet[i].fare, count);
            found = 1;
        }
    }
    if (found == 0) {
        printf("No duplicate fares.\n");
    }
}

// 10. Reverse
void reverseFleet(void) {
    int left = 0;
    int right = busCount - 1;

    printf("\nOriginal array:");
    displayFleet();

    while (left < right) {
        Bus temp = fleet[left];
        fleet[left] = fleet[right];
        fleet[right] = temp;
        left++;
        right--;
    }

    printf("\nReversed array:");
    displayFleet();
}