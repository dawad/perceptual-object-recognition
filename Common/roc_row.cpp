#include "StdAfx.h"
#include "roc_row.h"


roc_row::roc_row(void)
{
	roc_row::threshold=0; /// this attribute represent the threshold used to get the value of the next two attributes 
	roc_row::FP_rate=0; // this attributes is the true positive rate used as Y axis to draw the roc curve
	roc_row::FP_rate=0; // this attributes is the false positive rate used as X axix to draw the roc curve 
}


roc_row::~roc_row(void)
{
}
