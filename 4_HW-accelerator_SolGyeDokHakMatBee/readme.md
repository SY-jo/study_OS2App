저작권에 문제가 되지 않는 선에서 요약정리

# 강의
## lab 1
* 환경세팅 및 DIP 스위치, 택트 스위치, LED 를 control하는 예제 코드를 실행해봄

# 따로 찾아본거
## Vivado 관련
* 용어
  * Constraint : FPGA pin mapping 을 수행하는 TCL 코드들의 묶음. HAL 역할을 해줌 (physical). 그밖에도 logical constraints, timing constraints를 지정하는게 가능하다캄 
  * Synthesis : Verilog 나 VHDL 의 RTL(Resister-Transfer Level)의 코드를 gate-level representation (디지털 회로 블록)으로 변화하는 과정. 이렇게 해서 netlist 가 만들어짐
  * Implementation : Place & Route. 실제로 FPGA에 배치하고 배선하는 과정..?
* 왜 module 코드와 test bench 코드가 따로 필요한가?
  * test bench 는 만들어진 H/W module 을 기능을 테스트 하기 위한 simulation 을 정의한 것
  * 원하는 clock, input signal 등을 설정
* 