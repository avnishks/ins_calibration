/* Include files */
#include "blascompat32.h"
#include "tablerot_nonid_sfun.h"
#include "c1_tablerot_nonid.h"
#define CHARTINSTANCE_CHARTNUMBER (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER (chartInstance->instanceNumber)
#include "tablerot_nonid_sfun_debug_macros.h"

/* Type Definitions */



























/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static void initialize_params_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static void enable_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static void disable_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static void set_sim_state_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static void sf_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T c1_chartNumber);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_emlrt_marshallIn(SFc1_tablerot_nonidInstanceStruct *chartInstance, const mxArray *c1_y, const char_T *c1_name, real_T c1_b_y[3]);
static uint8_T c1_b_emlrt_marshallIn(SFc1_tablerot_nonidInstanceStruct *chartInstance, const mxArray *c1_b_is_active_c1_tablerot_nonid, const char_T *c1_name);
static void init_dsm_address_info(SFc1_tablerot_nonidInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
_sfTime_ = (real_T)ssGetT(chartInstance->S);
chartInstance->c1_is_active_c1_tablerot_nonid = 0U;
}

static void initialize_params_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
}

static void enable_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
_sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
_sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
const mxArray *c1_st = NULL;
const mxArray *c1_y = NULL;
int32_T c1_i0;
real_T c1_hoistedGlobal[3];
int32_T c1_i1;
real_T c1_u[3];
const mxArray *c1_b_y = NULL;
uint8_T c1_b_hoistedGlobal;
uint8_T c1_b_u;
const mxArray *c1_c_y = NULL;
real_T (*c1_d_y)[3];
c1_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
c1_st = NULL;
c1_y = NULL;
sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
for(c1_i0 = 0; c1_i0 < 3; c1_i0 = c1_i0 + 1) {
c1_hoistedGlobal[c1_i0] = (*c1_d_y)[c1_i0];
}
for(c1_i1 = 0; c1_i1 < 3; c1_i1 = c1_i1 + 1) {
c1_u[c1_i1] = c1_hoistedGlobal[c1_i1];
}
c1_b_y = NULL;
sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 1U, 0U, 1, 3));
sf_mex_setcell(c1_y, 0, c1_b_y);
c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_tablerot_nonid;
c1_b_u = c1_b_hoistedGlobal;
c1_c_y = NULL;
sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
sf_mex_setcell(c1_y, 1, c1_c_y);
sf_mex_assign(&c1_st, c1_y);
return c1_st;
}

static void set_sim_state_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance, const mxArray *c1_st)
{
const mxArray *c1_u;
real_T c1_dv0[3];
int32_T c1_i2;
real_T (*c1_y)[3];
c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
chartInstance->c1_doneDoubleBufferReInit = TRUE;
c1_u = sf_mex_dup(c1_st);
c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y", c1_dv0);
for(c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
(*c1_y)[c1_i2] = c1_dv0[c1_i2];
}
chartInstance->c1_is_active_c1_tablerot_nonid = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)), 
"is_active_c1_tablerot_nonid");
sf_mex_destroy(&c1_u);
c1_update_debugger_state_c1_tablerot_nonid(chartInstance);
sf_mex_destroy(&c1_st);
}


static void finalize_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
}

