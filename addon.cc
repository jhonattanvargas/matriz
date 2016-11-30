#include <node.h>
#include <iostream>
#include <v8.h>
#include <cmath>
using namespace std;

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::NumberObject;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
using v8::Integer;



void showArray (const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  /*
  Local<Array> argv_handle = Local<Array>::Cast(args[0]);
  for (int i = 0; i < argv_handle->Length(); i++) {
    String::Utf8Value arg(argv_handle->Get(i)->ToString());
    if(!isnan(stod(*arg))){
      cout << stod(*arg) << " | ";
    }
  }
  */
  int m[3][3];
  int m2[3][3];
  int s[3][3];
  if (args[0]->IsArray()) {
    std::cout << "matriz x" << std::endl;
    Local<Array> a = Local<Array>::Cast(args[0]);
    for (int index = 0, size = a->Length(); index < size; index++) {
      Local<Value> element = a->Get(index);
      if (element->IsArray()) {
        Local<Array> b = Local<Array>::Cast(element);
        for (int index2 = 0, size2 = b->Length(); index2 < size2; index2++) {
          Local<Value> element2 = b->Get(index2);
          String::Utf8Value arg(b->Get(index2)->ToString());
          if(!isnan(stod(*arg))){
            m[index][index2] = stod(*arg);
            cout << stod(*arg) << " | ";
          }
        }
      }
      cout << endl;
    }
  }

  if (args[1]->IsArray()) {
    std::cout << "matriz y" << std::endl;
    Local<Array> a = Local<Array>::Cast(args[1]);
    for (int index = 0, size = a->Length(); index < size; index++) {
      Local<Value> element = a->Get(index);
      if (element->IsArray()) {
        Local<Array> b = Local<Array>::Cast(element);
        for (int index2 = 0, size2 = b->Length(); index2 < size2; index2++) {
          Local<Value> element2 = b->Get(index2);
          String::Utf8Value arg(b->Get(index2)->ToString());
          if(!isnan(stod(*arg))){
            m2[index][index2] = stod(*arg);
            cout << stod(*arg) << " | ";
          }
        }
      }
      cout << endl;
    }
  }

  Local<Array> result = Array::New(isolate);

  std::cout << "result " << std::endl;
  for (int i = 0; i < 3; i++) {
    Local<Array> aux = Array::New(isolate);
    for (int j = 0; j < 3; j++) {
      s[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        s[i][j] = s[i][j] + (m[i][k] * m2[k][j]);
      }
      aux->Set(j,Integer::New(isolate,s[i][j]));
      std::cout << s[i][j] << " | ";
    }
    result->Set(i,aux);
    std::cout << std::endl;
  }


   args.GetReturnValue().Set(result);
}



void Init(Local<Object> exports) {
NODE_SET_METHOD(exports, "showArray", showArray);
}

NODE_MODULE(addon, Init)
