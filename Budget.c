#include <stdio.h>

void add_income(float *income, float pastIncomes[], int *incomeCount){
    float amount;
    printf("Enter income amount: $");
    scanf("%f", &amount);
    if(amount > 0) {
        *income += amount;
        pastIncomes[*incomeCount] = amount;
        (*incomeCount)++;
        printf("Income added successfully.\n");
    } else {
        printf("Invalid income amount.\n");
    }
}

void add_expense(float *expenses, float pastExpenses[], int *expenseCount){
    float amount;
    printf("Enter expense amount: $");
    scanf("%f", &amount);
    if(amount > 0) {
        *expenses += amount;
        pastExpenses[*expenseCount] = amount;
        (*expenseCount)++;
        printf("Expense added successfully.\n");
    } else {
        printf("Invalid expense amount.\n");
    }
}

void view_balance(float income, float expenses){
    printf("\nCurrent Balance: $%.2f\n", income - expenses);
}

void view_past_income(float pastIncomes[], int incomeCount){
    printf("\nIncome History:\n");
    if(incomeCount == 0) {
        printf("No income history available.\n");
        return;
    } else {
        for (int i = 0; i < incomeCount; i++) {
            printf("Income %d: $%.2f\n", i + 1, pastIncomes[i]);
        }
    }
}

void view_past_expenses(float pastExpenses[], int expenseCount){
    printf("\nExpense History:\n");
    if(expenseCount == 0) {
        printf("No expense history available.\n");
        return;
    } else {
        for (int i = 0; i < expenseCount; i++) {
            printf("Expense %d: $%.2f\n", i + 1, pastExpenses[i]);
        }
    }
}

void delete_income_entry(float pastIncomes[], int *incomeCount, float *income) {
    if (*incomeCount == 0) {
        printf("No income entries to delete.\n");
        return;
    }

    view_past_income(pastIncomes, *incomeCount);
    int index;
    printf("Enter the income entry number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *incomeCount) {
        printf("Invalid entry number.\n");
        return;
    }

    index--; 
    *income -= pastIncomes[index];

    for (int i = index; i < *incomeCount - 1; i++) {
        pastIncomes[i] = pastIncomes[i + 1];
    }
    (*incomeCount)--;
    printf("Income entry deleted.\n");
}

void delete_expense_entry(float pastExpenses[], int *expenseCount, float *expenses) {
    if (*expenseCount == 0) {
        printf("No expense entries to delete.\n");
        return;
    }

    view_past_expenses(pastExpenses, *expenseCount);
    int index;
    printf("Enter the expense entry number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *expenseCount) {
        printf("Invalid entry number.\n");
        return;
    }

    index--; 
    *expenses -= pastExpenses[index];

    for (int i = index; i < *expenseCount - 1; i++) {
        pastExpenses[i] = pastExpenses[i + 1];
    }
    (*expenseCount)--;
    printf("Expense entry deleted.\n");
}
