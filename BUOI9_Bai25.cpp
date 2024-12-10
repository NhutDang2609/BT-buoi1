#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NGAY_THANG {
    int ngay, thang, nam;
};

struct MON_HOC {
    char ma_mon[10];  
    float diem;
};

struct SINH_VIEN {
    char mssv[20];      
    int somon;
    char hoten[30];
    char gioitinh[5];  
    char diachi[100]; 
    struct NGAY_THANG ngaysinh;
    struct MON_HOC* monhoc;
};

void nhap_sinh_vien(struct SINH_VIEN* sv);
void xuat_sinh_vien(struct SINH_VIEN sv);
void nhap_danh_sach_sinh_vien(struct SINH_VIEN* ds, int n);
void xuat_danh_sach_sinh_vien(struct SINH_VIEN* ds, int n);
struct SINH_VIEN* tim_sinh_vien_theo_mssv(struct SINH_VIEN* ds, int n, const char* mssv);
void tim_sinh_vien_theo_ten(struct SINH_VIEN* ds, int n, const char* ten);
void tim_sinh_vien_sinh_thang_8(struct SINH_VIEN* ds, int n);
void tim_sinh_vien_theo_gioi_tinh(struct SINH_VIEN* ds, int n, const char* gioi_tinh);
void tim_sinh_vien_theo_dia_chi(struct SINH_VIEN* ds, int n, const char* dia_chi);

int main() 
{
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct SINH_VIEN ds[n];

    // Nhap danh sach sinh vien
    nhap_danh_sach_sinh_vien(ds, n);

    // Xuat danh sach
    printf("\nDanh sach sinh vien:\n");
    xuat_danh_sach_sinh_vien(ds, n);

    // Tim sinh vien theo ma so
    char mssv[20];
    printf("\nNhap ma so sinh vien can tim: ");
    scanf("%s", mssv);
    struct SINH_VIEN* sv = tim_sinh_vien_theo_mssv(ds, n, mssv);
    if (sv != NULL) {
        printf("Sinh vien tim thay:\n");
        xuat_sinh_vien(*sv);
    } else {
        printf("Khong tim thay sinh vien co ma so %s\n", mssv);
    }

    // Tim sinh vien theo ten
    char ten[50];
    printf("\nNhap ten sinh vien can tim: ");
    getchar();  
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';  

    printf("\nDanh sach sinh vien co ten '%s':\n", ten);
    tim_sinh_vien_theo_ten(ds, n, ten);

    // Tim sinh vien sinh thang 8
    printf("\nDanh sach sinh vien sinh trong thang 8:\n");
    tim_sinh_vien_sinh_thang_8(ds, n);

    // Tim sinh vien theo gioi tinh
    char gioi_tinh[10];
    printf("\nNhap gioi tinh can tim (Nam/Nu): ");
    scanf("%s", gioi_tinh);
    printf("\nDanh sach sinh vien gioi tinh '%s':\n", gioi_tinh);
    tim_sinh_vien_theo_gioi_tinh(ds, n, gioi_tinh);

    // Tim sinh vien theo dia chi
    char dia_chi[100];
    printf("\nNhap dia chi can tim: ");
    getchar(); 
    fgets(dia_chi, sizeof(dia_chi), stdin);
    dia_chi[strcspn(dia_chi, "\n")] = '\0';  
    printf("\nDanh sach sinh vien co dia chi '%s':\n", dia_chi);
    tim_sinh_vien_theo_dia_chi(ds, n, dia_chi);

    return 0;
}

void nhap_sinh_vien(struct SINH_VIEN* sv) 
{
    printf("\nNhap ma so sinh vien: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten sinh vien: ");
    getchar();  
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = '\0';  
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);
    printf("Nhap gioi tinh: ");
    scanf("%s", sv->gioitinh);
    printf("Nhap dia chi: ");
    getchar();  
    fgets(sv->diachi, sizeof(sv->diachi), stdin);
    sv->diachi[strcspn(sv->diachi, "\n")] = '\0';  
    printf("Nhap so luong mon hoc: ");
    scanf("%d", &sv->somon);
    sv->monhoc = (struct MON_HOC*)malloc(sv->somon * sizeof(struct MON_HOC));
    
    for (int i = 0; i < sv->somon; i++) 
	{
        printf("Nhap ma mon hoc %d: ", i + 1);
        scanf("%s", sv->monhoc[i].ma_mon);
        printf("Nhap diem mon hoc %d: ", i + 1);
        scanf("%f", &sv->monhoc[i].diem);
    }
}

void xuat_sinh_vien(struct SINH_VIEN sv) 
{
    printf("MSSV: %s\n", sv.mssv);
    printf("Ho Ten: %s\n", sv.hoten);
    printf("Ngay Sinh: %02d/%02d/%d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("Gioi Tinh: %s\n", sv.gioitinh);
    printf("Dia Chi: %s\n", sv.diachi);
    printf("So Mon Hoc: %d\n", sv.somon);
    for (int i = 0; i < sv.somon; i++) 
	{
        printf("Mon Hoc %d - Ma Mon: %s, Diem: %.2f\n", i + 1, sv.monhoc[i].ma_mon, sv.monhoc[i].diem);
    }
}

void nhap_danh_sach_sinh_vien(struct SINH_VIEN* ds, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("\nNhap thong tin cho sinh vien %d:\n", i + 1);
        nhap_sinh_vien(&ds[i]);
    }
}

void xuat_danh_sach_sinh_vien(struct SINH_VIEN* ds, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        xuat_sinh_vien(ds[i]);
    }
}

struct SINH_VIEN* tim_sinh_vien_theo_mssv(struct SINH_VIEN* ds, int n, const char* mssv) 
{
    for (int i = 0; i < n; i++) 
	{
        if (strcmp(ds[i].mssv, mssv) == 0) 
		{
            return &ds[i];
        }
    }
    return NULL;
}

void tim_sinh_vien_theo_ten(struct SINH_VIEN* ds, int n, const char* ten) 
{
    for (int i = 0; i < n; i++) 
	{
        if (strstr(ds[i].hoten, ten) != NULL) 
		{
            xuat_sinh_vien(ds[i]);
        }
    }
}

void tim_sinh_vien_sinh_thang_8(struct SINH_VIEN* ds, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        if (ds[i].ngaysinh.thang == 8) 
		{
            xuat_sinh_vien(ds[i]); 
        }
    }
}

void tim_sinh_vien_theo_gioi_tinh(struct SINH_VIEN* ds, int n, const char* gioi_tinh) 
{
    for (int i = 0; i < n; i++) 
	{
        if (strcmp(ds[i].gioitinh, gioi_tinh) == 0) 
		{
            xuat_sinh_vien(ds[i]);
        }
    }
}

void tim_sinh_vien_theo_dia_chi(struct SINH_VIEN* ds, int n, const char* dia_chi) 
{
    for (int i = 0; i < n; i++) 
	{
        if (strstr(ds[i].diachi, dia_chi) != NULL) 
		{
            xuat_sinh_vien(ds[i]);
        }
    }
}

