package com.jnidemo;

public class JniDemo {
    static {
        System.loadLibrary("JNISample");
    }
    public static native String getString();
    public static native boolean setString(String string);

}
