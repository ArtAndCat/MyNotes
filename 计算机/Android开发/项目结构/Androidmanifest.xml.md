#Android #编程 #xml 

第一运行的文件
```xml
<?xml version='1.0' encoding='utf-8'?>
<manifest
    xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.artwork.appcs">
    
    <application
        android:icon="@drawable/ic_launcher"
        android:label="@string/app_name"
        android:theme="@style/AppTheme"
        android:resizeableActivity="true">
        
        <activity
            android:name=".MainActivity"
            android:label="随便写几个字"
            android:exported="true"
            android:textColor="#000000">
            
            <intent-filter><!-- 第一运行文件 -->
                <action android:name="android.intent.action.MAIN"/>
                
                <category android:name="android.intent.category.LAUNCHER"/>
            </intent-filter>
        </activity>
        <meta-data 
            android:name="android.max_aspect"
            android:value="4.0"/> 
            <!-- 下面这行和注册有关 类似于“先声明这个类然后再进行初始化” -->
        <activity android:name=".secondActivity"/>
    </application>
</manifest>
```