#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <stdio.h>
#import <sys/stat.h>
#import <sys/statvfs.h>
#import <sys/mount.h>
#import <sys/syscall.h>
#import <sys/utsname.h>
#import <sys/syslimits.h>
#import <sys/time.h>
#import <errno.h>
#import <fcntl.h>
#import <mach-o/dyld.h>
#import <mach-o/dyld_images.h>
#import <mach-o/nlist.h>
#import <dlfcn.h>
#import <dirent.h>
#import <sys/sysctl.h>
#import <mach/mach.h>
#import <mach/task_info.h>
#import <mach/mach_traps.h>
#import <mach/host_special_ports.h>
#import <mach/task_special_ports.h>
#import <sandbox.h>
#import <bootstrap.h>
#import <spawn.h>
#import <objc/runtime.h>

#import "../../api/common.h"
#import "../../api/Shadow.h"
#import <substrate.h>
#import <HookKit.h>

// HookKit overrides
#ifdef hookkit_h
#define MSHookFunction(a, b, c) [hooks hookFunction:a withReplacement:b outOldPtr:c]
#define MSHookMessageEx HKHookMessage
#define MSGetImageByName HKOpenImage
#define MSFindSymbol HKFindSymbol
#define MSCloseImage HKCloseImage
#endif

// private symbols
#import "../../apple_priv/dyld_priv.h"
#import "../../apple_priv/codesign.h"
#import "../../apple_priv/ptrace.h"

extern Shadow* _shadow;

extern void shadowhook_DeviceCheck(HKSubstitutor* hooks);
extern void shadowhook_dyld(HKSubstitutor* hooks);
extern void shadowhook_libc(HKSubstitutor* hooks);
extern void shadowhook_mach(HKSubstitutor* hooks);
extern void shadowhook_NSArray(HKSubstitutor* hooks);
extern void shadowhook_NSBundle(HKSubstitutor* hooks);
extern void shadowhook_NSData(HKSubstitutor* hooks);
extern void shadowhook_NSDictionary(HKSubstitutor* hooks);
extern void shadowhook_NSFileHandle(HKSubstitutor* hooks);
extern void shadowhook_NSFileManager(HKSubstitutor* hooks);
extern void shadowhook_NSFileVersion(HKSubstitutor* hooks);
extern void shadowhook_NSFileWrapper(HKSubstitutor* hooks);
extern void shadowhook_NSProcessInfo(HKSubstitutor* hooks);
extern void shadowhook_NSString(HKSubstitutor* hooks);
extern void shadowhook_NSURL(HKSubstitutor* hooks);
extern void shadowhook_objc(HKSubstitutor* hooks);
extern void shadowhook_sandbox(HKSubstitutor* hooks);
extern void shadowhook_syscall(HKSubstitutor* hooks);
extern void shadowhook_sysctl(HKSubstitutor* hooks);
extern void shadowhook_UIApplication(HKSubstitutor* hooks);
extern void shadowhook_UIImage(HKSubstitutor* hooks);
extern void shadowhook_libc_extra(HKSubstitutor* hooks);
extern void shadowhook_libc_envvar(HKSubstitutor* hooks);
extern void shadowhook_libc_lowlevel(HKSubstitutor* hooks);
extern void shadowhook_libc_antidebugging(HKSubstitutor* hooks);
extern void shadowhook_dyld_extra(HKSubstitutor* hooks);
extern void shadowhook_dyld_symlookup(HKSubstitutor* hooks);
extern void shadowhook_dyld_symaddrlookup(HKSubstitutor* hooks);
extern void shadowhook_dyld_updatelibs(const struct mach_header* mh, intptr_t vmaddr_slide);
extern void shadowhook_dyld_updatelibs_r(const struct mach_header* mh, intptr_t vmaddr_slide);
extern void shadowhook_dyld_shdw_add_image(const struct mach_header* mh, intptr_t vmaddr_slide);
extern void shadowhook_dyld_shdw_remove_image(const struct mach_header* mh, intptr_t vmaddr_slide);
extern void shadowhook_NSProcessInfo_fakemac(HKSubstitutor* hooks);
extern void shadowhook_mem(HKSubstitutor* hooks);
extern void shadowhook_objc_hidetweakclasses(HKSubstitutor* hooks);
extern void shadowhook_LSApplicationWorkspace(HKSubstitutor* hooks);
