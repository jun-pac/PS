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

int datas[100020];
int query[100010];
pair<int,int> DP[40]; // DP[i]는 0이 i개였던 애들이 어떻게 되는가, added 값, 0개수

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<q; i++) cin>>query[i];
        for(int i=0; i<31; i++) DP[i]={0,i};
        for(int i=0; i<q; i++){
            for(int j=0; j<31; j++){
                if(DP[j].se>=query[i]){
                    DP[j].fi+=(1<<(query[i]-1));
                    DP[j].se=query[i]-1;
                }
            }
        }
        assert(DP[0].fi==0);
        for(int i=0; i<n; i++){
            int temp=datas[i];
            int cnt=0;
            while(temp%2==0){
                temp>>=1;
                cnt++;
            }
            datas[i]+=DP[cnt].fi;
        }
        for(int i=0; i<n; i++) cout<<datas[i]<<' ';
        cout<<endl;
    }
    return 0;
}