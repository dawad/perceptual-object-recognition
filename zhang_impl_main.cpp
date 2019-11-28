
#include "stdafx.h"
#include <boost/algorithm/string.hpp>
#include <boost/filesystem/operations.hpp>
#include<boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <time.h>

	#include "Fichiers/Fichiers.h"
	#include "kmean\kmean.h"
	#include "histograms\histograms.h"
	#include "mysvm\mysvm.h"
    #include "manip_heatmap.h"
	#include "Common\Mask.h"

void main() 
{
	
	
	
	/// generate the visual vocabularies using k-means algorithm
	
	Fichiers file; 
	//	boost::filesystem3::path classes_folders[10]={"C:/Users/dawad/Desktop/VOC06/trainval/bicycle/pos/","C:/Users/dawad/Desktop/VOC06/trainval/bus/pos/","C:/Users/dawad/Desktop/VOC06/trainval/car/pos/", "C:/Users/dawad/Desktop/VOC06/trainval/cat/pos/","C:/Users/dawad/Desktop/VOC06/trainval/cow/pos/","C:/Users/dawad/Desktop/VOC06/trainval/dog/pos/","C:/Users/dawad/Desktop/VOC06/trainval/horse/pos/","C:/Users/dawad/Desktop/VOC06/trainval/motorbike/pos/","C:/Users/dawad/Desktop/VOC06/trainval/person/pos/","C:/Users/dawad/Desktop/VOC06/trainval/sheep/pos/"};
	     //string classe[10]={"bicycle","bus","car","cat","cow","dog","horse","motorbike","person","sheeep"};
	//VOC05_data filteredSIFT
//	boost::filesystem3::path classes_folders[4]={"D:/filteredSIFT_th17/th=51/trainval/bike/pos/","D:/filteredSIFT_th17/th=34/trainval/cars/pos/","D:/filteredSIFT_th17/th=34/trainval/moto/pos/","D:/filteredSIFT_th17/th=17/trainval/persons/pos/"};
	//boost::filesystem3::path classes_folders[4]={"C:/Users/dawad/Desktop/voc2005_1/interest-pts/trainval/bike/pos/res/","C:/Users/dawad/Desktop/voc2005_1/interest-pts/trainval/cars/pos/res/","C:/Users/dawad/Desktop/voc2005_1/interest-pts/trainval//moto/pos/res/","C:/Users/dawad/Desktop/voc2005_1/interest-pts/trainval/persons/pos/res/"};
/*  boost::filesystem3::path classes_folders[19]={"D:/dounia/bande_dessinée/6388481817_4318f9c83/app/","D:/dounia/bande_dessinée/CYB_BUBBLEGOM/app/","D:/dounia/bande_dessinée/CYB_COSMOZONE/app/","D:/dounia/bande_dessinée/FOX_CHILLINTALES_ct_17/app","D:/dounia/bande_dessinée/FRED_PHILEMON9/app/",
                                                "D:/dounia/bande_dessinée/INOUE_KYOUMEN/app/","D:/dounia/bande_dessinée/JOLIVET_BOSTONPOLICEAFFAIREPRADI/app/","D:/dounia/bande_dessinée/LAMISSEB_ETPISTAF/app/","D:/dounia/bande_dessinée/LAMISSEB_LESNOEILS1/app/","D:/dounia/bande_dessinée/LUBBIN_LESBULLESDULABO/app/",
                                                 "D:/dounia/bande_dessinée/MCCALL_ROBINHOOD/app/","D:/dounia/bande_dessinée/MCCAY_LITTLENEMO/app/","D:/dounia/bande_dessinée/MIDAM_GAMEOVER/app/","D:/dounia/bande_dessinée/MIDAM_KIDPADDLE7/app/","D:/dounia/bande_dessinée/PIKE_BOYLOVEGIRLS/app/", 
                                                  "D:/dounia/bande_dessinée/ROUDIER_LESTERRESCREUSEES/app/","D:/dounia/bande_dessinée/SAINTOGAN_PROSPER_ET_LE_MONSTRE_MARIN/app/","D:/dounia/bande_dessinée/SAINTOGAN_ZIGPUCE_ET_ALFRED/app/","D:/dounia/bande_dessinée/SAINTOGAN_ZIGPUCE_MILLIONAIRES/app/"};
	string classe[19]={"6388481817_4318f9c83","CYB_BUBBLEGOM","CYB_COSMOZONE","FOX_CHILLINTALES_ct_17","FRED_PHILEMON9",
						"INOUE_KYOUMEN","JOLIVET_BOSTONPOLICEAFFAIREPRADI","LAMISSEB_ETPISTAF","LAMISSEB_LESNOEILS1","LUBBIN_LESBULLESDULABO",
						"MCCALL_ROBINHOOD","MCCAY_LITTLENEMO","MIDAM_GAMEOVER","MIDAM_KIDPADDLE7", "PIKE_BOYLOVEGIRLS",
						"ROUDIER_LESTERRESCREUSEES","SAINTOGAN_PROSPER_ET_LE_MONSTRE_MARIN","SAINTOGAN_ZIGPUCE_ET_ALFRED","SAINTOGAN_ZIGPUCE_MILLIONAIRES"};*/

	string classe[20]={"aeroplane","bicycle","bird","boat","bottle","bus","car","cat","chair","cow","diningtable","dog","horse","motorbike","person","pottedplant","sheep","sofa","train"
		"tvmonitor"};

     //std::vector<boost::filesystem3::path> descript_files;
	 vector<const string> descript_files;
	 std::map<std::string  ,vector<vector<float>>> descript;
	 // get the list of descriptor files for each class 
	for (int i =14 ; i<20 ; i++)
	{
	//int i=1;
	
	//cout <<classes_folders[i].string() <<endl;
	
	//file.read_Dirs(classes_folders[i],descript_files);

	file.read_list("D:/dounia/VOCdevkit/VOC2007/ImageSets/Main/",classe[i],"trainval","pos",descript_files);
	//file.read_multi_txt_files(descript_files,descript); 
	
	file.read_multi_txt_files("D:/dounia/__20100/Thesis/Mesures/Fixations/VDESC/",descript_files,descript);
	int size_total=0;

for( std::map<std::string  ,vector<vector<float>>>::iterator iter = descript.begin(); iter != descript.end(); ++iter ) 
		{
			
			 vector<vector<float>>tempVec = (*iter).second;
			 std::string key=(*iter).first;
			 size_total+=tempVec.size();
			/* for(int i=0; i<tempVec.size();i++)
			 {
				 cout<<"\n";
				 for(int j=0; j<tempVec.at(i).size();j++)
					 cout<<tempVec[i][j]<<" ";
			 }*/
 }
	cout << " SIFT keypoint size  = "<< size_total<<endl;
	

	
	kmean k_means;
	std::map<std::string  ,vector<vector<float>>> ::iterator iter;
	int nb_random=50000;
	/// definition des parametres necessaires 
	if(size_total<50000)
	 	  nb_random=k_means.set_Nb_instance_random(size_total);

	int desc_dim=k_means.set_desc_dimension(60);
	int nb_centers=k_means.set_nb_clusters(250);

	/// remove the unecessary data from the table and select randomly the descriptors from the table for the person class 
	//Mat data_class (nb_random,desc_dim,CV_32FC1);
	CvMat* mat =cvCreateMat(nb_random ,desc_dim,CV_32FC1);
	k_means.select_randomly_descs(mat,descript,nb_random,desc_dim,descript_files.size());
	
	/// defintion des matrice pour le centers et les labels pour chaque descriptor ( clusters_person ) pour la classe bike
	//Mat clusters_class(nb_random,1,CV_32SC1);
	CvMat* cluster =cvCreateMat(nb_random ,1,CV_32SC1);
	//Mat centers_class(nb_centers,desc_dim,CV_32FC1);
	CvMat* centers =cvCreateMat(nb_centers,desc_dim,CV_32FC1);
	clock_t begin_time,end_time;
	begin_time=clock();
	{
	//k_means.openCv_kmean(data_class,clusters_class,centers_class,nb_centers);
	k_means.openCv_kmean(mat,cluster,centers,nb_centers);
	}
	end_time=clock();
	float temps_calcul=(end_time-begin_time)/(double)CLOCKS_PER_SEC;
	cout << "time  : "<<temps_calcul << " per sec " <<endl;
	file.App_txt("D:/dounia/zhang_impl_v1/zhang_impl_v1/train/keypoints.txt",centers);
	file.write_calc_time_kmean ("D:/dounia/zhang_impl_v1/zhang_impl_v1/train/kmean_param.txt",classe[i],"train",descript_files.size(),temps_calcul,size_total);
	descript_files.clear();
	descript.clear();
	/*free(mat);
	free(cluster);
	free(centers);
	*/
}
	
	/*
	/// calcul of histogram for the images 
  Fichiers file;
	//test1
	//boost::filesystem3::path classes_folders[2]={"C:/Users/dawad/Desktop/VOC06/test/bicycle/pos/Harris_laplace","D:/VOC06/test/bicycle/neg/dorko_1/descript_txt/Harris_laplace"};
	//boost::filesystem3::path classes_folders[2]={"D:/VOC05_data/test2/persons/pos/Harris_laplace","D:/VOC05_data/test2/persons/neg/Harris_laplace"};
	//boost::filesystem3::path classes_folders[2]={"C:/Users/dawad/Desktop/VOC06/test/bicycle/pos/Harris_laplace","C:/Users/dawad/Desktop/VOC06/test/bicycle/neg/Harris_laplace"};
	//boost::filesystem3::path classes_folders_lap[2]={"D:/VOC05_data/test2/persons/pos/laplacian","D:/VOC05_data/test2/persons/neg/laplacian"};
	//boost::filesystem3::path classes_folders_lap[2]={"C:/Users/dawad/Desktop/VOC06/test/bicycle/pos/laplacian","D:/VOC06/test/bicycle/neg/dorko_1/descript_txt/laplacian"};
	/*boost::filesystem3::path classes_folders[4][2]={{"D:/VOC05_data/test2/bike/pos/","D:/VOC05_data/test2/bike/neg/"},
													{"D:/VOC05_data/test2/cars/pos/","D:/VOC05_data/cars/neg/"},
													{"D:/VOC05_data/test2/moto/pos/","D:/VOC05_data/test2/moto/neg/"},
													{"D:/VOC05_data/test2/persons/pos/","D:/VOC05_data/test2/persons/neg/"}
													};*/
/*	boost::filesystem3::path classes_folders[4][2]={{"D:/filteredSIFT_th17/th=136/test1/bike/pos/","D:/filteredSIFT_th17/th=136/test2/bike/neg/"},
													{"D:/filteredSIFT_th17/th=136/test2/cars/pos/","D:/filteredSIFT_th17/th=136/test2/cars/neg/"},
													{"D:/filteredSIFT_th17/th=136/test2/moto/pos/","D:/filteredSIFT_th17/th=136/test2/moto/neg/"},
													{"D:/filteredSIFT_th17/th=119/test2/persons/pos/","D:/filteredSIFT_th17/th=119/test2/persons/neg/"}
												};*/
 /*
  boost::filesystem3::path classes_folders[19]={"D:/dounia/bande_dessinée/6388481817_4318f9c83/app/","D:/dounia/bande_dessinée/CYB_BUBBLEGOM/app/","D:/dounia/bande_dessinée/CYB_COSMOZONE/app/","D:/dounia/bande_dessinée/FOX_CHILLINTALES_ct_17/app/","D:/dounia/bande_dessinée/FRED_PHILEMON9/app/",
                                                "D:/dounia/bande_dessinée/INOUE_KYOUMEN/app/","D:/dounia/bande_dessinée/JOLIVET_BOSTONPOLICEAFFAIREPRADI/app/","D:/dounia/bande_dessinée/LAMISSEB_ETPISTAF/app/","D:/dounia/bande_dessinée/LAMISSEB_LESNOEILS1/app/","D:/dounia/bande_dessinée/LUBBIN_LESBULLESDULABO/app/",
                                                 "D:/dounia/bande_dessinée/MCCALL_ROBINHOOD/app/","D:/dounia/bande_dessinée/MCCAY_LITTLENEMO/app/","D:/dounia/bande_dessinée/MIDAM_GAMEOVER/app/","D:/dounia/bande_dessinée/MIDAM_KIDPADDLE7/app/","D:/dounia/bande_dessinée/PIKE_BOYLOVEGIRLS/app/", 
                                                  "D:/dounia/bande_dessinée/ROUDIER_LESTERRESCREUSEES/app/","D:/dounia/bande_dessinée/SAINTOGAN_PROSPER_ET_LE_MONSTRE_MARIN/app/","D:/dounia/bande_dessinée/SAINTOGAN_ZIGPUCE_ET_ALFRED/app/","D:/dounia/bande_dessinée/SAINTOGAN_ZIGPUCE_MILLIONAIRES/app/"};
	string classe[19]={"6388481817_4318f9c83","CYB_BUBBLEGOM","CYB_COSMOZONE","FOX_CHILLINTALES_ct_17","FRED_PHILEMON9",
						"INOUE_KYOUMEN","JOLIVET_BOSTONPOLICEAFFAIREPRADI","LAMISSEB_ETPISTAF","LAMISSEB_LESNOEILS1","LUBBIN_LESBULLESDULABO",
						"MCCALL_ROBINHOOD","MCCAY_LITTLENEMO","MIDAM_GAMEOVER","MIDAM_KIDPADDLE7", "PIKE_BOYLOVEGIRLS",
						"ROUDIER_LESTERRESCREUSEES","SAINTOGAN_PROSPER_ET_LE_MONSTRE_MARIN","SAINTOGAN_ZIGPUCE_ET_ALFRED","SAINTOGAN_ZIGPUCE_MILLIONAIRES"};
	
	vector <vector<float>> keypoints;
	file.read_files("D:/dounia/zhang_impl_v1/zhang_impl_v1/train/keypoints.txt",keypoints);
	
	const int Total_cluster=4750;
	for ( int l=0; l<19;l++)
	{
	//int l=1;
	/*boost::filesystem3::path classes_folders[2]={"D:/VOC05_data/test1/"+classe[l]+"/pos/Harris_laplace/","D:/VOC05_data/test2/"+classe[l]+"/neg/Harris_laplace/"};
	boost::filesystem3::path classes_folders_lap[2]={"D:/VOC05_data/test2/"+classe[l]+"/pos/laplacian/","D:/VOC05_data/test2/"+classe[l]+"/neg/laplacian/"};*/
/*
	const string file_nomp="D:/dounia/zhang_impl_v1/zhang_impl_v1/train/histograms_"+classe[l]+"_pos.txt";//"D:/VOC_datasets/train/histograms_"+classe[l]+"_neg.txt"};
	const string param_file="D:/dounia/zhang_impl_v1/zhang_impl_v1/train/param/histograms_"+classe[l]+"_pos.params.txt";//"D:/VOC_datasets/train/histograms_"+classe[l]+"_neg.params.txt"};
	
	//for (int j=1; j< 2;j++)
	//{
	//int j=0;
	std::vector < boost::filesystem3::path> descript_files;
	//std::vector < boost::filesystem3::path> descript_files_lap;
	cout <<classes_folders[l].string() <<endl;
	file.read_Dirs (classes_folders[l],descript_files);
	//file.read_Dirs (classes_folders_lap[j],descript_files_lap);
	vector<vector<float>> descript;

	vector<mot> min_distance;
	vector<bins> multi_histograms;
	
	histograms histog;
	int nb_centers=250;
	float avg1=0;
	float avg2=0;
	for ( int i=0; i<descript_files.size();i++)
	{
	cout << "file name " << descript_files[i].string()<<endl;

	//string imgname=descript_files[i].leaf().string().substr(0,descript_files[i].leaf().string().size()-17);
	string imgname=descript_files[i].leaf().string().substr(0,descript_files[i].leaf().string().size()-4);
	cout <<"image name : " << imgname <<endl;
	//int fid=file.search_similar_file_name(descript_files_lap,imgname);
	//if(fid >=0)
	//{
	//string  fichier_nom[2]={descript_files[i].string(),descript_files_lap[fid].string()};
	//file.read_multi_files(fichier_nom,2,descript);
	file.read_txt_file (descript_files[i].string(),descript);
	/// construire des histogrammes
	
	time_t start,end;
	time (&start);
 	histog.Calculer_min_distance(keypoints,descript,min_distance,Total_cluster);
	time(&end);
	cout << "time "<<difftime(end,start)<< " per sec " <<endl;
	avg1+=difftime(end,start);
	clock_t begin_time_t,end_time_t;
	begin_time_t	=clock();
	{
	histog.build_histogram(min_distance,multi_histograms,Total_cluster);
	}
	end_time_t=clock();
	cout << "temps en secondes "<<(end_time_t-begin_time_t) /(double)CLOCKS_PER_SEC<< " per sec " <<endl;
	avg2+=(end_time_t-begin_time_t) /(double)CLOCKS_PER_SEC;
	file.App_ASCII_txt(file_nomp,multi_histograms,imgname,(end_time_t-begin_time_t) /(double)CLOCKS_PER_SEC);
	descript.clear();
	min_distance.clear();
	multi_histograms.clear();
	//}
	//else 
	//{
		//cout <<" no similar files"<<endl;
	
	//}
	}
	if(avg1!=0) avg1=avg1/descript_files.size();
	if(avg2!=0) avg2=avg2/descript_files.size();
	cout << " moyen du temp de calcule pour recherche le plus proche voisins " << avg1 << "\n moyen du temps du calcul pour la construction d'histogram " << avg2 << endl;
	file.write_param_txt(param_file,classe[l], "test1",descript_files.size(),avg1,avg2,0);
	
	}
	
	
*/
/*
/// classification

	Fichiers file;
	string classe[19]={"6388481817_4318f9c83","CYB_BUBBLEGOM","CYB_COSMOZONE","FOX_CHILLINTALES_ct_17","FRED_PHILEMON9",
						"INOUE_KYOUMEN","JOLIVET_BOSTONPOLICEAFFAIREPRADI","LAMISSEB_ETPISTAF","LAMISSEB_LESNOEILS1","LUBBIN_LESBULLESDULABO",
						"MCCALL_ROBINHOOD","MCCAY_LITTLENEMO","MIDAM_GAMEOVER","MIDAM_KIDPADDLE7", "PIKE_BOYLOVEGIRLS",
						"ROUDIER_LESTERRESCREUSEES","SAINTOGAN_PROSPER_ET_LE_MONSTRE_MARIN","SAINTOGAN_ZIGPUCE_ET_ALFRED","SAINTOGAN_ZIGPUCE_MILLIONAIRES"};
	//int thresh[4]={60,70,80,90};


	/// initialization 
	
	
	int Total_cluster=4750;
	mysvm test_svm;
	
	 
	//  vector<roc_row>table_roc;
for (int l=12;l<19;l++)
{
	//int l=2;
	/// SVM 
//for (int i=0;i<4;i++)
//{
	//int i=1;
	/*
    vector < vector< int >> histo_pos;
	char filt_folder_pos[50];
	string path_pos="D:/filteredSIFT_th17/%d/trainval/histograms_"+classe[l]+"_pos(%d%%).txt";
	sprintf(filt_folder_pos,path_pos.data (),thresh[i],thresh[i]);
	file.read_ASCII_files(filt_folder_pos,histo_pos);
	
	vector <vector < int>> histo_neg;
	char filt_folder_neg[50];
	string path_neg="D:/filteredSIFT_th17/%d/trainval/histograms_"+classe[l]+"_neg(%d%%).txt";
	sprintf(filt_folder_neg,path_neg.data (),thresh[i],thresh[i]);
	file.read_ASCII_files(filt_folder_neg,histo_neg);
	*/
/*
	vector < vector< int >> histo_pos;
	file.read_ASCII_files("D:/dounia/zhang_impl_v1/zhang_impl_v1/train/histograms_"+classe[l]+"_pos.txt",histo_pos,Total_cluster);
	vector <vector < int>> histo_neg;
	//file.read_ASCII_files("D:/VOC_datasets/train/histograms_"+classe[l]+"_neg.txt",histo_neg,Total_cluster);
		for(int i=0;i< 19; i++)
		{
			cout<<" i= " << i <<"\n";
			if((i-l)==0)
			{
				continue;
			}
			else 
			{
			//	cout<<" classe " << classe[i]<<"\n";
				file.read_ASCII_files("D:/dounia/zhang_impl_v1/zhang_impl_v1/train/histograms_"+classe[i]+"_pos.txt", histo_neg,Total_cluster);
			}
		}

	 int nb_rows=histo_pos.size()+histo_neg.size();
   // train
   	 CvMat * train =cvCreateMat(nb_rows,Total_cluster,CV_32FC1);
	 CvMat * response=cvCreateMat(nb_rows,1,CV_32FC1);
  
    test_svm.preparer_donnee_apprentissage(histo_pos,histo_neg,train,classe[l]);
  
   test_svm.preparer_classes(histo_pos.size(),histo_neg.size(),response);
   time_t start,end;
	
	/// test 
	double   gammma[6]={0.000001,0.00001,0.0001,0.001,0.01,0.1};
	for (int k=0; k<6;k++)
	{
	time(&start);
   test_svm.svm_train(train, response,gammma[k],10);
   time(&end);
   float avg =difftime(end,start);
   cout << "time "<<difftime(end,start)<< " per sec " <<endl;
   
   // test 
   /*
  for (int j=1; j<4;j++)
   {
   //int j=2;

  cout << "\n threshold_train -threshold_test  " << thresh[i] << "-"<<thresh[j] << "\n gamma " << gammma[k]<<endl;
  
    vector < vector< int >> histo_pos_val;
   	char test_folder_pos[50];
    path_pos="D:/filteredSIFT_th17/histograms_"+classe[l]+"_pos(%d).txt";
	sprintf(test_folder_pos,path_pos.data (),thresh[j],thresh[j]);
   file.read_ASCII_files(test_folder_pos,histo_pos_val);  
  
   double conf[2];


     
  	  vector <vector < int>> histo_neg_val; 
   char* test_folder_neg=new char[50];
	 path_neg="D:/filteredSIFT_th17/histograms_"+classe[l]+"_neg(%d).txt";
	sprintf(test_folder_neg,path_neg.data (),thresh[j],thresh[j]);
   file.read_ASCII_files(test_folder_neg,histo_neg_val);  
   double * conf1=new double[2];

     time_t begin_time_t,end_time_t;
	 time (&begin_time_t);
    cout << " test pour positive class "<<endl;
   int ** data_test_pos= test_svm.preparer_donee_test(histo_pos_val,0 ,histo_pos_val.size() ,Total_cluster);
   test_svm.svm_test(data_test_pos,histo_pos_val.size(),Total_cluster,conf);
   //cout << conf[0] << " "<<conf[1]<<endl;
    cout << " test pour negative class "<<endl;
   int ** data_test_neg= test_svm.preparer_donee_test(histo_neg_val,0 ,histo_neg_val.size() ,Total_cluster);
   test_svm.svm_test(data_test_neg,histo_neg_val.size(),Total_cluster,conf1);
      time(&end_time_t);
	float time_test=difftime(end_time_t,begin_time_t);
	*/
/*
   vector<roc_row>table_roc;
   vector < vector< int >> histo_pos_val;
   file.read_ASCII_files("D:/dounia/zhang_impl_v1/zhang_impl_v1/test/histograms_"+classe[l]+"_pos.txt",histo_pos_val,Total_cluster);  
     vector <vector < int>> histo_neg_val; 
	 for(int i=0;i< 18; i++)
		{
			cout<<" i" << i <<"\n";
			if((i-l)==0)
			{
				continue;
			}
			else 
			{
				cout<<" classe " << classe[i]<<"\n";
				file.read_ASCII_files("D:/dounia/zhang_impl_v1/zhang_impl_v1/test/histograms_"+classe[i]+"_pos.txt", histo_neg_val,Total_cluster);
			}
		}
  // file.read_ASCII_files("D:/VOC_datasets/test1/histograms_"+classe[l]+"_neg.txt",histo_neg_val,Total_cluster); 
     time_t begin_time_t,end_time_t;
	 time (&begin_time_t);
   cout << " test pour positive class "<<endl;
   double  conf[2];
   int ** data_test_pos= test_svm.preparer_donee_test(histo_pos_val,0 ,histo_pos_val.size() ,Total_cluster);
   test_svm.svm_test(data_test_pos,histo_pos_val.size(),Total_cluster,conf);
   double conf1[2];
   cout << " test pour negative class "<<endl;
  

   int ** data_test_neg= test_svm.preparer_donee_test(histo_neg_val,0 ,histo_neg_val.size() ,Total_cluster);
   test_svm.svm_test(data_test_neg,histo_neg_val.size(),Total_cluster,conf1);
   time(&end_time_t);
	float time_test=difftime(end_time_t,begin_time_t);
   
   time_t begin_time_t_1,end_time_t_1;
  
	time (&begin_time_t_1);
   test_svm.fill_roc_table(table_roc,histo_pos_val,histo_neg_val,0,Total_cluster,-5,4,classe[l]);
   double auc=test_svm.calc_AUC(table_roc);
	cout << " \n Area under curve  ( auc ) : " << auc <<endl;
	 time(&end_time_t_1);
	 
	string value=boost::lexical_cast <string>(gammma[k]);
  //  path_pos="D:/filteredSIFT_th17/histograms_"+classe[l]+"_test2_2(%d%%,%d%)_[%f].csv";
	string  path_pos="D:/dounia/zhang_impl_v1/zhang_impl_v1/test/res/histograms_"+classe[l]+"_test("+value+").csv";
	//sprintf(folder_pos1,path_pos.data (),thresh[i],thresh[j],gammma[k]);
	//sprintf(folder_pos1,path_pos.data (),gammma[k]);
    file.write_csv_File(path_pos,table_roc);
	 
  
	cout << "temps en secondes "<<difftime(end_time_t_1,begin_time_t_1)<< " per sec " <<endl;
	//char folder_pos[50];
    //path_pos="D:/filteredSIFT_th17/histograms_"+classe[l]+"_test2(%d%%,%d%%).txt";
	//sprintf(folder_pos,path_pos.data(),thresh[i],thresh[i],thresh[j]);

	file.write_svm_res("D:/dounia/zhang_impl_v1/zhang_impl_v1/test/res/histograms_"+classe[l]+"_test1.txt",classe[l],0,0,gammma[k],difftime(end,start),time_test,conf,conf1,auc);
	//file.write_svm_res(folder_pos,classe[l],thresh[i],thresh[j],gammma[k],avg,time_test,conf,conf1,auc);
	//test_svm.Free_Tab(data_test_pos,histo_pos_val.size());
	//test_svm.Free_Tab(data_test_neg,histo_neg_val.size());
	table_roc.clear();
	free(data_test_pos);
	free(data_test_neg);
  }
	//}
		
	}
	
	}
	
 //  Sleep(10000);
  // }*/
}