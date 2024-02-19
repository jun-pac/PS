// 
//./B<test

#include <bits/stdc++.h>
//#define endl '\n'
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

int datas[100][100];
pair<int,int> s_datas[10000];
bool visited[100][100];
int ans[100][100];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) fill(datas[i],datas[i]+m,0);
        for(int i=0; i<n; i++) fill(visited[i],visited[i]+m,0);
        for(int i=0; i<n; i++) fill(ans[i],ans[i]+m,-1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>datas[i][j];
                s_datas[i*m+j]={datas[i][j],i*m+j};
            }
        }
        sort(s_datas,s_datas+n*m);
        ll res=0;
        for(int i=0; i<m; i++){
            int idx=s_datas[i].se;
            //cout<<"da "<<s_datas[i].fi<<endl;
            visited[idx/m][idx%m]=true;
            ans[idx/m][i]=datas[idx/m][idx%m];
        }

        for(int i=0; i<n; i++){
            int cur=0;
            for(int j=0; j<m; j++){
                if(ans[i][j]!=-1) continue;
                while(cur<m && visited[i][cur]) cur++;
                ans[i][j]=datas[i][cur];
                visited[i][cur]=true;
            }
            // visited[i][cur];
            // ans[i][cur]
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cout<<ans[i][j]<<' ';
            cout<<endl;
        }
    }
    return 0;
}