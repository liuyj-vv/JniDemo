## test

1. NDK 安装
>File-->Project Structure-->SDK Location

![Alt text](./readme/ndk1.png)

![Alt text](./readme/ndk2.png)

2. 新建的 activity 能够正常编译运行
> AndroidManifest.xml 添加
```
        <activity android:name=".MainActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN"></action>
                <category android:name="android.intent.category.LAUNCHER"></category>
            </intent-filter>
        </activity>
```