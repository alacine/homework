#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

const int n = 5; // 进程数量
const int m = 4; // 资源种类

int Available[m]; // 资源向量
int Max[n][m]; // 最大需求矩阵
int Allocation[n][m]; // 分配矩阵
int Need[n][m]; // 需求矩阵
int Request[n][m]; // 进程的请求向量

int Work[m]; // 工作向量
int Finish[n]; // 完成向量

void init() {
    cout << "input Available[4]:" << endl; // 输入现有的4类资源向量
    for (int i = 0; i < m; i++) {
        cin >> Available[i];
    }
    cout << "input Max[5,4]:" << endl; // 输入最大需求矩阵(5*4), 非负数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Max[i][j];
        }
    }
    cout << "input Allocation[5][4]:" << endl; // 输入分配矩阵(5*4, 非负数)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Allocation[i][j];
        }
    }
    // 得到需求矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
            cout << Need[i][j] << " ";
        }
        cout << endl;
    }
}

int IsSafe() {
    // 定义两个返回值
    int safe = 1;
    int unsafe = 0;
    // 初始化完成向量和工作向量
    for (int i = 0; i < m; i++) {
        Work[i] = Available[i];
    }
    for (int i = 0; i < n; i++) {
        Finish[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int flag = 1;
        cout << "start" << endl;
        for (int p = 0; p < m; p++) {
            cout << Work[p] << " ";
        }
        cout << endl;
        for (int p = 0; p < m; p++) {
            cout << Need[i][p] << " ";
        }
        cout << endl;
        if (!Finish[i]) {
            for (int j = 0; j < m; j++) {
                if (Need[i][j] > Work[j]) {
                    cout << "in" << endl;
                    cout << i << " " << j << endl;
                    cout << Need[i][j] << " " << Work[j] << endl;
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            for (int j = 0; j < m; j++) {
                Work[j] = Work[j] + Allocation[i][j];
                Need[i][j] = 0;
                Finish[i] = 1;
                i = 0;
            }
        }
        if (i == 4 && flag == 0) {
            return unsafe;
        }
    }
    return safe;
}

int main() {
    freopen("input.txt", "r", stdin);
    init();
    if (IsSafe()) {
        cout << "safe" << endl;
    }
    else {
        cout << "unsafe" << endl;
    }
    return 0;
}