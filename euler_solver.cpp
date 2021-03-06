#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "App.h"


void App::euler_solver() {

	std::vector<double> var_cur(eq_ord+2, 0); //current values of variables

	App::fill_with_initial_cond(var_cur);



	for (int i = 1; i < N; i++) {

		double last_derivative = 0;

		for (int j = 0; j < eq_ord; j++) {

			var_cur[j] = var[j][i-1] + var[j+1][i-1]*delta;


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