	// zhang_impl_v1.cpp : Defines the entry point for the console application.
	//

	#include "stdafx.h"

	#include "Fichiers/Fichiers.h"
	#include "kmean\kmean.h"
	#include "histograms\histograms.h"
	#include "mysvm\mysvm.h"
//#include "Common\roc_row.h"

/*	void main() 
	{
	
	const int nb_fichiers=2;
	Fichiers file;
	/*
	/// read the descriptor of Person  class from files 
	vector <vector <float > > descriptors_person ; 
	//string fichiers_person[nb_fichiers]={"Implementation_VOCC/old_data/TUGraz_person/TUGraz_person.log.sift-desc.txt","Implementation_VOCC/old_data/TUGraz_person/TUGraz_person.har.sift-desc.txt"};
	string fichiers_person[nb_fichiers]={"Implementation_VOCC/Train/persons/persons.log.sift.desc.txt","Implementation_VOCC/Train/persons/persons.har.sift.desc.txt"};
	file.read_multi_files(fichiers_person,nb_fichiers,descriptors_person);
	cout << " size of sift keypoint for persons " << descriptors_person.size()<<endl;

	/// read the descriptor of cars class from files
	//string fichiers_cars [2] ={"Implementation_VOCC/old_data/cars/cars.har.sift.txt" ,"Implementation_VOCC/old_data/cars/cars.log.sift.txt"};

	string fichiers_cars [2] ={"Implementation_VOCC/Train/cars/cars.har.sift.desc.txt" ,"Implementation_VOCC/Train/cars/cars.log.sift.desc.txt"};
	vector<vector< float>> descriptors_cars ;
	file.read_multi_files(fichiers_cars,nb_fichiers,descriptors_cars);

	/// read the descriptor of moto class from files 
	
	vector < vector<float  >> descriptors_moto;
	//string fichiers_moto[nb_fichiers]={"Implementation_VOCC/old_data/Caltech_motorbikes_side/Caltech_motorbikes_side.har.desc.txt","Implementation_VOCC/old_data/Caltech_motorbikes_side/Caltech_motorbikes_side.log.sift-desc.txt"};

	string fichiers_moto[nb_fichiers]={"Implementation_VOCC/Train/moto/moto.har.sift.desc.txt","Implementation_VOCC/Train/moto/moto.log.sift.desc.txt"};
	file.read_multi_files(fichiers_moto,nb_fichiers,descriptors_moto);
	
	///read  the descriptors of bike class from files 
	//string fichiers_bike[nb_fichiers]={"Implementation_VOCC/old_data/TUGraz_bike/TUGraz_bike.log.sift-desc.txt","Implementation_VOCC/old_data/TUGraz_bike/TUGraz_bike.har.sift-desc.txt"};

	string fichiers_bike[nb_fichiers]={"Implementation_VOCC/Train/bike/bike.har.desc.sift.txt","Implementation_VOCC/Train/bike/bike.log.desc.txt"};
	vector<vector<float >> descriptors_bike;
	file.read_multi_files(fichiers_bike,nb_fichiers,descriptors_bike);
	*/
	/*
	/// definition des class pour kmean 
	kmean k_means;

	/// definition des parametres necessaires 
	int nb_random=k_means.set_Nb_instance_random(50000);
	int desc_dim=k_means.set_desc_dimension(128);
	int nb_centers=k_means.set_nb_clusters(250);
	
	/// remove the unecessary data from the table and select randomly the descriptors from the table for the person class 
	Mat data_person (nb_random,desc_dim,CV_32FC1);
	data_person=k_means.select_randomly_desc(descriptors_person,nb_random,desc_dim);

	/// remove the unecessary data from the table and select randomly the descriptors from the table for the cars class 
	Mat data_cars (nb_random,desc_dim,CV_32FC1);
	data_cars=k_means.select_randomly_desc(descriptors_cars,nb_random,desc_dim);

	// remove the unecessary data from the table and select randomly the descriptors from the table for the moto class 
	Mat data_moto (nb_random,desc_dim,CV_32FC1);
	data_moto=k_means.select_randomly_desc(descriptors_moto,nb_random,desc_dim);

	/// remove the unecessary data from the table and select randomly the descriptors from the table for the bike class 
	Mat data_bike (nb_random,desc_dim,CV_32FC1);
	data_bike=k_means.select_randomly_desc(descriptors_bike,nb_random,desc_dim);

	// defintion des matrice pour le centers et les labels pour chaque descriptor ( clusters_person ) pour la classe person
	Mat clusters_person(nb_random,1,CV_32SC1);
	Mat centers_person(nb_centers,desc_dim,CV_32FC1);

	/// defintion des matrice pour le centers et les labels pour chaque descriptor ( clusters_person ) pour la classe cars
	Mat clusters_cars(nb_random,1,CV_32SC1);
	Mat centers_cars(nb_centers,desc_dim,CV_32FC1);

	/// defintion des matrice pour le centers et les labels pour chaque descriptor ( clusters_person ) pour la classe bike
	Mat clusters_bike(nb_random,1,CV_32SC1);
	Mat centers_bike(nb_centers,desc_dim,CV_32FC1);

	/// defintion des matrice pour le centers et les labels pour chaque descriptor ( clusters_person ) pour la classe moto
	Mat clusters_moto(nb_random,1,CV_32SC1);
	Mat centers_moto(nb_centers,desc_dim,CV_32FC1);

	/// implement kmean function existed in openCv
	k_means.openCv_kmean(data_person,clusters_person,centers_person,nb_centers);
	k_means.openCv_kmean(data_cars,clusters_cars,centers_cars,nb_centers);
	k_means.openCv_kmean(data_bike,clusters_bike,centers_bike,nb_centers);
	k_means.openCv_kmean(data_moto,clusters_moto,centers_moto,nb_centers);
	*/
	/*
	
/// read filter SIFT training data 
	
	vector <vector <float > > descriptors_person ; 
	//string fichiers_person="../../filter_SIFT/filter_SIFT/itti_res/Train/persons_SIFT(th=0).txt";
	string fichiers_person="filtered_sift/Train/th=85/persons_SIFT(th=85).txt";
	file.read_files(fichiers_person,descriptors_person);
	 cout << " size of SIFt pts for persons  " <<descriptors_person.size()<<endl<<endl;
    vector<vector<float >> descriptors_bike;
	//string fichiers_bike="../../filter_SIFT/filter_SIFT/itti_res/Train/bike_SIFT(th=0).txt";
	string fichiers_bike="filtered_sift/Train/th=51/bike_SIFT(th=51).txt";
    file.read_files(fichiers_bike,descriptors_bike);

	vector < vector<float  >> descriptors_moto;
	//string fichiers_moto="../../filter_SIFT/filter_SIFT/itti_res/Train/moto_SIFT(th=0).txt";
	string fichiers_moto="filtered_sift/Train/th=102/moto_SIFT(th=102).txt";
    file.read_files(fichiers_moto,descriptors_moto); 

	vector<vector< float>> descriptors_cars ;
	//string fichiers_cars="../../filter_SIFT/filter_SIFT/itti_res/Train/cars_SIFT(th=0).txt";
	string fichiers_cars="filtered_sift/Train/th=85/cars_SIFT(th=85).txt";
	file.read_files(fichiers_cars,descriptors_cars);


	
		   

	 
	 
	 
	

	/// declaration of histogram object
	/*histograms histog;
	
	vector < vector < float >> keypoints;
	histog.concatenate_clusters_centers(centers_person, centers_cars,centers_bike,centers_moto, keypoints);
	file .write_txt("Implementation_VOCC/result/keypoint_3_3.txt",keypoints);*/
