public class Main {
    public static void main(String[] args) {

        EmailService emailService = new EmailService();
        SmsService smsService = new SmsService();

        Client client = new Client();

        client.inject(emailService);

        client.processMessage("Hello world!");

        client.inject(smsService);

        client.processMessage("Hello world!");

    }
}