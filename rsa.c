#include <stdio.h>
#include <math.h>

int findE(int phi) {
    int i;
    for(i=1;i<phi;i++) {
        if(phi%i!=0)
            return i;
    }
    return -1;
}

void rsaInit(int *p, int *q, int *d, int *phi, int *n, int *e, int *k) {
    *p=53, *q = 59;
    *k = 2;
    *n = *p * *q;
    *phi = (*p-1)*(*q-1);

    *e = findE(*phi);
    
    if(*e==-1) {
        printf("e not found\n");
    }

    *d = (*k * *phi + 1)/(*e);
}

void encrypt(char *data, int *en,int e,int n) {
    int i=0;
    while(*data!='\0') {
        en[i] = (int)pow(*data,e)%n;
        printf("%d ",en[i]);
        data++;
        i++;
    }
    printf("\n");
}

void decrypt(int *en, int d, int n) {
    int i=0;
    double val;
    while(i<5) {
        val = pow(en[i],d);
        printf("%f",val);
        i++;
    }
    printf("\n");
}

int main() {

    int p,q,d,phi,n,e,k;
    
    rsaInit(&p,&q,&d,&phi,&n,&e,&k);
    
    printf("n=%d\td=%d\te=%d\n",n,d,e);

    char data[30];
    int en[30];

    scanf("%s",data);

    encrypt(&data[0],&en[0],e,n);

    decrypt(&en[0],d,n);

    return 0;
}
