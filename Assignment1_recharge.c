/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Mobile Recharge Transaction Log
 * Operations: linear search by transaction ID, bubble sort by amount
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct recharge {
    int   txnID;
    char  operator_[15];   /* GP / Robi / BL / Teletalk / Airtel */
    char  phoneTail[6];    /* last 4 digits of phone */
    float amount;          /* in taka */
    char  package[20];     /* e.g. 5GB-30days */
    char  status[12];      /* Success / Failed */
};

typedef struct recharge RechargeData;

void Display(RechargeData r[]);
void Search(RechargeData r[], int id);
void SortByAmount(RechargeData r[]);

int main(void)
{
    RechargeData txns[SIZE] = {
        {88011, "GP",       "1209", 249.00, "5GB-30days",  "Success"},
        {88012, "Robi",     "5544", 149.00, "3GB-14days",  "Success"},
        {88013, "BL",       "8790",  99.00, "1.5GB-7days", "Failed" },
        {88014, "Airtel",   "3322", 349.00, "8GB-30days",  "Success"},
        {88015, "Teletalk", "6601",  59.00, "500MB-3days", "Success"},
        {88016, "GP",       "4415", 499.00, "15GB-30days", "Success"}
    };

    int id;

    printf("===== Recharge log (original) =====\n");
    Display(txns);

    printf("\nEnter a transaction ID to search: ");
    scanf("%d", &id);
    Search(txns, id);

    SortByAmount(txns);

    printf("\n===== Recharge log (sorted by amount) =====\n");
    Display(txns);

    return 0;
}

void Display(RechargeData r[])
{
    int i;
    printf("%-7s %-10s %-8s %-10s %-15s %-10s\n",
           "TxnID", "Operator", "Last4", "Amount", "Package", "Status");
    for (i = 0; i < SIZE; i++) {
        printf("%-7d %-10s %-8s %-10.2f %-15s %-10s\n",
               r[i].txnID, r[i].operator_, r[i].phoneTail,
               r[i].amount, r[i].package, r[i].status);
    }
}

void Search(RechargeData r[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (r[i].txnID == id) {
            printf("\nTransaction found:\n");
            printf("  Txn ID    : %d\n",      r[i].txnID);
            printf("  Operator  : %s\n",      r[i].operator_);
            printf("  Phone     : *****%s\n", r[i].phoneTail);
            printf("  Amount    : %.2f Tk\n", r[i].amount);
            printf("  Package   : %s\n",      r[i].package);
            printf("  Status    : %s\n",      r[i].status);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo transaction with ID %d.\n", id);
    }
}

void SortByAmount(RechargeData r[])
{
    int i, j;
    RechargeData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (r[j].amount > r[j + 1].amount) {
                temp     = r[j];
                r[j]     = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }
}
