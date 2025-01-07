
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

pair<pair<double,double>,array<double,3>> datas[N]; // {{a/b, c/a},{a, b, c}} 
stack<pair<double,int>> st; // start_pos, edge_idx (in datas)

double get_inter(array<double, 3> l1, array<double, 3> l2){
    ll a1=l1[0], b1=l1[1], c1=l1[2];
    ll a2=l2[0], b2=l2[1], c2=l2[2];
    assert(a1*b2!=a2*b1);
    return (c1*b2-c2*b1)/(a1*b2-a2*b1);
}

double get_y(double pos, array<double, 3> l1){
    return (l1[2]-l1[0]*pos)/(l1[1]);
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        double a,b,c;
        cin>>a>>b>>c;
        double r=a/b;
        double r2=c/a;
        datas[i]={{r,r2},{a,b,c}};   
    }
    sort(datas,datas+n); // 여기의 idx로
    while(!st.empty()) st.pop();
    st.push({0,0});
    rng(i,1,n-1){
        double a1=datas[i-1].se[0], b1=datas[i-1].se[1];
        double a2=datas[i].se[0], b2=datas[i].se[1];
        if(a1*b2==a2*b1) continue; // 더 넓은 놈이 뒤에 나오도록 설계
        
        while(!st.empty()){
            if(get_inter(datas[st.top().se].se,datas[i].se) <= st.top().fi) st.pop();
        }
        if(st.empty()) st.push({0,i});
        else st.push({get_inter(datas[st.top().se].se,datas[i].se),i});
    }
    while(!st.empty()) if(get_y(st.top().fi,datas[st.top().se].se)<0) st.pop();
    assert(!st.empty());
    ll sum=0;
    ll last=datas[st.top().se].se[2]/datas[st.top().se].se[0]; // 지금 처리해야 할 마지막 좌표

    while(!st.empty()){

    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

