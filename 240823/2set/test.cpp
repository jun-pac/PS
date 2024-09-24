#include <bits/stdc++.h>
using namespace std;
int cnt, N, t1, t2;
// const int NODES = 2147483647;
//�� ������Ʈ���� ��� ������ �̷���ִ��� üũ component 
unordered_map<int, int> parent;
int findParent(int x)
{
    if(x==parent[x]){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}
void Merge(int x, int y)
{
    int rootX = findParent(x);
    int rootY = findParent(y);
    
    
    // cout << "Merging " << x << " and " << y << endl;
    // cout << "Root of " << x << ": " << rootX << endl;
    // cout << "Root of " << y << ": " << rootY << endl;
    
    if(rootX != rootY)
    {
        parent[rootY] = rootX; 
    }
}
int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    unordered_set<int> nodes;
    
    int result = 0;
    //������ ��Ȧ�� �� ����
    
    cin >> cnt >> N;
    
    /*
    //�̸� �Ҵ� ���� �ʿ������ 
    for(int i= 0; i < NODES; ++i)
    {
        parent[i] = i;
    }
    */
    
    for(int i = 0 ; i < cnt; ++i)
    {
        t1 = t2 = 0;
        cin >> t1 >> t2;
        
        // ����� ��� �߰�
        // cout << "Processing nodes: " << t1 << " " << t2 << endl;
        
        // ��尡 ó�� ������ �� �ʱ�ȭ
        if (parent.find(t1) == parent.end()) {
            parent[t1] = t1;
        }
        if (parent.find(t2) == parent.end()) {
            parent[t2] = t2;
        }
        
        Merge(t1, t2);
        
        //���߿� ī�������� 
        nodes.insert(t1);
        nodes.insert(t2);
       // nodes.push_back(t1);
       //  nodes.push_back(t2);
    }
    
    // pair � ������ ��� �����Ѵ� 
    // ������ ã�� 
    // rootNode, count
    unordered_map<int, int> component;
    for(auto num : nodes)
    {
        int p = findParent(num);
        component[p]++;
    }
    
    for(auto &node : component)
    {
        if(node.second <= N)
        {
            result += node.second;
        }
    }
    
    cout << result << endl;
    
    return 0;
}



