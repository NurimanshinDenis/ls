package com.ls.porthole

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.ls.porthole.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = lsVmUpdateJNI()
    }



    /**
     * A native method that is implemented by the 'porthole' native library,
     * which is packaged with this application.
     */
    external fun lsVmUpdateJNI(): String

    companion object {
        // Used to load the 'porthole' library on application startup.
        init {
            System.loadLibrary("porthole")
        }
    }
}