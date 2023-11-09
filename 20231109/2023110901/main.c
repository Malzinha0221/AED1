#include <stdio.h>

int maior(int v[], int n){
    int x;
    if (n==1)
        return v[0];
    else{
        x= maior(v,n-1);
        if(x>v[n-1])
            return x;
        else
            return v[n-1];
    }
}
int menor(int v[], int n){
    if (n==1){
        return v[0];
    }
    int min = menor(v, n-1);
    return (v[n-1]<min ? v[n-1] : min);
}
int Soma(int v[], int n){
    if (n==0){
        return 0;
    }
    return v[n-1] + Soma(v,n-1);
}
int Produto(int v[], int n){
    if (n==1){
        return v[0];
    }
    return v[n-1] * Produto(v,n-1);
}
int main(){
    int v[]={1,2,3,4,5,6,7,8,9,10};
    printf("Maior %d\n", maior(v, 10));
    printf("Menor %d\n", menor(v, 10));
    printf("Soma %d\n", Soma(v, 10));
    printf("Produto %d\n", Produto(v, 10));

    return 0;
}
