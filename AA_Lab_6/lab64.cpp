#include <iostream>
#include <vector>
using namespace std;

//muchii ilegale

struct punct{
    long long x;
    long long y;
};

long long get_determinant(long long a, long long b, long long c, long long d, long long e, long long f, long long g, long long h, long long i, long long j, long long k, long long l, long long m, long long n, long long o, long long p)
{
    return a * f * k * p - a * f * l * o - a * g * j * p + a * g * l * n + a * h * j * o - a * h * k * n - b * e * k * p + b*e*l*o + b*g*i*p - b*g*l*m - b*h*i*o + b*h*k*m + c*e*j*p - c*e*l*n - c*f*i*p + c*f*l*m + c*h*i*n - c*h*j*m -d*e*j*o + d*e*k*n + d*f*i*o - d*f*k*m - d*g*i*n + d*g*j*m; 
}

int numeric_criteria(punct a, punct b, punct c, punct d) //determinant of 4x4 matrix
{
    // long long result =  a.x * (b.y * (c.x * c.x + c.y * c.y) + c.y * (d.x * d.x + d.y * d.y) + d.y * ( b.x * b.x + b.y * b.y) - d.y * (c.x * c.x + c.y * c.y) - b.y * (d.x * d.x + d.y * d.y) - c.y * ( b.x * b.x + b.y * b.y)) -a.y * (b.x * (c.x * c.x + c.y * c.y) + c.x * (d.x * d.x + d.y * d.y) + d.x * ( b.x * b.x + b.y * b.y) - d.x * (c.x * c.x + c.y * c.y) - b.x * (d.x * d.x + d.y * d.y) - c.x *( b.x * b.x + b.y * b.y)) + (a.x * a.x + a.y * a.y) * (b.x * c.y + c.x * d.y + d.x * b.y - d.x * c.y - b.x * d.y - c.x * b.y) -1 * (b.x * c.y * (d.x * d.x + d.y * d.y) + c.x * d.y * ( b.x * b.x + b.y * b.y)+ d.x * b.y * (c.x * c.x + c.y * c.y) - d.x * c.y * ( b.x * b.x + b.y * b.y) - b.x * c.y * (c.x * c.x + c.y * c.y) - c.x * b.y *  (d.x * d.x + d.y * d.y) );
    //long long result = a.x * b.y * (c.x * c.x + c.y * c.y) - a.x * b.y * (d.x * d.x + d.y * d.y) - a.x * c.y * ( b.x * b.x + b.y * b.y) + a.x * (b.x * b.x + b.y * b.y) * d.y + a.x * c.y * (d.x * d.x + d.y * d.y) - a.x * d.y * (c.x * c.x + c.y * c.y) - a.y * b.x * (c.x * c.x + c.y * c.y) + a.y * b.x * (d.x * d.x + d.y * d.y) + a.y * c.x * (b.x * b.x + b.y * b.y) - a.y * d.x * (b.x * b.x + b.y * b.y) - a.y * c.x * (d.x * d.x + d.y * d.y) + a.y * d.x * (c.x * c.x + c.y * c.y) +  ;
    long long result = get_determinant(a.x, a.y, (a.x*a.x + a.y*a.y), 1, b.x, b.y, (b.x*b.x + b.y*b.y), 1,c.x, c.y, (c.x*c.x + c.y*c.y), 1,d.x, d.y, (d.x*d.x + d.y*d.y), 1);
    if(result > 0) return 1;
    if(result < 0) return -1;
    return 0;
}

int main(){
    int numCriteria;

    punct a;
    punct b;
    punct c;
    punct d;

    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    numCriteria = numeric_criteria(a,b,c,d);
    if(numCriteria > 0) cout<<"AC: ILLEGAL\n";
    else cout<<"AC: LEGAL\n";

    numCriteria = numeric_criteria(a,b,d,c);
    if(numCriteria > 0) cout<<"BD: ILLEGAL\n";
    else cout<<"BD: LEGAL\n";
    
    return 0;
}