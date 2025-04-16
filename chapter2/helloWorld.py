#!/usr/bin/python3  

from bcc import BPF

program = r"""
int hello(void *ctx) {
    int pid = bpf_get_current_pid_tgid() >> 32;
    if (pid % 2 == 0){
        bpf_trace_printk("Hello World!");
    }
    else{
        bpf_trace_printk("Hello Gay!");
    }
    return 0;
}
"""

b = BPF(text=program)
syscall = b.get_syscall_fnname("execve")
b.attach_kprobe(event=syscall, fn_name="hello")

b.trace_print()