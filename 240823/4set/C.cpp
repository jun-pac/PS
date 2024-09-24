
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;

#define epsilon 0.00000001
double f(double x){
    return exp(2*x-1)-2;
}
double f_prime(double x){
    return (f(x+epsilon)-f(x))/epsilon;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int iter=100;
    double x_0=1, x_1;
    for(int i=0; i<100; i++){
        double y=f(x_0);
        double yp=f_prime(x_0);
        cout<<fixed;
        cout.precision(12);
        cout<<x_0<<' '<<y<<'\n';
        x_1=x_0-y/yp;
        if(abs(x_1-x_0)<epsilon) break;
        x_0=x_1;
    }
    return 0;
}

