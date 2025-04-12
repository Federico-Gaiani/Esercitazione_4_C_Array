#pragma once
#include <iostream>

using namespace std;

void import_data(double &S,	size_t &n, double * &w, double * &r, const string &nome_p_file);

bool stampa_risultati(double &S,	size_t &n, double * &w, double * &r);

string ArrayToString(const size_t& n, const double* const& v);