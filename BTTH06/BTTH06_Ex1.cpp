#include <stdio.h>
#include <stdlib.h>

void inputArray(int *arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", arr + i);
    }
}

void printfArray(int *arr, int size) {
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int binarySearch(int *arr, int size, int x) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
int main() {
    int size;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 0;
    }

   inputArray(arr, size);
   printfArray(arr, size);

    int x;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &x);

    int index = binarySearch(arr, size, x);
    if (index != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d trong mang.\n", x, index);
    } else {
        printf("Phan tu %d khong duoc tim thay trong mang.\n", x);
    }

    free(arr);
    return 0;
}
