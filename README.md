# Yet Another HMAC Implementation
An implemention of HMAC using SHA-1 I made for learning purposes

I had to make an HMAC implementation for a special platform with limited specs, so OpenSSL wasn't an option.
The teeny-sha1 provided a nice, small program for sha1, which I expanded to create a small program for hmac.

Note: The hmac implementation hasn't been thoroughly tested.

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
I didn't implement sha-1 and instead used the [teeny-sha1 implementation](https://github.com/CTrabant/teeny-sha1/) for the hmac implemented in c.
