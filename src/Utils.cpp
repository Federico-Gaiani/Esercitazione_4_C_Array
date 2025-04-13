#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

void import_data(double &S,	size_t &n, double * &w, double * &r, const string &nome_p_file){
	ifstream file;
    file.open(nome_p_file);

    if (file.fail())
    {
        cerr<< "Errore nell'apertura del file"<< endl;
        //return false;
    }
	
	
	stringstream ss;
	string line;
	string daIgnorare;
	
	getline(file, line);
	ss.str(line);
    getline(ss, daIgnorare, ';');

    ss >> S;
	ss.clear();
	getline(file, line);
	ss.str(line);
    getline(ss, daIgnorare, ';');

    ss >> n;
	
	getline(file, daIgnorare);
	
	char delimiter;
	
	w=new double[n];
	r=new double[n];
	
	
	for (unsigned int i=0; i<n;i++){
		std::getline(file, line); 
		ss.clear();
		ss.str(line);
		ss >> w[i]; 
		//cout<<"w[i]: "<<w[i]<<endl; 
		ss >> delimiter; 
		ss >> r[i];
		//cout<<"r[i]: "<<r[i]<<endl; 
	}
	
}

double Prodotto_scalare(const size_t& n, const double* const w, const double* const r){
	double prod_scalare=0.0;
	for (unsigned int i =0; i<n; i++){
		prod_scalare+=w[i]*r[i];
	}
	
	return prod_scalare;
}



bool stampa_risultati(double &S,	size_t &n, double * &w, double * &r, double& rate_of_ret, const string& nome_p_out_file){
	double V = S+(S*rate_of_ret);
	// Export terminale
	cout << fixed << setprecision(2);
	cout<<"S = "<<S<<", n = "<<n<<endl;
	cout<<"w = "<<ArrayToString(n,w)<<endl;
	cout<<"r = "<<ArrayToString(n,r)<<endl;
	cout<<"Rate of return of the portfolio: "<<setprecision(4)<<rate_of_ret<<endl;
	cout<<"V: "<<setprecision(2)<<V<<endl;
	
	// Export su file
	ofstream file;
    file.open(nome_p_out_file);

    if (file.fail())
    {
        cerr<< "apertura file output non riuscita"<< endl;
        return false;
    }
	file << fixed << setprecision(2);
	file <<"S = "<<S<<", n = "<<n<<endl;
	file <<"w = "<<ArrayToString(n,w)<<endl;
	file <<"r = "<<ArrayToString(n,r)<<endl;
	file <<"Rate of return of the portfolio: "<<setprecision(4)<<rate_of_ret<<endl;
	file <<"V: "<<setprecision(2)<<V<<endl;
	
	// Close File
    file.close();
	
	return true;
}

string ArrayToString(const size_t& n, const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}