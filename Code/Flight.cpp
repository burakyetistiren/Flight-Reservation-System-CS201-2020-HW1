/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#include "Flight.h"
#include <iostream>
using namespace std;
Flight::Flight()
{
    flightNo = 0;
    numberOfRows = 0;
    numberOfSeats = 0;
}

Flight::Flight( unsigned int flightNoS, unsigned int numberOfSeatsS,
                unsigned int numberOfRowsS, unsigned int numberOfUnoccupiedSeatsS)
{
    flightNo = flightNoS;
    numberOfSeats = numberOfSeatsS;
    numberOfRows = numberOfRowsS;
    numberOfUnoccupiedSeats = numberOfUnoccupiedSeatsS;
}

Flight::~Flight()
{
    //delete[] reservations;
}

void Flight::setFlightNo(unsigned int flightNoS)
{
    flightNo = flightNoS;
}

void Flight::setNumberOfSeats(unsigned int noOfSeats)
{
    numberOfSeats = noOfSeats;
}

void Flight::setNumberOfRows(unsigned int noOfRows)
{
    numberOfRows = noOfRows;
}

unsigned int Flight::getFlightNo() const
{
    return flightNo;
}

unsigned int Flight::getNumberOfSeats() const
{
    return numberOfSeats;
}

unsigned int Flight::getNumberOfRows() const
{
    return numberOfRows;
}

void Flight::operator=(const Flight &right)
{
    flightNo = right.flightNo;
    numberOfRows = right.numberOfRows;
    numberOfSeats = right.numberOfSeats;
    numberOfUnoccupiedSeats = right.numberOfUnoccupiedSeats;
}

void Flight::setNumberOfUnoccupiedSeats(unsigned int noOfUnoccupiedSeats)
{
    numberOfUnoccupiedSeats = noOfUnoccupiedSeats;
}

unsigned int Flight::getNumberOfUnoccupiedSeats() const
{
    return numberOfUnoccupiedSeats;
}