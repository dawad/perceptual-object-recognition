
#include "stdafx.h"
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
#include "histograms.h"
#include "../Common/nearest_clusters.h"
#include"../Common/bins.h"
#include "../Common/word.h"
#include "../Common/mot.h"
typedef vector<bins>  histog ;

histograms::histograms(void)
{
	
}


histograms::~histograms(void)
{
	cout  << " histogram destructor runs  " << endl;
}

/// trier les tableaus des desccripteurs en finction des images_id represente en row[3]
void histograms::sort_descripteurs(vector<vector<float>> & descripteurs)
{
typedef std::vector<float> Row;
struct comp
{ 
	inline bool operator()(const Row& row1,const Row& row2)
	{
		return (row1[3] < row2[3]);
	}
};
std::sort(descripteurs.begin(),descripteurs.end(),comp());
 cout << " le vecteur est triee "<<endl;
}


/// get the last last image in the descriptors 
float  histograms::get_last_element(vector<vector<float>> & descripteurs)
{
	int taille=descripteurs.size()-1;
	float  last= descripteurs [taille][3];
	cout << " last image id : "<<last <<endl;
    return last;

}
/// calculer le centre la plus proche  pour chaque points 
nearest_clusters histograms::plus_proche_clusters(float dist []  , int size )
{
	nearest_clusters min;
	
	min.set_min_distance(dist[0]);
	min.set_cluster_indice(0);
	for (int i=0;i< size;i++)
	{
		if(dist[i]<min.get_min_distance())
		{
			min.set_min_distance(dist[i]);
			min.set_cluster_indice(i);
		}
	}

	return min;	
}
/// calculer la distance entre les centres et les points , prend le centre qui a la plus petit distance et retourne un tableau de words contenant {point , scale , image_id , centre )
void histograms::Calculer_min_distance(vector<vector<float>> & keyppoints , vector<vector <float>> & descriptors , vector <word> & distance , const int total_nb_clusters,int Nb_trunc)
{
	int size=descriptors.size();
    distance.resize(size);
	float* sim= new float [total_nb_clusters];
	for (int d=0; d<(descriptors.size());d++)
	{
		for(int i=0;i<keyppoints.size();i++)
		{
			 float sum=0 , dist =0 ;
			for(int j=0;j < (keyppoints.at(i).size());j++)
			{
			     dist= (descriptors[d][j+Nb_trunc]-keyppoints[i][j])*(descriptors[d][j+Nb_trunc]-keyppoints[i][j]);
			
				 sum=sum+dist;
				 
				
			}
			sim[i]=sqrt(sum);	
			
		}
				
		word * key = new word();		
		key->set_point_x(descriptors[d][0]);
		key->set_point_y(descriptors[d][1]);
	    key->set_scale(descriptors[d][2]);
		key->set_fileid(descriptors[d][3]);
		key->set_nearest_cluster(plus_proche_clusters(sim , total_nb_clusters));
		
		distance.at(d)=*key;
		
		}

	 cout <<" la calcul des distances est finie "<<endl;
}

