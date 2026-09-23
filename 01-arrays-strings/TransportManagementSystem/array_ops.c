#include <stdio.h>
#include "transport.h"

void inputArray() {
    printf("Enter number of trips (max %d): ", MAX);
    scanf("%d", &count);

    if (count > MAX) {
        printf("Too many! Setting count to %d\n", MAX);
        count = MAX;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter fare for trip %d: ", i + 1);
        scanf("%f", &fare[i]);
    }
}

void displayArray() {
    printf("\nStored Fares:\n");
    for (int i = 0; i < count; i++) {
        printf("Trip %d: %.2f\n", i + 1, fare[i]);
    }

    printf("\nArray Size (MAX): %d\n", MAX);
    printf("Elements Used (count): %d\n", count);
}