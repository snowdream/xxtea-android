# XXTEA 加密算法的 C 实现 (JNI 版本)

[![License](https://img.shields.io/github/license/xxtea/xxtea-java.svg)](http://opensource.org/licenses/MIT)

## 简介

XXTEA 是一个快速安全的加密算法。本项目是 XXTEA 加密算法的 C 实现的JNI封装版本。

它不同于原始的 XXTEA 加密算法。它是针对 byte[] 类型数据进行加密的，而不是针对 32 位整型数组。同样，密钥也是 byte[]。

为了用户使用方便，除了提供对 byte[] 进行加解密的 API 之外，还提供了一些辅助方法来处理字符串和 Base64 编码。

## 使用

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
