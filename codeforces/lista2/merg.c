#include <stdio.h>
int main(){
    int a,b,p;
    scanf("%d %d",&a,&b);
    int h[b],j[a-b];
    for(int c=0;c<b;c++)
      scanf("%d",&h[c]);
    if(a==b || a==0){
        printf("*");
    }else{
    for(int i=1;i<=a;i++){
      if(b==0){
         printf("%d ",i);
      }
       for(int k=0;k<b;k++){
           if(i==h[k]){
            p=0; break;
           } 
           else p=1;
       }
      if(p==1){
        j[i]=i;
        printf("%d ",j[i]);
      }
    }
    }
}
