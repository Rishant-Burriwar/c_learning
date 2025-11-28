#include<stdio.h>
FILE*ptr ;
float tot_income=0,tot_expense=0;
float food_exp=0.0,entert_exp=0.0,edu_exp=0.0;

typedef struct income{
    float salary,bonus,savings;
}income;

income i ={0,0,0};

typedef struct expense{
    float food,entertainment,education;
}expense;

expense e ={0,0,0};


int add_income(){
    int n;
   
    printf("Enter your Income\n");
    do{
        printf("1. SALARY\n");
        printf("2. BONUS\n");
        printf("3. SAVINGS\n");                             //<----income
        printf("4. EXIT\n");
        printf("\nEnter your choice\n");
        scanf("%d",&n);
        getchar();
        printf("\n");

        switch(n){
            case 1: {
               printf("Enter Salary: ");
               scanf("%f",&i.salary);
               fprintf(ptr,"SALARY : +%.2f\n",i.salary);
               printf("SALARY ENTERED !!\n");
               tot_income += i.salary;
               getchar();
               break;
            } 
            case 2: {
               printf("Enter Bonus: ");
               scanf("%f",&i.bonus);
                fprintf(ptr,"BONUS : +%.2f\n",i.bonus);
               printf("BONUS ENTERED !!\n");
                tot_income += i.bonus;
               getchar();
               break;
            } 
            case 3: {
               printf("Enter Savings: ");
               scanf("%f",&i.savings);
                fprintf(ptr,"SAVINGS : +%.2f\n",i.savings);
               printf("SAVINGS ENTERED !!\n");
                tot_income += i.savings;
               getchar();
               break;
            }          
        }

     }while(n!=4 && n>0 && n<5);

    return 0;
}

int add_expense(){
    int n;
    
    printf("Enter your Expense\n");
    do{
        printf("1. FOOD\n");
        printf("2. EDUCATION\n");
        printf("3. ENTERTAINMENT\n");
        printf("4. EXIT\n");                                   //<------expenses
        printf("\nEnter your choice\n");
        scanf("%d",&n);
        getchar();
        printf("\n");

        switch(n){
            case 1: {
               printf("Enter Food: ");
               scanf("%f",&e.food);
                fprintf(ptr,"FOOD : -%.2f\n",e.food);
               printf("FOOD AMOUNT ENTERED !!\n");
               food_exp += e.food;
               tot_expense += e.food;
               getchar();
               break;
            } 
            case 2: {
               printf("Enter education: ");
               scanf("%f",&e.education);
               fprintf(ptr,"EDUCATION : -%.2f\n",e.education);
               printf("EDUCATION AMOUNT ENTERED !!\n");
                edu_exp += e.education;
                tot_expense += e.education;
               getchar();
               break;
            } 
            case 3: {
               printf("Enter Entertainment: ");
               scanf("%f",&e.entertainment);
               fprintf(ptr,"ENTERTAINMENT : -%.2f\n",e.entertainment);
               printf("ENTERTAIMENT AMOUNT ENTERED !!\n");
                entert_exp += e.entertainment;
                tot_expense += e.entertainment;
               getchar();
               break;
            }          
        }

     }while(n!=4 && n>0 && n<5);

    return 0;
}

int main(){
    
    ptr =fopen("Transaction History.txt","a");

    if(ptr == NULL){
        printf("ERROR ACCESSING FILE !!");
        return 0;
    }
    
    int n;
    float balance;

   do{

    printf("1. ADD INCOME\n");
    printf("2. ADD EXPENSE\n");
    printf("3. VIEW TRANSACTION HISTORY\n");      // <-- menu
    printf("4. CURRENT BALANCE\n");
    printf("5. SHOW CATEGORYWISE EXPENSES\n");
    printf("6. EXIT\n");
    printf("\nEnter your choice\n");
    scanf("%d",&n);
    getchar();
    printf("\n");

    switch(n){
        case 1 :{
            tot_income += add_income();
            break;
        }
        case 2 :{
            tot_expense += add_expense();
            break;
        }
        case 3:{
           
            fclose(ptr);
           ptr = fopen("Transaction History.txt","r");

           if(ptr==NULL){
            printf("error in accessing file");
            fclose(ptr);
             ptr = fopen("Transaction History.txt","a");
            break;
           }
           char statement[100];
           

           while(fgets(statement,100,ptr)){
           puts(statement);
           }
           fclose(ptr);
           ptr = fopen("Transaction History.txt","a");
            break;

        }
        case 4:{
            balance = tot_income - tot_expense;
            printf("CURRENT BALANCE : %.2f\n\n",balance);
            break;
        }
        case 5:{
            printf("FOOD: %.2f\n",food_exp);
            printf("ENTERTAINMENT: %.2f\n",entert_exp);
            printf("EDUCATION: %.2f\n\n",edu_exp);
            break;
        }
    }

   }while(n!=6 && n>0 && n<7);

   fprintf(ptr,"---------NEW SESSION---------\n\n");
   fclose(ptr);
    return 0;
}


