public class SmsService implements MessageInterface {
    public void sendMessage(String message) {
        System.out.println("Sending SMS : " + message);
    }
}
