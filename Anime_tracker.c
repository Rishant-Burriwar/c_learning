#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
FILE*ptr;
int i=0;

void add_anime(){

    char s[200];
    float rate;
    printf("Add anime name : ");
    fgets(s,200,stdin);
    s[strcspn(s,"\n")] = '\0';
    fprintf(ptr,"%s\t",s);

    printf("\nEnter rating of anime (1-10) : ");
    scanf("%f",&rate);
    getchar();
    fprintf(ptr,"%.2f\t",rate);

    printf("\nEnter status (watched/not watched/plan to watch) : ");
    fgets(s,200,stdin);
    s[strcspn(s,"\n")] = '\0';
    fprintf(ptr,"%s\t",s);

    printf("\nEnter genre : ");
    fgets(s,200,stdin);
    s[strcspn(s,"\n")] = '\0';
    fprintf(ptr,"%s\t",s);

    fprintf(ptr,"\n");
    ++i;

}

void remove_anime(){
   fclose(ptr);

    int k=0,j;
    char s[20][200],a[200];
    ptr = fopen("Anime_tracker.txt","r");

    while(fgets(s[k],200,ptr)){
      s[k][strcspn(s[k],"\n")] = '\0';
      ++k;
    }

    fclose(ptr);

    printf("Enter anime name to remove : ");
    fgets(a,200,stdin);
    a[strcspn(a,"\n")] = '\0';

    ptr = fopen("Anime_tracker.txt","w");

     for(j=0;j<k;++j){
        if(strncmp(s[j],a,strlen(a)) !=0){
            fprintf(ptr,"%s\n",s[j]);
        }
    }
    fclose(ptr);

    ptr = fopen("Anime_tracker.txt","a+");

}

void anime_list(){
  fclose(ptr);
  ptr = fopen("Anime_tracker.txt","r");
    int k=0;
    char s[20][200];

    while(fgets(s[k],200,ptr)){
      s[k][strcspn(s[k],"\n")] = '\0';
      ++k;
    }

    for(int i=0;i<k;++i){
        int len = strlen(s[i]);
        for(int j=0;j<len;++j){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fclose(ptr);
     ptr = fopen("Anime_tracker.txt","a+");

}

void recommend_anime(){
    FILE *ptr_file;
    ptr_file = fopen("anime_list.txt","r");
    int k=0;
    char s[100][100];
    while(fgets(s[k],100,ptr_file)){
        s[k][strcspn(s[k],"\n")] = '\0';
        ++k;
    }
    srand(time(0));
    int random = rand()%100;
    printf("%s\n\n",s[random]);
    fclose(ptr_file);
}

int main(){

    ptr = fopen("Anime_tracker.txt","a+");
    int n;

    if(ptr == NULL){
    printf("File not opened\n");
    return 0;
    }

    printf("-----------------WELCOME TO ANIME TRACKER----------------\n\n");

    do{
        printf("1. ADD ANIME\n");
        printf("2. REMOVE ANIME\n");
        printf("3. VIEW ANIME LIST\n");
        printf("4. RECOMMEND A RANDOM ANIME\n");
        printf("5. EXIT\n");

        printf("Enter choice\n");
        scanf("%d",&n);
        getchar();            //<--- removes new line from buffer
        printf("\n");

        switch(n){

        case 1: {
          add_anime();
          break;
        }

        case 2: {
          remove_anime();
          break;
        }

        case 3:{
         anime_list();
         break;
        }

        case 4: {
         recommend_anime();
         break;
        }

        }
       
    }while(n>0 && n<5);

    fclose(ptr);
    return 0;
}