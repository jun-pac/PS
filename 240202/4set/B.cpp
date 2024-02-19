
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

ll har[N], datas[N]; // val of har
ll haridx[N];
// ll left_har[N], right_har[N]; //  har idx임
set<pll> sh;


class node{
public:
    // Do something!
    node(){}
    node operator+(node b){ // 두 노드 모두 lazy는 0이라는 가정 
        node result;
        result.aval=aval+b.aval;
        result.bval=bval+b.bval;
        result.abval=abval+b.abval;
        result.lazya=result.lazyb=0;
        return result;
    }
    ll aval=0, lazya=0, bval=0, lazyb=0, abval=0;
};

class lazy_seg{
public:
	node seg[1<<20];
	lazy_seg(){}	
	void build_seg(int idx, int l, int r){
		if(l==r){
            ll leftval=prev(sh.upper_bound({l,-1}))->se;
            ll rightdist=(sh.upper_bound({l,-1})->fi) - l;
			seg[idx].aval=leftval; // left val
            seg[idx].bval=rightdist; // distance
			seg[idx].lazya=0;
            seg[idx].lazyb=0;
            seg[idx].abval=seg[idx].aval*seg[idx].bval;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=(seg[2*idx]+seg[2*idx+1]);
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r || (seg[idx].lazya==0 && seg[idx].lazyb==0)) return;
		ll mid=(l+r)>>1;
		// lazya, lazyb를 모두 가지고 있으면?
        ll len=(mid-l+1);
		seg[2*idx].abval+=seg[idx].lazya*seg[2*idx].bval+seg[idx].lazyb*seg[2*idx].aval+(len)*seg[idx].lazya*seg[idx].lazyb;
        seg[2*idx].aval+=seg[idx].lazya*(len);
        seg[2*idx].bval+=seg[idx].lazyb*(len);
        seg[2*idx].lazya+=seg[idx].lazya;
        seg[2*idx].lazyb+=seg[idx].lazyb;
        
        len=(r-mid);
        seg[2*idx+1].abval+=seg[idx].lazya*seg[2*idx+1].bval+seg[idx].lazyb*seg[2*idx+1].aval+(len)*seg[idx].lazya*seg[idx].lazyb;
        seg[2*idx+1].aval+=seg[idx].lazya*(len);
        seg[2*idx+1].bval+=seg[idx].lazyb*(len);
        seg[2*idx+1].lazya+=seg[idx].lazya;
        seg[2*idx+1].lazyb+=seg[idx].lazyb;

        //assert(seg[idx].abval==seg[2*idx].abval+seg[2*idx+1].abval);
        seg[idx].lazya=seg[idx].lazyb=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, ll aval, ll bval){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
            //assert(!(aval!=0 && bval!=0));
            seg[idx].abval+=aval*seg[idx].bval+bval*seg[idx].aval;
			seg[idx].aval+=aval*(r-l+1);
            seg[idx].bval+=bval*(r-l+1);
            seg[idx].lazya+=aval;
            seg[idx].lazyb+=bval;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,aval,bval);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,aval,bval);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

lazy_seg s;

void Solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    fill(haridx,haridx+n,-1);
    rng(i,0,m-1){
        cin>>har[i];
        har[i]--;
    }
    rng(i,0,m-1) cin>>datas[i];
    rng(i,0,m-1) sh.insert({har[i],datas[i]});

    // left_har[0]=0;
    // right_har[n-1]=m-1;
    // rng(i,1,n-1) left_har[i]=max(left_har[i-1],haridx[i]);
    // gnr(i,n-2,0) right_har[i]=min(right_har[i+1],(haridx[i]==-1?m:haridx[i]));
    //rng(i,0,n-1) cout<<i<<' '<<har[left_har[i]]<<' '<<har[right_har[i]]<<'\n';
    //rng(i,0,n-1) assert(har[right_har[i]]>=i);
    //rng(i,0,n-1) assert(har[left_har[i]]<=i);
    s.build_seg(1,0,n-1);

    rng(i,0,q-1){
        int tt;
        cin>>tt;
        if(tt==1){
            ll x,v; // x라는 곳에 har를 추가
            cin>>x>>v; 
            x--;
            assert(x!=0 && x!=n-1);
            sh.insert({x,v});
            auto l=*prev(sh.lower_bound({x,v})); // [l+1,x]의 입장에서는 우측의 dist가 바뀌는 경험
            auto r=*sh.upper_bound({x,v}); // [x,r-1]의 입장에서는 val이 바뀌는 경험을
            s.update_seg(1,0,n-1,l.fi+1,x,0,-(r.fi-x));
            s.update_seg(1,0,n-1,x,r.fi-1,v-l.se,0);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--, r--;
            // rng(j,l,r) cout<<s.find_seg(1,0,n-1,j,j).abval<<' ';
            // cout<<"\n";
            cout<<s.find_seg(1,0,n-1,l,r).abval<<'\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();
    }
    return 0;
}

