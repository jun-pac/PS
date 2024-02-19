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
ll vals[10];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    vals[0]=1;
    for(int i=1; i<10; i++) vals[i]=10*vals[i-1];
    while(t--){
        ll a,b,c;
        ll num;
        cin>>a>>b>>c>>num; 
        if(!(c-1<=max(a,b)<=c)){
            cout<<-1<<endl;
            continue;
        }
        ll mn_a=vals[a-1], mx_a=vals[a]-1;
        ll mn_b=vals[b-1], mx_b=vals[b]-1;
        ll mn_c=vals[c-1], mx_c=vals[c]-1;
        //cout<<mn_b<<' '<<mx_b<<endl;
        ll cnt=0;
        for(ll aa=mn_a; aa<=mx_a; aa++){
            ll temp=min(mx_c,mx_b+aa)-max(mn_c,mn_b+aa)+1;
            if(temp<=0) continue;
            //cout<<"debug : "<<aa<<' '<<max(mn_c,mn_b+aa)<<' '<<min(mx_c,mx_b+aa)<<endl;
            cnt+=temp;
            if(cnt>=num){
                cout<<aa<<" + "<<num-(cnt-temp)+max(mn_c-aa,mn_b)-1<<" = "<<num-(cnt-temp)+max(mn_c-aa,mn_b)-1+aa<<endl;
                break;
            }
        }
        if(cnt<num) cout<<-1<<endl;
    }
    return 0;
}