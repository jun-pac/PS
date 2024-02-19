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

int datas[100020], st[100020], r_mx[100010], l_mx[100010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) datas[i]--;
        for(int i=0; i<n; i++) st[i]=datas[i];
        for(int i=0; i<n; i++) l_mx[i]=(i==0?datas[0]:max(datas[i],l_mx[i-1]));
        for(int i=n-1; i>=0; i--) r_mx[i]=(i==n-1?datas[n-1]:max(datas[i],r_mx[i+1]));
        sort(st,st+n);
        reverse(r_mx,r_mx+n);

        for(int i=0; i<k; i++){
            int idx=lower_bound(st,st+n,i)-st;
            if(idx==n || st[idx]!=i) cout<<0<<' ';
            else{
                int lidx=upper_bound(l_mx,l_mx+n,i-1)-l_mx;
                int ridx=n-1-(upper_bound(r_mx,r_mx+n,i-1)-r_mx);
                cout<<(ridx-lidx+1)*2<<' ';
            }
        }
        cout<<endl;
        
    }
    return 0;
}