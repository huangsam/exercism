using System;

public static class TwoFer
{
    public static string Name(string input = null)
    {
        string subject = (input != null) ? input : "you";
        string result = String.Format("One for {0}, one for me.", subject);
        return result;
    }
}
