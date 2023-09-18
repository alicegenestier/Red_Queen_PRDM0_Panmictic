//==============//
//   Includes   //
//==============//


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

//===============//
//   Main code   //
//===============//

int main(int argc, char* argv[])    {
	srand(time(NULL));

	cout<< "Hello World !\0"<< endl;
	cout<< " "<< endl;


	// default values
	string name = "simu"; // name of the files
	int N = 1000; // effective population size
	int L = 100000; // size of the genome
	int nbsite = 400; // number of sites for each new allele
	int indPrdm9 = 5; // index of the site of the prdm9 gene
	int nballele = 1; // nb of alleles in the pop since the begining
	int parityIndex = 0; // index corresponding to the current population
    double u = 1e-4; //prdm9 mutation rate
    double v = 1e-4; // target mutation rate
	double w = 1e-3; //neutral site mutation rate
	double meanaff = 0.6; //mean gamma law 
	double varaff = 1; // variance gamma law
	int nbDSB = 6; //nb of DSB
	int nbGenerations = 10000; //nb of generations
	bool ismigration = false; //is there migration
	bool zygosity = false; //make difference between heterozygots and homozygots
	bool withDSB = false; //do we take into account the 2 DSB at one site as a cause of failed meiosis
	int everygen = 10; //nb of generation at which we want to print the results in the files
	double m = 0; // migration rate
	double alpha = 0.5; //first param of the beta distribution
	double beta = 0.5; //second param of the beta distribution
	int nbgenmig = -1; //nb of the generation at which we want to split de pop for migration (if = 0 => begin directly with 2 pop)
	int popsamesize = true; //two pop for migration has the same size of the initial pop or devided by two
	int nbhyb = 1000; //nb loop for indep q and fertility
	int nbcore = 1;  //nb core for open mp
	bool isallele = true;  //do we want the result for each allele
	bool issampling = true;  //do we want the result from the sampling
	bool isanalytic = true;  //do we want the analytical results
	double ctot = 1600;  //total concentration for 1 PRDM9 allele in heterozygot
	bool targetcomp = false;  //If we want to take into account target competition
	int quantilenb = 0;  //number of categories for the affinity distribution
	int nbmeiperind = 1; //number of meiosis that an individual can perform before being caracterizes as steril
	double cfreethreshold = 0.001; //threshold for the determination of cfree
	double dosagecoeff = 2; //dosage coefficient
	bool COasym = 0; //CO allows at asymetrcal sites
	
	
	int i=1;
    while (i < argc)    
    {
    	string s = argv[i];

		if (s == "-N") 
		{ // effective population size
        	i++;
            N = atoi(argv[i]);
        }
        else if (s == "-L") 
        { // size of the genome
        	i++;
            L = atoi(argv[i]);
        }
        else if (s == "-nbsite") 
        { // number of sites for each new allele
        	i++;
            nbsite = atoi(argv[i]);
        }
        else if (s == "-indPrdm9") 
        { // index of the site of the prdm9 gene
        	i++;
            indPrdm9 = atoi(argv[i]);
        }
        else if (s == "-nballele") 
        { // nb of alleles in the pop since the begining
        	i++;
            nballele = atoi(argv[i]);
        }
        else if (s == "-parityIndex") 
        { // index corresponding to the current population
        	i++;
            parityIndex = atoi(argv[i]);
        }
        else if (s == "-u")  
        { //prdm9 mutation rate
        	i++;
            u = atof(argv[i]);
        }
        else if (s == "-v")  
        { // target mutation rate
        	i++;
            v = atof(argv[i]);
        }
        else if (s == "-w") 
        { //neutral site mutation rate
        	i++;
            w = atof(argv[i]);
        }
        else if (s == "-meanaff") 
        { //mean gamma law 
        	i++;
            meanaff = atof(argv[i]);
        }
        else if (s == "-varaff") 
        { // variance gamma law
        	i++;
            varaff = atof(argv[i]);
        }
        else if (s == "-nbDSB") 
        { //nb of DSB
        	i++;
            nbDSB = atoi(argv[i]);
        }
        else if (s == "-nbGenerations") 
        { //nb of generations
        	i++;
            nbGenerations = atoi(argv[i]);
        }
        else if (s == "-ismigration") 
        { //is there migration
        	i++;
            ismigration = atoi(argv[i]);
        }
        else if (s == "-zygosity") 
        { //make difference between heterozygots and homozygots
        	i++;
            zygosity = atoi(argv[i]);
        }
        else if (s == "-withDSB") 
        { //do we take into account the 2 DSB at one site as a cause of failed meiosis
        	i++;
            withDSB = atoi(argv[i]);
        }
        else if (s == "-everygen") 
        { //nb of generation at which we want to print the results in the files
        	i++;
            everygen = atoi(argv[i]);
        }
		else if (s == "-m") 
		{ // migration rate
        	i++;
            m = atof(argv[i]);
        }
		else if (s == "-alpha") 
		{ //first param of the beta distribution
        	i++;
            alpha = atof(argv[i]);
        }
		else if (s == "-beta") 
		{ //second param of the beta distribution
        	i++;
            beta = atof(argv[i]);
        }
		else if (s == "-nbgenmig") 
		{ //nb of the generation at which we want to split de pop for migration (if = 0 => begin directly with 2 pop)
        	i++;
            nbgenmig = atoi(argv[i]);
        }
		else if (s == "-popsamesize") 
		{ //two pop for migration has the same size of the initial pop or devided by two
        	i++;
            popsamesize = atoi(argv[i]);
        }
        else if (s == "-nbhyb")
        { // number of hybrid
			i++;
			nbhyb = atoi(argv[i]);
		}
		else if (s == "-nbcore")
		{ //nb core for open mp
			i++;
			nbcore = atoi(argv[i]);
		}
		else if (s == "-isallele")
		{ //do we want the result for each allele
			i++;
			isallele = atoi(argv[i]);
		}
		else if (s == "-issampling")
		{ //do we want the result from the sampling
			i++;
			issampling = atoi(argv[i]);
		}
		else if (s == "-isanalytic")
		{ //do we want the analytical results
			i++;
			isanalytic = atoi(argv[i]);
		}
		else if (s == "-ctot")
		{ //total concentration for 1 PRDM9 allele in heterozygot
			i++;
			ctot = atof(argv[i]);
		}
		else if (s == "-targetcomp")
		{ //If we want to take into account target competition
			i++;
			targetcomp = atoi(argv[i]);
		}
		else if (s == "-quantilenb")
		{ //number of categories for the affinity distribution
			i++;
			quantilenb = atoi(argv[i]);
		}
		else if (s == "-nbmeiperind")
		{ //number of meiosis that an individual can perform before being caracterizes as sterile
			i++;
			nbmeiperind = atoi(argv[i]);
		}
		else if (s == "-cfreethreshold")
		{ //threshold for the determination of cfree
			i++;
			cfreethreshold = atof(argv[i]);
		}
		else if (s == "-dosagecoeff")
		{ //dosage coefficient
			i++;
			dosagecoeff = atof(argv[i]);
		}
		else if (s == "-COasym")
		{ //CO allows at asymetrcal sites
			i++;
			COasym = atoi(argv[i]);
		}
        else 
        {
        	// name of the run (name will be followed by extensions: <name>.general…);
            name = argv[i];
        }
        i++;
	}
	
	float temps1, temps2;
	clock_t t1, t2, t3;
	
	t1=clock();
	
	cout<< "Test for Model constructor" <<endl;
	Model model1(N, L, nbsite, indPrdm9, nballele, parityIndex, v, u, w, meanaff, varaff, nbDSB, nbGenerations, ismigration, zygosity, withDSB, everygen, m, alpha, beta, nbgenmig, popsamesize, nbhyb, nbcore, isallele, issampling, isanalytic, ctot, targetcomp, quantilenb, nbmeiperind, cfreethreshold, dosagecoeff, COasym, name);
	
	t2=clock();
	temps1=(float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps1 = %f\n", temps1);
	
	
	// performs the model
	model1.manygenerations();
	

	
	t3=clock();
	temps2=(float)(t3-t2)/CLOCKS_PER_SEC;
	printf("temps2 = %f\n", temps2);
	

	

return 0;
}

