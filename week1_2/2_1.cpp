/*
 * 1. The variable z is assigned the value 4.0 if x is larger than y or if x is smaller than 5. If none of these are
 *    true, z is assigned the value 2.0.
 *
 * 2. a) 4
 *    b) 2
 *    c) 4
 * 3. Voila:
 */

double x, y, z;
if ((x >= y) || (x < 5.0)) {
    z = 4.0; }
else
{
    z = 2.0;
}