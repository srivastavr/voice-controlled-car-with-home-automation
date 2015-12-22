//Coded By: Angelo Casimiro (4/27/14)
//Voice Activated Arduino (Bluetooth + Android)
//Feel free to modify it but remember to give credit
 
String voice;
int 
led1 = 2, //Connect LED 1 To Pin #2 
led2 = 3, //Connect LED 2 To Pin #3 
led3 = 4, //Connect LED 3 To Pin #4 
led4 = 5, //Connect LED 4 To Pin #5 
led5 = 6, //Connect LED 5 To Pin #6 
led6 = 7;  


//--------------------------Call A Function-------------------------------//  

void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
     //digitalWrite(led5, LOW);
}

void alloff1() { 
     digitalWrite(led5, LOW);
     digitalWrite(led5, LOW);
}

     
//-----------------------------------------------------------------------//  
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT); 
}


//-----------------------------------------------------------------------//  
void loop() {
  
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to 
  
  char c = Serial.read(); //Conduct a serial read
   //Exit the loop when the # is detected after the word  
  voice += c; //Shorthand for voice = voice + c
  if (c == '#') {break;}
  } 
  int i = 1;
  if (voice.length() > 0) {
    Serial.println(voice);
    while(i < voice.length()){
    if(voice == "*tv on#"){
     digitalWrite(led5,HIGH);
     voice="";
     break;
    }
     else if(voice == "*tv of#" || voice == "*tv off#"){
     digitalWrite(led5,LOW);
     voice="";
     break;
    }
    else if(voice == "*fan on#"){
     digitalWrite(led6,HIGH);
     voice="";
     break;
    }
     else if(voice == "*fan of#" || voice == "*fan off#"){
     digitalWrite(led6,LOW);
     voice="";
     break;
     
    }
     else if(voice == "*all of#" || voice == "*all off#"){
       digitalWrite(led5,LOW);
       digitalWrite(led6,LOW);
       voice="";
       break;
     }
    else if(voice[i] == 'b' && voice[i+1] == 'a') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      delay(2000);
      i = i+5;
      alloff();
     
    } else if(voice[i] == 'g' && voice[i+1] == 'o') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(2000);
      i = i+3;
       alloff();
    } else if(voice[i] == 'r' && voice[i+1] == 'i') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      delay(250);
      i = i+6;
       alloff();
    } else if(voice[i] == 'l' && voice[i+1] == 'e') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(250);
      i = i+5;
       alloff();
    } else break;
     
      delay(200);
    }
    
    
    voice="";
 }

} 
