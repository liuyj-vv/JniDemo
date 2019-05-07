## 问题
```
Error: Your project contains C++ files but it is not using a supported native build system.
Consider using CMake or ndk-build integration. For more information, go to:
 https://d.android.com/r/studio-ui/add-native-code.html
Alternatively, you can use the experimental plugin:
 https://developer.android.com/r/tools/experimental-plugin.html
 
错误：您的项目包含C ++文件，但它没有使用受支持的本机构建系统。
考虑使用CMake或ndk-build集成。 有关更多信息，请访问：
 https://d.android.com/r/studio-ui/add-native-code.html
或者，您可以使用实验插件：
 https://developer.android.com/r/tools/experimental-plugin.html
 ```
 
## 尝试一
> gradle.properties 添加
>>android.useDeprecatedNdk=true
 