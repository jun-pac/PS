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

int perm[100100];
int pos[100100];
int a[100100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;
        for(int i=0; i<n; i++){
            cin>>perm[i];
            pos[perm[i]]=i;
        }
        for(int i=0; i<m; i++) cin>>a[i];
        bool is_bad=true;
        int mn_dist=10000000;
        for(int i=0; i<m-1; i++){
            if(pos[a[i]] < pos[a[i+1]] && pos[a[i+1]] <= pos[a[i]]+d){
                mn_dist=min(mn_dist,pos[a[i+1]]-pos[a[i]]);
                if(n>d+1) mn_dist=min(mn_dist,d+1-(pos[a[i+1]]-pos[a[i]]));
            }
            else{
                is_bad=false;
                break;
            }
        }
        if(!is_bad){
            cout<<0<<endl;
        }
        else{
            cout<<mn_dist<<endl;
        }
    }
    return 0;
}