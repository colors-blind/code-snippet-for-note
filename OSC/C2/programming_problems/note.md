# Try strace on Linux and dstruss on macOS

- strace:

hello.c:

```
$ strace ./hello 

execve("./hello", ["./hello"], [/* 29 vars */]) = 0
brk(0)                                  = 0x920000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f30c8b04000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY)      = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=55857, ...}) = 0
mmap(NULL, 55857, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f30c8af6000
close(3)                                = 0
open("/lib64/libc.so.6", O_RDONLY)      = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0000\356\1\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1924768, ...}) = 0
mmap(NULL, 3750184, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f30c8551000
mprotect(0x7f30c86db000, 2097152, PROT_NONE) = 0
mmap(0x7f30c88db000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x18a000) = 0x7f30c88db000
mmap(0x7f30c88e1000, 14632, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f30c88e1000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f30c8af5000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f30c8af4000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f30c8af3000
arch_prctl(ARCH_SET_FS, 0x7f30c8af4700) = 0
mprotect(0x7f30c88db000, 16384, PROT_READ) = 0
mprotect(0x7f30c8b05000, 4096, PROT_READ) = 0
munmap(0x7f30c8af6000, 55857)           = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f30c8b03000
write(1, "Hello world", 11Hello world)             = 11
exit_group(11)                          = ?
+++ exited with 11 +++

$ echo $?
11

``` 

- dstruss

```
sudo dtruss ./hello

Hello worldSYSCALL(args)         = return
thread_selfid(0x0, 0x0, 0x0)         = 1262881 0
open(".\0", 0x0, 0x1)        = 3 0
fstat64(0x3, 0x7FFF5A5A8010, 0x1)        = 0 0
fcntl(0x3, 0x32, 0x7FFF5A5A8300)         = 0 0
close(0x3)       = 0 0
stat64("/Users/leeyang/VBox/app/github/code-snippets-for-note/OSC/C2/programming_problems\0", 0x7FFF5A5A7F80, 0x7FFF5A5A8300)    = 0 0
csops(0x0, 0x0, 0x7FFF5A5A8278)      = 0 0
issetugid(0x0, 0x0, 0x7FFF5A5A8278)      = 0 0
shared_region_check_np(0x7FFF5A5A61B8, 0x0, 0x7FFF5A5A8278)      = 0 0
stat64("/usr/lib/dtrace/libdtrace_dyld.dylib\0", 0x7FFF5A5A7348, 0x7FFF5A5A8278)         = 0 0
open("/usr/lib/dtrace/libdtrace_dyld.dylib\0", 0x0, 0x0)         = 3 0
pread(0x3, "\312\376\272\276\0", 0x1000, 0x0)        = 4096 0
pread(0x3, "\317\372\355\376\a\0", 0x1000, 0x1000)       = 4096 0
fcntl(0x3, 0x3D, 0x7FFF5A5A56B0)         = 0 0
mmap(0x10565C000, 0x2000, 0x5, 0x12, 0x3, 0x1000)        = 0x10565C000 0
mmap(0x10565E000, 0x1000, 0x3, 0x12, 0x3, 0x3000)        = 0x10565E000 0
mmap(0x10565F000, 0x1FC0, 0x1, 0x12, 0x3, 0x4000)        = 0x10565F000 0
close(0x3)       = 0 0
stat64("/usr/lib/dtrace/libdtrace_dyld.dylib\0", 0x7FFF5A5A7CC8, 0x1)        = 0 0
stat64("/usr/lib/libSystem.B.dylib\0", 0x7FFF5A5A7178, 0x1)      = 0 0
stat64("/usr/lib/system/libcache.dylib\0", 0x7FFF5A5A6D68, 0x1)      = 0 0
stat64("/usr/lib/system/libcommonCrypto.dylib\0", 0x7FFF5A5A6D68, 0x1)       = 0 0
stat64("/usr/lib/system/libcompiler_rt.dylib\0", 0x7FFF5A5A6D68, 0x1)        = 0 0
stat64("/usr/lib/system/libcopyfile.dylib\0", 0x7FFF5A5A6D68, 0x1)       = 0 0
stat64("/usr/lib/system/libcorecrypto.dylib\0", 0x7FFF5A5A6D68, 0x1)         = 0 0
stat64("/usr/lib/system/libdispatch.dylib\0", 0x7FFF5A5A6D68, 0x1)       = 0 0
stat64("/usr/lib/system/libdyld.dylib\0", 0x7FFF5A5A6D68, 0x1)       = 0 0
stat64("/usr/lib/system/libkeymgr.dylib\0", 0x7FFF5A5A6D68, 0x1)         = 0 0
stat64("/usr/lib/system/liblaunch.dylib\0", 0x7FFF5A5A6D68, 0x1)         = 0 0
stat64("/usr/lib/system/libmacho.dylib\0", 0x7FFF5A5A6D68, 0x1)      = 0 0
stat64("/usr/lib/system/libquarantine.dylib\0", 0x7FFF5A5A6D68, 0x1)         = 0 0

...

getpid(0x7FFF930E8740, 0x7FFF5A5A5E18, 0x1)      = 61681 0
open("/dev/dtracehelper\0", 0x2, 0x7FFF5A5A8170)         = 3 0
ioctl(0x3, 0x80086804, 0x7FFF5A5A80F8)       = 0 0
close(0x3)       = 0 0
sysctl(0x7FFF5A5A77B8, 0x2, 0x7FFF5A5A77C8)      = 0 0
thread_selfid(0x7FFF5A5A77B8, 0x2, 0x7FFF5A5A77C8)       = 1262881 0
bsdthread_register(0x7FFF9349C3E0, 0x7FFF9349C3D0, 0x2000)       = 1073741855 0
mprotect(0x105661000, 0x88, 0x1)         = 0 0
mprotect(0x105663000, 0x1000, 0x0)       = 0 0
mprotect(0x105679000, 0x1000, 0x0)       = 0 0
mprotect(0x10567A000, 0x1000, 0x0)       = 0 0
mprotect(0x105690000, 0x1000, 0x0)       = 0 0
mprotect(0x105691000, 0x1000, 0x1)       = 0 0
mprotect(0x105661000, 0x88, 0x3)         = 0 0
mprotect(0x105661000, 0x88, 0x1)         = 0 0
issetugid(0x105661000, 0x88, 0x1)        = 0 0
getpid(0x105661000, 0x88, 0x1)       = 61681 0
stat64("/AppleInternal/XBS/.isChrooted\0", 0x7FFF5A5A7718, 0x1)      = -1 Err#2
stat64("/BuildSupport/makeProject\0", 0x7FFF5A5A7718, 0x1)       = -1 Err#2
stat64("/AppleInternal\0", 0x7FFF5A5A7688, 0x1)      = -1 Err#2
csops(0xF0F1, 0x7, 0x7FFF5A5A71B0)       = -1 Err#22
csops(0xF0F1, 0x7, 0x7FFF5A5A6A90)       = -1 Err#22
getrlimit(0x1008, 0x7FFF5A5A81F0, 0x7FFF5A5A6A90)        = 0 0
fstat64(0x1, 0x7FFF5A5A8288, 0x7FFF5A5A6A90)         = 0 0
ioctl(0x1, 0x4004667A, 0x7FFF5A5A82CC)       = 0 0
write_nocancel(0x1, "Hello world\0", 0xB)        = 11 0

```


