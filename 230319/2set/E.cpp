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

string maps[50];
int visited[50][50];

void make_round(int n, int m){
    for(int i=0; i<n; i++){
        int s=-1,e=-1;
        for(int j=0; j<m; j++){
            if(maps[i][j]=='#'){
                if(s==-1) s=j;
                e=j;
            }
        }
        if(e!=-1) for(int j=s; j<=e; j++) maps[i][j]='#';
    }
    for(int j=0; j<m; j++){
        int s=-1,e=-1;
        for(int i=0; i<n; i++){
            if(maps[i][j]=='#'){
                if(s==-1) s=i;
                e=i;
            }
        }
        if(e!=-1) for(int i=s; i<=e; i++) maps[i][j]='#';
    }
}

void DFS(int i, int j, int n, int m, int val){
    if(visited[i][j]!=0) return;
    visited[i][j]=val;
    if(i>0 && maps[i-1][j]=='#') DFS(i-1,j,n,m,val);
    if(i<n-1 && maps[i+1][j]=='#') DFS(i+1,j,n,m,val);
    if(j>0 && maps[i][j-1]=='#') DFS(i,j-1,n,m,val);
    if(j<m-1 && maps[i][j+1]=='#') DFS(i,j+1,n,m,val);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>maps[i];
        for(int i=0; i<max(n,m); i++) make_round(n,m);
        make_round(n,m);
        for(int i=0; i<n; i++) fill(visited[i],visited[i]+m,0);
        int cnt=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(maps[i][j]=='#' && !visited[i][j]){
                    DFS(i,j,n,m,cnt);
                    cnt++;
                }
            }
        }
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<visited[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        */
        if(cnt==3){
            //cout<<"here?"<<endl;
            int mn_na=100, mx_na=-1, mn_mb=100, mx_mb=-1;
            int sample_a, sample_b;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(visited[i][j]==1){
                        mn_na=min(mn_na,i);
                        mx_na=max(mx_na,i);
                        sample_a=j;
                    }
                    if(visited[i][j]==2){
                        mn_mb=min(mn_mb,j);
                        mx_mb=max(mx_mb,j);
                        sample_b=i;
                    }
                }
            }
            int ii,jj;
            ii=(mx_na<sample_b?mx_na:mn_na);
            jj=(mx_mb<sample_a?mx_mb:mn_mb);
            maps[ii][jj]='#';
            for(int i=0; i<max(n,m); i++) make_round(n,m); 
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<maps[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}