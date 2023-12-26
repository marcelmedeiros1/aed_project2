#ifndef APP_H
#define APP_H

#include "FlightNetwork.hpp"
#include <cstdlib>

void clearScreen();

class App
{
    FlightNetwork flightnetwork;

public:
    App(FlightNetwork &flightnetwork);
    void mainMenu();

    void statisticsMenu();
    void goBackStatisticsMenu();
    void globalStatistics();
    void showNumFlights();
    void numberOfDestinations(Airport &airport);
};

#endif
