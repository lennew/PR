//#include <stdio.h>
//#include <omp.h>
//
//
//int main() {
//	omp_set_num_threads(3);
//	int i;
//	int a = 0, b = 0;
//#pragma omp parallel
//	{
//		printf("Hello World\n");
//
//		for(i=0;i<4;i++) {
//			printf("Iter:%d ID:%d\n", i, omp_get_thread_num());
//		}
//		printf("GoodBye World\n");
//	}
//	printf("a:%d", a);
//}