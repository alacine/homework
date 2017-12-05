#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn = 20000;
int s[maxn + 10];

void init() {
    for(int i = 1; i <= 20000 ; i++) {
        s[i] = rand();
    }
}

void BubbleSort() {
    for(int i = 0; i < maxn ; i++) {
        for(int j = i + 1; j < maxn; j++) {
            if(s[j] < s[i]) {
                int tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}

void InsertSort() {
    int low, high, mid;
    for(int i = 2; i < maxn; i++) {
        s[0] = s[i];
        low = 1;
        high = i - 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if(s[0] < s[mid]) high = mid - 1;
            else low = mid + 1;
        }
        for(int j = i - 1; j >= high+1; j--) s[j+1] = s[j];
        s[high+1] = s[0];
    }
}

void MergeSort() {
    
}

int main() {
    srand((unsigned)time(NULL));
    init();
    //BubbleSort();
    InsertSort();
    for(int i = 1; i < 15; i++) {
        cout << s[i] << "\t";
    }
    return 0;
}