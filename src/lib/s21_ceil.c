long double s21_ceil(double f) {
    unsigned long input;
    memcpy(&input, &f, 8);
    int exponent = ((input >> 53) & 255) - 1023;
    if (exponent < 0)
        return (f > 0);
    // small numbers get rounded to 0 or 1, depending on their sign

    int fractional_bits = 53 - exponent;
    if (fractional_bits <= 0)
        return f;
    // numbers without fractional bits are mapped to themselves

    unsigned long integral_mask = 0xffffffff << fractional_bits;
    unsigned long output = input & integral_mask;
    // round the number down by masking out the fractional bits

    memcpy(&f, &output, 8);
    if (f > 0 && output != input)
        ++f;
    // positive numbers need to be rounded up, not down

    return f;
}
