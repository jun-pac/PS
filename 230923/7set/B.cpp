// 
//./E<test

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

pair<ll,ll> pos[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        a--, b--;
        for(int i=0; i<n; i++){
            cin>>pos[i].fi>>pos[i].se;
        }
        ll mn=abs(pos[a].fi-pos[b].fi)+abs(pos[a].se-pos[b].se);
        ll mna=2*mn, mnb=2*mn;
        for(int i=0; i<k; i++){
            mna=min(mna,abs(pos[i].fi-pos[a].fi)+abs(pos[i].se-pos[a].se));
            mnb=min(mnb,abs(pos[i].fi-pos[b].fi)+abs(pos[i].se-pos[b].se));
        }
        mn=min(mn,mna+mnb);
        if(a<k) mn=min(mn,mnb);
        if(b<k) mn=min(mn,mna);
        if(a<k && b<k) mn=0;
        cout<<mn<<endl;
    }
    return 0;
}