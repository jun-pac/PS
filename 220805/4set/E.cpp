// 
//./E<test

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

#define MOD 998244353
#define N 300000
#define MAX_DIGIT 62

long long fact[N], f_inv[N];

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

void fill_fact(){
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+N,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<N; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

int p_team[1<<19]; // 각 position(=seed)의 팀. 주어지는 데이터 
int t_pos[1<<19]; // 각 팀의 position
int seg[1<<20];

void build_seg(int idx, int l, int r){
    if(l==r){
        seg[idx]=(p_team[l]==-1?1:0);
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid);
    build_seg(2*idx+1,mid+1,r);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

// 해당 idx의 개수를 제거하는 작동
void update_seg(int idx, int l, int r, int t_idx){
    if(l==r){
        seg[idx]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx);
    else update_seg(2*idx+1,mid+1,r,t_idx);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

int find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1, ans=0;
    if(t_l<=mid) ans=ans+find_seg(2*idx,l,mid,t_l,t_r);
    if(t_r>mid) ans=ans+find_seg(2*idx+1,mid+1,r,t_l,t_r);
    return ans;
}

bool visited[1<<19];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k;
        n=(1<<k);
        fill(t_pos,t_pos+n,-1);
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            a--;
            if(a==-2) a++;
            p_team[i]=a;
            if(p_team[i]!=-1) t_pos[p_team[i]]=i;
        }
        for(int u=0; u<k; u++){
            int l=(u==0?0:(1<<u));
            int r=(1<<(u+1))-1;
            sort(t_pos+l,t_pos+r+1);
        }
        for(int i=0; i<n; i++) if(t_pos[i]!=-1) p_team[t_pos[i]]=i;
        build_seg(1,0,n-1);

        ll cnt=1;
        bool flag=true;
        ll ones=(1<<(k-1));
        for(int u=0; u<k; u++){
            // [1<<u, 1<<(u+1))
            fill(visited,visited+((1<<u)+1),0);
            if(u>1) ones=ones+(1<<(k-u));
            int l=(u==0?0:(1<<u));
            int r=(1<<(u+1))-1;
            // 이번 iteration에서는 [l,r]을 커버할 생각입니다.
            ll num=0; // 아직 자리가 안정해진 애들의 개수
            int idx=l;
            while(idx<=r && t_pos[idx]==-1){
                idx++;
            }
            num=idx-l;
            ll val=1; // 곱할거니까 시작을 1로 줘야합니다.
            while(idx<=r){
                // t_pos[idx]와 t_pos[idx+1]가 같은 bucket에 포함되어있으면 강등
                if(u==0) visited[(t_pos[idx]&ones)>>(k-u-2)]=1;
                else visited[(t_pos[idx]&ones)>>(k-u-1)]=1;

                if(idx==r) break;
                if((t_pos[idx]&ones) == (t_pos[idx+1]&ones)){
                    flag=false;
                    break;
                }
                idx++;
            }
            if(!flag) break;
            
            for(int i=0; i<(u==0?2:(1<<u)); i++){
                if(visited[i]) continue;
                int duration=(u==0?(1<<(k-1)):(1<<(k-u)));
                val=val*find_seg(1,0,n-1,i*duration,(i+1)*duration-1);
                
            }

        }   
        if(!flag) cout<<0<<endl;
    }
    return 0;
}