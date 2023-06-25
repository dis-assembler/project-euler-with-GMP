/*
 *
 * CALCULATE THE LARGEST PRIME FACTOR OF 600851475143
 *
 */
#include <stdio.h>
#include <gmp.h>

int main() {
    
	mpz_t index;
	mpz_init(index);

	mpz_t prime;
	mpz_init(prime);
	mpz_set_str(prime, "600851475143", 10);

	mpz_t control;
	mpz_init(control);
	mpz_set_ui(control, 1);

	mpz_t factorial;
	mpz_init(factorial);

	mpz_t result;
	mpz_init(result);

	mpz_t result2;
	mpz_init(result2);

	mpz_t start;
	mpz_init(start);
	mpz_set_ui(start, 2);

	mpz_t step;
	mpz_init(step);
	mpz_set_ui(step, 1);

	
	for(mpz_set(index, start); mpz_cmp(control, prime); mpz_add(index, index, step)) {

		mpz_sub_ui(factorial, index, 1);
		mpz_fac_ui(factorial, mpz_get_ui(factorial));

		mpz_add_ui(result, factorial, 1);
		mpz_mod(result, result, index);

		mpz_mod(result2, prime, index);


		if ((mpz_cmp_ui(result, 0) == 0) && (mpz_cmp_ui(result2, 0) == 0 )) {

			gmp_printf("PRIMO: %Zd\n", index);
			
			mpz_mul(control, control, index);		
		}
	

	}




    return 0;
}


