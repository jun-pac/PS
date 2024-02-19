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

bool visited[200200];
int pp[200200];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        int all=0;
        int xk=0;
        for(int i=1; i<=n; i++) all=all^i;
        for(int i=0; i<k; i++) xk=xk^x;
        if(xk!=all || 2*k+1>n){
            cout<<"NO"<<endl;
            continue;
        }
        fill(visited,visited+n+1,false);
        fill(pp,pp+n+1,-1);
        int cnt=0, idx=1;
        while(cnt<k-1){
            while(idx<=n && ((x^idx)>n || visited[idx])) idx++;
            if(idx<=n && (!visited[idx]) && (!visited[idx^x])){
                visited[idx]=true;
                visited[x^idx]=true;
                pp[idx]=x^idx;
                pp[x^idx]=-1;
                cnt++;
                idx++;
            }
            if(idx>n) break;
        }
        if(cnt!=k-1){
            cout<<"NO"<<endl;
            continue;
        }
        int temp=0;
        for(int i=1; i<=n; i++){
            if(!visited[i]) temp=temp^i;
        }
        if(temp==x){
            cout<<"YES"<<endl;
            for(int i=1; i<=n; i++){
                if(pp[i]!=-1){
                    cout<<2<<' '<<i<<' '<<pp[i]<<endl;
                }
            }
            cout<<n-2*k<<' ';
            for(int i=1; i<=n; i++){
                if(!visited[i]) cout<<i<<' ';
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}