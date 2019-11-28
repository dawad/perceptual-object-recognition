#include "stdafx.h"

#include "svm.h"

#include<iostream>
#include<fstream>
#include "cv.h"
#include "highgui.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <strsafe.h>
#include <sstream> 
#include <ml.h>
#include<iomanip>
using namespace cv;
using namespace std ;
#include "../Fichiers/arff_data/Donnees.h"

svm::svm(void)
{
	svms = CvSVM ();
}

svm::svm(Donnees & app, Donnees & t)
{
	apprentissage=app;
	test=t;
	confusion=new int[app.cols()*app.rows()];
	svms = CvSVM ();

	for (int i = 0; i < apprentissage.nbClasses()*apprentissage.nbClasses(); i++) confusion[i]=0;
}

svm::~svm(void)
{
}
// preparer les donnees pour l'appresntissage compris les donnees et les classes
void svm::preparer_donnee_apprentissage(vector < vector < int >> & histo_person , vector < vector < int >> & histo_cars,vector < vector < int >> & histo_moto,vector < vector < int >> &histo_bike, int Total_nb_clusters , int nb_image_train , CvMat * train )
{
	
	    //CvMat * train =cvCreateMat(nb_image_train*4,Total_nb_clusters,CV_32FC1);

		CvMat cars, persons,bike, motorbike;

		cvGetRows(train,&bike,0,nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&bike,i,j,histo_bike[i][j]);
		}

		cvGetRows(train,&cars,nb_image_train,nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&cars,i,j,histo_cars[i][j]);
		}

		cvGetRows(train,&persons,nb_image_train+nb_image_train,nb_image_train+nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&persons,i,j,histo_person[i][j]);
		}

		cvGetRows(train,&motorbike,nb_image_train+nb_image_train+nb_image_train,nb_image_train+nb_image_train+nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&motorbike,i,j,histo_moto[i][j]);
		}

		cout <<" les donnees d'apprentissage est pret" << endl;
}

void svm::preparer_donnee_apprentissage(std::vector<vector<bins>>& histo_person , std::vector<vector<bins>>& histo_cars,std::vector<vector<bins>>& histo_moto,std::vector<vector<bins>>& histo_bike, int Total_nb_clusters , int nb_image_train , CvMat * train)
{
	
	    //CvMat * train =cvCreateMat(nb_image_train*4,Total_nb_clusters,CV_32FC1);

		CvMat cars, persons,bike, motorbike;

		cvGetRows(train,&bike,0,nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&bike,i,j,(int)histo_bike[i][j].get_cluster_freq());
			
		}

		cvGetRows(train,&cars,nb_image_train,nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&cars,i,j,(int)histo_cars[i][j].get_cluster_freq());
		}

		cvGetRows(train,&persons,nb_image_train+nb_image_train,nb_image_train+nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&persons,i,j,(int)histo_person[i][j].get_cluster_freq());
		}

		cvGetRows(train,&motorbike,nb_image_train+nb_image_train+nb_image_train,nb_image_train+nb_image_train+nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&motorbike,i,j,(int)histo_moto[i][j].get_cluster_freq());
		}
		cout <<" les donnees d'apprentissage est pret" << endl;

}		

// preparer les classes { bike=1, cars=2,persons=3, motorbikes=4}
void svm::preparer_classes(	 int nb_image_train , CvMat * Classes)
{
		//CvMat*  response=cvCreateMat(nb_image_train*4,1,CV_32FC1);
		CvMat bike_class ,cars_class,persons_class,motorbikes_class;
		cvGetRows(Classes,&bike_class,0,nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			
		cvmSet(&bike_class,i,1,1);
		}
		cvGetRows(Classes,&cars_class,nb_image_train,nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			
		cvmSet(&cars_class,i,1,2);
		}
		cvGetRows(Classes,&persons_class,nb_image_train+nb_image_train,nb_image_train+nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			
		cvmSet(&persons_class,i,1,3);
		}
		cvGetRows(Classes,&motorbikes_class,nb_image_train+nb_image_train+nb_image_train,(nb_image_train*4));
		for(int i=0; i<nb_image_train;i++)
		{
			
				cvmSet(&motorbikes_class,i,1,4);
		}
		cout <<" les classes sont aussi prets"<<endl;
}

