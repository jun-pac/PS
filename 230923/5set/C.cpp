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

int datas[100010], pos[100010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        fill(pos,pos+n,-1);
        for(int i=0; i<n; i++){
            cin>>datas[i];
            if(datas[i]<n) pos[datas[i]]=i;
        }
        int mex=-1;
        for(int i=0; i<n; i++){
            if(pos[i]==-1){
                mex=i;
                break;
            }
        }
        if(mex==-1) mex=n;
        datas[n]=mex;
        for(int i=0; i<n; i++) cout<<datas[((i-k)%(n+1)+(n+1))%(n+1)]<<' ';
        //for(int i=0; i<n; i++) cout<<(i+n-k)%(n+1)<<' ';
        cout<<endl;
    }
    return 0;
}