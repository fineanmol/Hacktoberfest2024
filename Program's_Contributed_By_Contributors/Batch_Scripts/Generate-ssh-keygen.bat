@echo off
title SSH-Key Generator
color 1F
mode con: cols=75 lines=35

echo -----------------------------------------------------------
echo Welcome to SSH-Key Generator for Windows - By: Philip Mello   
echo -------------------------v1.1------------------------------   

set /p input=Type your email:

ssh-keygen -o -t rsa -C %input%

echo ssh-key generated successfully!
pause