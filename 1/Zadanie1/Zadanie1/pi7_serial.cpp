#include <stdio.h>
#include <time.h>
#include <omp.h>

long long num_steps = 1000000000;
double step;

int main(int argc, char* argv[])
{
	clock_t start, stop;
	double x, pi, sumGlob = 0.0;
	int i;
	step = 1. / (double)num_steps;
	int  numOfThreads = 2;

	omp_set_num_threads(numOfThreads);
	volatile double sum[50] = { 0.0 };

	for (int j = 0; j < 50; ++j) {
		start = clock();
#pragma omp parallel
		{
			int numThread = omp_get_thread_num();
			sum[numThread + j] = 0;
#pragma omp for
			for (i = 0; i < num_steps; i++)
			{
				x = (i + .5) * step;
				sum[numThread + j] = sum[numThread + j] + 4.0 / (1. + x * x);

			}
		}
		sumGlob = 0;
		for (int k = j; k < j + numOfThreads; ++k) sumGlob += sum[k];
		pi = sumGlob * step;
		stop = clock();
		printf("Iteracja numer: %d\n", j);
		printf("Wartosc liczby PI wynosi %15.12f\n", pi);
		printf("Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));
	}
	return 0;
}