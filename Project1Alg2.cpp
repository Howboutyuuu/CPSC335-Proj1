// Project1Alg2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Henry Yu CPSC 335-11
 //Algorithm 2
#include <iostream>
#include <vector>

int optimal_start_city(std::vector<int>& city_distances, std::vector<int>& city_fuel, int car_mpg) {
    int n = city_distances.size(); // number of cities

    for (int start = 0; start < n; start++) {
        int check = 1; // used for checking for starting city has any fuel and is therefore a valid start
        int car_fuel = 0; // fuel amount in car

        for (int i = 0; i < n; i++) {
            int j = (i + start) % n; // city index 
            int fuel = city_fuel[j]; // city fuel level
            int distance = city_distances[j]; // distance to next city
            car_fuel += fuel * car_mpg - distance; // update fuel counter for car after each drive

            if (car_fuel < 0) {
                check = 0; // sets check value to zero to break out of function of starting city does not have enough fuel for drive
                break;
            }
        }

        if (check) {
            return start;
        }
    }

    return -1;
}

int main()
{

    std::vector<int> city_distances = { 5, 25, 15, 10, 15 };
    std::vector<int> city_fuel = { 1, 2, 1, 0, 3 };
    int car_mpg = 10;
    int starting_city = optimal_start_city(city_distances, city_fuel, car_mpg);

    if (starting_city >= 0) {
        std::cout << "Preferred starting city is " << starting_city << std::endl;
    }
    else {
        std::cout << "None of the listed cities are valid." << std::endl;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
