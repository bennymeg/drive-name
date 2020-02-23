#include <napi.h>
#include "DriveName.h"

Napi::String getDriveNameWrapped(const Napi::CallbackInfo& callbackInfo) {
    Napi::Env env = callbackInfo.Env();

    std::string driveName = drivename::getDriveName(callbackInfo[0].ToString());
    
    return Napi::String::New(env, driveName);
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    exports.Set("getDriveName", Napi::Function::New(env, getDriveNameWrapped));
    
    return exports;
}

NODE_API_MODULE(drive_name, InitAll);
