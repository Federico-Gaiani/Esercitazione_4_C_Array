#pragma once
#include <iostream>

using namespace std;

/*
import_data legge il capitale S, la dimensione dei vettori w, r e i vettori stessi dal file data.txt
S: capitale
n: dimensione dei vettori
w: vettore con le percentuali di suddivisione del portafogli
r: vettore con i rispettivi rendimenti per w
nome_p_file: percorso del file input
aggiorna le variabili nel main, ritorna true se la lettura ha successo, false altrimenti
*/

bool import_data(double &S,	size_t &n, double * &w, double * &r, const string &nome_p_file);

/*
Prodotto_scalare fa il prodotto scalare tra due vettori, di double
n: dimensione dei vettori
w: primo vettore
r: secondo vettore
ritorna il risultato del prodotto scalare
*/

double Prodotto_scalare(const size_t& n, const double* const w, const double* const r);

/*
stampa_risultati esporta i risultati sia sul terminale sia su un file
S: capitale
n: dimensione dei vettori
w: vettore percentuali
r: vettore rendimenti
rate_of_ret: risultato prodotto scalare
nome_p_out_file: percorso file output
ritorna vero se ha successo, falso altrimenti
*/

bool stampa_risultati(const double &S,
					  const size_t &n, 
					  const double * const &w, 
					  const double * const &r, 
					  const double& rate_of_ret, 
					  const string& nome_p_out_file);

/*
Funzione implementata a esercitazione (exercise1)
ArrayToString esporta un vettore come una stringa
n: dimensione del vettore
v: vettore
ritorna la stringa 
*/

string ArrayToString(const size_t& n, const double* const& v);