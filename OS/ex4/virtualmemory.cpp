// 虚拟内存
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

const int maxn = 30;

int page[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        page[i] = rand() % 8 + 1;
        cout << page[i] << " ";
    }
    cout << endl;
}

void opt() {

}

void fifo() {

}

void lru() {

}

int main() {
    srand((unsigned)time(NULL));  //set time as random number seed
    init();
    return 0;
}