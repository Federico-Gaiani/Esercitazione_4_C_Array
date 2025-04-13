#pragma once
#include <iostream>

using namespace std;

void import_data(double &S,	size_t &n, double * &w, double * &r, const string &nome_p_file);

double Prodotto_scalare(const size_t& n, const double* const w, const double* const r);

bool stampa_risultati(double &S,	size_t &n, double * &w, double * &r, double& rate_of_ret, const string& nome_p_out_file);

string ArrayToString(const size_t& n, const double* const& v);