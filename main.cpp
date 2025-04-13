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
	string nome_p_out_file = "./result.txt";
	
	
	
	
	import_data(S,n,w,r,nome_p_file);
	
	
	double rate_of_ret = Prodotto_scalare(n,w,r);
	
	//cout<<w<<endl;
	//cout<<*r<<endl;
	stampa_risultati(S,n,w,r, rate_of_ret, nome_p_out_file);
	
    return 0;
}

