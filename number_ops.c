#include <stdio.h>
int main() {

printf("\n ===Welcome to number Operations===\n");
int outer_input, inner_input;
do{

  //main menu
  printf("(1) Show numbers upto a chosen number\n");
  printf("(2) Sum numbers upto a chosen number\n");
  printf("(3) Show even numbers upto a number\n");
  printf("(4) Show odd numbers upto a number\n");
  printf("(5) Factorial of a chosen number\n");
  printf("(6) Multiplication table of a chosen number\n");
  printf("(7) Exit\n");

  printf("\nChoose an option\n");
  scanf("%d", &outer_input);
  while (getchar() != '\n');


  //case 1
  if(outer_input==1){             

    printf("Choose a number\n");
    scanf("%d", &inner_input);
    while (getchar() != '\n');
    for(int i=1;i<=inner_input;++i){

      printf("%d\n",i);
    }
  }
  

  //case 2
  else if (outer_input == 2){
    int sum =0;
    printf("Choose a number\n");
    scanf("%d", &inner_input);
    while (getchar() != '\n');
    for(int i=1 ;i<=inner_input;++i){

      sum += i;
    }

    printf("Sum = %d\n", sum);

  }

  //case 3
    else if (outer_input == 3){

    printf("Choose a number\n");
    scanf("%d", &inner_input);
    while (getchar() != '\n');
    for(int i=0;i<=inner_input;i+=2){

      printf("%d\n", i);
    }

  }
  //case 4

   else if (outer_input == 4){

    printf("Choose a number\n");
    scanf("%d", &inner_input);
    while (getchar() != '\n');
    for(int i=1;i<=inner_input;i+=2){

      printf("%d\n", i);
    }

    }
    //case 5
    else if(outer_input == 5){

    printf("Choose a number\n");
    scanf("%d", &inner_input);
    while (getchar() != '\n');

    int product = 1;
    for(int i=1;i<=inner_input;++i){
        product = product*i;
      }

       printf("Factorial of %d is %d\n",inner_input,product); 
    
  }

    //case 6
     else if(outer_input == 6){

    printf("Choose a number\n");
    scanf("%d", &inner_input);
    while (getchar() != '\n');

    for(int i= 1;i<=10;++i){

      printf("%d X %d = %d\n",inner_input,i,inner_input*i);
    }
  }
   
}while(outer_input < 7 );

}