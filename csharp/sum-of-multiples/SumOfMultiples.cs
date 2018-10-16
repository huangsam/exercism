using System;
using System.Collections.Generic;

public static class SumOfMultiples
{
    public static int Sum(IEnumerable<int> multiples, int max)
    {
        int result = 0;
        
        // Up until maximum value
        for (int cur_val = 1; cur_val < max; cur_val++) {

            // If current value is divisible
            foreach (var multiple in multiples) {
                if (cur_val % multiple == 0) {
                    result += cur_val;
                    break;
                }
            }
        }

        return result;
    }
}
