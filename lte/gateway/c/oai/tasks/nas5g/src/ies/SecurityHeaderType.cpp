#include <iostream>
#include <sstream>
#include <cstdint>
#include "SecurityHeaderType.h"
#include "CommonDefs.h"

using namespace std;
namespace magma5g {
SecurityHeaderTypeMsg::SecurityHeaderTypeMsg(){};

SecurityHeaderTypeMsg::~SecurityHeaderTypeMsg(){};

// Decode SecurityHeaderType IE
int SecurityHeaderTypeMsg::DecodeSecurityHeaderTypeMsg(
    SecurityHeaderTypeMsg* sec_header_type, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  int decoded = 0;

  MLOG(MDEBUG) << "   DecodeSecurityHeaderTypeMsg : ";
  sec_header_type->sec_hdr = *(buffer) &0xf;
  decoded++;
  MLOG(MDEBUG) << " Security header type = " << dec
               << int(sec_header_type->sec_hdr);
  return (decoded);
};

// Encode SecurityHeaderType IE
int SecurityHeaderTypeMsg::EncodeSecurityHeaderTypeMsg(
    SecurityHeaderTypeMsg* sec_header_type, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  int encoded = 0;

  MLOG(MDEBUG) << " EncodeSecurityHeaderTypeMsg : ";
  *(buffer) = sec_header_type->sec_hdr & 0xf;
  encoded++;
  MLOG(MDEBUG) << "Security header type = 0x" << hex << int(*(buffer));
  return (encoded);
};
}  // namespace magma5g
