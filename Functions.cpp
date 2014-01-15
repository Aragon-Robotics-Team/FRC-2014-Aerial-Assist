/*Any functions necessary for the code to run
Meant to be copy-pasted into our final file*/
#include <math.h>
float encoderMean(signed int x,signed int y) {
	if(abs(x-y)<25) {
		return (x-y)/2;
	}
	else {
		if(x>y) {
			return x;
		}
		else {
			return y;
		}
	}
}