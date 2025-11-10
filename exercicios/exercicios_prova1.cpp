#include <iostream>
#include <cstring>

using namespace std;

int expo(int x, int e) {
    int exp = 1;
    for (int i = 1; i <= e; i++)
    {
        exp *= x;
    }
    return exp;
}

int hash_string(string str, int k, int m){
    int res = 0;

    int i = 0;  
    while (str[i] != '\0')
    {
        res += str[i]*expo(k, str.length()-i-1);
        i++;
    }
    
    cout<<res<<'\n';

    return res % m;
}

int hash_string_horner(string str, int k, int m) {
    int res = 0;
    cout<<"horner -- \n";

    int i = 0;
    while (str[i] != '\0')
    {
        res = res*k + str[i];
        i++;
    }
    
    cout<<res<<'\n';

    return res % m;
}

int main(int argc, char** argv) {
    int h = hash_string("ABC", 31, 37);
    cout<<h<<endl;
    h = hash_string_horner("ABC", 31, 37);
    cout<<h<<endl;
    return 0;
}