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
	
	/*
	import_data inserisce delle variabili i valori presenti nel file 
	data.txt; se l'apertura del file non ha successo, viene terminato
	il main 
	*/
	
	if (!import_data(S,n,w,r,nome_p_file))
    {
        cerr<< "Import senza successo"<< endl;
        return -1;
    }
    else
        cout<< "Import avvenuto con successo"<< endl;

	/*
	Concettualmente il rate of return è il prodotto scalare tra w e r.
	Infatti nel generico w[i] c'è la percentuale di portafoglio allocata nell'investimento
	che rende r[i]. Il loro prodotto da il guadagno dato da quella percentuale di portafoglio, 
	la somma di tutte i prodotti da il guadagno totale.
	*/
	
	double rate_of_ret = Prodotto_scalare(n,w,r);
	
	/*
	Anche se si hanno problemi con il file di output il programma viene terminato
	*/
	
	if (!stampa_risultati(S,n,w,r, rate_of_ret, nome_p_out_file))
    {
        cerr<< "Export senza successo"<< endl;
        return -1;
    }
    else
        cout<< "Export avvenuto con successo"<< endl;
	
	/*
	Deallocazione della memoria allocata dinamicamente.
	*/
	
	delete[] w;
	delete[] r;
	
    return 0;
}

