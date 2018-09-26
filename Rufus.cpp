#include <Stepper.h> // Biblioteca do motor de paço

#define botao_alimentacao 7
//botao para iniciar a contagem
#define botao_parada 6
//botao para parada de emergencia
#define tempo_ativo 20
//alterar essa constante para definir o tempo ativo(em segundos)

const int voltas_do_motor = 200; //definido pelo fabricante do motor
bool click_comporta; // variavel para ativação do botao de alimentao
bool click_emergencia;
unsigned long currentMillis;


Stepper motor_de_passo(voltas_do_motor, 8,10,9,11); //definindo objeto do motor

void setup()
{

    motor_de_passo.setSpeed(60); //velocidade em rpm

    pinMode(botao_alimentacao, INPUT); //inputs de botao
    pinMode(botao_parada, INPUT);

}
void loop()
{
    click_comporta = digitalRead(botao_alimentacao); //liga a comporta
    if(click_comporta == HIGH) {
        abre_comporta(tempo_ativo*1000);
    }


}

//=========================FUNÇÃO DO MOTOR======================
/* Faz com que o motor ative por uma unidade de volta assim liberando a passagem da comida, logo depois retorna a forma incial
entretanto se houver alguma emergencia um botao pode ser pressionado para parar a comporta*/
void abre_comporta(unsigned long int time) {
    currentMillis = millis();
    while(millis() - currentMillis <= time) {
        motor_de_passo.step(voltas_do_motor);
        if((click_emergencia = digitalRead(botao_parada)==HIGH)
                motor_de_passo.step(-voltas_do_motor);
    }
motor_de_passo.step(-voltas_do_motor);

}
