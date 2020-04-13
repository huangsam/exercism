import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

class HandshakeCalculator {

    List<Signal> calculateHandshake(int number) {
        boolean isWink = (number & 1) == 1;
        boolean isDoubleWink = (number & 2) == 2;
        boolean isCloseYourEyes = (number & 4) == 4;
        boolean isJump = (number & 8) == 8;
        boolean isReversed = (number & 16) == 16;
        List<Signal> result = new LinkedList<Signal>();
        if (isWink) {
            result.add(Signal.WINK);
        }
        if (isDoubleWink) {
            result.add(Signal.DOUBLE_BLINK);
        }
        if (isCloseYourEyes) {
            result.add(Signal.CLOSE_YOUR_EYES);
        }
        if (isJump) {
            result.add(Signal.JUMP);
        }
        if (isReversed) {
            Collections.reverse(result);
        }
        return result;
    }

}
