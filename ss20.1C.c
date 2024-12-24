#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char nameBook[100];
    char author[100];
    float price;
    char type[50];
};

void nhapThongTinSach(struct Book books[], int *number);
void hienThiSach(struct Book books[], int number);
void themSachVaoIndex(struct Book books[], int *number);
void xoaSachTheoId(struct Book books[], int *number);
void capNhatSachTheoId(struct Book books[], int number);
void sapXepSachTheoGia(struct Book books[], int number, int tangDan);
void timKiemSachTheoTen(struct Book books[], int number);

int main() {
    struct Book books[100];
    int number = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao index\n");
        printf("4. Xoa sach theo ID\n");
        printf("5. Cap nhat sach theo ID\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSach(books, &number);
                break;
            case 2:
                hienThiSach(books, number);
                break;
            case 3:
                themSachVaoIndex(books, &number);
                break;
            case 4:
                xoaSachTheoId(books, &number);
                break;
            case 5:
                capNhatSachTheoId(books, number);
                break;
            case 6:
                {
                    int tangDan;
                    printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
                    scanf("%d", &tangDan);
                    sapXepSachTheoGia(books, number, tangDan);
                }
                break;
            case 7:
                timKiemSachTheoTen(books, number);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 8);

    return 0;
}

void nhapThongTinSach(struct Book books[], int *number) {
    printf("Nhap so luong sach: ");
    scanf("%d", number);
    for (int i = 0; i < *number; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &books[i].id);
        getchar();
        printf("Ten sach: ");
        fgets(books[i].nameBook, 100, stdin);
        books[i].nameBook[strcspn(books[i].nameBook, "\n")] = 0;
        printf("Tac gia: ");
        fgets(books[i].author, 100, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;
        printf("Gia: ");
        scanf("%f", &books[i].price);
        getchar();
        printf("The loai: ");
        fgets(books[i].type, 50, stdin);
        books[i].type[strcspn(books[i].type, "\n")] = 0;
    }
}

void hienThiSach(struct Book books[], int number) {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < number; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Ten sach: %s\n", books[i].nameBook);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
        printf("The loai: %s\n\n", books[i].type);
    }
}

void themSachVaoIndex(struct Book books[], int *number) {
    int index;
    printf("Nhap index muon them (0-based index): ");
    scanf("%d", &index);

    if (index < 0 || index > *number) {
        printf("Index khong hop le.\n");
        return;
    }

    for (int i = *number; i > index; i--) {
        books[i] = books[i - 1];
    }

    printf("Nhap thong tin sach moi:\n");
    printf("ID: ");
    scanf("%d", &books[index].id);
    getchar();
    printf("Ten sach: ");
    fgets(books[index].nameBook, 100, stdin);
    books[index].nameBook[strcspn(books[index].nameBook, "\n")] = 0;
    printf("Tac gia: ");
    fgets(books[index].author, 100, stdin);
    books[index].author[strcspn(books[index].author, "\n")] = 0;
    printf("Gia: ");
    scanf("%f", &books[index].price);
    getchar();
    printf("The loai: ");
    fgets(books[index].type, 50, stdin);
    books[index].type[strcspn(books[index].type, "\n")] = 0;

    (*number)++;
}

void xoaSachTheoId(struct Book books[], int *number) {
    int id;
    printf("Nhap ID sach can xoa: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < *number; i++) {
        if (books[i].id == id) {
            for (int j = i; j < *number - 1; j++) {
                books[j] = books[j + 1];
            }
            (*number)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Xoa thanh cong.\n");
    } else {
        printf("Khong tim thay sach co ID nay.\n");
    }
}

void capNhatSachTheoId(struct Book books[], int number) {
    int id;
    printf("Nhap ID sach can cap nhat: ");
    scanf("%d", &id);

    for (int i = 0; i < number; i++) {
        if (books[i].id == id) {
            printf("Nhap thong tin moi cho sach:\n");
            getchar();
            printf("Ten sach: ");
            fgets(books[i].nameBook, 100, stdin);
            books[i].nameBook[strcspn(books[i].nameBook, "\n")] = 0;
            printf("Tac gia: ");
            fgets(books[i].author, 100, stdin);
            books[i].author[strcspn(books[i].author, "\n")] = 0;
            printf("Gia: ");
            scanf("%f", &books[i].price);
            getchar();
            printf("The loai: ");
            fgets(books[i].type, 50, stdin);
            books[i].type[strcspn(books[i].type, "\n")] = 0;
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sach co ID nay.\n");
}

void sapXepSachTheoGia(struct Book books[], int number, int tangDan) {
    for (int i = 0; i < number - 1; i++) {
        for (int j = i + 1; j < number; j++) {
            if ((tangDan && books[i].price > books[j].price) || 
                (!tangDan && books[i].price < books[j].price)) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n");
}

void timKiemSachTheoTen(struct Book books[], int number) {
    char nameBook[100];
    getchar();
    printf("Nhap ten sach can tim: ");
    fgets(nameBook, 100, stdin);
    nameBook[strcspn(nameBook, "\n")] = 0;

    printf("Ket qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < number; i++) {
        if (strstr(books[i].nameBook, nameBook) != NULL) {
            printf("ID: %d\n", books[i].id);
            printf("Ten sach: %s\n", books[i].nameBook);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia: %.2f\n", books[i].price);
            printf("The loai: %s\n\n", books[i].type);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach nao phu hop.\n");
    }
}
