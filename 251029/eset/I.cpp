#include<bits/stdc++.h>
using namespace std;
#define N 300030
#define fi first
#define se second
#define rng(i,a,b) for(int i=a; i<=b; i++)
#define gnr(i,a,b) for(int i=a; i>=a; i--)
#define pb push_back

using ll=long long;
template<class t> using vc=vector<t>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int perm[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng(i,0,2) perm[i]=i;
    int a,b,c;
    cin>>a>>b>>c;
    if(max(a,max(b,c))==b){
        swap(a,b);
        swap(perm[0],perm[1]);
    }
    else if(max(a,max(b,c))==c){
        swap(a,c);
        swap(perm[0],perm[2]);
    }
    vc<array<int,3>> ans;
    // a is always the max;
    if(a+1<=b+c){
        int y=(a+c-b+1)/2;
        int x=(a+b-c+1)/2;
        int z=(b+c-a+1)/2;
        cout<<"xyz "<<x<<' '<<y<<' '<<z<<'\n';
        ans.pb({0,0,0});
        rng(i,1,x-1) ans.pb({i,0,0});
        rng(i,1,y-1) ans.pb({0,i,0});
        rng(i,1,z-1) ans.pb({0,0,i});
    }
    else{
        int z=1;
        int x=b;
        int y=c;
        if(a>x*y){
            cout<<"impossible\n";
        }
        ans.pb({0,0,0});
        rng(i,1,x-1) ans.pb({i,0,0});
        rng(i,1,y-1) ans.pb({0,i,0});


        int leftover=a-x-y+1;
        rng(i,1,x-1){
            rng(j,1,y-1){
                if(leftover==0) break;
                leftover--;
                ans.pb({i,j,0});
            }
        }
    }
    cout<<ans.size()<<'\n';
    if(perm[0]==0) for(auto temp: ans) cout<<temp[0]<<' '<<temp[1]<<' '<<temp[2]<<'\n';
    if(perm[0]==1) for(auto temp: ans) cout<<temp[0]<<' '<<temp[2]<<' '<<temp[1]<<'\n';
    if(perm[0]==2) for(auto temp: ans) cout<<temp[2]<<' '<<temp[1]<<' '<<temp[0]<<'\n';
}

