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

int datas[100010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,d;
        bool flag=false;
        cin>>n>>m>>d;
        for(int i=0; i<m; i++){
            cin>>datas[i];
        }   
        if(datas[0]!=1){
            for(int i=m-1; i>=0; i--){
                datas[i+1]=datas[i];
            }
            datas[0]=1;
            m++;
        }
        else flag=true;
        datas[m]=n+1;
        int ori=0;
        for(int i=0; i<m; i++){
            ori+=(datas[i+1]-datas[i]-1)/d+1;
        }
        int mx=0;
        for(int i=1; i<m; i++){
            int temp=(datas[i+1]-datas[i]-1)/d+1+(datas[i]-datas[i-1]-1)/d+1-(datas[i+1]-datas[i-1]-1)/d-1;
            mx=max(mx,temp);
        }
        int cnt=(mx==0&&flag?1:0);
        for(int i=1; i<m; i++){
            int temp=(datas[i+1]-datas[i]-1)/d+1+(datas[i]-datas[i-1]-1)/d+1-(datas[i+1]-datas[i-1]-1)/d-1;
            if(temp==mx) cnt++;
        }
        cout<<ori-mx<<' '<<cnt<<endl;
    }
    return 0;
}