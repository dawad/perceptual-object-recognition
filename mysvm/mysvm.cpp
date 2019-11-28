#include "stdafx.h"

#include "mysvm.h"

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
#include<iomanip>
using namespace cv;
using namespace std ;
#include "../Fichiers/arff_data/Donnees.h"
#include "../khi-deux_kernel/khi_deux.h"
#include "../Common/rate.h"
#include "../Common/roc_row.h"

mysvm::mysvm()
{
	svms = CvSVM ();

}

mysvm::mysvm(Donnees & app, Donnees & t)
{
	apprentissage=app;
	test=t;
	confusion=new int[app.cols()*app.rows()];
	svms = CvSVM ();

	for (int i = 0; i < apprentissage.nbClasses()*apprentissage.nbClasses(); i++) confusion[i]=0;
}

mysvm::~mysvm(void)
{
	cout << " svm destructor runs  " << endl;
}
/// preparer les donnees pour l'appresntissage compris les donnees et les classes
void mysvm::preparer_donnee_apprentissage(vector < vector < int >> & data_class_ref, vector < vector < int >> & outliers1_data,vector < vector < int >> &outliers2_data,vector < vector < int >> & outliers3_data, int Total_nb_clusters , int nb_image_train , CvMat* train , string Class_ref )
{
	
	    //CvMat * train =cvCreateMat(nb_image_train*4,Total_nb_clusters,CV_32FC1);
	   CvMat outliers1, outliers2,ref_class, outliers3;
	   	cvGetRows(train,&ref_class,0,nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&ref_class,i,j,(int)data_class_ref[i][j]);
		}

		cvGetRows(train,&outliers1,nb_image_train,nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&outliers1,i,j,(int)outliers1_data[i][j]);
		}
		cvGetRows(train,&outliers2,nb_image_train+nb_image_train ,(nb_image_train*3) );
	    for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&outliers2,i,j,(int)outliers2_data[i][j]);
		}
		cvGetRows(train,&outliers3,(nb_image_train*3),(nb_image_train*4));
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&outliers3,i,j,(int)outliers3_data[i][j]);
		}

		

		cout <<" les donnees d'apprentissage est pret" << endl;
}

void mysvm::preparer_donnee_apprentissage(vector < vector < int >> & data_class_ref, vector < vector < int >> & outliers1_data, CvMat* train , string Class_ref )
{
	//data_class_ref.at(i).size()
	    //CvMat * train =cvCreateMat(nb_image_train*4,Total_nb_clusters,CV_32FC1);
	   CvMat outliers1, outliers2,ref_class, outliers3;
	   	cvGetRows(train,&ref_class,0,data_class_ref.size());
		for(int i=0; i<data_class_ref.size();i++)
		{
			for (int j=0;j<data_class_ref.at(i).size();j++)
				cvmSet(&ref_class,i,j,(int)data_class_ref[i][j]);
		}

		cvGetRows(train,&outliers1,data_class_ref.size(),outliers1_data.size()+data_class_ref.size());
		for(int i=0; i<outliers1_data.size();i++)
		{
			for (int j=0;j<outliers1_data.at(i).size();j++)
				cvmSet(&outliers1,i,j,(int)outliers1_data[i][j]);
		}
		cout <<" les donnees d'apprentissage est pret" << endl;
}


/// prepare the data for the training 
void mysvm::preparer_donnee_apprentissage(std::vector<vector<bins>>& data_class_ref , std::vector<vector<bins>>& outliers1_data,std::vector<vector<bins>>& outliers2_data,std::vector<vector<bins>>& outliers3_data, int Total_nb_clusters , int nb_image_train , CvMat * train , string Class_ref)
{
	
	    //CvMat * train =cvCreateMat(nb_image_train*4,Total_nb_clusters,CV_32FC1);

		CvMat outliers1, outliers2,ref_class, outliers3;

		cvGetRows(train,&ref_class,0,nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&ref_class,i,j,(int)data_class_ref[i][j].get_cluster_freq());
			
		}
		cvGetRows(train,&outliers1,nb_image_train,nb_image_train+nb_image_train);
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&outliers1,i,j,(int)outliers1_data[i][j].get_cluster_freq());
		}
		cvGetRows(train,&outliers2,nb_image_train+nb_image_train ,(nb_image_train*3));
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&outliers2,i,j,(int)outliers2_data[i][j].get_cluster_freq());
		}
		cvGetRows(train,&outliers3,(nb_image_train*3),(nb_image_train*4));
			
		for(int i=0; i<nb_image_train;i++)
		{
			for (int j=0;j<Total_nb_clusters;j++)
				cvmSet(&outliers3,i,j,(int)outliers3_data[i][j].get_cluster_freq());
		}
		
		cout <<" les donnees d'apprentissage est pret" << endl;

}		

