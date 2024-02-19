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

int cnt[100];
vector<ll> pri;

void ppush(ll a){
    if(pri.size()==0) pri.push_back(a);
    else if(pri[pri.size()-1]!=a) pri.push_back(a);
    cnt[pri.size()-1]++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        pri.clear();
        fill(cnt,cnt+100,0);

        ll temp=n;
        while(temp!=1){
            ll end=sqrt(temp)+1;
            bool flag=false;
            //cout<<"de "<<temp<<' '<<end<<endl;
            for(int i=2; i<=end; i++){
                if(temp%i==0){
                    ppush(i);
                    temp=temp/i;
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ppush(temp);
                break;
            }
        }
        /*for(int i=0; i<pri.size(); i++){
            cout<<"prime "<<pri[i]<<' '<<cnt[i]<<endl;
        }*/
        ll res=0;
        ll prod=1;
        ll mx=pri.size();
        int mx_cnt=0;
        for(int i=0; i<mx; i++) mx_cnt=max(cnt[i],mx_cnt);
        for(int i=0; i<mx_cnt; i++){
            prod=1;
            for(int j=0; j<mx; j++){
                if(cnt[j]>i) prod=prod*pri[j];
            }
            res+=prod;
        } 
        cout<<res<<endl;
    }
    return 0;
}