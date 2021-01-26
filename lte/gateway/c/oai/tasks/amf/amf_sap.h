/**
 * Copyright 2020 The Magma Authors.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*****************************************************************************

  Source      amf_sap.h

  Version     0.1

  Date        2020/07/28

  Product     NAS stack

  Subsystem   Access and Mobility Management Function

  Author      

  Description Defines Access and Mobility Management Messages

*****************************************************************************/
#ifndef AMF_SAP_SEEN
#define AMF_SAP_SEEN

#include <sstream>
#include <thread>
#ifdef __cplusplus
extern "C" {
#endif
#include "bstrlib.h"
#ifdef __cplusplus
};
#endif
using namespace std;
#define MIN_GUMMEI 1
#define MAX_GUMMEI 5
#include "amf_app_ue_context_and_proc.h"
#include "amf_app_defs.h"
namespace magma5g {
/****************************************************************************/
/*********************  G L O B A L    C O N S T A N T S  *******************/
/****************************************************************************/

/*
 * AMFREG-SAP primitives
 */
typedef enum {
  _AMFREG_START = 0,
  _AMFREG_COMMON_PROC_REQ,     /* AMF common procedure requested   */
  _AMFREG_COMMON_PROC_CNF,     /* AMF common procedure successful  */
  _AMFREG_COMMON_PROC_REJ,     /* AMF common procedure failed, CN send REJECT */
  _AMFREG_COMMON_PROC_ABORT,   /* AMF common procedure aborted     */
  _AMFREG_REGISTRATION_CNF,    /* 5GS network REGISTRATION accepted      */
  _AMFREG_REGISTRATION_REJ,    /* 5GS network REGISTRATION rejected      */
  _AMFREG_REGISTRATION_ABORT,  /* 5GS network REGISTRATION aborted      */
  _AMFREG_DEREGISTRATION_INIT, /* Network DEREGISTRATION initiated         */
  _AMFREG_DEREGISTRATION_REQ,  /* Network DEREGISTRATION requested         */
  _AMFREG_DEREGISTRATION_FAILED, /* Network DEREGISTRATION attempt failed    */
  _AMFREG_DEREGISTRATION_CNF,    /* Network DEREGISTRATION accepted          */
  _AMFREG_SERVICE_REQ,
  _AMFREG_SERVICE_CNF,
  _AMFREG_SERVICE_REJ,
  _AMFREG_LOWERLAYER_SUCCESS,      /* Data successfully delivered      */
  _AMFREG_LOWERLAYER_FAILURE,      /* Lower layer failure indication   */
  _AMFREG_LOWERLAYER_RELEASE,      /* NAS signalling connection released   */
  _AMFREG_LOWERLAYER_NON_DELIVERY, /*  remote Lower layer failure indication  */
  _AMFREG_END
} amf_reg_primitive_t;

/*
 * 5GMM Mobility Management primitives
 * ----------------------------------
 * AMFREG-SAP provides registration services for location updating and
 * registration/deregistration procedures;
 * AMFSMF-SAP provides interlayer services to the 5GMM Session Management
 * NF for service registration and activate/deactivate PDU session context;
 * AMFAS-SAP provides services to the Access Stratum sublayer for NAS message
 * transfer;
 */
enum amf_primitive_t {
  AMFREG_COMMON_PROC_REQ = 1,
  AMFREG_COMMON_PROC_CNF,
  AMFREG_COMMON_PROC_REJ,
  AMFREG_COMMON_PROC_ABORT,
  /* AMFAS-SAP */
  AMFAS_SECURITY_REQ        = _AMFAS_SECURITY_REQ,
  AMFAS_SECURITY_IND        = _AMFAS_SECURITY_IND,
  AMFAS_SECURITY_RES        = _AMFAS_SECURITY_RES,
  AMFAS_SECURITY_REJ        = _AMFAS_SECURITY_REJ,
  AMFAS_ESTABLISH_REQ       = _AMFAS_ESTABLISH_REQ,
  AMFAS_ESTABLISH_CNF       = _AMFAS_ESTABLISH_CNF,
  AMFAS_ESTABLISH_REJ       = _AMFAS_ESTABLISH_REJ,
  AMFAS_RELEASE_REQ         = _AMFAS_RELEASE_REQ,
  AMFREG_REGISTRATION_REJ   = _AMFREG_REGISTRATION_REJ,
  AMFAS_DATA_IND            = _AMFAS_DATA_IND,
  AMFREG_REGISTRATION_CNF   = _AMFREG_REGISTRATION_CNF,
  AMFREG_DEREGISTRATION_REQ = _AMFREG_DEREGISTRATION_REQ,
  AMFAS_DATA_REQ            = _AMFAS_DATA_REQ,
  AMFCN_CS_RESPONSE         = AMFCN_SMC_PARAM_RES,
};
/*
 * Minimal identifier for AMF-SAP primitives
 */
#define AMFREG_PRIMITIVE_MIN _AMFREG_START
#define AMFAS_PRIMITIVE_MIN _AMFAS_START
#define AMFCN_PRIMITIVE_MIN _AMFCN_START

/*
 * Maximal identifier for AMF-SAP primitives
 */
#define AMFREG_PRIMITIVE_MAX _AMFREG_END
#define AMFAS_PRIMITIVE_MAX _AMFAS_END
#define AMFCN_PRIMITIVE_MAX _AMFCN_END

/****************************************************************************/
/************************  G L O B A L    T Y P E S  ************************/
/****************************************************************************/

/*
 * EMMREG primitive for registration  procedure
 * -------------------------------------
 */
typedef struct amf_reg_register_s {
  bool is_emergency; /* true if the UE was attempting to register to
                      * the network for emergency services only  */
  nas_amf_registration_proc_t* proc;
} amf_reg_register_t;

/*
 * AMFREG primitive for de-registration procedure
 * -------------------------------------
 */
typedef struct amf_reg_deregister_s {
  bool switch_off; /* true if the UE is switched off       */
  int type;        /* Network detach type              */
} amf_reg_deregister_t;

/*
 * Structure of AMFREG-SAP primitive
 */
typedef struct sap_primitive_s {
  amf_reg_register_t registered;
  amf_reg_deregister_t deregister;
  // amf_reg_sr_t sr;
  amf_fsm_state_t previous_amf_fsm_state;
  struct nas_amf_common_proc_s* common_proc;
} sap_primitive_t;

typedef struct amf_reg_s {
  amf_primitive_t primitive;
  amf_ue_ngap_id_t ue_id;
  amf_context_t* ctx;
  bool notify;  // notify through call-backs
  bool free_proc;
  sap_primitive_t u;
} amf_reg_t;

typedef struct amf_cn_auth_res_s {
  /* UE identifier */
  amf_ue_ngap_id_t ue_id;

  /* For future use: nb of vectors provided */
  // uint8_t nb_vectors;//TODO later

} amf_cn_auth_res_t;

typedef struct amf_cn_auth_fail_s {
  /* UE identifier */
  amf_ue_ngap_id_t ue_id;

  /* NAS cause */
  // nas_cause_t cause; //TODO
} amf_cn_auth_fail_t;

typedef struct amf_ul_s {
  amf_cn_primitive_t primitive;
  union {
    amf_cn_auth_res_t* auth_res;
    amf_cn_auth_fail_t* auth_fail;
    // TODO many more structures to be defined based on Primitives
  } u;
} amf_cn_t;

typedef struct primitive_s {
  primitive_s() {}
  ~primitive_s() {}
  amf_reg_t amf_reg; /* AMFREG-SAP primitives    */
  amf_as_t amf_as; /* AMFAS-SAP primitives     */
  amf_cn_t amf_cn; /* AMFCN-SAP primitives     */
} primitive_t;
/*
 * Structure of 5GMM Mobility Management primitive
 */
class amf_sap_t {
  uint32_t count;

 public:
  amf_sap_t() {}
  ~amf_sap_t() {}
  amf_primitive_t primitive;
  primitive_t u;
};

class amf_sap_c  //: public amf_sap_t
{
 public:
  amf_sap_c() {}
  ~amf_sap_c() {}

  void amf_sap_initialize(void);
  int amf_sap_send(amf_sap_t* msg);
};

typedef int (*amf_common_success_callback_t)(void*);
typedef int (*amf_common_reject_callback_t)(void*);
typedef int (*amf_common_failure_callback_t)(void*);
typedef int (*amf_common_ll_failure_callback_t)(void*);
typedef int (*amf_common_non_delivered_callback_t)(void*);
typedef int (*amf_common_abort_callback_t)(void*);

/*This function to handle all UL message final actions*/
int amf_cn_send(const amf_cn_t* msg);
int amf_reg_send(amf_reg_t* const msg);

}  // namespace  magma5g
#endif
