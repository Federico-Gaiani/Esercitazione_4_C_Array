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

bool stampa_risultati(double &S,	size_t &n, double * &w, double * &r){
	// Export terminale
	cout<<"S = "<<setprecision(2)<<S<<", n = "<<n<<endl;
	cout<<"w = "<<ArrayToString(n,w)<<endl;
	cout<<"r = "<<ArrayToString(n,r)<<endl;
	
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