static void sf_c1_tablerot_nonid(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
int32_T c1_i3;
int32_T c1_i4;
int32_T c1_previousEvent;
int32_T c1_i5;
real_T c1_hoistedGlobal[6];
int32_T c1_i6;
real_T c1_u[6];
uint32_T c1_debug_family_var_map[4];
static const char *c1_sv0[4] = { "nargin", "nargout", "u", "y" };
real_T c1_nargin = 1.0;
real_T c1_nargout = 1.0;
real_T c1_y[3];
int32_T c1_i7;
int32_T c1_i8;
real_T (*c1_b_y)[3];
real_T (*c1_b_u)[6];
c1_b_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
c1_b_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
_sfTime_ = (real_T)ssGetT(chartInstance->S);
_SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
for(c1_i3 = 0; c1_i3 < 6; c1_i3 = c1_i3 + 1) {
_SFD_DATA_RANGE_CHECK((*c1_b_u)[c1_i3], 0U);
}
for(c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
_SFD_DATA_RANGE_CHECK((*c1_b_y)[c1_i4], 1U);
}
c1_previousEvent = _sfEvent_;
_sfEvent_ = CALL_EVENT;
_SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
for(c1_i5 = 0; c1_i5 < 6; c1_i5 = c1_i5 + 1) {
c1_hoistedGlobal[c1_i5] = (*c1_b_u)[c1_i5];
}
for(c1_i6 = 0; c1_i6 < 6; c1_i6 = c1_i6 + 1) {
c1_u[c1_i6] = c1_hoistedGlobal[c1_i6];
}
sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_sv0, c1_debug_family_var_map);
sf_debug_symbol_scope_add_eml(&c1_nargin, c1_c_sf_marshall, 0U);
sf_debug_symbol_scope_add_eml(&c1_nargout, c1_c_sf_marshall, 1U);
sf_debug_symbol_scope_add_eml(&c1_u, c1_b_sf_marshall, 2U);
sf_debug_symbol_scope_add_eml(&c1_y, c1_sf_marshall, 3U);
CV_EML_FCN(0, 0);
_SFD_EML_CALL(0,4);
for(c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
c1_y[c1_i7] = c1_u[c1_i7];
}
_SFD_EML_CALL(0,-4);
sf_debug_symbol_scope_pop();
for(c1_i8 = 0; c1_i8 < 3; c1_i8 = c1_i8 + 1) {
(*c1_b_y)[c1_i8] = c1_y[c1_i8];
}
_SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
_sfEvent_ = c1_previousEvent;
sf_debug_check_for_state_inconsistency(_tablerot_nonidMachineNumber_, chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
const mxArray *c1_y = NULL;
int32_T c1_i9;
real_T c1_b_u[3];
const mxArray *c1_b_y = NULL;
SFc1_tablerot_nonidInstanceStruct *chartInstance;
chartInstance = (SFc1_tablerot_nonidInstanceStruct *)chartInstanceVoid;
c1_y = NULL;
for(c1_i9 = 0; c1_i9 < 3; c1_i9 = c1_i9 + 1) {
c1_b_u[c1_i9] = (*((real_T (*)[3])c1_u))[c1_i9];
}
c1_b_y = NULL;
sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 3));
sf_mex_assign(&c1_y, c1_b_y);
return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
const mxArray *c1_y = NULL;
int32_T c1_i10;
real_T c1_b_u[6];
const mxArray *c1_b_y = NULL;
SFc1_tablerot_nonidInstanceStruct *chartInstance;
chartInstance = (SFc1_tablerot_nonidInstanceStruct *)chartInstanceVoid;
c1_y = NULL;
for(c1_i10 = 0; c1_i10 < 6; c1_i10 = c1_i10 + 1) {
c1_b_u[c1_i10] = (*((real_T (*)[6])c1_u))[c1_i10];
}
c1_b_y = NULL;
sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 6));
sf_mex_assign(&c1_y, c1_b_y);
return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
const mxArray *c1_y = NULL;
real_T c1_b_u;
const mxArray *c1_b_y = NULL;
SFc1_tablerot_nonidInstanceStruct *chartInstance;
chartInstance = (SFc1_tablerot_nonidInstanceStruct *)chartInstanceVoid;
c1_y = NULL;
c1_b_u = *((real_T *)c1_u);
c1_b_y = NULL;
sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
sf_mex_assign(&c1_y, c1_b_y);
return c1_y;
}

const mxArray *sf_c1_tablerot_nonid_get_eml_resolved_functions_info(void)
{
const mxArray *c1_nameCaptureInfo = NULL;
c1_nameCaptureInfo = NULL;
sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0, 0U, 1U, 0U, 2, 0, 1));
return c1_nameCaptureInfo;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
const mxArray *c1_y = NULL;
boolean_T c1_b_u;
const mxArray *c1_b_y = NULL;
SFc1_tablerot_nonidInstanceStruct *chartInstance;
chartInstance = (SFc1_tablerot_nonidInstanceStruct *)chartInstanceVoid;
c1_y = NULL;
c1_b_u = *((boolean_T *)c1_u);
c1_b_y = NULL;
sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
sf_mex_assign(&c1_y, c1_b_y);
return c1_y;
}

