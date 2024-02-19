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

#define MOD 998244353
#define N 100100
int datas[N];
pair<int,int> order[N];
bool visited[N];
ll pow2[N], fact[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<=n; i++) pow2[i]=(i==0?1:pow2[i-1]*2)%MOD;
    for(int i=0; i<=n; i++) fact[i]=(i==0?1:fact[i-1]*i)%MOD;
    for(int i=0; i<n; i++) cin>>datas[i];
    for(int i=0; i<n; i++) order[i]={datas[i],i};
    sort(order,order+n);
    reverse(order,order+n);

    ll sum=0;
    int v_cnt=0;
    
    for(int i=0; i<n; i++){
        ll val=order[i].fi;
        int idx=order[i].se;
        ll last_num=(pow2[n-v_cnt]-1+MOD)%MOD;
        // (idx+1)의 모든 약수에 해당하는 칸을 block해야 함.
        if(!visited[idx]){
            for(int j=0; j<=min((int)sqrt(idx+1)+1,idx); j++){
                if((idx+1)%(j+1)==0 && !visited[j]){
                    visited[j]=true;
                    v_cnt++;
                }
                if((idx+1)%(j+1)==0 && !visited[(idx+1)/(j+1)-1]){
                    visited[(idx+1)/(j+1)-1]=true;
                    v_cnt++;
                }
            }
        }
        ll cur_num=(pow2[n-v_cnt]-1+MOD)%MOD;
        sum=(sum+val*(last_num-cur_num))%MOD;
    }
    cout<<(sum+MOD)%MOD<<endl;
    return 0;
}