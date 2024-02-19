
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
#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num, ll mod){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((mod-2)&(1LL<<i)){
            res=(res*mult)%mod;
        }
        mult=(mult*mult)%mod;
    }
    return res;
}

ll gcd(ll x, ll y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

void Solve(){
    ll x,y;
    cin>>x>>y;
    // 2=ax-by
    // GCD x,y==1ÀÎ °æ¿ì
    if(x==0){
        if(abs(y)==1) cout<<2<<' '<<0<<'\n';
        else if(abs(y)==2) cout<<1<<' '<<0<<'\n';
        else cout<<-1<<'\n';
        return;
    }
    if(y==0){
        if(abs(x)==1) cout<<0<<' '<<2<<'\n';
        else if(abs(x)==2) cout<<0<<' '<<1<<'\n';
        else cout<<-1<<'\n';
        return;
    }
    ll g=gcd(abs(x),abs(y));
    if(g>2){
        cout<<-1<<'\n';
        return;
    }
    bool flag=0;
    if(g==2){
        x/=2;
        y/=2;
    }
    else flag=1;

    ll q, r1, r2, r, s1, s2, s, t1, t2, t;

	r1 = x, r2 = y;
	s1 = 1, s2 = 0, t1 = 0, t2 = 1;

    while (true)
	{
		q = r1 / r2;
		r = r1 - (q * r2);
		s = s1 - (q * s2);
		t = t1 - (q * t2);

		if (r == 0)
		{
			cout << "GCD : " << r2 << '\n';
			cout << "S : " << s2 << ' '<<(s2*x%y+y)%y<<' '<<s2*y%x<<' '<<'\n';
			cout << "T : " << t2 <<' '<<t2*x%y <<' '<<(t2*y%x+x)%x<< '\n';
			break;
		}

		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}

    ll a=(s2%y+y)%y, b=(-t2%x+x)%x;
    //cout<<"check "<<a*x-b*y<<' '<<(a*x)%y<<' '<<(b*y)%x<<'\n';

    if(flag) cout<<2*b<<' '<<2*a<<'\n';
    else cout<<b<<' '<<a<<'\n';

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

