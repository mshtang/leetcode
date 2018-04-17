# MinGW-w64 + VSCode Settings

Inspired by [here](https://zhuanlan.zhihu.com/p/35178331)

## Step 1: setup `c_cpp_properties.json` for IntelliSense to be working

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceRoot}",
                "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.3.0/include/c++",
                "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.3.0/include/c++/x86_64-w64-mingw32",
                "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.3.0/include/c++/backward",
                "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.3.0/include",
                "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.3.0/include/c++/tr1",
                "C:/Program Files/mingw-w64/x86_64/mingw64/x86_64-w64-mingw32/include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "__GNUC__=7",
                "__cdecl=__attribute__((__cdecl__))"
            ],
            "intelliSenseMode": "clang-x64",
            "browse": {
                "path": [
                    "${workspaceRoot}",
                    "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.230/include/c++",
                    "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.230/include/c++/x86_64-w64-mingw32",
                    "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.230/include/c++/backward",
                    "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.230/include",
                    "C:/Program Files/mingw-w64/x86_64/mingw64/lib/gcc/x86_64-w64-mingw32/7.230/include/c++/tr1",
                    "C:/Program Files/mingw-w64/x86_64/mingw64/x86_64-w64-mingw32/include"
                ]
            },
            "limitSymbolsToIncludedHeaders": true,
            "databaseFilename": "",
            "cStandard": "c11",
            "cppStandard": "c++17"
        }
    ],
    "version": 3
}
```
## Step2: setup `tasks.json` to build and run

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build",
            "command": "g++",
            "args": [
                "-g",
                "-Wall",
                "-std=c++11",
                "-lm",
                "${file}",
                "-o"
            ],
            "windows": {
                "args": [
                    "${fileDirname}/${fileBasenameNoExtension}.exe"
                ]
            },
            "linux": {
                "args": [
                    "${fileDirname}/${fileBasenameNoExtension}.o"
                ]
            },
            "osx": {
                "args": [
                    "${fileDirname}/${fileBasenameNoExtension}.o"
                ]
            },
            "presentation": {
                "reveal": "always",
                "echo": false,
                "focus": true
            },
            "problemMatcher": {
                "owner": "cpp",
                "fileLocation": "absolute",
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            },
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "label": "Run",
            "type": "shell",
            "dependsOn": "Build",
            "command": "${fileDirname}/${fileBasenameNoExtension}.o",
            "windows": {
                "command": "${fileDirname}/${fileBasenameNoExtension}.exe"
            },
            "args": [],
            "presentation": {
                "reveal": "always",
                "focus": true
            },
            "problemMatcher": [],
            "group": {
                "kind": "test",
                "isDefault": true
            }
        }
    ]
}
```
> ctrl+shift+B: to build
> ctrl+shift+P: from command palette choose Run Task

## Step 3: setup `launch.json` to debug

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ Launch (GDB)",
            "type": "cppdbg",
            "request": "launch",
            "targetArchitecture": "x86",
            "program": "${workspaceRoot}\\${fileBasename}.exe",
            "miDebuggerPath": "C:\\Program Files\\mingw-w64\\x86_64\\mingw64\\bin\\gdb.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceRoot}",
            "externalConsole": true,
            "preLaunchTask": "g++"
        }
    ]
}