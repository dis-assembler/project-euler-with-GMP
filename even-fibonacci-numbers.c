/*
 *
 * FIND THE SUM NOT EXCEEDING FOUR MILLION OF THE EVEN FIBONACCI NUMBERS
 *
 */

#include <stdio.h>
#include <gmp.h>

int main(){


	mpz_t F0;
	mpz_init(F0);
	mpz_set_ui(F0, 1);

	mpz_t F1;
	mpz_init(F1);
	mpz_set_ui(F1, 1);

	mpz_t F2;
	mpz_init(F2);

	mpz_t sum;
	mpz_init(sum);
	mpz_set_ui(sum, 0);

	mpz_t counter;
	mpz_init(counter);
	mpz_set_ui(counter, 0);

	mpz_t limit;
	mpz_init(limit);
	mpz_set_ui(limit, 4000000);


	mpz_t mod1;
	mpz_init(mod1);

	mpz_t even;
	mpz_init(even);
	mpz_set_ui(even, 2);

	mpz_t step;
	mpz_init(step);
	mpz_set_ui(step, 1);


for (;( mpz_cmp(sum, limit) < 0); mpz_add(counter, counter, step)){

	mpz_add(F2, F0, F1);

	mpz_set(F1, F0);

	mpz_set(F0, F2);

	mpz_mod(mod1, F2, even);

//gmp_printf("%Zd\n", F2);

	if (mpz_even_p(F2)) {

	mpz_add(sum, sum, F2);

}
	else {
	
		continue;
	
	}

}

	gmp_printf("%Zd\n", sum);

	
	mpz_clear(F0);
	mpz_clear(F1);
	mpz_clear(F2);
	mpz_clear(even);
	mpz_clear(step);
	mpz_clear(mod1);
	mpz_clear(counter);
	mpz_clear(sum);
	return 0;

}
