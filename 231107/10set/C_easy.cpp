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

pair<int,int> datas[200020];
pair<int,int> seg[800000];
int one_len[200020]; // 각 비가 혼자만 덮는 구간
map<pair<int,int>, int> mp;
#define FULL 100000000
// 두 개의 구간이 야무지게 딱 덮으면 막을 방법이 있는가?

void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
    if(t_l<=l && r<=t_r){
        if(seg[idx].fi==-1) seg[idx].fi=val;
        else if(seg[idx].se==-1) seg[idx].se=val;
        else seg[idx]={FULL,FULL}; // 2개 이상이 와 있다.
        return;
    }
    int mid=(l+r)>>1;
    if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
    if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
}

pair<int,int> find_seg(int idx, int l, int r, int t_idx){
    if(l==r) return seg[idx];
    auto res=seg[idx];
    int mid=(l+r)>>1;
    if(t_idx<=mid){
        auto temp = find_seg(2*idx,l,mid,t_idx);
        if(res.fi==-1 && temp.fi!=-1) swap(res, temp);
        if(temp.fi==FULL || res.fi==FULL) res={FULL,FULL};
        else if(temp.fi==-1 && temp.se==-1) res=res;
        else if(res.fi==-1 && res.fi==-1) res=temp;
        else if(res.se==-1 && temp.se==-1) res={res.fi,temp.fi};
        else res={FULL,FULL};

    }
    if(t_idx>mid){
        auto temp=find_seg(2*idx+1,mid+1,r,t_idx);
        if(res.fi==-1 && temp.fi!=-1) swap(res, temp);
        if(temp.fi==FULL || res.fi==FULL) res={FULL,FULL};
        else if(temp.fi==-1 && temp.se==-1) res=res;
        else if(res.fi==-1 && res.fi==-1) res=temp;
        else if(res.se==-1 && temp.se==-1) res={res.fi,temp.fi};
        else res={FULL,FULL};
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<m; i++){
            cin>>datas[i].fi>>datas[i].se;
            datas[i].fi--, datas[i].se--;
        }
        fill(seg,seg+4*n,make_pair(-1,-1));
        for(int i=0; i<m; i++){
            update_seg(1,0,n-1,datas[i].fi,datas[i].se,i);
        }
        fill(one_len, one_len+m, 0);
        mp.clear();
        int offset=0;
        for(int i=0; i<n; i++){
            auto temp=find_seg(1,0,n-1,i);
            if(temp.fi==-1 && temp.se==-1) offset++;
            else if(temp.fi!=-1 && temp.se==-1) one_len[temp.fi]++;
            else if(temp.fi!=FULL && temp.fi!=-1 && temp.se!=-1){
                mp[{min(temp.fi, temp.se), max(temp.fi, temp.se)}]++;
            }
        }
        int mx=0;
        for(int i=0; i<n; i++){
            auto temp=find_seg(1,0,n-1,i);
            if(temp.fi!=FULL && temp.fi!=-1 && temp.se!=-1){
                mx=max(mx,one_len[temp.fi]+one_len[temp.se]+mp[{min(temp.fi, temp.se), max(temp.fi, temp.se)}]);
            }
        }
        sort(one_len,one_len+m);
        mx=max(mx, one_len[m-1]+one_len[m-2]);
        cout<<mx+offset<<endl;
    }
    return 0;
}