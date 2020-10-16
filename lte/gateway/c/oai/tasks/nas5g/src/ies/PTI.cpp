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
#include "PTI.h"
#include "CommonDefs.h"

using namespace std;
namespace magma5g {
PTIMsg::PTIMsg(){};
PTIMsg::~PTIMsg(){};

// Decode PTI IE
int PTIMsg::DecodePTIMsg(
    PTIMsg* pti, uint8_t iei, uint8_t* buffer, uint32_t len) {
  uint8_t decoded = 0;

  MLOG(MDEBUG) << " DecodePTIMsg : ";
  pti->pti = *(buffer + decoded);
  decoded++;
  MLOG(MDEBUG) << " PTI = 0x" << hex << int(pti->pti);

  return (decoded);
};

// Encode PTI IE
int PTIMsg::EncodePTIMsg(
    PTIMsg* pti, uint8_t iei, uint8_t* buffer, uint32_t len) {
  int encoded = 0;

  MLOG(MDEBUG) << " EncodePTIMsg : ";
  *(buffer + encoded) = pti->pti;
  MLOG(MDEBUG) << "PTI = 0x" << hex << int(*(buffer + encoded));
  encoded++;

  return (encoded);
};
}  // namespace magma5g
