#include <stdio.h>
#include <string.h>

int main(){

    char dna[256];
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%256s",dna);
        int len=strlen(dna);
        for(int j=0;j<len;j++){
            if(dna[j] == 'A'){
                printf("T");
                // dna[j]='T';
            }else if(dna[j]=='T'){
                // dna[j]='A';
                printf("A");
            }else if(dna[j]=='G'){
                // dna[j]='C';
                printf("C");
            }else if(dna[j]=='C'){
                // dna[j]='G'
                printf("G");;
            }
        }
        // for(int k=0;k<len;k++){
        //     printf("%c",dna[k]);
        // }
        printf("\n");
        //clear dna
        for(int x=0;x<255;x++){
            dna[x]='\0';
        }
    }
    return 0;
}