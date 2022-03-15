*저작권에 문제가 되지 않는 선에서 요약정리한 intro만 보관

*실습코드가 담겨있는 디렉토리는 로컬에서만 저장되고 원격으로 push 안 되도록 설정

*세세한 내용은 원노트에 따로 정리

# 강의요약
* lab 1
  * 환경세팅 및 DIP 스위치, 택트 스위치, LED 를 control하는 예제 코드를 실행해봄
* lab 2
  * FPGA 에 대해서
  * FPGA 의 아키텍쳐 변화
  * CLB, IOB, Interconnect + DSP, PLL 등에 대해 개념
* lab 3
  * Xilinx 제품군 소개
* lab 4 
  * host PC - target Zynq PS 사이의 serial communication 을 통해 "Hello World"
  * Vivado와 Vitis 를 사용하는 과정을 실습
* lab 5
	* Custom IP 사용법
  * Reports Utilization 을 통해 Implementation 된 디자인이 FPGA 리소스를 얼마나 썼는지 확인
* lab 6~8
  * Xilinx 에서 제공하는 AXI IP template 사용법
  * ILA IP 를 사용하여 Runtime에서 FPGA 내부 signal을 관찰하는 법
* lab 9~10
  * lab 4~8 까지의 내용을 종합하여, PC---(UART)---PS---(AXI4-Lite)---PL에 위치하는 controller(Blinking LED, FSM) 를 제어하는 실습
* lab 11~13
  * BRAM I/F controller 가 포함된 IP를 가지고, 메모리에 Read/Write 해보기
* lab 14~16
  * PS로부터 BRAM0 에 데이터를 입력 받고, BRAM1 에 옮기고, BRAM1에서 PS로 데이터 출력
* lab 17~20
	* 이전 lab의 Data Mover에 Multiplier module 을 추가하여 곱셈연산을 수행하도록
  * 1byte x 1byte 연산을 동시에 2번 수행할 수 있는 병렬연산기(H/W 가속기)를 간단히 만들어 실습
* lab 21~22
  * Fully connected layer 의 inference 구현
  * 이전 lab의 모델에서 BRAM0, BRAM1 을 Input node, weight node로 사용하고, 만들어둔 multiplier 모델을 이용해 곱셈 및 덧셈 연산을 해서 AXI4-lite control의 register에 최종 결과를 저장



# 따로 찾아본거
## Vivado 관련
* 용어
  * Constraint : FPGA pin mapping 을 수행하는 TCL 코드들의 묶음. HAL 역할을 해줌 (physical). 그밖에도 logical constraints, timing constraints를 지정하는게 가능하다캄 
  * Synthesis : Verilog 나 VHDL 의 RTL(Resister-Transfer Level)의 코드를 gate-level representation (디지털 회로 블록)으로 변화하는 과정. 이렇게 해서 netlist 가 만들어짐
  * Implementation : Place & Route. 실제로 FPGA에 배치하고 배선하는 과정..?
* 왜 module 코드와 test bench 코드가 따로 필요한가?
  * test bench 는 만들어진 H/W module 을 기능을 테스트 하기 위한 simulation 을 정의한 것
  * 원하는 clock, input signal 등을 설정
  
# History
  * ~22/03/15 : Vivado + Vitis 를 같이 사용해서 PL단에 만들어진 모듈을 사용하는 방법을 익히는데 중점을 두고 학습. Verilog를 써서 직접 모델을 만들어보는건 여름에 Verilog 강의를 듣고나서 진행 