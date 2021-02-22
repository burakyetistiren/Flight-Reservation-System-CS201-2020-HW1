/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#ifndef _RESERVATION_H
#define _RESERVATION_H
class Reservation{
    public:
    Reservation();
    Reservation( unsigned int reservationNo, unsigned int noOfPassengers,
                unsigned int flightNo, const int* seatNumberRow, const char* seatCode);
    ~Reservation();
    unsigned int getReservationNo() const;
    unsigned int getNoOfPassengers() const;
    int* getSeatNumberRow() const;
    char* getSeatCode() const;
    unsigned int getFlightNo() const;
    void setReservationNo(unsigned int reservationNo);
    void setNoOfPassengers(unsigned int noOfPassengers);
    void setflightNo(unsigned int flightNo);
    void setSeatNumberRow( int*& seatNumberRow);
    void setSeatCode( char*& seatCode);
    void operator=(const Reservation &right);

private:
    unsigned int flightNo;
    unsigned int reservationNo;
    unsigned int noOfPassengers;
    int* seatNumberRow;
    char* seatCode;
};
#endif // _RESERVATION_H