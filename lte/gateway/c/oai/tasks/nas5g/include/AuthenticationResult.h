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
#include "SpareHalfOctet.h"
#include "SecurityHeaderType.h"
#include "MessageType.h"
#include "NASKeySetIdentifier.h"
#include "EAPMessage.h"
using namespace std;
namespace magma5g {
class AuthenticationResultMsg {
 public:
  AuthenticationResultMsg();
  ~AuthenticationResultMsg();

  ExtendedProtocolDiscriminatorMsg extendedprotocoldiscriminator;
  SecurityHeaderTypeMsg securityheadertype;
  SpareHalfOctetMsg sparehalfoctet;
  MessageTypeMsg messagetype;
  NASKeySetIdentifierMsg naskeysetidentifier;
  EAPMessageMsg eapmessage;
#define AUTHENTICATION_RESULT_MINIMUM_LENGTH 10
  int DecodeAuthenticationResultMsg(
      AuthenticationResultMsg* authenticationresult,
      uint8_t* buffer, uint32_t len);
  int EncodeAuthenticationResultMsg(
      AuthenticationResultMsg* authenticationresult,
      uint8_t* buffer, uint32_t len);
};
}  // namespace magma5g

/*
AUTHENTICATION RESULT message content

IEI  Information Element             Type/Reference                        Presence   Format     Length

     Extended protocol discriminator Extended protocol discriminator 9.2       M         V          1
     Security header type            Security header type            9.3       M         V          1/2
     Spare half octet                Spare half                      9.5       M         V          1/2
     Authentication Result Msg       Message type                    9.7       M         V          1
     ngKSI                           NAS key set identifier      9.11.3.32     M         V          1/2 
     Spare half octet                Spare half                      9.5       M         V          1/2
     EAP message                     EAP message 9.11.2.2                      M         LV-E       6-1502     
*/
