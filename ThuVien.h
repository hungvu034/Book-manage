#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
// declare struct
struct Book{
	char Ten_sach[30];
	char  Ten_tac_gia[30];
	char  Nha_xuat_ban[30];
	int Nam_XB;
	double Gia_ban;
};
typedef struct Book Book ;
struct ThuVien{
	int n;
	Book *DanhSach;
};
// function support 
typedef ThuVien ThuVien ; 
void XuatSachFile(ThuVien );
void NhapSachFile(ThuVien *);
void NhapSachTuBanPhim();
void Enter_information(ThuVien *);
void Sort_NXB(ThuVien );
Book *TimKiem_Ten(ThuVien);
Book *TimKiem_TacGia(ThuVien);

// Mode function 

void Mode_1(); // Enter information of n books of HUST
void Mode_2(); // Print the information of the entered books on the screen
void Mode_3(); // Sort descending information by year of publication and display
void Mode_4(); // Search for books by title
void Mode_5(); // Search books by author's name
void Mode_6();  // Exit
