package com.github.snowdream.security.encrypt.xxtea;

/**
 * Created by snowdream on 2017/12/27.
 */

public final class XXTEA {
    /**
     * encrypt the plaintext
     *
     * @param plaintext
     * @return
     */
    public static native String encrypt(String plaintext);

    /**
     * decrypt the ciphertext
     *
     * @param ciphertext
     * @return
     */
    public static native String decrypt(String ciphertext);
}
