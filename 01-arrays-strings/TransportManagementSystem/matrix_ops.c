#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transport.h"

// reads one full line and removes the enter key
static void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

// 11. Input and display of the revenue matrix
// rows = buses, columns = months
void inputRevenueMatrix(void) {
    char temp[50];

    if (busCount == 0) {
        printf("Add buses first.\n");
        return;
    }

    for (int i = 0; i < busCount; i++) {
        printf("\nRevenue for bus %s\n", fleet[i].plateNumber);
        for (int j = 0; j < MONTHS; j++) {
            printf("  Month %d: ", j + 1);
            readLine(temp, sizeof(temp));
            revenue[i][j] = atof(temp);
        }
    }
    printf("\nRevenue saved.\n");
}

void displayRevenueMatrix(void) {
    if (busCount == 0) {
        printf("The fleet is empty.\n");
        return;
    }

    printf("\n%-14s", "Bus");
    for (int j = 0; j < MONTHS; j++) {
        printf("M%-9d", j + 1);
    }
    printf("\n");

    for (int i = 0; i < busCount; i++) {
        printf("%-14s", fleet[i].plateNumber);
        for (int j = 0; j < MONTHS; j++) {
            printf("%-10.2f", revenue[i][j]);
        }
        printf("\n");
    }
}

// 12. Totals, averages, highest and lowest
void busRevenueStats(void) {
    if (busCount == 0) {
        printf("The fleet is empty.\n");
        return;
    }

    float grandTotal = 0;
    float highest = 0, lowest = 0;
    int highestBus = 0, lowestBus = 0;

    printf("\n%-14s%-12s%-12s\n", "Bus", "Total", "Average");

    for (int i = 0; i < busCount; i++) {
        float total = 0;
        for (int j = 0; j < MONTHS; j++) {
            total = total + revenue[i][j];
        }
        float average = total / MONTHS;
        grandTotal = grandTotal + total;

        printf("%-14s%-12.2f%-12.2f\n", fleet[i].plateNumber, total, average);

        // the first bus is both the highest and the lowest so far
        if (i == 0 || total > highest) {
            highest = total;
            highestBus = i;
        }
        if (i == 0 || total < lowest) {
            lowest = total;
            lowestBus = i;
        }
    }

    printf("\nHighest earning bus: %s (%.2f)\n", fleet[highestBus].plateNumber, highest);
    printf("Lowest earning bus : %s (%.2f)\n", fleet[lowestBus].plateNumber, lowest);
    printf("Fleet average revenue per bus: %.2f\n", grandTotal / busCount);
}

// 13. Matrix addition: result = a + b
void addRevenueMatrices(float a[MAX][MONTHS], float b[MAX][MONTHS], float result[MAX][MONTHS]) {
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nMatrix A:\n");
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            printf("%-10.2f", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            printf("%-10.2f", b[i][j]);
        }
        printf("\n");
    }

    printf("\nA + B:\n");
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            printf("%-10.2f", result[i][j]);
        }
        printf("\n");
    }
}

// 14. Transpose: rows become columns
void transposeMatrix(void) {
    if (busCount == 0) {
        printf("The fleet is empty.\n");
        return;
    }

    float transposed[MONTHS][MAX];

    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            transposed[j][i] = revenue[i][j];
        }
    }

    printf("\nOriginal (bus x month):");
    displayRevenueMatrix();

    printf("\nTransposed (month x bus):\n");
    printf("%-10s", "Month");
    for (int i = 0; i < busCount; i++) {
        printf("%-14s", fleet[i].plateNumber);
    }
    printf("\n");

    for (int j = 0; j < MONTHS; j++) {
        printf("%-10d", j + 1);
        for (int i = 0; i < busCount; i++) {
            printf("%-14.2f", transposed[j][i]);
        }
        printf("\n");
    }
}