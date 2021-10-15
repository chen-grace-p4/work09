#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct menu {
   char* food;
   double price;
   int amount;
};

void print_menu(struct menu *s) {
   int i;
   printf("food: '");
   for (i = 0; *(s->food + i) != '\0'; i++) {
		printf("%c", *(s->food + i));
	}
   printf("'\t price: $%.2lf\tnumber of food: %d \n", s->price, s->amount);
}

struct menu * make_menu(char* food, double price, int amount);

int main() {
   srand(time(NULL));

   char * food = "banana";
   double price = rand() / 100000000.0;
   int amount = rand() / 100000000;

   struct menu *test = make_menu(food, price, amount);
   print_menu(test);

   free(test);
   printf("Note: price and number of food is randomized. \n");

   return 0;
}

struct menu * make_menu(char* food, double price, int amount) {
	struct menu *n;
	n = malloc(sizeof(struct menu));

	n->food = food;
	n->price = price;
   n->amount = amount;

	return n;
}
