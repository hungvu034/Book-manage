#include"ThuVien.h"

int main(){
	while(true){
		system("cls");
	printf("%40s\n\n","Menu");
	printf("--------------------------------------------------------------------------------");
	printf("1. Enter information of n books of HUST\n\n");
	printf("2. Print the information of the entered books on the screen\n\n");
	printf("3. Sort descending information by year of publication and display\n\n");
	printf("4. Search for books by title\n\n");
	printf("5. Search books by author's name\n\n");
	printf("6. Exit\n\n");
	printf("--------------------------------------------------------------------------------");
	printf("Select a mode then press enter: ");
	int n;
	while(true){
		scanf("%d",&n);
		if(n >= 1 && n <= 6 ) break;
		else
			printf("Please.Press a number in 1 to 6: ");
	}
	system("cls");
	switch(n){
		case 1:
			Mode_1();
			break;
		case 2:
			Mode_2();
			break;
		case 3:
			Mode_3();
			break;
		case 4:
			Mode_4();
			break;
		case 5:
			Mode_5();
			break;
		case 6:
			return 0;
	}
	}
}
