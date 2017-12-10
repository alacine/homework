#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn = 20000;
int s[maxn + 10];

void init() {
    for (int i = 1; i <= maxn ; i++) {
        s[i] = rand();
        cout << s[i] << " " ;
    }
    cout << "\n" << endl;
}

void BubbleSort(int arr[]) {
    for (int i = 0; i < maxn ; i++) {
        for (int j = i + 1; j < maxn; j++) {
            if (arr[j] < arr[i]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void InsertSort(int arr[]) {
    int low, high, mid;
    for (int i = 2; i < maxn; i++) {
        arr[0] = arr[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[0] < arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        for (int j = i - 1; j >= high+1; j--) arr[j+1] = arr[j];
        arr[high+1] = arr[0];
    }
}

void Merge(int arr[], int L, int M, int R) {
    int LEFT_SIZE = M - L;
    int RIGHT_SIZE = R - M + 1;
    int left[LEFT_SIZE];
    int right[RIGHT_SIZE];
    //for (int i = 0;)
}

int main() {
    freopen("out.txt","w",stdout);
    srand((unsigned)time(NULL));
    init();
    //BubbleSort(s);
    InsertSort(s);
    for (int i = 1; i < 15; i++) {
        cout << s[i] << " ";
    }
    return 0;
}
