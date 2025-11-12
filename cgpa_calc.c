#include <stdio.h>

    char name[100];
    char branch[10];
    char roll_no[10];
    int phy_1,chem_1,math_1,Ed_1;
    int phy_2,chem_2,math_2,Ed_2;
    float phy,chem,maths,Ed,x;

void student_details(){ // input details of student
   
    printf("What is your Name?\n");
    scanf(" %s" , name);
    getchar();
    printf("What is Your Roll No.?\n");
    scanf(" %s", roll_no);
    getchar();
    printf("Whats your branch?\n");
    scanf(" %s", branch);
    getchar();
}

void marks_1(){  //first sem marks 
    
    printf("Enter marks for the following subjects for sem 1\n");
    printf("Physics 1 : ");
     scanf("%d", &phy_1);
    printf("Chemistry 1 : ");
     scanf("%d", &chem_1);
    printf("Mathematics 1 : ");
     scanf("%d", &math_1);
    printf("Engineering drawing 1 : ");
     scanf("%d", &Ed_1);

}

void marks_2(){  //second sem marks 
    
    printf("Enter marks for the following subjects for sem 2\n");
    printf("Physics 2 : ");
     scanf("%d", &phy_2);
    printf("Chemistry 2 : ");
     scanf("%d", &chem_2);
    printf("Mathematics 2 : ");
     scanf("%d", &math_2);
    printf("Engineering drawing 2 : ");
     scanf("%d", &Ed_2);

} 

void avg(){
    phy = phy_1 + phy_2;
    phy = phy/2;

    chem = chem_1 + chem_2;
    chem = chem/2;

    maths = math_1 + math_2;
    maths = maths/2;

    Ed = Ed_1 + Ed_2;
    Ed = Ed/2;

}

 void report(){

    printf("\n\nName : %s\n", name);
    printf("Roll No : %s\n", roll_no);
    printf("Branch : %s\n", branch);
    printf("\n");
    printf("Maths : %.2f\n", maths);
    printf("Chemistry : %.2f\n", chem);
    printf("Engineering drawing : %.2f\n", Ed);
    printf("Physics : %.2f\n", phy);
    printf("\n");
    
 }

 void cgpa(){

    x = maths/10*4+phy/10*4+chem/10*4+Ed/10*4;
    x= x/16;
    printf("\nYour CGPA IS %.1f\n", x);
    
    
    
 }
int main() {

    printf("TO CHECK YOUR REPORT CARD FILL THE BELOW DEATILS\n");
    student_details();
    marks_1();
    marks_2();
    avg();
    report();
    cgpa();


   return 0;
}