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

ll a[1000];
int cnt[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool is_same=false;
        int even_cnt=0, odd_cnt=0;
        bool flag=true;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int r=2; r<=n/2; r++){
            fill(cnt, cnt+r, 0);
            bool temp=true;
            for(int i=0; i<n; i++) cnt[a[i]%r]++;
            for(int i=0; i<r; i++) if(cnt[i]<2) temp=false;
            if(temp) flag=false;
        }
        sort(a,a+n);
        for(int i=1; i<n; i++){
            if(a[i]==a[i-1]){
                is_same=true;
            }
        }


        if(is_same){
            cout<<"NO"<<endl;
        }
        else if(!flag){
            cout<<"NO"<<endl; 
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}