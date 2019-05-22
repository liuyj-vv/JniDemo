package com.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.Map;

public class MainActivity extends AppCompatActivity {
    String TAG = MainActivity.class.getSimpleName();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.btn1).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(getBaseContext(), JniDemo.getString(), Toast.LENGTH_SHORT).show();
            }
        });
        findViewById(R.id.btn2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                JniDemo.setString("=========================================");
            }
        });

        findViewById(R.id.btn3).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                JniDemo.setString1("logcat -c 2>&1");
                try {
                    final Process process = Runtime.getRuntime().exec("ls");


                    final Boolean[] flag = {true};
                    final Thread thread_stdout = new Thread(new Runnable() {
                        @Override
                        public void run() {
                            BufferedReader bufferedReader_stdin = null;
                            BufferedReader bufferedReader_stderr = null;
                            try {
                                bufferedReader_stdin = new BufferedReader(new InputStreamReader(process.getInputStream(), "gbk"));
                                bufferedReader_stderr = new BufferedReader(new InputStreamReader(process.getErrorStream(), "gbk"));
                                String line1 = null;
                                String line2 = null;
                                while (flag[0] ) {
                                    if ((line1 = bufferedReader_stdin.readLine()) != null) {
                                        Log.e(TAG, "LINE["+Thread.currentThread().getStackTrace()[2].getLineNumber()+"]" + " stdout:"+line1);
                                    }
                                    if ((line2 = bufferedReader_stderr.readLine()) != null) {
                                        Log.e(TAG, "LINE["+Thread.currentThread().getStackTrace()[2].getLineNumber()+"]" + " error :"+line2);

                                    }
                                }
                                bufferedReader_stdin.close();
                                bufferedReader_stderr.close();
                            } catch (UnsupportedEncodingException e) {
                                e.printStackTrace();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                    });
                    thread_stdout.start();

                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }
}

