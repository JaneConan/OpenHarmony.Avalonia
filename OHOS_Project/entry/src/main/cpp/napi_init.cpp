#include <cassert>
#include <dlfcn.h>
#include <stdlib.h>


extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    setenv("ICU_DATA", "/system/usr/ohos_icu", 0);
    auto handle = dlopen("libavalonia.so", RTLD_NOW);
    assert(handle != nullptr);
    auto func = (void(*)())dlsym(handle, "RegisterEntryModule");
    assert(func != nullptr);
    func();
}
