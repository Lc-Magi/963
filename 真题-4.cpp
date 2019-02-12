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
    visit[i][j] = true;// 访问过该坐标下的数字
    currentSum += A[i][j];// 更新遍历过的数字之和
    ++currentNum;// 更新遍历过的数字数量
    if (2 * currentSum >= sum) {// 如果当前遍历过的数字之和大于等于所有数字之和的一半
        if (2 * currentSum == sum)// 如果当前遍历过的数字之和等于所有数字之和的一半
            num = min(currentNum, num);// 更新包含左上角格子的那个区域包含的格子的最小数目
        visit[i][j] = false;
        return;// 回溯到上一结点
    }
    if (!outOfBorder(i, j + 1) && !visit[i][j + 1])// 向右移动
        DFS(i, j + 1, currentSum, currentNum);
    if (!outOfBorder(i + 1, j) && !visit[i + 1][j])// 向下移动
        DFS(i + 1, j, currentSum, currentNum);
    if (!outOfBorder(i, j - 1) && !visit[i][j - 1])// 向左移动
        DFS(i, j - 1, currentSum, currentNum);
    if (!outOfBorder(i - 1, j) && !visit[i - 1][j])// 向上移动
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
    if (num ==101)// num没有变化过，说明没有符合要求的剪法
        cout<<"0"<<endl;// 输出0
    else
       cout<<num<<endl;
    return 0;
}
