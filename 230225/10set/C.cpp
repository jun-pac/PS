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

int datas[500];
int ans[500][500];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) fill(ans[i],ans[i]+n,0);
    for(int i=0; i<n; i++) cin>>datas[i];
    for(int i=n-1; i>=0; i--){
        int cnt=datas[i];
        int cur_i=i, cur_j=i;
        while(cnt>0){
            ans[cur_i][cur_j]=datas[i];
            if(cur_i+1<n && ans[cur_i+1][cur_j]==0) cur_i++;
            else cur_j--;
            cnt--;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}