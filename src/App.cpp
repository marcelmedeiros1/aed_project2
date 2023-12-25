#include "../inc/App.hpp"
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

App::App(FlightNetwork &flightnetwork)
{
    this->flightnetwork = flightnetwork;
    clearScreen();
    mainMenu();
}

void App::mainMenu()
{
    int option;
    cout << "=================================================================================================" << endl
         << "Welcome to the Flight Network management system!" << endl
         << "Enter your option:" << endl
         << endl
         << "[1] See the statistics of the Flight Network" << endl
         << "[2] Search for the best flight option" << endl
         << endl
         << "[0] Exit" << endl
         << "=================================================================================================" << endl
         << endl
         << "-> ";
    cin >> option;

    clearScreen();

    if (!(option == 0 or option == 1 or option == 2))
    {
        cout << "Invalid option! please try again:" << endl
             << endl;
        mainMenu();
    }

    switch (option)
    {
    case 1:
    {
        clearScreen();
        statisticsMenu();
        break;
    }
    case 2:
    {
        clearScreen();
        // TODO
        break;
    }
    case 0:
    {
        exit(EXIT_SUCCESS);
        break;
    }
    default:
    {
        cout << "Invalid option! please try again:" << endl
             << endl;
        mainMenu();
    }
    }
}

void App::statisticsMenu()
{
    int option;
    cout << "=================================================================================================" << endl
         << "Statistics menu" << endl
         << endl
         << "Enter your option:" << endl
         << "[1] See the global number of airports and number of available flights." << endl
         << "[2] See the number of flights out of an airport (and from how many different airlines)." << endl
         << endl
         << "[0] Go back to the main menu." << endl
         << "=================================================================================================" << endl
         << endl
         << "-> ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        clearScreen();
        globalStatistics();
    }
    case 2:
    {
        string code;
        cout << endl
             << "Enter the airport code:" << endl
             << "-> ";
        cin >> code;
        Airport airport(code);
        clearScreen();
        showNumFlights(airport);
    }
    case 0:
    {
        clearScreen();
        mainMenu();
    }
    default:
    {
        clearScreen();
        cout << "Invalid option! please try again:" << endl
             << endl;
        statisticsMenu();
    }
    }
}

void App::goBackStatisticsMenu()
{
    int option;
    while (true)
    {
        cout << "-> ", cin >> option;
        if (option == 0)
        {
            clearScreen();
            statisticsMenu();
            break;
        }
        else
        {
            cout << "Invalid option, please try again:" << endl
                 << endl;
        }
    }
}

void App::globalStatistics()
{
    cout << "=================================================================================================" << endl
         << "Global number of flights -> " << flightnetwork.getGlobalNumOfFlights() << endl
         << endl
         << "Global number of airports -> " << flightnetwork.getGlobalNumOfAirports() << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;

    goBackStatisticsMenu();
}

void App::showNumFlights(const Airport &airport)
{
    int option;
    pair<int, int> res = flightnetwork.numFlightsAirport(airport);

    cout << "=================================================================================================" << endl
         << "Number of flights out of " << airport.getCode() << ": " << res.first << endl
         << "Number of different airlines: " << res.second << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu" << endl
         << endl;

    goBackStatisticsMenu();
}
