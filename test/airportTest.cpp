#include <iostream>
#include "../inc/Airport.hpp"

// g++ -o airportTest airportTest.cpp ../src/Airport.cpp

// Function to run tests for the Airport class
void testAirport()
{
    // Test data
    std::string code = "ABC";
    std::string name = "Test Airport";
    std::string city = "Test City";
    std::string country = "Test Country";
    std::pair<float, float> position = std::make_pair(42.0f, 73.0f);

    // Create an Airport object
    Airport testAirport(code, name, city, country, position);

    // Test getters
    if (testAirport.getCode() != code)
    {
        std::cerr << "Error: getCode()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (testAirport.getName() != name)
    {
        std::cerr << "Error: getName()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (testAirport.getCity() != city)
    {
        std::cerr << "Error: getCity()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (testAirport.getCountry() != country)
    {
        std::cerr << "Error: getCountry()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (testAirport.getPosition() != position)
    {
        std::cerr << "Error: getPosition()" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test setters
    std::string newCode = "XYZ";
    std::string newName = "Updated Airport";
    std::string newCity = "Updated City";
    std::string newCountry = "Updated Country";
    std::pair<float, float> newPosition = std::make_pair(1.0f, 2.0f);

    testAirport.setCode(newCode);
    testAirport.setName(newName);
    testAirport.setCity(newCity);
    testAirport.setCountry(newCountry);
    testAirport.setPosition(newPosition);

    if (testAirport.getCode() != newCode || testAirport.getName() != newName ||
        testAirport.getCity() != newCity || testAirport.getCountry() != newCountry ||
        testAirport.getPosition() != newPosition)
    {
        std::cerr << "Error: setters" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

int main()
{
    try
    {
        // Run the tests for the Airport class
        testAirport();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
