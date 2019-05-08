## jni 环境
0. Android Studio 版本
> Android Studio 3.2
! [Alt text](./readme/AdnroidStudio.png)

1. 环境支持
>Tools-->SDK Manager-->SDK Tools
>>安装 CMake、LLDB、NDK 

## 代码运行
0. 新建一个空的工程
1. 创建一个Basic Activity
2. 使新建的 Activity 能够正常编译运行
> AndroidManifest.xml 添加
```
        <activity android:name=".MainActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN"></action>
                <category android:name="android.intent.category.LAUNCHER"></category>
            </intent-filter>
        </activity>
```

## 生成使用 .h 文件，并实现对应的函数
0. 进入JniDemo.java(jni的java文件)目录
1. 执行命令 ***javac -h -jni JniDemo.java***
2. 将在当前目录下生成 ***./-jni/\*.h*** 和 *.class 文件
3. 在main目录下创建jni目录： 右键(main)-->new-->Folder-->JNI Folder-->Finish 创建ini目录
4. 拷贝 *.h 文件到 jni 目录下
5. 创建 *.c 文件实现对应的函数

## 编译问题
0. 修改模块下的 build.gradle，添加 ****ndk*** 和 ***externalNativeBuild***
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
