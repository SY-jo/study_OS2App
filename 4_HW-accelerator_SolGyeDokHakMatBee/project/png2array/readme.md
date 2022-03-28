

# Library version 
* libpng : 1.6.37
* zlib : 1.2.11

# Description
* \<lpng directory>\contrib\examples\pngpixel.c 를 참고하여 만듬
  * 코드 가독성을 위해 error handling 부분을 모두 삭제
  * interlace 가 안 쓰인 png file을 가정. pixel 값으로 변환하는 과정에서 interlace 관련된 부분을 삭제함
* 기능 구현이 가능한지를 테스트하는 용도

# libpng 라이브러리를 윈도우에서 사용하기 위한 절차
  * reference : https://m.blog.naver.com/ifthe1201/222131991813
  * library 의 source code 가 공개되서 배포되는 경우
    * 해당 소스코드를 모두 컴파일러에서 함께 빌드하되, 최종 결과물이 라이브러리 파일이 나오도록 옵션값을 줘야함
		* 최정적으로 라이브러리 파일(.lib, .a 등) 과 해당 라이브러리의 헤더파일(.h) 을 뽑아내야됨
		* 동적라이브러리로 빌드한 경우에는, 해당 파일이 실행파일과 동일한 디렉토리에 위치하도록
		* 또한 실제로 코딩을 진행하는 환경과 라이브러리를 빌드하는 환경을 동일하게 가져가야 에러 걱정이 덜어짐(ex: MSVC를 이용해 png2array를 빌드할 것이라면, 사용하는 라이브러리도 MSVC를 이용해 빌드한 것을 이용)
	* libpng 의 빌드를 위해 zlib 빌드
		* libpng 는 zlib 라이브러리에 dependency 가 있음
		* 때문에 zlib를 우선 static library 로 빌드하고, 해당 파일을 libpng의 빌드에 이용
    * 최종적으로 나온 libpng의 라이브러리 파일과 헤더파일을 이용해 png2array 작성