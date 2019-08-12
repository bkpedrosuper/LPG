#include <stdio.h>
#include <math.h>

float volume(float r);

int main(){
    float r, res;

    scanf("%f", &r);
    res = volume(r);

    printf("%.2f\n", res);

}

float volume(float r){
    return (4 * M_PI * pow(r,3))/3;
}
