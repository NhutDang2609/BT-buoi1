struct NGAY_THANG
{
	int ngay, thang, nam;
};
typedef NGAY_THANG NGAY;

struct SAN_PHAM
{
	char ma[10], ten[10];
	float dongia;
	NGAY_THANG ngaysx;
};
typedef SAN_PHAM SP;

void nhapSP(SP *a);
void xuatSP(SP *a);

int main ()
{
	//Khai bao bien
	int n;
	char k[10];
	SP *a;
	 
	printf("\nMoi nhap so luong san pham: ");
	sacnf("%d",&n);
	a=(SP*) malloc(n* sizeof(SP));
	
	
	return 0;
}


void nhapSP(SP *a)
{
	printf("\nNhap ma san pham:");
	fflush(stdin);
	scanf("%s",a->ma)
	
	printf("\nNhap ten san pham: ");
	fflush(stdin);
	gets(a->ten);
	
	printf("\nNhap don gia cua san pham:");
	scanf("%f",&a->dongia);
	
	printf("\nNhap ngay san xuat: ");
	nhapNGAY (&a->ngaysx);
}

void xuatSP(SP *a)
{
	printf("\n%s\t%s\t%.1f")
}
