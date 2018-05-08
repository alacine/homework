// 内存动态分区分配
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int memory[1024];

struct Table {
    int address;
    int size;
    Table *next;
};

struct Work {
    int size;
    int time;
}work[10];

void update_table(Table *start, Table *end) {
    for (int i = 1023; i >= 0; i--) {
        if (memory[i] == 0) {
            int cnt = 0;
            for (int j = i; j >= 0; j--) {
                if (memory[j] == 0) {
                    cnt++;
                    continue;
                }
                break;
            }
            Table *cup;
            cup = new Table;
            cup->address = i - cnt + 1;
            cup->size = cnt;
            cup->next = start->next;
            start->next = cup;
            i -= cnt;
        }
    }
}

int main() {
    Table *head, *end;
    head = new Table;
    end = new Table;
    head->next = end;
    end->next = NULL;
    update_table(head, end);
    int i;
    while (cin >> i && i != -1) {
        cout << i << endl;
    }

    return 0;
}