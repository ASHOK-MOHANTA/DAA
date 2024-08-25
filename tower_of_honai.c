#include <stdio.h>
int count=0;
void TOH(int n, char source, char temp, char dest) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, dest);
        count++;
        return;
        
    }
    TOH(n - 1, source, dest, temp);
    printf("Move disk %d from rod %c to rod %c\n", n, source, dest);
    TOH(n - 1, temp, source, dest);
    count++;
}

int main() {
    int num_disks;
    char source = 'A', temp = 'B', dest = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    TOH(num_disks, source, temp, dest);
    printf("Number of disk shift is: %d",count);
    
    return 0;
}
