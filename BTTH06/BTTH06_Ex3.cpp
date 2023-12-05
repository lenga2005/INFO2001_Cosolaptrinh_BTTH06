#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char author[100];
    float price;
} Book;

void displayBooks(Book* book, int n) {
    printf("\n--- Thong tin cac sach ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ten sach: %s", book[i].name);
        printf("Tac gia: %s", book[i].author);
        printf("Gia sach: %.2f\n", book[i].price);
    }
}

int main() {
    Book* book = NULL;
    int n = 0;
    int choice = 0;

    while (1) {
        printf("\n---CHUONG TRINH QUAN LI DANH SACH SACH ---\n");
        printf("1. Them sach moi\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\nThem moi 1 sach:\n");
                n++;
                book = (Book*)realloc(book, n * sizeof(Book));
                printf("Ten sach: ");
                fgets(book[n - 1].name, 100, stdin);
                printf("Tac gia: ");
                fgets(book[n - 1].author, 100, stdin);
                printf("Gia sach: ");
                scanf("%f", &book[n - 1].price);
                getchar();
                break;
            case 2:
                displayBooks(book, n);
                break;
            case 3:
                printf("Thoat chuong trinh.\n");
                free(book);
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    }

    return 0;
}
