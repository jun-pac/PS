// 
//./B<test

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

ll datas[200900];
int parent[200800];
int deg[200020];
int mex[200001];

int find(int idx){
    return parent[idx]=(parent[idx]==idx? idx: find(parent[idx]));
}

void c_union(int a, int b){
    parent[find(a)]=parent[find(b)];
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        sort(datas,datas+n);
        int zero=0;
        for(int i=0; i<n; i++) if(datas[i]==0) zero++;
        //cout<<"z L : "<<zero<<endl;
        if(zero>(n+1)/2){
            if(zero==n) cout<<1<<endl;
            else if(datas[n-1]==1) cout<<2<<endl;
            else cout<<1<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}