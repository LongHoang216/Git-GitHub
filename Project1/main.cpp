#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// TÌM KIẾM NHỊ PHÂN - DANH SÁCH ĐẶC
int Binary_search(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int middle = (l + r) / 2;
        if (a[middle] == x) {
            return middle;
        }
        else if (a[middle] > x) {
            r = middle - 1;
        }
        else {
            l = middle + 1;
        }
    }
    return -1;
}
void output(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}
// THUẬT TOÁN SẮP XẾP: INSERTION SORT
void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int pos = i - 1;
        while (pos >= 0 && a[pos] > temp) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = temp;
    }
}
//THUAT TOAN SAP XEP: INTERCHANGE SORT
void InterchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; i < n; j++) {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
//THUAT TOAN SAP XEP: BUBBLE SORT
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}
//THUAT TOAN SAP XEP: QUICK SORT
void QuickSort(int a[], int left, int right) {
    int pivot = a[(left+right)/2];
    int l = left;
    int r = right;
    do {
        while (a[l] < pivot) {
            l++;
        }
        while (a[r] > pivot) {
            r--;
        }
        if (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    } while (l <= r);

    if (r > left) {
        QuickSort(a, left, r);
    }
    if (l < right) {
        QuickSort(a, l, right);
    }
}
//THUAT TOAN SAP XEP: MERGE SORT
// THUẬT TOÁN SẮP XẾP 2 DÃY CÓ THỨ TỰ THÀNH 1 DÃY CÓ THỨ TỰ
int* merge(int* a, int n1, int* b, int n2) {
    int* c = (int*)malloc((n1+n2)*sizeof(int));
    int i = 0,j = 0,count = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            c[count++] = a[i++];
        }
        else {
            c[count++] = b[j++];
        }
    }
    for (int k = i; k < n1; k++) {
        c[count++] = a[k];
    }
    for (int k=j; k < n2; k++) {
        c[count++] = b[k];
    }
    return c;
}
// TÁCH DÃY ĐẦU THÀNH TỪNG PHẦN TỬ CON ĐỂ TIẾN HÀNH MERGE
int* mergeSort(int a[], int n) {
    if (n == 1)
        return a;
    int mid = n / 2;
    int* m1 = (int*)malloc(mid*sizeof(int));
    int* m2 = (int*)malloc((n-mid)*sizeof(int));
    for (int i = 0; i < mid; i++) {
        m1[i] = a[i];
    }
    for (int i = 0; i < n-mid; i++) {
        m2[i] = a[i + mid];
    }   // TÁCH ĐC 2 DẪY PHỤ M1 VS M2 LẦN ĐẦU
    // DÙNG ĐỆ QUY TIẾP TỤC TÁCH 2 DÃY CHO TỚI KHI DÃY PHỤ CON CHỈ CÓ 1 PHẦN TỬ
    m1 = mergeSort(m1, mid);
    m2 = mergeSort(m2, n - mid);
    return merge(m1, mid, m2, n - mid);
}
int main()
{
    int a[] = { 3,2,6,12,32,62,123,1,4,-50,21 };
    int n = sizeof(a) / sizeof(a[0]);
    InsertionSort(a, n);
    output(a, n);
    return 0;
}
