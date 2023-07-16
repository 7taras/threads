// threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <vector>
#include <functional>


void add(std::vector<int>& arr, int splits, int part)
{
    int sum{ 0 };
    //int beg = arr.size() / part;
    for (int beg = (arr.size() / splits) * part; beg < (arr.size() / splits) * (part + 1); ++beg)
    {
        sum += arr[beg];
    }
    std::cout << sum << ' ';
}

int main()
{
    int amount, splits;
    std::vector<int> arr;
    std::vector<std::thread> tarr;

    std::cout << "Input amount values of array: ";
    std::cin >> amount;
    std::cout << "Input number values of splits: ";
    std::cin >> splits;

    srand(time(0));

    if (amount > 0)
    {
        for (int i = 0; i < amount; ++i)
        {
            arr.push_back(rand() % 10);
        }        
    }
    
    for (auto it : arr)
    {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    if (splits > 0)
    {
        for (auto i = 0; i < splits; ++i)
        {
            std::thread tx(add, std::ref(arr), splits, i);
            tx.join();
        }
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
