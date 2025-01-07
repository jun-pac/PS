
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
#define INF 10000000000000007 

pll pos[N];
pair<char, ll> mv[N]; // dir, dist
bool visited[N];
pair<ll,pll> x_fi[N], y_fi[N];
set<pair<ll,pll>> x_seg, y_seg; // 각각 {x,{ymn, ymx}}같은걸 업데이트 함. 겹치면?

void Solve(){
    ll n,m,x,y; // hause, mv
    cin>>n>>m>>x>>y;
    rng(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        pos[i]={a,b}; // 각각의 집별로 visited를 만들 수 있을 듯
    }
    rng(i,0,n-1){
        x_fi[i]={pos[i].fi,{pos[i].se,i}};
        y_fi[i]={pos[i].se,{pos[i].fi,i}};
    }

    rng(i,0,m-1){
        char a;
        ll b;
        cin>>a>>b;
        mv[i]={a,b};
        // cout<<mv[i].fi<<' '<<mv[i].se<<'\n';
    }
    
    sort(x_fi, x_fi+n);
    sort(y_fi, y_fi+n);
    ll cnt=0;

    rng(i,0,m-1){
        ll nx, ny;
        ll dist=mv[i].se;
        if(mv[i].fi=='L'){
            nx=x-dist;
            ny=y;
        }
        if(mv[i].fi=='R'){
            nx=x+dist;
            ny=y;
        }
        if(mv[i].fi=='D'){
            nx=x;
            ny=y-dist;
        }
        if(mv[i].fi=='U'){
            nx=x;
            ny=y+dist;
        }
        // cout<<dist<<' '<<nx<<' '<<ny<<'\n';
        if(mv[i].fi=='L' || mv[i].fi=='R'){
            // use y_fi, y_seg {y,{mn,mx}}
            ll mn=min(x,nx);
            ll mx=max(x,nx);
            pair<ll,pll> cur={y,{mn,mx}};
            // 뒷쪽
            
            // 앞쪽
            pair<ll,pll> temp={y,{mn,-INF}};
            auto prev_seg=y_seg.upper_bound(temp);
            if(prev_seg!=y_seg.begin()){
                prev_seg=prev(prev_seg);
                if((*prev_seg).fi==y && (*prev_seg).se.se>=mn-1){
                    temp=*prev_seg;
                    y_seg.erase(*prev_seg);
                    cur={y,{min(mn,temp.se.fi),max(mx,temp.se.se)}};   
                }
            }
            temp={y,{cur.se.fi,-INF}};
            auto next_seg=y_seg.lower_bound(temp);
            while(next_seg!=y_seg.end() && (*next_seg).fi==y && (*next_seg).se.fi<=cur.se.se+1){
                temp=*next_seg;
                next_seg=next(next_seg);
                y_seg.erase(temp);
                cur={y,{min(cur.se.fi,temp.se.fi),max(cur.se.se,temp.se.se)}};   
            }
            y_seg.insert(cur);
        }
        else{
            // use x_fi 
            ll mn=min(y,ny);
            ll mx=max(y,ny);
            pair<ll,pll> cur={x,{mn,mx}};
            
            // 뒷쪽
            pair<ll,pll> temp={x,{mn,-INF}};
            auto prev_seg=x_seg.upper_bound(temp);
            if(prev_seg!=x_seg.begin()){
                prev_seg=prev(prev_seg);
                if((*prev_seg).fi==x && (*prev_seg).se.se>=mn-1){
                    temp=*prev_seg;
                    x_seg.erase(*prev_seg);
                    cur={x,{min(mn,temp.se.fi),max(mx,temp.se.se)}};   
                }
            }
            temp={x,{cur.se.fi,-INF}};
            auto next_seg=x_seg.lower_bound(temp);
            while(next_seg!=x_seg.end() && (*next_seg).fi==x && (*next_seg).se.fi<=cur.se.se+1){
                temp=*next_seg;
                next_seg=next(next_seg);
                x_seg.erase(temp);
                cur={x,{min(cur.se.fi,temp.se.fi),max(cur.se.se,temp.se.se)}};   
            }
            x_seg.insert(cur);
        }
        x=nx, y=ny;
    }


    // x_seg
    for(auto temp: x_seg){
        ll curx=temp.fi;
        ll mn=temp.se.fi;
        ll mx=temp.se.se;
        // cout<<"? "<<curx<<' '<<mn<<' '<<mx<<'\n';
        pair<ll,pll> tar={curx,{mn,-INF}};
        auto curptr=lower_bound(x_fi,x_fi+n,tar);
        while(curptr!=x_fi+n && (curptr->fi)==curx && (curptr->se.fi)<=mx){
            if(!visited[curptr->se.se]){
                visited[curptr->se.se]=1;
                cnt++;
            }
            curptr++;
        }
    }
    // y
    for(auto temp: y_seg){
        ll cury=temp.fi;
        ll mn=temp.se.fi;
        ll mx=temp.se.se;
        // cout<<"! "<<cury<<' '<<mn<<' '<<mx<<'\n';
        pair<ll,pll> tar={cury,{mn,-INF}};
        auto curptr=lower_bound(y_fi,y_fi+n,tar);
        while(curptr!=y_fi+n && (curptr->fi)==cury && (curptr->se.fi)<=mx){
            if(!visited[curptr->se.se]){
                visited[curptr->se.se]=1;
                cnt++;
            }
            curptr++;
        }
    }

    cout<<x<<' '<<y<<' '<<cnt;

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

