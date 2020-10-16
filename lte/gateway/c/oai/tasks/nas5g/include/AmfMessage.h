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
#include "RegistrationRequest.h"
#include "RegistrationAccept.h"
#include "RegistrationComplete.h"
#include "RegistrationReject.h"
#include "IdentityRequest.h"
#include "IdentityResponse.h"
#include "AuthenticationRequest.h"
#include "AuthenticationResponse.h"
#include "AuthenticationReject.h"
#include "AuthenticationFailure.h"
#include "SecurityModeCommand.h"
#include "SecurityModeComplete.h"
#include "SecurityModeReject.h"
#include "DeRegistrationRequestUEInit.h"
#include "DeRegistrationAcceptUEInit.h"

using namespace std;
namespace magma5g {
// Amf NAS Msg Header Class
class AmfMsgHeader {
 public:
  uint8_t extended_protocol_discriminator;
  uint8_t sec_header_type;
  uint8_t message_type;
};

// Amf NAS Msg Class
class AmfMsg {
 public:
  AmfMsgHeader header;
  RegistrationRequestMsg reg_request;
  RegistrationAcceptMsg reg_accept;
  RegistrationCompleteMsg reg_complete;
  RegistrationRejectMsg reg_reject;
  IdentityRequestMsg identity_request;
  IdentityResponseMsg identity_response;
  AuthenticationRequestMsg auth_request;
  AuthenticationResponseMsg auth_response;
  AuthenticationRejectMsg auth_reject;
  AuthenticationFailureMsg auth_failure;
  SecurityModeCommandMsg sec_mode_command;
  SecurityModeCompleteMsg sec_mode_complete;
  SecurityModeRejectMsg sec_mode_reject;
  DeRegistrationRequestUEInitMsg de_reg_request;
  DeRegistrationAcceptUEInitMsg de_reg_accept;

  AmfMsg();
  ~AmfMsg();
  int M5gNasMessageEncodeMsg(AmfMsg* msg, uint8_t* buffer, uint32_t len);
  int M5gNasMessageDecodeMsg(AmfMsg* msg, uint8_t* buffer, uint32_t len);
  int AmfMsgDecodeHeaderMsg(
      AmfMsgHeader* header, uint8_t* buffer, uint32_t len);
  int AmfMsgEncodeHeaderMsg(
      AmfMsgHeader* header, uint8_t* buffer, uint32_t len);
  int AmfMsgDecodeMsg(AmfMsg* msg, uint8_t* buffer, uint32_t len);
  int AmfMsgEncodeMsg(AmfMsg* msg, uint8_t* buffer, uint32_t len);
};
}  // namespace magma5g
