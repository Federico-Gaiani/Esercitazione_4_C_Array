#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"
using namespace std;


int main()
{
	double S;
	size_t n=0;
	double * w=nullptr;
	double * r=nullptr;
	
	string nome_p_file = "./data.txt";
	
	
	
	
	import_data(S,n,w,r,nome_p_file);
	
	cout<<S<<endl;
	cout<<n<<endl;
	
	//cout<<w<<endl;
	//cout<<*r<<endl;
	stampa_risultati(S,n,w,r);
	
    return 0;
}

