#include"ThuVien.h"
void NhapSachFile(ThuVien * Tv){
	FILE * File_IO = fopen("HUST.txt","r");
	fscanf(File_IO ,"%d\n",&Tv->n);
	Tv->DanhSach = (Book *)malloc((Tv->n) * sizeof(Book));
	for(int i = 0 ; i < Tv->n ; i ++ ){
		fgets(Tv->DanhSach[i].Ten_sach , 30 , File_IO);
		Tv->DanhSach[i].Ten_sach[strlen(Tv->DanhSach[i].Ten_sach) - 1] = '\0';
		fgets(Tv->DanhSach[i].Ten_tac_gia , 30 , File_IO);
		Tv->DanhSach[i].Ten_tac_gia[strlen(Tv->DanhSach[i].Ten_tac_gia) - 1] = '\0';
		fgets(Tv->DanhSach[i].Nha_xuat_ban , 30 , File_IO);
		Tv->DanhSach[i].Nha_xuat_ban[strlen(Tv->DanhSach[i].Nha_xuat_ban) - 1] = '\0';
		fscanf(File_IO, "%d\n",&Tv->DanhSach[i].Nam_XB);
		fscanf(File_IO , "%lf\n",&Tv->DanhSach[i].Gia_ban);
	}
	fclose(File_IO);
}

void XuatSachFile(ThuVien Tv){
	for(int i = 0 ; i < Tv.n ; i++){
		printf("Quyen thu %d\n",i+1);
		printf("Ten sach: %s\nTen Tac Gia: %s\nNha Xuat Ban: %s\nNam Xuat Ban: %d\nGia ban: %lf\n\n",Tv.DanhSach[i].Ten_sach , Tv.DanhSach[i].Ten_tac_gia , Tv.DanhSach[i].Nha_xuat_ban , Tv.DanhSach[i].Nam_XB , Tv.DanhSach[i].Gia_ban);
	}
}

void NhapSachTuBanPhim(){
	ThuVien * Tv;
	Tv = (ThuVien *)malloc(sizeof(ThuVien));
	FILE * GPIO  = fopen("HUST.txt","r");
	ThuVien Temp;
	fscanf(GPIO,"%d\n",&Temp.n);
	if(feof(GPIO))	
		Temp.n = 0;
	
	Temp.DanhSach = (Book *)malloc(Temp.n * sizeof(Book));
	for(int i = 0 ; i < Temp.n ; i ++){
		fgets(Temp.DanhSach[i].Ten_sach , 30 , GPIO);
		Temp.DanhSach[i].Ten_sach[strlen(Temp.DanhSach[i].Ten_sach) - 1 ] = '\0';
		fgets(Temp.DanhSach[i].Ten_tac_gia, 30 , GPIO);
		Temp.DanhSach[i].Ten_tac_gia[strlen(Temp.DanhSach[i].Ten_tac_gia) - 1 ] = '\0';
		fgets(Temp.DanhSach[i].Nha_xuat_ban, 30 , GPIO);
		Temp.DanhSach[i].Nha_xuat_ban[strlen(Temp.DanhSach[i].Nha_xuat_ban) - 1 ] = '\0';
		fscanf(GPIO,"%d\n",&Temp.DanhSach[i].Nam_XB);
		fscanf(GPIO,"%lf\n",&Temp.DanhSach[i].Gia_ban);
	}
	fclose(GPIO);
	printf("-------------------------------------------\n");
	printf("Nhap Vao So Luong Sach Muon Them   ");
	scanf("%d",&Tv->n);
	
	fflush(stdin);
	GPIO = fopen("HUST.txt","w");
	fprintf(GPIO,"%d\n",Temp.n + Tv->n);
	

	for(int i = 0 ; i < Temp.n ; i ++ ){
		fprintf(GPIO,"%s\n",Temp.DanhSach[i].Ten_sach);
		fprintf(GPIO,"%s\n",Temp.DanhSach[i].Ten_tac_gia);
		fprintf(GPIO,"%s\n",Temp.DanhSach[i].Nha_xuat_ban);
		fprintf(GPIO,"%d\n",Temp.DanhSach[i].Nam_XB);
		fprintf(GPIO,"%lf\n",Temp.DanhSach[i].Gia_ban);
	}
	fclose(GPIO);
	GPIO = fopen("HUST.txt","a");
	Tv->DanhSach = (Book *)malloc(Tv->n * sizeof(Book));
	for(int i = 0 ; i < Tv->n ; i ++ ){
		printf("Quyen Thu %d ",i+1);
		printf("Ten Sach: ");
		fflush(stdin);
		gets(Tv->DanhSach[i].Ten_sach);
		fprintf(GPIO,"%s\n",Tv->DanhSach[i].Ten_sach);
		printf("Ten Tac Gia: ");
		gets(Tv->DanhSach[i].Ten_tac_gia);
		fprintf(GPIO,"%s\n",Tv->DanhSach[i].Ten_tac_gia);
		printf("Nha Xuat Ban: ");
		gets(Tv->DanhSach[i].Nha_xuat_ban);
		fprintf(GPIO,"%s\n",Tv->DanhSach[i].Nha_xuat_ban);
		printf("Nam Xuat Ban: ");
		scanf("%d",&Tv->DanhSach[i].Nam_XB);
		fprintf(GPIO,"%d\n",Tv->DanhSach[i].Nam_XB);
		printf("Gia Tien: ");
		scanf("%lf",&Tv->DanhSach[i].Gia_ban);
		fprintf(GPIO,"%lf\n",Tv->DanhSach[i].Gia_ban);
	}
	fclose(GPIO);
}

