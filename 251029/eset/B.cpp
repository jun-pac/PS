
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll area[N];
array<ll,5> box[N]; // l,r,b,t,idx
priority_queue<pll> pq; // {-r, idx}
map<ll,ll> mp;

int parent[N];
int find_r(int idx){
    if(idx==parent[idx]) return idx;
    return parent[idx]=find_r(parent[idx]);
}
void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        ll x,y,w,h;
        cin>>x>>y>>w>>h;
        box[i]={x,x+w-1,y,y+h-1};
    }   
    // rng(i,0,n-1) cout<<area[i]<<'\n';
    rng(i,0,n-1) parent[i]=i;
    sort(box,box+n);
    rng(i,0,n-1) area[i]=(box[i][3]-box[i][2]+1)*(box[i][1]-box[i][0]+1);
    // rng(i,0,n-1) cout<<"boxes "<<i<<' '<<box[i][0]<<' '<<box[i][1]<<' '<<box[i][2]<<' '<<box[i][3]<<'\n';

    ll curx;
    int idx=0;
    while(idx<n){
        curx=box[idx][0];
        while(!pq.empty() && -pq.top().fi<curx-1){
            int tempidx=pq.top().se;
            mp[box[tempidx][2]]=0;
            mp[box[tempidx][3]]=0;
            pq.pop();
        }
        vc<array<ll,3>> justbefore; // {bottom, top, idx}
        while(!pq.empty() && -pq.top().fi==curx-1){
            int tempidx=pq.top().se;
            mp[box[tempidx][2]]=0;
            mp[box[tempidx][3]]=0;
            justbefore.pb({box[tempidx][2],box[tempidx][3],tempidx});
            pq.pop();
        }
        sort(all(justbefore));

        // cout<<"curx "<<curx<<'\n';
        // rng(i,0,(int)justbefore.size()-1) cout<<"justbefore: "<<justbefore[i][0]<<' '<<justbefore[i][1]<<'\n';
        while(idx<n && box[idx][0]==curx){
            ll tempt=box[idx][3];
            ll tempb=box[idx][2];
            // cout<<"your current: "<<idx<<' '<<box[idx][0]<<' '<<box[idx][1]<<' '<<tempb<<' '<<tempt<<'\n';
            if(mp[tempt+1]!=0){
                // cout<<"sidebyside(top) "<<idx<<' '<<mp[tempt+1]-1<<'\n';
                int ra=find_r(mp[tempt+1]-1);
                int rb=find_r(idx);
                if(ra!=rb){
                    area[ra]+=area[rb];
                    parent[rb]=ra;
                    // cout<<"area "<<ra<<' '<<area[ra]<<'\n';
                }
            }
            if(mp[tempb-1]!=0){
                // cout<<"sidebyside(bottom) "<<idx<<' '<<mp[tempb-1]-1<<'\n';

                int ra=find_r(mp[tempb-1]-1);
                int rb=find_r(idx);
                if(ra!=rb){
                    area[ra]+=area[rb];
                    parent[rb]=ra;
                    // cout<<"area "<<ra<<' '<<area[ra]<<'\n';
                }
            }
            array<ll,3> tar={tempb,-1,-1};
            int bidx=lower_bound(all(justbefore),tar)-justbefore.begin();
            if(bidx!=0) bidx--;
            while(bidx<justbefore.size() && justbefore[bidx][0]<=tempt+1){
                if(justbefore[bidx][1]>=tempb-1){
                    // cout<<"backandforth "<<justbefore[bidx][2]<<' '<<idx<<'\n';
                    int ra=find_r(justbefore[bidx][2]);
                    int rb=find_r(idx);
                    if(ra!=rb){
                        area[ra]+=area[rb];
                        parent[rb]=ra;
                        // cout<<"area "<<ra<<' '<<area[ra]<<'\n';
                    }
                }
                bidx++;
            }
            mp[tempt]=idx+1;
            mp[tempb]=idx+1;
            pq.push({-box[idx][1],idx});
            idx++;
        }

        // pq.insert({-box[i].se,});
    }

    ll mx=0;
    rng(i,0,n-1) mx=max(mx,area[i]);
    cout<<mx<<'\n';
}  

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

