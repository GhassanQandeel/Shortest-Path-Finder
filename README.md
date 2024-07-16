﻿# Shortest-Path-Finder
## Overview
This C program finds the shortest path between cities using Dijkstra's and BFS algorithms.
The program uses a 2-dimensional array (cities_graph) to represent the graph, where each city is connected to others with specified distances.

## Detailed Explanation
### Definitions and Global Variables

*  `NUM_CITIES and MAX`: Constants defining the number of cities and a large value representing infinity.
* `cities_graph`: A 2-D array representing the graph of cities and their distances.
* `city_name_initialize`: An array to store the names of the cities.
* `data_to_file`: An array to store the paths that will be written to a file.
* `index_data`: An index to keep track of the current position in data_to_file.

### Function Prototypes
* `Cities_Index`: Returns the index of a city given its name.
* `Dijkstra`: Implements Dijkstra's algorithm to find the shortest path.
* `BFS`: Implements the BFS algorithm to find the shortest path.
* `DisplayMenu`: Displays a menu and returns the user's choice.
* `Load_info`: Loads city data from a file into cities_graph.
* `store_info`: Saves the data from data_to_file into a file.

### `store_info()`:
* Load_info Function
* Opens the file Cities.txt and reads the data line by line.
* Each line contains a source city, a destination city, and the distance between them.
* Updates the cities_graph array with these values.
### `Cities_Index` 
* Initializes the array city_name_initialize with city names.
* Searches for the given city name and returns its index.
* Returns -1 if the city is not found.
### `Dijkstra`
* Initializes the distances, visited, and path arrays.
* Implements Dijkstra's algorithm to find the shortest path from start_vertex to end_vertex.
* Prints the shortest path and updates the data_to_file array.
### `BFS` 
* Initializes the visited and path arrays.
* Implements the BFS algorithm to find the shortest path from start_vertex to end_vertex.
* Prints the shortest path and updates the data_to_file array.
### `DisplayMenu ` 
* Displays the menu options and returns the user's choice.

## Conclusion
This program allows the user to load city data, input source and destination cities, and find the shortest paths using two different algorithms. It then saves these paths to a file for future reference.
