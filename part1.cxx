#include <iostream>
#include <cstdlib>

using namespace std;

void random(const int N, double* p){
	for(int i=0; i<N; i++)
		p[i]=rand()/double(RAND_MAX);
}

void minmax(const int N, double* p, double& min, double& max){
	for(int i=0; i<N; i++){
		if (p[i]>max)
			max=p[i];
		if (p[i]<min)
			min=p[i];
	}
}
int main(){

	srand(time(NULL));
	int N;
	cout << "N="; cin >> N;
	double* p= new double[N];
	double min=1,max=0;
	
	
	random(N,p);
	minmax(N,p,min,max);
	//for(int i=0; i<N; i++)
	//	cout << p[i] << endl;
	cout << "max=" << max << "\t" << "min=" << min << endl;
	delete[] p;
	return 0;
}
