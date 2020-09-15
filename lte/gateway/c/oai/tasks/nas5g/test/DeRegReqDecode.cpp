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

/* using this stub code we are going to test Decoding functionality of De-Registration Request Message */

#include <iostream>
#include "DeRegistrationRequestUEInit.h"
#include "CommonDefs.h"
using namespace std;
using namespace magma5g;

namespace magma5g
{
   int decode(void)
   {
      int ret = 0;
      //Message to be Decoded
      uint8_t buffer[] = {0x7E, 0x00, 0x45, 0x01, 0x00, 0x0B, 0xF2, 0x13, 0x00, 0x14,0x44, 0x33, 0x12, 0x00, 0x00, 0x00, 0x01};
      int len = 17;
      DeRegistrationRequestUEInitMsg De_Req;
      MLOG(MDEBUG) << "\n\n---Decoding De-registration request (UE originating) Message---\n\n";
      ret = De_Req.DecodeDeRegistrationRequestUEInitMsg( &De_Req, buffer, len);

      MLOG(BEBUG) << "\n\n ---DECODED MESSAGE ---\n\n";
      MLOG(MDEBUG) << " Extended Protocol Discriminator :"<< dec << int(De_Req.extendedprotocoldiscriminator.extendedprotodiscriminator);
      MLOG(MDEBUG) << " Spare half octet : " << dec  << int(De_Req.sparehalfoctet.spare);
      MLOG(MDEBUG) << " Security Header Type : " << dec << int(De_Req.securityheadertype.securityhdr);
      MLOG(MDEBUG) << " Message Type : 0x" << hex << int(De_Req.messagetype.msgtype);
      MLOG(MDEBUG) << " M5GS De-Registration Type :";
      MLOG(DEBUG)  << "   Switch off = "<< dec << int(De_Req.m5gsderegistrationtype.switchoff);
      MLOG(MDEBUG) << "   Re-registration required = "<< dec << int(De_Req.m5gsderegistrationtype.reregistrationrequired);
      MLOG(MDEBUG) << "   Access Type = "<< dec << int(De_Req.m5gsderegistrationtype.accesstype);
      MLOG(MDEBUG) << " NAS key set identifier : ";
      MLOG(MDEBUG) << "   Type of security context flag = " << dec << int(De_Req.naskeysetidentifier.tsc);
      MLOG(MDEBUG) << "   NAS key set identifier = " << dec << int(De_Req.naskeysetidentifier.naskeysetidentifier);
      MLOG(MDEBUG) << " M5GS mobile identity : ";
      MLOG(MDEBUG) << "   Odd/even Indication = "<< dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.oddeven);
      MLOG(MDEBUG) << "   Type of identity = " << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.typeofidentity);
      MLOG(MDEBUG) << "   Mobile Country Code (MCC) = "<< dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.mcc_digit1) << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.mcc_digit2) << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.mcc_digit3);
      MLOG(MDEBUG) << "   Mobile NetWork Code (MNC) = "<< dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.mnc_digit1) << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.mnc_digit2) << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.mnc_digit3);
      MLOG(MDEBUG) << " AMF Region ID = " << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.amfregionid);
      MLOG(MDEBUG) << " AMF Set ID = " << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.amfsetid);
      MLOG(MDEBUG) << " AMF Pointer = " << dec << int(De_Req.m5gsmobileidentity.mobileidentity.guti.amfpointer);
      MLOG(MDEBUG) << " 5G-TMSI = 0x0" << hex << int(De_Req.m5gsmobileidentity.mobileidentity.guti.tmsi1) << "0" << hex << int(De_Req.m5gsmobileidentity.mobileidentity.guti.tmsi2) << "0" << hex << int(De_Req.m5gsmobileidentity.mobileidentity.guti.tmsi3) << "0" << hex << int(De_Req.m5gsmobileidentity.mobileidentity.guti.tmsi4)<<"\n\n";

      return 0;
   }
}  

//Main Function to call test decode function
int main(void)
{
   int ret;
   ret = magma5g::decode();
   return 0;
   }
