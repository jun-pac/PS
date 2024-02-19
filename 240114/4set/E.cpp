
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

int datas[N];

// always DIFF>=MEX : 0,1,2,3,[],6,6,7,8 -> MEX=4, DIFF=4+(number over 4)
// 그래서 지금 큰 애들을 greedy하게  붙여주면 좋을 것 같다.
// 0에서부터.. 사실 빈칸을 메꾸는 과정이니까,

map<int,int> mp;
int n,k;

void Solve(){
    cin>>n>>k;
    mp.clear();
    rng(i,0,n-1){
        cin>>datas[i];
        mp[datas[i]]++;
    }
    sort(datas,datas+n);
    // if(n==100000) rng(i,n-100,n-1) cout<<datas[i]<<' ';
    int l=0, num_diff=0, num_datas=0;
    while(l<=n){
        if(mp[l]>0) num_diff++, num_datas+=mp[l];
        // l+1-num_diff개의 빈 칸을 min(k,n-num_datas)로 채우는게 가능한지
        //cout<<"cur "<<l<<' '<<num_diff<<' '<<n-num_datas<<'\n';
        if(l+1-num_diff>min(k,n-num_datas+mp[l]-1)) break;
        l++;
    }
    if(l+1-num_diff>min(k,n-num_datas+mp[l]-1)) l--;

    // [0,l]까지는 된다고 치자고요
    priority_queue<pii> pq;
    int idx=upper_bound(datas,datas+n,l)-datas; // 이게 n이 될 일은 없..?
    int prev=-1, adds=0;
    //if(n==100000) cout<<l<<' '<<datas[idx-1]<<'\n';
    rng(i,idx,n-1){
        if(prev==datas[i]) continue;
        //if(n==100000) cout<<datas[i]<<' ';

        pq.push({-mp[datas[i]],datas[i]});
        prev=datas[i];
    }
    rng(i,0,k-1){
        if(pq.empty()) break;
        pii temp=pq.top();
        pq.pop();
        mp[temp.se]--;
        assert(mp[temp.se]>=0);
        if(temp.fi!=-1) pq.push({temp.fi+1,temp.se});
    }
    int res=0;
    for(auto temp : mp){
        if(temp.fi>l && temp.se!=0) res++;
        //if(temp.fi>l && temp.se!=0 && n==100000) cout<<temp.se<<' '<<temp.fi<<'\n';
    }
    cout<<res<<'\n';
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

