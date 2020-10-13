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

#include <sstream>
#include <cstdint>
#include "PDUSessionIdentity.h"
#include "CommonDefs.h"

using namespace std;
namespace magma5g {
PDUSessionIdentityMsg::PDUSessionIdentityMsg(){};
PDUSessionIdentityMsg::~PDUSessionIdentityMsg(){};

// Decode PDUSessionIdentity IE
int PDUSessionIdentityMsg::DecodePDUSessionIdentityMsg(
    PDUSessionIdentityMsg* pdusessionidentity, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  uint8_t decoded = 0;

  MLOG(MDEBUG) << "   DecodePDUSessionIdentityMsg : ";
  pdusessionidentity->pdusessionid = *(buffer + decoded);
  decoded++;
  MLOG(MDEBUG) << " PDUSessionIdentity = " << hex
               << int(pdusessionidentity->pdusessionid);

  return (decoded);
};

// Encode PDUSessionIdentity IE
int PDUSessionIdentityMsg::EncodePDUSessionIdentityMsg(
    PDUSessionIdentityMsg* pdusessionidentity, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  int encoded = 0;

  MLOG(MDEBUG) << " EncodePDUSessionIdentityMsg : ";
  *(buffer + encoded) = pdusessionidentity->pdusessionid;
  MLOG(MDEBUG) << "PDUSessionIdentity = 0x" << hex << int(*(buffer + encoded));
  encoded++;

  return (encoded);
};
}  // namespace magma5g
