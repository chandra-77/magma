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

using namespace std;
namespace magma5g {
class RegistrationCompleteMsg {
 public:
  ExtendedProtocolDiscriminatorMsg extended_protocol_discriminator;
  SecurityHeaderTypeMsg sec_header_type;
  SpareHalfOctetMsg spare_half_octet;
  MessageTypeMsg message_type;
#define REGISTRATION_COMPLETE_MINIMUM_LENGTH 3

  RegistrationCompleteMsg();
  ~RegistrationCompleteMsg();
  int DecodeRegistrationCompleteMsg(
      RegistrationCompleteMsg* reg_complete, uint8_t* buffer, uint32_t len);
  int EncodeRegistrationCompleteMsg(
      RegistrationCompleteMsg* reg_complete, uint8_t* buffer, uint32_t len);
};
}  // namespace magma5g
/*
   Table 8.2.8.1.1: REGISTRATION COMPLETE message content

   IEI           Information Element                            Type/Reference                      Presence     Format     Length

            Extended protocol discriminator               Extended Protocol discriminator 9.2          M           V          1 
            Security header type                          Security header type 9.3                     M           V          1/2 
            Spare half octet                              Spare half octet 9.5                         M           V          1/2 
            Registration complete  message identity       Message type 9.7                             M           V          1 
   */
