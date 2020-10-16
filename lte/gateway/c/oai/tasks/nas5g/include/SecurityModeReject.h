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
#include "5GMMCause.h"

using namespace std;
namespace magma5g {
class SecurityModeRejectMsg {
 public:
  ExtendedProtocolDiscriminatorMsg extended_protocol_discriminator;
  SecurityHeaderTypeMsg sec_header_type;
  SpareHalfOctetMsg spare_half_octet;
  MessageTypeMsg message_type;
  M5GMMCauseMsg m5gmm_cause;
#define SECURITY_MODE_REJECT_MINIMUM_LENGTH 4

  SecurityModeRejectMsg();
  ~SecurityModeRejectMsg();
  int DecodeSecurityModeRejectMsg(
      SecurityModeRejectMsg* sec_mode_reject, uint8_t* buffer, uint32_t len);
  int EncodeSecurityModeRejectMsg(
      SecurityModeRejectMsg* sec_mode_reject, uint8_t* buffer, uint32_t len);
};
}  // namespace magma5g
/*
   Table 8.2.27.1.1: SECURITY_MODE REJECT message content

   IEI           Information Element                            Type/Reference                      Presence     Format     Length

            Extended protocol discriminator               Extended Protocol discriminator 9.2          M           V          1 
            Security header type                          Security header type 9.3                     M           V          1/2 
            Spare half octet                              Spare half octet 9.5                         M           V          1/2 
            Registration Reject  message identity         Message type 9.7                             M           V          1 
            5GMM Cause                                    5GMM Cause 9.11.3.2                          M           V          1
*/
