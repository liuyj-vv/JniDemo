## jni 环境
0. Android Studio 版本
> Android Studio 3.2

1. 环境支持
>Tools-->SDK Manager-->SDK Tools
>>安装 CMake、LLDB、NDK 

## 生成使用 .h 文件，并实现对应的函数
0. 进入JniDemo.java(jni的java文件)目录
1. 执行命令 ***javac -h -jni JniDemo.java***
2. 将在当前目录下生成 ***./-jni/\*.h*** 和 *.class 文件
3. 在main目录下创建jni目录： 右键(main)-->new-->Folder-->JNI Folder-->Finish 创建ini目录
4. 拷贝 *.h 文件到 jni 目录下
5. 创建 *.c 文件实现对应的函数

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
