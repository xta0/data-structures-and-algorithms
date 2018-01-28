#include<stdio.h>
using namespace std;

struct patient
{
    int num;
    float how;
};

int main() {
    int m, i, j;
    float a;

    

    scanf("%d%f", &m, &a);
    struct patient p[51];
    for (i=0; i<m; i++) {
        scanf("%d%f", &p[i].num, &p[i].how);
    }
    for (j=1;j<m;j++) {
        for (i=0;i<j;i++) {
            if (p[i].how<p[j].how) {
                struct patient temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    bool hasPrint = false;
    for (i=0;i<m;i++) {
        if (p[i].how > a) {
            printf("%03d %.1f\n", p[i].num, p[i].how);
            hasPrint = true;
        }
    }
    if (!hasPrint) {
        printf("None.");
    }
    return 0;
}