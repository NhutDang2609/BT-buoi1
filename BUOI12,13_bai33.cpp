#include <stdio.h>
#include <stdlib.h>

struct PHAN_SO {
    int tuSo;
    int mauSo;
};

typedef struct PHAN_SO ps;

void nhapPhanSo(PHAN_SO *ps);
void xuatPhanSo(PHAN_SO ps);
int uocchunglon(int a, int b);
void rutGonPhanSo(PHAN_SO *ps);
void ghiPhansovaoFile(PHAN_SO ps[], int n, const char *tenFile);
int docphansotuFile(PHAN_SO ps[], const char *tenFile);
void hienthiDanhSachRutGon(PHAN_SO ps[], int n);
PHAN_SO timPhanSoNhoNhat(PHAN_SO ps[], int n);
int demPhanSoNhoNhat(PHAN_SO ps[], int n, PHAN_SO min);
void SapXepGiamDan(PHAN_SO ps[], int n);

int main() {
    int n;
    PHAN_SO ps[100];
    const char *tenFile = "phan_so.txt";
    
    printf("Nhap so luong phan so (n>0): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&ps[i]);
    }
    
    ghiPhansovaoFile(ps, n, tenFile);
    int soluong = docphansotuFile(ps, tenFile);
    printf("\nDanh sach phan so sau khi doc tu file:\n");
    hienthiDanhSachRutGon(ps, soluong);
    
    PHAN_SO min = timPhanSoNhoNhat(ps, soluong);
    printf("\nPhan so nho nhat: ");
    xuatPhanSo(min);
    printf("\n");
   
    int dem = demPhanSoNhoNhat(ps, soluong, min);
    printf("\nSo luong phan so nho nhat: %d\n", dem);
    
    SapXepGiamDan(ps, soluong);
    printf("\nDanh sach phan so sau khi sap xep giam dan:\n");
    hienthiDanhSachRutGon(ps, soluong);

    return 0;
}

void xuatPhanSo(PHAN_SO ps) {
    printf("%d/%d", ps.tuSo, ps.mauSo);
}

void nhapPhanSo(PHAN_SO *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tuSo);
    do {
        printf("Nhap mau so (mau so phai khac 0): ");
        scanf("%d", &ps->mauSo);
    } while (ps->mauSo == 0);
}

int uocchunglon(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void rutGonPhanSo(PHAN_SO *ps) {
    int uocchunglon_val = uocchunglon(ps->tuSo, ps->mauSo);
    ps->tuSo /= uocchunglon_val;
    ps->mauSo /= uocchunglon_val;

    // If the denominator is negative, make both numerator and denominator negative
    if (ps->mauSo < 0) {
        ps->tuSo = -ps->tuSo;
        ps->mauSo = -ps->mauSo;
    }
}

void ghiPhansovaoFile(PHAN_SO ps[], int n, const char *tenFile) {
    FILE *file = fopen(tenFile, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %d\n", ps[i].tuSo, ps[i].mauSo);
    }
    
    fclose(file);
}

int docphansotuFile(PHAN_SO ps[], const char *tenFile) {
    FILE *file = fopen(tenFile, "r");
    if (file == NULL) {
        printf("\nKhong the mo file.\n");
        return -1;
    }

    int i = 0;
    while (fscanf(file, "%d %d", &ps[i].tuSo, &ps[i].mauSo) == 2) {
        i++;
    }
    fclose(file);
    return i;
}

void hienthiDanhSachRutGon(PHAN_SO ps[], int n) {
    for (int i = 0; i < n; i++) {
        rutGonPhanSo(&ps[i]);
        xuatPhanSo(ps[i]);
        printf("\n");
    }
}

PHAN_SO timPhanSoNhoNhat(PHAN_SO ps[], int n) {
    PHAN_SO min = ps[0];
    for (int i = 1; i < n; i++) {
        if ((double)ps[i].tuSo / ps[i].mauSo < (double)min.tuSo / min.mauSo) {
            min = ps[i];
        }
    }
    return min;
}

int demPhanSoNhoNhat(PHAN_SO ps[], int n, PHAN_SO min) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if ((double)ps[i].tuSo / ps[i].mauSo == (double)min.tuSo / min.mauSo) {
            dem++;
        }
    }
    return dem;
}

void SapXepGiamDan(PHAN_SO ps[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((double)ps[i].tuSo / ps[i].mauSo < (double)ps[j].tuSo / ps[j].mauSo) {
                PHAN_SO temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }
}

