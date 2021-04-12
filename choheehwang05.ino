#include <IRremote.h> // 라이브러리명
// Pins 정의, 전역변수 설정
int blue = 2;
int green = 3;
int yellow = 4;
int red = 5;
int RECV_PIN = 11; // 적외선 수신기에서 신호를 받는 핀
// IR library 객체
IRrecv irrecv(RECV_PIN);
decode_results results; // IR 신호 복호화, 10진수를 아스키코드로 변환하는 것과 비슷한 역할

void setup() {
  // 최초 1회만 실행
  // GPIO 핀모드 설정
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  // 시리얼 모니터 출력 설정
  Serial.begin(9600);
  Serial.println("IR Input Enabled");
  irrecv.enableIRIn();
  Serial.println("IR Input Starting");
}

void loop() {
  // 무한반복 실행
  if(irrecv.decode(&results)) {// decode = 수신값 존재시 true 반환하는 함수
    unsigned int value = results.value;
    Serial.println(value); // 적외선 수신기로 받은 값 출력
    switch(value) {
      case 34935: // 리모콘 2번
        digitalWrite(blue, HIGH);
        delay(500); // 딜레이 0.5초
        digitalWrite(blue, LOW);
        break;
      case 18615: // 리모콘 3번
        digitalWrite(green, HIGH);
        delay(500);
        digitalWrite(green, LOW);
        break;
      case 10455: // 리모콘 4번
        digitalWrite(yellow, HIGH);
        delay(500);
        digitalWrite(yellow, LOW);
        break;
      case 43095: // 리모콘 5번
        digitalWrite(red, HIGH);
        delay(500);
        digitalWrite(red, LOW);
        break;
    } // switch문 end
    irrecv.resume(); // 다음 수신값 받기
  }
}
