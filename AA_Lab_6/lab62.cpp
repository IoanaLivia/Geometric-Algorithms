#include <iostream>
#include <vector>
using namespace std;


struct punct{
    long long x;
    long long y;
};

int main(){
    int n;
    cin>>n;

    vector<punct> puncte;

    long long p1, p2, min_x = 1e9, id_min_x = 0, min_y = 1e9, id_min_y = 0;
    punct p;
    for(int i = 0; i < n; ++i)
    {
        cin>>p1>>p2;
        p.x = p1;
        p.y = p2;
        puncte.push_back(p);

        if(p1 < min_x)
        {
            min_x = p1;
            id_min_x = i;
        }

        if(p2 < min_y)
        {
            min_y = p2;
            id_min_y = i;
        }
    }

    long long prev = min_x;
    bool turn = false, monoton = true;

    for(int i = 0; i < n ; ++i)
    {
        if(puncte[(i+id_min_x)%n].x < prev)
        {
            turn = true;
        }
        if(puncte[(i+id_min_x)%n].x > prev && turn == true)
        {
            monoton = false;
            break;
        }

        prev = puncte[(i+id_min_x)%n].x;
    }

    if(monoton)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<"\n";

    prev = min_y;
    turn = false, monoton = true;

    for(int i = 0; i < n ; ++i)
    {
        if(puncte[(i+id_min_y)%n].y < prev)
        {
            turn = true;
        }
        if(puncte[(i+id_min_y)%n].y > prev && turn == true)
        {
            monoton = false;
            break;
        }

        prev = puncte[(i+id_min_y)%n].y;
    }

    if(monoton)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}