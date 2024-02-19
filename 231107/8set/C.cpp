// 
//./C<test

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

string datas[200020];
ll totsum[200020];
ll sums[6][101]; // even길이인데 sum이 i인 것이 몇 개냐?

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    for(int i=0; i<n; i++){
        int sum=0;
        for(auto c:datas[i]) sum+=c-'0';
        sums[datas[i].size()][sum]++;
        totsum[i]=sum;
    }
    ll ans=0;
    ll comp_sum=0;
    for(int i=0; i<n; i++){
        int cur_sum=0;
        int kk=datas[i].size();
        for(int j=0; j<kk; j++){
            cur_sum+=datas[i][j]-'0';
            if((j+1)*2>kk && cur_sum*2>totsum[i]){
                ans+=sums[(j+1)*2-kk][cur_sum*2-totsum[i]];
            }
        }
        cur_sum=0;
        for(int j=0; j<kk; j++){
            cur_sum+=datas[i][kk-1-j]-'0';
            if((j+1)*2>kk && cur_sum*2>totsum[i]){
                ans+=sums[(j+1)*2-kk][cur_sum*2-totsum[i]];
            }
        }
        comp_sum+=sums[kk][totsum[i]];
    }
    cout<<ans-comp_sum<<endl;

    return 0;
}