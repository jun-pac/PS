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

ll gcd(ll x, ll y){
    if(y>x) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    else return gcd(y,x%y);
}

ll a[200000], b[200000], c[200000], d[200000];
// ���� a - ����, b - ����<=10000, c - cost, d - partitionũ��
// d[i]=c[i]*b[i]����, a[i]%d[i]==0 �����ؾ�
// ������ c[i]�� �ִ��� �����ϵ��� 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i]>>b[i];
        int ans=1;
        ll cur_gcd=a[0]*b[0];
        ll margin=a[0]; // ���ο� gcd�� ���ߴµ�, cur_gcd���� a[0]�� ��ŭ�� �۾Ƶ� �ȴ�.
        for(int i=1; i<n; i++){
            ll cur_mul=a[i]*b[i];
            ll new_gcd=gcd(cur_gcd,cur_mul);
            ll new_r=cur_mul/new_gcd;
            if(a[i]%new_r==0 && margin%(cur_gcd/new_gcd)==0){
                margin/=(cur_gcd/new_gcd);
                margin=gcd(margin,new_gcd/b[i]);
                cur_gcd=new_gcd;
            }
            else{
                ans++;
                cur_gcd=cur_mul;
                margin=a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}