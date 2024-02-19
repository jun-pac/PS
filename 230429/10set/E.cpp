// Sprague-grundy Theorem
// ���� [��������, ������������, �Ϲݰ���, �� ���� ������, ������ ����] 
// ������ ������ grundy���� ������ �� ����. 
// 0�̸� ������ �й�� ����� ��Ȳ
// Grundy Number of State A = mex{A���� �̵��� �� �ִ� ������ Grundy��}
// 0�̸� �й��ϴ� �ʱ�����, 1�̸� �¸��ϴ� �ʱ�����

// ���� ���� ���� ���ÿ� ����� ���� XOR���� Grundy��

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int x, res=0;
    for(int i=0; i<n; i++){
        cin>>x;
        res=res^x;
    }
    cout<<(res!=0?"koosaga":"cubelover")<<'\n';
    return 0;
}