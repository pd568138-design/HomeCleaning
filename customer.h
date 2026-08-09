#ifndef CUSTOMER_H
#define CUSTOMER_H

#define MAX_BOOKINGS 100
#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_SERVICE 40
#define MAX_STATUS 20

typedef struct
{
    int bookingId;
    char customerName[MAX_NAME];
    char phone[MAX_PHONE];
    char serviceType[MAX_SERVICE];
    int homeSize;
    float serviceCost;
    char bookingDate[20];
    char status[MAX_STATUS];
} Booking;

void addBooking(Booking bookings[], int *count);
void displayBookings(Booking bookings[], int count);
void searchBooking(Booking bookings[], int count);

#endif