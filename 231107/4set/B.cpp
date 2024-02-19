// 
//./D<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        double px,py;
        double ax, ay, bx, by;
        cin>>px>>py;
        cin>>ax>>ay>>bx>>by;
        double d=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        double w1=d/2;
        w1=max(w1,min(sqrt((ax-0)*(ax-0)+(ay-0)*(ay-0)),sqrt((bx-0)*(bx-0)+(by-0)*(by-0))));
        w1=max(w1,min(sqrt((ax-px)*(ax-px)+(ay-py)*(ay-py)),sqrt((bx-px)*(bx-px)+(by-py)*(by-py))));
        double w2=max(sqrt((ax-0)*(ax-0)+(ay-0)*(ay-0)),sqrt((ax-px)*(ax-px)+(ay-py)*(ay-py)));
        double w3=max(sqrt((bx-0)*(bx-0)+(by-0)*(by-0)),sqrt((bx-px)*(bx-px)+(by-py)*(by-py)));

        cout<<fixed;
        cout.precision(12);
        cout<<min(w1,min(w2,w3))<<endl;
    }
    return 0;
}