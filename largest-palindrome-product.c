/*
 *
 * FIND LARGEST PALINDROME PRODUCT OF TWO 3-DIGIT NUMBERS.
 *
 */

#include <stdio.h>
#include <gmp.h>
#include <string.h>

int main() {


	mpz_t counter1;
	mpz_init(counter1);
	

	
	mpz_t counter2;
	mpz_init(counter2);
	

	mpz_t min;
	mpz_init(min);
	mpz_set_ui(min,100);

	mpz_t product;
	mpz_init(product);

	mpz_t cmpr;
	mpz_init(cmpr);
	mpz_set_ui(cmpr, 1);


	for (mpz_set_ui(counter1,999);mpz_cmp(counter1,min) >= 0; mpz_sub_ui(counter1, counter1, 1)) {

			

		for (mpz_set_ui(counter2,999);mpz_cmp(counter2,min) >= 0; mpz_sub_ui(counter2, counter2, 1)) {

			mpz_mul(product, counter1, counter2);		
		//	gmp_printf("%Zd * %Zd = %Zd\n", counter1, counter2, product);
	                
			char* prdStr = mpz_get_str(NULL, 10, product);
			int prdLenght = strlen(prdStr);		
			int palFlag = 1;
			
				for(int i = 0; i < prdLenght; i++){
			
					if (prdStr[i]!=prdStr[prdLenght-i-1]){
						palFlag=0;
						break;
					}
									
				}

			if (palFlag) {
				
				if(mpz_cmp(product,cmpr) > 0)
				{
					mpz_set(cmpr, product);
				}
							
	
			}
			
			


    	          }

	}	

			gmp_printf("%Zd\n", cmpr); 	

}
 
