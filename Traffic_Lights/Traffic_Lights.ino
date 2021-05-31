/*2 way traffic light program
created by Zabil on 31 May 2021
program uses dfa to move to toggle
different lights
*/

const short int side_1_red = 2, side_1_yellow = 3, side_1_green = 4, side_1_switch = 5;
const short int side_2_red = 8, side_2_yellow = 9, side_2_green = 10, side_2_switch = 11; 
const short int pedest_red = 6, pedest_green = 12;
const short int tick_rate = 10;       //10ms
int previous = 0, current = 0;
int state = 0, time = 0;
bool switch_1_pressed = 0, switch_2_pressed = 0;

/*
state 0: starting state
state 1: AY
state 2: AG
state 3: AYa
state 4: BY
state 5: BG
state 6: BYa
state 7: PG
*/

void setup() {
    pinMode(side_1_red, OUTPUT);
    pinMode(side_1_yellow, OUTPUT);
    pinMode(side_1_green, OUTPUT);
    pinMode(side_1_switch, INPUT_PULLUP);
    pinMode(side_2_red, OUTPUT);
    pinMode(side_2_yellow, OUTPUT);
    pinMode(side_2_green, OUTPUT);
    pinMode(side_2_switch, INPUT_PULLUP);
    pinMode(pedest_red, OUTPUT);
    pinMode(pedest_green, OUTPUT);
}

//implemented on the given finite machine
void two_way_traffic() {
    switch (state)
    {
    case 0: //starting state
        digitalWrite(side_1_yellow, HIGH);
        digitalWrite(side_2_yellow, HIGH);
        digitalWrite(pedest_red, HIGH);
        if(++time >= 300) //300 * 10(tick_rate) = 3 sec
        {
            digitalWrite(side_1_yellow, LOW);
            digitalWrite(side_2_yellow, LOW);
            digitalWrite(pedest_red, LOW);
            state = 1; 
            time = 0;
        }
        break;
    case 1: //AY
        digitalWrite(side_1_yellow, HIGH);
        digitalWrite(side_2_red, HIGH);
        digitalWrite(pedest_red, HIGH);
        if(++time >= 200) //200 * 10 = 2 sec
        {
            digitalWrite(side_1_yellow, LOW);
            digitalWrite(side_2_red, LOW);
            digitalWrite(pedest_red, LOW);
            state = 2;
            time = 0;
        }
        break;
    case 2: //AG
        digitalWrite(side_1_green, HIGH);
        digitalWrite(side_2_red, HIGH);
        digitalWrite(pedest_red, HIGH);
        if(++time >= 1000) //1000 * 10 = 10 sec
        {
            digitalWrite(side_1_green, LOW);
            digitalWrite(side_2_red, LOW);
            digitalWrite(pedest_red, LOW);
            state = 3;
            time = 0;
        }
        break;
    case 3: //AYa
        digitalWrite(side_1_yellow, HIGH);
        digitalWrite(side_2_red, HIGH);
        digitalWrite(pedest_red, HIGH);
        if(++time >= 200) //200 * 10 = 2 sec
        {
            digitalWrite(side_1_yellow, LOW);
            digitalWrite(side_2_red, LOW);
            digitalWrite(pedest_red, LOW);
            state = 4;
            time = 0;
        }
        break;
    case 4: //BY
        digitalWrite(side_1_red, HIGH);
        digitalWrite(side_2_yellow, HIGH);
        digitalWrite(pedest_red, HIGH);
        if(++time >= 200) //200 * 10 = 2 sec
        {
            digitalWrite(side_1_red, LOW);
            digitalWrite(side_2_yellow, LOW);
            digitalWrite(pedest_red, LOW);
            state = 5;
            time = 0;
        }
        break;
    case 5: //BG
        digitalWrite(side_1_red, HIGH);
        digitalWrite(side_2_green, HIGH);
        digitalWrite(pedest_red, HIGH);
        if(++time >= 1500) //1500* 10 = 15 sec
        {
            digitalWrite(side_1_red, LOW);
            digitalWrite(side_2_green, LOW);
            digitalWrite(pedest_red, LOW);
            state = 6;
            time = 0;
        }
        break;
    case 6: //BYa
        digitalWrite(side_1_red, HIGH);
        digitalWrite(side_2_yellow, HIGH);
        digitalWrite(pedest_red, HIGH);
        if(++time >= 200) //200*10 = 2 sec
        {
            digitalWrite(side_1_red, LOW);
            digitalWrite(side_2_yellow, LOW);
            digitalWrite(pedest_red, LOW);
            time = 0;
            state = (switch_1_pressed || switch_2_pressed) ? 7 : 1; //if switch 1 or 2 is pressed, return state 7 else 1
            switch_1_pressed = switch_2_pressed = 0;
        }
        break;
    case 7: //PG
        digitalWrite(side_1_red, HIGH);
        digitalWrite(side_2_red, HIGH);
        digitalWrite(pedest_green, HIGH);
        if(++time >= 500) //500*10 = 5 sec
        {
            digitalWrite(side_1_red, LOW);
            digitalWrite(side_2_red, LOW);
            digitalWrite(pedest_green, LOW);
            state = 1;
            time = 0;
        }
        break;
    default:
        state = 0;
        break;
    }
}

void loop() {
    current = millis();
    //HIGH is 1 and bool 1 is true
    switch_1_pressed = !digitalRead(side_1_switch); //digitalRead() will return LOW if switch pressed
    switch_2_pressed = !digitalRead(side_2_switch); // and ! operator will convert it to HIGH
    if(current - previous >= tick_rate) {
      previous += tick_rate;  
      two_way_traffic();
    } 
}
