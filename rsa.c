#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int isPrime(long int n) {
    long int i;
    float rt = sqrt(n);
    for(i=2;i<=rt;i++) {
        if(n%i==0)
            return 0;
    }
    return 1;
}

long int randomNumbers(long int c) {
    long int a = 32768;
    long int b = 1048576;
    for(long int i=a+c;i<b;i++) {
        if(isPrime(i))
            return i;
    }
    return -1;
}

long int gcd(long int a, long int b) {
    if(a==0)
        return b;
    return gcd(b%a,a);
}

long int find_e(long int lamda_n) {
    long int i;
    for(i=3;i<lamda_n;i++) {
        if(gcd(i,lamda_n)==1) {
            return i;
        }
    }
    return -1;
}


//finds value of d and finds gcd
long int gcdExtended(long int p, long int q, long int *x, long int *y) {
    if(p==0) {
        *x = 0;
        *y = 1;
        return q;
    }

    long int x1;
    long int y1;
    long int gcd = gcdExtended(q%p, p, &x1, &y1);

    *x = y1 - (q/p)*x1;
    *y = x1;

    return gcd;
}

int main() {
    long int p,q,gcdv,lamda_n,n,e=-1,d,temp; 

    
    while(e==-1) {
        /*
        p = randomNumbers(0);
        q = randomNumbers(p);
        */
        p = 61;
        q = 53;
        
        gcdv = gcdExtended(p-1,q-1,&d,&temp);

        n = p*q;
        lamda_n = ((p-1)*(q-1))/gcdv;

        e = find_e(lamda_n);
        printf("p=%ld\nq=%ld\nn=%ld\nlamda_n=%ld\ne=%ld\n",p,q,n,lamda_n,e);
    }

    printf("d=%ld\n",d);

    return 0;
}
