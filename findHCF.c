// #include<stdio.h>
// //#include<conio.h>
// int find_HCF(int m, int n)
// {
//     if (n==0)
//         return m;
//     else
//         return find_HCF(n, m%n);
// }

// int main()
// {
//     int a, b;
//     printf("Enter 2 positive integers: ");
//     scanf("%d %d " , &a, &b);
//     int R=find_HCF(a, b);
//     printf("The HCF of %d and %d is: %d", a, b, R);
// }

#include<stdio.h>
int findHCF(int m, int n)
{
    if (n==0)
        return m;
    else
        return findHCF(n, m%n);
}

int main()
{
    int a, b;
    printf("Enter 2 positive integers: ");
    scanf("%d%d", &a, &b);
    printf("The HCF of %d and %d is:",a,b);
    printf("%d", findHCF(a, b));

}