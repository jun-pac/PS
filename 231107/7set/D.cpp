// 
//./D<test

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

int datas[300030], pos[300030];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    for(int i=0; i<n; i++) datas[i]--;
    for(int i=0; i<n; i++) pos[datas[i]]=i;
    // 2���� increasing�ϴ� �����Ͱ� ������, �������� ������ �� �� �ִ���, ���������� ������ �� �� �ִ��� �� �� �ִ�.
    // �� �� ���̱��� ������ convex hull�� �����ڳ׿�
    // 

    int q,l,r;
    cin>>q;

    for(int i=0; i<q; i++){
        cin>>l>>r;
        l--, r--;

    }
    return 0;
}