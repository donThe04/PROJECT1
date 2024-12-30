//C 
#include <stdio.h> 

int main() 
{ 
        int n; scanf("%d", &n);
    for(int i = 1; i <= 999; i++){
        int x;
        x = n * i;
        if(x >= 100 && x <= 999){
            printf(" %d ", x);
        }
    }
    
    return 0;

}

