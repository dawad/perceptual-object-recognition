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


using namespace cv;
using namespace std ;

class kmean
{
public:
	kmean(void);
	~kmean(void);
	Mat  select_randomly_desc(vector <vector<float>> & , int Nb_instance_random , int desc_dimension, int Nb_trunc=4);
	Mat  select_randomly_desc(std::map<std::string  ,vector<vector<float>>>& , int Nb_instance_random , int desc_dimension,int Nb_fichiers, int Nb_trunc=4);
	CvMat*  select_randomly_descs(std::map<std::string  ,vector<vector<float>>>& , int Nb_instance_random , int desc_dimension,int Nb_fichiers, int Nb_trunc=4);
	void  select_randomly_descs(CvMat* ,std::map<std::string  ,vector<vector<float>>>& , int Nb_instance_random , int desc_dimension,int Nb_fichiers, int Nb_trunc=4);
	int set_Nb_instance_random( int instance);
	int set_nb_clusters(int clusters);
	int set_desc_dimension(int dim);
	void openCv_kmean(Mat data, Mat clusters , Mat centers, int nb_clusters);
	void openCv_kmean(CvMat*  data, CvMat*  clusters , CvMat*  centers, int nb_clusters);
private :
	int Nb_instance_random;
	int nb_clusters;
	int desc_dimension;
};

