#include "regression.h"

Nan::Persistent<v8::Function> RVM::constructor;

RVM::RVM(int sample_width) : _sample_width(sample_width) { }

RVM::~RVM() { }

void RVM::Init(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("RVM").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  // Nan::SetPrototypeMethod(tpl, "value", GetValue);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("RVM").ToLocalChecked(), tpl->GetFunction());
}

void RVM::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.IsConstructCall()) {
    // Invoked as constructor: `new RVM(...)`
    int s_width_val = (int)info[0]->IsUndefined() ? 0 : info[0]->NumberValue();
    RVM* obj = new RVM(s_width_val);
    // obj->Set()
    obj->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  } else {
    // Invoked as plain function `RVM(...)`, turn into construct call.
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { info[0] };
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor, argc, argv);
    v8::MaybeLocal<v8::Object> inst = Nan::NewInstance(cons, argc, argv);
    if (!inst.IsEmpty())
      info.GetReturnValue().Set(inst.ToLocalChecked());
  }
}
