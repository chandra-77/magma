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

#ifndef N11_MESSAGES_TYPES_SEEN
#define N11_MESSAGES_TYPES_SEEN
#include "common_types.h"
//-----------------------------------------------------------------------------
/** @struct itti_n11_create_pdu_session_response_t
 *  @brief Create PDU Session Response */

/***********************pdu_res_set_change starts*************************/
typedef enum {
  SHALL_NOT_TRIGGER_PRE_EMPTION,
  MAY_TRIGGER_PRE_EMPTION,
} pre_emption_capability;

typedef enum {
  NOT_PREEMPTABLE,
  PRE_EMPTABLE,
} pre_emption_vulnerability;

typedef struct m5g_allocation_and_retention_priority_s {
  int priority_level;
  pre_emption_capability pre_emption_cap;
  pre_emption_vulnerability pre_emption_vul;
} m5g_allocation_and_retention_priority;

typedef struct non_dynamic_5QI_descriptor_s {
  int fiveQI;
} non_dynamic_5QI_descriptor;
// Dynamic_5QI not cosidered

typedef struct qos_characteristics_s {
  non_dynamic_5QI_descriptor non_dynamic_5QI_desc;
} qos_characteristics;

typedef struct qos_flow_level_qos_parameters_s {
  qos_characteristics qos_characteristic;
  m5g_allocation_and_retention_priority alloc_reten_priority;

} qos_flow_level_qos_parameters;

typedef struct qos_flow_setup_request_item_s {
  uint32_t qos_flow_identifier;
  qos_flow_level_qos_parameters qos_flow_level_qos_param;
  // E-RAB ID is optional spec-38413 - 9.3.4.1
} qos_flow_setup_request_item;

typedef struct qos_flow_request_list_s {
  qos_flow_setup_request_item qos_flow_req_item;

} qos_flow_request_list;

typedef struct amf_pdn_type_value_s {
  pdn_type_value_t pdn_type;
} amf_pdn_type_value_t;

typedef struct gtp_tunnel_s {
  bstring endpoint_ip_address;  // Transport_Layer_Information
  uint8_t gtp_tied[4];
} gtp_tunnel;

typedef struct up_transport_layer_information_s {
  gtp_tunnel gtp_tnl;
} up_transport_layer_information_t;

typedef struct amf_ue_aggregate_maximum_bit_rate_s {
  uint64_t dl;
  uint64_t ul;
} amf_ue_aggregate_maximum_bit_rate_t;

typedef struct pdu_session_resource_setup_request_transfer_s {
  amf_ue_aggregate_maximum_bit_rate_t pdu_aggregate_max_bit_rate;
  up_transport_layer_information_t up_transport_layer_info;
  amf_pdn_type_value_t pdu_ip_type;
  qos_flow_request_list qos_flow_setup_request_list;
} pdu_session_resource_setup_request_transfer_t;

/***********************pdu_res_set_change ends*************************/

typedef enum SMSessionFSMState_response_s {
  CREATING_0,
  CREATE_1,
  ACTIVE_2,
  INACTIVE_3,
  RELEASED_4
} SMSessionFSMState_response;

typedef enum PduSessionType_response_s {
  IPV4,
  IPV6,
  IPV4IPV6,
  UNSTRUCTURED
} PduSessionType_response;

typedef enum SscMode_response_s {
  SSC_MODE_1,
  SSC_MODE_2,
  SSC_MODE_3
} SscMode_response;

typedef enum M5GSMCause_response_s {
  M5GSM_OPERATOR_DETERMINED_BARRING                       = 0,
  M5GSM_INSUFFICIENT_RESOURCES                            = 1,
  M5GSM_MISSING_OR_UNKNOWN_DNN                            = 2,
  M5GSM_UNKNOWN_PDU_SESSION_TYPE                          = 3,
  M5GSM_USER_AUTHENTICATION_OR_AUTHORIZATION_FAILED       = 4,
  M5GSM_REQUEST_REJECTED_UNSPECIFIED                      = 5,
  M5GSM_SERVICE_OPTION_NOT_SUPPORTED                      = 6,
  M5GSM_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED           = 7,
  M5GSM_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER           = 8,
  M5GSM_REGULAR_DEACTIVATION                              = 10,
  M5GSM_NETWORK_FAILURE                                   = 11,
  M5GSM_REACTIVATION_REQUESTED                            = 12,
  M5GSM_INVALID_PDU_SESSION_IDENTITY                      = 13,
  M5GSM_SEMANTIC_ERRORS_IN_PACKET_FILTER                  = 14,
  M5GSM_SYNTACTICAL_ERROR_IN_PACKET_FILTER                = 15,
  M5GSM_OUT_OF_LADN_SERVICE_AREA                          = 16,
  M5GSM_PTI_MISMATCH                                      = 17,
  M5GSM_PDU_SESSION_TYPE_IPV4_ONLY_ALLOWED                = 18,
  M5GSM_PDU_SESSION_TYPE_IPV6_ONLY_ALLOWED                = 19,
  M5GSM_PDU_SESSION_DOES_NOT_EXIST                        = 20,
  M5GSM_INSUFFICIENT_RESOURCES_FOR_SPECIFIC_SLICE_AND_DNN = 21,
  M5GSM_NOT_SUPPORTED_SSC_MODE                            = 22,
  M5GSM_INSUFFICIENT_RESOURCES_FOR_SPECIFIC_SLICE         = 23,
  M5GSM_MISSING_OR_UNKNOWN_DNN_IN_A_SLICE                 = 24,
  M5GSM_INVALID_PTI_VALUE                                 = 25,
  M5GSM_MAXIMUM_DATA_RATE_PER_UE_FOR_USER_PLANE_INTEGRITY_PROTECTION_IS_TOO_LOW =
      26,
  M5GSM_SEMANTIC_ERROR_IN_THE_QOS_OPERATION                 = 27,
  M5GSM_SYNTACTICAL_ERROR_IN_THE_QOS_OPERATION              = 28,
  M5GSM_INVALID_MAPPED_EPS_BEARER_IDENTITY                  = 29,
  M5GSM_SEMANTICALLY_INCORRECT_MESSAGE                      = 30,
  M5GSM_INVALID_MANDATORY_INFORMATION                       = 31,
  M5GSM_MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED        = 32,
  M5GSM_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE = 33,
  M5GSM_INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED = 34,
  M5GSM_CONDITIONAL_IE_ERROR                                = 35,
  M5GSM_MESSAGE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE      = 36,
  M5GSM_PROTOCOL_ERROR_UNSPECIFIED                          = 37,
  M5GSM_PTI_ALREADY_IN_USE                                  = 38,
  M5GSM_OPERATION_SUCCESS                                   = 40
} M5GSMCause_response;

