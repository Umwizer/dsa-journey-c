#include <stdio.h>
#include "transport.h"

Bus fleet[MAX];
int busCount = 0;
float revenue[MAX][MONTHS];

int main(void) {
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

    return 0;
}