#include <LiquidCrystal.h>
#include <Servo.h>

// Definição de constantes
const int pinBotao = 3;
const int servoPosInicial = 0;
const int servoPosPressionado = 75;
const unsigned long intervaloDeEspera = 5000;
const unsigned long intervaloDeLimpeza = 1000;

// Inicialização dos objetos
Servo myServo;
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  lcd.begin(16, 2);
  myServo.attach(9);
  myServo.write(servoPosInicial);
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop() {
  static unsigned long ultimaAtualizacao = 0;
  static bool estadoBotaoAnterior = HIGH;
  bool estadoBotaoAtual = digitalRead(pinBotao);

  // Verifica se o botão foi pressionado
  if (estadoBotaoAtual == LOW && estadoBotaoAnterior == HIGH) {
    myServo.write(servoPosPressionado);
    delay(intervaloDeEspera);
    myServo.write(servoPosInicial);

    // Exibe mensagem no LCD
    exibirMensagemLCD();
  }

  // Atualiza o estado do botão
  estadoBotaoAnterior = estadoBotaoAtual;

  // Limpa o LCD após um intervalo de tempo
  if (millis() - ultimaAtualizacao > intervaloDeLimpeza) {
    lcd.clear();
    ultimaAtualizacao = millis();
  }
}

void exibirMensagemLCD() {
  lcd.clear();
  lcd.home();
  lcd.print("Agua");
  delay(100);
  lcd.print(" Coca");
  delay(100);
  lcd.print(" LOBAO");
  delay(100);
  lcd.setCursor(0, 2);
  lcd.print(" Aperte o botao");
}
 