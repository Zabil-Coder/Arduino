const int a_pin = 6, b_pin = 5, c_pin = 4, d_pin = 3, e_pin = 2, f_pin = 7, g_pin = 8;
const int start_pin = 10, stop_pin = 11;

int counter = 9;
int timer_status = 0, stop_click = 0; //0: stop, 1: start

void setup()
{
    pinMode(a_pin, OUTPUT);
    pinMode(b_pin, OUTPUT);
    pinMode(c_pin, OUTPUT);
    pinMode(d_pin, OUTPUT);
    pinMode(e_pin, OUTPUT);
    pinMode(f_pin, OUTPUT);
    pinMode(g_pin, OUTPUT);
    pinMode(start_pin, INPUT_PULLUP);
    pinMode(stop_pin, INPUT_PULLUP);
}

void clearSegment()
{
    digitalWrite(a_pin, LOW);
    digitalWrite(b_pin, LOW);
    digitalWrite(c_pin, LOW);
    digitalWrite(d_pin, LOW);
    digitalWrite(e_pin, LOW);
    digitalWrite(f_pin, LOW);
    digitalWrite(g_pin, LOW);
}

void zeroSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(e_pin, HIGH);
    digitalWrite(f_pin, HIGH);
}

void oneSegment()
{
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
}

void twoSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(e_pin, HIGH);
    digitalWrite(d_pin, HIGH);
}

void threeSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
}

void fourSegment()
{
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
}

void fiveSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
}

void sixSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(e_pin, HIGH);
}

void sevenSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
}

void eightSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(e_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
}

void nineSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
}

void numberToSegment(int number)
{
    switch (number)
    {
    case 0:
        zeroSegment();
        break;
    case 1:
        oneSegment();
        break;
    case 2:
        twoSegment();
        break;
    case 3:
        threeSegment();
        break;
    case 4:
        fourSegment();
        break;
    case 5:
        fiveSegment();
        break;
    case 6:
        sixSegment();
        break;
    case 7:
        sevenSegment();
        break;
    case 8:
        eightSegment();
        break;
    case 9:
        nineSegment();
        break;
    default:
        clearSegment();
        break;
    }
}

void decrementCounter()
{
}

void loop()
{
    if (!digitalRead(start_pin) == HIGH)
        timer_status = 1;
    if (!digitalRead(stop_pin) == HIGH)
    {
        timer_status = 0;
        numberToSegment(counter);
    }
    if (timer_status == 1)
    {
        numberToSegment(counter);
        delay(1000);
        clearSegment();
        counter--;
        if (counter == -1)
        {
            counter = 9;
            timer_status = 0;
        }
    }
    else
        delay(10); //to stablize read
}
