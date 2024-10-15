// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Henry Yu CPSC 335-11 Project 1 
//Algorithm 1
#include <iostream>
#include <vector>

int seat_swaps(std::vector<int>& row) {
    int count = 0;
    for (int i = 0; i < row.size() - 1; i += 2) {
        //std::cout << "Being checked: " << row[i] << " and " << row[i + 1] << std::endl;   //Debug
        if ((row[i + 1] != row[i] - 1) && (row[i] + 1 != row[i + 1] )) {
            //std::cout << "Flagged\n";    //Debug
            for (int j = 0; j < row.size(); j++) {
                if ((row[i] + 1 == row[j]) || (row[i] - 1 == row[j])) {
                    std::swap(row[i + 1], row[j]);
                    count++;
                    break;
                }
            }
        }
    }

    /*std::cout << "row: ";
    for (int i = 0; i < row.size() ; i += 1) {  //Debug
        std::cout << row[i];                         
    }*/
    
    return count;
}


int main() {
    std::vector<int> row1 = { 1, 2, 0, 3}; //Test Set 1
    std::vector<int> row2 = { 2, 1, 0, 3}; //Test Set 2

    std::cout << "Number of swaps made in row1: " << seat_swaps(row1) << std::endl;  
    std::cout << "Number of swaps made in row2: " << seat_swaps(row2) << std::endl;  

   
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