/// preparer les classes { bike=1, cars=2,persons=3, motorbikes=4}
void mysvm::preparer_classes( int nb_image_ref , int nb_image_outl, CvMat * Classes)
{
		//CvMat*  response=cvCreateMat(nb_image_train*4,1,CV_32FC1);
		CvMat ref_class, outliers;
		cvGetRows(Classes,&ref_class ,0,nb_image_ref);
		for(int i=0; i<nb_image_ref;i++)
		{			
		cvmSet(&ref_class ,i,0,1);
		}
		cvGetRows(Classes,&outliers,nb_image_ref,nb_image_outl+nb_image_ref);
		for(int i=0; i<(nb_image_outl);i++)
		{
			cvmSet(&outliers ,i,0,2);
		}	
		cout <<" les classes sont aussi prets"<<endl;
}

/// appliquer l'apprentissage 
void mysvm::svm_train(CvMat* train ,CvMat* response , double gamma , double C)
{
	//khi_deux noyau;
	  time_t start,end;
	time(&start);
	CvSVMParams  param  = CvSVMParams (CvSVM::C_SVC, CvSVM::KHI, 0.0, gamma, 0.0, C,0.0, 0.0, NULL, cvTermCriteria (CV_TERMCRIT_EPS, 10000, 0.00001));
	
	// CvSVMParams( int _svm_type, int _kernel_type, double _degree, double _gamma, double _coef0, double Cvalue, double _nu, double _p, CvMat* _class_weights, CvTermCriteria _term_crit );
	//CvSVMParams param = CvSVMParams (CvSVM::C_SVC, CvSVM::POLY, 2.0, 0.01, 0.0, 1.0, 0.5, 0.1, NULL, cvTermCriteria (CV_TERMCRIT_EPS , 1000, 0.1 ));
	svms.train(train,response,0,0,param);
	//svms.train_auto(train,response,0,0,param,5);
	  time(&end);
	 cout << "time "<<difftime(end,start)<< " per sec " <<endl;
  // svms.save ("C:/Users/dawad/Desktop/VOC06/trainval/bicycle/bike_svm_train.xml", 0);
	cout<<" l'apprentissage est terminee "<<endl;
}
void mysvm::svm_train(CvMat* train ,CvMat* response)
{
	khi_deux noyau;
	vector<vector<double>> distance;
	double row=train->rows;

	
	CvSVMParams  param  = CvSVMParams (CvSVM::C_SVC, CvSVM::KHI, 0.0, 0.0005, 0.0, 10,0.0, 0.0, NULL, cvTermCriteria (CV_TERMCRIT_EPS, 1000, 0.1));
	
	// CvSVMParams( int _svm_type, int _kernel_type, double _degree, double _gamma, double _coef0, double Cvalue, double _nu, double _p, CvMat* _class_weights, CvTermCriteria _term_crit );
	//CvSVMParams param = CvSVMParams (CvSVM::C_SVC, CvSVM::POLY, 2.0, 0.01, 0.0, 1.0, 0.5, 0.1, NULL, cvTermCriteria (CV_TERMCRIT_EPS , 1000, 0.1 ));
	svms.train(train,response,0,0,param);
	
	svms.save ("Implementation_VOCC/svm_training/train_test1.xml", 0);
	cout<<" l'apprentissage est terminee "<<endl;
}
void mysvm::svm_train()
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
	param = CvSVMParams (CvSVM::C_SVC, CvSVM::POLY, 2.0, 0.01, 0.0, 1.0, 0.5, 0.1, NULL, criteria);

	svms.train(&data_mat, &res_mat, NULL, NULL, param);
}


