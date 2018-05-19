#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn = 20000;
int s[maxn + 10];
int t[maxn + 10];
clock_t runtime, op, ed;

void init() {
    for (int i = 1; i <= maxn ; i++) {
        s[i] = rand();
        t[i] = s[i];
    }
}

// Here is Bubble sort
void BubbleSort(int arr[], int size) {
    for (int i = 1; i <= size ; i++) {
        for (int j = i + 1; j <= size; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Here is Insert sort
void InsertSort(int arr[], int size) {
    int low, high, mid;
    for (int i = 2; i < size; i++) {
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

// Here is Merge sort
void Merge(int arr[], int L, int M, int R) {
    int LEFT_SIZE = M - L;
    int RIGHT_SIZE = R - M + 1;
    int left[LEFT_SIZE];
    int right[RIGHT_SIZE];
    int i, j, k;
    // fill in the left sub array
    for (i = L; i < M; i++) {
        left[i-L] =  arr[i];
    }
    // fill in the right sub array
    for (i = M; i <= R; i++) {
        right[i-M] = arr[i];
    }
    // merge into the original array
    i = 0; j = 0; k = L;
    while (i < LEFT_SIZE && j < RIGHT_SIZE) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
            k++;
        }
        else {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < LEFT_SIZE) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (i < RIGHT_SIZE) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int L, int R) {
    if (L == R) {
        return;
    }
    else {
        int M = (L + R) / 2;
        MergeSort(arr, L, M);
        MergeSort(arr, M+1, R);
        Merge(arr, L, M+1, R);
    }
}

// Here is Quick sort
void QuickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = arr[end];
    int left = start;
    int right = end;
    while (left < right) {
        while (arr[left] < mid && left < right) {
            left++;
        }
        while (arr[right] >= mid && left < right) {
            right--;
        }
        swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end]) {
        swap(arr[left], arr[end]);
    }
    else {
        left++;
    }
    QuickSort(arr, start, left - 1);
    QuickSort(arr, left + 1, end);
}

// Here is Shell sort
void ShellSort(int arr[], int size) {
    int h = 1;
    while (h < size / 2) {
        h = 2 * h + 1;
    }
    while (h >= 1) {
        for (int i = h + 1; i < size; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) {
                swap(arr[j], arr[j - h]);
            }
        }
        h = h / 2;
    }
}

// print the array to a new file
void Print(const char *f) {
    FILE *fp;
    fp = fopen(f, "w");
    cout << "\n" << f << ": " << difftime(ed, op) << " ms" << endl;
    for (int i = 1; i <= maxn; i++) {
        fprintf(fp, "%d ", s[i]);
    }
    fprintf(fp, "\n");
}

int main() {
    srand((unsigned)time(NULL));  //set time as random number seed
    init();
    Print("origin.txt");

    // use clock to timing
    op = clock();
    BubbleSort(s, maxn);
    ed = clock();
    Print("BubbleSort.txt");
    
    op = clock();
    InsertSort(s, maxn);
    ed = clock();
    Print("InsertSort.txt");
    
    op = clock();
    MergeSort(s, 1, maxn);
    ed = clock();
    Print("MergeSort.txt");
    
    op = clock();
    QuickSort(s, 1, maxn);
    ed = clock();
    Print("QuickSort.txt");
    
    op = clock();
    ShellSort(s, maxn);
    ed = clock();
    Print("ShellSort.txt");
    return 0;
}
