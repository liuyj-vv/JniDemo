package com.jnidemo;

public class JniDemo {
    static {
        System.loadLibrary("JNISample");
    }
    public native String test();
}
