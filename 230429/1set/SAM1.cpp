// 
//./SAM1<test

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

int datas[100005];
int cnt[100005];
int num;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        int n,k;
        cin>>n>>k;
        num=0;
        fill(cnt,cnt+k+1,0);
        for(int i=0; i<n; i++) cin>>datas[i];
        ll l=0,r=0,res=0;
        while(l<=n-k){
            while(r<n && num!=k){
                cnt[datas[r]]++;
                if(cnt[datas[r]]==1) num++;
                r++;
            }
            if(num==k) res+=n-r+1;
            cnt[datas[l]]--;
            if(cnt[datas[l]]==0) num--;
            l++;
        }
        cout<<'#'<<tt<<' '<<res<<endl;
    }
    return 0;
}