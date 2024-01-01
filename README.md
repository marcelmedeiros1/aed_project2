# Air Travel Flight Management System

## Overview

Welcome to the Air Travel Flight Management System! This system is designed to help users explore and plan their air travel efficiently. It leverages real-world data about airports, airlines, and flights to provide a comprehensive tool for making informed decisions.

## Dataset

The system utilizes a dataset containing information about 3019 airports, 444 airlines, and 63832 flights. This dataset includes details such as airport codes, names, cities, countries, latitude, and longitude, among other information.

## Features

### Data Handling
- Read and parse provided data, loading it into an appropriate graph data structure.

### Flight Management System
- Develop a user-friendly system with functionalities for exploring and planning air travel.

### Network Statistics
- Calculate and list statistics such as the global number of airports and flights.
- Provide statistics on flights per airport, per city, per airline, and more.

### Maximum Trip and Essential Airports
- Identify the maximum number of stops for a round-trip.
- Identify essential airports for the network's circulation capability.

### Best Flight Options
- Present the best flight options based on user-specified criteria, such as airport code, name, city, or coordinates.

### Flight Filtering
- Allow users to filter flight options based on preferences, such as specific airlines or minimizing the number of different airlines.

### Documentation
- Include Doxygen documentation for relevant functions, indicating their time complexity.

## Implementation Details

This system is implemented in C++ using the provided `Graph` class for managing the network of airports and flights. The data is loaded from CSV files, and various functionalities are provided to assist users in navigating the flight network.

## How to Use

To get started, instantiate the `FlightNetwork` class with filenames for airlines, airports, and flights data. Then, use the provided functions to explore the features mentioned above.

### To run the program, run the following commands:

```
mkdir build
cd build
cmake ..
make
./aed_project2
```

## Authors

Leonardo Garcia<br/>
Marcel Madeiros<br/>
Pedro Castro<br/>

### Happy flying!
