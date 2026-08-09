#include <stdio.h>
#include "customer.h"
#include "cleaning.h"
#include "billing.h"

int main()
{
    Booking bookings[MAX_BOOKINGS];
    int count = 0;
    int choice;

    printf("============================================\n");
    printf("   HOME CLEANING SERVICE MANAGEMENT SYSTEM\n");
    printf("============================================\n");

    printf("\n--------------- MENU ----------------\n");
    printf("1. Add Cleaning Booking\n");
    printf("2. View All Bookings\n");
    printf("3. Search Booking\n");
    printf("4. Calculate Service Cost\n");
    printf("5. Update Cleaning Status\n");
    printf("6. Generate Bill\n");
    printf("7. Exit\n");
    printf("-------------------------------------\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBooking(bookings, &count);
                break;

            case 2:
                displayBookings(bookings, count);
                break;

            case 3:
                searchBooking(bookings, count);
                break;

            case 4:
                calculateServiceCost(bookings, count);
                break;

            case 5:
                updateCleaningStatus(bookings, count);
                break;

            case 6:
                generateBill(bookings, count);
                break;

            case 7:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}