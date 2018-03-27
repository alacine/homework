#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[3] = {1, 10, 3};
    int b[3] = {1, 10};

    sort(a, a + 3);
    sort(b, b + 3);

    for (int i = 0; i < 3; i++) {
        cout << a[i] << " " ;
    }

    return 0;
}