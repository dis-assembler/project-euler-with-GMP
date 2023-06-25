/*
 *
 * FIND THE SUM OF MULTIPLES OF 3 OR 5 BELOW 1000
 *
 */
#include <stdio.h>
#include <gmp.h>

int main() {

	mpz_t limit;
	mpz_init(limit);
	mpz_set_ui(limit, 999);

	mpz_t sum;
	mpz_init(sum);
	mpz_set_ui(sum, 0);
	
	mpz_t counter;
	mpz_init(counter);
	
	mpz_t div1;
	mpz_init(div1);
	mpz_set_ui(div1, 3);

	mpz_t div2;
	mpz_init(div2);
	mpz_set_ui(div2, 5);

	mpz_t mod3;
	mpz_init(mod3);

	mpz_t mod5;
	mpz_init(mod5);

for (mpz_set(counter,limit); mpz_cmp_ui(counter,0) > 0; mpz_sub_ui(counter,counter,1)) {

	mpz_mod(mod3, counter, div1);
	
	mpz_mod(mod5, counter, div2);

	if ( (mpz_cmp_ui(mod3, 0) == 0) || (mpz_cmp_ui(mod5, 0) == 0)) {

		mpz_add_ui(sum, sum, mpz_get_ui(counter));
	
	}

}

	gmp_printf("\n%Zd\n", sum);

}
