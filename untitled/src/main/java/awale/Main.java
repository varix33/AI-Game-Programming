package awale;

enum Level {
    SEVERE,
    CONFIG,
    INFO,
    FINE,
    FINER
}

interface Logger {

    public void logSevere(String txt);
    public void logConfig(String txt);

}

class Severe implements Logger {

    public void logSevere(String txt) {
        System.out.println(txt);
    }

    public void logConfig(String txt) {
        new Config().logConfig(txt);
    }

}

class Config implements Logger {

    public void logSevere(String txt) {
        // rien
    }

    public void logConfig(String txt) {
        System.out.println(txt);
    }

}

public class Main {
    public static void main(String[] args) {
        x = y;

        while (condition && x != 3) {
            x = 3;
        }
    }
}
