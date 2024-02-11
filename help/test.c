#include <stdio.h>

int find_d(long int p, long int q, long int gcdv) {
    long int r[2] = {p,q};
    long int s[2] = {1,0};
    long int t[2] = {0,1};
    long int qi,temp;

    printf("r=%ld %ld\n",r[0],r[1]);
    printf("s=%ld %ld\n",s[0],s[1]);
    printf("t=%ld %ld\n",t[0], t[1]);
    while(r[1]!=0) {
        qi = r[0] / r[1];
        printf("qi=%ld\n",qi);
        
        temp = r[0] - (qi * r[1]);
        r[0] = r[1];
        r[1] = temp;
        printf("r=%ld %ld\n",r[0],r[1]);

        temp = s[0] - qi * s[1];
        s[0] = s[1];
        s[1] = temp;
        printf("s=%ld %ld\n",s[0],s[1]);

        temp = t[0] - qi * t[1];
        t[0] = t[1];
        t[1] = temp;
        printf("t=%ld %ld\n",t[0], t[1]);
    }
    return s[1];
}

int main() {
    printf("%ld\n",find_d(240,46,1));

    return 0;
}
