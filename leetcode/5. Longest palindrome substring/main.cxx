#include <iostream>
#include "brute_force.hxx"
#include "dp.hxx"
#include "middle_diffusion.hxx"

using namespace std;

int main(){
    string s = "ababa";
    // Brute Force Method
    Solution_1 object_1;
    cout << object_1.longestPalindrome(s) << endl;
    // Dynamic Programming Method
    Solution_2 object_2;
    cout << object_2.longestPalindrome(s) << endl;
    // Middle Diffusion Method
    Solution_3 object_3;
    cout << object_3.longestPalindrome(s) << endl;
}