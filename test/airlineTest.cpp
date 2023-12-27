#include <iostream>
#include "../inc/Airline.hpp"
#include "../inc/FlightNetwork.hpp"

// g++ -o airlineTest airlineTest.cpp ../src/Airline.cpp ../src/FlightNetwork.cpp

// Function to run tests for the Airline class
void testAirline()
{
    // Test data
    std::string code = "ABC123";
    std::string name = "Test Airline";
    std::string callsign = "TEST";
    std::string country = "Testland";

    // Create an Airline object
    Airline testAirline(code, name, callsign, country);

    // Test getters
    if (testAirline.getCode() != code)
    {
        std::cerr << "Error: getCode()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (testAirline.getName() != name)
    {
        std::cerr << "Error: getName()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (testAirline.getCallsign() != callsign)
    {
        std::cerr << "Error: getCallsign()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (testAirline.getCountry() != country)
    {
        std::cerr << "Error: getCountry()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test setters
    std::string newCode = "XYZ789";
    std::string newName = "Updated Airline";
    std::string newCallsign = "UPD";
    std::string newCountry = "UpdatedLand";

    testAirline.setCode(newCode);
    testAirline.setName(newName);
    testAirline.setCallsign(newCallsign);
    testAirline.setCountry(newCountry);

    if (testAirline.getCode() != newCode || testAirline.getName() != newName ||
        testAirline.getCallsign() != newCallsign || testAirline.getCountry() != newCountry)
    {
        std::cerr << "Error: setters" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testAirlineCodeToName()
{
    std::string res = airlineCodeToName("IBE");
    std::cout << "\nNAME -> " << res << '\n';
}

int main()
{
    try
    {
        // Run the tests for the Airline class
        testAirline();
        testAirlineCodeToName();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