// appliquer l'apprentissage 
void svm::svm_train(CvMat* train ,CvMat* response )
{
	
	CvSVMParams  param  = CvSVMParams (CvSVM::C_SVC, CvSVM::KHI, 0.0, 0.00001 , 0.0, 10, 0.0, 0.0, NULL, cvTermCriteria (CV_TERMCRIT_EPS, 1000, 0.1));
	svms.train(train,response,0,0,param);
//	svms.save ("Implementation_VOCC/svm_training/train_test1.xml", 0);
	cout<<" l'apprentissage est terminee "<<endl;
}
void svm::svm_train()
{
	CvMat res_mat;
	CvMat data_mat;
	CvSVMParams param;
	CvTermCriteria criteria;
	apprentissage.getResMat(res_mat);
	apprentissage.getDataMat(data_mat);

	// FLT_EPSILON
	//	criteria = cvTermCriteria (CV_TERMCRIT_ITER | CV_TERMCRIT_EPS , 1000, 0.1 );
	criteria = cvTermCriteria (CV_TERMCRIT_EPS , 1000, 0.1 );
	// CvSVMParams( int _svm_type, int _kernel_type, double _degree, double _gamma, double _coef0, double Cvalue, double _nu, double _p, CvMat* _class_weights, CvTermCriteria _term_crit );
	param = CvSVMParams (CvSVM::C_SVC, CvSVM::POLY, 2.0, .01, 0., 1.0, 0.5, 0.1, NULL, criteria);

	svms.train(&data_mat, &res_mat, NULL, NULL, param);
}



double** svm::creer_matrice (int lig, int col)
{
   int i, j;
   double **mat = (double**) malloc(lig * sizeof(double*));
   for (i = 0; i < lig; i++){
     mat[i] = (double*)malloc(col * sizeof(double));
     for(j = 0; j < col; j++)
       mat[i][j] = lig * i + j; // une initialisation comme une autre
   }
   return mat;
} 
// preparation du donnee du test 
double ** svm::preparer_donee_test(vector < vector < int >> & histog, int begin, int end ,int Total_nb_clusters)
{
	int row = histog.size();
	int cols=1000;
	double ** data_test=creer_matrice(row,cols);
	for(int i=begin;i<end ;i++)
	{
	 for(int j=0;j<cols;j++)
	 {
		data_test[i-begin][j]=histog[i][j];
		
	 }
	}
	cout <<" les donnees du test est pret" << endl;
	
	return data_test;

}

double ** svm::preparer_donee_test(vector < vector < bins >> & histog, int begin, int end ,int Total_nb_clusters)
{
	int row = histog.size();
	int cols=1000;
	double ** data_test=creer_matrice(row,cols);
	for(int i=begin;i<end ;i++)
	{
	 for(int j=0;j<cols;j++)
	 {
		data_test[i-begin][j]=histog[i][j].get_cluster_freq();
		
	 }
	}
	cout <<" les donnees du test est pret" << endl;
	
	return data_test;

}

// appliquer le test de svm  et calculer la matrice de confusion 
void svm::svm_test(double ** data_test , int nb_images_test , int Total_nb_clusters )
{
	

	cout << "bike=1, cars=2,persons=3, motorbikes=4"<<endl;
		float _sample [1][1000];
		float resp ;
	     double count1=0, count2=0, count3=0, count4=0;
		for (int i=0; i<nb_images_test ;i++)
		{
			

			 for (int j=0;j<Total_nb_clusters;j++)
               _sample [0][j] =data_test[i][j];


			CvMat test=cvMat(1,Total_nb_clusters,CV_32FC1,_sample);

			resp=svms.predict(&test);
			
	
			switch ((int)resp)
			{
			case 1 :
				{
				 count1=count1+1;
				 break;
				}
			case 2:
				{
				count2=count2+1;
				break;
				}
			case 3:
				{				
				count3++;
				break;
				}
			case 4:
				{				
				count4++;
				}
			}

		}
		cout <<" la test est finie " <<endl;
		cout <<" matrice de confusion :"<<endl<<endl;
		cout << "Bicyclette "<< " " << "Voiture " << "   " << "Person " << "   " << "Motorbikes "<< ""<<endl;
		cout <<fixed<<setprecision(2)<< (count1/nb_images_test)*100 <<"%"<< "       "<<(count2/nb_images_test)*100 <<"%"<< "       "<<(count3/nb_images_test)*100 <<"%"<< "       "<<(count4/nb_images_test)*100 <<"%"<< "        " <<endl;

		
		
}



void svm::svm_test()
{
	CvMat m;

	std::vector<float> vec = test.getVectors();
	std::cout << "Tester " << test.rows() << std::endl;

	for (int i = 0; i < test.rows(); i++) {

		float ret = 0.0;
		const int colonne=test.cols();
		float * a= new float [colonne ];

		for(int j=0;j<test.cols();j++)
		{
			a[j]=(vec[j+i*test.cols()]);
		}

		cvInitMatHeader (&m, 1, test.cols(), CV_32FC1, a);
		ret = svms.predict (&m);

		confusion[(int)(ret-1)+(int)((apprentissage.getClasseNumbers()[i]-1)*apprentissage.nbClasses())]++;
	}
	std::cout << std::endl;

}