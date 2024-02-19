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
vector<int> ans;

bool all2(ll x){
    while(x%2==0) x/=2;
    return x==1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        ans.clear();
        ans.push_back(x);   
        while(!all2(x)){
            ll temp=1;
            while((temp&x)==0){
                //cout<<"d "<<temp<<' '<<(temp&x)<<endl;
                temp*=2;
            }

            x-=temp;
            ans.push_back(x);
        }
        //cout<<"mid "<<x<<endl;
        while(x!=1){
            x/=2;
            ans.push_back(x);
        }
        
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}