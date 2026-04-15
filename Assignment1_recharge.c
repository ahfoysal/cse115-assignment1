#include <stdio.h>
#include <string.h>

struct recharge {
    int txnID;
    char operator_[15];
    char phoneTail[6];
    float amount;
    char package[20];
    char status[12];
};

int main() {
    struct recharge r[6] = {
        {88011, "GP", "1209", 249, "5GB-30days", "Success"},
        {88012, "Robi", "5544", 149, "3GB-14days", "Success"},
        {88013, "BL", "8790", 99, "1.5GB-7days", "Failed"},
        {88014, "Airtel", "3322", 349, "8GB-30days", "Success"},
        {88015, "Teletalk", "6601", 59, "500MB-3days", "Success"},
        {88016, "GP", "4415", 499, "15GB-30days", "Success"}
    };

    int i, j, key, found = 0;
    struct recharge temp;

    printf("All Transactions:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Operator: %s, Phone: *****%s, Amount: %.2f Tk, Package: %s, Status: %s\n",
               r[i].txnID, r[i].operator_, r[i].phoneTail, r[i].amount, r[i].package, r[i].status);
    }

    printf("\nEnter transaction ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (r[i].txnID == key) {
            printf("Found: %d, %s, *****%s, %.2f Tk, %s, %s\n",
                   r[i].txnID, r[i].operator_, r[i].phoneTail, r[i].amount, r[i].package, r[i].status);
            found = 1;
        }
    }
    if (found == 0)
        printf("Transaction not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (r[j].amount > r[j + 1].amount) {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by amount:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Operator: %s, Phone: *****%s, Amount: %.2f Tk, Package: %s, Status: %s\n",
               r[i].txnID, r[i].operator_, r[i].phoneTail, r[i].amount, r[i].package, r[i].status);
    }

    return 0;
}
