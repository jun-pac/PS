// 
//./B<test

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

pair<int,int> datas[500000];
int seg[1300000];
pair<int,int> bs[500000];

void build_seg(int idx, int l, int r){
    if(l==r){
        seg[idx]=datas[l].se;
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid);
    build_seg(2*idx+1,mid+1,r);
    seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Some other operation
}

int find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1, ans=0;
    if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r));
    if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r));
    return ans;
}

bool compare(pair<int,int> p, int val){
    return p.fi<val;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;   
        for(int i=0; i<n; i++) cin>>datas[i].fi>>datas[i].se;
        sort(datas,datas+n);
        for(int i=0; i<n; i++) bs[i]={datas[i].se,i};
        sort(bs,bs+n);

        build_seg(1,0,n-1);
        int ans=1000000007;
        for(int i=n-1; i>=0; i--){
            int tar_a=datas[i].fi;
            int temp_min=1000000007;
            if(i==n-1){
                int b_l=lower_bound(bs,bs+n,tar_a,compare)-bs;
                int comp;
                if(b_l==n){
                    comp=n-1;
                    if(bs[comp].se==i) comp--;
                    if(comp!=-1) umin(temp_min, abs(tar_a-bs[comp].fi));
                    // cout<<"d1 "<<abs(tar_a-bs[comp].fi)<<endl;
                }
                else if(b_l==0){
                    comp=0;
                    if(bs[comp].se==i) comp++;
                    if(comp!=n) umin(temp_min, abs(tar_a-bs[comp].fi));
                    // cout<<"d2 "<<abs(tar_a-bs[comp].fi)<<endl;
                }
                else{
                    comp=b_l;
                    if(bs[comp].se==i) comp++;
                    if(comp!=n) umin(temp_min, abs(tar_a-bs[comp].fi));
                    // cout<<"d2.5 "<<comp<<' '<<abs(tar_a-bs[comp].fi)<<endl;
                    comp=b_l-1;
                    if(bs[comp].se==i) comp--;
                    if(comp!=-1) umin(temp_min, abs(tar_a-bs[comp].fi));
                    // cout<<"d3 "<<abs(tar_a-bs[comp].fi)<<endl;
                }    
            }
            else{
                int mn_b=find_seg(1,0,n-1,i+1,n-1);
                //cout<<"mn_b : "<<mn_b<<endl;
                if(tar_a <= mn_b){
                    // 老锭啊 巩力老刨单
                    umin(temp_min, abs(tar_a-mn_b));
                    // cout<<"d4 "<<abs(tar_a-mn_b)<<endl;
                } 
                else{
                    int b_l=lower_bound(bs,bs+n,tar_a,compare)-bs;
                    int comp;
                    if(b_l==n){
                        comp=n-1;
                        if(bs[comp].se==i) comp--;
                        if(comp!=-1) umin(temp_min, abs(tar_a-bs[comp].fi));
                        // cout<<"d5 "<<abs(tar_a-bs[comp].fi)<<endl;
                    }
                    else if(b_l==0){
                        comp=0;
                        if(bs[comp].se==i) comp++;
                        if(comp!=n) umin(temp_min, abs(tar_a-bs[comp].fi));
                        // cout<<"d6 "<<abs(tar_a-bs[comp].fi)<<endl;
                    }
                    else{
                        comp=b_l;
                        if(bs[comp].se==i) comp++;
                        if(comp!=n) umin(temp_min, abs(tar_a-bs[comp].fi));
                        // cout<<"d6.5 "<<abs(tar_a-bs[comp].fi)<<endl;
                        comp=b_l-1;
                        if(bs[comp].se==i) comp--;
                        if(comp!=-1) umin(temp_min, abs(tar_a-bs[comp].fi));
                        // cout<<"d7 "<<abs(tar_a-bs[comp].fi)<<endl;
                    }
                }
            }
            ans=min(ans,temp_min);
        }
        cout<<ans<<endl;
    }
    return 0;
}