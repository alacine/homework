// 虚拟内存
#include <iostream>
#include <ctime>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

const int maxn = 30;

int page[maxn];
int block[maxn];
queue<int> block_queue;


void init() {  //随机生成一个页面走向的序列
    for (int i = 0; i < maxn; i++) {
        page[i] = rand() % 8 + 1;
        cout << page[i] << " ";
    }
    cout << endl;
}

bool check(int page, int block_num) {
    for (int i = 0; i < block_num; i++) {
        if (page == block[i]) {
            return true;
        }
    }
    return false;
}

void show_block(int block_num, int page_index) {
    cout << page[page_index] << ": ";
    for (int i = 0; i < block_num; i++) {
        cout << block[i] << " ";
    }
    cout << endl;
}

void change_block(int block_num, int old, int fresh) {
    for (int i = 0; i < block_num; i++) {
        if (block[i] == old) {
            block[i] = fresh;
            break;
        }
    }
}

void fifo(int block_num) {
    for (int i = 0; i < block_num; i++) {
        block_queue.push(0);
    }
    for (int i = 0; i < maxn; i++) {
        if (check(page[i], block_num)) {
            show_block(block_num, i);
            continue;
        }
        block_queue.push(page[i]);
        change_block(block_num, block_queue.front(), page[i]);
        if (block_queue.size() >= block_num) {
            block_queue.pop();
        }
        show_block(block_num, i);
    }
}

void opt() {
    
}

void lru() {

}

int main() {
    srand((unsigned)time(NULL));  //set time as random number seed
    init();
    int n;
    cout << "input the number of blocks" << endl;
    cin >> n;
    fifo(n);
    return 0;
}