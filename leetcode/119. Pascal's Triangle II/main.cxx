#include <iostream>
#include "dp.hxx"

using namespace std;

int main() {
    Solution object;
    vector<int> result = object.getRow(3);
    for(int i = 0; i < result.size(); i++) {
       cout << result[i] << " ";
    }
    cout << endl;
}