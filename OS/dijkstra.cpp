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
int SafeSequence[n]; // 安全序列

void init() {
    cout << "input Available[4]:" << endl; // 输入现有的4类资源向量
    for (int i = 0; i < m; i++) {
        cin >> Available[i];
    }
    cout << "input Allocation[5][4]:" << endl; // 输入分配矩阵(5*4, 非负数)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Allocation[i][j];
        }
    }
    cout << "input Need[5,4]:" << endl; // 输入需求矩阵(5*4), 非负数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Need[i][j];
        }
    }
    // 得到最大需求矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Max[i][j] = Need[i][j] + Allocation[i][j];
        }
    }
}

void Print() {
    cout << "----------------------------------------" << endl;
    cout << "Allocation" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << Allocation[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Need" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << Need[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Available" << endl;
    for (int i = 0; i < m; i++) {
        cout << Available[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
}

int IsSafe() {
    int safe = 1; // 定义两个返回值
    int unsafe = 0;
    int sum = 0;  // sum 用来表示已完成的进程数量
    for (int i = 0; i < m; i++) { // 初始化工作向量为资源向量
        Work[i] = Available[i];
    }
    for (int i = 0; i < n; i++) { // 初始化完成向量，即每个任务未完成
        Finish[i] = 0;
    }

    for (int i = 0; i < n; i++) { //开始历遍每个任务
        int flag = 1;
        if (!Finish[i]) { // 若当前任务未完成
            for (int j = 0; j < m; j++) { // 比较Need和Work数组
                if (Need[i][j] > Work[j]) { // 只要有一类资源不满足就都不分配资源
                    flag = 0;
                    break;
                }
            }
            if (flag) { // 当前可用资源数量能够使该进程顺利执行
                for (int j = 0; j < m; j++) {
                    Work[j] += Allocation[i][j]; // 释放该进程的资源
                }
                SafeSequence[sum] = i; // 加入安全序列
                Finish[i] = 1; // 标记该任务已完成
                sum += 1; // 完成数量加一
                i = 0; // 每完成一个任务，就从头开始历遍未完成的任务
            }
        }

        if (i == n - 1 && flag == 0) {
            return unsafe; // 返回当前状态为安全
        }
        if (sum == n) {
            return safe; // 返回当前状态为不安全
        }
    }
}

void Diy() {
    int k;
    char answer;
    while (1) {
        int flag = 1;
        cout << "Which process do you want to give resource to? ";
        cout << "Input '0' means the fisrt one, '1' means the second one, and so on." << endl;
        cin >> k;
        cout << "OK, now you need to give me the number of each resource like '0 0 1 0'." << endl;
        for (int i = 0; i < m; i++) {
            cin >> Request[k][i];
        }
        for (int i = 0; i < m; i++) {
            if (Request[k][i] > Available[i] || Request[k][i] > Need[k][i]) {
                flag = 0;
                cout << "Sorry, you ask too much." << endl;
                break;
            }
        }
        if (flag == 1) {
            for (int i = 0; i < m; i++) {
                Available[i] -= Request[k][i];
                Allocation[k][i] += Request[k][i];
                Need[k][i] -= Request[k][i];
            }
            if (IsSafe()) {
                cout << "OK, it is done." << endl;
                cout << "Do you want to see it?(Y/N) ";
                cin >> answer;
                if (answer == 'Y' || answer == 'y') {
                    Print();
                }
                else if (answer == 'N' || answer == 'n') {
                    ;// do nothing.
                }
                else {
                    ;// do nothing
                }
            }
            else {
                for (int i = 0; i < m; i++) {
                    Available[i] -= Request[k][i];
                    Allocation[k][i] += Request[k][i];
                    Need[k][i] -= Request[k][i];
                }
                cout << "Sorry, it is not safe, you can't do that." << endl;
            }
        }
        cout << "Do you want to qiut? (Y/N) ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y') {
            break;
        }
        else {
            ;// do nothing
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    init();
    if (IsSafe()) {
        cout << "safe" << endl;
        cout << "The safe sequence is <";
        for (int i = 0; i < n; i++) {
            cout << SafeSequence[i] << ",";
        }
        cout << ">" <<endl;
        //Diy();
    }
    else {
        cout << "unsafe" << endl;
    }
    return 0;
}