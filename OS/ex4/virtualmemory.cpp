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


void init() {  //随机生成一个页面走向的序列
    for (int i = 0; i < maxn; i++) {
        page[i] = rand() % 8 + 1;
        cout << page[i] << " ";
    }
    cout << endl;
}

bool check(int page, int block_num) {  // 查看当前页面是否在内存中
    for (int i = 0; i < block_num; i++) {
        if (page == block[i]) {
            return true;
        }
    }
    return false;
}

void show_block(int block_num, int page_index) {  // 打印物理块
    cout << page[page_index] << ": ";
    for (int i = 0; i < block_num; i++) {
        cout << block[i] << " ";
    }
    cout << endl;
}

int change_block(int block_num, int old, int fresh) {  // 修改物理块
    for (int i = 0; i < block_num; i++) {
        if (block[i] == old) {
            block[i] = fresh;
            return 1;
        }
    }
    return 0;
}

int fifo(int block_num) {  // 先进先出算法
    queue<int> block_queue;
    int interruptions_num = 0;
    for (int i = 0; i < block_num; i++) {
        block_queue.push(0);
    }
    for (int i = 0; i < maxn; i++) {
        if (check(page[i], block_num)) {
            show_block(block_num, i);
            continue;
        }
        block_queue.push(page[i]);
        interruptions_num += change_block(block_num, block_queue.front(), page[i]);
        if (block_queue.size() >= block_num) {
            block_queue.pop();
        }
        show_block(block_num, i);
    }
    return interruptions_num;
}

int opt(int block_num) {
    int interruptions_num = 0;
    for (int i = 0; i < maxn; i++) {
        int sum = 9999;
        int index_j = 0;
        for (int j = 0; j < block_num; j++) {
            int cnt = 0;
            for (int k = 0; k < maxn; k++) {
                if (block[j] == page[k]) {
                    cnt ++;
                }
            }
            if (cnt < sum) {
                sum = cnt;
                index_j = j;
            }
        }
        if (check(page[i], block_num)) {
            show_block(block_num, i);
            continue;
        }
        interruptions_num += change_block(block_num, block[index_j], page[i]);
        show_block(block_num, i);
    }
    return interruptions_num;
}

void lru() {

}

int main() {
    srand((unsigned)time(NULL));  //set time as random number seed
    init();
    int n;
    cout << "input the number of blocks" << endl;
    cin >> n;
    int fifo_ans = fifo(n);
    cout << "When use FIFO, the number of interruptions is " << fifo_ans << "." << endl;
    cout << "When use FIFO, the number of page changing is " << fifo_ans + n << "." << endl;
    cout << "And the page fault rate is " << fifo_ans*100.0/maxn << "\%." << endl;
    int opt_ans = opt(n);
    return 0;
}