/*
	 //	Fichiers file;
histograms histog;
int nb_centers=250;
vector < vector < float >> keypoints;
file.read_ASCII_files("Implementation_VOCC/result/keypoint_3_3.txt",keypoints);


	/// sort the descriptors dependind on File id 
	histog.sort_descripteurs(descriptors_person);
	   cout << " size of SIFt pts for persons  " <<descriptors_person.size()<<endl<<endl;
	histog.sort_descripteurs(descriptors_cars);
	   cout << " size of SIFt pts for cars  " <<descriptors_cars.size()<<endl<<endl;
	histog.sort_descripteurs(descriptors_moto);
	 cout << " size of SIFt pts for moto  " <<descriptors_moto.size()<<endl<<endl;
	histog.sort_descripteurs(descriptors_bike);
	  cout << " size of SIFt pts for bike  " <<descriptors_bike.size()<<endl<<endl;

	/// get the last fileid 
	float img_id_last_person=histog.get_last_element(descriptors_person);
	float img_id_last_cars=histog.get_last_element(descriptors_cars);
	float img_id_last_moto=histog.get_last_element(descriptors_moto);
	float img_id_last_bike=histog.get_last_element(descriptors_bike);

	/// calculer les distances entres chaque descripteurs et toutes les centres de keypoint  et prendre le centre la plus proche pour chaque points 
	vector<word> distance_pers,distance_cars,distance_moto,distance_bike; 
	histog.Calculer_min_distance(keypoints, descriptors_person,distance_pers,(nb_centers*4));
	histog.Calculer_min_distance(keypoints, descriptors_cars,distance_cars,(nb_centers*4));
	histog.Calculer_min_distance(keypoints, descriptors_moto,distance_moto,(nb_centers*4));
	histog.Calculer_min_distance(keypoints, descriptors_bike,distance_bike,(nb_centers*4));

	

	/// Calculer toutes les histogrammes du class personne

	
	vector<vector<bins>> table_histograms_pers ,table_histograms_cars,table_histograms_moto,table_histograms_bike;


	histog.get_all_histograms(table_histograms_pers,img_id_last_person,distance_pers,(nb_centers*4));
	histog.get_all_histograms(table_histograms_cars,img_id_last_cars,distance_cars,(nb_centers*4));
	histog.get_all_histograms(table_histograms_moto,img_id_last_moto,distance_moto,(nb_centers*4));
	histog.get_all_histograms(table_histograms_bike,img_id_last_bike,distance_bike,(nb_centers*4));


		float s=0;
				for(int i=0;i<table_histograms_pers.size(); i++)
				{
					for (int j=0;j<table_histograms_pers.at(i).size();j++)
					{
						s+=table_histograms_pers[i][j].get_cluster_freq();
					}
				}
		cout <<" la somme total d'histo est " << s <<endl;
	
	file.write_txt("itti_heatmap/res/persons_histog(th=85).txt",table_histograms_pers);
	file.write_txt("itti_heatmap/res/cars_histog(th=85).txt",table_histograms_cars);
	file.write_txt("itti_heatmap/res/moto_histog(th=85).txt",table_histograms_moto);
	file.write_txt("itti_heatmap/res/bike_histog(th=85).txt",table_histograms_bike);
	
	/*
/// lire les fichiers contient les keypoints 

/// lire fichiers des histogrammes 
 typedef std ::vector<int> sub_test; 
	     vector<sub_test> table_histograms_bike;
		 vector<sub_test> table_histograms_cars;
		 vector<sub_test> table_histograms_pers;
		 vector<sub_test> table_histograms_moto;
file.read_ASCII_files("Implementation_VOCC/result/persons_histog(th=90%).txt",table_histograms_pers);
file.read_ASCII_files("Implementation_VOCC/result/cars_histog(th=90%).txt",table_histograms_cars);
file.read_ASCII_files("Implementation_VOCC/result/moto_histog(th=90%).txt",table_histograms_moto);
file.read_ASCII_files("Implementation_VOCC/result/bike_histog(th=90%).txt",table_histograms_bike);
*/
/*
	
/// test data 

	/// read the descriptor of   class from files 

	    vector <vector <float > > descriptors_person_Testing ; 
	    vector <vector <float > > descriptors_bike_Testing ; 
		vector <vector <float > > descriptors_cars_Testing ; 
	    vector <vector <float > > descriptors_moto_Testing ; 
	
	/*
	    string fichiers_person_testing[nb_fichiers]={"Implementation_VOCC/Testing/persons/persons.log.sift.desc.txt","Implementation_VOCC/Testing/persons/persons.har.sift.desc.txt"};
	    file.read_multi_files(fichiers_person_testing,nb_fichiers,descriptors_person_Testing);

		string fichiers_bike_testing[nb_fichiers]={"Implementation_VOCC/Testing/bike/bike.har.desc.txt","Implementation_VOCC/Testing/bike/bike.log.desc.txt"};
	    file.read_multi_files(fichiers_bike_testing,nb_fichiers,descriptors_bike_Testing);

		string fichiers_cars_testing[nb_fichiers]={"Implementation_VOCC/Testing/cars/cars.har.sift.desc.txt","Implementation_VOCC/Testing/cars/cars.log.sift.desc.txt"};
	    file.read_multi_files(fichiers_cars_testing,nb_fichiers,descriptors_cars_Testing);

		string fichiers_moto_testing[nb_fichiers]={"Implementation_VOCC/Testing/moto/moto.har.sift.desc.txt","Implementation_VOCC/Testing/moto/moto.log.sift.desc.txt"};
	    file.read_multi_files(fichiers_moto_testing,nb_fichiers,descriptors_moto_Testing);
		*/
		
	/*	
		//string fichiers_person_testing="../../filter_SIFT/filter_SIFT/itti_res/Testing/persons_SIFT(th=0).txt";
		string fichiers_person_testing="filtered_sift/Testing/th=85/persons_SIFT(th=85).txt";
		file.read_files(fichiers_person_testing,descriptors_person_Testing);		
		
		string fichiers_bike_testing="filtered_sift/Testing/th=102/bike_SIFT(th=102).txt";
		 file.read_files(fichiers_bike_testing,descriptors_bike_Testing);
									
		 string fichiers_moto_testing="filtered_sift/Testing/th=102/moto_SIFT(th=102).txt";
		   file.read_files(fichiers_moto_testing,descriptors_moto_Testing);

		 string fichiers_cars_testing="filtered_sift/Testing/th=68/cars_SIFT(th=68).txt";
		 file.read_files(fichiers_cars_testing,descriptors_cars_Testing);
		 
		/// sort the descriptors
	    histog.sort_descripteurs(descriptors_person_Testing);
		   cout << " size of SIFt pts for persons  " <<descriptors_person_Testing.size()<<endl<<endl;
		histog.sort_descripteurs(descriptors_bike_Testing);
		   cout << " size of SIFt pts for bike " <<descriptors_bike_Testing.size()<<endl<<endl;
	    histog.sort_descripteurs(descriptors_cars_Testing);
		   cout << " size of SIFt pts for cars " <<descriptors_cars_Testing.size()<<endl<<endl;
	   histog.sort_descripteurs(descriptors_moto_Testing);
		   cout << " size of SIFt pts for moto " <<descriptors_moto_Testing.size()<<endl<<endl;
		   
			 /// get the id of last image
		    float img_id_last_person_testing=histog.get_last_element(descriptors_person_Testing);		 
			float img_id_last_bike_testing=histog.get_last_element(descriptors_bike_Testing);
			float img_id_last_cars_testing=histog.get_last_element(descriptors_cars_Testing);
			float img_id_last_moto_testing=histog.get_last_element(descriptors_moto_Testing);


		/// calculer le min distance entre les descriptors et les keoypoints
		vector<word> distance_pers_testing;
		histog.Calculer_min_distance(keypoints, descriptors_person_Testing,distance_pers_testing,(nb_centers*4));

		vector<word> distance_bike_testing;
		histog.Calculer_min_distance(keypoints, descriptors_bike_Testing,distance_bike_testing,(nb_centers*4));

			vector<word> distance_cars_testing;
		histog.Calculer_min_distance(keypoints, descriptors_cars_Testing,distance_cars_testing,(nb_centers*4));

			vector<word> distance_moto_testing;
		histog.Calculer_min_distance(keypoints, descriptors_moto_Testing,distance_moto_testing,(nb_centers*4));

		/// calculer l'histogramme pour chaque image et les sauvegarder dans un tableau
		vector<vector<bins>> table_histograms_pers_Testing;
		histog.get_all_histograms(table_histograms_pers_Testing,img_id_last_person_testing,distance_pers_testing,(nb_centers*4));
		//file.write_txt("Implementation_VOCC/result/res_test_histo/persons_histog_test().txt",table_histograms_pers_Testing);

		vector<vector<bins>> table_histograms_bike_Testing;
		histog.get_all_histograms(table_histograms_bike_Testing,img_id_last_bike_testing,distance_bike_testing,(nb_centers*4));
		//file.write_txt("Implementation_VOCC/result/res_test_histo/bike_histog_test().txt",table_histograms_bike_Testing);
	

		vector<vector<bins>> table_histograms_cars_Testing;
		histog.get_all_histograms(table_histograms_cars_Testing,img_id_last_cars_testing,distance_cars_testing,(nb_centers*4));
		//file.write_txt("Implementation_VOCC/result/res_test_histo/cars_histog_test().txt",table_histograms_cars_Testing);

		vector<vector<bins>> table_histograms_moto_Testing;
		histog.get_all_histograms(table_histograms_moto_Testing,img_id_last_moto_testing,distance_moto_testing,(nb_centers*4));
		//file.write_txt("Implementation_VOCC/result/res_test_histo/moto_histog_test().txt",table_histograms_moto_Testing);

	// definition du svm 
	mysvm  test_svm;
		int  nb_image_trains=112;
		int nb_total = nb_image_trains *4;
	//histograms histo_test=histograms();
	//Fichiers file_test=Fichiers();
		vector<roc_row> table_roc;
			int nb_images_test=56;
		/*
    /// svm classifer for persons class 
			///preparer les donnees pour l'apprentissage
			CvMat * train =cvCreateMat(nb_total,(nb_centers*4),CV_32FC1);
			test_svm.preparer_donnee_apprentissage(table_histograms_pers,table_histograms_cars,table_histograms_moto,table_histograms_bike,(nb_centers*4),nb_image_trains,train, "persons");
			/// definir les classes selon les donnees repmlis dans le methode ci_dessus 
			CvMat*  response=cvCreateMat(nb_total,1,CV_32FC1);
			test_svm.preparer_classes(nb_image_trains,response);
			/// faire l'apprentissage 
			test_svm.svm_train(train, response,0.0002,10);
		/// ecrire dans un fichier arff 
		//file.write_arff("Implementation_VOCC/svm_training/train.arff",train,response);

		

		/// preparer les donnes pour le test
		int nb_images_test=56;
		cout<< " test for persons "  <<endl;		
		/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_pers= test_svm.preparer_donee_test(table_histograms_pers_Testing,0,nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_pers,nb_images_test,(nb_centers*4));	
		
		cout << " test for bike "<<endl;		
		/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_bike= test_svm.preparer_donee_test(table_histograms_bike_Testing,0, nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_bike,nb_images_test,(nb_centers*4));


		cout <<" test for cars " <<endl;		
		/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_cars= test_svm.preparer_donee_test(table_histograms_cars_Testing,0,nb_images_test ,(nb_centers*4));
	    test_svm.svm_test(data_test_cars,nb_images_test,(nb_centers*4));

		cout <<" test for moto " <<endl;		
		/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_moto= test_svm.preparer_donee_test(table_histograms_moto_Testing,0,nb_images_test ,(nb_centers*4));
		test_svm.svm_test(data_test_moto,nb_images_test,(nb_centers*4));
		
		vector<roc_row> table_roc;
		// bikes    cars   persons   Moto
		test_svm.fill_roc_table(table_roc,table_histograms_pers_Testing,table_histograms_bike_Testing, table_histograms_cars_Testing,table_histograms_moto_Testing,0,nb_images_test,(nb_centers*4),-5,4,"persons");
		file.write_csv_File("itti_heatmap/res/roc_pers_khi(th=85.85).csv",table_roc);
		
		double auc=test_svm.calc_AUC(table_roc);
		cout << " \n Area under curve  ( auc ) : " << auc <<endl;
		table_roc.clear();
		
		// svm classifier for cars class
		///preparer les donnees pour l'apprentissage
			//CvMat * train =cvCreateMat(nb_total,(nb_centers*4),CV_32FC1);
			test_svm.preparer_donnee_apprentissage(table_histograms_cars,table_histograms_pers,table_histograms_moto,table_histograms_bike,(nb_centers*4),nb_image_trains,train, "cars");
			/// definir les classes selon les donnees repmlis dans le methode ci_dessus 
			//CvMat*  response=cvCreateMat(nb_total,1,CV_32FC1);
			test_svm.preparer_classes(nb_image_trains,response);
			/// faire l'apprentissage 
			test_svm.svm_train(train, response,0.0003,10);
		/// ecrire dans un fichier arff 
		//file.write_arff("Implementation_VOCC/svm_training/train.arff",train,response);

		

	/// preparer les donnes pour le test
//		int nb_images_test=56;
		cout <<"test for cars" <<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_cars_1= test_svm.preparer_donee_test(table_histograms_cars_Testing,0, nb_images_test ,(nb_centers*4));
	    test_svm.svm_test(data_test_cars_1,nb_images_test,(nb_centers*4));

		cout<< " test for persons "  <<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_pers_1= test_svm.preparer_donee_test(table_histograms_pers_Testing,0  ,nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_pers_1,nb_images_test,(nb_centers*4));	

		cout << " test for bike "<<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_bike_1= test_svm.preparer_donee_test(table_histograms_bike_Testing,0 , nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_bike_1,nb_images_test,(nb_centers*4));

		cout <<" test for moto " <<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_moto_1= test_svm.preparer_donee_test(table_histograms_moto_Testing,0 ,nb_images_test ,(nb_centers*4));
		test_svm.svm_test(data_test_moto_1,nb_images_test,(nb_centers*4));
		
//		vector<roc_row> table_roc;
		// bikes    cars   persons   Moto
		test_svm.fill_roc_table(table_roc,table_histograms_cars_Testing,table_histograms_pers_Testing,table_histograms_bike_Testing, table_histograms_moto_Testing,0,nb_images_test,(nb_centers*4),-5,4,"cars");
		file.write_csv_File("itti_heatmap/res/roc_cars_khi(th=85.85).csv",table_roc);
		
	    double _auc=test_svm.calc_AUC(table_roc);
		cout << " \n Area under curve  ( auc ) : " << _auc <<endl;
		table_roc.clear();
	// svm classifier for bike 
		///preparer les donnees pour l'apprentissage
	//		CvMat * train =cvCreateMat(nb_total,(nb_centers*4),CV_32FC1);
			test_svm.preparer_donnee_apprentissage(table_histograms_bike,table_histograms_cars,table_histograms_pers,table_histograms_moto,(nb_centers*4),nb_image_trains,train, "bike");
			/// definir les classes selon les donnees repmlis dans le methode ci_dessus 
	//		CvMat*  response=cvCreateMat(nb_total,1,CV_32FC1);
			test_svm.preparer_classes(nb_image_trains,response);
			/// faire l'apprentissage 
			test_svm.svm_train(train, response,0.002,10);
		/// ecrire dans un fichier arff 
		//file.write_arff("Implementation_VOCC/svm_training/train.arff",train,response);

		

		/// preparer les donnes pour le test
	//	int nb_images_test=56;

		cout << " test for bike "<<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_bike_2= test_svm.preparer_donee_test(table_histograms_bike_Testing,0 , nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_bike_2,nb_images_test,(nb_centers*4));

		cout<< " test for persons "  <<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_pers_2= test_svm.preparer_donee_test(table_histograms_pers_Testing,0,nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_pers_2,nb_images_test,(nb_centers*4));

		cout <<"test for cars" <<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_cars_2= test_svm.preparer_donee_test(table_histograms_cars_Testing,0, nb_images_test ,(nb_centers*4));
	    test_svm.svm_test(data_test_cars,nb_images_test,(nb_centers*4));

		cout <<" test for moto " <<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_moto_2= test_svm.preparer_donee_test(table_histograms_moto_Testing,0 ,nb_images_test ,(nb_centers*4));
		test_svm.svm_test(data_test_moto_2,nb_images_test,(nb_centers*4));
		
		//vector<roc_row> table_roc;
		// bikes    cars   persons   Moto
		test_svm.fill_roc_table(table_roc,table_histograms_bike_Testing,table_histograms_cars_Testing,table_histograms_pers_Testing, table_histograms_moto_Testing,0,nb_images_test,(nb_centers*4),-5,4,"bike");
		                                                                             //(th=test,app)
		file.write_csv_File("itti_heatmap/res/roc_bike_khi(th=85.85).csv",table_roc);

	    double auc_1=test_svm.calc_AUC(table_roc);
		cout << " \n Area under curve  ( auc ) : " << auc_1 <<endl;
		
		table_roc.clear();
		*/
