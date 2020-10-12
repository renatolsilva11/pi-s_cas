// IMPORTANDO BIBLIOTECAS
import processing.serial.*;
import meter.*;

//VARIAVEIS PARA AS PORTAS SERIAL / TERMOMETRO
Serial port;
Meter termometro;

float umid = 0.00;
float percent = 0.00;
void setup()
{
  
 size(500,400);  // LARGURA, ALTURA
 // printArray(Serial.list()); // PRINTAR PORTAS SERIAL DISPONIVEIS
 port = new Serial(this, "COM3", 9600); // CONEXÃO COM A PORTA DO ARDUINO
  background(0, 0, 0);
 termometro = new Meter(this, 27, 50);
 
 termometro.setTitleFontSize(20);
 termometro.setTitleFontName("Arial bold");
 termometro.setTitle("UMIDADE DO SOLO (%)");
 
 // MUDAR VALORES DA ESCALA
 String[] scaleLabels = {"0","10","20","30","40","50","60","70","80", "90","100"};
 termometro.setScaleLabels(scaleLabels);
 termometro.setScaleFontSize(18);
 termometro.setScaleFontName("Arial bold");
 termometro.setScaleFontColor(color(200, 30, 70));
 
 // VALORES DO TERMOMETRO
 termometro.setDisplayDigitalMeterValue(true);
 
 termometro.setArcColor(color(141, 113, 178));
 termometro.setArcThickness(15);
 termometro.setMaxScaleValue(100);
 termometro.setMinInputSignal(0);
 termometro.setMaxInputSignal(100);
 
 termometro.setNeedleThickness(3);
}

void draw() // EQUIVALE AO LOOP DO ARDUINO
{
  //int valores_um = (int)random(0,100);
  
 if(port.available()>0) {
   String val = port.readString();
   String [] list = split(val, ',');
   umid = float(list[0]);
  percent = ( 100 - ( (umid/1023.00) * 100 ) );
  println("UMIDADE: " + umid + "\n");
  println("PERCENT: " + percent + "% \n");
  
  
  }
  
  // TESTE
  termometro.updateMeter(int(percent));
  delay(800);
}
