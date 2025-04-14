#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool import_data(double &S,	size_t &n, double * &w, double * &r, const string &nome_p_file){
	
	// apertura file
	ifstream file;
    file.open(nome_p_file);

    if (file.fail())
    {
        cerr<< "Errore nell'apertura del file input"<< endl;
        return false;
    }
	
	// uso uno stringstream per operare sulle righe del file
	stringstream ss;
	string line;
	string daIgnorare;
	
	//Prima riga file
	getline(file, line);
	ss.str(line);
    getline(ss, daIgnorare, ';');
	
	//dentro la string "daIgnorare" sinisce il nome della variabile
	// cout<<"_______________Da ignorare: "<<daIgnorare<<endl;

    ss >> S;
	ss.clear();
	
	//Seconda riga file
	getline(file, line);
	ss.str(line);
    getline(ss, daIgnorare, ';');

    ss >> n;
	
	//Terza riga file: non contiene informazioni utili da memorizzare
	getline(file, daIgnorare);
	
	//Lettura dei vettori
	
	char delimiter;
	
	w=new double[n];
	r=new double[n];
	
	// posso usare l'operatore >>, perchè riconoscerà il primo double, quindi il delimitatore e infine il secondo double
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
	
	// chiusura file
    file.close();
	
	return true;
}

double Prodotto_scalare(const size_t& n, const double* const w, const double* const r){
	double prod_scalare=0.0;
	for (unsigned int i =0; i<n; i++){
		prod_scalare+=w[i]*r[i];
	}
	
	return prod_scalare;
}



bool stampa_risultati(const double &S,
					  const size_t &n,
					  const double * const &w, 
					  const double * const &r, 
					  const double& rate_of_ret, 
					  const string& nome_p_out_file){
	double V = S+(S*rate_of_ret);
	// Export su terminale
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
        cerr<< "Apertura file output non riuscita"<< endl;
        return false;
    }
	file << fixed << setprecision(2);
	file <<"S = "<<S<<", n = "<<n<<endl;
	file <<"w = "<<ArrayToString(n,w)<<endl;
	file <<"r = "<<ArrayToString(n,r)<<endl;
	file <<"Rate of return of the portfolio: "<<setprecision(4)<<rate_of_ret<<endl;
	file <<"V: "<<setprecision(2)<<V<<endl;
	
	// chiusura file
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