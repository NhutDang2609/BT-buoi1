struct SACH{
	char masach[20], tacgia[30], tensach[30], nhaxuatban[100];
	int namxuatban, soluong;
	float dongia, thuctien, thanhtien, thue;
};

void nhapSach(struct SACH* qs);


int main()
{
	int n;
	
	struct SINH_VIEN tt[n];
	
	//a.	Nhap thong tin n quyen sach 
	nhapthongtin(tt, n);
	return 0;
}

void nhapSach(struct SACH* qs)
{
	printf("Nhap ma sach :");
	scanf("%s",qs->masach);
	printf("\nNhap tac gia:");
	getschar();
	fgets(qs->tacgia, sizeof(qs->tacgia), stdin);
	qs->tacgia[strcspn(qs->tacgia, "\n")] = '\0';
	printf("\nNhap ten sach: ");
	getschar();
	fgets(qs->tensach, sizeof(qs->tensach),stdin);
	qs->tensach[strcspn(qs->tensach,"\n")] ='\0';
	printf("\nNhap nha xuat ban:"); 


}