/// create Matrix of pointers 
int** mysvm::creer_matrice (int lig, int col)
{
   int i,j;
   int **mat = (int**) malloc(lig * sizeof(int*));
   for (i = 0; i < lig; i++){
     mat[i] = (int*)malloc(col * sizeof(int));
 // for(j = 0; j < col; j++)
   //    mat[i][j] = lig * i + j; // une initialisation comme une autre
   }
   return mat;
} 

/// preparation du donnee du test 
int ** mysvm::preparer_donee_test(vector < vector < int >> & histog, int begin, int end ,int Total_nb_clusters)
{
	const int row = histog.size();
	const int cols=Total_nb_clusters;
	int ** data_test=creer_matrice(row,cols);
	for(int i=0;i<row ;i++)
	{
	 for(int j=0;j<cols;j++)
	 {
		data_test[i][j]=histog[i][j];
		
	 }
	}
	//cout <<" les donnees du test est pret" << endl;
	
	return data_test;

}
void mysvm::preparer_donee_test( int ** data_test,vector < vector < int >> & histog, int begin, int end ,int Total_nb_clusters)
{
for(int i=0;i<end ;i++)
	{
	 for(int j=0;j<Total_nb_clusters;j++)
	 {
		data_test[i][j]=histog[i][j];
		
	 }
	}
	//cout <<" les donnees du test est pret" << endl;

}
/// prepare the data for testing 
int ** mysvm::preparer_donee_test(vector < vector < bins >> & histog, int begin, int end ,int Total_nb_clusters)
{
	int row = histog.size();
	int cols=Total_nb_clusters;
	int ** data_test=creer_matrice(row,cols);
	for(int i=begin;i<end ;i++)
	{
	 for(int j=0;j<cols;j++)
	 {
		data_test[i-begin][j]=histog[i][j].get_cluster_freq();
		
	 }
	}
	//cout <<" les donnees du test est pret" << endl;
	
	return data_test;

}

/// appliquer le test de svm  et calculer la matrice de confusion 
void mysvm::svm_test(int ** data_test , int nb_images_test ,  int Total_nb_clusters )
{
	

	//cout << "bike=1, cars=2,persons=3, motorbikes=4"<<endl;
		int * _sample = new int  [Total_nb_clusters+1];
		float resp ;
	     double count1=0, count2=0, count3=0, count4=0;
		for (int i=0; i<nb_images_test ;i++)
		{
			for (int j=0;j<Total_nb_clusters+1;j++)
               _sample [j] =data_test[i][j];


			CvMat test=cvMat(1,Total_nb_clusters,CV_32FC1,_sample);

			resp=svms.predict(&test);
			
	
			switch ((int)resp)
			{
			case 1 ://class_ref
				{
				 count1=count1+1;
				 break;
				}
			case 2://outliers
				{
				count2=count2+1;
				break;
			
			  }

		}
		}
		//cout <<" la test est finie " <<endl;
		cout <<" matrice de confusion :"<<endl;
		cout << " class_ref"<< " " << " outliers   " <<endl;
		cout <<fixed<<setprecision(0)<<count1<<" "<< "          "<<count2 <<endl;
		cout <<fixed<<setprecision(2)<< (count1/nb_images_test)*100 <<"%"<< "       "<<(count2/nb_images_test)*100 <<"%" <<endl;

		
		
}

