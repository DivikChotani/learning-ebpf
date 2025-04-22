#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>
#include "hello-tracepoint.h"

int c = 1;
struct {
    __uint(type, BPF_MAP_TYPE_PERF_EVENT_ARRAY);
    __uint(key_size, sizeof(u32));
    __uint(value_size, sizeof(u32));
} output SEC(".maps");

SEC("tracepoint/syscalls/sys_enter_execve")
int kprobe_exec(void *ctx)
{
   c++; 
   bpf_perf_event_output(ctx, &output, BPF_F_CURRENT_CPU,  &c, sizeof(c));
   return 0;
   
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";