  /////Definição dos pinos/////o programa q ta certo, ajuste so no ki e kd
  int L = 12; //Pino do sensor esquerdo
  int C = 4; //Pino do sensor central
  int R = 2; //Pino do sensor direito
  int ENA = 3; // Pino pra PWM
  int IN1 = 5; // Pinos pra controlar o sentido de rotação do motor
  int IN2 = 6;
  int IN3 = 9;
  int IN4 = 10;
  int ENB = 11; // Pino pra PWM
  ////////////////////////////

  ///Declaração das Variáveis////
  int V = 180; // Valor da equação para achar o setpoint
  int constante = 110; //Constante usada para definir a velocidade dos motores
  int setPoint = 200; // Velocidade ideal dos motores
  int motorA; //Variável responsável pela velocidade dos motores
  int motorB;
  float kp = 2 , ki = 0.0025, kd = 110; //Variáveis de controle Proporcional, Integrativo e Derivativo
  //Pista 1(U): kp=2,ki=0.0015,kd=110;
  //Pista 2(W): kp=2,ki=0.0015,kd=110;
  //Pista 3(H): kp=,ki=0.00,kd=
  int erro; // Variável do erro
  int Va; //Valor anterior da equação
  int t = 0, ta = 0, dt = 0; //Variáveis para obter o tempo, tempo anterior e diferença entre os tempos
  float P,I,D; //Variáveis que recebem os calculos dos controladores
///////////////////////////////////////

void setup() {

 pinMode(L, INPUT);
 pinMode(C, INPUT);
 pinMode(R, INPUT);
 pinMode(ENA, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(ENB, OUTPUT);

 digitalWrite(ENA, LOW);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 digitalWrite(ENB, LOW);

 //Serial.begin(9600);
 //Serial.println("Setup feito.");
}

void loop() {
  ta = t;
  t = millis();
  dt = t - ta;
  int r = digitalRead(L);
  int c = digitalRead(C);
  int l = digitalRead(R);
  
//Inversão dos dados////
  if(l == 1){
    l = 0;
  } else {
    l = 1;
  }

  if(c == 1){
    c = 0;
  } else{
    c = 1;
  }

  if(r == 1){
    r = 0;
  } else {
    r = 1;
  }
//////////////////////////////////
  Va = V;
///Equação/////
  if((l+r+c)!=0){
    
   V = (300*l + 200*c + 100*r)/(l+c+r);
  }
////////////////    

  erro = setPoint - V; //Calculo do erro

  P = erro*kp; //Controlador Proporcional
  I+= erro*dt*ki; //Controlador Integrativo
  D = (kd*(V - Va))/dt; //Controlador Derivativo

  motorA = constante + (P + I + D); //Calculo para a velocidade dos motores
  motorB = constante - (P + I + D);

///Comandos////
  if(motorA > 220){
    motorA = 220;
  }

  if(motorB < -170){
    motorB = -170;
  }
  
  if(motorA < -170){
    motorA = -170;
  }

  if(motorB > 200){
    motorB = 200;
  }
  if (motorA>0 && motorB>0)
  frente(motorA,motorB);
  if((motorA<0) && (motorB>0)){
    esquerda(-motorA,motorB);
    
  } 
  if((motorA>0) && (motorB<0)){
    direita(motorA,-motorB);
    
  }
  
}

////Funções/////
void frente(int a, int b){
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);

  analogWrite(ENA, a);
  analogWrite(ENB, b);
}

void esquerda(int a, int b){
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);

  analogWrite(ENA, a+70);//+70
  analogWrite(ENB, b);//-20
}

void direita(int a, int b){

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);

  analogWrite(ENA, a);//-20
  analogWrite(ENB, b+70);//+50
 }
