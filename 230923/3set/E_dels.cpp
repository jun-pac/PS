// 
//./E<test

#include <bits/stdc++.h>
//#define endl '\n'
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

class node{
public:
    bool is_plus;
    int val;
    int ch_idx, last_val;
    int last_datas;
};

#define N 1000002
node job_stack[1000010];
int f_app[1000010]; // 각 숫자 처음으로 등장한 idx
int datas[1000010]; 
int st_cnt, sz; // sz가 datas에서 어디까지가 현재 real array인지
int seg[1<<21]; // 첫 등장 여부에 따라 1또는 0 

// 원소를 찾으면 disable도 같이 해주면 될 거 같음
void update_seg(int idx, int l, int r, int t_idx, int val){
    if(l==r){
        seg[idx]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx,val);
    else update_seg(2*idx+1,mid+1,r,t_idx,val);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

int find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1, ans=0;
    if(t_l<=mid) ans=ans+find_seg(2*idx,l,mid,t_l,t_r);
    if(t_r>mid) ans=ans+find_seg(2*idx+1,mid+1,r,t_l,t_r);
    return ans;
}


void jpush(bool is_plus, int val){
    if(is_plus){
        // val 
        job_stack[st_cnt].is_plus=is_plus;
        job_stack[st_cnt].val=val;
        job_stack[st_cnt].last_datas=datas[sz];
        datas[sz]=val;
        sz++;
        if(f_app[val]>=sz-1 || datas[f_app[val]]!=val){
            job_stack[st_cnt].ch_idx=find_seg(1,0,N,sz-1,sz-1), job_stack[st_cnt].last_val=f_app[val];
            f_app[val]=sz-1;
            update_seg(1,0,N,sz-1,1);
        }
        else{
            job_stack[st_cnt].ch_idx=find_seg(1,0,N,sz-1,sz-1), job_stack[st_cnt].last_val=f_app[val];
            update_seg(1,0,N,sz-1,0);
        }
    }
    else{
        job_stack[st_cnt].is_plus=is_plus;
        job_stack[st_cnt].val=val;
        sz-=val;
    }
    st_cnt++;
}

void jpop(){
    if(job_stack[st_cnt-1].is_plus){
        // 원소 하나를 집어넣은 것이죠
        f_app[job_stack[st_cnt-1].val]=job_stack[st_cnt-1].last_val;
        update_seg(1,0,N,sz-1,job_stack[st_cnt-1].ch_idx);
        datas[sz-1]=job_stack[st_cnt-1].last_datas;
        sz--;
    }
    else{
        sz+=job_stack[st_cnt-1].val;
    }
    st_cnt--;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    char c;
    int n;
    st_cnt=0, sz=0;
    cin>>q;
    fill(f_app,f_app+N,10000000);
    for(int i=0; i<q; i++){
        cin>>c;
        if(c=='+'){
            cin>>n;
            jpush(true, n);
        }
        else if(c=='-'){
            cin>>n;
            jpush(false, n);
        }
        else if(c=='!') jpop();
        else{
            //for(int i=0; i<4; i++) cout<<(f_app[i]==10000000?5:f_app[i])<<' ';
            //cout<<endl;
            //for(int i=0; i<4; i++) cout<<find_seg(1,0,N,i,i)<<' ';
            //cout<<endl;
            cout<<(sz==0?0:find_seg(1,0,N,0,sz-1))<<endl;
        }
    }
    return 0;
}