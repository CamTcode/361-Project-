#include <stdio.h>
#include "Budget.h"
#include "Ui.h"

int main() {
    float income = 0.0, expenses = 0.0;
    float pastIncomes[MAX_HISTORY] = {0};
    float pastExpenses[MAX_HISTORY] = {0};
    int incomeCount = 0, expenseCount = 0;
    int choice;

    while (1) {
        display_ui();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&income, pastIncomes, &incomeCount);
                break;
            case 2:
                add_expense(&expenses, pastExpenses, &expenseCount);
                break;
            case 3:
                view_balance(income, expenses);
                break;
            case 4:
                view_past_income(pastIncomes, incomeCount);
                break;
            case 5:
                view_past_expenses(pastExpenses, expenseCount);
                break;
            case 6:
                delete_income_entry(pastIncomes, &incomeCount, &income);
                break;
            case 7:
                delete_expense_entry(pastExpenses, &expenseCount, &expenses);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}