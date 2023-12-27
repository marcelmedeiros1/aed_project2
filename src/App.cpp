#include "../inc/App.hpp"
using namespace std;

// g++ -o App App.cpp FlightNetwork.cpp Airline.cpp Airport.cpp

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
         << "[2] See the number of flights out of an airport (and from how many different airlines), city or airline." << endl
         << "[3] See the number of countries that a given airport flies to." << endl
         << "[4] See the number of countries that a given city flies to." << endl
         << "[5] See number of destinations (airports, cities or countries) available for a given airport." << endl
         << "[6] See Number of reachable destinations (airports, cities or countries) from a given airport in a maximum number of X stops (lay-overs)." << endl 
         << "[7] See the maximum trip available (the trip with the most stops)." << endl 
         << "[8] See the top K airports with the greatest air traffic capacity." << endl
         << "[9] See the airports that are essential to the network's circulation capacability." << endl
         << endl
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
        clearScreen();
        showNumFlights();
    }
    case 3:
    {
        clearScreen();
        string code;
        cout << endl
             << "Enter the airport code:" << endl
             << "-> ";
        cin >> code;
        Airport airport(code);

        set<string> res = flightnetwork.getDiffCountriesAirport(airport);

        cout << "=================================================================================================" << endl
         << "Countries: " << endl;

        int count = 1;
        for(string country : res){
            cout << "[" << count << "]" << " " << country << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();

    }
    case 4: 
    {
        clearScreen();
        string city;
        cout << endl
             << "Enter the city name:" << endl
             << "-> ";
        cin >> city;
        set<string> res = flightnetwork.getDiffCountriesCity(city);
        cout << "=================================================================================================" << endl
         << "Countries: " << endl;

        int count = 1;
        for(string country : res){
            cout << "[" << count << "]" << " " << country << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
    }
    case 5:
    {
        clearScreen();
        string code;
        cout << endl
             << "Enter the airport code:" << endl
             << "-> ";
        cin >> code;
        Airport airport(code);

        numberOfDestinations(airport);
    }
    case 6:
    {
        clearScreen();
        string code;
        cout << endl
             << "Enter the airport code:" << endl
             << "-> ";
        cin >> code;
        Airport airport(code);

        int stops;
        cout << endl
             << "Enter the maximum number of stops allowed:" << endl
             << "-> ";
        cin >> stops;

        reachableDest(airport, stops);
    }
    case 7: 
    {
        clearScreen();
        vector<pair<string, string>> airports;
        int res = flightnetwork.maximumTrip(airports);
        cout << "=================================================================================================" << endl
         << "The maximum trip has: " << res  << " stops" << endl
         << "The flights are: " << endl;

        int count = 1;
        for(pair<string,string> sourcdest : airports){
            cout << "[" << count << "]" << " from " << sourcdest.first << " to " << sourcdest.second << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
    }
    case 8:
    {
        clearScreen();
        int k;
        cout << endl
             << "Enter the number of top airports you want to find:" << endl
             << "-> ";
        cin >> k;
        set<string> res = flightnetwork.getGreatestTraffic(k);
        cout << "=================================================================================================" << endl
         << "Top " << k << " airports with the greatest air traffic capacity: " << endl;

        int count = 1;
        for(string country : res){
            cout << "[" << count << "]" << " " << country << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
    }
    case 9:
    {
        clearScreen();
        set<string> res = flightnetwork.getEssentialAirports();
        cout << "=================================================================================================" << endl
         << "The airports that are essential to the network are: " << endl;

        int count = 1;
        for(string airport : res){
            cout << "[" << count << "]" << airport << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
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

void App::showNumFlights()
{
    int option;

    cout << "=================================================================================================" << endl
         << "Number of flights out of: "
         << "Enter your option:" << endl
         << "[1] Airport" << endl
         << "[2] City" << endl
         << "[3] Airline" << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the main menu" << endl
         << endl;


    cin >> option;

    switch (option)
    {
    case 1:
    {
        clearScreen();
        string code;
        cout << endl
             << "Enter the airport code:" << endl
             << "-> ";
        cin >> code;
        Airport airport(code);

        pair<int, int> res = flightnetwork.numFlightsAirport(airport);
        cout << "=================================================================================================" << endl
         << "Number of flights out of " << airport.getCode() << ": " << res.first << endl
         << "Number of different airlines: " << res.second << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu" << endl
         << endl;
         goBackStatisticsMenu();
    }
    case 2:
    {
        clearScreen();
        string city;
        cout << endl
             << "Enter the city name:" << endl
             << "-> ";
        cin >> city;
        int res = flightnetwork.numFlightsCity(city);
        cout << "=================================================================================================" << endl
         << "Number of flights out of " << city
         << " is " << res << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu" << endl
         << endl;
         goBackStatisticsMenu();
    }
    case 3:
    {
        clearScreen();
        string code;
        cout << endl
             << "Enter the airline code:" << endl
             << "-> ";
        cin >> code;
        Airline airline(code);
        int res = flightnetwork.numFlightsAirline(airline);
        cout << "=================================================================================================" << endl
         << "Number of flights out of " << code
         << " is " << res << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu" << endl
         << endl;
         goBackStatisticsMenu();
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

void App::numberOfDestinations(Airport &airport){
     int option;

    cout << "=================================================================================================" << endl
         << "Select the type of destination!"
         << "Enter your option:" << endl
         << "[1] Airport" << endl
         << "[2] City" << endl
         << "[3] Country" << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the main menu" << endl
         << "-> " << endl;


    cin >> option;

    switch (option)
    {
    case 1:
    {
        clearScreen();
        set<string> res = flightnetwork.getAirportsDestinations(airport);
        cout << "=================================================================================================" << endl
         << "Destinations: " << endl;

        int count = 1;
        for(string dest : res){
            cout << "[" << count << "]" << " " << dest << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
    }
    case 2:
    {
        clearScreen();
        set<string> res = flightnetwork.getCitiesDestinations(airport);
        cout << "=================================================================================================" << endl
         << "Destinations: " << endl;

        int count = 1;
        for(string dest : res){
            cout << "[" << count << "]" << " " << dest << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
    }
    case 3:
    {
        clearScreen();
        set<string> res = flightnetwork.getCountriesDestinations(airport);
        cout << "=================================================================================================" << endl
         << "Destinations: " << endl;

        int count = 1;
        for(string dest : res){
            cout << "[" << count << "]" << " " << dest << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
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

void App::reachableDest(Airport &airport, int stops){
     int option;

    cout << "=================================================================================================" << endl
         << "Select the type of destination!"
         << "Enter your option:" << endl
         << "[1] Airport" << endl
         << "[2] City" << endl
         << "[3] Country" << endl
         << "=================================================================================================" << endl
         << "[0] Go back to the main menu" << endl
         << "-> " << endl;


    cin >> option;

    switch (option)
    {
    case 1:
    {
        clearScreen();
        set<string> res = flightnetwork.getReachableAirports(airport,stops);
        cout << "=================================================================================================" << endl
         << "Destinations: " << endl;

        int count = 1;
        for(string dest : res){
            cout << "[" << count << "]" << " " << dest << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
    }
    case 2:
    {
        clearScreen();
        set<string> res = flightnetwork.getReachableCities(airport,stops);
        cout << "=================================================================================================" << endl
         << "Destinations: " << endl;

        int count = 1;
        for(string dest : res){
            cout << "[" << count << "]" << " " << dest << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
    }
    case 3:
    {
        clearScreen();
        set<string> res = flightnetwork.getReachableCountries(airport,stops);
        cout << "=================================================================================================" << endl
         << "Destinations: " << endl;

        int count = 1;
        for(string dest : res){
            cout << "[" << count << "]" << " " << dest << endl;
            count++;
        }
        cout << "=================================================================================================" << endl
         << "[0] Go back to the statistics menu." << endl
         << endl
         << endl;
        
        goBackStatisticsMenu();
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