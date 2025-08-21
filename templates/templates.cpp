#include <iostream>

using namespace std;

template<typename T>
T soma_array(T* arr, int n){
    T sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {
    float arr[] = { 1.44, 2.3, 3.1111, 4.76, 5.009, 6.124 };
    int i_arr[] = { 1, 3, 4 };
    double d_arr[] = { 4.4343243243243, 3.5324524432};

    float sum = soma_array(arr, 6);
    int sum_i = soma_array(i_arr, 3);
    float sum_d = soma_array(d_arr, 2);
    cout<<sum<<"\n";
    cout<<sum_i<<"\n";
    cout<<sum_d<<"\n";

    return 0;
}