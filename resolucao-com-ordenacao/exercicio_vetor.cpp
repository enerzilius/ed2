#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

pair<int, int> twoSum(vector<int> v, int k) {;
    sort(v.begin(), v.end());
    
    int low = 0;
    int high = v.size()-1;

    if(k <= v[low]) return make_pair(-1, -1);

    while (low < high)
    {
        if(v[low] + v[high] == k) return make_pair(v[low], v[high]);
        if(v[low] + v[high] < k) low++;
        if(v[low] + v[high] > k) high--;
    }
    
    return make_pair(-1, -1);
}

int main() {
    vector<int> v = { 9, 14, 2, 1, 17, 10 };
    int k = 27;
    pair<int, int> par = twoSum(v, k);
    cout<<par.first<<" "<<par.second<<endl;

    return 0;
}