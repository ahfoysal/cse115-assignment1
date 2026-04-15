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
        {77021, "Robi", "2208", 199, "4GB-15days", "Success"},
        {77022, "GP", "7733", 129, "2GB-7days", "Success"},
        {77023, "Airtel", "5512", 79, "1GB-3days", "Failed"},
        {77024, "BL", "9901", 299, "7GB-30days", "Success"},
        {77025, "Teletalk", "3340", 49, "300MB-2days", "Success"},
        {77026, "Robi", "6678", 549, "20GB-30days", "Success"}
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
