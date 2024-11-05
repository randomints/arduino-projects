#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

String line0 = "Click on something!";
String line1;
String line2;
String line3;


int vacc = 11;
int mito = 2;
int chloro = 10;
int nuc = 9;
int cyto = 12;
int choose = 6;
int knob = A0;
int btn = 7;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  Serial.begin(9600);
  
  pinMode(knob, INPUT);

  pinMode(btn, INPUT);
  digitalWrite(btn, HIGH);

  pinMode(vacc, INPUT);
  digitalWrite(vacc, HIGH);

  pinMode(mito, INPUT);
  digitalWrite(mito, HIGH);

  pinMode(chloro, INPUT);
  digitalWrite(chloro, HIGH);

  pinMode(nuc, INPUT);
  digitalWrite(nuc, HIGH);

  pinMode(cyto, INPUT);
  digitalWrite(cyto, HIGH);

  pinMode(choose, INPUT);
  digitalWrite(choose, HIGH);
  

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  lcd.write("               ");

  lcd.setCursor(0, 0);

  lcd.print("Click on something!");
}

void loop()
{
  int mitoVal = digitalRead(mito);
  int vaccVal = digitalRead(vacc);
  int chloroVal = digitalRead(chloro);
  int nucVal = digitalRead(nuc);
  int cytoVal = digitalRead(cyto);
  int chooseVal = digitalRead(choose);
  int btnVal = digitalRead(btn);
  int knobVal = analogRead(knob);

  if (vaccVal == 0) {
    line0 = "Name: Vacuole";
    line1 = "-filled with cell sa";
    line2 = "p, a liquid containi";
    line3 = "ng salt and sugar.";
    write();
  }

  if (mitoVal == 0) {
    line0 = "Name: Mitochondria";
    line1 = "-creates energy for";
    line2 = "the cell with food";
    line3 = "from chloroplasts";

    write();

  }

  if (chloroVal == 0) {
    line0 = "Name: Chloroplast";
    line1 = "-creates food for";
    line2 = "the cell through";
    line3 = "photosyntheis";

    write();
  }

  if (nucVal == 0) {
    line0 = "Name: Nucleus";
    line1 = "-controles the";
    line2 = "cell and contains";
    line3 = "genetic information";

    write();

  }

  if (cytoVal == 0) {
    line0 = "Name: Cytoplasm";
    line1 = "-a jelly inside the";
    line2 = "cell and where chemi";
    line3 = "cal reactions happen";

    write();

  }

  if (chooseVal == 0) {
    line0 = "Choose:";
    line1 = "Cell Wall";
    line2 = "Cell Membrane";
    line3 = "reclick to refresh";

    if (knobVal > 508) {
      line0 = "Choose:";
      line1 = "Cell Wall";
      line2 = "> Cell Membrane";
      line3 = "reclick to refresh";

      write();
    }

    if (knobVal < 509) {
      line0 = "Choose:";
      line1 = "> Cell Wall";
      line2 = "Cell Membrane";
      line3 = "reclick to refresh";

      write();
    }

    if (knobVal > 508 && btnVal == 0) {
      line0 = "Name: Cell Wall";
      line1 = "-stiff outer layer";
      line2 = "that gives the cell";
      line3 = "structure";

      write();
    }

    if (knobVal < 509 && btnVal == 0) {
      line0 = "Name: Cell Membrane";
      line1 = "-a thin skin around";
      line2 = "the cell that lets";
      line3 = "things in and out";

      write();
    }

    write();
  }


  
  lcd.setCursor(0,0);

  
}

void write() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line0);

  lcd.setCursor(0, 1);
  lcd.print(line1);

  lcd.setCursor(0, 2);
  lcd.print(line2);

  lcd.setCursor(0, 3);
  lcd.print(line3);
}
