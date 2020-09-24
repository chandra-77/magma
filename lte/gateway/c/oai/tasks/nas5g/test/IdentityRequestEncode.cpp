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

/* using this stub code we are going to test Encoding functionality of Identity
 * Request Message */

#include <iostream>
#include <iomanip>
#include "IdentityRequest.h"
#include "CommonDefs.h"

using namespace std;
using namespace magma5g;

namespace magma5g {
int encode(void) {
  int ret           = 0;
  uint8_t buffer[4] = {};
  int len           = 4;
  IdentityRequestMsg msg;

  // Message to be Encoded
  msg.extendedprotocoldiscriminator.extendedprotodiscriminator = 126;
  msg.securityheadertype.securityhdr                           = 0;
  msg.sparehalfoctet.spare                                     = 0;
  msg.messagetype.msgtype                                      = 0x5B;
  msg.sparehalfoctet.spare                                     = 0;
  msg.m5gsidentitytype.toi                                     = 1;

  MLOG(MDEBUG) << "---Encoding message--- \n";
  ret = msg.EncodeIdentityRequestMsg(&msg, buffer, len);

  MLOG(MDEBUG) << " ENCODED MESSAGE : " << setfill('0') << hex << setw(2)
               << int(buffer[0]) << hex << setw(2) << int(buffer[1]) << hex
               << setw(2) << int(buffer[2]) << hex << setw(2) << int(buffer[3])
               << "\n";

  MLOG(MDEBUG) << "---Decoding encoded message--- ";
  int ret2 = 0;
  ret2     = msg.DecodeIdentityRequestMsg(&msg, buffer, len);
  MLOG(MDEBUG) << "\n\n";
  return 0;
}
}  // namespace magma5g

int main(void) {
  int ret;
  ret = magma5g::encode();
  return 0;
}
