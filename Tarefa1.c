int main(int argc, char const *argv[])
{
    int vetor[] = {1,5,2,6,12,567,12,87,3,45};
    int *v = &vetor;
    mergesort(v, 0, 10);
    for (int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    
    return 0;
}

int aux[100];
merge(int a[], int l, int m, int r){
    int i, j, k;
    for (i = m+1; i>l; i--) aux[i-1] = a[i-1];
    for (j = m; j<r; j++) aux[r+m-l] = a[j+1];
    for (k = l; k<=r; k++)
        if (less(aux[j], aux[i]))
            a[k] = aux[j--]; else a[k] = aux[i++];
}

void mergesort(int a[], int l, int r){
    int m = (r+l)/2;
    if (r <= 1) return;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
}