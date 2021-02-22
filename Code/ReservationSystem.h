/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#ifndef _RESERVATION_SYSTEM_H
#define _RESERVATION_SYSTEM_H

#include "Reservation.h"
#include "Flight.h"
class ReservationSystem {

public:
    ReservationSystem();
    ~ReservationSystem();
    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers,
    const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );
    bool findReservation( int &index, int resCode);
    bool doesFlightExist(unsigned int flightNo, unsigned int& index);
    int getNumberOfFlights();
    Flight* getFlights();

private:
    Reservation* reservations;
    Flight* flights;
    unsigned int numberOfFlights;
    unsigned int numberOfReservations;
};

#endif // _RESERVATION_SYSTEM_H