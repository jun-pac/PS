// 
//./F<test

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

vector<pair<int,int>> lazy_val[500050]; // val , time
vector<int> child[500050];
ll res[500050];

#define N 500000
ll seg[1<<20];

// 원소를 찾으면 disable도 같이 해주면 될 거 같음
void update_seg(int idx, int l, int r, int t_idx, ll val){
    if(l==r){
        seg[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx,val);
    else update_seg(2*idx+1,mid+1,r,t_idx,val);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

ll find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    ll mid=(l+r)>>1, ans=0;
    if(t_l<=mid) ans=ans+find_seg(2*idx,l,mid,t_l,t_r);
    if(t_r>mid) ans=ans+find_seg(2*idx+1,mid+1,r,t_l,t_r);
    return ans;
}

void DFS(int idx){
    // res[idx]의 처리
    // 자신의 값 sz이하에 나온 것들만 처리한다는 느낌으로.
    for(auto adder : lazy_val[idx]){
        // 다 더해줌
        update_seg(1,0,N-1,adder.se,adder.fi);
    }
    res[idx]=find_seg(1,0,N-1,idx,N-1);
    for(auto next : child[idx]){
        DFS(next);
    }
    for(auto adder : lazy_val[idx]){
        // 다 빼줌
        update_seg(1,0,N-1,adder.se,-adder.fi);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int sz=1;
        int q,a,b,c;
        cin>>q;
        child[0].clear();
        lazy_val[0].clear();
        
        for(int i=0; i<q; i++){
            cin>>a;
            if(a==1){
                cin>>b;
                b--;
                child[b].push_back(sz);
                child[sz].clear();
                lazy_val[sz].clear();
                //add child to b, value of sz;
                sz++;
            }
            else{
                cin>>b>>c;
                b--;
                lazy_val[b].push_back({c,sz-1});
                // add value c to all subtree of b
            }
        }
        DFS(0);
        for(int i=0; i<sz; i++) cout<<res[i]<<' ';     
        cout<<endl;  
        // for(int i=0; i<sz; i++) lazy_val[i].clear();
        // for(int i=0; i<sz; i++) child[i].clear();
    }
    return 0;
}