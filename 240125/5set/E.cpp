
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

ll as[N], bs[N];
ll ls[N], rs[N];

// 이게 항상 a[i]가 충분히 크면 그냥 답이 나오고,
// a[i]가 너무 작으면 (tar>a[i]) => (last<=a[i] && tar<=last+b[i] => tar-b[i]<=last<=a[i])
// 그니까 우리의 관심사가 b[i]만큼씩 내려감
// 이걸 역으로 추적하는 과정인데, a[i]가 ...?
// 일단 적어도 tar를 찾고 싶다면 a[i]<=tar이거나, tar<=a[i]+b[i]는 적어도 만족해야 한다.

// 근데 tar를 찾는 것도 범위다. tar를 찾으면 되는 범위가 [l,r]이었다면
// l<=a[i]이면 게임 끝. a[i]<l<=a[i]+b[i]이라면 다음 tar는 [l-b[i], a[i]]가 되는...
// 일단 l만 중요하다는 사실을 알 수 있다. 그렇다면 어떤 greedy가 가능할까?

// 남은 후보중에서 as[i]>=l이 있으면 증명 끌.
// 그렇지 않다면 as[i]+bs[i]>=l이 없으면 불가능하므로 증명 끝.
// 남은 것들 중에서는 bs[i]가 큰 걸 고르면 되나?
// 그냥 가능한 a[i]+b[i]중에 가장 작은 걸 고르는 greedy는? -- 이게 아마 l을 최소화하는 방법일텐데 큰 a가 모두 사라지면...
// 이렇게 지워버렸는데 a[i]가 크면 아까운 거 아닌가?
// 


bool visited[N];
priority_queue<pll> abpq; // {a+b,idx}
priority_queue<pll> apq; // {a,idx}
priority_queue<pll> bpq;

inline void pqclear(){
    while(!apq.empty() && visited[apq.top().se]) apq.pop();
    while(!bpq.empty() && visited[bpq.top().se]) bpq.pop();
}

void Solve(){
    ll n,k;
    cin>>n>>k;
    while(!abpq.empty()) abpq.pop();
    while(!apq.empty()) apq.pop();
    while(!bpq.empty()) bpq.pop();

    rng(i,0,n-1){
        cin>>as[i]>>bs[i];
        if(i!=0) abpq.push({as[i]+bs[i],i});
    }

    ll tar=k;
    fill(visited,visited+n,0);
    if(as[0]>=k){
        cout<<"YES\n";
        return;
    }
    if(as[0]+bs[0]<tar){
        cout<<"NO\n";
        return;
    }
    else{
        visited[0]=1;
        tar-=bs[0];
    }

    while(true){
        while(!abpq.empty() && abpq.top().fi>=tar){
            int idx=abpq.top().se;
            apq.push({as[idx],idx});
            bpq.push({bs[idx],idx});
            abpq.pop();
        }
        pqclear();

        if(apq.empty()){
            cout<<"NO\n";
            return;
        }
        if(apq.top().fi>=tar){
            cout<<"YES\n";
            return;
        }
        if(apq.top().se!=bpq.top().se){
            pll temp=bpq.top();
            tar=tar-temp.fi;
            visited[temp.se]=1;
        }
        else{
            pll tempa=apq.top(), tempb=bpq.top();
            apq.pop(); bpq.pop();
            pqclear();
            if(apq.empty()){
                assert(bpq.empty());
                tar=tar-tempb.fi;
                visited[tempb.se]=1;
                continue;
            }
            int asecond=apq.top().fi, bsecond=bpq.top().fi;
            if(asecond+tempb.fi>bsecond+tempa.fi){
                tar=tar-tempb.fi;
                visited[tempb.se]=1;
            }
            else{
                tar=tar-bsecond;
                visited[bpq.top().se]=1;
                apq.push(tempa);
                bpq.push(tempb);
            }
        }
    }
    //cout<<"NO\n";
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

