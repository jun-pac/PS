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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll p,q,x;
        cin>>p>>q;
        // p�� ���, q�� ����� �ƴ�, ���� ū x
        // p�� ���μ����ش�...?
        // ��� p�� �Ҽ��� ������ p�� 1�� ����
        // ���ʿ� p%q==0�� ���� �����ϸ� �� ��
        if(p%q==0){
            ll mx=1;
            ll r=q;
            ll temp=p/r;
            //cout<<temp<<endl;
            while(temp%q==0) temp/=r;
            //cout<<"p1 "<<temp<<endl;
            mx=max(mx,temp);
            for(ll i=2; i<=(ll)sqrt(q)+1; i++){
                r=i;
                // ����� �Ҽ��� ������ ����� �ϴ�
                if(q%r==0){
                    //cout<<"hello : "<<q<<' '<<r<<' '<<p/r<<endl;
                    temp=p/r;
                    while(temp%q==0){
                        //cout<<"check : "<<temp<<' '<<(temp%r)<<endl;
                        temp/=r;
                    }
                    //cout<<"p2 "<<temp<<endl;

                    mx=max(mx,temp);
                    r=q/i;
                    if(r==1) break;
                    temp=p/r;
                    while(temp%q==0)temp/=r;
                    //cout<<"p3 "<<temp<<endl;
                    mx=max(mx,temp);
                }
            }
            cout<<mx<<endl;
        }
        else{
            cout<<p<<endl;    
        }
    }
    return 0;
}