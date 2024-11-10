public class EmailService implements MessageInterface {
    public void sendMessage(String message) {
        System.out.println("Sending email : " + message);
    }
}
