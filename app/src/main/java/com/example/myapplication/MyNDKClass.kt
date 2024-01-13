package com.example.myapplication
object MyNDKClass {
    init {
        System.loadLibrary("myapplication")
    }
    external fun callKotlinFunction(): String
}