/*
// svm for moto
///preparer les donnees pour l'apprentissage
			CvMat * train =cvCreateMat(nb_total,(nb_centers*4),CV_32FC1);
			test_svm.preparer_donnee_apprentissage(table_histograms_moto,table_histograms_bike,table_histograms_cars,table_histograms_pers,(nb_centers*4),nb_image_trains,train, "bike");
			/// definir les classes selon les donnees repmlis dans le methode ci_dessus 
			CvMat*  response=cvCreateMat(nb_total,1,CV_32FC1);
			test_svm.preparer_classes(nb_image_trains,response);
			/// faire l'apprentissage 
			test_svm.svm_train(train, response,0.0005,10);
		/// ecrire dans un fichier arff 
		//file.write_arff("Implementation_VOCC/svm_training/train.arff",train,response);

		

		/// preparer les donnes pour le test
		//int nb_images_test=56;

		cout <<" test for moto " <<endl;
					/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_moto_3= test_svm.preparer_donee_test(table_histograms_moto_Testing,0 ,nb_images_test ,(nb_centers*4));
		test_svm.svm_test(data_test_moto_3,nb_images_test,(nb_centers*4));
		
		cout << " test for bike "<<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_bike_3= test_svm.preparer_donee_test(table_histograms_bike_Testing,0 , nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_bike_3,nb_images_test,(nb_centers*4));

	  	cout<< " test for persons "  <<endl;
				/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_pers_3= test_svm.preparer_donee_test(table_histograms_pers_Testing,0  ,nb_images_test ,(nb_centers*4));
		/// tester les donnees 
		test_svm.svm_test(data_test_pers_3,nb_images_test,(nb_centers*4));	

		
		cout <<"test for cars" <<endl;
			/// preparer les donnees des hitogrammes obtenus pour le test
		int ** data_test_cars_3= test_svm.preparer_donee_test(table_histograms_cars_Testing,0, nb_images_test ,(nb_centers*4));
	    test_svm.svm_test(data_test_cars_3,nb_images_test,(nb_centers*4));
		
	//	vector<roc_row> table_roc;
		// bikes    cars   persons   Moto
		test_svm.fill_roc_table(table_roc,table_histograms_moto_Testing,table_histograms_bike_Testing,table_histograms_cars_Testing,table_histograms_pers_Testing, 0,nb_images_test,(nb_centers*4),-5,4,"moto");
		file.write_csv_File("itti_heatmap/res/roc_moto_khi(th=85.85).csv",table_roc);
		
		double auc_moto=test_svm.calc_AUC(table_roc);
		cout << " \n Area under curve  ( auc ) : " << auc_moto <<endl;
		cout << " the program is finished" <<endl;
}

*/