#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int code[100];
    int find;
    int present[60];
    int i =0,low=0,high=32,mid,flag=0,option,r=0;
    char ch;

    FILE* ptr_file = fopen("Student.txt","r");
    FILE* ptr = fopen("Attendence.txt","w");

    if(ptr == NULL || ptr_file == NULL){
        printf("Error in accessing file");
        return 0;
    }
    
    while (fscanf(ptr_file, "%d", &code[i]) == 1) {
        present[i] = 0;   // everyone starts as ABSENT
        i++;
    }
   
   do{

    printf("1.Enter code for attendence\n");
    printf("2.Check attendence list\n");
    printf("3.Exit\n\n");
    
    scanf("%d",&option);
    getchar();  // <-- removes newline from buffer
    printf("\n");

    if(option <1 || option>3){
        printf("PLEASE ENTER VALID OPTION\n");
        return 0;
    }

    if(option ==1){
        
        do{
        flag=0;
         printf("Enter your unique code\n");
         scanf("%d",&find);
         getchar();
        
        low=0,high=i-1;
        while(low<=high){
       mid =(low+high)/2;

       if(code[mid]==find){
          if(present[mid] ==1){
            printf("Already marked present\n");
            flag =1;
            break;
          }
          else{
               present[mid] = 1;
               flag =1;
               fprintf(ptr, "%d  %d\n",code[mid],present[mid]);
               ++r;
               break;
          }
        
       }
       else if(code[mid]>find){      // checking the uniques code
        high = mid-1;
       }
       else {
        low = mid+1;
       }
      
    }

    if(flag==0){

        printf("\nInvalid code entered\n\n");
        
    }


    printf("press E to exit and C to continue\n");
    scanf(" %c",&ch);
    ch = tolower(ch);

}while(ch=='c');

    }

    if(option ==2){

      printf("PRESENT STUDENTS: \n\n");
      for(int k=0;k<i;++k){
        if(present[k]==1){
            printf("%d\n",code[k]);
        }
      }
      printf("\n\nABSENT STUDENTS: \n\n");
      for(int k=0;k<i;++k){
        if(present[k]==0){
            printf("%d\n",code[k]);
        }
      }

      printf("\nTotal Students : %d\n",i);
      printf("No of students present : %d\n",r);
      printf("No of students absent : %d\n\n",i-r);

    }

    
}while(option != 3);
  
    fclose(ptr_file);
    fclose(ptr);
    return 0;
}