void Sort_NXB(ThuVien Tv){
	for(int i = 0 ; i < Tv.n - 1 ; i ++ ){
		for(int j = i + 1 ; j < Tv.n ; j ++ ){
			if(Tv.DanhSach[i].Nam_XB > Tv.DanhSach[j].Nam_XB){
				Book temp = Tv.DanhSach[i];
				Tv.DanhSach[i] = Tv.DanhSach[j];
				Tv.DanhSach[j] = temp;
			}
		}
	}
}

ThuVien TimKiem_TacGia(ThuVien Tv , char* Name){
	ThuVien ds;
	ds.DanhSach = (Book *)malloc(100 * sizeof(Book));
	ds.n = 0;
	for(int i = 0 ; i < Tv.n ; i ++ ){
		if(stricmp(Tv.DanhSach[i].Ten_tac_gia , Name) == 0)
			ds.DanhSach[ds.n ++] = Tv.DanhSach[i];
	}
	return ds;
}

Book *TimKiem_Ten(ThuVien Tv, char * Name){
	for(int i = 0 ; i < Tv.n ; i ++ ){
		if(stricmp(Tv.DanhSach[i].Ten_sach,Name) == 0 )
			return &Tv.DanhSach[i];
	}
	return NULL;
}

void Mode_1(){
	NhapSachTuBanPhim();
	printf("Them sach thanh cong !\n ");
	printf("Bam 0 de thoat , Bam so bat ki de tro ve menu: ");
	int n;
	scanf("%d",&n);
	if(n == 0)
		exit(0);
}
void Mode_2(){
	ThuVien Tv;
	NhapSachFile(&Tv);
	printf("Thu vien cua ban gom nhung cuon sach sau , Bam 0 de thoat , Bam so bat ki de tro ve menu\n ");
	XuatSachFile(Tv);
	int n;
	scanf("%d",&n);
	if(n == 0)
		exit(0);
}
void Mode_3(){
	ThuVien Tv;
	printf("Thu vien sau khi sap xep: \n");
	NhapSachFile(&Tv);
	Sort_NXB(Tv);
	XuatSachFile(Tv);
	printf("Bam 0 de thoat , Bam so bat ki de tro ve menu: ");
	int n;
	scanf("%d",&n);
	if(n == 0)
		exit(0);

}
void Mode_4(){
	ThuVien Tv;
	NhapSachFile(&Tv);
	printf("Nhap Ten Sach Muon Tim: ");
	char str[30];
	fflush(stdin);
	gets(str);
	Book* Temp = TimKiem_Ten(Tv,str);
	if(Temp == NULL)
		printf("Khong Tim Thay Sach");
	else
	{
		printf("Tim Thay Sach\n");
		printf("Ten sach: %s\nTen tac gia: %s\nNha xuat ban: %s\nNam xuat ban: %d\nGia ca: %lf\n",Temp->Ten_sach , Temp->Ten_tac_gia , Temp->Nha_xuat_ban , Temp->Nam_XB , Temp->Gia_ban);

	}
		printf("Bam 0 de thoat , Bam so bat ki de tro ve menu: ");
	int n;
	scanf("%d",&n);
	if(n == 0)
		exit(0);
}
void Mode_5(){
	ThuVien Tv;
	NhapSachFile(&Tv);
	printf("Nhap Vao Ten Tac Gia: ");
	char p[30];
	fflush(stdin);
	gets(p);
	ThuVien temp = TimKiem_TacGia(Tv,p);
	if(temp.n == 0){
		printf("Khong Tim Thay Tac Gia\n");
	} 
	else{
	printf("%s la tac gia cua nhung sach sau:\n",p);
	for(int i = 0 ; i < temp.n ; i ++ ){
		printf("Quyen thu %d: \n",i+1);
		printf("Ten sach: %s\nTen tac gia: %s\nNha xuat ban: %s\nNam san xuat: %d\nGia ban: %lf\n",temp.DanhSach[i].Ten_sach,temp.DanhSach[i].Ten_tac_gia,temp.DanhSach[i].Nha_xuat_ban,temp.DanhSach[i].Nam_XB,temp.DanhSach[i].Gia_ban);
	}
}
	printf("Bam 0 de thoat , Bam so bat ki de tro ve menu: ");
	int n;
	scanf("%d",&n);
	if(n == 0)
		exit(0);
}