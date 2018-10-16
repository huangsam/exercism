import java.time.LocalDate;
import java.time.LocalDateTime;

class Gigasecond {

    private LocalDate birthDate;
    private LocalDateTime birthDateTime;

    Gigasecond(LocalDate birthDate) {
        this.birthDate = birthDate;
    }

    Gigasecond(LocalDateTime birthDateTime) {
        this.birthDateTime = birthDateTime;
    }

    LocalDateTime getDate() {
        LocalDateTime current = this.birthDateTime;
        if (current == null) {
            current = this.birthDate.atStartOfDay();
        }
        int seconds = (int) Math.pow(10, 9);
        return current.plusSeconds(seconds);
    }

}
