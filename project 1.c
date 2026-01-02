#include <stdio.h>

struct Product
{
    int pid;
    char name[20];
    int qty;
    float price;
    float total;
};

int main()
{
    struct Product p[5];
    FILE *fp;
    int i, searchId, found = 0;

    /* Writing data into file */
    fp = fopen("product.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    printf("Enter details of 5 products:\n");

    for (i = 0; i < 5; i++)
    {
        printf("\nProduct %d\n", i + 1);

        printf("Product ID: ");
        scanf("%d", &p[i].pid);

        printf("Product Name: ");
        scanf("%s", p[i].name);

        printf("Quantity: ");
        scanf("%d", &p[i].qty);

        printf("Price: ");
        scanf("%f", &p[i].price);

        p[i].total = p[i].qty * p[i].price;

        fprintf(fp, "%d %s %d %.2f %.2f\n",
                p[i].pid, p[i].name, p[i].qty, p[i].price, p[i].total);
    }

    fclose(fp);

    /* Reading data from file */
    fp = fopen("product.txt", "r");

    printf("\n--------------------------------------------------\n");
    printf("PID\tName\tQty\tPrice\tTotal\n");
    printf("--------------------------------------------------\n");

    float grandTotal = 0;

    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%d %s %d %f %f",
               &p[i].pid, p[i].name, &p[i].qty, &p[i].price, &p[i].total);

        printf("%d\t%s\t%d\t%.2f\t%.2f\n",
               p[i].pid, p[i].name, p[i].qty, p[i].price, p[i].total);

        grandTotal += p[i].total;
    }

    printf("--------------------------------------------------\n");
    printf("Total Bill Amount: %.2f\n", grandTotal);
    printf("--------------------------------------------------\n");

    fclose(fp);

    /* Search Product */
    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);

    for (i = 0; i < 5; i++)
    {
        if (p[i].pid == searchId)
        {
            printf("\nProduct Found\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nTotal: %.2f\n",
                   p[i].pid, p[i].name, p[i].qty, p[i].price, p[i].total);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nProduct not found!");
    }

    return 0;
}