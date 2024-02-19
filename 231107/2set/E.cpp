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

int a[4000], b[4000];
vector<int> aans, bans;
int posa[4000], posb[4000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i]--;
        posa[a[i]]=i;
    }
    for(int j=0; j<m; j++){
        cin>>b[j];
        b[j]--;
        posb[b[j]]=j;
    }
    int aoff=0, boff=0;
    for(int i=0; i<n; i++){
        int vir_pos=posa[i]+i;
        int real_pos=vir_pos+aoff;
        if(vir_pos==i) continue;
        else{
            aans.push_back(real_pos);
            aoff+=;
        }
    }
    return 0;
}