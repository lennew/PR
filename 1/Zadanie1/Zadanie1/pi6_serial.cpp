//#include <stdio.h>
//#include <time.h>
//#include <omp.h>
//
//long long num_steps = 1000000000;
//double step;
//
//int main(int argc, char* argv[])
//{
//	clock_t start, stop;
//	double x, pi, sumGlob = 0.0;
//	int i;
//	step = 1./(double)num_steps;
//	
//	int  threadNum = 6;
//	omp_set_num_threads(threadNum);
//	volatile double sum[6] = { 0.0 };
//
//	start = clock();
//#pragma omp parallel
//	{
//#pragma omp for
//		for (i = 0; i < num_steps; i++)
//		{
//			x = (i + .5) * step;
//			sum[omp_get_thread_num()] = sum[omp_get_thread_num()] + 4.0 / (1. + x * x);
//		}
//	}
//	for (int i = 0; i < threadNum; ++i) sumGlob += sum[i];
//	pi = sumGlob*step;
//	stop = clock();
//
//	printf("Wartosc liczby PI wynosi %15.12f\n",pi);
//	printf("Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));
//
//	return 0;
//}