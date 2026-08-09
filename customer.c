#include <stdio.h>
#include <string.h>
#include "customer.h"

void addBooking(Booking bookings[], int *count)
{
    int serviceChoice;

    if (*count >= MAX_BOOKINGS)
    {
        printf("\nBooking storage is full!\n");
        return;
    }

    bookings[*count].bookingId = *count + 1;

    printf("\n========== ADD CLEANING BOOKING ==========\n");

    printf("Enter customer name: ");
    scanf(" %49[^\n]", bookings[*count].customerName);

    printf("Enter phone number: ");
    scanf("%14s", bookings[*count].phone);

    printf("\nSelect Cleaning Service\n");
    printf("1. Basic Home Cleaning     - Rs. 500\n");
    printf("2. Deep Cleaning           - Rs. 1000\n");
    printf("3. Kitchen Cleaning        - Rs. 700\n");
    printf("4. Bathroom Cleaning       - Rs. 600\n");
    printf("5. Full Home Cleaning      - Rs. 1500\n");

    printf("Enter service choice: ");
    scanf("%d", &serviceChoice);

    switch (serviceChoice)
    {
        case 1:
            strcpy(bookings[*count].serviceType,
                   "Basic Home Cleaning");
            bookings[*count].serviceCost = 500;
            break;

        case 2:
            strcpy(bookings[*count].serviceType,
                   "Deep Cleaning");
            bookings[*count].serviceCost = 1000;
            break;

        case 3:
            strcpy(bookings[*count].serviceType,
                   "Kitchen Cleaning");
            bookings[*count].serviceCost = 700;
            break;

        case 4:
            strcpy(bookings[*count].serviceType,
                   "Bathroom Cleaning");
            bookings[*count].serviceCost = 600;
            break;

        case 5:
            strcpy(bookings[*count].serviceType,
                   "Full Home Cleaning");
            bookings[*count].serviceCost = 1500;
            break;

        default:
            printf("\nInvalid service choice!\n");
            return;
    }

    printf("Enter home size (in sq.ft): ");
    scanf("%d", &bookings[*count].homeSize);

    printf("Enter booking date (DD/MM/YYYY): ");
    scanf("%19s", bookings[*count].bookingDate);

    strcpy(bookings[*count].status, "Booked");

    (*count)++;

    printf("\nBooking added successfully!\n");
    printf("Booking ID: %d\n",
           bookings[*count - 1].bookingId);
}

void displayBookings(Booking bookings[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\n========== ALL CLEANING BOOKINGS ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nBooking ID   : %d\n",
               bookings[i].bookingId);

        printf("Customer     : %s\n",
               bookings[i].customerName);

        printf("Phone        : %s\n",
               bookings[i].phone);

        printf("Service      : %s\n",
               bookings[i].serviceType);

        printf("Home Size    : %d sq.ft\n",
               bookings[i].homeSize);

        printf("Cost         : Rs. %.2f\n",
               bookings[i].serviceCost);

        printf("Booking Date : %s\n",
               bookings[i].bookingDate);

        printf("Status       : %s\n",
               bookings[i].status);

        printf("-------------------------------------------\n");
    }
}

void searchBooking(Booking bookings[], int count)
{
    int id;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\nEnter Booking ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (bookings[i].bookingId == id)
        {
            printf("\n========== BOOKING FOUND ==========\n");

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

            printf("Cost         : Rs. %.2f\n",
                   bookings[i].serviceCost);

            printf("Booking Date : %s\n",
                   bookings[i].bookingDate);

            printf("Status       : %s\n",
                   bookings[i].status);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nBooking ID %d not found.\n", id);
    }
}