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

ll datas[200020], qs[200020];
ll adda[200020], addi[200020]; // �� ���� ��, �ϳ� ���� ���� ��.
ll min_adda[200020], min_right[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>datas[i];
    sort(datas,datas+n);
    for(int i=n-1; i>=0; i--) min_right[i]=(i==n-1?datas[n-1]:min(datas[i],min_right[i+1]));
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
    for(int i=0; i<n; i++) min_adda[i]=(i==0?adda[0]:min(min_adda[i-1],adda[i]));

    for(int i=0; i<q; i++) cin>>qs[i];
    for(int i=0; i<q; i++){
        int cur=qs[i];
        if(cur<=n){
            ll res=INF;
            /*for(int j=0; j<cur; j++){
                res=min(res,datas[j]+(cur-j));
                //cout<<datas[i]+(cur-j)<<endl;
            }*/
            // 0~cur-1������ adda - (n-cur)�� ��Ȳ 
            
            //for(int j=cur; j<n; j++) cout<<datas[j]<<end;;
            //for(int j=cur; j<n; j++) res=min(res,datas[j]);
            res=min((cur==0?INF:min_adda[cur-1]-(n-cur)),(cur==n?INF:min_right[cur]));
            cout<<res<<' ';
        }
        else if(cur%2==n%2){
            // ���� ���� adda + (cur-n)�� ��Ȳ
            // ����Ž���� �̿��Ѵ�.
            ll cnt=(cur-n)/2; // �̰Ÿ�ŭ ���� ��.
            ll thres=adda_sum;
            if(thres>=cnt) cout<<adda[0]+cur-n<<' ';
            else cout<<adda[0]-cediv(cnt-thres,n)+cur-n<<' ';
        }
        else{
            // ���� ���� addi + (cur-n)�� ��Ȳ // datas[n]�� ����
            ll cnt=(cur-n+1)/2;
            if(n==1) cout<<datas[0]-(cur/2)<<' ';
            else if(addi[0]+cur-n>=addi[n-1]){
                // �� ���� addi[n-1]�� minimum
                // addi_sum+(addi[0]+cur-n-addi[n-1])*(n-1)
                ll thres=addi_sum+(addi[0]+cur-n-addi[n-1])*(n-1);
                if(thres>=cnt) cout<<addi[n-1]<<' ';
                else cout<<adda[n-1]-cediv(cnt-thres,n)<<' ';
            }
            else{
                // addi[0]�� �ּ���.
                ll thres=addi_sum+(addi[n-1]-addi[0]-(cur-n));
                if(thres>=cnt) cout<<adda[0]+cur-n<<' ';
                else cout<<adda[0]+cur-n-cediv(cnt-thres,n)<<' ';
            }
        }
    }
    return 0;
}