static void c1_emlrt_marshallIn(SFc1_tablerot_nonidInstanceStruct *chartInstance, const mxArray *c1_y, const char_T *c1_name, real_T
 c1_b_y[3])
{
real_T c1_dv1[3];
int32_T c1_i11;
sf_mex_import(c1_name, sf_mex_dup(c1_y), &c1_dv1, 1, 0, 0U, 1, 0U, 1, 3);
for(c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
c1_b_y[c1_i11] = c1_dv1[c1_i11];
}
sf_mex_destroy(&c1_y);
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_tablerot_nonidInstanceStruct *chartInstance, const mxArray *
c1_b_is_active_c1_tablerot_nonid, const char_T *c1_name)
{
uint8_T c1_y;
uint8_T c1_u0;
sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_tablerot_nonid), &c1_u0, 1, 3, 0U, 0, 0U, 0);
c1_y = c1_u0;
sf_mex_destroy(&c1_b_is_active_c1_tablerot_nonid);
return c1_y;
}

static void init_dsm_address_info(SFc1_tablerot_nonidInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_tablerot_nonid_get_check_sum(mxArray *plhs[])
{
         ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2870612212U);
         ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(724177022U);
         ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2461944119U);
         ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2349215192U);
}

mxArray *sf_c1_tablerot_nonid_get_autoinheritance_info(void)
{
     const char *autoinheritanceFields[] = {"checksum","inputs","parameters","outputs"};
     mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,autoinheritanceFields);
     {
         mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
         double *pr = mxGetPr(mxChecksum);
             pr[0] = (double)(1925492579U);
             pr[1] = (double)(668487415U);
             pr[2] = (double)(2816732538U);
             pr[3] = (double)(3491550121U);
         mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
     }
 {
         const char *dataFields[] = {"size","type","complexity"};
         mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
             {
                 mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
                 double *pr = mxGetPr(mxSize);
                 pr[0] = (double)(6);
                 pr[1] = (double)(1);
                 mxSetField(mxData,0,"size",mxSize);
             }            
             {
                 const char *typeFields[] = {"base","fixpt"};
                 mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
                 mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
                     mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
                 mxSetField(mxData,0,"type",mxType);
             }                        
             mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
         mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
 }
 {
         mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));            
 }
 {
         const char *dataFields[] = {"size","type","complexity"};
         mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
             {
                 mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
                 double *pr = mxGetPr(mxSize);
                 pr[0] = (double)(3);
                 pr[1] = (double)(1);
                 mxSetField(mxData,0,"size",mxSize);
             }            
             {
                 const char *typeFields[] = {"base","fixpt"};
                 mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
                 mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
                     mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
                 mxSetField(mxData,0,"type",mxType);
             }                        
             mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
         mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
 }
     return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_tablerot_nonid(void)
{
   const char *infoFields[] = {"chartChecksum", "varInfo"};
   mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
   const char *infoEncStr[] = {
   "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_tablerot_nonid\",}}"
   };
   mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
   mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
   sf_c1_tablerot_nonid_get_check_sum(&mxChecksum);
   mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
   mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
   return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int fullDebuggerInitialization)
{
   if(!sim_mode_is_rtw_gen(S)) {
        SFc1_tablerot_nonidInstanceStruct *chartInstance;
        chartInstance = (SFc1_tablerot_nonidInstanceStruct *) ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
     if(ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
        /* do this only if simulation is starting */
	{
	unsigned int chartAlreadyPresent;
	chartAlreadyPresent = sf_debug_initialize_chart(_tablerot_nonidMachineNumber_,
                                                   1,
                                                   1,
                                                   1,
                                                   2,
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   &(chartInstance->chartNumber),
                                                   &(chartInstance->instanceNumber),
                                                   ssGetPath(S),
                                                   (void *)S);
	if(chartAlreadyPresent==0) {
	/* this is the first instance */
     init_script_number_translation(_tablerot_nonidMachineNumber_,chartInstance->chartNumber);
 sf_debug_set_chart_disable_implicit_casting(_tablerot_nonidMachineNumber_,chartInstance->chartNumber,1);
 sf_debug_set_chart_event_thresholds(_tablerot_nonidMachineNumber_,
                                     chartInstance->chartNumber,
                                     0,
                                     0,
                                     0);
 
		    {
		unsigned int dimVector[1];
			    dimVector[0]= 6;
	_SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"u",0,(MexFcnForType)c1_b_sf_marshall);
		    }
		    {
		unsigned int dimVector[1];
			    dimVector[0]= 3;
	_SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"y",0,(MexFcnForType)c1_sf_marshall);
		    }
	_SFD_STATE_INFO(0,0,2);
	_SFD_CH_SUBSTATE_COUNT(0);
	_SFD_CH_SUBSTATE_DECOMP(0);
	
	}
 _SFD_CV_INIT_CHART(0,0,0,0);
	{
	    _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
	}

     _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);


 /* Initialization of EML Model Coverage */
 _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
 _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,38);
	_SFD_TRANS_COV_WTS(0,0,0,1,0);
	if(chartAlreadyPresent==0)
{
		_SFD_TRANS_COV_MAPS(0,
		0,NULL,NULL,
		0,NULL,NULL,
		1,NULL,NULL,
		0,NULL,NULL);
}

