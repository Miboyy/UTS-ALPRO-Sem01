#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    float price;
    int stock;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int num_products;
};

void clearInputBuffer() {
    while (getchar() != '\n');
}

void addOrUpdateProduct(struct Inventory *inventory, int index) {
    if (index < 0 || index >= MAX_PRODUCTS || inventory->num_products >= MAX_PRODUCTS) {
        printf("Operasi tidak valid.\n");
        return;
    }

    struct Product *product = &inventory->products[index];

    printf("Masukkan nama barang baru: ");
    fgets(product->name, sizeof(product->name), stdin);
    product->name[strcspn(product->name, "\n")] = '\0';

    printf("Masukkan harga barang baru: ");
    scanf("%f", &product->price);
    clearInputBuffer();

    printf("Masukkan stok barang baru: ");
    scanf("%d", &product->stock);
    clearInputBuffer();

    if (index == inventory->num_products) {
        inventory->num_products++;
        printf("Produk berhasil ditambahkan ke inventaris.\n");
    } else {
        printf("Data produk berhasil diubah.\n");
    }
}

void deleteProduct(struct Inventory *inventory, int index) {
    if (index < 0 || index >= inventory->num_products) {
        printf("Operasi tidak valid.\n");
        return;
    }

    for (int i = index; i < inventory->num_products - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    inventory->num_products--;

    printf("Produk berhasil dihapus dari inventaris.\n");
}

void displayInventory(struct Inventory inventory) {
    printf("Daftar Produk:\n");
    printf("============================================\n");
    printf(" %-4s | %-20s | %-10s | %-5s\n", "No", "Nama Produk", "Harga", "Stok");
    printf("============================================\n");

    for (int i = 0; i < inventory.num_products; i++) {
        printf(" %-4d | %-20s | %-10.2f | %-5d\n", i + 1, inventory.products[i].name, inventory.products[i].price, inventory.products[i].stock);
    }
}

int main() {
    struct Inventory inventory = {{}, 0};
    int choice, index;

    do {
        printf("\nAplikasi Manajemen Inventaris Toko\n");
        printf("1. Masukkan/Edit Data Barang\n");
        printf("2. Hapus Data Barang\n");
        printf("3. Tampilkan Data\n");
        printf("0. Keluar\n");
        printf("Pilih perintah: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Pilih nomor produk (0 untuk menambahkan baru): ");
                scanf("%d", &index);
                clearInputBuffer();
                addOrUpdateProduct(&inventory, index - 1);
                break;
            case 2:
                printf("Pilih nomor produk yang akan dihapus: ");
                scanf("%d", &index);
                clearInputBuffer();
                deleteProduct(&inventory, index - 1);
                break;
            case 3:
                displayInventory(inventory);
                break;
            case 0:
                printf("Terimakasih telah menggunakan.\n");
                break;
            default:
                printf("Perintah tidak valid. Silakan coba lagi.\n");
        }

    } while (choice != 0);

    return 0;
}
