// 
//./E<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back


using namespace std;
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}


ll a,b,c,d,e,f,g; 

vector<ll> v; 

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b,a%b); 
}

ll inv(ll a, ll b){ // ax = 1(mod b)
    return a>1? b-inv(b%a,a)*b/a  : 1; 
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b); 
}

pair<ll,ll> fuck(ll a1, ll n1, ll a2, ll n2){
    ll g = gcd(n1,n2); 
    if(a1<a2) return fuck(a2,n2,a1,n1); 
    //cout << n1/g << " " << n2/g << " " << inv(n1/g,n2/g) << "\n"; 
    //assert( (inv(n1/g,n2/g)*n1/g)%(n2/g) ==1 );
    ll t = inv(n1/g, n2/g)*(a2-a1)/g;   
    //assert(  (a2-a1)%g==0 );
    ll re = (n1*t+a1)%lcm(n1,n2); 
    re = (re + lcm(n1,n2))% lcm(n1,n2); 
    //assert (re %n1 == a1); 
    //assert(re%n2== a2); 
    return {re, lcm(n1,n2)}; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a>>b>>c>>d>>e>>f>>g; 


    for(ll i=1; 2*i  <  min(a,b); i++){
        v.pb(i*(a-2*i)*(b-2*i)); 
    }
    sort(v.begin(),v.end()); 
    v.erase(unique(v.begin(),v.end()),v.end());
    ll m1 = v[v.size()-1], m2= v[v.size()-2], m3= v[v.size()-3]; 
    auto x = fuck(c,m1,d,m2);
    x.first %= x.second; 
    x.first = (x.first+x.second)%x.second; 
    auto y = fuck(x.first, x.second, e, m3); 
    ll a = y.first; 
    ll m = y.second; 
    a = (a%m + m)%m; 
    // f 이상 g 이하 a (mod m )
    if(f%m <= a) {
        cout << m*(f/m) + a; 
    }
    else {
        cout << m*(f/m + 1) + a; 
    }
}