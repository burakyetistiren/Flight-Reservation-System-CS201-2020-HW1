/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#ifndef _FLIGHT_H
#include "Reservation.h"
class Flight{
public:
    Flight();
    Flight( unsigned int flightNo, unsigned int numberOfSeats,
            unsigned int numberOfRows, unsigned int numberOfUnoccupiedSeats);
    ~Flight();
    void setFlightNo(unsigned int flightNo);
    void setNumberOfSeats(unsigned int noOfSeats);
    void setNumberOfRows(unsigned int noOfRows);
    void setNumberOfUnoccupiedSeats(unsigned int noOfOccupiedSeats);
    unsigned int getFlightNo() const;
    unsigned int getNumberOfSeats() const;
    unsigned int getNumberOfRows() const;
    unsigned int getNumberOfUnoccupiedSeats() const;
//    Reservation* getReservation(int index) const;
    void operator=(const Flight &right);
//    bool addReservation(const int numPassengers,
//                        const int *seatRow, const char *seatCol, int &resNo);

private:
    unsigned int flightNo;
    unsigned int numberOfSeats;
    unsigned int numberOfRows;
    unsigned int numberOfUnoccupiedSeats;
};
#define _FLIGHT_H
#endif // _FLIGHT_H