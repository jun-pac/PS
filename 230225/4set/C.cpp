// 
//./C<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

#define INF 1000000007

using namespace std;

ll datas[200000];
pair<ll,ll> s_datas[200000]; // val,idx
ll ori_to_seg[200000], seg_to_ori[200000];

class node{
public:
    // Do something!
    node(){}
    node operator+(node b){
        node result;
        result.lazy_val=0;
        result.num=num+b.num;
        result.val=min(val,b.val);
        return result;
    }
    ll val=INF, lazy_val=0, num=0;
};

class lazy_seg{
public:
	node seg[800000];
	
	lazy_seg(){}

	
	void build_seg(ll idx, ll l, ll r){
		if(l==r){
			seg[idx].val=INF;
            seg[idx].lazy_val=0;
            seg[idx].num=0;
		}
		else{
			ll mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=seg[2*idx]+seg[2*idx+1];
		}
	}
	
	void update_down(ll idx, ll l, ll r){
		if(l==r) return;
		ll mid=(l+r)>>1;
		// seg[2*idx], seg[2*idx+1]
		seg[2*idx].val+=seg[idx].lazy_val;
        seg[2*idx+1].val+=seg[idx].lazy_val;
        seg[idx].lazy_val=0;
		// seg[idx]의 lazy_val초기화
	}
	
	void update_seg(ll idx, ll l, ll r, ll t_l, ll t_r, ll val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			// seg[idx].val과 seg[idx].lazy_val업데이트
            seg[idx].val+=val;
            seg[idx].lazy_val+=val;
			return;
		}
		ll mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
	}
	
    void update_num(ll idx, ll l, ll r, ll t_idx, ll val){
		update_down(idx, l, r);
		if(l==r){
			// seg[idx].val과 seg[idx].lazy_val업데이트
            seg[idx].num=1;
            seg[idx].val=val;
			return;
		}
		ll mid=(l+r)>>1;
		if(t_idx<=mid) update_num(2*idx,l,mid,t_idx,val);
		if(t_idx>mid) update_num(2*idx+1,mid+1,r,t_idx,val);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
	}

	ll find_min(ll idx, ll l, ll r, ll t_l, ll t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx].val;
		}
		ll result=INF;
		ll mid=(l+r)>>1;
		if(t_l<=mid) result=min(result,find_min(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=min(result,find_min(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}

    ll find_num(ll idx, ll l, ll r, ll t_l, ll t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx].num;
		}
		ll result=0;
		ll mid=(l+r)>>1;
		if(t_l<=mid) result=result+find_num(2*idx,l,mid,t_l,t_r);
		if(t_r>mid) result=result+find_num(2*idx+1,mid+1,r,t_l,t_r);
		return result;
	}
};

lazy_seg s;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++){
            cin>>datas[i];
        }
        for(ll i=0; i<n; i++){
            s_datas[i]={datas[i],i};
        }
        sort(s_datas,s_datas+n);
        for(ll i=0; i<n; i++) ori_to_seg[s_datas[i].se]=i;
        

        vector<ll> ans;
        s.build_seg(1,0,n-1);
        ll sum=0;
        for(ll i=0; i<n; i++){
            //tot_sum+=datas[i];
            ll idx=ori_to_seg[i];
            //cout<<"IDX : "<<i<<' '<<idx<<' '<<datas[i]<<endl;
            ll last_val=1, val=0;
            if(s.find_num(1,0,n-1,0,idx)==0){
                val=1;
                sum+=datas[i]-val;
                s.update_num(1,0,n-1,idx,datas[i]-val);
                last_val=-1;
            }
            else{
                // 이분탐색으로 가장 오른쪽 non_zero위치 찾기 
                ll l=0, r=idx-1;
                while(l<r){
                    ll mid=(l+r+1)>>1;
                    if(s.find_num(1,0,n-1,mid,idx)>0) l=mid;
                    else r=mid-1;
                }
                last_val=s_datas[l].fi-s.find_min(1,0,n-1,l,l);
                val=min(last_val+1,datas[i]);
                s.update_num(1,0,n-1,idx,datas[i]-val);
                sum+=datas[i]-val;
            }

            //cout<<"LASTVAL : "<<last_val<<' '<<"VAL : "<<val<<endl;

            if(val!=last_val && idx!=n-1){
                ll l=idx+1, r=n-1;// 이분탐색으로 idx~n-1영역에서 0인 애가 존재하는지 찾기
                while(l<r){
                    ll mid=(l+r)>>1;
                    if(s.find_min(1,0,n-1,idx+1,mid)<=0) r=mid;
                    else l=mid+1;
                }   
                // val[r]=0임
                if(s.find_min(1,0,n-1,idx+1,l)>0){
                    //cout<<"ZERO PNT "<<l<<' '<<s.find_num(1,0,n-1,idx+1,l)<<endl;
                    sum-=(ll)s.find_num(1,0,n-1,idx+1,l);
                    s.update_seg(1,0,n-1,idx+1,l,-1);
                }
                else{
                    //cout<<"ZERO PNT "<<l<<' '<<s.find_num(1,0,n-1,idx+1,l-1)<<endl;
                    sum-=(ll)s.find_num(1,0,n-1,idx+1,l-1);
                    s.update_seg(1,0,n-1,idx+1,l-1,-1);
                }
            }

            //cout<<sum<<' ';
            ans.push_back(sum);
        }
        for(ll i=0; i<n; i++) cout<<ans[i]<<' ';
        cout<<endl;
    }  
    return 0;
}