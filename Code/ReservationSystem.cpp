/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#include <iostream>
#include "ReservationSystem.h"
using namespace std;

ReservationSystem::ReservationSystem()
{
    flights = new Flight[100];
    reservations = new Reservation[500];
    numberOfFlights = 0;
    numberOfReservations = 0;
}

ReservationSystem::~ReservationSystem()
{
    delete [] flights;
    delete [] reservations;
}

void ReservationSystem::addFlight( const int flightNo, const int rowNo,
                                  const int seatNo )
{

    if( rowNo > 0 && seatNo > 0)
    {
        unsigned int index = 0;
        if( !doesFlightExist(flightNo, index))
        {
            Flight* f = new Flight( flightNo, seatNo, rowNo, seatNo * rowNo);
            flights[numberOfFlights] = *f;

            delete f;

            cout << "Flight " << flightNo << " has been added." << endl;
            numberOfFlights++;
        }
        else
            cout << "Flight " << flightNo << " already exists." << endl;
    }
    else
        cout << "Please enter valid seat & row numbers." << endl;

}

bool ReservationSystem::doesFlightExist(unsigned int flightNoS, unsigned int& index)
{
    for ( int unsigned i = 0; i < numberOfFlights; i++)
        if ( flightNoS == flights[i].getFlightNo())
        {
            index = i;
            return true;
        }

    return false;
}

void ReservationSystem::cancelFlight( const int flightNo)
{
    unsigned int index = 0;
    if( doesFlightExist(flightNo, index))
    {
        for( unsigned int i = index; i < numberOfFlights - 1; i++)
            flights[i] = flights[i+1];
        numberOfFlights--;
		
        for( unsigned int i = 0; i < numberOfReservations; ++i)
            if( flightNo == reservations[i].getFlightNo())
            {
                for( int j = i; j < numberOfReservations; ++j)
                    reservations[i] = reservations[i + 1];
                --numberOfReservations;
            }

        cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;
    }
    else
        cout << "Flight " << flightNo << " does not exist." << endl;
}

int ReservationSystem::getNumberOfFlights()
{
    return numberOfFlights;
}

Flight* ReservationSystem::getFlights()
{
    return flights;
}

void ReservationSystem::showAllFlights()
{
    if(numberOfFlights)
    {
        cout << endl;
        cout << "Flights currently operated:" << endl;
        for( unsigned int i = 0; i < numberOfFlights; ++i)
        {
            cout << "Flight " << flights[i].getFlightNo() << " ("
            << flights[i].getNumberOfUnoccupiedSeats() << " available seats)" << endl;
        }
        cout << endl;
    }
    else
        cout << endl << "No flights exist" << endl << endl;
}

void ReservationSystem::showFlight( const int flightNo )
{
    unsigned int index = 0;
    if(doesFlightExist(flightNo, index))
    {
        cout << endl;
        cout << "Flight " << flightNo << " has "
        << flights[index].getNumberOfUnoccupiedSeats() << " available seats." << endl;

        for( unsigned int i = 65; i < flights[index].getNumberOfSeats() + 65; ++i)
            cout << (char)i << " ";
        cout << endl;

        for( unsigned int i = 1; i < flights[index].getNumberOfRows() + 1; ++i)
        {
            cout << i << " ";
            for( unsigned int j = 0; j < flights[index].getNumberOfSeats(); ++j)
            {
                bool reserved = false;
                for(unsigned int k = 0; k < numberOfReservations; ++k)
                {
                    if( flightNo == reservations[k].getFlightNo())
                    {
                        for( unsigned int m = 0; m < reservations[k].getNoOfPassengers(); ++m)
                        {
                            if( *(reservations[k].getSeatNumberRow() + m) == i && *(reservations[k].getSeatCode() + m) == (char)(j + 65))
                                reserved = true;

                        }
                    }
                }
                if(!reserved)
                    cout << "o ";
                else
                    cout << "x ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
        cout << "Flight " << flightNo << " does not exist." << endl;
}

int ReservationSystem::makeReservation( const int flightNo,
                                       const int numPassengers,
                                       const int *seatRow, const char *seatCol )
{
    unsigned int index = 0;

    bool result = true;
    if ( doesFlightExist(flightNo, index))
    {
        for( unsigned int i = 0; i < numberOfReservations; ++i)
        {
            if(reservations[i].getFlightNo() == flightNo)
            {
                for( unsigned int m = 0; m < numPassengers; ++m)
                    for( unsigned int j = 0; j < reservations[i].getNoOfPassengers(); ++j)
                    {
                        if( seatRow[m] == *((reservations[i].getSeatNumberRow()) + j) && seatCol[m] == *((reservations[i].getSeatCode()) + j))
                        {
                            result = false;
                            cout << seatRow[m] << seatCol[m] << " ";
                        }
                    }
            }
        }
        if( result)
        {
            int resNo = flightNo * 10000 + numberOfReservations + 1;
            Reservation* r = new Reservation( resNo, numPassengers, flightNo, seatRow, seatCol);
            reservations[numberOfReservations] = *r;
            delete r;
            flights[index].setNumberOfUnoccupiedSeats(flights[index].getNumberOfUnoccupiedSeats() - numPassengers);
            numberOfReservations = numberOfReservations + 1;

            return resNo;
        }
        else
            cout << "not available." << endl;
            return -1;
        }
    else
    {
        cout << "Flight " << flightNo << " does not exist.";
        return -1;
    }
}

bool ReservationSystem::findReservation( int &index, int resCode)
{
    for( unsigned int i = 0; i < numberOfReservations; ++i)
        if( resCode == reservations[i].getReservationNo())
        {
            index = i;
            return true;
        }

    return false;
}

void ReservationSystem::cancelReservation( const int resCode )
{
    int index = -1;
    bool exists = findReservation(index, resCode);

    if( exists && index >= 0)
    {
        cout << "Reservation for the seat(s) ";
        for( unsigned int k = 0; k < reservations[index].getNoOfPassengers(); ++k)
            cout << *(reservations[index].getSeatNumberRow() + k)
            << *(reservations[index].getSeatCode() + k) << " ";
        cout << "is canceled in Flight " << reservations[index].getFlightNo() << endl;

        unsigned int flightIndex = 0;
        doesFlightExist(reservations[index].getFlightNo(), flightIndex);

        flights[flightIndex].setNumberOfUnoccupiedSeats(flights[flightIndex].getNumberOfUnoccupiedSeats() + reservations[index].getNoOfPassengers());
        for( ; index < numberOfReservations; ++index)
            reservations[index] = reservations[index + 1];
        --numberOfReservations;

        return;
    }
    cout << "No reservations are found under code " << resCode << endl;
}

void ReservationSystem::showReservation( const int resCode )
{
    int index = -1;
    bool exists = findReservation(index, resCode);
    if(exists)
    {
        cout << endl;
        cout << "Reservations under Code " << resCode << " in Flight "
        << reservations[index].getFlightNo() << ": ";

        for( unsigned int i = 0; i < reservations[index].getNoOfPassengers(); ++i)
            cout << *(reservations[index].getSeatNumberRow() + i)
            << *(reservations[index].getSeatCode() + i) << " ";
        cout << endl;
        return;
    }
    cout << endl << "No reservations under Code " << resCode << endl << endl;
}