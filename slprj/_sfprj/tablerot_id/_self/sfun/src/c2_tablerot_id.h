#ifndef __c2_tablerot_id_h__
#define __c2_tablerot_id_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"


/* Type Definitions */











typedef struct {
SimStruct *S;
uint32_T chartNumber;
uint32_T instanceNumber;
boolean_T c2_doneDoubleBufferReInit;
boolean_T c2_isStable;
uint8_T c2_is_active_c2_tablerot_id;
ChartInfoStruct chartInfo;
} SFc2_tablerot_idInstanceStruct;
















/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_tablerot_id_get_eml_resolved_functions_info(void);

/* Function Definitions */



















extern void sf_c2_tablerot_id_get_check_sum(mxArray *plhs[]);
extern void c2_tablerot_id_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

