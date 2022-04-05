# Material
* https://learnopengl.com/

# Part 1
  ## Chp 1~2
  * API specification
    * openGL 자체는 graphics 를 다루기 위한 set of functions 를 정의해둔 문서.
    * Specification 은 각 function 의 input/output, 어떻게 동작해야되는지가 명시되어 있음
    * 라이브러리의 actual implementaion 은 그래픽카드 생산자들이 함
    * 글카의 드라이버를 주기적으로 업데이트하는게 중요한 이유 중 하나임
  * Core-profile v.s. Immediate mode
    * Immediate mode : openGL ver 3.2 까지는 openGL 내부의 동작구조를 매우 많이 추상화하였다고 함. 
  	* Core-profile : openGL ver.3.3 부터는 좀 더 추상화를 덜 하여서, 개발자쪽에서 control할 수 있는 부분이 많아였지만, 그만큼 개발자가 openGL의 동작구조에 대해 알아야 할 게 더 많아졌다캄.
  	* ver.3.3 에 들어서면서 과거의 function 들을 파기deprecate 하였음
  	* ver.3.3 부터는 추가적인 기능추가가 있을뿐, 큰 변화가 없었음
  * Extension
  	* 그래픽카드 제조사(GPU 제조사) 측에서 내놓은 추가적인 기능을 의미.
  	* 특정 GPU에 따라서 지원이 되기도, 안 되기도 하니까 이런걸 주의하면서 사용해야됨
  	* 이러한 Extension들을 사용하는 것에 편의성을 주는게 glew 라이브러리
  	* Extension이 openGL의 나중 버전에서 공식적으로 추가되기도 함
  * State Machine?
  	* openGL은 일종의 state machine 처럼 구동함. function 들이 
  	* state-changing function 과 state-using function으로 나눠
  	* 이런건 직접 써봐야 알아먹을듯
  	* OpenGL context ; opengl state machine의 state 를 의미하는 개념 

  ## Chp 3
  * 필요한 라이브러리 setup
  * GLFW
    * 특정 OS에 맞춘 programming 을 추상화해주는 라이브러리
    * window 를 띄우고, 키보드/마우스를 통한 입력을 제어하는 등의 기능을 동일한 API로 제공
  * GLAD
    * openGL를 쓰려면 Graphic Driver에 구현된 실제 코드에 연결을 해줘야됨.
    * 근데 실제 코드의 위치는 driver별로, OS별로 천차만별
    * 위와 같은 기능을 대신 수행해주는게 GLAD
  * 설치
    * GLAD는 glad.c 와 include directory 에 필요한게 다 있음.
    * GLFW를 쓰기 위해서는 실제로 main.cpp 를 작성해서 빌드하는 환경과 동일한 tool chain 에서 GLFW의 소스코드를 빌드해야됨. 상세한 instruction은 glfw.org 에 있음.
    * VScode 에서 MSVC로 작업을 해보려다가 실패. MSVC만으로 GLFW를 어떻게 빌드해야할지 모르겠음. pre-build binary library 가 VS2019껄로 다운받아서 사용해봤지만 링킹 에러.

  ## Chp 4
  * 색이 있는 윈도우를 띄움

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
