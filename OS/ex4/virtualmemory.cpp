// 虚拟内存
#include <iostream>
#include <ctime>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

const int maxn = 30;

int page[maxn];  // 页面序列
int block[maxn];  // 物理块数组

void init() {  //随机生成一个页面走向的序列
    for (int i = 0; i < maxn; i++) {
        page[i] = rand() % 6 + 1;
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

void show_block(int block_num, int page_index, bool itr) {  // 打印物理块
    cout << page[page_index] << ": ";
    for (int i = 0; i < block_num; i++) {
        cout << block[i] << " ";
    }
    if (!itr) {
        cout << "X ";  // 如果有缺页中断显示一个叉
    }
    cout << endl;
}

int change_block(int block_num, int old, int fresh) {  // 修改物理块
    // 有缺页中断返回1，没有中断返回0
    for (int i = 0; i < block_num; i++) {
        if (block[i] == old) {
            block[i] = fresh;
            return 1;
        }
    }
    return 0;
}

void clean_block() {  // 清空物理块
    for (int i = 0; i < maxn; i++) {
        block[i] = 0;
    }
}


int opt(int block_num) {  // 最佳置换算法，返回缺页中断次数
    int interruptions_num = 0;
    for (int i = 0; i < maxn; i++) {  // 开始历遍页面走向序列
        bool itr = check(page[i], block_num);  // 检查该页面是否在内存中
        if (itr) {
            show_block(block_num, i, itr);  // 打印当前的物理块情况
            continue;
        }
        int longest_time_before_next = 0;  // 内存中页面将来最晚出现的时间
        int index_j = 0;  // 需要进行页面置换的物理块号
        for (int j = 0; j < block_num; j++) {  // 历遍所有物理块
            int time_before_next = 0;  // 该页面将来出现的时间
            for (int k = i + 1; k < maxn; k++) {
                if (block[j] == page[k]) {
                    time_before_next = k - i;  // 计数
                    break;
                }
                if (k == maxn - 1) {
                    time_before_next = maxn;
                }
            }
            if (time_before_next > longest_time_before_next) {  // 标记将来出现最晚的页面号
                longest_time_before_next = time_before_next;
                index_j = j;
            }
        }
        interruptions_num += change_block(block_num, block[index_j], page[i]);  // 缺页中断计数
        show_block(block_num, i, itr);
    }
    return interruptions_num;
}

int fifo(int block_num) {  // 先进先出算法，返回缺页中断次数
    queue<int> block_queue;  // 队列，表示先进先出
    int interruptions_num = 0;
    for (int i = 0; i < block_num; i++) {  // 初始化队列
        block_queue.push(0);
    }
    for (int i = 0; i < maxn; i++) {  // 历遍页面走向序列
        bool itr = check(page[i], block_num);   // 检查该页面是否在内存中
        if (itr) {
            show_block(block_num, i, itr);
            continue;
        }
        block_queue.push(page[i]);  // 当前页面入队
        interruptions_num += change_block(block_num, block_queue.front(), page[i]);
        if (block_queue.size() > block_num) { // 如果队列长度超过了物理块数，队头页面出队
            block_queue.pop();
        }
        show_block(block_num, i, itr);
    }
    return interruptions_num;
}

int lru(int block_num) {  // 最近最久未使用算法，返回缺页中断次数
    int interruptions_num = 0;
    for (int i = 0; i < maxn; i++) {
        bool itr = check(page[i], block_num);  // 检查该页面是否在内存中
        if (itr) {
            show_block(block_num, i, itr);
            continue;
        }
        int longest_time_after_last = 0;  // 最久未使用页面的未使用的时间
        int index_j =0;  // 需要进行页面置换的物理块号
        for (int j = 0; j < block_num; j++) {
            int time_after_last = 0;  // 当前页面未使用的时间
            for (int k = i - 1; k >= 0; k--) {  // 找出哪一块物理块中的页面最久未使用
                if (block[j] == page[k]) {
                     time_after_last = i - k;
                     break;
                }
                if (k == 0) {
                    time_after_last = i - k + 1;
                }
            }
            if (time_after_last > longest_time_after_last) {  // 标记最久未使用页面所在物理块的块号
                longest_time_after_last = time_after_last;
                index_j = j;
            }
        }
        interruptions_num += change_block(block_num, block[index_j], page[i]);
        show_block(block_num, i, itr);
    }
    return interruptions_num;
}

int get_page_chag(int itr_times, int block_num) {  // 计算换页次数
    if (itr_times - block_num < 0) {  // 换页次数不可能为负数
        return 0;
    }
    return itr_times - block_num;
}

int main() {
    srand((unsigned)time(NULL));  // 设置时间为随机数种子
    init();
    int block_num;
    int itr_times = 0;
    int page_chag_times = 0;
    cout << "input the number of blocks" << endl;
    cin >> block_num;
    itr_times = opt(block_num);
    cout << "When use OPT, the number of interruptions is " << itr_times << "." << endl;
    cout << "When use OPT, the number of page changing is " << get_page_chag(itr_times, block_num) << "." << endl;
    cout << "And the page fault rate is " << itr_times*100.0/maxn << "\%." << endl;
    clean_block();
    itr_times = fifo(block_num);
    cout << "When use FIFO, the number of interruptions is " << itr_times << "." << endl;
    cout << "When use FIFO, the number of page changing is " << get_page_chag(itr_times, block_num) << "." << endl;
    cout << "And the page fault rate is " << itr_times*100.0/maxn << "\%." << endl;
    clean_block();
    itr_times = lru(block_num);
    cout << "When use LRU, the number of interruptions is " << itr_times << "." << endl;
    cout << "When use LRU, the number of page changing is " << get_page_chag(itr_times, block_num) << "." << endl;
    cout << "And the page fault rate is " << itr_times*100.0/maxn << "\%." << endl;
    return 0;
}