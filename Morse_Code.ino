// Map each character with its sequence
String letters[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." }; // A-Z or a-z
int dot_Unit = 300; // for delay
// map each number with its sequence
String numbers[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." }; // 0-9

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
 
void loop() {
  
  if(Serial.available()) // check serial monitor 
  {
    char ch = Serial.read(); // read character
    if(ch != 10) // check if it's null
    {
      if((ch >= 'A'&& ch <= 'Z')) // check if its a valid character between A & Z
      {
        Serial.print(letters[ch-'A'] + " "); // access character sequence and print it
        generate(letters[ch-'A']); // generate the sequence in the arduino
      }
      else if(ch>='a'&&ch<='z') // chcck if its a valid character between a & z
      {
        generate(letters[ch-'a']); // generate the sequence in the arduino
      }
      else if(ch>='0'&&ch<='9') // check if its a number between 0 & 9
      {
        generate(numbers[ch-'0']); // generate the sequence in the arduino
      }
      else if(ch==' ') // check if its space
      {
        delay(dot_Unit*7); // delay for seven time units long
      }
    }
  }
}
// function to loop though the sequence and make flashes in the arduino kit
void generate(String s)
{
  for(int i=0;i<s.length();i++)
  {
    flash(s.charAt(i));
  }
  delay(dot_Unit*3); // between each character sequence delay for three time units long
}
// function to flash dots and dashes
void flash(char dotOrDash)
{
  digitalWrite(13,HIGH);
  if(dotOrDash=='.')
  {
    delay(dot_Unit);
  }
  else
  {
    delay(dot_Unit*3);
  }
  digitalWrite(13,LOW);
  delay(dot_Unit);
  
}