void histograms::Calculer_min_distance(vector<vector<float>> & keyppoints , vector<vector <float>> & descriptors , vector <mot> & distance , const int total_nb_clusters,int Nb_trunc)
{
	int size=descriptors.size();
    distance.resize(size);
	float* sim= new float [total_nb_clusters];
	for (int d=0; d<(descriptors.size());d++)
	{
		for(int i=0;i<keyppoints.size();i++)
		{
			 float sum=0 , dist =0 ;
			for(int j=0;j < keyppoints.at(i).size()-1;j++)
			{
			     dist= (descriptors[d][j+Nb_trunc]-keyppoints[i][j])*(descriptors[d][j+Nb_trunc]-keyppoints[i][j]);
				 sum=sum+dist;
	
			}
			sim[i]=sqrt(sum);	
			
		}
				
		mot * key = new mot();		
		key->set_point_x(descriptors[d][0]);
		key->set_point_y(descriptors[d][1]);
		key->set_nearest_cluster(plus_proche_clusters(sim , total_nb_clusters));
		distance.at(d)=*key;
		
	}

	 cout <<" la calcul des distances est finie "<<endl;
}
void histograms::Calculer_min_distance(vector<vector<float>> & keyppoints , std::map< std::string  ,vector<vector<float>>>& descriptors ,std::map<std::string,vector<mot>> &distance ,int total_nb_clusters,int Nb_trunc)
{
	int size=descriptors.size();
	cout << " la taille du donnée " << size << endl;
	float* sim= new float [total_nb_clusters];
	vector<mot>tempWord;
		for( map<std::string ,vector<vector<float>> >::iterator iter = descriptors.begin(); iter != descriptors.end(); ++iter ) 
		{
			 std::string key=(*iter).first;
			 vector<vector<float>>tempVec = (*iter).second;
			tempWord.resize(tempVec.size());
			 for (int d=0; d<(tempVec.size());d++)
				{
					for(int i=0;i<keyppoints.size();i++)
					{
						 float sum=0 , dist =0 ;
						for(int j=0;j < (keyppoints.at(i).size());j++)
							{
								 dist= (tempVec[d][j+Nb_trunc]-keyppoints[i][j])*(tempVec[d][j+Nb_trunc]-keyppoints[i][j]);
								  sum=sum+dist;
						    }
					sim[i]=sqrt(sum);	
					}

					mot  * vocab = new mot();	
					vocab->set_point_x (tempVec[d][0]);
					vocab->set_point_y(tempVec[d][1]);
					vocab->set_nearest_cluster(plus_proche_clusters(sim , total_nb_clusters));
					
					tempWord.at(d)=*vocab;
			    }
	         distance.at(key)=tempWord;
		}
}
/// calculer la frequence des chaque word dans dans chaque image
void histograms::build_histogram(vector<word> & distance  , int img_id , vector<bins> & histogram, int total_nb_clusters)
{
	histogram.resize(total_nb_clusters);
	
	for(int j=0; j<distance.size() ;j++)
	{
	  if(distance[j].get_fileid()==img_id)
		{
			for(int i=0;i<total_nb_clusters;i++)
			{
				if( distance[j].get_nearest_cluster().get_cluster_indice()==i)
				{ 
					histogram[i].set_cluster_freq(histogram[i].get_cluster_freq()+1);					
				}
				histogram[i].set_cluster_indice(i);
			}
			
		}

	}
	

}
void histograms::build_histogram(vector<mot> & distance, vector<bins> & histogram, int total_nb_clusters)
{
	histogram.resize(total_nb_clusters);
	
	for(int j=0; j<distance.size() ;j++)
	{
		for(int i=0;i<total_nb_clusters;i++)
			{
				if( distance[j].get_nearest_cluster().get_cluster_indice()==i)
				{ 
					histogram[i].set_cluster_freq(histogram[i].get_cluster_freq()+1);					
				}
				histogram[i].set_cluster_indice(i);
			}
			
		}
	cout << "'histogramme est calculee"<<endl;
	}
	


void histograms::build_histograms(std::map<std::string,vector<mot>> & distance , std::map<std::string,vector<bins>> & multi_histogs , int total_nb_clusters)
{
	vector <bins> histog;
	histog.resize(total_nb_clusters);
	for( std::map<std::string,vector<mot>>::iterator iter = distance.begin(); iter != distance.end(); ++iter ) 
	{
		std::string key=(*iter).first;
		vector<mot>tempWord=(*iter).second;
		for (int i=0; i<tempWord.size();i++)
			for(int j=0;j<total_nb_clusters;j++)
			{
				if( tempWord[j].get_nearest_cluster().get_cluster_indice()==i)
				{
					histog[i].set_cluster_freq(histog[i].get_cluster_freq()+1);	
				}
				histog[i].set_cluster_indice(i);
			}
        multi_histogs[key]=histog;
		histog.clear();
	}
}
/// calcule  les histogrammes pour toutes les images 
void histograms::get_all_histograms(vector <vector<bins>> & table_histograms ,float last_image ,vector<word> & distance,int total_nb_clusters)
{
	

	 for ( int k=0;k<=last_image;k++)
			  {
				histog histo;
			 	build_histogram(distance,k,histo,total_nb_clusters);
				table_histograms.push_back(histo);
				histo.clear();
				
			
			  }

	cout <<" toutes les histogrammes ont ete calculee  \n" ;
}

/// convert from "Mat"  format to "vector of vector " format 
void histograms::remplir_Cluster_center( Mat centers_Class , vector<vector <float>> & keypoint)
{
	
	std::vector < float > row;
	for (int i =0; i < centers_Class.rows;i++)
	{
		
		for (int j=0; j < centers_Class.cols;j++)
		{
			row.push_back(centers_Class.at<float>(i,j));
		}
		
		keypoint.push_back(row);
		row.clear();
	}

}
/// regroups all the keypoints calculated in one vector to get the visual vocabulary of 1000 words.
void histograms::concatenate_clusters_centers(  Mat centers_cars , Mat centers_perso , Mat centers_bike , Mat centers_moto ,vector<vector <float>> & keypoint)
{

	//int size= centers_cars.rows+ centers_perso.rows+centers_moto.rows+centers_bike.rows;
	remplir_Cluster_center(centers_cars,keypoint);
	remplir_Cluster_center(centers_perso,keypoint);
	remplir_Cluster_center(centers_bike,keypoint);
	remplir_Cluster_center(centers_moto,keypoint);

}
