#!/usr/bin/python3  
from bcc import BPF
from time import sleep

program = r"""
BPF_HASH(counter_table);

int hello(struct bpf_raw_tracepoint_args *ctx) {
    int call = ctx->args[1];
    u64 uid;
    u64 counter = 0;
    u64 *p;
    uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;
    p = counter_table.lookup(&uid);
    if (p != 0) {
        counter = *p;
    }

    counter ++;
    counter_table.update(&uid, &counter);
    return 0;
    
}


"""

b = BPF(text=program)
b.attach_raw_tracepoint(tp="sys_enter", fn_name="hello")

# Attach to a tracepoint that gets hit for all syscalls 
# b.attach_raw_tracepoint(tp="sys_enter", fn_name="hello")
try:
    while True:
        sleep(1)
except KeyboardInterrupt:
    print("\nSyscall counts by UID:")
    
    for k, v in b['counter_table'].items():
        print(f"UID: {k.value}: {v.value}")
