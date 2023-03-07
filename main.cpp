#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstring>
#include <omp.h>

#include "model.h"

using namespace std;


int main(int argc, char* argv[])    {
	srand(time(NULL));

	cout<< "Hello World !\0"<< endl;
	cout<< " "<< endl;


	// default values
	string name = "simu";
	int N = 1000;
	int L = 100000;
	int nbsite = 400;
	int indPrdm9 = 5;
	int nballele = 1;
	int parityIndex = 0;
    double u = 1e-4;
    double v = 1e-4;
	double w = 1e-3;
	double meanaff = 0.6;
	double varaff = 1;
	int nbDSB = 6;
	int nbGenerations = 10000;
	bool ismigration = false;
	bool zygosity = false;
	bool withDSB = false;
	int everygen = 10;
	double m = 0.1;
	double alpha = 0.5;
	double beta = 0.5;
	int nbgenmig = -1;
	int popsamesize = true;
	int nbloop = 1000;
	int nbcore = 4;
	bool isallele = true;
	bool issampling = true;
	bool isanalytic = true;
	double ctot = 1600;
	bool targetcomp = false;
	int quantilenb = 0;
	int nbmeiperind = 1;
	double cfreethreshold = 0.001;
	bool affinityUniform = 0;
	

	int i=1;
    while (i < argc)    {
    	string s = argv[i];

		if (s == "-N") {
        	i++;
            N = atoi(argv[i]);
        }
        else if (s == "-L") {
        	i++;
            L = atoi(argv[i]);
        }
        else if (s == "-nbsite") {
        	i++;
            nbsite = atoi(argv[i]);
        }
        else if (s == "-indPrdm9") {
        	i++;
            indPrdm9 = atoi(argv[i]);
        }
        else if (s == "-nballele") {
        	i++;
            nballele = atoi(argv[i]);
        }
        else if (s == "-parityIndex") {
        	i++;
            parityIndex = atoi(argv[i]);
        }
        else if (s == "-u")  {
        	i++;
            u = atof(argv[i]);
        }
        else if (s == "-v")  {
        	i++;
            v = atof(argv[i]);
        }
        else if (s == "-w") {
        	i++;
            w = atof(argv[i]);
        }
        else if (s == "-meanaff") {
        	i++;
            meanaff = atof(argv[i]);
        }
        else if (s == "-varaff") {
        	i++;
            varaff = atof(argv[i]);
        }
        else if (s == "-nbDSB") {
        	i++;
            nbDSB = atoi(argv[i]);
        }
        else if (s == "-nbGenerations") {
        	i++;
            nbGenerations = atoi(argv[i]);
        }
        else if (s == "-ismigration") {
        	i++;
            ismigration = atoi(argv[i]);
        }
        else if (s == "-zygosity") {
        	i++;
            zygosity = atoi(argv[i]);
        }
        else if (s == "-withDSB") {
        	i++;
            withDSB = atoi(argv[i]);
        }
        else if (s == "-everygen") {
        	i++;
            everygen = atoi(argv[i]);
        }
		else if (s == "-m") {
        	i++;
            m = atof(argv[i]);
        }
		else if (s == "-alpha") {
        	i++;
            alpha = atof(argv[i]);
        }
		else if (s == "-beta") {
        	i++;
            beta = atof(argv[i]);
        }
		else if (s == "-nbgenmig") {
        	i++;
            nbgenmig = atoi(argv[i]);
        }
		else if (s == "-popsamesize") {
        	i++;
            popsamesize = atoi(argv[i]);
        }
        else if (s == "-nbloop"){
			i++;
			nbloop = atoi(argv[i]);
		}
		else if (s == "-nbcore"){
			i++;
			nbcore = atoi(argv[i]);
		}
		else if (s == "-isallele"){
			i++;
			isallele = atoi(argv[i]);
		}
		else if (s == "-issampling"){
			i++;
			issampling = atoi(argv[i]);
		}
		else if (s == "-isanalytic"){
			i++;
			isanalytic = atoi(argv[i]);
		}
		else if (s == "-ctot"){
			i++;
			ctot = atoi(argv[i]);
		}
		else if (s == "-targetcomp"){
			i++;
			targetcomp = atoi(argv[i]);
		}
		else if (s == "-quantilenb"){
			i++;
			quantilenb = atoi(argv[i]);
		}
		else if (s == "-nbmeiperind"){
			i++;
			nbmeiperind = atoi(argv[i]);
		}
		else if (s == "-cfreethreshold"){
			i++;
			cfreethreshold = atoi(argv[i]);
		}
		else if (s == "-affinityUniform"){
			i++;
			affinityUniform = atoi(argv[i]);
		}
        else {
        	// name of the run (name will be followed by extensions: <name>.general…);
            name = argv[i];
        }
        i++;
	}
	
	
	float temps1, temps2;
	clock_t t1, t2, t3;
	
	t1=clock();
	
	cout<< "Model constructor" <<endl;
	Model model1(N, L, nbsite, indPrdm9, nballele, parityIndex, v, u, w, meanaff, varaff, nbDSB, nbGenerations, ismigration, zygosity, withDSB, everygen, m, alpha, beta, nbgenmig, popsamesize, nbloop, nbcore, isallele, issampling, isanalytic, ctot, targetcomp, quantilenb, nbmeiperind, cfreethreshold, affinityUniform, name);
	
	t2=clock();
	temps1=(float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps1 = %f\n", temps1);
	
	
	
	model1.manygenerations();
	

	
	t3=clock();
	temps2=(float)(t3-t2)/CLOCKS_PER_SEC;
	printf("temps2 = %f\n", temps2);
	

	

return 0;
}

