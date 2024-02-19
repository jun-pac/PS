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

int datas[500050];
pair<int, pair<int,int>> qs[500050]; // ������ ���� ��Ȥ�ϴ�.
vector<pair<int,int>> st; // {t,value}�÷� t���� �����ϴ� segment�� ����
vector<pair<int,int>> en; // {t,value}�÷� t���� ������ segment�� ����
int ans[500050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int l,r,x;
        cin>>q;
        st.clear();
        en.clear();
        st.reserve(q);
        en.reserve(q);
        for(int i=0; i<q; i++){
            cin>>l>>r>>x;
            l--, r--;
            st.push_back({l,x});
            en.push_back({r,x});
            //qs[i]={x,{l,r}};
        }
        sort(st.begin(), st.end());
        sort(en.begin(), en.end());

        for(int i=0; i<n; i++){
            // ���� ���� �� ���ֱ�
            // ���⼭ �����ϴ� �� �����ֱ�
            // 
        }
        
        // �� �ڸ��� ���ؼ� O(n)���� ������ �ĺ��� ã�� ���� ����.
        // �� ���� ���� ���ݾ�?
        // a[0], ..., a[i-1]�� �ݵ�� ���� �ž� �Ѵ�~ �̷��Ŵ� ������
        // �׷� �� �ĺ����� ��� ���� ���� �ֳ�?
        // �� priority queue�� �� �� �ֳ�
        // �̰� �ٵ� �� scan�ϴ� ����� �����.
        // ���� ���ɼ��� �ִ°͸� pq�� �̿��ؼ� �����, �� ������ ��ȭ�� jump�� ó���ؾ� �� �� ������
        // �������� ���� �� �����ϴ� �� �ȵɰŰ�
        // ���ϴ� ���� ��ü�� �����ϸ� ����ϴ�. 
        // �װ� �ٸ� ��츦 ���ĺ��� O(n)������
        // ��� �׷� ���ι��� sweeping�ϴ� ������ ���°� �մ��ϳ׿�


    }
    return 0;
}