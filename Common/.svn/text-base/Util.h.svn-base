


#include "../stdafx.h"

#include<iostream>
#include<fstream>
#include "cv.h"
#include "highgui.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <windows.h>


using namespace cv;
using namespace std ;


namespace Util
{
	/*
	 * Teste si un element appartient a un vecteur
	 */
	template <class T>
	static bool contains(std::vector<T> vec, T val)
	{
		return (find(vec.begin(),vec.end(),val)!=vec.end());
	}

	/*
	 * Convertit en type T a partir d'une chaine
	 */
	template<class T> T fromString(const std::string& s)
	{
		std::istringstream stream (s);
		T t;
		stream >> t;
		return t;
	}
}
