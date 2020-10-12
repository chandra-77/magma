/*
Copyright 2020 The Magma Authors.
This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once
#include <sstream>
#include "ExtendedProtocolDiscriminator.h"
#include "SecurityHeaderType.h"
#include "MessageType.h"
#include "SpareHalfOctet.h"
#include "5GSRegistrationResult.h"
#ifdef HANDLE_POST_MVC
#include "5GSMobileIdentity.h"
#include "PLMNList.h"
#include "NRGSTrackingAreaIdentityList.h"
#include "NSSAI.h"
#include "RejectedNSSAI.h"
#include "5GSNetworkFeatureSupport.h"
#include "PDUSessionStatus.h"
#include "PDUSessionReactivationResult.h"
#include "PDUSessionReactivationResultErrorCause.h"
#include "LADNInformation.h"
#include "MICOIndication.h"
#include "NetworkSlicingIndication.h"
#include "ServiceAreaList.h"
#include "GPRSTimer3.h"
#include "GPRSTimer2.h"
#include "EmergencyNumberList.h"
#include "ExtendedEmergencyNumberList.h"
#include "SORTransparentContainer.h"
#include "EAPMessage.h"
#include "NSSAIInclusionMode.h"
#include "OperatorDefinedAccessCategoryDefinitions.h"
#include "5GSDRXParameters.h"
#include "Non3GPPNWprovidedpolicies.h"
#include "EPSbearercontextstatus.h"
#include "5GSTrackingAreaIdentity.h"
#include "5GSTrackingAreaIdentitylist.h"
#endif

using namespace std;

namespace magma5g {
class RegistrationAcceptMsg {
 public:
  RegistrationAcceptMsg();
  ~RegistrationAcceptMsg();
  ExtendedProtocolDiscriminatorMsg extendedprotocoldiscriminator;
  SecurityHeaderTypeMsg securityheadertype;
  SpareHalfOctetMsg sparehalfoctet;
  MessageTypeMsg messagetype;
  M5GSRegistrationResultMsg m5gsregistrationresult;
#ifdef HANDLE_POST_MVC
  M5GSMobileIdentityMsg m5gsmobileidentity;
  PLMNListMsg plmnlist;
  M5GSTrackingAreaIdentityListMsg m5gstrackingareaidentitylist;
  NSSAIMsg nssai;
  RejectedNSSAIMsg rejectednssai;
  M5GSNetworkFeatureSupportMsg m5gsnetworkfeaturesupport;
  PDUSessionStatusMsg pdusessionstatus;
  PDUSessionReactivationResultMsg pdusessionreactivationresult;
  PDUSessionReactivationResultErrorCauseMsg
      pdusessionreactivationresulterrorcause;
  LADNInformationMsg ladninformation;
  MICOIndicationMsg micoindication;
  NetworkSlicingIndicationMsg networkslicingindication;
  ServiceAreaListMsg servicearealist;
  GPRSTimer3Msg gprstimer3;  // T3512 value
  GPRSTimer2Msg
      gprstimer2;  // Non-3GPP de-registration timer value or T3502 value
  EmergencyNumberListMsg emergencynumberlist;
  ExtendedEmergencyNumberListMsg extendedemergencynumberlist;
  SORTransparentContainerMsg sortransparentcontainer;
  EAPMessageMsg eapmessage;
  NSSAIInclusionModeMsg nssaiinclusionmode;
  OperatorDefinedAccessCategoryDefinitionsMsg
      operatordefinedaccesscategorydefinitions;
  M5GSDRXParametersMsg m5gsdrxparameters;
  Non3GPPNWProvidedPoliciesMsg non3gppnwprovidedpolicies;
  EPSBearerContextStatusMsg epsbearercontextstatus;
#endif
#define REGISTRATION_ACCEPT_MINIMUM_LENGTH 5
  int DecodeRegistrationAcceptMsg(
      RegistrationAcceptMsg* registrationaccept, uint8_t* buffer, uint32_t len);
  int EncodeRegistrationAcceptMsg(
      RegistrationAcceptMsg* registrationaccept, uint8_t* buffer, uint32_t len);
};
}  // namespace magma5g
/*
   Table 8.2.7.1.1: REGISTRATION ACCEPT message content

   IEI           Information Element                            Type/Reference                      Presence     Format     Length

            Extended protocol discriminator               Extended Protocol discriminator 9.2          M           V          1 
            Security header type                          Security header type 9.3                     M           V          1/2 
            Spare half octet                              Spare half octet 9.5                         M           V          1/2 
            Registration accept message identity          Message type 9.7                             M           V          1 
            5GS registration result                       5GS registration result 9.11.3.6             M           LV         2 
   77       5GS GUTI                                      5GS mobile identity 9.11.3.4                 O           TLV-E      14
   4A       Equivalent PLMNs                              PLMN list 9.11.3.45                          O           TLV        5-47 
   54       TAI list                                      5GS tracking area identity list 9.11.3.9     O           TLV        9-114 
   15       Allowed NSSAI                                 NSSAI9.11.3.37                               O           TLV        4-74
   11       Rejected NSSAI                                Rejected NSSAI9.11.3.46                      O           TLV        4-42 
   31       Configured NSSAI                              NSSAI9.11.3.37                               O           TLV        4-146 
   21       5GS network feature support                   5GS network feature support9.11.3.5          O           TLV        3-5
   50       PDU session status                            PDU session status9.11.3.44                  O           TLV        4-34
   26       PDU session reactivation result               PDU session reactivation result 9.11.3.42    O           TLV        4-34 
   72       PDU session reactivation result error cause   Error cause 9.11.3.43                        O           TLV-E      5-515
   79       LADN information                              LADN information 9.11.3.30                   O           TLV-E      12-1715 
   B-       MICO indication                               MICO indication 9.11.3.31                    O           TV         1
   9-       Network slicing indication                    Network slicing indication 9.11.3.36         O           TV         1 
   27       Service area list                             Service area list 9.11.3.49                  O           TLV        6-114
   5E       T3512 value                                   GPRS timer 3 9.11.2.5                        O           TLV        3
   5D       Non-3GPP de-registration timer value          GPRS timer 2 9.11.2.4                        O           TLV        3
   16       T3502 value                                   GPRS timer 2 9.11.2.4                        O           TLV        3 
   34       Emergency number list                         Emergency number list 9.11.3.23              O           TLV        5-50 
   7A       Extended emergency number list                Extended emergency number list 9.11.3.26     O           TLV-E      7-65538 
   73       SOR transparent container                     SOR transparent container 9.11.3.51          O           TLV-E      20-2048 
   78       EAP message                                   EAP message 9.11.2.2                         O           TLV-E      7-1503
   A-       NSSAI inclusion mode                          NSSAI inclusion mode 9.11.3.37A              O           TV         1 
   76       Operator-defined access category definitions  Category definitions 9.11.3.38               O           TLV-E      3-n 
   51       Negotiated DRX parameters                     5GS DRX parameters 9.11.3.2A                 O           TLV        3
   D-       Non-3GPP NW policies                          Non-3GPP NW provided policies 9.11.3.36A     O           TV         1 
   60       EPS bearer context status                     EPS bearer context status 9.11.3.23A         O           TLV        4

*/
