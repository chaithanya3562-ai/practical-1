#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int t[100], i = l, j = m + 1, k = l;
    while(i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while(i <= m) t[k++] = a[i++];
    while(j <= r) t[k++] = a[j++];
    for(i = l; i <= r; i++)
        a[i] = t[i];
}
void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main() {
    int n, a[100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
