@echo off
setlocal enabledelayedexpansion

for %%f in (programs\*.c) do (
    set name=%%~nf
    echo Compiling %%f
    gcc "%%f" -o "build\!name!.exe"
)

echo Compiled all to .\build
pause
