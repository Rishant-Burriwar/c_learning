#include<stdio.h>
#include<string.h>
int main (){

int n,a=0,i=0,m,k,l;
char book[20][50],temp[50],bookfind[50];
char bookremove[50];

 char input_pass[10],pass[10]="lib2025";
 printf("WELCOME TO RISHANT'S LIBRARY\n\n");
 printf("Enter password to access your profile\n");

 fgets(input_pass,sizeof(input_pass),stdin);
 input_pass[strcspn(input_pass,"\n")] =0;

 n=strcmp(input_pass,pass);
 
if(n==0){

    printf("\nValid password entered !!\n");

do{
    printf("\n1. Add new book\n");
    printf("2. Remove a book\n");
    printf("3. Sort the books\n");
    printf("4. Search for a book\n");          //menu
    printf("5. Display all books\n");
    printf("6. EXIT\n");
    
    printf("\nChoose an option: ");
    scanf("%d",&a);
    

  switch(a){

    //CASE 1  ADD BOOKS

    case 1 : {
      printf("\nEnter name of the book\n");
      getchar();  //this clears the '\n' left by scanf
      fgets(book[i], sizeof(book[i]), stdin);
      book[i][strcspn(book[i], "\n")] = 0;
    
      printf("\nBOOK ADDED SUCCESSFULLY !!\n");
      ++i;
      break;
    } 

    //CASE 2    REMOVE BOOKS

    case 2 : {
      if(i==0){
        printf("\nFIRST ADD BOOKS TO LIBRARY\n");
        break;
      }
      printf("\nEnter name of the book to remove\n");
      getchar();
      fgets(bookremove,sizeof(bookremove),stdin);
      bookremove[strcspn(bookremove, "\n")] = 0;
      
      int found =0;
      for(m=0;m<i;++m){
        if(strcmp(book[m],bookremove)==0){
          found =1;
          
          for(k=m;k<=i;++k){
            strcpy(book[k],book[k+1]);
          }
          --i;
          break;

        }        
       }
       if(found!=0){
        printf("\nBOOK REMOVED SUCCESSFULLY");
       }
       else{
        printf("\nBOOK NOT FOUND !!");
       }
    
    break;
  }

  //CASE 3      SORTING BOOKS

  case 3 : {

     if(i==0){
        printf("\nFIRST ADD BOOKS TO LIBRARY\n");
        break;
      }
    for(l=0;l<i-1;++l){
    
      for(k=0;k<i-l-1;++k){
       if(strcmp(book[k],book[k+1])>0){
        strcpy(temp,book[k]);
        strcpy(book[k],book[k+1]);
        strcpy(book[k+1],temp);
      }
    }

  }

  printf("BOOKS SORTED SUCCESSFULLY !!");

  for(k=0;k<i;++k){
    printf("\n%s\n",book[k]);
  }

 break;
  
}

   //CASE 4    FINDING BOOK

   case 4 : {

      if(i==0){
        printf("\nFIRST ADD BOOKS TO LIBRARY\n");
        break;
      }

     printf("\nENTER NAME OF THE BOOK TO FIND\n");

     getchar();
     fgets(bookfind,sizeof(bookfind),stdin);
     bookfind[strcspn(bookfind ,"\n")] = 0;

     int found =0;
     for(k=0;k<i;++k){
      if(strcmp(book[k],bookfind)==0){
        found =1;
        break;

      }

     }

     if(found ==1){
       printf("\nBOOK FOUND !!\n");
     }

     else{
       printf("\nBOOK NOT FOUND !!\n");
     }

   break;
   }

  //case 5   DISPLAYING BOOKS

  case 5 : {

     if(i==0){

        printf("\nFIRST ADD BOOKS TO LIBRARY\n");
       break;

      }

  printf("\nALL AVAILABLE BOOKS ARE :-\n");

  for(k=0;k<i;++k){

    printf("\n%s\n",book[k]);
  }

  break;

  }

}

}while(a<6);

}

  else{
    printf("INVALID PASSWORD ENTERED");
}

}









