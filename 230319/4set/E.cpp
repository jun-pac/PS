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

unsigned long long DP[100];

void prt_sec(ll num, ll step, ll offset){
    // step is minimum number that satisfies : DP[step]>=num;
    //cout<<"for debug. "<<num<<' '<<step<<' '<<offset<<' '<<(DP[step]>=num)<<endl;
    if(step==1){
        cout<<step+offset<<' ';
        return;
    }
    if(DP[step]==num){
        for(int i=0; i<step; i++) cout<<offset+step-i<<' ';
        return;
    }

    int cur;
    unsigned long long ssum=0;
    for(int i=step-1; i>=0; i--){
        ssum+=DP[i];
        if(ssum>=num){
            cur=i;
            break;
        }
    }
    // 예컨대 cur==step-1이면 1+offset출력하고 나머지는 직무유기
    // 즉 step-cur개 출력 
    for(int i=0; i<step-cur; i++) cout<<step-cur+offset-i<<' ';
    prt_sec(num-(ssum-DP[cur]),cur,offset+step-cur);

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        DP[0]=1;
        int last_val=-1;
        for(int i=1; i<=n; i++){
            if(i==1) DP[i]=1;
            else DP[i]=2*DP[i-1];
            if(DP[i]>=k){
                last_val=i;
                break;
            }
        }
        //if(last_val!=-1) cout<<"dfe1 : "<<last_val<<' '<<DP[last_val]<<endl;
        if(last_val==-1) cout<<-1<<endl;
        else{
            for(int i=0; i<n-last_val; i++) cout<<i+1<<' ';
            prt_sec(k,last_val,n-last_val);
            //cout<<"k? "<<k<<endl;
            cout<<endl;
        }
    }
    return 0;
}