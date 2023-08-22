#include <stdio.h>
#include <string.h>

struct Employee {
    int empId;
    char name[100];
    char designation[100];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
};

int main() {
    int n;

    printf("Enter no. of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter employee %d information:\n", i + 1);
        
        printf("Name: ");
        scanf(" %s", employees[i].name);
        
        printf("Designation: ");
        scanf(" %s", employees[i].designation);
        
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        
        printf("HRA %%: ");
        scanf("%f", &employees[i].hraPercentage);
        
        printf("DA %%: ");
        scanf("%f", &employees[i].daPercentage);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; ++i) {
        float hraAmount = employees[i].basicSalary * (employees[i].hraPercentage / 100);
        float daAmount = employees[i].basicSalary * (employees[i].daPercentage / 100);
        float grossSalary = employees[i].basicSalary + hraAmount + daAmount;

        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("HRA %% : %.2f\n", employees[i].hraPercentage);
        printf("DA %%: %.2f\n", employees[i].daPercentage);
        printf("Gross Salary: %.2f\n", grossSalary);
        printf("\n");
    }

    return 0;
}