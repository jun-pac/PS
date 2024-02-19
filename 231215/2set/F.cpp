// 
//./F<test

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

vector<pair<int,int>> dir;
string mp[1001];
bool visited[1001][1001];
int n,m;

int DFS(int a, int b){
    if(a<0 || a>=n || b<0 || b>=m || visited[a][b] || mp[a][b]=='#') return 0;
    visited[a][b]=true;
    int res=0;
    if(a==0 || a==n-1 || b==0 || b==m-1) res++;
    for(auto mv : dir){
        int na=a+mv.fi;
        int nb=b+mv.se;
        res+=DFS(na,nb);
    }
    return res;
}

#define INF 1000000007
int dist[1001][1001];
queue<pair<pair<int,int>,int>> q;
void BFS(){
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int a=cur.fi.fi, b=cur.fi.se;
        int d=cur.se;
        if(a<0 || a>=n || b<0 || b>=m || dist[a][b]==INF || mp[a][b]=='#') continue;
        dist[a][b]=d;
        for(auto mv : dir){
            int na=a+mv.fi;
            int nb=b+mv.se;
            if(!(na<0 || na>=n || nb<0 || nb>=m) && dist[na][nb]==INF && mp[na][nb]!='#'){
                q.push({{na,nb},d+1});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    dir.push_back({-1,0});
    dir.push_back({1,0});
    dir.push_back({0,1});
    dir.push_back({0,-1});

    while(t--){
        cin>>n>>m;
        int va, vb;
        int numb=0;
        for(int i=0; i<n; i++){
            cin>>mp[i];
            for(int j=0; j<m; j++){
                if(mp[i][j]=='V') va=i, vb=j;
                else if(mp[i][j]=='#') numb++;
            }
        }
        for(int i=0; i<n; i++) fill(visited[i],visited[i]+m,0);
        int res=DFS(va,vb);
        if(res==0){
            cout<<n*m-1-numb<<'\n';
        }
        else if(res==1){
            for(int i=0; i<n; i++) fill(dist[i],dist[i]+m,INF);
            q.push({{va,vb},0});
            BFS();
            int ans=0;
            for(int j=1; j<m-1; j++) if(dist[0][j]!=INF && mp[0][j]!='#') ans=dist[0][j]+1;
            for(int j=1; j<m-1; j++) if(dist[n-1][j]!=INF && mp[n-1][j]!='#') ans=dist[n-1][j]+1;
            for(int j=1; j<n-1; j++) if(dist[j][0]!=INF && mp[j][0]!='#') ans=dist[j][0]+1;
            for(int j=1; j<n-1; j++) if(dist[j][m-1]!=INF && mp[j][m-1]!='#') ans=dist[j][m-1]+1;
            cout<<n*m-(ans+1)-numb<<'\n';
        }
        else if(res==2){
            for(int i=0; i<n; i++) fill(dist[i],dist[i]+m,INF);
            q.push({{va,vb},0});
            BFS();
            int ans=INF, na, nb;
            for(int j=1; j<m-1; j++) if(dist[0][j]!=INF && mp[0][j]!='#'){
                if(ans<dist[0][j]+1) ans=dist[0][j]+1, na=0, nb=j;
            }
            for(int j=1; j<m-1; j++) if(dist[n-1][j]!=INF && mp[n-1][j]!='#'){
                if(ans<dist[m-1][j]+1) ans=dist[m-1][j]+1, na=m-1, nb=j;
            }
            for(int j=1; j<n-1; j++) if(dist[j][0]!=INF && mp[j][0]!='#'){
                if(ans<dist[j][0]+1) ans=dist[j][0]+1, na=j, nb=0;
            }
            for(int j=1; j<n-1; j++) if(dist[j][m-1]!=INF && mp[j][m-1]!='#'){
                if(ans<dist[j][n-1]+1) ans=dist[j][n-1]+1, na=j, nb=0;
            }
            cout<<ans+1<<'\n';
        }
    }
    return 0;
}