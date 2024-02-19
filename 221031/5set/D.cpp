// 
//./D<test.txt

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

inline int tdiv(ll num){
    int cnt=0;
    while(num!=0 && num%2==0){
        num/=2;
        cnt++;
    }
    return cnt;
}

#define N 200020
ll datas[N];
int divtable[N];
int divs[N];
int divsum[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0; i<N; i++) divtable[i]=tdiv(i);
    
    while(t--){
        int n;
        cin>>n;
        int tcnt=0;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++){
            tcnt+=tdiv(datas[i]);
            divs[i]=divtable[i+1];
        }

        //cout<<"tcnt "<<tcnt<<endl;
        sort(divs,divs+n);
        reverse(divs,divs+n);
        divsum[0]=divs[0];
        for(int i=1; i<n; i++) divsum[i]=divsum[i-1]+divs[i];

        //for(int i=0; i<n; i++) cout<<divsum[i]<<" ";
        //cout<<endl;

        if(divsum[n-1]+tcnt<n) cout<<-1<<endl;
        else if(tcnt>=n) cout<<0<<endl;
        else cout<<lower_bound(divsum,divsum+n,n-tcnt)-divsum+1<<endl;
    }
    return 0;
}