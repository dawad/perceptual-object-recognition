#pragma once
#include "../stdafx.h"
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
#include "../Fichiers/arff_data/Donnees.h"
#include "../Common/bins.h"

using namespace cv;
using namespace std ;
class svm
{
private:
	int nb_image_train_per_class;
	int nb_image_test_per_class;
	Donnees	apprentissage;
	CvSVM svms;
	Donnees test;
	int	*confusion;
	
	
public:
	svm(void);
	~svm(void);
	svm(Donnees  & app, Donnees & t);
	void preparer_donnee_apprentissage(vector < vector < int >> & class1, vector < vector < int >> & class2,vector < vector < int >> &class3,vector < vector < int >> & class4, int Total_nb_clusters , int nb_image_train , CvMat* );
	void preparer_donnee_apprentissage(vector < vector < bins >> & class1, vector < vector < bins >> & class2,vector < vector < bins >> &class3,vector < vector < bins >> & class4, int Total_nb_clusters , int nb_image_train , CvMat* );
	void preparer_classes(int nb_image_train,CvMat*);
	void svm_train(CvMat* , CvMat*);
	void svm_train();
	double ** creer_matrice ( int lig, int col);
	double **  preparer_donee_test(	vector < vector < int >> & , int begin, int end ,int Total_nb_clusters);
	double **  preparer_donee_test(	vector < vector < bins >> & ,int begin, int end ,int Total_nb_clusters);
	void svm_test ( double ** data_test , int nb_images_test , int Total_nb_clusters);
	void svm_test();
	
};

