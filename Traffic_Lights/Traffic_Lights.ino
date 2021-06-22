int red_1 = 0, red_2 = 1, yellow_1 = 2,  yellow_2 = 3, green_1 = 4,  green_2 = 5, switch_1 = 6, switch_2 = 7; 
int pred = 8, pgreen = 9;
bool btn1_press = false, btn2_press = false;
int old = 0, curr = 0, s = 0, minor = 0; 

void setup() {
    pinMode(red_1, OUTPUT);
    pinMode(red_2, OUTPUT);
    
    pinMode(yellow_1, OUTPUT);
    pinMode(yellow_2, OUTPUT);

    pinMode(green_1, OUTPUT);
    pinMode(green_2, OUTPUT);

    pinMode(switch_1, INPUT_PULLUP);
    pinMode(switch_2, INPUT_PULLUP);

    pinMode(pred, OUTPUT);
    pinMode(pgreen, OUTPUT);
}


void loop() {
    curr = millis();
    if(digitalRead(switch_1) == LOW)
        btn1_press = true; 
    if(digitalRead(switch_2) == LOW)
        btn2_press = true;
    if(curr - old >= 10) {
        old += 10;  
        switch (s)
        {
        case 0:
            digitalWrite(yellow_1, HIGH);
            digitalWrite(yellow_2, HIGH);
            digitalWrite(pred, HIGH);
            minor++;
            if(minor >= 300) {
                digitalWrite(yellow_1, LOW);
                digitalWrite(yellow_2, LOW);
                digitalWrite(pred, LOW);
                minor = 0;
                s = 1; 
            }
            break;
        case 1:
            digitalWrite(yellow_1, HIGH);
            digitalWrite(red_2, HIGH);
            digitalWrite(pred, HIGH);
            minor++;
            if(minor >= 200) {
                digitalWrite(yellow_1, LOW);
                digitalWrite(red_2, LOW);
                digitalWrite(pred, LOW);
                minor = 0;
                s = 2;
            }
            break;
        case 2:
            digitalWrite(green_1, HIGH);
            digitalWrite(red_2, HIGH);
            digitalWrite(pred, HIGH);
            minor++;
            if(minor >= 1000) {
                digitalWrite(green_1, LOW);
                digitalWrite(red_2, LOW);
                digitalWrite(pred, LOW);
                minor = 0;
                s = 3;
            }
            break;
        case 3:
            digitalWrite(yellow_1, HIGH);
            digitalWrite(red_2, HIGH);
            digitalWrite(pred, HIGH);
            minor++;
            if(minor >= 200) {
                digitalWrite(yellow_1, LOW);
                digitalWrite(red_2, LOW);
                digitalWrite(pred, LOW);
                minor = 0;
                s = 4;
            }
            break;
        case 4:
            digitalWrite(red_1, HIGH);
            digitalWrite(yellow_2, HIGH);
            digitalWrite(pred, HIGH);
            minor++;
            if(minor >= 200) {
                digitalWrite(red_1, LOW);
                digitalWrite(yellow_2, LOW);
                digitalWrite(pred, LOW);
                minor = 0;
                s = 5;
            }
            break;
        case 5:
            digitalWrite(red_1, HIGH);
            digitalWrite(green_2, HIGH);
            digitalWrite(pred, HIGH);
            minor++;
            if(minor >= 1500) {
                digitalWrite(red_1, LOW);
                digitalWrite(green_2, LOW);
                digitalWrite(pred, LOW);
                minor = 0;
                s = 6;
            }
            break;
        case 6:
            digitalWrite(red_1, HIGH);
            digitalWrite(yellow_2, HIGH);
            digitalWrite(pred, HIGH);
            minor++;
            if(minor >= 200) {
                digitalWrite(red_1, LOW);
                digitalWrite(yellow_2, LOW);
                digitalWrite(pred, LOW);
                minor = 0;
                if (btn1_press || btn2_press) 
                    s = 7;
                else
                    s = 1; 
                btn1_press = false;
                btn2_press = false;
            }
            break;
        case 7:
            digitalWrite(red_1, HIGH);
            digitalWrite(red_2, HIGH);
            digitalWrite(pgreen, HIGH);
            minor++;
            if(minor >= 500) {
                digitalWrite(red_1, LOW);
                digitalWrite(red_2, LOW);
                digitalWrite(pgreen, LOW);
                minor = 0;
                s = 1;
            }
            break;
        default:
            break;
        }
    } 
}
