
#include "stdafx.h"
#include <boost/algorithm/string.hpp>
#include <boost/filesystem/operations.hpp>
#include<boost/filesystem/fstream.hpp>
#include <time.h>

	#include "Fichiers/Fichiers.h"
	#include "kmean\kmean.h"
	#include "histograms\histograms.h"
	#include "mysvm\mysvm.h"
    #include "manip_heatmap.h"
	#include "Common\Mask.h"
/*
void main() 
{
	/// filtering of the SIFT Point using heatmap 

	// lire les fichiers SIFT des images 
	 Fichiers file;
	 string  Classes_voc[3]={"cars","moto","persons"};
	// for( int l=0; l< 2;l++)
	 //{
	 int l =1;
	 boost::filesystem3::path classes_folders[2]={"D:/VOC05_data/trainval/"+Classes_voc[l]+"/pos/Harris_laplace/","D:/VOC05_data/trainval/"+Classes_voc[l]+"/neg/Harris_laplace/"};
	 boost::filesystem3::path classes_folders_lap[2]={"D:/VOC05_data/trainval/"+Classes_voc[l]+"/pos/laplacian/","D:/VOC05_data/trainval/"+Classes_voc[l]+"/neg/laplacian/"};
	  // lire the heatmap 
	 boost::filesystem3::path heatmap_dossier[2]={"D:/Mathieu_data/trainval/"+Classes_voc[l]+"/"+Classes_voc[l]+"_pos/","D:/Mathieu_data/trainval/"+Classes_voc[l]+"/"+Classes_voc[l]+"_neg/"};
	 /// the path for the new generated files 
	 const string param_file[2]={"D:/Mathieu_data/trainval/"+Classes_voc[l]+"/"+Classes_voc[l]+"_pos/filtered_SIFT_"+Classes_voc[l]+"_pos_filt.params.txt","D:/Mathieu_data/trainval/"+Classes_voc[l]+"/"+Classes_voc[l]+"_neg/filtered_SIFT_"+Classes_voc[l]+"_neg_filt.params.txt"};		
	
	
	vector < boost::filesystem3::path >  file_name;	

	//for (int j=0; j< 2;j++)
	//{
	int j=1;
	/// get the path of the heatmap files 

	file.read_Dirs(heatmap_dossier[j] , file_name);


	/// get the path of the SIFT files 
	/// declaration
	std::vector < boost::filesystem3::path> descript_files;
	std::vector < boost::filesystem3::path> descript_files_lap;
	/// lire les paths of the SIFT files 
	cout <<classes_folders[j].string() <<endl;
	cout <<classes_folders_lap[j].string() <<endl;
	file.read_Dirs (classes_folders[j],descript_files);
	file.read_Dirs (classes_folders_lap[j],descript_files_lap);
	///declaration of the data
	float avg1=0;
	vector<vector<float>> descript;
	vector <vector <float>> _filtered_descriptors ; 
	vector <Mask> img_mask;
	/// definition of the threshold 
	for( int threshold=68; threshold<=136;threshold+=17)
	{
    char* filt_folder_pos=new char[50];
	string path_pos="D:/filteredSIFT_th17/th=%d/trainval/"+Classes_voc[l]+"/pos/";
	sprintf(filt_folder_pos,path_pos.data (),threshold);
	 char* filt_folder_neg=new char[50];
	 string path_neg="D:/filteredSIFT_th17/th=%d/trainval/"+Classes_voc[l]+"/neg/";
	sprintf(filt_folder_neg,path_neg.data(),threshold);
	char* SIFT_filt_files[2]={filt_folder_pos,filt_folder_neg};
	 cout << threshold <<endl;
	 int size_total=0;
	for ( int i=0; i<descript_files.size();i++)
	{

	/// lire les 2 Types de descripteurs detectee par Harris_laplace et laplacian 
	string imgname=descript_files[i].leaf().string().substr(0,descript_files[i].leaf().string().size()-17);
	int fid=file.search_similar_file_name(descript_files_lap,imgname);
	if(fid >=0)
	{
	string  fichier_nom[2]={descript_files[i].string(),descript_files_lap[fid].string()};
	file.read_multi_files(fichier_nom,2,descript);
	 manip_heatmap htmp;
	   /// find the right heatmap for each image
	 		cout <<i<< "/"<< descript_files.size()<< "    file name   "<< imgname<<"\n";
			string heatmap=" ";
			file.get_heatmap_file(heatmap,imgname,file_name);
			cout << " the right heatmap " << heatmap << endl;
		time_t start,end;
		time (&start);
		/// generate heatmap
			htmp.generate_mask(heatmap.c_str(),threshold,img_mask);
		/// filter the SIFT descriptor 
			htmp.filter_sift_pts(img_mask,threshold,descript,_filtered_descriptors,i);
		time(&end);		
	  avg1+=difftime(end,start);
	  size_total+=_filtered_descriptors.size();
	/// ecrire les resultats dans un fichiers .txt 
			 string img_NID=SIFT_filt_files[j]+imgname+".sift(th=%d).txt";
			char Newfile[50];
			sprintf(Newfile,img_NID.data(),threshold);
			cout <<"file name "<< " " << Newfile<<endl;
			file.write_txt(Newfile,_filtered_descriptors);
	/// clear le memoire;
   _filtered_descriptors.clear();
	descript.clear();
    img_mask.clear();
	htmp.~manip_heatmap();
	}
	else 
	{
		cout <<" no similar files"<<endl;
	//Classe_table[l]
	}
	}
	cout << "Filtered sift keypoints " << size_total;
	cout <<endl;
	if(avg1!=0) avg1=avg1/descript_files.size();
	cout << " moyen du temp de calcule pour filtrer  " << avg1  << endl;
	file.write_param_txt(param_file[j],Classes_voc[l], "trainval",descript_files.size(),avg1,0,threshold,size_total);
	}
	}*/