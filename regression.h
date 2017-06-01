#ifndef REGRESSION_H_
#define REGRESSION_H_

#include <nan.h>

class RVM : public Nan::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit RVM(int sample_width);
    ~RVM();

    static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static Nan::Persistent<v8::Function> constructor;

    int _sample_width;
};

#endif // REGRESSION_H_
