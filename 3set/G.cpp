
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

class node{
public:
    int val;
    int ne, pr; // node¿« idx
};

//int datas[N];
int cnt=0;
node datas[400004];
map<int,int> cur_pos;

void Solve(){
    int n,q;
    cin>>n;  
    int start=0;
    rng(i,0,n-1){
        cin>>datas[i].val;
        cur_pos[datas[i].val]=i;
        if(i!=0) datas[i].pr=i-1;
        if(i!=n-1) datas[i].ne=i+1;
    }
    datas[0].pr=-1;
    datas[n-1].ne=-1;
    cnt=n;

    cin>>q;
    rng(i,0,q-1){
        int a,x,y;
        cin>>a;
        if(a==1){
            cin>>x>>y;
            assert((cur_pos[y]==-1||cur_pos[y]==0) && cur_pos[x]!=-1);
            cur_pos[y]=cnt++;
            int idxy=cur_pos[y], idxx=cur_pos[x];
            int nexidx=datas[idxx].ne;
            datas[idxy].val=y;
            datas[idxy].ne=nexidx;
            datas[idxy].pr=idxx;
            datas[idxx].ne=idxy;
            if(nexidx!=-1) datas[nexidx].pr=idxy;
        }
        else{
            cin>>x;
            int idxx=cur_pos[x];
            assert(cur_pos[x]!=-1);
            cur_pos[x]=-1;
            if(start==idxx){
                start=datas[idxx].ne;
                if(start!=-1) datas[start].pr=-1;
            }
            else{
                int preidx=datas[idxx].pr;
                int nexidx=datas[idxx].ne;
                assert(preidx!=-1);
                datas[preidx].ne=nexidx;
                if(nexidx!=-1) datas[nexidx].pr=preidx;
            }
        }

        // cout<<"debug ";
        // int cur=start;
        // while(cur!=-1){
        //     cout<<datas[cur].val<<' ';
        //     cur=datas[cur].ne;
        // }
        // cout<<'\n';
    }

    int cur=start;
    while(cur!=-1){
        cout<<datas[cur].val<<' ';
        cur=datas[cur].ne;
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

