// 
//./B<test.txt

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

int datas[100000];
vector<int> edges[100000];
pair<int,int> link[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<m; i++){
            cin>>a>>b;
            a--,b--;
            link[i]={a,b};
            edges[a].push_back(b), edges[b].push_back(a);
        }
        if(m%2==0){
            cout<<0<<endl;
            continue;
        }
        ll min_val=1000000;
        for(int i=0; i<n; i++){
            if((int)edges[i].size()%2==1){
                if(datas[i]<min_val) min_val=datas[i];
            }
        }
        for(int i=0; i<m; i++){
            if((int)edges[link[i].fi].size()%2==0 && (int)edges[link[i].se].size()%2==0){
                if(datas[link[i].fi]+datas[link[i].se]<min_val) min_val=datas[link[i].fi]+datas[link[i].se];
            }
        }
        cout<<min_val<<endl;
    }
    return 0;
}