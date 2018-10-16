using System;

public static class Bob
{
    public static string Response(string statement)
    {
        bool isQuestion = false;
        bool allCaps = true;
        bool noAlphaNum = true;
        bool capExists = false;
        bool questionMarkFound = false;

        // Process statement
        for (int i = 0; i < statement.Length; i++) {
            char c = statement[i];
            if (char.IsLetterOrDigit(c)) {
                noAlphaNum = false;
            }

            if (questionMarkFound && !char.Equals(' ', c)) {
                isQuestion = false;
            }

            if (char.IsLower(c)) {
                allCaps = false;
            } else if (char.IsUpper(c)) {
                capExists = true;
            }

            if (char.Equals(c, '?')) {
                questionMarkFound = true;
                isQuestion = true;
            }
        }

        // Return result
        if (noAlphaNum == true && isQuestion == false) {
            return "Fine. Be that way!";
        } else if (allCaps == true && capExists == true) {
            return "Whoa, chill out!";
        } else if (isQuestion == true) {
            return "Sure.";
        }
        return "Whatever.";
    }
}