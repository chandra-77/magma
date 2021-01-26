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

  Source      amf_sap.cpp

  Version     0.1

  Date        2020/07/28

  Product     NAS stack

  Subsystem   Access and Mobility Management Function

  Author     

  Description Defines Access and Mobility Management Messages

*****************************************************************************/
#include <sstream>
#ifdef __cplusplus
extern "C" {
#endif
#include "log.h"
#ifdef __cplusplus
}
#endif
#include "amf_fsm.h"
#include "amf_asDefs.h"
#include "amf_as.h"
#include "amf_sap.h"

using namespace std;

namespace magma5g {
amf_as amf_access;  // Object to call respective functions
int amf_sap_c::amf_sap_send(amf_sap_t* msg) {
  int rc                    = RETURNerror;
  amf_primitive_t primitive = msg->primitive;

  OAILOG_FUNC_IN(LOG_NAS_AMF);

  /*
   * Check the AMF-SAP primitive
   */
  if ((primitive > (amf_primitive_t) AMFREG_PRIMITIVE_MIN) &&
      (primitive < (amf_primitive_t) AMFREG_PRIMITIVE_MAX)) {
    /*
     * Forward to the AMFREG-SAP
     * will handle for state update
     */
    msg->u.amf_reg.primitive = primitive;
    rc                       = amf_reg_send(&msg->u.amf_reg);
  }
  else if (
      (primitive > (amf_primitive_t) AMFAS_PRIMITIVE_MIN) &&
      (primitive < (amf_primitive_t) AMFAS_PRIMITIVE_MAX)) {
    /*
     * Forward to the AMFAS-SAP
     */
    msg->u.amf_as.primitive = (amf_as_primitive_t) primitive;
    rc                      = amf_access.amf_as_send(&msg->u.amf_as);
  } else if (
      (primitive > (amf_primitive_t) AMFCN_PRIMITIVE_MIN) &&
      (primitive < (amf_primitive_t) AMFCN_PRIMITIVE_MAX)) {
    /*
     * Forward to the AMFCN-SAP
     */

    msg->u.amf_cn.primitive = (amf_cn_primitive_t) primitive;
    rc                      = amf_cn_send(&msg->u.amf_cn);
  } else {
	  //TODO
  }

  OAILOG_FUNC_RETURN(LOG_NAS_AMF, rc);
}

/****************************************************************************
 **                                                                        **
 ** Name:    amf_as_set_security_data()                                    **
 **                                                                        **
 ** Description: Setup security data according to the given 5GCN security   **
 **      context when data transfer to lower layers is requested
 ***
 **                                                                        **
 ** Inputs:  args:  5GCN security context currently in use **
 **      			is_new:    Indicates whether a new security
 *context
 ***
 **             	has just been taken into use                          **
 **      			is_ciphered:   Indicates whether the NAS message
 *has
 ***
 **            		 be sent ciphered **
 **      Others:    None **
 **                                                                        **
 **      Outputs:     data:      5GCN NAS security data to be setup          **
 **      Return:    None                                                 **
 **      Others:    None                                       **
 **                                                                        **
 ***************************************************************************/

void amf_as_data_t::amf_as_set_security_data(
    amf_as_security_data_t* data, const void* args, bool is_new,
    bool is_ciphered) {
  OAILOG_FUNC_IN(LOG_NAS_AMF);

  const amf_security_context_t* context = (amf_security_context_t*) (args);

  memset(data, 0, sizeof(amf_as_security_data_t));

  if (context && ((context->sc_type == SECURITY_CTX_TYPE_FULL_NATIVE) ||
                  (context->sc_type == SECURITY_CTX_TYPE_MAPPED))) {
    /*
     * 3GPP TS 24.501, sections 5.4.3.3 and 5.4.3.4
     * * * * Once a valid 5GCN security context exists and has been taken
     * * * * into use, UE and AMF shall cipher and integrity protect all
     * * * * NAS signalling messages with the selected NAS ciphering and
     * * * * NAS integrity algorithms
     */
    OAILOG_DEBUG(
        LOG_NAS_AMF,
        "5GCN security context exists is new %u KSI %u SQN %u count %u\n",
        is_new, context->eksi, context->ul_count.seq_num,
        *(uint32_t*) (&context->ul_count));
    data->is_new = is_new;
    data->ksi    = context->eksi;
    data->sqn    = context->dl_count
                    .seq_num;  // TODO AT check whether we need to
                               // increment this by one or it is already
                               // incremented after sending last NAS mssage.
    data->count = 0x00000000 |
                  ((context->dl_count.overflow & 0x0000FFFF) << 8) |
                  (context->dl_count.seq_num & 0x000000FF);
    /*
     * NAS integrity and cyphering keys may not be available if the
     * * * * current security context is a partial EPS security context
     * * * * and not a full native 5GCN security context
     */
    data->is_knas_int_present = true;
    memcpy(data->knas_int, context->knas_int, sizeof(data->knas_int));

    if (is_ciphered) {
      /*
       * 3GPP TS 25.501, sections 4.4.5
       * * * * When the UE establishes a new NAS signalling connection,
       * * * * it shall send initial NAS messages integrity protected
       * * * * and unciphered
       */
      /*
       * 3GPP TS 25.501, section 5.4.3.2
       * * * * The AMF shall send the SECURITY MODE COMMAND message integrity
       * * * * protected and unciphered
       */
      OAILOG_DEBUG(LOG_NAS_AMF, "5GCN security context exists knas_enc\n");
      data->is_knas_enc_present = true;
      memcpy(data->knas_enc, context->knas_enc, sizeof(data->knas_enc));
    }
  } else {
    data->ksi = KSI_NO_KEY_AVAILABLE;
  }

  OAILOG_FUNC_OUT(LOG_NAS_AMF);
}
}  // namespace magma5g
