# Yet Another HMAC Implementation
### Description
An implemention of HMAC using SHA-1 I made for the TI-84+ CE or a regular computer, made primarily for learning purposes.

I had to make an HMAC implementation for a special platform with limited specs (TI-84+ CE), so OpenSSL wasn't an option.
The teeny-sha1 provided a nice, small program for sha1, which I expanded to create a small program for hmac.

Note: The hmac implementation hasn't been thoroughly tested. It's also probably slower than the other ones.

Build the c program using the makefile if you're using this on a regular computer.
If you want to run the c program on a TI-84+ CE, use the LLVM based compiler for the CE (TI-Planet has one).

### Build and Run
#### C
```console
$ cd c
$ make
$ ./hmac
0xb34ceac4516ff23a143e61d79dfa7a4fbe5f266
```
#### Python3
```console
$ cd python3
$ ./hmac.py
0xb34ceac4516ff23a143e61d79dfa7a4fbe5f266
```

### Credits
I didn't implement SHA-1 and instead used the [teeny-sha1 implementation](https://github.com/CTrabant/teeny-sha1/) for the c version.
