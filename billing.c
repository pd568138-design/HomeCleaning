#include <stdio.h>
#include "billing.h"

void generateBill(Booking bookings[], int count)
{
    int id;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\nEnter Booking ID for bill: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (bookings[i].bookingId == id)
        {
            found = 1;

            printf("\n========================================\n");
            printf("        HOME CLEANING SERVICE BILL\n");
            printf("========================================\n");

            printf("Booking ID   : %d\n",
                   bookings[i].bookingId);

            printf("Customer     : %s\n",
                   bookings[i].customerName);

            printf("Phone        : %s\n",
                   bookings[i].phone);

            printf("Service      : %s\n",
                   bookings[i].serviceType);

            printf("Home Size    : %d sq.ft\n",
                   bookings[i].homeSize);

            printf("Booking Date : %s\n",
                   bookings[i].bookingDate);

            printf("Status       : %s\n",
                   bookings[i].status);

            printf("----------------------------------------\n");

            printf("Total Amount : Rs. %.2f\n",
                   bookings[i].serviceCost);

            printf("========================================\n");

            break;
        }
    }

    if (!found)
    {
        printf("\nBooking ID %d not found.\n", id);
    }
}