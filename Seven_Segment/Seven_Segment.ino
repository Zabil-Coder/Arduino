const int a_pin = 2, b_pin = 3, c_pin = 8, d_pin = 5, e_pin = 4, f_pin = 7, g_pin = 6;

void setup()
{
    pinMode(a_pin, OUTPUT);
    pinMode(b_pin, OUTPUT);
    pinMode(c_pin, OUTPUT);
    pinMode(d_pin, OUTPUT);
    pinMode(e_pin, OUTPUT);
    pinMode(f_pin, OUTPUT);
    pinMode(g_pin, OUTPUT);
}

void numberToSegment(int number)
{
    switch (number)
    {
    case 1:
        digitalWrite(b_pin, HIGH);
        digitalWrite(c_pin, HIGH);
        break;

    default:
        break;
    }
}

void loop()
{
    digitalWrite(a_pin, OUTPUT);
    digitalWrite(b_pin, OUTPUT);
    digitalWrite(e_pin, OUTPUT);
    digitalWrite(d_pin, OUTPUT);
    digitalWrite(f_pin, OUTPUT);
    digitalWrite(g_pin, OUTPUT);
    digitalWrite(c_pin, OUTPUT);
}