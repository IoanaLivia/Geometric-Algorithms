#include <iostream>

using namespace std;


int main(){
    long long t, xp, yp, xq, yq, xr, yr, result;
    cin>>t;

    for(int i = 0; i < t; ++i){
        cin>>xp>>yp>>xq>>yq>>xr>>yr;
        result = xq * yr + xp * yq + yp * xr - xq * yp - xr * yq - yr * xp;
        if (result == 0) cout<<"TOUCH\n";
        if (result > 0) cout<<"LEFT\n";
        if (result < 0) cout<<"RIGHT\n";    
    }

    return 0;
}