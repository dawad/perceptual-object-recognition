#include "stdafx.h"

#include "khi_deux.h"
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

using namespace cv;
using namespace std ;

#if 1
typedef float Qfloat;
#define QFLOAT_TYPE CV_32F
#else
typedef double Qfloat;
#define QFLOAT_TYPE CV_64F
#endif

khi_deux::khi_deux(void)
{
}


khi_deux::~khi_deux(void)
{
}


/*double** khi_deux::creer_matrice (int lig, int col)
{
   int i, j;
   double **mat = (double**) malloc(lig * sizeof(double*));
   for (i = 0; i < lig; i++)
   {
     mat[i] = (double*)malloc(col * sizeof(double));
     for(j = 0; j < col; j++)
       mat[i][j] = lig * i + j; // une initialisation comme une autre
   }
   return mat;
} 

 double  ** khi_deux::GetTrainData(CvMat * train , int nb_image_train, int total_cluster)
{
	 double ** sample =creer_matrice (nb_image_train, total_cluster);
	 for (int i=0; i< nb_image_train ;i++)
	   {
		 for (int j=0;j< total_cluster;j++)
		  {
			  sample[i][j]=cvmGet(train,i,j);
		  }
	   }

	 return sample;
}
void  khi_deux::Calcul_khiDeux_distance(double ** &train , vector <vector <double>> & distance,int nb_image_train, int total_cluster )
{
	
	vector <double > sub_distance;
	 sub_distance.resize(nb_image_train);

	 for (int i=0; i< nb_image_train ;i++)
	   {
	    const double * another  = train[i];
	   
		 for (int j=0;j< nb_image_train;j++)
		  {
			 double s=0;
			  for (int k=0; k<total_cluster;k++)
			  {
				  double t0=train[j][k]-another[k];
				  double t1=train[j][k]+another[k];
				  double t2=t1==0?1:t1;
				  s+=(t0*t0)/t1;
			  }
			  sub_distance[j]=s;
		  
		 distance.push_back(sub_distance);
	   }
}
}

double khi_deux::Get_A_Parameter( vector <vector <double>> & distance)
{
	double size=distance.size();
	double somme=0;
	for(int i=0;i<distance.size();i++)
		for(int j=0;j<distance.at(i).size();j++)
		{
			somme += distance[i][j];
		}

		double moy=somme/(size*size);

		return moy;
}



// integrer directemment dans le CVSVMKernel 

/*void CvSVMKernel:: calc_khi_deux(int vcount, int var_count,const float** vecs, const float * another , Qfloat* results)
{
	CvMat R = cvMat( 1, vcount, QFLOAT_TYPE, results );
    double gamma = -params->gamma;
    int j, k;

    for( j = 0; j < vcount; j++ )
    {
        const float* sample = vecs[j];
        double s = 0;

        for( k = 0; k <= var_count - 4; k += 4 )
        {
            double t0 = sample[k] - another[k];
            double t1 = sample[k+1] - another[k+1];
			double t2=  sample[k] + another[k];
			double t3=sample[k+1] + another[k+1];

            s += (t0*t0)/ t2 + (t1*t1)/t3;

            t0 = sample[k+2] - another[k+2];
            t1 = sample[k+3] - another[k+3];
			t2=sample[k+2]+ another[k+2];
			t3=sample[k+3] + another[k+3];

            s += (t0*t0)/t2 + (t1*t1)/t3;
        }

        for( ; k < var_count; k++ )
        {
            double t0 = sample[k] - another[k];
			double t2=sample[k] + another[k];;
            s += (t0*t0)/t2;
        }
        results[j] = (Qfloat)((0.5*s)*(1/gamma));
    }

    if( vcount > 0 )
        cvExp( &R, &R );
	}

bool CvSVMKernel::create( const CvSVMParams* _params, Calc _calc_func)
{
	 clear();
    params = _params;
    calc_func = _calc_func;

    if( !calc_func )
        calc_func = params->kernel_type == CvSVM::RBF ? &CvSVMKernel::calc_rbf :
		            params->kernel_type == CvSVM::KHI ? &CvSVMKernel::calc_khi_deux:
                    params->kernel_type == CvSVM::POLY ? &CvSVMKernel::calc_poly :
                    params->kernel_type == CvSVM::SIGMOID ? &CvSVMKernel::calc_sigmoid :
                    &CvSVMKernel::calc_linear;

    return true;
}
*/