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
#include "../Common/nearest_clusters.h"
#include"../Common/bins.h"
#include "../Common/word.h"
#include"../Common/mot.h"
using namespace cv;
using namespace std ;

class histograms
{
private:
	
	
	
void remplir_Cluster_center ( Mat centers_Class , vector<vector <float>> & keypoint);
public:
	
	
	histograms(void);
	~histograms(void);
	float get_last_element(vector<vector<float>>& descripteurs);
	void sort_descripteurs ( vector<vector<float>> & descripteur);
	void Calculer_min_distance(vector<vector<float>> & keyppoints , vector<vector <float>> & descriptors , vector <word> &,int total_nb_clusters,int Nb_trunc=4);
	void Calculer_min_distance(vector<vector<float>> & keyppoints , std::map< std::string  ,vector<vector<float>>>& , std::map<std::string,vector<mot>> &,int ,int Nb_trunc=4);
	void Calculer_min_distance(vector<vector<float>> & keyppoints , vector<vector <float>> & descriptors , vector <mot> &,int total_nb_clusters,int Nb_trunc=4);
	void build_histogram(vector<word> & , int img_id , vector<bins> & , int total_nb_clusters);
	void build_histogram(vector<mot> & ,  vector<bins> & , int total_nb_clusters);
	void build_histograms(std::map<std::string,vector<mot>> & , std::map<std::string,vector<bins>> & , int total_nb_clusters);
	void get_all_histograms ( vector <vector<bins>> &  , float ,vector<word> & ,int );
	nearest_clusters plus_proche_clusters( float distances []  , int size);
	void concatenate_clusters_centers( Mat centers_cars , Mat centers_perso , Mat centers_bike , Mat centers_moto , vector<vector <float>> &);
	
	
};

