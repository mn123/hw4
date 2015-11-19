#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void read(const int N, double* p, const string ifname);
void filter(const int N, double* p, double x, double y, double z);
void write(const int N, double* p, const string ofname);


int main(){

	const string inputfile="noisy.txt";
	const string outputfile="filtered.txt";
	const int N=237; //Zahl der Zeilen
	int M; //Anzahl der Filteranwendungen
	double x,y,z;
	double* p = new double[N];	

	cout << "Bitte geben Sie die Zahl der Filteranwendungen ein: "; cin >> M;

	read(N,p,inputfile);
	for (int i=0; i<M; i++)
		filter(N,p,x,y,z);
	write(N,p,outputfile);

	delete[] p;
	return 0;
}


void read(const int N, double* p, const string ifname){
	ifstream in(ifname.c_str());
	for (int i=0; i<N; i++)
		in >> p[i];
	in.close();
}

void filter(const int N, double* p, double x, double y, double z){
	z=p[0];
	x=p[0];
	p[0]=(p[N-1]+p[0]+p[1])/3;
	for(int i=1; i<(N-1); i++){
		y=p[i];
		p[i]=(x+p[i]+p[i+1])/3;
		x=y;	
	}
	p[N-1]=(x+p[N-1]+z)/3;
}

void write(const int N, double* p, const string ofname){
	ofstream out(ofname.c_str());
	for (int i=0; i<N; i++)
		out << p[i] << endl;
}
