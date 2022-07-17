#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct punct{
    long long x;
    long long y;
};

bool pe_latura(punct a, punct b, punct p)
{
    if(p.x >= min(a.x, b.x) && p.y >= min(a.y, b.y) && p.x<= max (a.x, b.x)&& p.y <= max(a.y, b.y)) return true;
    else return false;
}

int intersectie(punct a, punct b, punct M, punct p)
{
    long long result = p.x * b.y + a.x * p.y + a.y * b.x - p.x * a.y - b.x * p.y - b.y * a.x; //p fata de AB 
    long long result2 = M.x * b.y + a.x * M.y + a.y * b.x - M.x * a.y - b.x * M.y - b.y * a.x; //M fata de AB
    long long result3 = a.x * p.y + M.x * a.y + M.y * p.x - a.x * M.y - p.x * a.y - p.y * M.x; //a fata de Mp
    long long result4 = b.x * p.y + M.x * b.y + M.y * p.x - b.x * M.y - p.x * b.y - p.y * M.x; //b fata de Mp

    //verific proprietatea de boundary
    if(result == 0)
    {
       if(pe_latura(a,b,p)) return 0;
    }
    if(result2 == 0)
    {
        M.x += 100;
        M.y += 100;
        result2 = M.x * b.y + a.x * M.y + a.y * b.x - M.x * a.y - b.x * M.y - b.y * a.x;
    }
    //daca verifica conditia de a fi de o parte si de alta
    if(((result < 0 && result2 > 0) || (result > 0 && result2 < 0)) && ((result3 < 0 && result4 > 0) || (result3 > 0 && result4 < 0))) return 1;
    else
    {
        //verific daca trece printr-un varf
        if(result4 == 0 && result3 != 0 && pe_latura(p,M,b))
        {
            punct M2;
            M2.x = ++M.x;
            M2.y = ++M.y;
            return intersectie(a,b,M2,p);
        }
        if(result3 == 0 && result4 != 0 && pe_latura(p,M,a))
        {
            punct M2;
            M2.x = ++M.x;
            M2.y = ++M.y;
            return intersectie(a,b,M2,p);
        }
        
    }
    return -1;
}

int main(){
    int n, m;
    cin>>n;

    punct p, first, last;
    vector<punct> puncte;

    //primul punct
    cin>>p.x>>p.y;
    first.x = p.x;
    first.y = p.y;
    puncte.push_back(p);

    for(int i = 1 ; i < n - 1 ; ++i)
    {
        cin>>p.x>>p.y;
        puncte.push_back(p);
    }

    //ultimul punct
    cin>>p.x>>p.y;
    last.x = p.x;
    last.y = p.y;
    puncte.push_back(p);

    cin>>m;

    punct M;
    M.x = 1000000001;
    for(int i = 0 ; i < m ; ++i)
    {
        cin>>p.x>>p.y;
        
        M.y = p.y;

        int index = 0;
        int cnt = 0; //numarul de intersectii
        bool ba = false;
        while(true)
        {
            punct a = puncte[index];
            if(index + 1 == n) break;
            punct b = puncte[index+1];

            if(intersectie(a,b,M,p) == 0)
            {
                ba = true;
                cout<<"BOUNDARY\n";
                break;
            }
            if(intersectie(a,b,M,p) > 0) cnt++;
            index++;
        }

        punct a = last;
        punct b = first;

        if(intersectie(a,b,M,p) == 0)
        {
            ba = true;
        }
        if(intersectie(a,b,M,p) > 0) cnt++;

        if(ba == false)
        {
            if(cnt % 2 == 0) cout<<"OUTSIDE\n";
            else cout<<"INSIDE\n";
        }

    }
    return 0;
}