#include <nan.h>
#include "frontalFaceDetector.h"
#include "regression.h"

void InitAll(v8::Local<v8::Object> exports) {
  FrontalFaceDetector::Init(exports);
  RVM::Init(exports);
}

NODE_MODULE(dlib, InitAll)
