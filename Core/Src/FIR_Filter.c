/*
 * FIRfilter.c
 *
 *  Created on: Jan 14, 2025
 *      Author: Priyan
 */


//
//
//
#include <FIRFilter.h>
#include <stdio.h>
static float FIR_IMPULSE_RESPONSE[FIR_FILTER_LENGTH] = {
		-0.028094547010435022,
		0.000000000000000007,
		0.042141820515652538,
		0.090915863922831200,
		0.136373795884246835,
		0.168567282062610097,
		0.180191569250188838,
		0.168567282062610097,
		0.136373795884246835,
		0.090915863922831200,
		0.042141820515652538,
		0.000000000000000007,
		-0.028094547010435022};

void FIRFilter_Init(FIRFilter *fir) {
    for(uint8_t n = 0; n < FIR_FILTER_LENGTH; n++) {
fir->buf[n] = 0.0f;

    }
    //reset buffer index
    fir->bufIndex= 0;

    //clear filter output
    fir->out = 0.0f;
}

float FIRFilter_Update(FIRFilter *fir, float inp) {
fir->buf[fir->bufIndex] = inp;
    fir ->bufIndex++;
    if(fir->bufIndex == FIR_FILTER_LENGTH) {

        fir->bufIndex = 0;
    }

    fir->out = 0.0f;
    uint8_t sumIndex = fir->bufIndex;


    for(uint8_t n = 0; n < FIR_FILTER_LENGTH; n++) {
              if(sumIndex>0) {
                  sumIndex--;
              }
        else {
            sumIndex = FIR_FILTER_LENGTH -1;
        }
        fir->out += FIR_IMPULSE_RESPONSE[n]*fir->buf[sumIndex];

    }
return  fir->out;
}

