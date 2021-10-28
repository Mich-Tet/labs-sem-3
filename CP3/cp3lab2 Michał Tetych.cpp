#include <iostream>
#include <vector>
#include <algorithm>
#include "ConsoleApplication9.h"

using namespace std;
// for_each - array that prints 
// lambda function for print 
// Sieve of Eratosthenes: printing prime num {2,3,4,5,6,7,8,9,10,11,12}

// 2. Sieve of Eratosthenes algorithm
void soe(int n) 
{
    
    vector<int> primenums(n + 1, true);
    


        for (int i = 2; i*i <= n; i++)
        {
            if (primenums[i]==true)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    primenums[j] = false;
                }
            }
        }
    
        for (int g = 2; g <= n; g++)
        {
            if (primenums[g])
            {
                cout << g << " ";
            }
        }

}

int main()
{
    
    //1. For_each and lambda application
    
    vector<string> wow{"John", "Mark", "Josh", "Mike", "Albert"};
    auto print = [](auto i) {cout << " " << i << endl; };
    for_each(wow.begin(), wow.end(), print);
    
    cout << "========"<< endl; // just to distinguish tasks

    //2. Using algorithm for Sieve of Eratosthenes for numbers up to 12
    soe(12);
    
}
