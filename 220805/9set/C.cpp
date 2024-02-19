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

map<pair<int,int>,int> mp;
int znum[200002];
int ro[200002]; // (자자포함) 우측의 가장 가까운 1
int lz[200002]; // 좌측의 가장 가까운 0의 인덱스

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        int n,m,a,b;
        cin>>n>>m;
        cin>>s;
        int last=-1;
        for(int i=0; i<n; i++){
            znum[i]=(i==0?0:znum[i-1])+(s[i]=='0'?1:0);
        }
        for(int i=0; i<n; i++){
            lz[i]=(s[i]=='0'?i:(i==0?-1:lz[i-1]));
            //cout<<lz[i]<<' ';
        }
        //cout<<endl;
        for(int i=n-1; i>=0; i--){
            ro[i]=(s[i]=='1'?i:(i==n-1?n:ro[i+1]));
            //cout<<ro[i]<<' ';
        }
        //cout<<endl;
        int cnt=0;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            a--, b--;
            int nn=znum[b]-(a==0?0:znum[a-1]);
            //cout<<a+1<<' '<<b+1<<' '<<nn<<' '<<ro[a]+1<<' '<<lz[b]+1<<endl;
            if(nn==0 || nn==b-a+1 || ro[a]==lz[b]+1){
                if(mp[{-1,-1}]!=t+1){
                    cnt++;
                    mp[{-1,-1}]=t+1;
                }
            }
            else{
                if(mp[{ro[a],lz[b]}]!=t+1){
                    cnt++;
                    mp[{ro[a],lz[b]}]=t+1;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}