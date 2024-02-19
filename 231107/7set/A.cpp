// 
//./A<test

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

int aa[100010], bb[100010];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n-1; i++) cin>>aa[i];
        for(int i=0; i<n; i++) cin>>bb[i];
        sort(aa,aa+n-1);
        sort(bb,bb+n);
        // aa[0] = 1, 2,` ... , m
        // 각각에 대해 답을 구하면 된다
        ll sum=0;

        // a[0]=1인 case
        int cur_pos=lower_bound(aa,aa+n-1,1)-aa; // a[0]가 매칭되는 위치
        int l=0, r=n;
        while(l<r){
            int mid=(l+r+1)/2;
            bool flag=true;
            for(int i=0; i<mid; i++){
                if((i==0?1:aa[i-1])>=bb[n-mid+i]){
                    flag=false;
                    break;
                }
            }
            if(!flag) r=mid-1;
            else l=mid;
        }
        sum+=n-l;
        
        // 처음으로 l이 아니라 l-1로 줄어드는 a[0]를 구하는 것이다.
        if(l!=n && aa[l-1]<bb[n-1]){
            sum=(ll)m*(n-l);
        }
        else{
            int pnt=bb[n-1];
            int cur=0;
            for(int i=0; i<l-1; i++){
                if(aa[i]>=bb[i]){
                    pnt=bb[i];
                    break;
                }
            }
            sum=(ll)m*(n-l)-(max(0,m-pnt+1));
        }
        cout<<sum<<endl;
    }
    return 0;
}