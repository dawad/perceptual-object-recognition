/// this class represent each row in the table that serve to draw a roc curve
#pragma once
class roc_row
{
private:
	
	float threshold; /// this attribute represent the threshold used to get the value of the next two attributes 
	float TP_rate; // this attributes is the true positive rate used as Y axis to draw the roc curve
	float FP_rate; // this attributes is the false positive rate used as X axix to draw the roc curve 
public:
	roc_row(void);
	~roc_row(void);
	
	/// getters 
	float get_TP_rate() {return TP_rate;};
	float get_FP_rate(){return FP_rate;};
	float get_threshold(){ return threshold;};
	/// setters
	void set_TP_rate( float _TP_rate) {TP_rate=_TP_rate;};
	void set_FP_rate(float _FP_rate) {FP_rate=_FP_rate;};
	void set_threshold ( float _threshold ) {threshold=_threshold;};
};