void mysvm::svm_test(int ** data_test , int nb_images_test ,  int Total_nb_clusters , double * conf)
{


	//cout << "bike=1, cars=2,persons=3, motorbikes=4"<<endl;
		float * _sample = new float  [Total_nb_clusters+1];
		float resp ;
	    double count1=0, count2=0;
		for (int i=0; i<nb_images_test ;i++)
		{
			for (int j=0;j<Total_nb_clusters+1;j++)
               _sample [j] =data_test[i][j];


			CvMat test=cvMat(1,Total_nb_clusters,CV_32FC1,_sample);

			resp=svms.predict(&test);
			
	
			switch ((int)resp)
			{
			case 1 ://class_ref
				{
				 count1=count1+1;
				 break;
				}
			case 2://outliers
				{
				count2=count2+1;
				break;
			
			  }

		}
		}
		conf[0]=count1;
		conf[1]=count2;
		//cout <<" la test est finie " <<endl;
		cout <<" matrice de confusion :"<<endl;
		cout << " class_ref"<< " " << " outliers   " <<endl;
		cout <<fixed<<setprecision(0)<<count1<<" "<< "          "<<count2 <<endl;
		cout <<fixed<<setprecision(2)<< (count1/nb_images_test)*100 <<"%"<< "       "<<(count2/nb_images_test)*100 <<"%" <<endl;

		
		
}

void mysvm::svm_test()
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
void write_csv_File(const string &fileName, vector <CVSVMResultat> table_roc)
{
	ofstream out(fileName.c_str());
	if(!out)
	{
		cout <<"\n ERROR:file could not be opened.";
	}
	out << "donnee pour prediction " <<"\n";
	out <<"Class Label"<<";"<<"DF value "<<"\n";
	for(int i=table_roc.size()-1;i>=0;i--)
	{
		
	    out <<table_roc[i].Class_label<< ";"<<table_roc[i].DFValue<<"\n" ;	
		
	}
	cout<<" the file " << fileName<<" created.";
	out.close();

}
/// this function return matrix like the confusion matrix but with different values of threshold ( index ) 

rate  mysvm::svm_test(int ** data_test , int nb_images_test , int Total_nb_clusters, double index , const string &fileName )
{
	
	//cout << "bike=1, cars=2,persons=3, motorbikes=4"<<endl;
	double count1=0, count2=0;
		
	float _sample [1][1000];
	CVSVMResultat res;
	vector <CVSVMResultat> reslt;
	for (int i=0; i<nb_images_test ;i++)
		{
		 for (int j=0;j<Total_nb_clusters;j++)
             _sample [0][j] =data_test[i][j];
		 
			CvMat test=cvMat(1,1000,CV_32FC1,_sample);
			res=svms.predict(&test,index , true);
			//cout << " ress " << res.Class_label << "  " << res.DFValue <<endl;
			reslt.push_back(res);
			switch ((int)res.Class_label)
				{
			case 1 : // class_ref
				{
				 count1=count1+1;
				 break;
				}
			case 2: //outliers
				{
				count2=count2+1;
				break;
				}
			
			}
	}
	
	write_csv_File(fileName,reslt);
	rate  freq;
	freq.set_ref_rate(count1);
	freq.set_outlier_rate(count2);
	

	//cout << " rate " << count1 << "   " << count2<<endl;

	return freq;		
			
}
void  mysvm::svm_test(rate & freq ,int ** data_test , int nb_images_test , int Total_nb_clusters, double index  )
{
	
	//cout << "bike=1, cars=2,persons=3, motorbikes=4"<<endl;
	double count1=0, count2=0;
		
	int * _sample = new int  [Total_nb_clusters];
	CVSVMResultat res;

	for (int i=0; i<nb_images_test ;i++)
		{
		 for (int j=0;j<Total_nb_clusters;j++)
             _sample [j] =data_test[i][j];
		 
			CvMat test=cvMat(1,Total_nb_clusters,CV_32FC1,_sample);
			res=svms.predict(&test,index , true);
			//cout << " ress " << res.Class_label << "  " << res.DFValue <<endl;
			
			switch ((int)res.Class_label)
				{
			case 1 : // class_ref
				{
				 count1=count1+1;
				 break;
				}
			case 2: //outliers
				{
				count2=count2+1;
				break;
				}
			
			}
	}
	freq.set_ref_rate(count1);
	freq.set_outlier_rate(count2);
	//cout << " rate " << freq.get_ref_rate() << "   " << freq.get_outlier_rate()<<endl;
}