{
real_T (*c1_u)[6];
real_T (*c1_y)[3];
c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
c1_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
_SFD_SET_DATA_VALUE_PTR(0U, c1_u);
_SFD_SET_DATA_VALUE_PTR(1U, c1_y);
}
}
     } else {
        sf_debug_reset_current_state_configuration(_tablerot_nonidMachineNumber_,chartInstance->chartNumber,chartInstance->instanceNumber);
     }
   }
}


static void sf_opaque_initialize_c1_tablerot_nonid(void *chartInstanceVar)
{
   chart_debug_initialization(((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar)->S,0);
   initialize_params_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar);
   initialize_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_tablerot_nonid(void *chartInstanceVar)
{
   enable_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_tablerot_nonid(void *chartInstanceVar)
{
   disable_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar);
}


static void sf_opaque_gateway_c1_tablerot_nonid(void *chartInstanceVar)
{
   sf_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_tablerot_nonid(SimStruct* S)
{
    ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
    mxArray *plhs[1] = {NULL};
    mxArray *prhs[4];
    int mxError = 0;

    prhs[0] = mxCreateString("chart_simctx_raw2high");
    prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
    prhs[2] = (mxArray*) get_sim_state_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*)chartInfo->chartInstance); /* raw sim ctx */
    prhs[3] = sf_get_sim_state_info_c1_tablerot_nonid(); /* state var info */

    mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");

    mxDestroyArray(prhs[0]);
    mxDestroyArray(prhs[1]);
    mxDestroyArray(prhs[2]);
    mxDestroyArray(prhs[3]);

    if (mxError || plhs[0] == NULL) {
        sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
    }

    return plhs[0];
}

static void sf_internal_set_sim_state_c1_tablerot_nonid(SimStruct* S, const mxArray *st)
{
    ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
    mxArray *plhs[1] = {NULL};
    mxArray *prhs[4];
    int mxError = 0;
    
    prhs[0] = mxCreateString("chart_simctx_high2raw");
    prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
    prhs[2] = mxDuplicateArray(st); /* high level simctx */
    prhs[3] = (mxArray*) sf_get_sim_state_info_c1_tablerot_nonid(); /* state var info */
    
    mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
    
    mxDestroyArray(prhs[0]);
    mxDestroyArray(prhs[1]);
    mxDestroyArray(prhs[2]);
    mxDestroyArray(prhs[3]);
    
    if (mxError || plhs[0] == NULL) {
        sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
    }
    
    set_sim_state_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*)chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
    mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_tablerot_nonid(SimStruct* S)
{
    return sf_internal_get_sim_state_c1_tablerot_nonid(S);
}

static void sf_opaque_set_sim_state_c1_tablerot_nonid(SimStruct* S, const mxArray *st)
{
    sf_internal_set_sim_state_c1_tablerot_nonid(S, st);
}

