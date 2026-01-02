#include<stdio.h>

struct product
{
    int pid;
    char pname[20];
    int qty;
    float price;
    float total;
};

int main()
{
    struct product p[5];
    int i;
    float grandTotal = 0;

    printf("\nEnter 5 product details:\n");

    for(i=0; i<5; i++)
    {
        printf("\nEnter product ID: ");
        scanf("%d",&p[i].pid);

        printf("Enter product name: ");
        scanf("%s",p[i].pname);

        printf("Enter product quantity: ");
        scanf("%d",&p[i].qty);

        printf("Enter product price: ");
        scanf("%f",&p[i].price);

        p[i].total = p[i].qty * p[i].price;
        grandTotal = grandTotal + p[i].total;
    }

    printf("\n-------------------------------------------");
    printf("\nID\tName\tQty\tPrice\tTotal");
    printf("\n-------------------------------------------");

    for(i=0; i<5; i++)
    {
        printf("\n%d\t%s\t%d\t%.2f\t%.2f",
               p[i].pid, p[i].pname, p[i].qty, p[i].price, p[i].total);
    }

    printf("\n-------------------------------------------");
    printf("\nGrand Total = %.2f", grandTotal);
    printf("\n-------------------------------------------");
    printf("\n\t\tThank You\n\t\tVisit Again");

    return 0;
}