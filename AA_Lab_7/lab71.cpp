#include <iostream>


using namespace std;

const int inf = 1<<30;


int max(int a, int b){
    if(a>b) return a;
    return b;
}

int min(int a, int b){
    if(a<b) return a;
    return b;
}
int main(){
    int N, a, b, c, min_x = -inf, max_x = inf, min_y = -inf, max_y = inf,bound_min = -inf, bound_max = inf;
    cin>>N;
    for(int i = 0; i < N; ++i){
        bound_min = -inf, bound_max = inf;
        cin>>a>>b>>c;
        if(a == 0) // plan vertical: y
        {
            if(b > 0) bound_max = int( - c / b);
            else bound_min = int( - c / b);

            min_y = max(min_y, bound_min);
            max_y = min(max_y, bound_max);
        }
        else //plan orizontal
        {
            if(a > 0) bound_max = int( - c / a);
            else bound_min = int( - c / a);

            min_x = max(min_x, bound_min);
            max_x = min(max_x, bound_max);
        }

    }

    if(min_x > max_x || min_y > max_y) cout<<"VOID";
    else
    {
        if(max_x != inf && min_x != -inf && min_y != -inf && max_y != inf) cout<<"BOUNDED";
        else cout<<"UNBOUNDED";
    }
    return 0;
}