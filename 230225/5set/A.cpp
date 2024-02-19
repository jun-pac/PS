// 
//./A<test

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

int datas[10000];

int less_l[5000][5000], less_r[5000][5000]; //[num][pos] // pos기준으로 num보다 작은 것 개수를 세어준다.

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==0) less_l[i][j]=(datas[j]<i+1?1:0);
                else less_l[i][j]=less_l[i][j-1]+(datas[j]<i+1?1:0);
            }
            for(int j=n-1; j>=0; j--){
                if(j==n-1) less_r[i][j]=(datas[j]<i+1?1:0);
                else less_r[i][j]=less_r[i][j+1]+(datas[j]<i+1?1:0);
            }
        }
        ll res=0;
        for(int b=1; b<n-2; b++){
            for(int c=b+1; c<n-1; c++){
                res+=(ll)less_l[datas[c]-1][b-1]*((ll)less_r[datas[b]-1][c+1]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}