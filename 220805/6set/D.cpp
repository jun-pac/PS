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
#define N 1000010

ll datas[N];
ll inter_cnt[N];
ll ans_idx[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        sort(datas,datas+n);
        // 0번째 interval은 0번째의 앞.
        
        for(int i=0; i<=k; i++){
            ll l=(i==0?0:datas[i-1]), r=(i==k?m:datas[i]);
            if(l>r){
                inter_cnt[i]=-1;
                continue;
            }
            if(i-k<0 && i+k-1>=n){
                inter_cnt[i]=m+1;
                
            }
            else if(i-k<0){

            }
            else if(i+k-1>=n){

            }
            else{

            }
        }
    }
    return 0;
}