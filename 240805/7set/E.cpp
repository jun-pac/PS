
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

string a;
string b;
string s;
int alow[N], ahigh[N];
int blow[N], bhigh[N];
int low[N], high[N];
int cnt;
int tcnt;
int res[N];
int sum[1000001];

void peel_out(int l, int r){
    tcnt=0;
    int cur=0;
    bool act=0;
    rng(i,l,r){
        //cout<<i<<' '<<s[i]<<'\n';
        if(!act && '0'<=s[i] && s[i]<='9'){
            cur=(int)(s[i]-'0');
            act=1;
            //cout<<"cur "<<cur<<'\n';
        }
        else if(act && '0'<=s[i] && s[i]<='9'){
            //cout<<"d1 "<<cur<<'\n';
            cur=cur*10+(int)(s[i]-'0');
        }
        else if(act){
            res[tcnt++]=cur;
            //cout<<"d "<<cur<<'\n';
            cur=0;
            act=0;
        }
    }
    // cout<<"what? "<<l<<' '<<r<<'\n';
    // for(auto val : res) cout<<val<<' ';
    // cout<<'\n';
}

#define LOG2 21

class RMQ{
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=sum[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=min(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		// [a,b] minimum query
		assert(a<=b);
		int lgn=LG[b-a+1];
		return min(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};

RMQ rmq;


void main_DFS(int l, int r){
    // cout<<l<<' '<<r<<'\n';
    // rng(i,l,r) cout<<s[i];
    // cout<<'\n';
    if(s[l]=='['){
        peel_out(l,r);
        int curcnt=cnt;
        rng(j,0,tcnt-1) low[cnt++]=res[j];
        rng(j,0,tcnt-1) high[curcnt++]=res[j]; 
        return;
    }
    else if(s[l]=='s' && s[l+1]=='h'){
        peel_out(l,r);
        int curcnt=cnt;
        sort(res, res+tcnt);
        rng(j,0,tcnt-1) low[cnt++]=res[j];
        reverse(res, res+tcnt);
        rng(j,0,tcnt-1) high[curcnt++]=res[j]; 
        return;
    }
    else if(s[l]=='s' && s[l+1]=='o'){
        peel_out(l,r);
        int curcnt=cnt;
        sort(res, res+tcnt);
        rng(j,0,tcnt-1) low[cnt++]=res[j];
        rng(j,0,tcnt-1) high[curcnt++]=res[j]; 
        return;
    }
    else{
        // concat
        int idx=l;
        if(s[l+7]=='['){
            int curcnt=1;
            idx=l+8;
            int st=l+8, e=r-2;
            // l+7이 괄호가 열리는 지점.
            // l+7이상인 지점 중에서 최소의 지점 중 가장 앞의 지점을 찾기
            while(st<e){
                int mid=(st+e)>>1;
                if(rmq.query(l+7,mid)==sum[l+6]) e=mid;
                else st=mid+1;
            }
            assert(s[e]==']');
            idx=e+1;
            main_DFS(l+7,idx-1);
        }
        else if(s[l+7]=='s' || s[l+7]=='c'){
            int curcnt=1;
            idx=l+7;
            while(idx<r && s[idx]!='(') idx++;
            //assert(s[idx]=='(');
            int st=idx+1, e=r-2;
            // idx이 괄호가 열리는 지점.
            // idx이상인 지점 중에서 최소의 지점 중 가장 앞의 지점을 찾기
            while(st<e){
                int mid=(st+e)>>1;
                if(rmq.query(idx,mid)==sum[idx-1]) e=mid;
                else st=mid+1;
            }
            assert(s[e]==')');
            idx=e+1;
            main_DFS(l+7,idx-1);
        }
        main_DFS(idx+1,r-1);
        return;
    }
    return;
}

void Solve(){
    cin>>a;
    cin>>b;
    
    cnt=0;
    s=a;
    rng(i,0,(int)s.size()-1) sum[i]=(i==0?0:sum[i-1])+((s[i]=='('||s[i]=='[')?1:((s[i]==')'||s[i]==']')?-1:0));
    rmq.build_sparse(s.size());
    main_DFS(0,(int)a.size()-1);
    int cnta=cnt;
    rng(i,0,cnt-1) alow[i]=low[i];
    rng(i,0,cnt-1) ahigh[i]=high[i]; 
    
    cnt=0;
    s=b;
    rng(i,0,(int)s.size()-1) sum[i]=(i==0?0:sum[i-1])+((s[i]=='('||s[i]=='[')?1:((s[i]==')'||s[i]==']')?-1:0));
    rmq.build_sparse(s.size());

    main_DFS(0,(int)b.size()-1);
    int cntb=cnt;
    rng(i,0,cnt-1) blow[i]=low[i];
    rng(i,0,cnt-1) bhigh[i]=high[i];
    bool flag=1;
    if(cnta!=cntb) flag=0;
    rng(i,0,cnta-1) if(alow[i]!=blow[i]) flag=0;
    rng(i,0,cnta-1) if(ahigh[i]!=bhigh[i]) flag=0;
    cout<<(flag?"equal\n":"not equal\n");
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

