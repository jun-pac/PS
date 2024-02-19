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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
ll w[200000];

ll datas[120000];
int p[120000];
map<ll,ll> um;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q,x,y;
    cin>>n>>q;
    for(int i=0;i<=100000;i++){
		w[i]=rng();
	}
    for(int i=0; i<n; i++) cin>>datas[i];
    p[0]=-1;
    for(int i=1; i<n; i++){
        cin>>x; 
        p[i]=x-1;
    }
    for(int i=0; i<q; i++){
        cin>>x>>y;
        x--, y--;
        ll tx=x, ty=y;
        ll temp=0, ans;
        while(tx!=-1){
            if(um[w[tx]+w[ty]]!=0){
                temp=temp+um[w[tx]+w[ty]];
                break;
            }
            temp=temp+datas[tx]*datas[ty];
            tx=p[tx];
            ty=p[ty];
        }
        ans=temp;
        ll sx=x, sy=y;
        while(sx!=tx){
            um[w[sx]+w[sy]]=temp;
            temp=temp-datas[sx]*datas[sy];
            sx=p[sx];
            sy=p[sy];
        }
        cout<<ans<<endl;
    }
    return 0;
}