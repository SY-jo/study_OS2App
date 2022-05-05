# Material
* https://learnopengl.com/

# Index
  ## part 1
  * chp 1-2 : openGL에 대한 기초적인 지식
  * chp 3 : glfw, glad library setup
  * chp 4 : window 생성
  * chp 5 : VBO, VAO, VEO, shader -> Hello Triangle
  * chp 6 : GLSL. Shader class를 만들어서 코드 간소화
  * chp 7 : Texture 에 대한 기초

# Trouble Shooting
  * MinGW 사용시 링크 에러
    * Error Log
        ``` 
            D:\J\3_utility\OpenSourceLibraries\lib/libglfw3.a(win32_monitor.c.obj):win32_monitor.c:(.text+0x12c): undefined reference to `CreateDCW@16'
            D:\J\3_utility\OpenSourceLibraries\lib/libglfw3.a(win32_monitor.c.obj):win32_monitor.c:(.text+0x165): undefined reference to `GetDeviceCaps@8'
            D:\J\3_utility\OpenSourceLibraries\lib/libglfw3.a(win32_monitor.c.obj):win32_monitor.c:(.text+0x17e): undefined reference to `GetDeviceCaps@8'
            D:\J\3_utility\OpenSourceLibraries\lib/libglfw3.a(win32_monitor.c.obj):win32_monitor.c:(.text+0x1cf): undefined reference to `GetDeviceCaps@8'
            D:\J\3_utility\OpenSourceLibraries\lib/libglfw3.a(win32_monitor.c.obj):win32_monitor.c:(.text+0x24f): undefined reference to `GetDeviceCaps@8'
            D:\J\3_utility\OpenSourceLibraries\lib/libglfw3.a(win32_monitor.c.obj):win32_monitor.c:(.text+0x294): undefined reference to `DeleteDC@4'
            D:\J\3_utility\OpenSourceLibraries\lib/libglfw3.a(win32_monitor.c.obj):win32_monitor.c:(.text+0xa69): undefined reference to `GetDeviceCaps@8'
        ```
    * 원인
      * CreatDCW, GetDeviceCaps 등의 function이 정의된 gdi32.a 라이브러리가 linking 되야함
    * 해결
      * vscode 에서 build task 를 아래와 같이 수정
      ``` json
         {
              "label": "g++ build for openGL",
              "command": "g++",
              "args": [
                  "${fileDirname}\\*.cpp",
                  "${fileDirname}\\*.c",
                  "-g",
                  "-I",
                  "D:\\J\\3_utility\\OpenSourceLibraries\\head",
                  "-L",
                  "D:\\J\\3_utility\\OpenSourceLibraries\\lib",
                  "-lopengl32",
                  "-lglfw3",
                  "-lgdi32",
                  "-o",
                  "${fileDirname}\\${fileBasenameNoExtension}.exe"
              ],
              "group": {
                  "kind": "build",
                  "isDefault": true
              },
              "problemMatcher": [
                  "$gcc"
              ]
          },
      ```
