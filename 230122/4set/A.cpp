// 
//./A<test

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

pair<int,int> pos[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        for(int i=0; i<3; i++) cin>>pos[i].fi>>pos[i].se;
        bool f1=pos[0].fi==pos[1].fi || pos[2].fi==pos[1].fi || pos[2].fi==pos[0].fi;
        bool f2=pos[0].se==pos[1].se || pos[2].se==pos[1].se || pos[2].se==pos[0].se;
        if(f1&&f2){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}