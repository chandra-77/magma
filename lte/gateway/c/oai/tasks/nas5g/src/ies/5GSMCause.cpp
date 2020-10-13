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

#include <iostream>
#include <sstream>
#include <cstdint>
#include <cstring>
#include "5GSMCause.h"
#include "CommonDefs.h"
using namespace std;
namespace magma5g {
M5GSMCauseMsg::M5GSMCauseMsg(){};
M5GSMCauseMsg::~M5GSMCauseMsg(){};

// Decode M5GSMCause IE
int M5GSMCauseMsg::DecodeM5GSMCauseMsg(
    M5GSMCauseMsg* m5gsmcause, uint8_t iei, uint8_t* buffer, uint32_t len) {
  int decoded    = 0;
  uint32_t ielen = 0;

  if (iei > 0) {
    m5gsmcause->iei = *buffer;
    CHECK_IEI_DECODER(iei, (unsigned char) m5gsmcause->iei);
  }

  m5gsmcause->causevalue = *buffer;
  decoded++;
  MLOG(MDEBUG) << "DecodeM5GSMCauseMsg__: iei = " << hex << int(m5gsmcause->iei)
               << endl;
  MLOG(MDEBUG) << "DecodeM5GSMCauseMsg__: causevalue = " << hex
               << int(m5gsmcause->causevalue) << endl;

  return (decoded);
};

// Encode M5GSMCause IE
int M5GSMCauseMsg::EncodeM5GSMCauseMsg(
    M5GSMCauseMsg* m5gsmcause, uint8_t iei, uint8_t* buffer, uint32_t len) {
  int encoded = 0;

  if (iei > 0) {
    m5gsmcause->iei = *buffer;
    CHECK_IEI_DECODER(iei, (unsigned char) m5gsmcause->iei);
  }

  *(buffer + encoded) = m5gsmcause->causevalue;
  MLOG(MDEBUG) << "EncodeM5GSMCauseMsg__: causevalue = " << hex
               << int(m5gsmcause->causevalue) << endl;

  return (encoded);
};
}  // namespace magma5g
