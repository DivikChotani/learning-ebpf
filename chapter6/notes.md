Changing this to <= means and c could have value beyond the bounds of the
data.message array
if (c <= sizeof(data.message)) {}
this would fail because of potential out of bounds

This is a loop that will pass the verifier
   for (int i=0; i < 10; i++) {
      bpf_printk("Looping %d", i);
   }

   This is a loop that will fail the verifier
   for (int i=0; i < c; i++) {
      bpf_printk("Looping %d", i);
   }

This would fail because loop size must be known at compile time