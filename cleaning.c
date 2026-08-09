#include <stdio.h>
#include <string.h>
#include "cleaning.h"

void calculateServiceCost(Booking bookings[], int count)
{
    int id;
    int i;
    int found = 0;
    float extraCharge = 0;

    if (count == 0)
    {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\nEnter Booking ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (bookings[i].bookingId == id)
        {
            found = 1;
            extraCharge = 0;

            if (bookings[i].homeSize > 1500)
            {
                extraCharge = 500;
            }
            else if (bookings[i].homeSize > 1000)
            {
                extraCharge = 300;
            }

            bookings[i].serviceCost += extraCharge;

            printf("\n========== SERVICE COST ==========\n");
            printf("Booking ID     : %d\n",
                   bookings[i].bookingId);

            printf("Service        : %s\n",
                   bookings[i].serviceType);

            printf("Home Size      : %d sq.ft\n",
                   bookings[i].homeSize);

            printf("Base Cost      : Rs. %.2f\n",
                   bookings[i].serviceCost - extraCharge);

            printf("Extra Charge   : Rs. %.2f\n",
                   extraCharge);

            printf("Total Cost     : Rs. %.2f\n",
                   bookings[i].serviceCost);

            break;
        }
    }

    if (!found)
    {
        printf("\nBooking ID %d not found.\n", id);
    }
}

void updateCleaningStatus(Booking bookings[], int count)
{
    int id;
    int choice;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\nEnter Booking ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (bookings[i].bookingId == id)
        {
            found = 1;

            printf("\nCurrent Status: %s\n",
                   bookings[i].status);

            printf("\n1. Booked\n");
            printf("2. Assigned\n");
            printf("3. In Progress\n");
            printf("4. Completed\n");

            printf("Enter new status: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    strcpy(bookings[i].status, "Booked");
                    break;

                case 2:
                    strcpy(bookings[i].status, "Assigned");
                    break;

                case 3:
                    strcpy(bookings[i].status, "In Progress");
                    break;

                case 4:
                    strcpy(bookings[i].status, "Completed");
                    break;

                default:
                    printf("\nInvalid status choice.\n");
                    return;
            }

            printf("\nStatus updated successfully!\n");
            printf("New Status: %s\n",
                   bookings[i].status);

            break;
        }
    }

    if (!found)
    {
        printf("\nBooking ID %d not found.\n", id);
    }
}