#include <stdio.h>

struct student {
    char name[50];
    int age;
    double height;
};

void print(char name[], int age, double height) {
    printf("%s %d %.2f", name, age, height);
}

void keyvalue(char *name, int *age, double *height) {
    printf("输入");
    scanf("%s %d %lf", name, age, height);
};

int main() {
    struct student a = {"小金毛陶源", 20, 181.0};
    struct student b;

    print(a.name, a.age, a.height);
    keyvalue(b.name, &b.age, &b.height);

    print(b.name, b.age, b.height);
}
