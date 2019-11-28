#pragma once
#include "../stdafx.h"
#include<iostream>
#include<fstream>
#include <cv.h>
#include <highgui.h>
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
#include "../Fichiers/arff_data/Donnees.h"
#include "../Common/bins.h"
#include "../khi-deux_kernel/khi_deux.h"
#include "../Common/roc_row.h"
#include "../Common/rate.h"
using namespace cv;
using namespace std ;

class mysvm
{
private:
	int nb_image_train_per_class;
	int nb_image_test_per_class;
	Donnees	apprentissage;
	CvSVM svms;
	Donnees test;
	//bins obj;
	//khi_deux ker;
	//roc_row lig;
	int	*confusion;
	rate row_one;
	
	
public:
	mysvm();
	~mysvm();
	mysvm(Donnees  & app, Donnees & t);
	void preparer_donnee_apprentissage(vector < vector < int >> & data_class_ref, vector < vector < int >> & outliers1_data,vector < vector < int >> &outliers2_data,vector < vector < int >> & outliers3_data, int Total_nb_clusters , int nb_image_train , CvMat* , string Class_ref );
	void preparer_donnee_apprentissage(vector < vector < int >> & data_class_ref, vector < vector < int >> & outliers1_data, CvMat* , string Class_ref );
	void preparer_donnee_apprentissage(std::vector<vector<bins>>& data_class_ref , std::vector<vector<bins>>& outliers1_data,std::vector<vector<bins>>& outliers2_data,std::vector<vector<bins>>& outliers3_data, int Total_nb_clusters , int nb_image_train , CvMat * train , string Class_ref);
	void preparer_classes(int nb_image_train,CvMat*);
	void preparer_classes(int , int ,CvMat*);
	void svm_train(CvMat* , CvMat*);
	void svm_train(CvMat* train ,CvMat* response , double gamma , double C);
	void svm_train();
	int ** creer_matrice ( int lig, int col);
	void initialiser_matrice (int **  mat,int lig, int col)
	{
		for ( int i =0 ; i <lig ; i++)
			for ( int j =0; j<col ; j++)
				mat[i][j]=0;
	}
	int **  preparer_donee_test(	vector < vector < int >> & , int begin, int end ,int Total_nb_clusters);
	void preparer_donee_test(int ** ,vector < vector < int >> & , int begin, int end ,int Total_nb_clusters);
	int **  preparer_donee_test(	vector < vector < bins >> & ,int begin, int end ,int Total_nb_clusters);
	void svm_test();
	void svm_test ( int ** data_test , int nb_images_test , int Total_nb_clusters);
	void svm_test(int ** data_test , int nb_images_test ,  int Total_nb_clusters , double * conf );
	rate  svm_test(int ** data_test , int nb_images_test , int Total_nb_clusters, double index,const string &fileName);
	rate  svm_test(int ** data_test , int nb_images_test , int Total_nb_clusters, double index);
	void  svm_test(rate &  freq ,int ** data_test , int nb_images_test , int Total_nb_clusters, double index  );
	//void fill_roc_table (vector<roc_row> & table_roc, vector < vector < int >> & ref_class_data , vector < vector < int >> & data_test_class2,  vector < vector < int >> & data_test_class3 , vector < vector < int >> & data_test_class4, int nb_image_train , int nb_image_test , int Total_nb_clusters ,double index_init , double index_end ,string Class_ref);
	//void fill_roc_table (vector<roc_row> & table_roc, vector < vector < bins >> & ref_class_data , vector < vector < bins >> & data_test_class2,  vector < vector < bins >> & data_test_class3 , vector < vector < bins >> & data_test_class4, int nb_image_train , int nb_image_test , int Total_nb_clusters ,double index_init , double index_end ,string Class_ref);
	void fill_roc_table(vector<roc_row> & table_roc, vector < vector < int >> & ref_class_data , vector < vector < int >> & data_test_class2, int begin , int Total_nb_clusters ,double index_init , double index_end ,string Class_ref);
	double Trapezoid_area(double x1, double x2, double y1, double y2);
	double calc_AUC(vector<roc_row> & table_roc );
	void Free_Tab(int**t ,int nLignes)
	{ 
    for(int i=0 ; i < nLignes ; i++)
    delete[] t[i];
     delete[] t;
   }
	
	
};

