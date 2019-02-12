#include <iostream>
#include <algorithm>

using namespace std;

int N, M, num =101, sum = 0;
int A[10][10];
bool visit[10][10];
bool outOfBorder(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M)
        return true;
    return false;
}

void DFS(int i, int j, int currentSum, int currentNum) {
    visit[i][j] = true;// ���ʹ��������µ�����
    currentSum += A[i][j];// ���±�����������֮��
    ++currentNum;// ���±���������������
    if (2 * currentSum >= sum) {// �����ǰ������������֮�ʹ��ڵ�����������֮�͵�һ��
        if (2 * currentSum == sum)// �����ǰ������������֮�͵�����������֮�͵�һ��
            num = min(currentNum, num);// ���°������ϽǸ��ӵ��Ǹ���������ĸ��ӵ���С��Ŀ
        visit[i][j] = false;
        return;// ���ݵ���һ���
    }
    if (!outOfBorder(i, j + 1) && !visit[i][j + 1])// �����ƶ�
        DFS(i, j + 1, currentSum, currentNum);
    if (!outOfBorder(i + 1, j) && !visit[i + 1][j])// �����ƶ�
        DFS(i + 1, j, currentSum, currentNum);
    if (!outOfBorder(i, j - 1) && !visit[i][j - 1])// �����ƶ�
        DFS(i, j - 1, currentSum, currentNum);
    if (!outOfBorder(i - 1, j) && !visit[i - 1][j])// �����ƶ�
        DFS(i - 1, j, currentSum, currentNum);
    visit[i][j] = false;
}
int main(){
    cin>>M>>N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin>>A[i][j];
            sum += A[i][j];
        }
    DFS(0,0,0,0);
    if (num ==101)// numû�б仯����˵��û�з���Ҫ��ļ���
        cout<<"0"<<endl;// ���0
    else
       cout<<num<<endl;
    return 0;
}
