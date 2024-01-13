package com.example.myapplication

public  class MyKotlinClass {
    fun getHelloWorldString(): String {
        return "Yes Kotlin function called !!"
    }
}
object MyNDKClass {
    init {
        System.loadLibrary("myapplication")
    }
    external fun callKotlinFunction(): String
}
