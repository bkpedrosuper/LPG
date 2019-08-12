#include <stdio.h>

int pos(int x);

int main(){
    int a, res;

    scanf("%i", &a);
    res = pos(a);

    if(res==1) printf("%i é positivo\n", a);
    if(res==-1) printf("%i é negativo\n", a);
    if(res==0) printf("%i é nulo\n", a);

}

int pos(int x){
    if (x<0) return -1;
    if (x>0) return 1;
    if (x==0) return 0;
}
