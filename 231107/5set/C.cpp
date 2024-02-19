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

#define N 5050
double p[N], g[N], go[N], res[N];
vector<int> edges[N], redges[N];
int cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a,b;
        for(int i=0;i<n;i++) edges[i].clear();
        for(int i=0;i<n;i++) redges[i].clear();
        for(int i=0; i<m; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            redges[b].push_back(a);
        }
        
        for(int i=0; i<n; i++){
            p[i]=0;
            if(i==0) p[i]=1;
            for(auto prev : redges[i]){
                p[i]+=p[prev]/((double)edges[prev].size());
            }
        }
        
        //for(int i=0; i<n; i++) cout<<p[i]<<endl;
        for(int i=n-1; i>=0; i--){
            if(i==n-1) g[i]=1;
            else g[i]=0;
            for(auto next : edges[i]){
                g[i]+=g[next]*(p[i]/((double)edges[i].size()))/p[next];
            }
        }

        for(int i=0; i<n; i++){
            if(edges[i].size()==0) continue;
            double mx=0;
            int mx_idx=0;
            for(auto next : edges[i]){
                if(g[next]>mx){
                    mx_idx=next;
                    mx=g[next];
                }
            }
            go[i]=mx_idx;
        }

        for(int i=0; i<n; i++){
            if(i==0) res[i]=1;
            else res[i]=0;
            for(auto prev : redges[i]){
                res[i]+=res[prev]/((double)edges[prev].size())*(i==go[prev]?1:0);
            }
        }
        cout<<fixed;
        cout.precision(12);
        cout<<res[n-1]<<endl;
    }
    return 0;
}