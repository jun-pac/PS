// 
//./C<test.txt

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

ll datas[100000];
ll dev[100000];
ll sum_l[100000];
ll sum_r[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        ll res=0;
        if(n%2==1){
            for(int i=1; i<n-1; i+=2){
                res+=max((long long)0,1+max(datas[i-1],datas[i+1])-datas[i]);
            }
        }
        else{
            for(int i=1; i<n-1; i++){
                dev[i]=max((long long)0,1+max(datas[i-1],datas[i+1])-datas[i]);
                if(i%2==1) sum_l[i]=dev[i]+(i!=1?sum_l[i-2]:0);
                else sum_l[i]=sum_l[i-1];
            }
            for(int i=n-2; i>0; i--){
                if(i%2==0) sum_r[i]=dev[i]+(i!=n-2?sum_r[i+2]:0);
                else sum_r[i]=sum_r[i+1];
            }
            res=sum_r[1];
            for(int i=1; i<n-1; i++){
                if(i%2==1){
                    res=min(res,sum_l[i]+(i+3<n?sum_r[i+2]:0));
                    //cout<<"debug : "<<i<<' '<<sum_l[i]<<' '<<(i+3<n?sum_r[i+2]:0)<<endl;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}