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
// P CC...C (PC ... PC) PP...P C
// 맨 앞의 P는 CC...C가 1개 이상일 때만 가능
// 맨 뒤의 C는 PP...P가 1개 이상일 때만 가능

ll datas[200020];
ll ssum[200020]; 
set<ll> even_set, odd_set;

// C...C와 P...P는 포함
ll solve(int s, int e, ll init_offset){
    // offset은 p쪽에 더해질 것을 의미함.
    // 양 끝은 반드시 하나 포함됨을 가정
    ll temp_cnt=0;
    even_set.clear();
    odd_set.clear();
    ll even_offset=0;
    ll odd_offset=0;

    for(int i=e-1; i>=s; i--){
        if((e-i)%2==0){
            even_offset=+datas[i+1]-datas[i+2];
            even_set.insert(ssum[e]-(i==-1?0:ssum[i])-even_offset+init_offset);
            ll lsum=(i==-1?0:ssum[i])-(s==0?0:ssum[s-1])-even_offset;
            auto upper = even_set.upper_bound(lsum);

            temp_cnt+=(ll)distance(upper, even_set.end());
        }
        else{
            if(i==e-1){
                odd_offset+=datas[e];
                odd_set.insert(datas[e]-odd_offset+init_offset);
            }
            else{
                odd_offset+=datas[i+1]-datas[i+2];
                odd_set.insert(ssum[e]-(i==-1?0:ssum[i])-odd_offset+init_offset);
            }
            ll lsum=(i==-1?0:ssum[i])-(s==0?0:ssum[s-1])-odd_offset;

            auto upper = odd_set.upper_bound(lsum);
            temp_cnt+=(ll)distance(upper, odd_set.end());
        }
    }
    //cout<<"For debug : "<<temp_cnt<<endl;
    return temp_cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            ssum[i]=(i==0?datas[i]:ssum[i-1]+datas[i]);
        }
        ll cnt=0;
        // Let ___ be CC..C PCPC...PC PP...P // each element could not appear in the sequence.
        if(n>=2) cnt+=solve(0,n-1,0); // C___P
        if(n>=3) cnt+=solve(1,n-1,datas[0]); // PC__P
        if(n>=3) cnt+=solve(0,n-2,-datas[n-1]); // C__PC
        if(n>=4) cnt+=solve(1,n-2,datas[0]-datas[n-1]); // PC_PC

        // PPPPP, PPPPC, PPPCC, ... ,PCCCC (CCCCC는 확인할 필요가 없음.)
        for(int i=0; i<n; i++){
            if(ssum[i]*2>ssum[n-1]) cnt++;
        }

        cout<<cnt%MOD<<endl;
    }
    return 0;
}