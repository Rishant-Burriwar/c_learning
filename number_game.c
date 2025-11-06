#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int chances =7;
void lifecount(){
  
   --chances;
   printf("lives left = %d\nTRY AGAIN\n",chances);
}
int main(){
    int input;
    char name[100];
    srand(time(0));
    int random= rand()%100+1;
    
    printf("Enter your Name\n");
    scanf("%s",name);
    getchar();
    printf("====Press Enter to Start Number Game=====\n");
    getchar();
    printf("Wait a sec....lemme choose a number between 1-100 !!\n");
    printf("All right start guessing...\n");
    scanf("%d",&input);
   
    do{

    if (input == random){ 
       printf("I chose %d and you guessed correct",random);
       break;
    }

    else if (input!=random){

        if(input>random){
            printf("\nWRONG BOY, YOUR NUMBER IS MORE\n");
            lifecount();
            scanf("%d",&input);
        }
        else if (input<random){
            printf("\nWRONG BOY, YOUR NUMBER IS LESS\n ");
            lifecount();
            scanf("%d",&input);
        }
        
    }
    
}while(chances>0);

printf("\nTHE number was %d\n", random);

}