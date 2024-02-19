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

// idx������ �������� 0�� bonus���� �̻��̾��ٸ�, �տ� �ִ� bonus�� ������ ������. (���� 0�� ��������� ���� ����?)
// idx������ � ���������� 0�� bonus�������� ���� �� �ִ�. �̶��� ������ ��.

priority_queue<ll> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        while(!pq.empty()) pq.pop();
        ll sum=0;
        ll a;
        for(int i=0; i<n; i++){
            cin>>a;
            if(a==0){
                if(pq.size()!=0){
                    a=pq.top();
                    pq.pop();
                    sum+=a;
                }
            }
            else{
                pq.push(a);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}