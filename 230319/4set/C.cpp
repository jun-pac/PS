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
// ������ Ȯ���� ���� �� �´ٸ� O(n^2)���� ����
ll datas[2000];
ll DP[2000]; // DP[i]�� ���� stage����, ������ ������ ������. ���� ��� idx stage���� DP[i]�� [i,i+stage-1]����
ll temp[2000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    sort(datas,datas+n);
    
    // for stage 0
    for(int i=0; i<n; i++) DP[i]=0; // [i,i+0]�� ����
    for(int s=1; s<n; s++){
        fill(temp,temp+n-s,INF);
        for(int i=0; i<n-s; i++) temp[i]=min(DP[i], DP[i+1])+datas[i+s]-datas[i];
        for(int i=0; i<n-s; i++) DP[i]=temp[i];
    }
    cout<<DP[0]<<endl;
    return 0;
}