public class HelloWorld {
    public static String hello(String name) {
        if (name == null) {
            return "Hello, World!";
        } else if (name.equals("")) {
            return "Hello, World!";
        }
        return String.format("Hello, %s!", name);
    }
}
