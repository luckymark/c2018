#include<stdio.h>

#include<math.h>

#include<time.h>

int main()



{

	float start, end;

	start = clock();

	int n, i, p;



	for (n = 2; n <= 1000; n++) {



		p = 0;

		for (i = 2; i <= sqrt(n); i++) {



			if (n%i == 0) {



				p = 1;

				break;

			}



		}

		if (p == 0) printf("%d   ", n);

	}

	end = clock();

	printf("\ntime=%fms", end - start);

	return 0;



}