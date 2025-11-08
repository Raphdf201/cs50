#include <stdio.h>
#include <cs50.h>

int main(void) {
    double money;
    int coins = 0;
    do {
        money = get_double("Change owed : ");
    } while (money <= 0);

    while (money > 0) {
        if (money >= 25) {
            money -= 25;
            coins += 1;
        } else if (money >= 10) {
            money -= 10;
            coins += 1;
        } else if (money >= 5) {
            money -= 5;
            coins += 1;
        } else if (money >= 1) {
            money -= 1;
            coins += 1;
        }
    }

    printf("%i\n", coins);
}
