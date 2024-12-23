#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phone[20];
} Students;

void Strudents(int lengthsize, Students *Studentsptr);
void InStudents(int lengthsize, Students *Studentsptr);
int deleteStudentByName(Students *Studentsptr, int *lengthsize, const char *studentName);

int main() {
    int lengthsize = 5;
    Students *Studentsptr = (Students *)malloc(50 * sizeof(Students));
    if (Studentsptr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }


    Strudents(lengthsize, Studentsptr);


    InStudents(lengthsize, Studentsptr);


    char studentName[50];
    printf("Moi ban nhap ten muon tim kiem: ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0'; 

    if (deleteStudentByName(Studentsptr, &lengthsize, studentName)) {
        printf("xoa ten  sv: %s\n", studentName);
    } else {
        printf("khong tim thay sinh vien: %s\n", studentName);
    }


    InStudents(lengthsize, Studentsptr);


    free(Studentsptr);
    return 0;
}


void Strudents(int lengthsize, Students *Studentsptr) {
    Studentsptr[0].id = 1;
    strcpy(Studentsptr[0].name, "Nguyen N");
    Studentsptr[0].age = 18;
    strcpy(Studentsptr[0].phone, "8493575784");

    Studentsptr[1].id = 2;
    strcpy(Studentsptr[1].name, "Cui DS");
    Studentsptr[1].age = 18;
    strcpy(Studentsptr[1].phone, "23113213");

    Studentsptr[2].id = 3;
    strcpy(Studentsptr[2].name, "Agergb");
    Studentsptr[2].age = 18;
    strcpy(Studentsptr[2].phone, "54525225");

    Studentsptr[3].id = 4;
    strcpy(Studentsptr[3].name, "Nguyen");
    Studentsptr[3].age = 1;
    strcpy(Studentsptr[3].phone, "8493575784");

    Studentsptr[4].id = 5;
    strcpy(Studentsptr[4].name, "Fdfaffs");
    Studentsptr[4].age = 184;
    strcpy(Studentsptr[4].phone, "2343435325");
}


void InStudents(int lengthsize, Students *Studentsptr) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < lengthsize; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SdT: %s\n",
               Studentsptr[i].age,
               Studentsptr[i].name,
               Studentsptr[i].age,
               Studentsptr[i].phone);
    }
    printf("\n");
}


int deleteStudentByName(Students *Studentsptr, int *lengthsize, const char *studentName) {
    for (int i = 0; i < *lengthsize; i++) {
        if (strcmp(Studentsptr[i].name, studentName) == 0) {
    
            for (int j = i; j < *lengthsize - 1; j++) {
                Studentsptr[j] = Studentsptr[j + 1];
            }
            (*lengthsize)--; 
            return 1;        
        }
    }
    return 0; 
}

