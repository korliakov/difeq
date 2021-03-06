#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "App.h"

void App::rk4_solver() {

	std::vector<double> var_cur(eq_ord+2, 0);
	std::vector<double> k1(eq_ord+2, 0);
	std::vector<double> k2(eq_ord+2, 0);
	std::vector<double> k3(eq_ord+2, 0);
	std::vector<double> k4(eq_ord+2, 0);



	fill_with_initial_cond(var_cur);

	for (int i = 1; i < N; i++) {
		double last_derivative = 0;

		for (int j = 0; j < eq_ord; j++) {

			k1[j] = var[j+1][i-1];

			last_derivative -= var[j][i-1] * (coefs[j]/coefs[eq_ord]);

		}
		k1[eq_ord-1] = last_derivative;

		last_derivative = 0;

		for (int j = 0; j < eq_ord; j++) {

			k2[j] = (var[j+1][i-1] + 0.5*delta*k1[j+1]);

			last_derivative -= (var[j][i-1] + 0.5*delta*k1[j]) * (coefs[j]/coefs[eq_ord]);

		}
		k2[eq_ord-1] = last_derivative;

		last_derivative = 0;

		for (int j = 0; j < eq_ord; j++) {

			k3[j] = (var[j+1][i-1] + 0.5*delta*k2[j+1]);

			last_derivative -= (var[j][i-1] + 0.5*delta*k2[j]) * (coefs[j]/coefs[eq_ord]);

		}
		k3[eq_ord-1] = last_derivative;

		last_derivative = 0;

		for (int j = 0; j < eq_ord; j++) {

			k4[j] = (var[j+1][i-1] + delta*k3[j+1]);

			last_derivative -= (var[j][i-1] + delta*k3[j]) * (coefs[j]/coefs[eq_ord]);

		}
		k4[eq_ord-1] = last_derivative;

		last_derivative = 0;
		for (int j = 0; j < eq_ord; j++) {
			var_cur[j] = var[j][i-1] + delta*(k1[j] + 2*k2[j] + 2*k3[j] + k4[j])/6;
			last_derivative -= var_cur[j] * (coefs[j]/coefs[eq_ord]);

		}

		var_cur[eq_ord] = last_derivative;
		var_cur[eq_ord + 1] += delta;

		for (int k = 0; k <= eq_ord+1; k++) {

			var[k][i] = var_cur[k];
		}

		var_cur.resize(0); //deleting all values


	}








}