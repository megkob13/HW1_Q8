#include <iostream>
#include <vector>


using namespace std;

// AERSP 424 Homework 1: Question 8
// Goal: Create classifier software.

double z = 0;//initialize variable z
double sigma = 0; //initialize variable sigma
double sigmaprime = 0; //initialize variable sigmaprime
double y_predict = 0; //initialize variable y_predict
double dC = 0; //initialize variable
double alpha = .001; //assign given value
int y = 0; //initialize variable

vector<double> gradient_weights(vector<double>&, vector<double>&, double);//function prototype for gradient_weights
vector<double> update_weights(vector <double>&, vector <double>&, double); //function prototype for update_weights

int main()
{
	//initialize w
	vector<double> w = { .0001,.0001,.0001 };

	//assign values to vector elements for each aircraft
	vector<double> x_M346Master = { 124.00,31.89,20.945 };
	vector<double> x_AT402B = { 74.00,51.08,9.170 };
	vector<double> x_MB326 = { 103.00, 34.67, 8.300 };
	vector<double> x_AT502B = { 77.00,52.00,9.4 };
	vector<double> x_MB339 = { 104.00,35.63,13.00 };
	vector<double> x_AT602 = { 92.00,56.00,12.5 };
	vector<double> x_AeroL159Alca = { 130.00,31.29,17.637 };
	vector<double> x_AT504 = { 73.00,52.00,9.6 };

	//assign engine type values to each aircraft
	double y_M346Master = 1;
	double y_AT402B = 0;
	double y_MB326 = 1;
	double y_AT502B = 0;
	double y_MB339 = 1;
	double y_AT602 = 0;
	double y_AeroL159Alca = 1;
	double y_AT504 = 0;

	//initialize dw vectors for each aircraft
	vector<double> dw_M346Master = { 0,0,0 };
	vector<double> dw_AT402B = { 0,0,0 };
	vector<double> dw_MB326 = { 0,0,0 };
	vector<double> dw_AT502B = { 0,0,0 };
	vector<double> dw_MB339 = { 0,0,0 };
	vector<double> dw_AT602 = { 0,0,0 };
	vector<double> dw_AeroL159Alca = { 0,0,0 };
	vector<double> dw_AT504 = { 0,0,0 };

	//initialize updated w vector
	vector<double> w_updated = { 1,1,1 };

	//calculate all dw and updated w for each aircraft
	for (int i = 0; i < 101; i++)
	{
		{
			dw_M346Master = gradient_weights(w, x_M346Master, y_M346Master);
			w_updated = update_weights(dw_M346Master, w, alpha);
		}

		{
			dw_AT402B = gradient_weights(w, x_AT402B, y_AT402B);
			w_updated = update_weights(dw_AT402B, w, alpha);
		}

		{
			dw_MB326 = gradient_weights(w, x_MB326, y_MB326);
			w_updated = update_weights(dw_MB326, w, alpha);
		}

		{
			dw_AT502B = gradient_weights(w, x_AT502B, y_AT502B);
			w_updated = update_weights(dw_AT502B, w, alpha);
		}

		{
			dw_MB339 = gradient_weights(w, x_MB339, y_MB339);
			w_updated = update_weights(dw_MB339, w, alpha);
		}

		{
			dw_AT602 = gradient_weights(w, x_AT602, y_AT602);
			w_updated = update_weights(dw_AT602, w, alpha);
		}

		{
			dw_AeroL159Alca = gradient_weights(w, x_AeroL159Alca, y_AeroL159Alca);
			w_updated = update_weights(dw_AeroL159Alca, w, alpha);
		}

		{
			dw_AT504 = gradient_weights(w, x_AT504, y_AT504);
			w_updated = update_weights(dw_AT504, w, alpha);
		}
	}

	//Print calculated w value
	cout << "Updated w: " << endl;
	for (int i = 0; i < w.size(); i++)
	{
		cout << "w[" << i << "] = " << w[i] << endl; //prints individual elements of vector
	}

	//For loops to print values in each element of w and dw vectors for M-346 Master
	cout << "M-346 Master:" << endl;
	for (int i = 0; i < dw_M346Master.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_M346Master[i] << endl; //prints individual elements of vector
	}

	//For loops to print values in each element of w and dw vectors for AT-402B
	cout << "AT-402B:" << endl;
	for (int i = 0; i < dw_AT402B.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_AT402B[i] << endl; //prints individual elements of vector
	}


	//For loops to print values in each element of w and dw vectors for MB-326
	cout << "MB-326:" << endl;
	for (int i = 0; i < dw_MB326.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_MB326[i] << endl; //prints individual elements of vector
	}


	//For loops to print values in each element of w and dw vectors for AT-502B
	cout << "AT-502B:" << endl;
	for (int i = 0; i < dw_AT502B.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_AT502B[i] << endl; //prints individual elements of vector
	}


	//For loops to print values in each element of w and dw vectors for MB-339
	cout << "MB-339:" << endl;
	for (int i = 0; i < dw_MB339.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_MB339[i] << endl; //prints individual elements of vector
	}


	//For loops to print values in each element of w and dw vectors for AT-602
	cout << "AT-602:" << endl;
	for (int i = 0; i < dw_AT602.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_AT602[i] << endl; //prints individual elements of vector
	}

	//For loops to print values in each element of w and dw vectors for Aero L-159 Alca
	cout << "Aero L-159 Alca:" << endl;
	for (int i = 0; i < dw_AeroL159Alca.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_AeroL159Alca[i] << endl; //prints individual elements of vector
	}

	//For loops to print values in each element of w and dw vectors for AT-504
	cout << "AT-504:" << endl;
	for (int i = 0; i < dw_AT504.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw_AT504[i] << endl; //prints individual elements of vector
	}

	return 0;
}
