#include<stdio.h>
int main(){
  int matrix_1[3][3];
  int matrix_2[3][3];
  int addition[3][3],subtraction[3][3],multiplication[3][3];
  printf("Enter values inside the matrix\n");
  for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
        
        printf("a%d%d: ",i+1,j+1);
        scanf("%d",&matrix_1[i][j]);
    }
  }
   for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
        
        printf("b%d%d: ",i+1,j+1);
        scanf("%d",&matrix_2[i][j]);
    }
   
  }

  printf("The addition matrix,subtaction,multiplication is :-\n"); //addition
       
   for(int i=0;i<3;++i){              
    for(int j=0;j<3;++j){
      for(int k=0;k<3;++k){

  addition[i][j] = matrix_1[i][j] + matrix_2[i][j];
  
  
      }
      printf("%d\t",addition[i][j]);

    }
    if(i==0 || i==1){
    printf("\n");
  }
    
  }
   
  printf("\n");
   for(int i=0;i<3;++i){              
    for(int j=0;j<3;++j){

subtraction[i][j]= matrix_1[i][j] - matrix_2[i][j];
    printf("%d\t",subtraction[i][j]);
}
    if(i==0||i==1){
      printf("\n");
    }
}

printf("\n");
 for(int i=0;i<3;++i){              
    for(int j=0;j<3;++j){
      multiplication[i][j]=0;
      for(int k=0;k<3;++k){
      
      multiplication[i][j] += matrix_1[i][k]*matrix_2[k][j];
       
      }
       printf("%d\t",multiplication[i][j]);
    }
    if(i==0||i==1){
      printf("\n");
    }
  }


   return 0;
}