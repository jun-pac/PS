// 
//./F<test

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

int datas[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        sort(datas,datas+n);
        // ������ �ֵ鸸 ��Ҵٸ�? ��� ���� ����
        // 0�� �ִٸ�? 0������ ��� �� ����
        // ��� k�� �ִٸ� k hop�� �ٸ鼭 ã�ƾ� �ϴµ�, greedy�ϰ� ������ �Ǳ� ��. �׷� ���� n^2�̴ϱ� ������
        // ��� k�� ���õǾ��ٴ� ���� k�̰� �� �Ʒ��δ� �ٷ� 0 ���Ϸ� �߶�.
        // �״ϱ� 0 �����ξֵ� ���� �̴°ͺ��� �ִ� 1 �������� ��
        int m_cnt=0;
        while(m_cnt<n && datas[m_cnt]<=0) m_cnt++;
        if(m_cnt==n) cout<<m_cnt<<endl;
        else if(m_cnt==0){
            cout<<1<<endl;
        }
        else{
            int mn_diff=1000000007;
            for(int i=0; i<m_cnt-1; i++) mn_diff=min(mn_diff,datas[i+1]-datas[i]);
            if(datas[m_cnt]<=mn_diff) cout<<m_cnt+1<<endl;
            else cout<<m_cnt<<endl;
        }
    }
    return 0;
}