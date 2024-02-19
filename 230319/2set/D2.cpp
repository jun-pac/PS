// 
//./D<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

const ll INF=1000000000000000;
//ll DP[300300];
ll cold[300300], hot[300300]; // hot<cold
int datas[300300];
ll straight;

class node{
public:
    // Do something!
    node(){
        //val=0, lazy_val=0;
    }
    node operator+(node b){
        node result;
        // Do something!
        result.val=min(val,b.val);
        return result;
    }
    ll val=INF, lazy_val=0;
};

class lazy_seg{
public:
	node seg[1200000];
	
	lazy_seg(){}
	lazy_seg(int n){
	    //fill(seg,seg+n,node());
	}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			// Do something!
            seg[idx].val=INF;
            seg[idx].lazy_val=0;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=seg[2*idx]+seg[2*idx+1];
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r) return;
		int mid=(l+r)>>1;
		// seg[2*idx], seg[2*idx+1]
		seg[2*idx].val+=seg[idx].lazy_val;
        seg[2*idx+1].val+=seg[idx].lazy_val;
        seg[2*idx].lazy_val+=seg[idx].lazy_val;
        seg[2*idx+1].lazy_val+=seg[idx].lazy_val;
		// seg[idx]의 lazy_val초기화
		seg[idx].lazy_val=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, ll val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			// seg[idx].val과 seg[idx].lazy_val업데이트
            seg[idx].val+=val;
            seg[idx].lazy_val+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
	}
	
    void change_seg(int idx, int l, int r, int t_idx, ll val){
		update_down(idx, l, r);
		if(l==r){
			// seg[idx].val과 seg[idx].lazy_val업데이트
            seg[idx].val=val;
            seg[idx].lazy_val=0;
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) change_seg(2*idx,l,mid,t_idx,val);
		if(t_idx>mid) change_seg(2*idx+1,mid+1,r,t_idx,val);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
	}

	node find_seg(int idx, int l, int r, int t_l, int t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=result+find_seg(2*idx,l,mid,t_l,t_r);
		if(t_r>mid) result=result+find_seg(2*idx+1,mid+1,r,t_l,t_r);
		return result;
	}
};

lazy_seg s;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        ll ans;
        
        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            datas[i]--;
        }
        for(int i=0; i<m; i++) cin>>cold[i];
        for(int i=0; i<m; i++) cin>>hot[i];
        straight=cold[datas[0]];
        //fill(DP,DP+m,INF);
        s.build_seg(1,0,m-1);

        ll last_prog=datas[0];

        for(int i=1; i<n; i++){
            // last_prog와 datas[i]가 같은 경우
            //cout<<i<<" th"<<endl;
            if(datas[i]==last_prog){
                /*
                for(int j=0; j<m; j++){
                    if(j!=last_prog) DP[j]=DP[j]+hot[last_prog];
                }
                */
                s.update_seg(1,0,m-1,0,m-1,hot[datas[i]]);
                straight+=hot[datas[i]];
                continue;
            }
            

            // 반대쪽에 올리는 경우
            //DP[last_prog]=min(DP[last_prog],straight+cold[datas[i]]);
            ll last_prog_val=straight+cold[datas[i]];
            /*for(int j=0; j<m; j++){
                if(j!=last_prog && j!=datas[i]){
                    //cout<<"ds "<<j<<' '<<DP[j]<<' '<<cold[datas[i]]<<endl;
                    DP[last_prog]=min(DP[last_prog],DP[j]+cold[datas[i]]);
                }
                if(j==datas[i]) DP[last_prog]=min(DP[last_prog],DP[j]+hot[datas[i]]);
            }*/
            last_prog_val=min(last_prog_val,s.find_seg(1,0,m-1,0,m-1).val+cold[datas[i]]);
            last_prog_val=min(last_prog_val,s.find_seg(1,0,m-1,datas[i],datas[i]).val+hot[datas[i]]);
            
            // 같은 쪽에 올리는 경우
            /*for(int j=0; j<m; j++){
                if(j!=datas[i] && j!=last_prog) DP[j]=DP[j]+cold[datas[i]];
            }*/
            s.update_seg(1,0,m-1,0,m-1,cold[datas[i]]);
            s.change_seg(1,0,m-1,last_prog,last_prog_val);
            s.change_seg(1,0,m-1,datas[i],INF);

            //DP[datas[i]]=INF;
            last_prog=datas[i];
            straight+=cold[datas[i]];
            
            //ans=INF;
            //for(int j=0; j<m; j++) ans=min(ans,DP[j]);
            
            //cout<<min(straight,ans)<<endl;
            //cout<<"DP : ";
            //for(int j=0; j<m; j++) cout<<(DP[j]>=INF?100:DP[j])<<' ';
            //cout<<endl;
        }
        ans=s.find_seg(1,0,m-1,0,m-1).val;
        //for(int i=0; i<m; i++) ans=min(ans,DP[i]);
        cout<<min(straight,ans)<<endl;
    }
    return 0;
}