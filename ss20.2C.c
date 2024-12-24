#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[100];
    float importPrice;
    float sellPrice;
    int quantity;
};

void nhapThongTinSanPham(struct Product products[], int *number, float *revenue);
void hienThiSanPham(struct Product products[], int number);
void nhapSanPham(struct Product products[], int *number, float *revenue);
void capNhatSanPham(struct Product products[], int number);
void sapXepSanPhamTheoGia(struct Product products[], int number, int tangDan);
void timKiemSanPham(struct Product products[], int number);
void banSanPham(struct Product products[], int *number, float *revenue);
void hienThiDoanhThu(float revenue);

int main() {
    struct Product products[100];
    int number = 0;
    float revenue = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/giam)\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSanPham(products, &number, &revenue);
                break;
            case 2:
                hienThiSanPham(products, number);
                break;
            case 3:
                nhapSanPham(products, &number, &revenue);
                break;
            case 4:
                capNhatSanPham(products, number);
                break;
            case 5: {
                int tangDan;
                printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
                scanf("%d", &tangDan);
                sapXepSanPhamTheoGia(products, number, tangDan);
                break;
            }
            case 6:
                timKiemSanPham(products, number);
                break;
            case 7:
                banSanPham(products, &number, &revenue);
                break;
            case 8:
                hienThiDoanhThu(revenue);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 9);

    return 0;
}

void nhapThongTinSanPham(struct Product products[], int *number, float *revenue) {
    printf("Nhap so luong san pham: ");
    scanf("%d", number);
    for (int i = 0; i < *number; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &products[i].id);
        getchar();
        printf("Ten san pham: ");
        fgets(products[i].name, 100, stdin);
        products[i].name[strcspn(products[i].name, "\n")] = 0;
        printf("Gia nhap: ");
        scanf("%f", &products[i].importPrice);
        printf("Gia ban: ");
        scanf("%f", &products[i].sellPrice);
        printf("So luong: ");
        scanf("%d", &products[i].quantity);

        *revenue -= products[i].importPrice * products[i].quantity;
    }
}

void hienThiSanPham(struct Product products[], int number) {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < number; i++) {
        printf("ID: %d\n", products[i].id);
        printf("Ten san pham: %s\n", products[i].name);
        printf("Gia nhap: %.2f\n", products[i].importPrice);
        printf("Gia ban: %.2f\n", products[i].sellPrice);
        printf("So luong: %d\n\n", products[i].quantity);
    }
}

void nhapSanPham(struct Product products[], int *number, float *revenue) {
    int id, quantity;
    printf("Nhap ID san pham: ");
    scanf("%d", &id);
    printf("Nhap so luong: ");
    scanf("%d", &quantity);

    for (int i = 0; i < *number; i++) {
        if (products[i].id == id) {
            products[i].quantity += quantity;
            *revenue -= products[i].importPrice * quantity;
            printf("Them so luong thanh cong.\n");
            return;
        }
    }

    printf("San pham moi, nhap thong tin:\n");
    products[*number].id = id;
    getchar();
    printf("Ten san pham: ");
    fgets(products[*number].name, 100, stdin);
    products[*number].name[strcspn(products[*number].name, "\n")] = 0;
    printf("Gia nhap: ");
    scanf("%f", &products[*number].importPrice);
    printf("Gia ban: ");
    scanf("%f", &products[*number].sellPrice);
    products[*number].quantity = quantity;

    *revenue -= products[*number].importPrice * quantity;
    (*number)++;
}

void capNhatSanPham(struct Product products[], int number) {
    int id;
    printf("Nhap ID san pham can cap nhat: ");
    scanf("%d", &id);

    for (int i = 0; i < number; i++) {
        if (products[i].id == id) {
            printf("Nhap thong tin moi:\n");
            getchar();
            printf("Ten san pham: ");
            fgets(products[i].name, 100, stdin);
            products[i].name[strcspn(products[i].name, "\n")] = 0;
            printf("Gia nhap: ");
            scanf("%f", &products[i].importPrice);
            printf("Gia ban: ");
            scanf("%f", &products[i].sellPrice);
            printf("So luong: ");
            scanf("%d", &products[i].quantity);
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay san pham co ID nay.\n");
}

void sapXepSanPhamTheoGia(struct Product products[], int number, int tangDan) {
    for (int i = 0; i < number - 1; i++) {
        for (int j = i + 1; j < number; j++) {
            if ((tangDan && products[i].sellPrice > products[j].sellPrice) ||
                (!tangDan && products[i].sellPrice < products[j].sellPrice)) {
                struct Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n");
}

void timKiemSanPham(struct Product products[], int number) {
    char name[100];
    getchar();
    printf("Nhap ten san pham can tim: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Ket qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < number; i++) {
        if (strstr(products[i].name, name) != NULL) {
            printf("ID: %d\n", products[i].id);
            printf("Ten san pham: %s\n", products[i].name);
            printf("Gia nhap: %.2f\n", products[i].importPrice);
            printf("Gia ban: %.2f\n", products[i].sellPrice);
            printf("So luong: %d\n\n", products[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay san pham.\n");
    }
}

void banSanPham(struct Product products[], int *number, float *revenue) {
    int id, quantity;
    printf("Nhap ID san pham: ");
    scanf("%d", &id);
    printf("Nhap so luong muon ban: ");
    scanf("%d", &quantity);

    for (int i = 0; i < *number; i++) {
        if (products[i].id == id) {
            if (products[i].quantity == 0) {
                printf("Het hang.\n");
                return;
            }
            if (products[i].quantity < quantity) {
                printf("Khong con du hang.\n");
                return;
            }

            products[i].quantity -= quantity;
            *revenue += products[i].sellPrice * quantity;
            printf("Ban thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay san pham co ID nay.\n");
}

void hienThiDoanhThu(float revenue) {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}

