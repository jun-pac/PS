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

#define MOD 1000000007

int datas[20020];
ll DP[5005];
int cls[5005]; // 현재 점의 cls

#define N 5050
long long fact[N], f_inv[N];

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

long long nCr(int n, int r){
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    fill_fact();
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            int cc;
            cin>>cc;
            datas[i]=cc-1;
            // datas[i] : i의 color
        }

        fill(DP,DP+n,0); // DP는 가짓수를 담는다.
        
        // ssum[i]는 i이전(i포함)의 DP중에서 i와 class가 같은 애들의 값의 합임
        for(int i=0; i<n; i++){
            // datas[i]를 씁니다.
            int temp_cnt=0; // datas[i]와 같은 애들
            int temp_l=i;
            while(temp_l>=0){
                if(datas[temp_l]==datas[i]) temp_cnt++;
                if(temp_cnt>=k) break;
                temp_l--;
            } 
            if(temp_cnt<k){
                cls[i]=(i==0?0:cls[i-1]);
                DP[i]=0; // ?
            }
            else{
                cls[i]=(temp_l==0?1:cls[temp_l-1]+1);
                if(i!=0 && cls[i]<cls[i-1]){
                    DP[i]=0;
                    cls[i]=cls[i-1];
                    continue;
                }
                int l=temp_l;
                int cnt=temp_cnt;
                if(cls[i]==1){
                    l--;
                    while(l>=0){
                        if(datas[l]==datas[i]) cnt++;
                        l--;
                    }
                    DP[i]=nCr(cnt-1,k-1);
                }
                else{
                    //cout<<"DE "<<cls[i]<<' '<<cls[l-1]<<endl;
                    while(l>0 && cls[l-1]==cls[temp_l-1]){
                        //cout<<"CASE : "<<l<<' '<<nCr(cnt-1, k-1)<<' '<<DP[l-1]<<endl;
                        DP[i]=(DP[i]+(nCr(cnt-1, k-1)*DP[l-1])%MOD)%MOD;
                        l--;
                        if(datas[l]==datas[i]) cnt++;
                    }
                }
            }
            //cout<<"i cls DP temp_l temp_cnt : "<<i<<' '<<cls[i]<<' '<<DP[i]<<' '<<temp_l<<' '<<temp_cnt<<endl;
        }
        ll ans=0, r=n-1;
        while(r>=0 && cls[r]==cls[n-1]){
            ans=(ans+DP[r])%MOD;
            r--;
        }
        if(cls[n-1]==0) cout<<1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}