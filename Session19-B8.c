#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int Id;
	char name[50];
	int age;
	char phone[30];
}SinhVien;
void InStudents(SinhVien *StundentsPtr,int size);
void printStudents(SinhVien *StundentsPtr,int size);
void inStudents(SinhVien *StudentsPtr, int size, SinhVien *newstudents,int pod);
int main() {
	int size = 5;
	SinhVien *StundentsPtr=(SinhVien *)malloc(50 * sizeof( SinhVien));
	if (StundentsPtr == NULL){
		printf("bo nho qua tai\n");
		return 1;
	}
	 InStudents(StundentsPtr, size);
	// hien 
	printStudents(StundentsPtr,size);
	
	SinhVien newstudents;
	printf("Thong tin nguoi moi\n");
	printf("Id");
	scanf("%d",&newstudents.Id);
	getchar();
	
	printf("ten:");
	fgets(newstudents.name,sizeof(newstudents.name),stdin);
	newstudents.name[strcpn(newstudents.name,"\n")]='\0';
	
	
	printf("Thong tin nguoi moi\n");
	printf("Tuoi");
	scanf("%d",&newstudents.age);
	getchar();
	
	printf("SDT:");
	fgets(newstudents.phone,sizeof(newstudents.phone),stdin);
	newstudents.phone[strcmp(newstudents.phone,"\n")]='\0';
	
	int pod = rand() % (size +1);
	printf("chen sinh vien vao vi tri %d ",pod);
    return 0;
}
void InStudents(SinhVien *StundentsPtr,int size){
	StundentsPtr[0].Id=1;
	strcpy(StundentsPtr[0].name,"nnn");
	StundentsPtr[0].age=15;
	strcpy(StundentsPtr[0].phone,"03481379");
	
	StundentsPtr[1].Id=2;
	strcpy(StundentsPtr[1].name,"mmm");
	StundentsPtr[1].age=13;
	strcpy(StundentsPtr[1].phone,"7893389");
	
	StundentsPtr[2].Id=3;
	strcpy(StundentsPtr[2].name,"bbb");
	StundentsPtr[2].age=152;
	strcpy(StundentsPtr[2].phone,"543581379");
	
	StundentsPtr[3].Id=4;
	strcpy(StundentsPtr[3].name,"fff");
	StundentsPtr[3].age=17;
	strcpy(StundentsPtr[3].phone,"243545225325");
	
	StundentsPtr[4].Id=5;
	strcpy(StundentsPtr[4].name,"ggg");
	StundentsPtr[4].age=55;
	strcpy(StundentsPtr[4].phone,"043481379");
};
void printStudents(SinhVien *StundentsPtr,int size){
	for(int i = 0 ; i<size;i++){
		printf("Id: %d , ten: %s , tuoi: %d , sdt: %s \n",
		StundentsPtr[i].Id,
		StundentsPtr[i].name,
		StundentsPtr[i].age,
		StundentsPtr[i].phone);
	}
	printf("\n");
}
void inStudents(SinhVien *StudentsPtr, int size, SinhVien *newstudents,int pod){
	*size += 1;
	
	for(int i =*size -1;i>pod;i--){
		StundentsPtr[i]=StundentsPtr[i-1];
	}
	StundentsPtr[i]=newstudents;
}
