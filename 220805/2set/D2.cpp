// 
//./E<test

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

#define INF 1000000009

ll datas[1020], qs[1010];
ll adda[1010], addi[1010]; // 다 더한 거, 하나 빼고 더한 거.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>datas[i];
    sort(datas,datas+n);
    
    for(int i=0; i<n; i++) adda[i]=datas[i]+(n-i);
    for(int i=0; i<n-1; i++) addi[i]=datas[i]+(n-i);
    addi[n-1]=datas[n-1];
    sort(adda, adda+n);
    sort(addi, addi+n-1);
    ll adda_sum=0;
    ll addi_sum=0;
    for(int i=0; i<n; i++) adda_sum=adda_sum+adda[i];
    for(int i=0; i<n-1; i++) addi_sum=addi_sum+addi[i];
    adda_sum-=adda[0]*n;
    addi_sum-=addi[0]*(n-1);

    for(int i=0; i<q; i++) cin>>qs[i];
    for(int i=0; i<q; i++){
        int cur=qs[i];
        if(cur<=n){
            ll res=INF;
            for(int j=0; j<cur; j++){
                res=min(res,datas[j]+(cur-j));
                //cout<<datas[i]+(cur-j)<<endl;
            }
            //for(int j=cur; j<n; j++) cout<<datas[j]<<end;;
            for(int j=cur; j<n; j++) res=min(res,datas[j]);
            cout<<"a"<<res<<' ';
        }
        else if(cur%2==n%2){
            // 현재 값은 adda + (cur-n)인 상황
            // 리분탐색을 이용한다.
            ll cnt=(cur-n)/2; // 이거만큼 빼야 함.
            ll thres=adda_sum;
            if(thres>=cnt) cout<<"b"<<adda[0]+cur-n<<' ';
            else cout<<"c"<<adda[0]-cediv(cnt-thres,n)+cur-n<<' ';
        }
        else{
            // 현재 값은 addi + (cur-n)인 상황 // datas[n]값 빼고
            ll cnt=(cur-n+1)/2;

            if(addi[0]+cur-n>=addi[n-1]){
                // 이 때는 addi[n-1]이 minimum
                // addi_sum+(addi[0]+cur-n-addi[n-1])*(n-1)
                ll thres=addi_sum+(addi[0]+cur-n-addi[n-1])*(n-1);
                if(thres>=cnt) cout<<"d"<<addi[n-1]<<' ';
                else cout<<"e"<<adda[n-1]-cediv(cnt-thres,n)<<' ';
            }
            else{
                // addi[0]가 최소임.
                ll thres=addi_sum+(addi[n-1]-addi[0]-(cur-n));
                if(thres>=cnt) cout<<"f"<<adda[0]+cur-n<<' ';
                else cout<<"g"<<adda[0]+cur-n-cediv(cnt-thres,n)<<' ';
            }
        }
    }
    return 0;
}