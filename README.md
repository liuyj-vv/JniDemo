## 环境
0. Android Studio 版本
> Help-->About
>> Android Studio 3.2

1. 环境支持
>Tools-->SDK Manager-->SDK Tools
>>安装 CMake、LLDB、NDK 

>>>NDK 是什么，英文全称 Native Develop Kit。Android NDK 就是一套工具集合，允许你使用C/C++语言来实现应用程序的部分功能。

>>>JNI，全称为Java Native Interface，即Java本地接口，JNI是Java调用Native 语言的一种特性。
![Alt text](./doc/jni说明.png)

## 生成使用 .h 文件，并实现对应的函数
[添加javac -h 快捷键](./hotkey.md)
0. 进入JniDemo.java(jni的java文件)目录
1. 执行命令 ***javac -h ../jni JniDemo.java***
``` 
javac -h        //命令
jni             //生成的 .h 文件保存的目录(可随意指定)
JniDemo.java    //要处理的java文件
```
2. 将在指定目录下生成 ***./jni/\*.h*** 和在当前目录下生成 *.class（不需要删掉） 文件
3. 在main目录下创建jni目录： 右键(main)-->new-->Folder-->JNI Folder-->Finish 创建ini目录
4. 拷贝 *.h 文件到 jni 目录下
5. 创建 *.c 文件实现对应的函数

[javac执行示例 javac -h ../../../jni JniDemo.java](./doc/javac_commad.png)

## 编译问题
0. 修改模块下的 build.gradle，添加 ***ndk*** 和 ***externalNativeBuild***
```
android {
    compileSdkVersion 28
    defaultConfig {
        applicationId "com.jnidemo"
        minSdkVersion 17
        targetSdkVersion 28
        versionCode 1
        versionName "1.0"
        testInstrumentationRunner "android.support.test.runner.AndroidJUnitRunner"

        ndk {
            moduleName "JNISample"
            abiFilters "armeabi-v7a", "x86"//cpu的类型
        }
    }
    externalNativeBuild {
        cmake {
            version "3.12.0"
        }
        ndkBuild {
            path 'build/intermediates/ndk/debug/Android.mk'
        }
    }

    buildTypes {
        release {
            minifyEnabled false
            proguardFiles getDefaultProguardFile('proguard-android.txt'), 'proguard-rules.pro'
        }
    }
}
```

## 遇到的问题

[0. 新建的工程不能运行的问题](./doc/errorNewActivity.md)

[1. so的编译问题](./doc/errorSoCompile.md)

[2. 找不到Android.mk](./doc/errorNoAndroid.mk.md)
