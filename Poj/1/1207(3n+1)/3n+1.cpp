#include<iostream>
using namespace std;
int main() {
    int n, p, i, j, count, max, low, high;

    while (!cin.eof()) {
        cin>>i>>j;
        max = 0;
        low = i < j ? i : j;
        high = i < j ? j : i;
        for (p = low; p <= high; p++) {
            n = p;
            count = 1;
            while (1 != n) {
                count++;
                if (n % 2 == 0) {
                    n /= 2;
                } else {
                    n = 3 * n + 1;
                }
            }
            if (count > max) {
                max = count;
            }
        }
        printf("%d %d %d\n", i, j, max);

    }

    return 0;
}
