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
#include "PDUSessionIdentity.h"
#include "PTI.h"
#include "MessageType.h"
#include "5GSMCause.h"

using namespace std;
namespace magma5g {
// PDUSessionEstablishmentReject Message Class
class PDUSessionEstablishmentRejectMsg {
 public:
#define PDU_SESSION_ESTABLISHMENT_REJ_MIN_LEN 5
  ExtendedProtocolDiscriminatorMsg extended_protocol_discriminator;
  PDUSessionIdentityMsg pdu_session_identity;
  PTIMsg pti;
  MessageTypeMsg message_type;
  M5GSMCauseMsg m5gsm_cause;

  PDUSessionEstablishmentRejectMsg();
  ~PDUSessionEstablishmentRejectMsg();
  int DecodePDUSessionEstablishmentRejectMsg(
      PDUSessionEstablishmentRejectMsg* pdu_session_estab_reject,
      uint8_t* buffer, uint32_t len);
  int EncodePDUSessionEstablishmentRejectMsg(
      PDUSessionEstablishmentRejectMsg* pdu_session_estab_reject,
      uint8_t* buffer, uint32_t len);
};
}  // namespace magma5g
