
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int N;
int fx, fy;
struct edge{
    int x1, y1, x2, y2;
};

vector<edge> edges;

double inter_x(int tx, int ty, edge cur){
    if(cur.x1 == cur.x2){
        return cur.x1;
    }
    return (double)tx / (double)ty * cur.y1;
}

int CCW(pll p1, pll p2, pll p3){
    ll val=(p3.se-p2.se)*(p2.fi-p1.fi)-(p3.fi-p2.fi)*(p2.se-p1.se);
    return (val>0?1:(val<0?-1:0));
}

bool inter(int tx, int ty, edge cur){
    pll A(0, 0), B(tx, ty), C(cur.x1, cur.y1), D(cur.x2, cur.y2);
    if(CCW(A,B,D)*CCW(A,B,C)<=0 &&\
        CCW(C,D,A)*CCW(C,D,B)<=0)
        return true;
    else return false;
}



bool simul(vector<int> meet){
    int tx = fx, ty = fy;
    int n = meet.size();
    vector<edge> orders;
    vector<edge> must, never[8];
    vector<edge> never_man;
    set<int> met;
    for(int cur: meet) {
        orders.push_back(edges[cur]);
        met.insert(cur);
    }
    for(int t=0;t<N;t++){
        if(met.find(t) == met.end()){
            never_man.push_back(edges[t]);
        }
    }
    
    for(int t=0;t<n;t++){
        for(int j=t+1;j<n;j++){
            never[t].push_back(orders[j]);
        }
        for(auto& cur: never_man){
            never[t].push_back(cur);
        }
        must.push_back(orders[t]);
        if(orders[t].x1 == orders[t].x2){
            for(int j=t+1;j<n;j++){
                orders[j].x1 = 2 * orders[t].x1 - orders[j].x1;
                orders[j].x2 = 2 * orders[t].x2 - orders[j].x2;
            }
            
            for(auto& cur: never_man){
                cur.x1 = 2 * orders[t].x1 - cur.x1;
                cur.x2 = 2 * orders[t].x2 - cur.x2;
            }
            tx = 2 * orders[t].x1 - tx;
        }else{
            for(int j=t+1;j<n;j++){
                orders[j].y1 = 2 * orders[t].y1 - orders[j].y1;
                orders[j].y2 = 2 * orders[t].y2 - orders[j].y2;
            }
            
            for(auto& cur: never_man){
                cur.y1 = 2 * orders[t].y1 - cur.y1;
                cur.y2 = 2 * orders[t].y2 - cur.y2;
            }
            
            ty = 2 * orders[t].y1 - ty;
        }
    }
    // check
    //cout<<tx<<' '<<ty<<'\n';
    if(tx == 0 or ty == 0) return false;
    for(int t=0;t<n;t++){
        if(!inter(tx,ty, must[t])) return false;

        double crit = inter_x(tx, ty, must[t]);
        //cout<<crit<<'\n';
        for(int j=0;j<never[t].size();j++){
            if(inter(tx, ty, never[t][j]) and abs(inter_x(tx, ty, never[t][j])) < abs(crit)){
                // not possible
                return false;
            }
        }
        
    }
    //cout<<"possible in "<<tx<<' '<<ty<<'\n';
    for(int t=0;t<n;t++){
        //cout<<meet[t]<<' ';
    }
    
    //cout<<'\n';
    return true;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    cin>>fx>>fy;
    for(int i=0;i<N;i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        edges.push_back({x1, y1, x2, y2});
    }
    int ans = -1;
    //when ans == 0
    bool one_inter = false;
    for(int i=0;i<N;i++){
        if(inter(fx, fy, edges[i])){
            one_inter = true;
            break;
        }
    }
    if(!one_inter){
        ans = 0;
    }
    for(int i=1;i<=N;i++){
        vector<int> vec(N);
        for(int j=0;j<N;j++) vec[j] = j;
        do{
            vector<int> meet(i);
            for(int j=0;j<i;j++){
                meet[j] = vec[j];
            }
            if(simul(meet)){
                ans = i;
                cout<<"possible in ";
                for(int j=0;j<i;j++){
                    cout<<meet[j]<<' ';
                }
                cout<<'\n';
                //break;
            }
        }while(next_permutation(vec.begin(), vec.end()));
    }
    if(ans == -1){
        cout<<"impossible";
    }else cout<<ans;

    return 0;
}

