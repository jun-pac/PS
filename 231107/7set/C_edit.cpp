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
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

ll datas[500050];
pair<pair<ll,ll>,ll> qs[500050];
priority_queue<pair<ll,ll>> pq;
long long seg[1<<20];

void update_seg(int idx, int l, int r, int t_l, int t_r, ll val){
    if(t_l<=l && r<=t_r){
        seg[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
    if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
}

ll find_seg(int idx, int l, int r, int t_idx){
    if(l==r) return seg[idx];
    ll res=seg[idx];
    int mid=(l+r)>>1;
    if(t_idx<=mid) res=res+find_seg(2*idx,l,mid,t_idx);
    if(t_idx>mid) res=res+find_seg(2*idx+1,mid+1,r,t_idx);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        while(!pq.empty()) pq.pop();
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        ll q,l,r,x;
        cin>>q;
        for(int i=0; i<q; i++){
            cin>>l>>r>>x;
            l--, r--;
            pq.push({-l,x});
            pq.push({-(r+1),-x});
            // 맨 앞부분 merge
            while(!pq.empty()){
                auto temp=pq.top();
                pq.pop();
                while(!pq.empty() && pq.top().fi==temp.fi){
                    temp.se+=pq.top().se;
                    pq.pop();
                }
                if(temp.se==0) continue;
                else{
                    pq.push(temp);
                    break;
                }
            }
            // 현재 update된 부분이 더 작은지?
            if(!pq.empty() && pq.top().se<0){
                while(!pq.empty()){
                    auto temp=pq.top();
                    pq.pop();
                    update_seg(1,0,n-1,-temp.fi,n-1,temp.se);
                }
            }
        }
        for(int i=0; i<n; i++) cout<<datas[i]+find_seg(1,0,n-1,i)<<' ';
        cout<<endl;
        fill(seg,seg+min((1<<20), 4*n),0);
    }
    return 0;
}