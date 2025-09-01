#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
bool hasRepetitions(vector<T> &vec) {
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size()-1; i++){
        if(vec[i] == vec[i+1]) return true;
    }
    return false;
}

int main(){
    vector<int> vec = { 1, 2, 3 , 4, 5 };

    vector<int> u = { 6, 0, 9, 2, 8, 1, 1 };

    vector<string> s = { "banana", "melao", "mamao" };

    vector<string> s2 = { "banana", "melao", "melao" };

    cout<<hasRepetitions(vec) <<endl;
    cout<<hasRepetitions(u) <<endl;
    cout<<hasRepetitions(s) <<endl;
    cout<<hasRepetitions(s2) <<endl;

    return 0;
}