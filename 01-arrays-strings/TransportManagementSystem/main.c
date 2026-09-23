
#include <stdio.h>
#include "transport.h"

Bus fleet[MAX];
int busCount = 0;
float revenue[MAX][MONTHS];

int main(void){
    int choice;
    do{
        printf("\n===== TRANSPORT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Bus\n2. Display Fleet\n3. Insert Bus\n4. Delete Bus\n");
        printf("5. Search Bus\n6. Update Bus\n7. Statistics\n8. Duplicates\n");
        printf("9. Reverse Fleet\n10. Revenue Matrix\n11. String Ops\n12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:addBuses();
            break;
            case 2:displayFleet();
            break;
            case 3:insertBus();
            break;
            case 4:DeleteBus();
            break;
            case 5:SearchBus();
            break;
            case 6:UpdateBus();
            break;
            case 7:Statistics();
            break;
            case 8:findDuplicateFares();
            break;
            case 9:reverseFleet();
            break;
            case 10:inputRevenueMatrix();
            break;
            case 11:StringOperations();
            break;
            case 12:printf("Exiting...\n");
            break;
            default:printf("Invalid choice! Please try again.\n");
               
        } 
    }while(choice != 12);
    return 0;
}
