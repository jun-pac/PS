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

int datas[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,d,w;
        cin>>n>>k>>d>>w;
        for(int i=0; i<n; i++) cin>>datas[i];
        int cnt=0;
        int last_t=-100000007;
        int last_cnt=0;
        for(int i=0; i<n; i++){
            if(last_cnt==0 || last_t+d<datas[i]){
                // 새로 약을 까야 할 때
                last_t=datas[i]+w;
                cnt++;
                last_cnt=k-1;
            }
            else{
                last_cnt--;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}