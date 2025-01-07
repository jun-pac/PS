
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

class segtree{
public:	
	int seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			// seg[idx]=datas[l];
            seg[idx]=0;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]+=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree segl, segr;

int n;
int f(int y){
    int res;
    // y가 0부터 y까지인거를 가져감
    int val1=segl.find_seg(1,0,n-1,0,y);
    int val2=segl.find_seg(1,0,n-1,0,n-1)-val1;
    int val3=segr.find_seg(1,0,n-1,0,y);
    int val4=n-val1-val2-val3;
    // cout<<"yval "<<y<<' '<<val1<<' '<<val2<<' '<<val3<<' '<<val4<<' '<<min(min(val1,val2),min(val3,val4))<<'\n';
    res=min(min(val1,val2),min(val3,val4));
    return res;
}

pii ternary(int s, int e){
    // find max
    while(3<=e-s){
        int l=(s+s+e)/3, r=(s+e+e)/3;
        if(f(l)>f(r)) e=r;
        else if(f(l)<f(r)) s=l;
        else{
            if(f(s)>f(e)) e=r;
            else if(f(s)<f(e)) s=l;
            else if(f(s)<f(l)){
                s=l, r=e;
            }
            else{
                
            }
        }
    }
    int mx=-INF, res;
    for(int i=s; i<=e; i++){
        int temp=f(i);
        if(mx<temp) mx=temp, res=i;
    }
    return {res,mx};
}

pii pos[N];
int xpos[N], ypos[N];
void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>pos[i].fi>>pos[i].se;
    // x압축 y압축을 하고 seg같은걸 써야하지않나싶음
    rng(i,0,n-1) xpos[i]=pos[i].fi;
    rng(i,0,n-1) ypos[i]=pos[i].se;
    sort(xpos,xpos+n);
    sort(ypos,ypos+n);
    int xn=unique(xpos,xpos+n)-xpos;
    int yn=unique(ypos,ypos+n)-ypos;
    // rng(i,0,xn-1) cout<<xpos[i]<<' ';
    // cout<<'\n';
    rng(i,0,n-1) pos[i].fi=lower_bound(xpos,xpos+xn,pos[i].fi)-xpos;
    rng(i,0,n-1) pos[i].se=lower_bound(ypos,ypos+yn,pos[i].se)-ypos;
    // rng(i,0,n-1){
    //     cout<<i<<" th: "<<pos[i].fi<<' '<<pos[i].se<<'\n';
    // }
    // 압축을 했다 이거야. 그 다음에는 뭐냐.
    // 2개의 multiset을 만들어.
    int mx=0;
    sort(pos,pos+n);
    // rng(i,0,n-1){
    //     cout<<i<<" th: "<<pos[i].fi<<' '<<pos[i].se<<'\n';
    // }
    // x를 갖다가 바꿀것임.
    segl.build_seg(1,0,n-1);
    segr.build_seg(1,0,n-1);
    rng(i,0,n-1) segr.update_seg(1,0,n-1,pos[i].se,1);
    // 이 경우에 mx값은 그냥 mx임
    int cur=0;
    int x0=xpos[0], y0=ypos[0];

    rng(x,0,xn-1){
        // 조금씩 l쪽으로 만들것이다.
        while(cur<n && pos[cur].fi<=x){
            segr.update_seg(1,0,n-1,pos[cur].se,-1);
            segl.update_seg(1,0,n-1,pos[cur].se,1);
            cur++;
        }
        // 삼분탐색
        pii temp=ternary(0,n-1);
        // cout<<"de "<<x<<' '<<temp.fi<<' '<<temp.se<<' '<<segl.find_seg(1,0,n-1,0,n-1)<<' '<<segr.find_seg(1,0,n-1,0,n-1)<<'\n';
        if(mx<temp.se){
            mx=temp.se;
            x0=xpos[x]+1;
            y0=ypos[temp.fi]+1;
        }
    }
    cout<<mx<<'\n';
    cout<<x0<<' '<<y0<<'\n';
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