typedef enum RedirectAddressType_response_s {
  IPV4_1,
  IPV6_1,
  URL,
  SIP_URI
} RedirectAddressType_response;

typedef struct RedirectServer_response_s {
  RedirectAddressType_response redirect_address_type;
  uint8_t redirect_server_address[16];
} RedirectServer_response;

typedef struct QosRules_response_s {
  uint32_t qos_rule_identifier;
  bool dqr;
  uint32_t number_of_packet_filters;
  uint32_t packet_filter_identifier[16];
  uint32_t qos_rule_precedence;
  bool segregation;
  uint32_t qos_flow_identifier;
} QosRules_response;

typedef struct AggregatedMaximumBitrate_respose_t {
  uint32_t max_bandwidth_ul;
  uint32_t max_bandwidth_dl;
} AggregatedMaximumBitrate_response;

#if 0
// typedef enum pre_emption_capability_response_e {
typedef enum {
  SHALL_NOT_TRIGGER_PRE_EMPTION,
  MAY_TRIGGER_PRE_EMPTION,
} pre_emption_capability_response;

// typedef enum pre_emption_vulnerability_response_e {
typedef enum {
  NOT_PREEMPTABLE,
  PRE_EMPTABLE,
} pre_emption_vulnerability_response;

typedef struct allocation_and_retention_priority_response_s {
  int priority_level;
  pre_emption_capability_response pre_emption_cap;
  pre_emption_vulnerability_response pre_emption_vul;
  // pre_emption_capability_t pre_emption_cap;
  // pre_emption_vulnerability_t pre_emption_vul;
} allocation_and_retention_priority_response;

typedef struct non_dynamic_5QI_descriptor_response_s {
  int fiveQI;
} non_dynamic_5QI_descriptor_response;
// Dynamic_5QI not cosidered

typedef struct qos_characteristics_response_s {
  non_dynamic_5QI_descriptor_response non_dynamic_5QI_desc;
} qos_characteristics_response;

typedef struct qos_flow_level_qos_parameters_response_s {
  qos_characteristics_response qos_characteristic;
  allocation_and_retention_priority_response alloc_reten_priority;

} qos_flow_level_qos_parameters_response;

typedef struct qos_flow_setup_response_s {
  uint32_t qos_flow_identifier;
  qos_flow_level_qos_parameters_response qos_flow_level_qos_param;
} qos_flow_setup_response;
typedef struct qos_flow_response_list_s {
  qos_flow_setup_response qos_flow_req_item;
  
} qos_flow_response_list;
#endif

typedef enum AmbrUnit_response_e {
  Kbps_0  = 0,
  Kbps_1  = 1,
  Kbps_4  = 2,
  Kbps_16 = 3,
  Kbps_64 = 4
} AmbrUnit_response;

typedef struct SessionAmbr_reponse_s {
  AmbrUnit_response downlink_unit_type;
  uint32_t downlink_units;  // Only to use lower 2 bytes (16 bit values)
  AmbrUnit_response uplink_unit_type;
  uint32_t uplink_units;  // Only to use lower 2 bytes (16 bit values)
} SessionAmbr_response;

typedef struct TeidSet_response_s {
  uint8_t teid[4];
  uint8_t end_ipv4_addr[16];
} TeidSet_response;
//#endif

typedef struct itti_n11_create_pdu_session_response_s {
  // common context
  char imsi[IMSI_BCD_DIGITS_MAX + 1];
  SMSessionFSMState_response sm_session_fsm_state;
  uint32_t sm_session_version;
  // M5GSMSessionContextAccess
  uint8_t pdu_session_id;
  PduSessionType_response pdu_session_type;
  SscMode_response selected_ssc_mode;
  QosRules_response
      authorized_qos_rules[4];  // TODO 32 in NAS5g,3 in pcap, revisit later
  SessionAmbr_response session_ambr;
  //  AggregatedMaximumBitrate_response session_ambr;
  M5GSMCause_response M5gsm_cause;
  bool always_on_pdu_session_indication;
  SscMode_response allowed_ssc_mode;
  bool M5gsm_congetion_re_attempt_indicator;
  RedirectServer_response pdu_address;
  //  qos_flow_response_list qos_list;
  qos_flow_request_list qos_list;
  TeidSet_response upf_endpoint;
  uint8_t procedure_trans_identity[2];
  // take data from TS 129 571
} itti_n11_create_pdu_session_response_t;

#define N11_CREATE_PDU_SESSION_RESPONSE(mSGpTR)                                \
  (mSGpTR)->ittiMsg.n11_create_pdu_session_response

#endif
