#include <iostream>
#include <vector>
using namespace std;


struct punct{
    long x;
    long y;
};

int main(){
    int n;
    cin>>n;

    vector<punct> v;
    vector<punct> ans;

    long xmin = 100000001, xmax = -100000001, ymin = 100000001, ymax = -100000001, pozitie = -100000001;
    long long result;
    punct p;

    for(int i = 0; i < n; ++i){
        cin>>p.x>>p.y;
        if(p.x < xmin)
        {
            xmin = p.x;
            pozitie = i;
        }
        if(p.x > xmax)
        {
            xmax = p.x;
            pozitie = i;
        }
        if(p.y < ymin)
        {
            ymin = p.y;
            pozitie = i;
        }
        if(p.y > ymax)
        {
            ymax = p.y;
            pozitie = i;
        }

        v.push_back(p);
    }

    int poz, poz2, poz3;

    poz = pozitie;
    poz2 = poz + 1;
    if(poz2 == n) poz2 = 0;
    poz3 = poz2 + 1;
    if(poz3 == n) poz3 = 0;
    int cnt = 0;
    punct x;
    while(true)
    {

        result = v[poz2].x * v[poz3].y + v[poz].x * v[poz2].y + v[poz].y * v[poz3].x - v[poz2].x * v[poz].y - v[poz3].x * v[poz2].y - v[poz3].y * v[poz].x;

        if (result > 0)
        {
            x.x = v[poz2].x;
            x.y = v[poz2].y;
            ans.push_back(x);
            cnt += 1;
        }

        poz = poz2;
        poz2 = poz3;
        poz3 = poz3 + 1;
        if(poz3 == n) poz3 = 0;

        if(poz == pozitie) break;
    }

    // cout<<cnt<<'\n';
    // for(auto pct: ans){
    //     cout<<pct.x<<' '<<pct.y<<'\n';
    // }

    long m;
    cin>>m;

    vector<punct> puncte;
    for(int i = 0; i < m; ++i){
        cin>>p.x>>p.y;
        int y = 0;
        int z = 1;
        int st = 0, dr = 0, b = 0;
        while(z < n)
        {
            //result(ans[y], ans[z], (p.x,p.y))
            result = ans[z].x * p.y + ans[y].x * ans[z].y + ans[y].y * p.x - ans[z].x * ans[y].y - p.x * ans[z].y - p.y * ans[y].x;
            y++;
            z++;
            if(result == 0){
                cout<<"BOUNDARY"<<"\n";
                b = 1;
                break;}
            if(result > 0) st++;
            if(result < 0) dr++;
        }

        if(b == 0)
        {
            if((st == 0 && dr != 0) || (st != 0 && dr == 0)) cout<<"INSIDE\n";
            else cout<<"OUTSIDE\n";
        }
    }
    

    
    return 0;
}