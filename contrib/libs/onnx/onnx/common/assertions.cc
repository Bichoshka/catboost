/*
 * SPDX-License-Identifier: Apache-2.0
 */

// ATTENTION: The code in this file is highly EXPERIMENTAL.
// Adventurous users should note that the APIs will probably change.

#include "onnx/common/assertions.h"
#include <cstdarg>
#include <cstdio>
#include "onnx/common/common.h"

namespace ONNX_NAMESPACE {

TString barf(const char* fmt, ...) {
  char msg[2048];
  va_list args;

  va_start(args, fmt);
  vsnprintf(msg, 2048, fmt, args);
  va_end(args);

  return TString(msg);
}

void throw_assert_error(TString& msg) {
  ONNX_THROW_EX(assert_error(msg));
}

void throw_tensor_error(TString& msg) {
  ONNX_THROW_EX(tensor_error(msg));
}

} // namespace ONNX_NAMESPACE
