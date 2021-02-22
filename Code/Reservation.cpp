/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#include "Reservation.h"
#include <iostream>
using namespace std;
Reservation::Reservation()
{
    flightNo = 0;
    reservationNo = 0;
    noOfPassengers = 0;
    seatNumberRow = NULL;
    seatCode = NULL;
}

Reservation::Reservation( unsigned int reservationNoS, unsigned int noOfPassengersS,
                unsigned int flightNoS, const int* seatNumberRowS, const char* seatCodeS)
{
    reservationNo = reservationNoS;
    noOfPassengers = noOfPassengersS;
    flightNo = flightNoS;

    seatNumberRow = new int[noOfPassengers];
    seatCode = new char[noOfPassengers];

    for( unsigned int i = 0; i < noOfPassengers; i++)
    {
        seatNumberRow[i] = seatNumberRowS[i];
        seatCode[i] = seatCodeS[i];
    }
}

Reservation::~Reservation()
{
    delete [] seatCode;
    delete [] seatNumberRow;
}

unsigned int Reservation::getReservationNo() const
{
    return reservationNo;
}

unsigned int Reservation::getNoOfPassengers() const
{
    return noOfPassengers;
}

int* Reservation::getSeatNumberRow() const
{
    return seatNumberRow;
}

char* Reservation::getSeatCode() const
{
    return seatCode;
}

unsigned int Reservation::getFlightNo() const
{
    return flightNo;
}

void Reservation::setReservationNo(unsigned int reservationNoS)
{
    reservationNo = reservationNoS;
}

void Reservation::setNoOfPassengers(unsigned int noOfPassengersS)
{
    noOfPassengers = noOfPassengersS;
}

void Reservation::setflightNo(unsigned int flightNoS)
{
    flightNo = flightNoS;
}

void Reservation::setSeatNumberRow( int*& seatNumberRowS)
{
    seatNumberRow = seatNumberRowS;
}

void Reservation::setSeatCode( char*& seatCodeS)
{
    seatCode = seatCodeS;
}

void Reservation::operator=(const Reservation &right)
{
    flightNo = right.flightNo;
    reservationNo = right.reservationNo;
    noOfPassengers = right.noOfPassengers;

    delete[] seatNumberRow;
    delete[] seatCode;

    if(right.seatNumberRow)
    {
        seatNumberRow = new int[noOfPassengers];
        for( unsigned int i = 0; i < right.noOfPassengers; ++i)
            seatNumberRow[i] = right.seatNumberRow[i];
    }
    else
        seatNumberRow = NULL;

    if(right.seatCode)
    {
        seatCode = new char[noOfPassengers];
       for( unsigned int i = 0; i < right.noOfPassengers; ++i)
            seatCode[i] = right.seatCode[i];
    }
    else
        seatCode = NULL;
}