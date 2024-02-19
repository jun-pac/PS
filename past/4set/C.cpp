// 
//./C<test.txt

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

int maps[1000][1000];
bool visited[1000][1000];
int l[1000][1000], r[1000][1000];

void DFS(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = true;
    int lval=100000000;
    int rval=-100000000;
    if(i==0 && j==0){
        l[i][j]=maps[i][j];
        r[i][j]=maps[i][j];
        return;
    }
    if(i!=0){
        DFS(i-1,j);
        umin(lval,l[i-1][j]);
        umax(rval,r[i-1][j]);
    }
    if(j!=0){
        DFS(i,j-1);
        umin(lval,l[i][j-1]);
        umax(rval,r[i][j-1]);
    }
    l[i][j]=lval+maps[i][j];
    r[i][j]=rval+maps[i][j];
    //cout<<"debug"<<i<<' '<<j<<' '<<lval<<' '<<rval<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        bool flag=true;
        if((a+b-1)%2==1) flag=false;
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cin>>maps[i][j];
            }
            fill(visited[i],visited[i]+b,false);
        }
        if(flag) DFS(a-1,b-1);
        if(flag && l[a-1][b-1]<=0 && r[a-1][b-1]>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}