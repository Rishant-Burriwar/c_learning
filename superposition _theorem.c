#include <stdio.h>
int main() {
  double a[5];
  double i1,i2,it;
  double req,s;
  printf("enter r1,r2,r3 and v1,v2 :\n");
  for(int i=0;i<5;++i){
    scanf("%lf",&a[i]);
  }
//v1 acting
req = (a[1]*a[2])/(a[1] +a[2]);
req = req + a[0];

i1 = a[3]/req;
it=i1;
i1 = i1*a[1]/(a[2]+a[1]);
//v2 acting
req = (a[0]*a[2])/(a[0]+a[2]);
req = req + a[1];

i2 = a[4]/req;
i2 = i2*a[0]/(a[2]+a[0]);

printf("%lf\n%lf\n",i1,i2);



printf("current in r3 is %lf",i1+i2);
}


    


