#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("请输入输入数字的个数");
    scanf("%d",&n);
    int *p=(int* )malloc(n*sizeof(int));
    int *w=(int*)calloc(n,sizeof(int));

    if (p==NULL||w==NULL) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        printf("please press number");
        scanf("%d",p+i);
        scanf("%d",w+i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d",*(p+i));
        printf("%d",*(w+i));

    }
    p=(int*)realloc(p,2*n*sizeof(int));
    for (int i = n; i < 2*n; ++i) {
        printf("please press number");
        scanf("%d",p+i);

    }
    for(int i = 0; i < 2*n; ++i) {
        printf("%d",*(p+i));
    }
    free(p);
    p=NULL;
    free(w);
    w=NULL;
}

