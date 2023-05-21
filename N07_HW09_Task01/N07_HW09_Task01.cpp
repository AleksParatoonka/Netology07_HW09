// N07_HW09_Task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

template <class T>
void move_vectors(std::vector<T>& l_vec, std::vector<T>& r_vec) {
    
    if (l_vec != r_vec) {
        l_vec = std::move(r_vec);
    }
    else {
        return;
    }
    
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    //std::cout << &one << "\n";
    //std::cout << &two << "\n";
    /*std::cout << "[Test] : ";
    for (int i = 0; i < one.size(); i++) {
        std::cout << one[i] << " ";
    }
    std::cout << std::endl;*/
    move_vectors(two, one);
    //std::cout << &one << "\n";
    //std::cout << &two << "\n";
    /*std::cout << "[Test] : ";
    for (int i = 0; i < two.size(); i++) {
        std::cout << two[i] << " ";
    }
    std::cout << std::endl;*/
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