rate  mysvm::svm_test(int ** data_test , int nb_images_test , int Total_nb_clusters, double index  )
{
	
	//cout << "bike=1, cars=2,persons=3, motorbikes=4"<<endl;
	double count1=0, count2=0;
		
	float * _sample = new float  [Total_nb_clusters];
	CVSVMResultat res;

	for (int i=0; i<nb_images_test ;i++)
		{
		 for (int j=0;j<Total_nb_clusters;j++)
             _sample [j] =data_test[i][j];
		 
			CvMat test=cvMat(1,Total_nb_clusters,CV_32FC1,_sample);
			res=svms.predict(&test,index , true);
			//cout << " ress " << res.Class_label << "  " << res.DFValue <<endl;
			
			switch ((int)res.Class_label)
				{
			case 1 : // class_ref
				{
				 count1=count1+1;
				 break;
				}
			case 2: //outliers
				{
				count2=count2+1;
				break;
				}
			
			}
	}
	
	
	rate  freq;
	freq.set_ref_rate(count1);
	freq.set_outlier_rate(count2);
	
	

	//cout << " rate " << count1 << "   " << count2<<endl;

	return freq;		
			
}

/// this function return the table that serve to draw the roc curve 
/*
void mysvm::fill_roc_table(vector<roc_row> & table_roc, vector < vector < int >> & ref_class_data , vector < vector < int >> & data_test_class2,  vector < vector < int >> & data_test_class3 , vector < vector < int >> & data_test_class4, int begin , int nb_image_test , int Total_nb_clusters ,double index_init , double index_end ,string Class_ref)
{
	for ( double ind= index_init ; ind <=index_end; ind+=0.5)
	 {
	
		//cout << " seuil " <<ind<<endl;
		 /// get the confusion matrix with different value of index for the first class ( bike)
	     int ** ref_class_data_test= preparer_donee_test(ref_class_data,begin, begin+nb_image_test ,Total_nb_clusters);
	 	 rate row1= svm_test(ref_class_data_test,nb_image_test,Total_nb_clusters,ind);
		 /// get the confusion matrix with different value of index for the second class ( cars)
		int ** data_test_Class2= preparer_donee_test(data_test_class2,begin, begin+nb_image_test ,Total_nb_clusters);
		rate row2=svm_test(data_test_Class2,nb_image_test,Total_nb_clusters,ind);
		 /// get the confusion matrix with different value of index for the third class ( persons)
		int ** data_test_Class3=preparer_donee_test(data_test_class3,begin, begin+nb_image_test ,Total_nb_clusters);
		rate row3=svm_test(data_test_Class3,nb_image_test,Total_nb_clusters,ind);
		 /// get the confusion matrix with different value of index for the first class ( moto)
		int ** data_test_Class4=preparer_donee_test(data_test_class4,begin, begin+nb_image_test ,Total_nb_clusters);
		rate row4=svm_test(data_test_Class4,nb_image_test,Total_nb_clusters,ind);
		// in this set of conditions we calculated the value of TPr and FPr depending on the choosed class-reference
		roc_row lig;
		
			
					lig.set_TP_rate(row1.get_ref_rate()/nb_image_test);
					lig.set_FP_rate ((row2.get_ref_rate()+row3.get_ref_rate()+row4.get_ref_rate())/(nb_image_test*3));
					lig.set_threshold(ind);
				
		table_roc.push_back(lig);
	}
}*/
void mysvm::fill_roc_table(vector<roc_row> & table_roc, vector < vector < int >> & ref_class_data , vector < vector < int >> & data_test_class2, int begin , int Total_nb_clusters ,double index_init , double index_end ,string Class_ref)
{
	int ** ref_class_data_test = creer_matrice(ref_class_data.size(),Total_nb_clusters);
	int** data_test_outl =creer_matrice(data_test_class2.size(),Total_nb_clusters);
	
	  
	for ( double ind= index_init ; ind <=index_end; ind+=0.5)
	 {
   
	preparer_donee_test(ref_class_data_test,ref_class_data,begin, begin+ref_class_data.size() ,Total_nb_clusters);
    rate row1=svm_test(ref_class_data_test,ref_class_data.size(),Total_nb_clusters,ind);
	preparer_donee_test(data_test_outl,data_test_class2,begin, begin+data_test_class2.size() ,Total_nb_clusters);
    rate row2=svm_test(data_test_outl,data_test_class2.size(),Total_nb_clusters,ind);
	roc_row lig;

		lig.set_TP_rate(row1.get_ref_rate()/ref_class_data.size());
		lig.set_FP_rate ((row2.get_ref_rate())/(data_test_class2.size()));
		lig.set_threshold(ind);
				
		table_roc.push_back(lig);
       mysvm::initialiser_matrice(ref_class_data_test,ref_class_data.size(),Total_nb_clusters);
	   mysvm::initialiser_matrice(data_test_outl,data_test_class2.size(),Total_nb_clusters);
	   row1.~rate();
	   row2.~rate();
	}
	free(ref_class_data_test);
	free(data_test_outl);
}
/*
void mysvm::fill_roc_table(vector<roc_row> & table_roc, vector < vector < bins >> & ref_class_data , vector < vector < bins >> & data_test_class2,  vector < vector < bins >> & data_test_class3 , vector < vector < bins >> & data_test_class4, int begin , int nb_image_test , int Total_nb_clusters ,double index_init , double index_end ,string Class_ref)
{
	for ( double ind= index_init ; ind <=index_end; ind+=0.5)
	 {
	
		//cout << " seuil " <<ind<<endl;
		 /// get the confusion matrix with different value of index for the first class ( bike)
	     int ** ref_class_data_test= preparer_donee_test(ref_class_data,begin, begin+nb_image_test ,Total_nb_clusters);
	 	 rate row1= svm_test(ref_class_data_test,nb_image_test,Total_nb_clusters,ind);
		 /// get the confusion matrix with different value of index for the second class ( cars)
		int ** data_test_Class2= preparer_donee_test(data_test_class2,begin, begin+nb_image_test ,Total_nb_clusters);
		rate row2=svm_test(data_test_Class2,nb_image_test,Total_nb_clusters,ind);
		 /// get the confusion matrix with different value of index for the third class ( persons)
		int ** data_test_Class3=preparer_donee_test(data_test_class3,begin, begin+nb_image_test ,Total_nb_clusters);
		rate row3=svm_test(data_test_Class3,nb_image_test,Total_nb_clusters,ind);
		 /// get the confusion matrix with different value of index for the first class ( moto)
		int ** data_test_Class4=preparer_donee_test(data_test_class4,begin, begin+nb_image_test ,Total_nb_clusters);
		rate row4=svm_test(data_test_Class4,nb_image_test,Total_nb_clusters,ind);
		// in this set of conditions we calculated the value of TPr and FPr depending on the choosed class-reference
		roc_row lig;
		
			
					lig.set_TP_rate(row1.get_ref_rate()/nb_image_test);
					lig.set_FP_rate ((row2.get_ref_rate()+row3.get_ref_rate()+row4.get_ref_rate())/(nb_image_test*3));
					lig.set_threshold(ind);
				
		table_roc.push_back(lig);
	}
}*/
double mysvm::Trapezoid_area( double x1, double x2, double y1, double y2)
{
	double base= x1-x2;
	base = (base >0 )? base : (base* -1);
	double height= ( y1+y2) /2;
	double area = base*height;
	return area ;
}

double mysvm::calc_AUC(vector<roc_row> & table_roc)
{
	double area=0;
	//double N= (nb_image_train*3);
	for (int i=1 , j=i-1; i<=(table_roc.size()-2) , j<(table_roc.size()-1); i++ , j++)
	{
		double temp=Trapezoid_area(table_roc[i].get_FP_rate(),table_roc[j].get_FP_rate(),table_roc[i].get_TP_rate() , table_roc[j].get_TP_rate());
		area= area+ temp ;
	}
	double auc= area;
	return auc;
}