#pragma once
class rate
{
private:
float class_ref_rate;
float outliers_rate;

public:
	rate(void);
	~rate(void);
	void initialiser_rates()
	{
		class_ref_rate=0;
		outliers_rate=0;
	};
	float get_ref_rate () { return class_ref_rate;};
	float get_outlier_rate() { return outliers_rate;};
	void set_ref_rate (float _class_ref_rate) { class_ref_rate=_class_ref_rate;};
	void set_outlier_rate( float _outliers_rate) { outliers_rate=_outliers_rate;};
};
 
	
