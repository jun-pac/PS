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

#define INF 10000000000000LL
// 연속한 확장이 좋은 게 맞다면 O(n^2)으로 가능
ll datas[2000];
ll DP[2000]; // DP[i]는 현재 stage에서, 선수의 구간의 시작점. 예를 들어 idx stage에서 DP[i]는 [i,i+stage-1]구간
ll temp[2000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    sort(datas,datas+n);
    
    // for stage 0
    for(int i=0; i<n; i++) DP[i]=0; // [i,i+0]의 구간
    for(int s=1; s<n; s++){
        fill(temp,temp+n-s,INF);
        for(int i=0; i<n-s; i++) temp[i]=min(DP[i], DP[i+1])+datas[i+s]-datas[i];
        for(int i=0; i<n-s; i++) DP[i]=temp[i];
    }
    cout<<DP[0]<<endl;
    return 0;
}