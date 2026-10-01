#include <stdio.h>
#include "transport.h"
#include <string.h>
Bus fleet[MAX];
int busCount = 0;
float revenue[MAX][MONTHS];

int main(void) {
    /* ---------- PART A: Array Operations ---------- */
    addBuses();
    displayFleet();
    fareStatistics();
    traverseFleet();
    Bus extra = {"RAC 999 B", "Kigali-Huye", "Alice K.", 40, 2500.0};
    insertBus(1, extra);
    deleteBus(0);

    linearSearchByPlate("RAC 999 B");
    binarySearchByFare(2500.0);
    updateBus(0);
    findDuplicateFares();
    reverseFleet();

    /* ---------- PART B: Matrix Operations ---------- */
    printf("\n\n===== TESTING MATRIX OPERATIONS =====\n");

    inputRevenueMatrix();
    displayRevenueMatrix();
    busRevenueStats();
    transposeMatrix();

    /* Matrix addition test using current revenue + a "bonus" copy */
    float q1[MAX][MONTHS] = {0}, q2[MAX][MONTHS] = {0}, result[MAX][MONTHS] = {0};
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < MONTHS; j++) {
            q1[i][j] = revenue[i][j];
            q2[i][j] = revenue[i][j] * 0.5f;
        }
    }
    addRevenueMatrices(q1, q2, result);
        /* ---------- PART C: String Operations ---------- */
    printf("\n\n===== TESTING STRING OPERATIONS =====\n");

    analyseRouteString(fleet[0].routeName);
    compareStrings(fleet[0].plateNumber, fleet[1].plateNumber);

    char fullName[60];
    concatenateNames("Jean", "Baptiste", fullName);

    char sub[30];
    extractSubstring(fleet[0].routeName, 0, 6, sub);

    patternMatch(fleet[0].routeName, "Kigali");

    isPalindrome("LEVEL");
    isPalindrome(fleet[0].routeName);

    char toReverse[30];
    strcpy(toReverse, fleet[0].plateNumber);
    reverseString(toReverse);

    char combinedRoutes[200];
    strcpy(combinedRoutes, fleet[0].routeName);
    strcat(combinedRoutes, " ");
    strcat(combinedRoutes, fleet[1].routeName);
    wordFrequency(combinedRoutes);
    return 0;
}