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
static float readFloatLine(void) {
    char temp[50];
    readLine(temp, sizeof(temp));
    return (float)atof(temp);
}
/* ---------- 11. Matrix Input and Display ---------- */
void inputRevenueMatrix(void) {
    if (busCount == 0) {
        printf("Add buses first (Fleet is empty).\n");
        return;
    }
    for (int i = 0; i < busCount; i++) {
        printf("\nRevenue for bus %s:\n", fleet[i].plateNumber);
        for (int j = 0; j < MONTHS; j++) {
            printf("  Month %d: ", j + 1);        /* FIX: was missing */
            revenue[i][j] = readFloatLine();
        }
    }
    printf("\nRevenue matrix recorded.\n");
}

void displayRevenueMatrix(void) {
    if (busCount == 0) {
        printf("Fleet is empty.\n");
        return;                                    /* FIX: was missing a return */
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

/* ---------- 12. Bus Revenue Statistics ---------- */
void busRevenueStats(void) {
    if (busCount == 0) {
        printf("Fleet is empty.\n");
        return;
    }

    float grandTotal = 0;
    int highestBus = 0, lowestBus = 0;
    float highestTotal = -1, lowestTotal = -1;

    printf("\n%-14s%-10s%-10s\n", "Bus", "Total", "Average");

    for (int i = 0; i < busCount; i++) {
        float total = 0;
        for (int j = 0; j < MONTHS; j++) {
            total += revenue[i][j];
        }
        float average = total / MONTHS;
        grandTotal += total;
        printf("%-14s%-10.2f%-10.2f\n", fleet[i].plateNumber, total, average);

        if (highestTotal == -1 || total > highestTotal) {
            highestTotal = total;
            highestBus = i;
        }
        if (lowestTotal == -1 || total < lowestTotal) {
            lowestTotal = total;
            lowestBus = i;
        }
    }                                                /* FIX: summary block moved OUT of this loop */

    float classAverage = grandTotal / busCount;
    printf("\nHighest-earning bus: %s (%.2f)\n", fleet[highestBus].plateNumber, highestTotal);
    printf("Lowest-earning bus : %s (%.2f)\n", fleet[lowestBus].plateNumber, lowestTotal);
    printf("Overall fleet average revenue: %.2f\n", classAverage);
}

/* ---------- 13. Matrix Addition ---------- */
void addRevenueMatrices(float a[MAX][MONTHS], float b[MAX][MONTHS], float result[MAX][MONTHS]) {
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nMatrix A:\n");
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) printf("%-10.2f", a[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) printf("%-10.2f", b[i][j]);
        printf("\n");
    }

    printf("\nResultant Matrix (A + B):\n");
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) printf("%-10.2f", result[i][j]);
        printf("\n");
    }
}

/* ---------- 14. Matrix Transposition ---------- */
void transposeMatrix(void) {
    if (busCount == 0) {
        printf("Fleet is empty.\n");
        return;
    }

    float transposed[MONTHS][MAX];                  /* FIX: was [MAX][MONTHS], wrong shape for transpose */
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            transposed[j][i] = revenue[i][j];
        }
    }

    printf("\nOriginal matrix (Bus x Month):\n");
    displayRevenueMatrix();

    printf("\nTransposed matrix (Month x Bus):\n");
    printf("%-10s", "Month");
    for (int j = 0; j < busCount; j++) {
        printf("%-10s", fleet[j].plateNumber);
    }
    printf("\n");

    for (int i = 0; i < MONTHS; i++) {
        printf("%-10d", i + 1);
        for (int j = 0; j < busCount; j++) {
            printf("%-10.2f", transposed[i][j]);
        }
        printf("\n");
    }
}