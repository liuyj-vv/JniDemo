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