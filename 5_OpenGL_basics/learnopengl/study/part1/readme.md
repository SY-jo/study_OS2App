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
  * line-by-line 으로 각 GLFW function 이 무엇을 의미하는지 세세하게 설명됨

  ## Chp 5
  * Shdaer 에 대해
        <center> <img src="..\img\1.png"> </center>
    * openGL에서 다뤄지는 data는 3차원 정보를 담고있는 Vertex Data
    * Vertex Data가 Graphics pipeline에 들어가면, 최종적으로 모니터 상의 2D pixel 로 출력됨
    * Graphics pipeline을 구성하는 개별적인 작은 연산 블록들을 "Shader"라고함
    * Shader 중 일부는 configurable 하지만, 아닌 것들도 있음.
    * 다른 shader들은 default operation이 존재하지만, Vertex shader 와 Fragment shader는 필수적으로 코딩해줘야됨
    * Shader는 "openGL Shading Language"(GLSL)이라는 언어로 프로그래밍 됨
    * 각 Shader 의 역할에 대한 설명은 나중에 openGL 좀 써보고나서야 제대로 이해할 수 있을듯
  * Normalized Device Coordinates(NDC)
        <center> <img src="..\img\2.png"> </center>
    * Shader에서 사용하는 좌표계
    * 원점은 정중앙. -1 ~ 1 사이의 실수값을 가짐.
    * 기본적으로 window에서의 좌표는 좌상단을 원점으로 하여, pixel 단위로 크기를 가짐.
    * `glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);`
      * Attribute Pointer를 설정할 때, 4번재 argument가 NDC로 좌표계를 변화할지 여부를 정함
  * 기초적인 Shader 생성, Compile, Link
    ``` c++
     // Shader Object 생성
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    int success;
    char infoLog[512];

    // Compile : GLSL 은 runtime에서 compile됨
    glShaderSource(vertexShader, 1, &vShaderCode, NULL); //vShaderCode : GLSL코드를 담고있는 문자열
    glCompileShader(vertexShader); 
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); //에러처리
    if(!success) 
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // ...Fragment Shader도 동일한 방식으로 compile... 

    // Shader Program : shader들이 모두 연결된 program object
    myProgram = glCreateProgram();
    glAttachShader(myProgram, vertexShader);
    glAttachShader(myProgram, fragmentShader);
    glLinkProgram(myProgram);
    glGetProgramiv(myProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(myProgram, 512, NULL, infoLog);
        std::cout << "ERRPR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }

    // shader program이 완성되면 Shader object는 필요없음.
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    // Rendering loop 안에서
    ...
    glUseProgram(myProgram)
    ...
    ```
  * VBO
        <center> <img src="..\img\3.png"> </center>
    * Vertex Buffer Object
    * vertex data를 담고있는 buffer. GPU의 VRAM에 위치
    ``` cpp
      GLuint VBO; 
        // CPU측에서 VBO를 식별하는 reference 를 담아줄 unsigned int 
      glGenBuffers(1, &VBO); 
        // GPU VRAM에 buffer 생성
      glBindBuffer(GL_ARRAY_BUFFER, VBO); 
        // 생성된 buffer를 openGL context 의 GL_ARRAY_BUFFER에 연동. Binding 이후에 openGL에서 GL_ARRAY_BUFFER에 접근하는 모든 function 은 연결된 VBO memory에 접근하게 됨.
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 
        // GL_ARRAY_BUFFER에 vertices 변수에 있는 데이터를 넣어줌
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); 
        // GL_ARRAY_BUFFER 에 저장된 Vertex data들을 어떻게 해석하여 Vertex Attribute로 사용할건지 정의해주는 작업. 위 예시에서는 position, color
        // 1st argument 0: 어떤 attribute에 대한건지 지정. 해당 attribute가 position인지, color인지는 vertex shader에서 layout (location = 0) in vec3 Pos 가 어떻게 사용되냐에 따라 결정됨 
        // 2nd 3: 1개 attribute를 구성하는 데이터 개수. 위 예시는 x,y,z좌표를 사용했기에 vertex shader에서 in vec3 Pos. 따라서 3개
        // 3rd GL_FLOAT: 데이터 타입
        // 4th GL_FALSE: NDC 로의 normalization 을 해서 vertex shader에 넘겨줄지 여부
        // 5th 6 * sizeof(float): stride. 다음 vertex의 메모리 시작점으로 이동하기 위한 크기
        // 6th (void*)0: VBO 에서 해당 attribute가 위치하는 최초의 base 위치
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 3*sizeof(float)); 
        // color attribute
      glEnableVertexAttribArray(1);


    ```

  * VAO
        <center> <img src="..\img\4.png"> </center>
    ``` cpp
      GLuint VAO;
      glGenVertexArrays(1, &VAO);

      glBindVertexArray(VAO);
    ```
    * Vertex Arrary Object
    * Vertex attributes 에 대한 context를 저장하는 object
    * Vertex attributes에 연관된 function call이 있으면, 가장 최근에 bind된 VAO에서 해당 context가 read/write됨
    * glVertexAttribPointer() 를 이용해 configuration 한 정보를 저장해주기에, Vertex Data 마다 달리해야하는 configuration 을 한 번만 설정해두고, 나중에는 VAO에서 필요한 설정을 가져다 쓰는 식
    * 현재 예제로는 VAO 1개, VBO 1개 씩만 사용해서 이러한 array object가 왜 필요한지 체감을 못 했음. 나중에 추가 서술 필요
  * VEO
    * Vertex Element Object
    * Vertex Data의 여러 꼭지점 중에 곂치는 부분이 있는 경우에 불필요한 메모리 낭비를 막기 위한 수단
      * ex : 삼각형 2개를 표현해야하는 상황에서 두 삼각형이 꼭지점 1개를 공유한다면?
        * VBO만을 사용하면 총 6개의 vertices
        * VEO를 이용하면 VBO가 5개의 vertices 만을 저장하도록 할 수 있음
    * VEO를 생성하고, 꼭지점에 대한 index 정보를 VEO에 저장.
    * glDrawElement*() 로 시작하는 function을 통해 draw

  ## chp 6 : GLSL
  * syntax
    ``` GLSL
        #version version_number
        in type in_variable_name;
        in type in_variable_name;
        out type out_variable_name;
        uniform type uniform_name;
        void main()
        {
        // process input(s) and do some weird graphics stuff
        ...
        // output processed stuff to output variable
        out_variable_name = weird_stuff_we_processed;
        }
    ```
  * data type
    * int, float, double, uint, bool 같은 data type
    * vectors, matrices 와 같은 container
  * vec
    * vec3, vec4, ivec3, uvec4 등 다양한 type 지원
        * prefix : data type. 기본은 float. i : int / d : double / u : unsigned int / b : boolean / ...
        * suffix : 개수
    * indexing -> Swizzling
      * 순서대로 .x, .y, .z, .w 가 각각 1~4번째 element를 의미
      * 다양한 표현 지원
        ``` GLSL
        vec2 someVec;
        vec4 differentVec = someVec.xyxx;
        vec3 anotherVec = differentVec.zyw;
        vec4 otherVec = someVec.xxxx + anotherVec.yxzy;
        ```
  * in, out, uniform
    * in : shader 로 들어오는 input
    * out : shader 에서 나가는 output 
    * uniform : 모든 shader에서 global variable처럼 사용할 수 있는...something
  * uniform
    * CPU측에서 pipeline 안의 parameter 를 runtime 중에 조절할 수 있는 수단
      ``` GLSL
        GLint uniform_loc = glGetUniformLocation(shaderProgram, "uniform_name");
        glUniform4f(uniform_loc, 0.0f, greenValue, 0.0f, 1.0f);
      ```

  ## Chp 7 : Texture
  * Texture
    * texture란
    * texture coordinate
    * sampling
  * Config
    * Wrapping
    * Minifying/Magnifying Filtering
  * Texture Object
    * 생성
    * Fragment Shader에게 전달하는 법
    * Texture unit

  ## Chp 8 : Transformations
  * vector, matrix basic
  * Transform Matrix
    * translation
    * scail
    * rotations
  * glm library
    * header only library
    * matrix class 나 다른 수학연산을 GLSL 포맷에서 사용하기 좋게 제공
  
  