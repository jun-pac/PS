
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

// �̰� �׻� a[i]�� ����� ũ�� �׳� ���� ������,
// a[i]�� �ʹ� ������ (tar>a[i]) => (last<=a[i] && tar<=last+b[i] => tar-b[i]<=last<=a[i])
// �״ϱ� �츮�� ���ɻ簡 b[i]��ŭ�� ������
// �̰� ������ �����ϴ� �����ε�, a[i]�� ...?
// �ϴ� ��� tar�� ã�� �ʹٸ� a[i]<=tar�̰ų�, tar<=a[i]+b[i]�� ��� �����ؾ� �Ѵ�.

// �ٵ� tar�� ã�� �͵� ������. tar�� ã���� �Ǵ� ������ [l,r]�̾��ٸ�
// l<=a[i]�̸� ���� ��. a[i]<l<=a[i]+b[i]�̶�� ���� tar�� [l-b[i], a[i]]�� �Ǵ�...
// �ϴ� l�� �߿��ϴٴ� ����� �� �� �ִ�. �׷��ٸ� � greedy�� �����ұ�?

// ���� �ĺ��߿��� as[i]>=l�� ������ ���� ��.
// �׷��� �ʴٸ� as[i]+bs[i]>=l�� ������ �Ұ����ϹǷ� ���� ��.
// ���� �͵� �߿����� bs[i]�� ū �� ���� �ǳ�?
// �׳� ������ a[i]+b[i]�߿� ���� ���� �� ���� greedy��? -- �̰� �Ƹ� l�� �ּ�ȭ�ϴ� ������ٵ� ū a�� ��� �������...
// �̷��� �������ȴµ� a[i]�� ũ�� �Ʊ�� �� �ƴѰ�?
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

