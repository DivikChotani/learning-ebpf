🔍 1. fentry Fails on ARM: Needs Kernel 6.0+
❌ fentry at do_execve() not working:
➜ “fentry requires kernel version 6.0 on ARM”

✅ Why this happens:
fentry (and its sibling fexit) rely on the BPF trampoline infrastructure.

Trampolines require architecture-specific support, which was added later for ARM than for x86.

On ARM, full support for fentry wasn’t merged until Linux 6.0+.

✅ Fix:
You need to be running Linux kernel version ≥ 6.0 on ARM to use fentry.

🔍 2. kprobe at do_execve() fails with:
libbpf: prog 'kprobe_do_execve': failed to create kprobe 'do_execve+0x0' perf event: No such file or directory

✅ Why this happens:
This error means: the kernel couldn’t find a symbol called do_execve in kallsyms.

Common reasons:
do_execve is inlined in ARM builds

ARM compilers may inline functions more aggressively.

If it’s inlined, there’s no entry point to probe, and thus no kprobe can be attached.

Symbol isn’t exported or visible

Kernel symbols must be visible in /proc/kallsyms (or via kprobe_events).

Use this to check:

grep do_execve /proc/kallsyms