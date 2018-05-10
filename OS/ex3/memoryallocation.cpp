/* 内存动态分区分配
 * 采用首次适应算法
 */
#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

int memory[1024];  // 定义内存空间
clock_t timetable[10]; // 定义一个时间表，用于表示每个任务的开始时间

struct Table {  // 定义空闲分区表
    int address; // 起始空间
    int size;  // 大小
    Table *next;
};

struct Work {  // 定义作业
    int size;  // 作业大小
    int time;  // 完成作业所需要的时间
}work[10];

void clean_table(Table *start, Table *end) {  // 清空分区表
    Table *ta;
    ta = start->next;
    while (ta->next != NULL) {  // 回收空间
        start->next = ta->next;
        delete ta;
        ta = start->next;
    }
}

void update_table(Table *start, Table *end) {  // 更新空闲分区表
    // 先清空原来的分区表
    clean_table(start, end);
    // 重新建立分区表
    for (int i = 1023; i >= 0; i--) {  // 从后往前找
        if (memory[i] == 0) {
            int cnt = 0;
            for (int j = i; j >= 0; j--) {  // 找到了空闲的块，开始计算大小
                if (memory[j] == 0) {
                    cnt++;
                    continue;
                }
                break;
            }
            Table *ta;  // 在分区表head后插入这个空闲的块
            ta = new Table;
            ta->address = i - cnt + 1;
            ta->size = cnt;
            ta->next = start->next;
            start->next = ta;
            i -= cnt;
        }
    }
}

int allocate_memory(int n, Table *start, Table *end) {  // 分配内存，分配成功返回1，分配失败返回0
    for (int i = 0; i < 1024; i++) {  // 已经在内存里的任务不需要再分配
        if (memory[i] == n + 1) {
            return 0;
        }
    }
    Table *ta;
    ta = start->next;
    while (ta->next != NULL) {
        if (ta->size >= work[n].size) {  // 找到一个足够大的空闲的块，将该作业载入内存
            for (int i = ta->address; i < ta->address + work[n].size; i++) {
                memory[i] = n + 1;
            }
            timetable[n] = clock();  // 记录下该作业开始的时间
            return 1;
        }
        ta = ta->next;
    }
    return 0;
}

void recovery() {  // 回收运行完成的作业
    clock_t t;
    t = clock();  // 记下开始执行回收操作时的时间
    for (int i = 0; i < 10; i++) {
        // 当时间已经满足了某一个作业的完成时间，释放该作业占用的内存空间
        if (timetable[i] != 0 && t-timetable[i] >= CLOCKS_PER_SEC*work[i].time) {
            for (int j = 0; j < 1024; j++) {
                if (memory[j] == i + 1) {
                    memory[j] = 0;
                }
            }
        }
    }
}

void print_table(Table *start, Table *end) {  // 打印空闲分区表
    Table *ta;
    ta = start->next;
    int i = 0;
    cout << "\n" << "Start of Table" << endl;
    while (ta->next != NULL) {
        cout << i << " ";
        cout << ta->address << " ";
        cout << ta->size << endl;
        i++;
        ta = ta->next;
    }
    cout << "End of Table\n" << endl;
}

void show_memory() {  // 显示当前内存空间的分配状况
    for (int i = 0; i < 1024; i++) {
        if (memory[i] == 0) {
            cout << "/" << " ";
        }
        else {
            cout << memory[i]-1 << " ";
        }
        if ((i + 1) % 50 == 0 && i > 9) {  // 方便阅读，一排显示50个内存单元
            cout << endl;
        }
    }
    cout << endl;
}

void delete_table(Table *start, Table *end) {  // 删除表，释放所有空间
    clean_table(start, end);
    delete start;
    delete end;
}

int main() {
    Table *head, *end;
    head = new Table;
    end = new Table;
    head->next = end;
    end->next = NULL;
    update_table(head, end);
    int i;
    while (1) {
        cout << "input the order number (0 <= i <= 9) of work" << endl;
        cout << "quit if i = -1" << endl;
        cin >> i;
        if (i == -1) {
            break;
        }
        else {
            // 输入作业的大小和需要的时间，以秒为单位
            cout << "input the size and time of this work: ";
            cin >> work[i].size >> work[i].time;
            recovery();  // 回收已完成的作业占用的内存
            update_table(head, end);  // 回收后及时更新空闲分区表
            if (allocate_memory(i, head, end)) {
                cout << "SUCCESS" << endl;
                update_table(head, end);  //分配后及时更新空闲分区表
            }
            else {
                cout << "FAILED" << endl;
            }
        }
        print_table(head, end);
        show_memory();
    }
    delete_table(head, end); // 程序结束，回收所有空间
    return 0;
}