static void sf_opaque_terminate_c1_tablerot_nonid(void *chartInstanceVar)
{
 if(chartInstanceVar!=NULL) {
     SimStruct *S = ((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar)->S;
     if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
         sf_clear_rtw_identifier(S);
     }
     finalize_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*) chartInstanceVar);
     free((void *)chartInstanceVar);
     ssSetUserData(S,NULL);
 }
}

   
extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_tablerot_nonid(SimStruct *S)
{
   int i;
   for(i=0;i<ssGetNumRunTimeParams(S);i++) {
      if(ssGetSFcnParamTunable(S,i)) {
         ssUpdateDlgParamAsRunTimeParam(S,i);
      }
   }
   if(sf_machine_global_initializer_called()) {
       initialize_params_c1_tablerot_nonid((SFc1_tablerot_nonidInstanceStruct*)(((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
   }
}

static void mdlSetWorkWidths_c1_tablerot_nonid(SimStruct *S)
{

 if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
     int_T chartIsInlinable =
               (int_T)sf_is_chart_inlinable("tablerot_nonid","tablerot_nonid",1);
     ssSetStateflowIsInlinable(S,chartIsInlinable);
		ssSetRTWCG(S,sf_rtw_info_uint_prop("tablerot_nonid","tablerot_nonid",1,"RTWCG"));
      ssSetEnableFcnIsTrivial(S,1);
      ssSetDisableFcnIsTrivial(S,1);
		ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("tablerot_nonid","tablerot_nonid",1,"gatewayCannotBeInlinedMultipleTimes"));
     if(chartIsInlinable) {            
           ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
             sf_mark_chart_expressionable_inputs(S,"tablerot_nonid","tablerot_nonid",1,1);
             sf_mark_chart_reusable_outputs(S,"tablerot_nonid","tablerot_nonid",1,1);
     }
     sf_set_rtw_dwork_info(S,"tablerot_nonid","tablerot_nonid",1);
         ssSetHasSubFunctions(S,!(chartIsInlinable));
           ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
 }

 ssSetChecksum0(S,(2388172725U));
 ssSetChecksum1(S,(3523505408U));
 ssSetChecksum2(S,(3189015169U));
 ssSetChecksum3(S,(900871512U));

 ssSetmdlDerivatives(S, NULL);

   ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_tablerot_nonid(SimStruct *S)
{
   if(sim_mode_is_rtw_gen(S)) {
      sf_write_symbol_mapping(S, "tablerot_nonid", "tablerot_nonid",1);
	      ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
   }
      
}

static void mdlStart_c1_tablerot_nonid(SimStruct *S)
{
 SFc1_tablerot_nonidInstanceStruct *chartInstance;
 chartInstance = (SFc1_tablerot_nonidInstanceStruct *)malloc(sizeof(SFc1_tablerot_nonidInstanceStruct));
 memset(chartInstance, 0, sizeof(SFc1_tablerot_nonidInstanceStruct));
 if(chartInstance==NULL) {
     sf_mex_error_message("Could not allocate memory for chart instance.");
 }
 chartInstance->chartInfo.chartInstance = chartInstance;
 chartInstance->chartInfo.isEMLChart = 1;
 chartInstance->chartInfo.chartInitialized = 0;
 chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_tablerot_nonid;
 chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_tablerot_nonid;
 chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_tablerot_nonid;
 chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_tablerot_nonid;
 chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_tablerot_nonid;
 chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_tablerot_nonid;
 chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_tablerot_nonid;
 chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_tablerot_nonid;
    chartInstance->chartInfo.zeroCrossings = NULL;
    chartInstance->chartInfo.outputs = NULL;
    chartInstance->chartInfo.derivatives = NULL;
 chartInstance->chartInfo.mdlRTW = mdlRTW_c1_tablerot_nonid;
 chartInstance->chartInfo.mdlStart = mdlStart_c1_tablerot_nonid;
 chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_tablerot_nonid;
 chartInstance->chartInfo.extModeExec = NULL;
 chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
 chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
 chartInstance->chartInfo.storeCurrentConfiguration = NULL;
 chartInstance->S = S;
 ssSetUserData(S,(void *)(&(chartInstance->chartInfo))); /* register the chart instance with simstruct */

 if(!sim_mode_is_rtw_gen(S)) {
     init_dsm_address_info(chartInstance);
 }
   chart_debug_initialization(S,1);
}

void c1_tablerot_nonid_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
  case SS_CALL_MDL_START:
    mdlStart_c1_tablerot_nonid(S);
    break;
  case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_tablerot_nonid(S);
    break;
  case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_tablerot_nonid(S);
    break;
  default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_tablerot_nonid_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}


