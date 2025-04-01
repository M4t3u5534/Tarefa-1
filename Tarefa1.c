#include <stdio.h>

#define maxN 100
int aux[maxN];

int main() {
    int vetor[] = {1, 5, 2, 6, 12, 567, 12, 87, 3, 45};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    mergesort(vetor, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

void merge(int a[], int l, int m1, int m2, int r) {
    int i = l, j = m1 + 1, k = m2 + 1, o = l;
    
    while (i <= m1 && j <= m2 && k <= r) {
        if (a[i] <= a[j] && a[i] <= a[k]) aux[o++] = a[i++];
        else if (a[j] <= a[i] && a[j] <= a[k]) aux[o++] = a[j++];
        else aux[o++] = a[k++];
    }
    
    while (i <= m1 && j <= m2) aux[o++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (j <= m2 && k <= r) aux[o++] = (a[j] <= a[k]) ? a[j++] : a[k++];
    while (i <= m1 && k <= r) aux[o++] = (a[i] <= a[k]) ? a[i++] : a[k++];
    
    while (i <= m1) aux[o++] = a[i++];
    while (j <= m2) aux[o++] = a[j++];
    while (k <= r) aux[o++] = a[k++];
    
    for (int x = l; x <= r; x++) a[x] = aux[x];
}

void mergesort(int a[], int l, int r) {
    if (l >= r) return;
    
    int m1 = l + (r - l) / 3;
    int m2 = l + 2 * (r - l) / 3;
    
    mergesort(a, l, m1);
    mergesort(a, m1 + 1, m2);
    mergesort(a, m2 + 1, r);
    
    merge(a, l, m1, m2, r);
}