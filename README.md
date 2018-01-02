# xxtea-android

[![License](https://img.shields.io/github/license/xxtea/xxtea-java.svg)](http://opensource.org/licenses/MIT)

## Introduction

XXTEA is a fast and secure encryption algorithm. This is a XXTEA library for C with JNI.

It is different from the original XXTEA encryption algorithm. It encrypts and decrypts byte[] instead of 32bit integer array, and the key is also the byte[].

In addition to providing the API of byte[] encryption and decryption, it also provides some methods to handle string and Base64 encode.

## Usage

```java
package org.xxtea.test;

import org.xxtea.XXTEA;

public class Main {
    public static void main(String[] args) {
              String text = "Hello World! 你好，中国！";
              String ciphertext = XXTEA.encrypt(text);
              String plaintext = XXTEA.decrypt(ciphertext);
              
              assert (text.equals(plaintext));
    }
}
```
