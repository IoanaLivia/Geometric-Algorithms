#include <iostream>

using namespace std;

int main(){
    int xp, yp, xq, yq, xr, yr, v_st = 0, v_dr = 0, stayed = 0, xstart, ystart;
    long long result;
    int n;
    cin>>n;

    cin>>xp>>yp;
    //voi reveni in start, adica P1
    xstart = xp;
    ystart = yp;

    cin>>xq>>yq;

    n -= 2;

    for(int i = 0; i < n; ++i){
        cin>>xr>>yr;

        result = xq * yr + xp * yq + yp * xr - xq * yp - xr * yq - yr * xp;

        if(result < 0){v_dr+=1;}
        if(result > 0){v_st+=1;}
        if(result == 0){stayed +=1;}

        xp = xq;
        yp = yq;
        xq = xr;
        yq = yr;
    }


    xr = xstart;
    yr = ystart;
    
    result = xq * yr + xp * yq + yp * xr - xq * yp - xr * yq - yr * xp;

    if(result < 0){v_dr+=1;}
    if(result > 0){v_st+=1;}
    if(result == 0){stayed +=1;}

    cout<<v_st<<' '<<v_dr<<' '<<stayed;

    return 0;
}